<?php
/**
 * @file
 * designssquare_theme_block_plus_sample_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquare_theme_block_plus_sample_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
