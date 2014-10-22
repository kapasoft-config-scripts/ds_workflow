<?php
/**
 * @file
 * designssquare_com_theme_metronic_configurations_structure_data.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function designssquare_com_theme_metronic_configurations_structure_data_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 1,
    'filters' => array(),
  );

  return $formats;
}
