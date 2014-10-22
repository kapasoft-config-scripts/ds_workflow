<?php
/**
 * @file
 * designssquarecom_blog_example_data.features.inc
 */

/**
 * Implements hook_content_assets_default_settings().
 */
function designssquarecom_blog_example_data_content_assets_default_settings() {
$content_assets = array();

$content_assets = array(
  'public://H264_test2_Talkinghead_mp4_480x320.mp4' => array(
    'uri' => 'public://H264_test2_Talkinghead_mp4_480x320.mp4',
    'filename' => 'H264_test2_Talkinghead_mp4_480x320.mp4',
  ),
  'public://audio/Allegro-from-Duet-in-Major.mp3' => array(
    'uri' => 'public://audio/Allegro-from-Duet-in-Major.mp3',
    'filename' => 'Allegro-from-Duet-in-Major.mp3',
  ),
  'public://blog/11.jpg' => array(
    'uri' => 'public://blog/11.jpg',
    'filename' => '11.jpg',
  ),
  'public://blog/4.jpg' => array(
    'uri' => 'public://blog/4.jpg',
    'filename' => '4.jpg',
  ),
  'public://blog/blur.jpg' => array(
    'uri' => 'public://blog/blur.jpg',
    'filename' => 'blur.jpg',
  ),
  'public://styles/ds_blog_img_post_big/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_img_post_big/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/ds_blog_img_post_slider/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_img_post_slider/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/ds_blog_img_post_small/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_img_post_small/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/ds_blog_video_post_big/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_video_post_big/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/ds_blog_video_post_slider/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_video_post_slider/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/ds_blog_video_post_small/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_video_post_small/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/ds_blog_vimeo_post_big/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_vimeo_post_big/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/ds_blog_vimeo_post_slider/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_vimeo_post_slider/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/ds_blog_vimeo_post_small/public/modules/image/sample.png' => array(
    'uri' => 'public://styles/ds_blog_vimeo_post_small/public/modules/image/sample.png',
    'filename' => 'sample.png',
  ),
  'public://styles/large/public/AleksandraDementjeva.jpg' => array(
    'uri' => 'public://styles/large/public/AleksandraDementjeva.jpg',
    'filename' => 'AleksandraDementjeva.jpg',
  ),
  'public://styles/large/public/AleksandraDementjeva_0.jpg' => array(
    'uri' => 'public://styles/large/public/AleksandraDementjeva_0.jpg',
    'filename' => 'AleksandraDementjeva_0.jpg',
  ),
  'public://styles/large/public/fridge_2.jpg' => array(
    'uri' => 'public://styles/large/public/fridge_2.jpg',
    'filename' => 'fridge_2.jpg',
  ),
  'public://styles/large/public/fridge_2_1.jpg' => array(
    'uri' => 'public://styles/large/public/fridge_2_1.jpg',
    'filename' => 'fridge_2_1.jpg',
  ),
  'public://styles/square_thumbnail/public/AleksandraDementjeva.jpg' => array(
    'uri' => 'public://styles/square_thumbnail/public/AleksandraDementjeva.jpg',
    'filename' => 'AleksandraDementjeva.jpg',
  ),
  'public://styles/square_thumbnail/public/AleksandraDementjeva_0.jpg' => array(
    'uri' => 'public://styles/square_thumbnail/public/AleksandraDementjeva_0.jpg',
    'filename' => 'AleksandraDementjeva_0.jpg',
  ),
  'public://styles/square_thumbnail/public/Fridge_1.jpg' => array(
    'uri' => 'public://styles/square_thumbnail/public/Fridge_1.jpg',
    'filename' => 'Fridge_1.jpg',
  ),
  'public://styles/square_thumbnail/public/fridge_2.jpg' => array(
    'uri' => 'public://styles/square_thumbnail/public/fridge_2.jpg',
    'filename' => 'fridge_2.jpg',
  ),
  'public://styles/square_thumbnail/public/fridge_2_0.jpg' => array(
    'uri' => 'public://styles/square_thumbnail/public/fridge_2_0.jpg',
    'filename' => 'fridge_2_0.jpg',
  ),
  'public://styles/square_thumbnail/public/fridge_2_1.jpg' => array(
    'uri' => 'public://styles/square_thumbnail/public/fridge_2_1.jpg',
    'filename' => 'fridge_2_1.jpg',
  ),
  'public://styles/thumbnail/public/blog/4.jpg' => array(
    'uri' => 'public://styles/thumbnail/public/blog/4.jpg',
    'filename' => '4.jpg',
  ),
);
return $content_assets;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquarecom_blog_example_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "jw_player" && $api == "jw_player_presets") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
