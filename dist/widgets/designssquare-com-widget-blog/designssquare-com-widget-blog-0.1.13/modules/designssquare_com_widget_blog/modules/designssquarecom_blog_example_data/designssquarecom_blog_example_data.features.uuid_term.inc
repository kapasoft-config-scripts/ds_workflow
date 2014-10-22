<?php
/**
 * @file
 * designssquarecom_blog_example_data.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function designssquarecom_blog_example_data_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'javascript',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '0cfcce2a-e821-48d7-9b69-8aa4e7f5ab70',
    'vocabulary_machine_name' => 'tags',
  );
  $terms[] = array(
    'name' => 'css',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '2620c910-cde3-4e50-9789-25e20543ca07',
    'vocabulary_machine_name' => 'tags',
  );
  $terms[] = array(
    'name' => 'Audios',
    'description' => 'All Audio Posts',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '3cef33ef-6ecf-4f0e-bb4b-e66ab7a2b122',
    'vocabulary_machine_name' => 'blog_categories',
  );
  $terms[] = array(
    'name' => 'coffee script',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '46c96324-b1e8-4e07-b626-67ea820330ba',
    'vocabulary_machine_name' => 'tags',
  );
  $terms[] = array(
    'name' => 'Text Posts',
    'description' => 'All Text Posts',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '553f1ea7-4573-4bab-8cb1-b8810e30e283',
    'vocabulary_machine_name' => 'blog_categories',
  );
  $terms[] = array(
    'name' => 'python',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '6d139a07-c5a7-4195-8049-f826463dce32',
    'vocabulary_machine_name' => 'tags',
  );
  $terms[] = array(
    'name' => 'Image Posts',
    'description' => 'All Image Posts',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '8aeb7d0f-2eaa-477b-9320-87c89191c6a4',
    'vocabulary_machine_name' => 'blog_categories',
  );
  $terms[] = array(
    'name' => 'ruby',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '8b505ff6-c53b-4c18-9b42-ca17ad36fc9b',
    'vocabulary_machine_name' => 'tags',
  );
  $terms[] = array(
    'name' => 'scala',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'a738f9a5-fe9c-4724-9ca1-37fd0f1f6cfa',
    'vocabulary_machine_name' => 'tags',
  );
  $terms[] = array(
    'name' => 'Videos',
    'description' => 'All Video Posts',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'bbe940de-d14e-4f41-8eff-eccba132453a',
    'vocabulary_machine_name' => 'blog_categories',
  );
  $terms[] = array(
    'name' => 'groovy',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'c1b4b72b-c009-49b5-bfd7-a66818d94402',
    'vocabulary_machine_name' => 'tags',
  );
  $terms[] = array(
    'name' => 'Uncategorized',
    'description' => 'All Uncategorized Posts',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'c91c0033-2fb4-4bbd-b74c-2b6f381b3f7d',
    'vocabulary_machine_name' => 'blog_categories',
  );
  $terms[] = array(
    'name' => 'php',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'e16d1b8a-0b0d-4e91-bfa8-851f064f2f27',
    'vocabulary_machine_name' => 'tags',
  );
  $terms[] = array(
    'name' => 'java',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'ff12326b-a0cd-49b4-9097-05eb6dade7f7',
    'vocabulary_machine_name' => 'tags',
  );
  return $terms;
}
