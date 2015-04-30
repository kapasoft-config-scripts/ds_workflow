<?php
/**
 * @file
 * ds_theme_smartbox_configurations_structure_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ds_theme_smartbox_configurations_structure_data_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ds_theme_smartbox_configurations_structure_data_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_left_sidebar' => array(
      'name' => t('Basic - Left Sidebar'),
      'base' => 'node_content',
      'description' => t('layout with left sidebar for Drupal Theme - Smartbox '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_no_header' => array(
      'name' => t('Basic - No Header'),
      'base' => 'node_content',
      'description' => t('layout without header section '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_right_sidebar' => array(
      'name' => t('Basic - Right Sidebar'),
      'base' => 'node_content',
      'description' => t('SmartBox layout with right sidebar'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_simple' => array(
      'name' => t('Basic - Simple Header'),
      'base' => 'node_content',
      'description' => t('the same as Basic Page except header is the simple version without image'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => t('layout for contact page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'home' => array(
      'name' => t('Home'),
      'base' => 'node_content',
      'description' => t('the layout of Home page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page_404' => array(
      'name' => t('404'),
      'base' => 'node_content',
      'description' => t('layout for 404 page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
