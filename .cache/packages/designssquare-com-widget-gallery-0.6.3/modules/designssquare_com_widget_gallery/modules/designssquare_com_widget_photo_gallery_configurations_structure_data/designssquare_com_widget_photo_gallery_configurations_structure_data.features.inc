<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_configurations_structure_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_ctools_plugin_api($module = NULL, $api = NULL) {
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
function designssquare_com_widget_photo_gallery_configurations_structure_data_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_image_default_styles() {
  $styles = array();

  // Exported image style: ds_gallery_block_thumb.
  $styles['ds_gallery_block_thumb'] = array(
    'name' => 'ds_gallery_block_thumb',
    'label' => 'DS Gallery Block Thumbnails',
    'effects' => array(
      4 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 220,
          'height' => 154,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_gallery_index_thumb.
  $styles['ds_gallery_index_thumb'] = array(
    'name' => 'ds_gallery_index_thumb',
    'label' => 'DS Gallery Index Thumbnails',
    'effects' => array(
      5 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 240,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_gallery_node_thumb.
  $styles['ds_gallery_node_thumb'] = array(
    'name' => 'ds_gallery_node_thumb',
    'label' => 'DS Gallery Node Thumbnails',
    'effects' => array(
      6 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 220,
          'height' => 220,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_gallery_teaser_thumb.
  $styles['ds_gallery_teaser_thumb'] = array(
    'name' => 'ds_gallery_teaser_thumb',
    'label' => 'DS Gallery Teaser Thumbnails',
    'effects' => array(
      7 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 245,
          'height' => 160,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_node_info() {
  $items = array(
    'ds_gallery' => array(
      'name' => t('DS Gallery'),
      'base' => 'node_content',
      'description' => t('photo gallery'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ds_gallery_index' => array(
      'name' => t('DS Gallery Index'),
      'base' => 'node_content',
      'description' => t('DesignsSquare.com: Widget: Photo Gallery space for all Photo Galleries'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
