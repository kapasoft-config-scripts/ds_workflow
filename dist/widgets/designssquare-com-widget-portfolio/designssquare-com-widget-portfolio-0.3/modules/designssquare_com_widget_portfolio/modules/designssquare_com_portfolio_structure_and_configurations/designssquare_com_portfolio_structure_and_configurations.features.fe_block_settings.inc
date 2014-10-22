<?php
/**
 * @file
 * designssquare_com_portfolio_structure_and_configurations.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function designssquare_com_portfolio_structure_and_configurations_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-ds_portfolio_block-projects'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ds_portfolio_block-projects',
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
      'espresso' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'espresso',
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

  $export['views-ds_portfolio_projects-projects'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ds_portfolio_projects-projects',
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
      'espresso' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'espresso',
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

  $export['views-ds_portfolio_teaser-projects'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ds_portfolio_teaser-projects',
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
      'espresso' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'espresso',
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
