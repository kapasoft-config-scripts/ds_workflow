<?php
function strongarm_override_features_export_options()
{

    $options = array();

    //load all variables
    $vars = strongarm_vars_load();

    foreach ($vars as $var_index => $var) {
        if (preg_match('/theme/', $var_index) || preg_match('/site/', $var_index) || preg_match('/uuid/', $var_index) || preg_match('/ds_/', $var_index)) {
            $options[$var_index] = $var->name;
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
function strongarm_override_features_export($data, &$export, $module_name)
{
//we have module dependencies in order for this module to function properly
//so we'll add them here
    $export['dependencies']['designssquare_lib_sample_data'] = 'designssquare_lib_sample_data';

// The following is the simplest implementation of a straight object export
// with no further export processors called.
    foreach ($data as $component) {
        $export['features']['strongarm_override'][$component] = $component;
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
function strongarm_override_features_export_render($module_name, $data, $export = NULL)
{
    module_load_include('module', 'designssquare_lib');

    $code = array();
    $code[] = '$strongarm_override = array();';
    $code[] = '';

    foreach ($data as $var_name) {
//        $file = file_load($var_name);

        if (preg_match('/site_frontpage/', $var_name) || preg_match('/site_403/', $var_name) || preg_match('/site_404/', $var_name)) {
            $item = array(
                'name' => $var_name,
                'value' => ($url = variable_get($var_name)) ? drupal_get_path_alias($url) : '',
            );
        } else {
            $item = array(
                'name' => $var_name,
                'value' => variable_get($var_name),
            );
        }


        //add the contest code to the feature
        if (isset($item)) {
            $code[] = '$strongarm_override[] = ' . features_var_export($item, '') . ';';
        }
    }


    $code[] = 'return $strongarm_override;';
    $code = implode("\n", $code);

    return array('strongarm_override_default_settings' => $code);
}


/**
 * Implementation of hook_features_rebuild(). [component_hook]
 */
function strongarm_override_features_rebuild($module)
{
    $items = module_invoke($module, 'strongarm_override_default_settings');

    //import all variables
    foreach ($items as $var) {
        variable_set($var['name'], $var['value']);
    }
}


/**
 * Implementation of hook_features_revert(). [component_hook]
 */
function strongarm_override_features_revert($module)
{
    strongarm_override_features_rebuild($module);
}