<?php
/**
 * @file
 * designssquare_com_theme_espresso_configurations_structures.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquare_com_theme_espresso_configurations_structures_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function designssquare_com_theme_espresso_configurations_structures_node_info() {
  $items = array(
    'basic_page_3_columns' => array(
      'name' => t('Basic Page - 3 Columns'),
      'base' => 'node_content',
      'description' => t('basic page with three columns layout'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => t('contact layout with a contact form'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'home' => array(
      'name' => t('Home'),
      'base' => 'node_content',
      'description' => t('home / landing page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => t('layout for portfolio'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('layout for Project page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
