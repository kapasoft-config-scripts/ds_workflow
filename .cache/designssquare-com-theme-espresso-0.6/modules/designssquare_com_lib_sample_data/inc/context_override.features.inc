<?php
function context_override_features_export_options()
{
    $options = array();
    //load all context
    $contexts = context_load();
    foreach ($contexts as $ctx_index => $ctx) {
        $options[$ctx_index] = $ctx->name;
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
function context_override_features_export($data, &$export, $module_name)
{
//we have module dependencies in order for this module to function properly
//so we'll add them here
    $export['dependencies']['designssquare_lib_sample_data'] = 'designssquare_lib_sample_data';

// The following is the simplest implementation of a straight object export
// with no further export processors called.
    foreach ($data as $component) {
        $export['features']['context_override'][$component] = $component;
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
function context_override_features_export_render($module_name, $data, $export = NULL)
{
//    module_load_include('module', 'designssquare_lib');
//
    $code = array();
    $code[] = '$context_override = array();';
    $code[] = '';
//    $items = context_features_export($data, $export, $module_name);

    foreach ($data as $ctx_name) {
        $ctx = context_load($ctx_name);

        //add the contest code to the feature
        if (isset($ctx)) {
            $code[] = '$context_override[] = ' . features_var_export($ctx, '') . ';';
        }
    }

    $code[] = 'return $context_override;';
    $code = implode("\n", $code);
    return array('context_override_default_settings' => $code);
}


/**
 * Implementation of hook_features_rebuild(). [component_hook]
 */
function context_override_features_rebuild($module)
{
    $items = module_invoke($module, 'context_override_default_settings');

    foreach ($items as $ctx_id => $ctx) {
        $existing = context_load($ctx['name'], TRUE);
        if ($existing) {
            $new_status = (isset($ctx['disabled'])) ? $ctx['disabled'] : FALSE ;
            ctools_export_set_status('context', $ctx['name'], $new_status);
            $status = drupal_write_record('context', $ctx, 'name');
        } else {
            ctools_export_set_status('context', $ctx['name'], $ctx['disabled']);
            drupal_write_record('context', $ctx);
        }
        context_load(NULL, TRUE);
        context_invalidate_cache();
    }

}


/**
 * Implementation of hook_features_revert(). [component_hook]
 */
function context_override_features_revert($module)
{
    context_override_features_rebuild($module);
}