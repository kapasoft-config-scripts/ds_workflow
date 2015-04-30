<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_configurations_structure_data.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_gallery:ds-gallery
  $menu_links['main-menu_gallery:ds-gallery'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ds-gallery',
    'router_path' => 'ds-gallery',
    'link_title' => 'Gallery',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_gallery:ds-gallery',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Gallery');


  return $menu_links;
}
