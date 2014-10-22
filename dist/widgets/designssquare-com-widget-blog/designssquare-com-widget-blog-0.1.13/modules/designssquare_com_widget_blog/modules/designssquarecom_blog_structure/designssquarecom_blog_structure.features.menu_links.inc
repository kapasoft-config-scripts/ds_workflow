<?php
/**
 * @file
 * designssquarecom_blog_structure.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function designssquarecom_blog_structure_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_blog:ds-blog
  $menu_links['main-menu_blog:ds-blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ds-blog',
    'router_path' => 'ds-blog',
    'link_title' => 'BLOG',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_blog:ds-blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('BLOG');


  return $menu_links;
}
