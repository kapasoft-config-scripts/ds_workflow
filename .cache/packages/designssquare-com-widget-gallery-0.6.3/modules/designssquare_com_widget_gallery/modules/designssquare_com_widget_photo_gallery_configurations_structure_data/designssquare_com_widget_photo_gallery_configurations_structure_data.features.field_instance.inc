<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_configurations_structure_data.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-ds_gallery-body'
  $field_instances['node-ds_gallery-body'] = array(
    'bundle' => 'ds_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-ds_gallery-field_ds_gallery_categories'
  $field_instances['node-ds_gallery-field_ds_gallery_categories'] = array(
    'bundle' => 'ds_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'category of the Gallery',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_gallery_categories',
    'label' => 'Categories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-ds_gallery-field_ds_gallery_featured_img'
  $field_instances['node-ds_gallery-field_ds_gallery_featured_img'] = array(
    'bundle' => 'ds_gallery',
    'deleted' => 0,
    'description' => 'the one image from the Gallery that is going to be used for featuring the Gallery in the teaser in home/landing page or any other section of the page',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_gallery_featured_img',
    'label' => 'Featured Photo',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'designssquare_com/widget/gallery',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-ds_gallery-field_ds_gallery_item'
  $field_instances['node-ds_gallery-field_ds_gallery_item'] = array(
    'bundle' => 'ds_gallery',
    'default_value' => array(
      0 => array(
        'title' => '',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
        'ds_gallery_item_tag' => '',
        'content_choice[0]' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'items for Gallery such as image, video, etc',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => NULL,
        'settings' => array(),
        'type' => 'designssquare_com_widget_gallery_item_formatter',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_gallery_item',
    'label' => 'Items',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'designssquare_com_widget_gallery_item',
      'settings' => array(),
      'type' => 'designssquare_com_widget_gallery_item',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-ds_gallery-field_ds_gallery_page_intro'
  $field_instances['node-ds_gallery-field_ds_gallery_page_intro'] = array(
    'bundle' => 'ds_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'short intro on this page displayed part of the header for many themes',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_gallery_page_intro',
    'label' => 'Intro',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-ds_gallery-field_ds_gallery_summary'
  $field_instances['node-ds_gallery-field_ds_gallery_summary'] = array(
    'bundle' => 'ds_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Little introduction about the Gallery that is going to be featured part of teaser or any block',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_gallery_summary',
    'label' => 'Summary',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-ds_gallery-field_ds_gallery_tags'
  $field_instances['node-ds_gallery-field_ds_gallery_tags'] = array(
    'bundle' => 'ds_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'tag for the Gallery',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_gallery_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-ds_gallery-field_ds_index_reference'
  $field_instances['node-ds_gallery-field_ds_index_reference'] = array(
    'bundle' => 'ds_gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Reference to Gallery Index used to set breadcrumbs trail for the gallery',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_index_reference',
    'label' => 'Index Reference',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-ds_gallery_index-field_breadcrumb_category'
  $field_instances['node-ds_gallery_index-field_breadcrumb_category'] = array(
    'bundle' => 'ds_gallery_index',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'the name used in breadrumbs',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_breadcrumb_category',
    'label' => 'Breadcrumb Category',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-ds_gallery_index-field_ds_gallery_page_intro'
  $field_instances['node-ds_gallery_index-field_ds_gallery_page_intro'] = array(
    'bundle' => 'ds_gallery_index',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ds_gallery_page_intro',
    'label' => 'Intro',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Breadcrumb Category');
  t('Categories');
  t('Featured Photo');
  t('Index Reference');
  t('Intro');
  t('Items');
  t('Little introduction about the Gallery that is going to be featured part of teaser or any block');
  t('Reference to Gallery Index used to set breadcrumbs trail for the gallery');
  t('Summary');
  t('Tags');
  t('category of the Gallery');
  t('items for Gallery such as image, video, etc');
  t('short intro on this page displayed part of the header for many themes');
  t('tag for the Gallery');
  t('the name used in breadrumbs');
  t('the one image from the Gallery that is going to be used for featuring the Gallery in the teaser in home/landing page or any other section of the page');

  return $field_instances;
}
