<?php
/**
 * @file
 * designssquarecom_blog_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquarecom_blog_structure_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "jw_player" && $api == "jw_player_presets") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function designssquarecom_blog_structure_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function designssquarecom_blog_structure_image_default_styles() {
  $styles = array();

  // Exported image style: ds_blog_img_post_big.
  $styles['ds_blog_img_post_big'] = array(
    'name' => 'ds_blog_img_post_big',
    'label' => 'DS Image Post Teaser Big',
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
          'width' => 780,
          'height' => 468,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_blog_img_post_slider.
  $styles['ds_blog_img_post_slider'] = array(
    'name' => 'ds_blog_img_post_slider',
    'label' => 'DS Image Post Teaser Slider',
    'effects' => array(
      8 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 570,
          'height' => 330,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_blog_img_post_small.
  $styles['ds_blog_img_post_small'] = array(
    'name' => 'ds_blog_img_post_small',
    'label' => 'DS Img Post Teaser Small',
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
          'width' => 370,
          'height' => 222,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_blog_video_post_big.
  $styles['ds_blog_video_post_big'] = array(
    'name' => 'ds_blog_video_post_big',
    'label' => 'DS Video Post Teaser Big',
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
          'width' => 780,
          'height' => 468,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_blog_video_post_slider.
  $styles['ds_blog_video_post_slider'] = array(
    'name' => 'ds_blog_video_post_slider',
    'label' => 'DS Video Post Teaser Slider',
    'effects' => array(
      3 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 570,
          'height' => 330,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_blog_video_post_small.
  $styles['ds_blog_video_post_small'] = array(
    'name' => 'ds_blog_video_post_small',
    'label' => 'DS Video Post Teaser Small',
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
          'width' => 370,
          'height' => 222,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_blog_vimeo_post_big.
  $styles['ds_blog_vimeo_post_big'] = array(
    'name' => 'ds_blog_vimeo_post_big',
    'label' => 'DS Vimeo Post Teaser Big',
    'effects' => array(
      9 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 624,
          'height' => 468,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_blog_vimeo_post_slider.
  $styles['ds_blog_vimeo_post_slider'] = array(
    'name' => 'ds_blog_vimeo_post_slider',
    'label' => 'DS Vimeo Post Teaser Slider',
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
          'width' => 570,
          'height' => 330,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: ds_blog_vimeo_post_small.
  $styles['ds_blog_vimeo_post_small'] = array(
    'name' => 'ds_blog_vimeo_post_small',
    'label' => 'DS Vimeo Post Teaser Small',
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
          'width' => 240,
          'height' => 122,
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
function designssquarecom_blog_structure_node_info() {
  $items = array(
    'blog_posts' => array(
      'name' => t('Blog Posts'),
      'base' => 'node_content',
      'description' => t('list of posts '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
