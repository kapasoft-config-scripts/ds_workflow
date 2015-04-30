<?php
/**
 * @file
 * designssquare_com_theme_metronic_configurations_structure_data.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function designssquare_com_theme_metronic_configurations_structure_data_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_ui_general';
  $strongarm->value = 0;
  $export['comment_anonymous_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_ui_general';
  $strongarm->value = 1;
  $export['comment_default_mode_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_ui_general';
  $strongarm->value = '50';
  $export['comment_default_per_page_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_ui_general';
  $strongarm->value = 1;
  $export['comment_form_location_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_ui_general';
  $strongarm->value = '1';
  $export['comment_preview_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_ui_general';
  $strongarm->value = 1;
  $export['comment_subject_field_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_ui_general';
  $strongarm->value = '1';
  $export['comment_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__ui_general';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_compression_type';
  $strongarm->value = 'min';
  $export['jquery_update_compression_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_admin_version';
  $strongarm->value = '1.10';
  $export['jquery_update_jquery_admin_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_cdn';
  $strongarm->value = 'google';
  $export['jquery_update_jquery_cdn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.10';
  $export['jquery_update_jquery_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_expanded';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_expanded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_ui_general';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_ui_general';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_ui_general';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_ui_general';
  $strongarm->value = '1';
  $export['node_preview_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_ui_general';
  $strongarm->value = 0;
  $export['node_submitted_ui_general'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_blog_pattern';
  $strongarm->value = 'blogs/[user:name]';
  $export['pathauto_blog_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_forum_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_forum_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = 'content/[node:title]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_hyphen';
  $strongarm->value = 1;
  $export['pathauto_punctuation_hyphen'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_taxonomy_term_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_user_pattern';
  $strongarm->value = 'users/[user:name]';
  $export['pathauto_user_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_node';
  $strongarm->value = array(
    'about_us' => 'about_us',
    'advanced_datatables' => 'advanced_datatables',
    'ajax_datatables' => 'ajax_datatables',
    'ajax_portlets' => 'ajax_portlets',
    'alerts_dialogs' => 'alerts_dialogs',
    'page' => 'page',
    'block_ui' => 'block_ui',
    'blog' => 'blog',
    'blog_post' => 'blog_post',
    'calendar' => 'calendar',
    'contact_us' => 'contact_us',
    'custom_dropdowns' => 'custom_dropdowns',
    'dashboard' => 'dashboard',
    'date_paginator' => 'date_paginator',
    'draggable_portlets' => 'draggable_portlets',
    'dropzone_file_upload' => 'dropzone_file_upload',
    'editable_datatables' => 'editable_datatables',
    'editors' => 'editors',
    'error' => 'error',
    'error_500' => 'error_500',
    'error_500_full' => 'error_500_full',
    'error_full' => 'error_full',
    'error_full2' => 'error_full2',
    'extended_modals' => 'extended_modals',
    'form_layouts' => 'form_layouts',
    'form_tools' => 'form_tools',
    'form_validation' => 'form_validation',
    'form_wizard' => 'form_wizard',
    'form_x_editable' => 'form_x_editable',
    'google_maps' => 'google_maps',
    'image_crop' => 'image_crop',
    'inbox' => 'inbox',
    'invoice' => 'invoice',
    'ion_range_sliders' => 'ion_range_sliders',
    'knob_circle_dials' => 'knob_circle_dials',
    'lock_screen' => 'lock_screen',
    'managed_datatables' => 'managed_datatables',
    'multiple_file_upload' => 'multiple_file_upload',
    'nestable_list' => 'nestable_list',
    'news' => 'news',
    'noui_range_sliders' => 'noui_range_sliders',
    'notifica8_notifications' => 'notifica8_notifications',
    'order_view' => 'order_view',
    'orders' => 'orders',
    'pickers' => 'pickers',
    'poll' => 'poll',
    'portfolio' => 'portfolio',
    'pricing_tables' => 'pricing_tables',
    'product_edit' => 'product_edit',
    'products' => 'products',
    'progress_bar' => 'progress_bar',
    'timeline' => 'timeline',
    'toastr_notifications' => 'toastr_notifications',
    'ui_general' => 'ui_general',
    'ui_tree' => 'ui_tree',
    'vector_maps' => 'vector_maps',
    'visual_charts' => 'visual_charts',
    'ecommerce_dashboard' => 'ecommerce_dashboard',
    'jquery_ui_sliders' => 'jquery_ui_sliders',
    'article' => 0,
  );
  $export['uuid_features_entity_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_taxonomy_term';
  $strongarm->value = array(
    'tags' => 'tags',
  );
  $export['uuid_features_entity_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_assets_path';
  $strongarm->value = '';
  $export['uuid_features_file_assets_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_mode';
  $strongarm->value = 'local';
  $export['uuid_features_file_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_node';
  $strongarm->value = array(
    'about_us' => 'about_us',
    'advanced_datatables' => 'advanced_datatables',
    'ajax_datatables' => 'ajax_datatables',
    'ajax_portlets' => 'ajax_portlets',
    'alerts_dialogs' => 'alerts_dialogs',
    'page' => 'page',
    'block_ui' => 'block_ui',
    'blog' => 'blog',
    'blog_post' => 'blog_post',
    'calendar' => 'calendar',
    'contact_us' => 'contact_us',
    'custom_dropdowns' => 'custom_dropdowns',
    'dashboard' => 'dashboard',
    'date_paginator' => 'date_paginator',
    'draggable_portlets' => 'draggable_portlets',
    'dropzone_file_upload' => 'dropzone_file_upload',
    'editable_datatables' => 'editable_datatables',
    'editors' => 'editors',
    'error' => 'error',
    'error_500' => 'error_500',
    'error_500_full' => 'error_500_full',
    'error_full' => 'error_full',
    'error_full2' => 'error_full2',
    'extended_modals' => 'extended_modals',
    'form_layouts' => 'form_layouts',
    'form_tools' => 'form_tools',
    'form_validation' => 'form_validation',
    'form_wizard' => 'form_wizard',
    'form_x_editable' => 'form_x_editable',
    'google_maps' => 'google_maps',
    'image_crop' => 'image_crop',
    'inbox' => 'inbox',
    'invoice' => 'invoice',
    'ion_range_sliders' => 'ion_range_sliders',
    'knob_circle_dials' => 'knob_circle_dials',
    'lock_screen' => 'lock_screen',
    'managed_datatables' => 'managed_datatables',
    'multiple_file_upload' => 'multiple_file_upload',
    'nestable_list' => 'nestable_list',
    'news' => 'news',
    'noui_range_sliders' => 'noui_range_sliders',
    'notifica8_notifications' => 'notifica8_notifications',
    'order_view' => 'order_view',
    'orders' => 'orders',
    'pickers' => 'pickers',
    'poll' => 'poll',
    'portfolio' => 'portfolio',
    'pricing_tables' => 'pricing_tables',
    'product_edit' => 'product_edit',
    'products' => 'products',
    'progress_bar' => 'progress_bar',
    'timeline' => 'timeline',
    'toastr_notifications' => 'toastr_notifications',
    'ui_general' => 'ui_general',
    'ui_tree' => 'ui_tree',
    'vector_maps' => 'vector_maps',
    'visual_charts' => 'visual_charts',
    'ecommerce_dashboard' => 'ecommerce_dashboard',
    'jquery_ui_sliders' => 'jquery_ui_sliders',
    'article' => 0,
  );
  $export['uuid_features_file_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_supported_fields';
  $strongarm->value = 'file, image,file_managed';
  $export['uuid_features_file_supported_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_taxonomy_term';
  $strongarm->value = array(
    'tags' => 0,
  );
  $export['uuid_features_file_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_vocabulary_terms';
  $strongarm->value = 1;
  $export['uuid_features_vocabulary_terms'] = $strongarm;

  return $export;
}
