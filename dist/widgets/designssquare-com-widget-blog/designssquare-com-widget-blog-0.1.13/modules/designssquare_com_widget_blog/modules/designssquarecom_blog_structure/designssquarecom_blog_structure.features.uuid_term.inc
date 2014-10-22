<?php
/**
 * @file
 * designssquarecom_blog_structure.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function designssquarecom_blog_structure_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'none',
    'description' => 'there is no sidebar',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '3656f50c-c9b3-476d-b225-cf52f279949a',
    'vocabulary_machine_name' => 'post_sidebar',
  );
  $terms[] = array(
    'name' => 'Small',
    'description' => 'post with small image or video',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '4724e570-b398-44db-bc53-db323445d51c',
    'vocabulary_machine_name' => 'post_format',
  );
  $terms[] = array(
    'name' => 'left',
    'description' => 'there is sidebar on left',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '6dbf4c34-4e34-4ed7-aaa3-f4991036be13',
    'vocabulary_machine_name' => 'post_sidebar',
  );
  $terms[] = array(
    'name' => 'Big',
    'description' => 'post with large image or video',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '770c84f6-5cf0-4310-b306-66f4c0037afc',
    'vocabulary_machine_name' => 'post_format',
  );
  $terms[] = array(
    'name' => 'right',
    'description' => 'there is sidebar on right',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'bdfd197f-6e7f-489e-94cc-cfd7ea290a70',
    'vocabulary_machine_name' => 'post_sidebar',
  );
  return $terms;
}
