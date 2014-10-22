<?php
/**
 * @file
 * designssquarecom_blog_example_data.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function designssquarecom_blog_example_data_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_blog';
  $strongarm->value = 'edit-comment';
  $export['additional_settings__active_tab_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_blog_layout';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_blog_layout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_blog_left_sidebar';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_blog_left_sidebar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_blog_left_sidebar_small';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_blog_left_sidebar_small'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_blog_posts';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_blog_posts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_blog_right_sidebar';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_blog_right_sidebar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_blog_right_sidebar_small';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_blog_right_sidebar_small'] = $strongarm;

  return $export;
}
