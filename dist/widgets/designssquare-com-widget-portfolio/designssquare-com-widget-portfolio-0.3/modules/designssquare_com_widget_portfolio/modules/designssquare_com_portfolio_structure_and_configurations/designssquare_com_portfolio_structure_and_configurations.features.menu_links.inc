<?php
/**
 * @file
 * designssquare_com_portfolio_structure_and_configurations.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function designssquare_com_portfolio_structure_and_configurations_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_portfolio:ds-portfolio
  $menu_links['main-menu_portfolio:ds-portfolio'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ds-portfolio',
    'router_path' => 'ds-portfolio',
    'link_title' => 'Portfolio',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_portfolio:ds-portfolio',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Portfolio');


  return $menu_links;
}
