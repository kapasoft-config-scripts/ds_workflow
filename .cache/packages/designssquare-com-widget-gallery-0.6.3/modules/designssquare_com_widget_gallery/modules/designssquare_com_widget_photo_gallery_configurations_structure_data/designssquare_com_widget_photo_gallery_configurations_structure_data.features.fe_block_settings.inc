<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_configurations_structure_data.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-ds_gallery_all-all'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ds_gallery_all-all',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'metronic' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'metronic',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-ds_gallery_block-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ds_gallery_block-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'metronic' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'metronic',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-ds_gallery_teaser-teaser'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ds_gallery_teaser-teaser',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'metronic' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'metronic',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
