<?php
/**
 * @file
 * designssquarecom_blog_example_data.jw_player_presets.inc
 */

/**
 * Implements hook_default_jw_player_presets().
 */
function designssquarecom_blog_example_data_default_jw_player_presets() {
  $export = array();

  $jw_player_preset = new stdClass();
  $jw_player_preset->disabled = FALSE; /* Edit this to true to make a default jw_player_preset disabled initially */
  $jw_player_preset->api_version = 1;
  $jw_player_preset->preset_name = 'Video Big Preset';
  $jw_player_preset->machine_name = 'big_video_preset';
  $jw_player_preset->description = 'preset for big video post';
  $jw_player_preset->settings = array(
    'mode' => 'html5',
    'width' => '770',
    'height' => '440',
    'controlbar' => 'bottom',
    'skin' => '',
    'autoplay' => 0,
  );
  $export['big_video_preset'] = $jw_player_preset;

  $jw_player_preset = new stdClass();
  $jw_player_preset->disabled = FALSE; /* Edit this to true to make a default jw_player_preset disabled initially */
  $jw_player_preset->api_version = 1;
  $jw_player_preset->preset_name = 'slider_video_preset';
  $jw_player_preset->machine_name = 'slider_video_preset';
  $jw_player_preset->description = 'preset for the slider';
  $jw_player_preset->settings = array(
    'mode' => 'html5',
    'width' => '570',
    'height' => '299',
    'controlbar' => 'bottom',
    'skin' => '',
    'autoplay' => 0,
  );
  $export['slider_video_preset'] = $jw_player_preset;

  $jw_player_preset = new stdClass();
  $jw_player_preset->disabled = FALSE; /* Edit this to true to make a default jw_player_preset disabled initially */
  $jw_player_preset->api_version = 1;
  $jw_player_preset->preset_name = 'Video Small Preset';
  $jw_player_preset->machine_name = 'video_small_preset';
  $jw_player_preset->description = 'preset for small video posts';
  $jw_player_preset->settings = array(
    'mode' => 'html5',
    'width' => '370',
    'height' => '240',
    'controlbar' => 'bottom',
    'skin' => '',
    'autoplay' => 0,
  );
  $export['video_small_preset'] = $jw_player_preset;

  return $export;
}
