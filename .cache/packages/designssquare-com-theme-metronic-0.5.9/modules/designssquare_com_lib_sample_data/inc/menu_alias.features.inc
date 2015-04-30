<?php
function menu_alias_features_export_options()
{

    $options = array();

    //load all menus
    $menus = menu_get_menus();

    foreach ($menus as $key => $title) {
        $options[$key] = $title;
    }

    return $options;
}

/**
 * Implementation of hook_features_export [component hook]
 *
 * This is a component hook, rather then a module hook, therefore this is the
 * callback from hook_features_api which relates to the specific component we
 * are looking to export. When a specific instance of the component we are
 * looking to export is selected, this will include the necessariy item, plus
 * any dependencies into our export array.
 *
 * @param array $data
 * this is the machine name for the component in question
 * @param array &$export
 * array of all components to be exported
 * @param string $module_name
 * The name of the feature module to be generated.
 * @return array
 * The pipe array of further processors that should be called
 */
function menu_alias_features_export($data, &$export, $module_name)
{
//we have module dependencies in order for this module to function properly
//so we'll add them here
    $export['dependencies']['designssquare_lib_sample_data'] = 'designssquare_lib_sample_data';

// The following is the simplest implementation of a straight object export
// with no further export processors called.
    foreach ($data as $component) {
        $export['features']['menu_alias'][$component] = $component;
    }
    return array();
}

/**
 * Implementation of hook_features_export_render. [component hook]
 *
 * This hook will be invoked in order to export
 * Component hook. The hook should be implemented using the name ot the
 * component, not the module, eg. [component]_features_export() rather than
 * [module]_features_export().
 *
 * Render one or more component objects to code.
 *
 * @param string $module_name
 *   The name of the feature module to be exported.
 * @param array $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param array $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return array
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, e.g. the key for `hook_example` should simply be `example`.
 */
function menu_alias_features_export_render($module_name, $data, $export = NULL)
{
    module_load_include('module', 'designssquare_lib');

    $code = array();
    $code[] = '$menu_alias = array();';
    $code[] = '';
    $items = array();
    foreach ($data as $menu_id) {
        $menu = menu_load($menu_id);
        if($menu){
            $items[$menu_id] =  array(
                        'definition' => _menu_definition($menu),
                        'links' => _menu_links($menu),
            );
        }

    }

    //add the contest code to the feature
    if (!empty($items)) {
        $code[] = '$menu_alias = '. features_var_export($items, '') .';';
    }

    $code[] = 'return $menu_alias;';
    $code = implode("\n", $code);

    return array('menu_alias_default_settings' => $code);
}


function _menu_definition($menu_ins){
    $menu_item = array();

    if ($menu_ins) {
        $menu_item = array(
                    'menu_name' => $menu_ins['menu_name'],
                    'title' => str_replace("'", "\'", $menu_ins['title']),
                    'description' => str_replace("'", "\'", $menu_ins['description'])
        );
    } else {
        watchdog(WATCHDOG_NOTICE, "menu: $menu_ins not found");
    }

    return $menu_item;
}

function _menu_links($menu){
    $output = array();

    //for menu map retrieve all links
    $mlid_ins = db_select('menu_links', 'ml')
        ->fields('ml', array('mlid', 'link_path'))
        ->condition('ml.menu_name', $menu['menu_name'])
        ->condition('ml.hidden', '0')
        ->execute()->fetchAllAssoc('mlid', PDO::FETCH_ASSOC);
    //generate the map between mlid and alias path
    foreach ($mlid_ins as $mlid => $options) {
        $alias_map[$mlid] = drupal_get_path_alias($options['link_path']);
    }


    //grab all the links
    $links = db_select('menu_links', 'ml', array('fetch' => PDO::FETCH_ASSOC))
        ->fields('ml')
        ->condition('ml.menu_name', $menu['menu_name'])
        ->condition('ml.hidden', '0')
        ->orderBy('weight')
        ->execute()
        ->fetchAll();

    //unserialize
    foreach ($links as $key => $link) {
        $links[$key]['options'] = unserialize($link['options']);
    }

    //export
    foreach ($links as $key => $link) {
        $alias_path = drupal_get_path_alias($link['link_path']);

        $link_export = $link;
        $link_export['link_path'] = $alias_path;
        unset($link_export['mlid']);
        unset($link_export['router_path']);
        unset($link_export['options']['identifier']);
        $link_export['plid'] = ($link_export['plid']) ? $alias_map[$link_export['plid']] : $link_export['plid'];
        $link_export['p1'] = ($link_export['p1']) ? $alias_map[$link_export['p1']] : $link_export['p1'];
        $link_export['p2'] = ($link_export['p2']) ? $alias_map[$link_export['p2']] : $link_export['p2'];
        $link_export['p3'] = ($link_export['p3']) ? $alias_map[$link_export['p3']] : $link_export['p3'];

        $output[$alias_path] = $link_export;
    }

    return $output;
}


/**
 * Implementation of hook_features_rebuild(). [component_hook]
 */
function menu_alias_features_rebuild($module) {
    $items = module_invoke($module, 'menu_alias_default_settings');

    //import all variables referencing assets
    foreach ($items as $key => $menu_import) {
        //create menu based on alias path
        _import_menu_alias($key, $menu_import);
    }
}


/**
 * Implementation of hook_features_revert(). [component_hook]
 */
function menu_alias_features_revert($module) {
    menu_alias_features_rebuild($module);
}


function _import_menu_alias($id, $import){
    $t = get_t();

    $menu = $import['definition'];
    // clear menus and create new ones if doesn't exist
      //remove menu links for clean install
        menu_delete_links($menu['menu_name']);
        drupal_set_message($t('Links deleted from menu - ' . $menu['menu_name']));

        if (!menu_load($menu['menu_name'])) {
            //doesn't exist...lets create one
            drupal_set_message($t('Missing menu ' . $menu['menu_name'] . '...creating'));
            menu_save($menu);
        }


    //map containing the structure of the menu
    $alias_map = array();

    //shuffle so that parents are always above the children menu items
    //this is important so when building the $alias_map child is not being inserted without parent already present
    $all_items = $import['links'];
    $parents_p1 = array();
    $parents_p2 = array();
    $parents_p3 = array();
    $parents_p4 = array();
    $parents_p5 = array();

    foreach ($all_items as $key => $item) {
        if ($key == $item['p1']) {
            $parents_p1[$key] = $item;
        }
        if ($key == $item['p2']) {
            $parents_p2[$key] = $item;
        }
        if ($key == $item['p3']) {
            $parents_p3[$key] = $item;
        }
        if ($key == $item['p4']) {
            $parents_p4[$key] = $item;
        }
        if ($key == $item['p5']) {
            $parents_p5[$key] = $item;
        }
    }

    $sorted_menu_list = array_merge($parents_p1, $parents_p2, $parents_p3, $parents_p4, $parents_p5);

    //add links
    foreach ($sorted_menu_list as $key => $item) {
        $alias_link_path = $item['link_path'];
        //look up node based on the alias path of existing drupal instance
        $item['link_path'] = drupal_get_normal_path($alias_link_path);

        //drupal_set_message('plid: '.$item['plid']. ' alias_map:' . $alias_map[$item['plid']] );
        $item['plid'] = ($item['plid'] !== 0 && !empty($alias_map[$item['plid']])) ? $alias_map[$item['plid']] : $item['plid'];
        $item['p1'] = ($item['p1'] !== 0 && !empty($alias_map[$item['p1']])) ? $alias_map[$item['p1']] : $item['p1'];
        $item['p2'] = ($item['p2'] !== 0 && !empty($alias_map[$item['p2']])) ? $alias_map[$item['p2']] : $item['p2'];
        $item['p3'] = ($item['p3'] !== 0 && !empty($alias_map[$item['p3']])) ? $alias_map[$item['p3']] : $item['p3'];

        $installed = menu_link_save($item);
        if ($installed !== FALSE) {
            drupal_set_message($t('Menu Item : ' . $key . ' installed'));
            //drupal_set_message('INSERT: link_path: '.$alias_link_path. ' mlip:' . $installed );
            $alias_map[$alias_link_path] = $installed;
        } else {
            drupal_set_message($t('Menu Item : ' . $key . ' was not installed'));
        }
    }
    menu_link_save($item);
    menu_cache_clear_all();
    drupal_set_message($t('Installed Menu: '.$menu['menu_name']));
}