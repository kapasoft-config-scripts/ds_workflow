<?php
function variable_assets_features_export_options()
{

    $options = array();

    //load all variables
    $vars = strongarm_vars_load();

    foreach ($vars as $var_index => $var) {

        if (is_numeric($var->value)) {
            //see if there is entry in files usage table
            $file_usage = db_select('file_usage', 'f')
                ->fields('f', array('fid', 'type', 'module'))
                ->condition('f.type', $var->name)
                ->condition('f.fid', $var->value)
                ->execute()
                ->fetchAssoc();

            if (isset($file_usage['fid'])) {
                $options[$file_usage['fid']] = $var->name;
            }
        }


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
function variable_assets_features_export($data, &$export, $module_name)
{
//we have module dependencies in order for this module to function properly
//so we'll add them here
    $export['dependencies']['designssquare_lib_sample_data'] = 'designssquare_lib_sample_data';

// The following is the simplest implementation of a straight object export
// with no further export processors called.
    foreach ($data as $component) {
        $export['features']['variable_assets'][$component] = $component;
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
function variable_assets_features_export_render($module_name, $data, $export = NULL)
{
    module_load_include('module', 'designssquare_lib');

    $code = array();
    $code[] = '$variable_assets = array();';
    $code[] = '';

    foreach ($data as $fid) {
        $file = file_load($fid);

        if($file){
            //export asset
            export_asset((array)$file, $module_name);

            //export feature
            $usage_list = ($file) ? file_usage_list($file) : '';
            $usage = array_shift($usage_list);

            $item = array(
                array_keys($usage)[0]  => $file
            );
        }

        //add the contest code to the feature
         if (isset($item)) {
             $code[] = '$variable_assets = '. features_var_export($item, '') .';';
         }
    }
    $code[] = 'return $variable_assets;';
    $code = implode("\n", $code);

    return array('variable_assets_default_settings' => $code);
}


/**
 * Implementation of hook_features_rebuild(). [component_hook]
 */
function variable_assets_features_rebuild($module) {
    $items = module_invoke($module, 'variable_assets_default_settings');

    //import all variables referencing assets
    foreach ($items as $variable_name => $file_array) {
        //transfer asset in the file system and save it in db
        $fid = transfer_asset($file_array, $module, $variable_name);
        //update variable with the new fid
        variable_set($variable_name,$fid);
    }
}


/**
 * Implementation of hook_features_revert(). [component_hook]
 */
function variable_assets_features_revert($module) {
    variable_assets_features_rebuild($module);
}