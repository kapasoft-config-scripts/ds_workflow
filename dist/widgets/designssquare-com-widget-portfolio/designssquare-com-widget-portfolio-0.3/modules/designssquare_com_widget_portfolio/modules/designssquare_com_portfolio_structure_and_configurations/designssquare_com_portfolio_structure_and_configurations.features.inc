<?php
/**
 * @file
 * designssquare_com_portfolio_structure_and_configurations.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquare_com_portfolio_structure_and_configurations_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function designssquare_com_portfolio_structure_and_configurations_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function designssquare_com_portfolio_structure_and_configurations_node_info() {
  $items = array(
    'ds_portfolio' => array(
      'name' => t('DS Portfolio'),
      'base' => 'node_content',
      'description' => t('portfolio type part of DesignsSquare.com Portfolio Widget'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_portfolio_index' => array(
      'name' => t('DS Portfolio Index'),
      'base' => 'node_content',
      'description' => t('DesignsSquare.com Portfolio Widget index'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
