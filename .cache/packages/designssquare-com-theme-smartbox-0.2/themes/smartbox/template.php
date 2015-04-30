<?php

function smartbox_js_alter(&$javascript)
{
    //use theme specific bootstrap
    unset($javascript[drupal_get_path('theme', 'bootstrap') . '/bootstrap/js/bootstrap.js']);
    unset($javascript[drupal_get_path('theme', 'bootstrap') . '/bootstrap/js/bootstrap.min.js']);
}

function smartbox_css_alter(&$css)
{
    //use theme specific bootstrap
    unset($css[drupal_get_path('theme', 'bootstrap') . '/bootstrap/css/bootstrap.min.css']);
    unset($css[drupal_get_path('theme', 'bootstrap') . '/bootstrap/css/bootstrap.css']);
}

function smartbox_preprocess_html(&$vars)
{
    $vars['classes_array'] = array();
}

function smartbox_preprocess_page(&$vars)
{
    //per layout
    if (!empty($vars['node'])) {
        $node = $vars['node'];
        $type = $node->type;
    } else {
        $type = 'none';
    }

    /*STYLES & JS**/
    module_load_include('inc', 'designssquare_lib', 'includes/ds_front_end');
    module_load_include('inc', 'designssquare_com_theme_smartbox', 'includes/smartbox_imports');
    import_front_end('css', _default_smartbox_css($type));
    import_front_end('js', _default_smartbox_js($type));
    import_front_end('js', _page_smartbox_js($type));

    /*LAYOUTS*/
    switch ($type) {
        case 'home':
//            $vars['theme_hook_suggestions'][] = 'page__home';//@ToDo look into why suggestion doesnt work
            $vars['theme_hook_suggestion'] = 'page__home';
            break;
        case 'basic_simple':
//            $vars['theme_hook_suggestions'][] = 'page__home';//@ToDo look into why suggestion doesnt work
            $vars['theme_hook_suggestion'] = 'page__basic_simple';
            break;
        case 'basic_no_header':
//            $vars['theme_hook_suggestions'][] = 'page__home';//@ToDo look into why suggestion doesnt work
            $vars['theme_hook_suggestion'] = 'page__basic_no_header';
            break;
        case 'basic_right_sidebar':
//            $vars['theme_hook_suggestions'][] = 'page__home';//@ToDo look into why suggestion doesnt work
            $vars['theme_hook_suggestion'] = 'page__right_sidebar';
            break;
        case 'basic_left_sidebar':
            //            $vars['theme_hook_suggestions'][] = 'page__home';//@ToDo look into why suggestion doesnt work
            $vars['theme_hook_suggestion'] = 'page__left_sidebar';
            break;
        case 'page_404':
            //            $vars['theme_hook_suggestions'][] = 'page__home';//@ToDo look into why suggestion doesnt work
            $vars['theme_hook_suggestion'] = 'page__404';
            break;
        case 'contact':
            //            $vars['theme_hook_suggestions'][] = 'page__home';//@ToDo look into why suggestion doesnt work
            $vars['theme_hook_suggestion'] = 'page__contact';
            break;
        case 'page':
            //            $vars['theme_hook_suggestions'][] = 'page__home';//@ToDo look into why suggestion doesnt work
            $vars['theme_hook_suggestion'] = 'page';
            break;
        default:
            //sets the header title for all other types not part of smartbox theme
            $vars['page_tapi']['intro'] = $vars['page_tapi']['title'];
            break;
    }
}

function smartbox_preprocess_block(&$vars)
{
    switch ($vars['block_html_id']) {
        case 'block-system-main-menu':
        case 'block-search-form':
            $vars['theme_hook_suggestions'][] = 'block__no_wrap_ds';
            break;
        case 'block-system-main':
            $vars['theme_hook_suggestions'][] = 'block';
            break;
    }
}

/*Add header background image to the page_tapi
 * */

function smartbox_page_tapi_alter(&$page_tapi)
{
    $node = get_node_from_cache();
    $bg_instance = (isset($node)) ? field_get_items('node', $node, 'field_header_background') : '';

    $header_bg = array();
    if (isset($bg_instance[0]) && !empty($bg_instance[0])) {
        $header_bg['url'] = file_create_url($bg_instance[0]['uri']);
        $header_bg['alt'] = $bg_instance[0]['alt'];
        $header_bg['title'] = $bg_instance[0]['title'];
    } else {
        $header_bg['url'] = base_path() . path_to_theme() . '/smartbox/images/assets/landscapes/landscape-1-1250x300.jpg';
        $header_bg['alt'] = 'smartbox header bg image';
        $header_bg['title'] = 'smarbox header bg title';
    }


    $page_tapi['header_bg'] = $header_bg;
}

/*Add header background image to the page_tapi
 * */

function smartbox_html_tapi_alter(&$html_tapi)
{
    $node = get_node_from_cache();
    $bg_instance = (isset($node)) ? field_get_items('node', $node, 'field_page_background') : '';

    $header_bg = array();
    if (isset($bg_instance[0]) && !empty($bg_instance[0])) {
        $header_bg['url'] = file_create_url($bg_instance[0]['uri']);
        $header_bg['is_enabled'] = true;
    } else {
        $header_bg['url'] = '';
        $header_bg['is_enabled'] = false;
    }


    $html_tapi['page_bg'] = $header_bg;
}


