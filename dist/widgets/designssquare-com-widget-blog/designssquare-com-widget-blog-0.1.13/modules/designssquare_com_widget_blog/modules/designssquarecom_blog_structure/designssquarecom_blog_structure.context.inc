<?php
/**
 * @file
 * designssquarecom_blog_structure.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function designssquarecom_blog_structure_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_category';
  $context->description = 'for posts of certain category';
  $context->tag = '';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'blog_categories' => 'blog_categories',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-blog_block_view-recent_ver1' => array(
          'module' => 'views',
          'delta' => 'blog_block_view-recent_ver1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-ds_blog_categories-cat' => array(
          'module' => 'views',
          'delta' => 'ds_blog_categories-cat',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-ds_blog_tags-tag' => array(
          'module' => 'views',
          'delta' => 'ds_blog_tags-tag',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('for posts of certain category');
  $export['blog_category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_entry';
  $context->description = 'blog_entry';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-blog_block_view-recent_ver1' => array(
          'module' => 'views',
          'delta' => 'blog_block_view-recent_ver1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-ds_blog_categories-cat' => array(
          'module' => 'views',
          'delta' => 'ds_blog_categories-cat',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-ds_blog_tags-tag' => array(
          'module' => 'views',
          'delta' => 'ds_blog_tags-tag',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blog_entry');
  $export['blog_entry'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_posts';
  $context->description = 'blog posts';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog_posts' => 'blog_posts',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'ds-blog' => 'ds-blog',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ds_blog_content-posts' => array(
          'module' => 'views',
          'delta' => 'ds_blog_content-posts',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ds_blog_categories-cat' => array(
          'module' => 'views',
          'delta' => 'ds_blog_categories-cat',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-ds_blog_tags-tag' => array(
          'module' => 'views',
          'delta' => 'ds_blog_tags-tag',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-3dd29840f2e82fbe8c21732070304977' => array(
          'module' => 'views',
          'delta' => '3dd29840f2e82fbe8c21732070304977',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blog posts');
  $export['blog_posts'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_tags';
  $context->description = 'blog_tags';
  $context->tag = '';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'tags' => 'tags',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-blog_block_view-recent_ver1' => array(
          'module' => 'views',
          'delta' => 'blog_block_view-recent_ver1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-ds_blog_categories-cat' => array(
          'module' => 'views',
          'delta' => 'ds_blog_categories-cat',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-ds_blog_tags-tag' => array(
          'module' => 'views',
          'delta' => 'ds_blog_tags-tag',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blog_tags');
  $export['blog_tags'] = $context;

  return $export;
}
