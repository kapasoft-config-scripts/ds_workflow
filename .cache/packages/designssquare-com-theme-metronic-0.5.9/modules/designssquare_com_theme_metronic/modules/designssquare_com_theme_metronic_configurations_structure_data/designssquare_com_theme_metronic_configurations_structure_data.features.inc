<?php
/**
 * @file
 * designssquare_com_theme_metronic_configurations_structure_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquare_com_theme_metronic_configurations_structure_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function designssquare_com_theme_metronic_configurations_structure_data_image_default_styles() {
  $styles = array();

  // Exported image style: ds_avatar.
  $styles['ds_avatar'] = array(
    'name' => 'ds_avatar',
    'label' => 'Avatar',
    'effects' => array(
      2 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 29,
          'height' => 29,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_user_profile.
  $styles['ds_user_profile'] = array(
    'name' => 'ds_user_profile',
    'label' => 'User Profile',
    'effects' => array(
      1 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 259,
          'height' => 213,
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
function designssquare_com_theme_metronic_configurations_structure_data_node_info() {
  $items = array(
    'about_us' => array(
      'name' => t('About Us'),
      'base' => 'node_content',
      'description' => t('layout for about us'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'advanced_datatables' => array(
      'name' => t('Advanced Datatables'),
      'base' => 'node_content',
      'description' => t('Advanced Datatables'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ajax_datatables' => array(
      'name' => t('Ajax Datatables'),
      'base' => 'node_content',
      'description' => t('Ajax Datatables'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ajax_portlets' => array(
      'name' => t('Ajax Portlets'),
      'base' => 'node_content',
      'description' => t('Ajax Portlets'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'alerts_dialogs' => array(
      'name' => t('Alerts & Dialogs'),
      'base' => 'node_content',
      'description' => t('layout for Alerts & Dialogs'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'block_ui' => array(
      'name' => t('Block UI'),
      'base' => 'node_content',
      'description' => t('layout for Block UI'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('blog'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'blog_post' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => t('layout of blog post'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'calendar' => array(
      'name' => t('Calendar'),
      'base' => 'node_content',
      'description' => t('layout of Calendar'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'contact_us' => array(
      'name' => t('Contact Us'),
      'base' => 'node_content',
      'description' => t('layout for Contact Us'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'custom_dropdowns' => array(
      'name' => t('Custom Dropdowns'),
      'base' => 'node_content',
      'description' => t('layout of Custom Dropdowns'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dashboard' => array(
      'name' => t('Dashboard'),
      'base' => 'node_content',
      'description' => t('dashboard type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'date_paginator' => array(
      'name' => t('Date Paginator'),
      'base' => 'node_content',
      'description' => t('layout for date paginator'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'draggable_portlets' => array(
      'name' => t('Draggable Portlets'),
      'base' => 'node_content',
      'description' => t('Draggable Portlets'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dropzone_file_upload' => array(
      'name' => t('Dropzone File Upload'),
      'base' => 'node_content',
      'description' => t('Dropzone File Upload'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ecommerce_dashboard' => array(
      'name' => t('eCommerce Dashboard'),
      'base' => 'node_content',
      'description' => t('eCommerce Dashboard'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'editable_datatables' => array(
      'name' => t('Editable Datatables'),
      'base' => 'node_content',
      'description' => t('Editable Datatables'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'editors' => array(
      'name' => t('Editors'),
      'base' => 'node_content',
      'description' => t('layout for editors'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'error' => array(
      'name' => t('Error'),
      'base' => 'node_content',
      'description' => t('layout to Error'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'error_500' => array(
      'name' => t('Error 500'),
      'base' => 'node_content',
      'description' => t('layout for error 500 simple'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'error_500_full' => array(
      'name' => t('Error 500 Full'),
      'base' => 'node_content',
      'description' => t('layout of Error 500 full screen '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'error_full' => array(
      'name' => t('Error Full'),
      'base' => 'node_content',
      'description' => t('full error layout'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'error_full2' => array(
      'name' => t('Error Full Ver 2'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'extended_modals' => array(
      'name' => t('Extended Modals'),
      'base' => 'node_content',
      'description' => t('layout for extended moduls'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'form_layouts' => array(
      'name' => t('Form Layouts'),
      'base' => 'node_content',
      'description' => t('layout for form layouts'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'form_tools' => array(
      'name' => t('Form Tools'),
      'base' => 'node_content',
      'description' => t('layout for form tools'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'form_validation' => array(
      'name' => t('Form Validation'),
      'base' => 'node_content',
      'description' => t('layout of form validation'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'form_wizard' => array(
      'name' => t('Form Wizard'),
      'base' => 'node_content',
      'description' => t('layout for form wizard'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'form_x_editable' => array(
      'name' => t('Form X-editable'),
      'base' => 'node_content',
      'description' => t('layout for Form X-editable'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'google_maps' => array(
      'name' => t('Google Maps'),
      'base' => 'node_content',
      'description' => t('Google Maps'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'image_crop' => array(
      'name' => t('Image Cropping'),
      'base' => 'node_content',
      'description' => t('layout for image cropping'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'inbox' => array(
      'name' => t('Inbox'),
      'base' => 'node_content',
      'description' => t('layout for inbox'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'invoice' => array(
      'name' => t('Invoice'),
      'base' => 'node_content',
      'description' => t('layout of invoice'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ion_range_sliders' => array(
      'name' => t('Ion Range Sliders'),
      'base' => 'node_content',
      'description' => t('layout for Ion Range Sliders'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'jquery_ui_sliders' => array(
      'name' => t('jQuery UI Sliders'),
      'base' => 'node_content',
      'description' => t('layout for jQuery UI Sliders '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'knob_circle_dials' => array(
      'name' => t('Knob Circle Dials'),
      'base' => 'node_content',
      'description' => t('layout for Knob Circle Dials'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'lock_screen' => array(
      'name' => t('Lock Screen'),
      'base' => 'node_content',
      'description' => t('layout for locked screen'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'managed_datatables' => array(
      'name' => t('Managed Datatables'),
      'base' => 'node_content',
      'description' => t('Managed Datatables'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'multiple_file_upload' => array(
      'name' => t('Multiple File Upload'),
      'base' => 'node_content',
      'description' => t('layout for Multiple File Upload'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nestable_list' => array(
      'name' => t('Nestable List'),
      'base' => 'node_content',
      'description' => t('layout for nestable lists'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('layout of news'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'notifica8_notifications' => array(
      'name' => t('Notifica8 Notifications'),
      'base' => 'node_content',
      'description' => t('layout for Notifica8 Notifications'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'noui_range_sliders' => array(
      'name' => t('NoUI Range Sliders'),
      'base' => 'node_content',
      'description' => t('layout of NoUI Range Sliders'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'order_view' => array(
      'name' => t('Order View'),
      'base' => 'node_content',
      'description' => t('oder view layout'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'orders' => array(
      'name' => t('Orders'),
      'base' => 'node_content',
      'description' => t('orders layout'),
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
    'pickers' => array(
      'name' => t('Pickers'),
      'base' => 'node_content',
      'description' => t('layout for Pickers'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => t('portfolio'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pricing_tables' => array(
      'name' => t('Pricing Tables'),
      'base' => 'node_content',
      'description' => t('layout for Pricing Table'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_edit' => array(
      'name' => t('Product Edit'),
      'base' => 'node_content',
      'description' => t('layout of product edit'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'products' => array(
      'name' => t('Products'),
      'base' => 'node_content',
      'description' => t('layout of products'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'progress_bar' => array(
      'name' => t('Progress Bar'),
      'base' => 'node_content',
      'description' => t('layout for progress bar'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'timeline' => array(
      'name' => t('Timeline'),
      'base' => 'node_content',
      'description' => t('timeline'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'toastr_notifications' => array(
      'name' => t('Toastr Notifications'),
      'base' => 'node_content',
      'description' => t('layout of Toastr Notifications'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ui_general' => array(
      'name' => t('UI General'),
      'base' => 'node_content',
      'description' => t('layout for UI General components'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ui_tree' => array(
      'name' => t('UI Tree'),
      'base' => 'node_content',
      'description' => t('layout of UI Tree'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'vector_maps' => array(
      'name' => t('Vector Maps'),
      'base' => 'node_content',
      'description' => t('Vector Maps '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'visual_charts' => array(
      'name' => t('Visual Charts'),
      'base' => 'node_content',
      'description' => t('Visual Charts'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
