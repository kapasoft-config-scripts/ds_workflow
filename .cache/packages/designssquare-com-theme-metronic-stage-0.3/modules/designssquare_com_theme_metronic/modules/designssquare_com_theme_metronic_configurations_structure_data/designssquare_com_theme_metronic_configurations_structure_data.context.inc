<?php
/**
 * @file
 * designssquare_com_theme_metronic_configurations_structure_data.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function designssquare_com_theme_metronic_configurations_structure_data_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ds_metronic_statewide';
  $context->description = 'statewide';
  $context->tag = 'designssquare.com.theme.metronic';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-metronic_notifications' => array(
          'module' => 'boxes',
          'delta' => 'metronic_notifications',
          'region' => 'header',
          'weight' => '-9',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'boxes-metronic_copyrights' => array(
          'module' => 'boxes',
          'delta' => 'metronic_copyrights',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'boxes-metronic_actions' => array(
          'module' => 'boxes',
          'delta' => 'metronic_actions',
          'region' => 'breadcrumbs_sidebar',
          'weight' => '-8',
        ),
        'boxes-metronic_dashboard_box' => array(
          'module' => 'boxes',
          'delta' => 'metronic_dashboard_box',
          'region' => 'breadcrumbs_sidebar',
          'weight' => '-7',
        ),
        'boxes-metronic_themer_styler' => array(
          'module' => 'boxes',
          'delta' => 'metronic_themer_styler',
          'region' => 'theme_panel',
          'weight' => '-9',
        ),
        'boxes-metronic_footer_copyrights' => array(
          'module' => 'boxes',
          'delta' => 'metronic_footer_copyrights',
          'region' => 'login_footer',
          'weight' => '-9',
        ),
        'boxes-quick_sidebar_box' => array(
          'module' => 'boxes',
          'delta' => 'quick_sidebar_box',
          'region' => 'quick_sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.theme.metronic');
  t('statewide');
  $export['ds_metronic_statewide'] = $context;

  return $export;
}
