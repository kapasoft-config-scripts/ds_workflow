<?php
function content_assets_features_export_options()
{
    $dir = drupal_realpath('public://');
    $options = array();

    if ($handle = opendir($dir)) {
        while (false !== ($file = readdir($handle))) {
            if ($file != "." && $file != ".." && $file != ".htaccess") {
//                $options[$dir.'/'.$file] = $file;
                $options[$file] = $file;
            }
        }
        closedir($handle);
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
function content_assets_features_export($data, &$export, $module_name)
{
//we have module dependencies in order for this module to function properly
//so we'll add them here
    $export['dependencies']['designssquare_lib_sample_data'] = 'designssquare_lib_sample_data';

// The following is the simplest implementation of a straight object export
// with no further export processors called.
    foreach ($data as $component) {
        $export['features']['content_assets'][$component] = $component;
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
function content_assets_features_export_render($module_name, $data, $export = NULL)
{
    module_load_include('module', 'designssquare_lib');

    $code = array();
    $code[] = '$content_assets = array();';
    $code[] = '';
    $items = array();
    foreach ($data as $uri => $dir_name) {
        $module_src_dir = drupal_get_path('module', $module_name).'/assets/content';
        $items += export_transfer_asset($dir_name, $module_src_dir, '');
    }

    //add the contest code to the feature
    if (!empty($items)) {
        $code[] = '$content_assets = '. features_var_export($items, '') .';';
    }

    $code[] = 'return $content_assets;';
    $code = implode("\n", $code);

    return array('content_assets_default_settings' => $code);
}

/**
 * Implementation of hook_features_rebuild(). [component_hook]
 */
function content_assets_features_rebuild($module) {
    $items = module_invoke($module, 'content_assets_default_settings');

    //import all variables referencing assets
    foreach ($items as $uri => $dir_import) {
            $dir_name = drupal_dirname($uri);
            $source_path = drupal_get_path('module', $module).'/assets/content/'.substr($dir_import['uri'],9);
            file_prepare_directory($dir_name, FILE_CREATE_DIRECTORY);
            (!file_exists(drupal_realpath($uri))) ? file_unmanaged_copy($source_path, $uri) : '';
    }
}

/**
 * Implementation of hook_features_revert(). [component_hook]
 */
function content_assets_features_revert($module) {
    content_assets_features_rebuild($module);
}

/**
 * Implementation of exporting and transfering assets into array and local module
 *
 * @param $file
 * the name of the file or directory
 *
 * @param $module_src_dir
 * path to the module plus location for directory where the assets are going to be written
 *
 * @param $rel_path
 * relative path to the public directory for the particular asset
 *
 * @return
 * array of all files in the tree
 */
function export_transfer_asset($file, $module_src_dir, $rel_path)
{
    $output = array();
    $public_dir = drupal_realpath('public://');
    $full_path = $public_dir . ((empty($rel_path)) ? '' : '/' . $rel_path) . '/'.$file;

    if ($handle = @opendir($full_path)) {
        $new_rel_path = $rel_path . (!empty($rel_path) ? '/' . $file : $file);
        while (false !== ($file = readdir($handle))) {
            if (is_dir($full_path . '/' . $file) && $file != '.' && $file != '..') {
                $output += export_transfer_asset($file, $module_src_dir, $new_rel_path);
            } elseif ($file != '.' && $file != '..') {
                $output += _file_export($module_src_dir, $new_rel_path, $file);
            }
        }
      closedir($handle);
    }elseif(file_exists($full_path)){
        //must be file
        $output += _file_export($module_src_dir, '' ,$file);
    }
    return $output;
}

function _file_export($module_src_dir, $rel_path, $file){
    $file_ref  = $rel_path . (empty($rel_path) ? '' : '/') . $file;
    $uri = file_build_uri($file_ref);

    //transfer file
    $dest_dir = $module_src_dir . (empty($rel_path) ? '' : '/') . $rel_path;
    $dest_full_path = $dest_dir . '/' . $file;
    if (!file_exists($dest_full_path)) {
        file_prepare_directory($dest_dir, FILE_CREATE_DIRECTORY);
        file_unmanaged_copy($uri, $dest_full_path, FILE_EXISTS_REPLACE);
    }

    return array(
        $uri => array(
            'uri' => $uri,
            'filename' => $file,
//            'source' => $module_src_dir . '/' . $file_ref,
        )
    );
}