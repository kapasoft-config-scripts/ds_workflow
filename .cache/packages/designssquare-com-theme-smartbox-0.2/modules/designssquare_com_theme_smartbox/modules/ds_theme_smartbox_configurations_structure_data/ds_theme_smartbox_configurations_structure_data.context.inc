<?php
/**
 * @file
 * ds_theme_smartbox_configurations_structure_data.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ds_theme_smartbox_configurations_structure_data_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'smartbox_blog';
  $context->description = 'context for normal blog page';
  $context->tag = 'designssquare.com.theme.smartbox';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'normal-blog' => 'normal-blog',
        'post' => 'post',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'designssquare_com_theme_blocks-ds_blog_recent_posts_sidebar' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_recent_posts_sidebar',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'designssquare_com_theme_blocks-ds_blog_categories' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_categories',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'designssquare_com_theme_blocks-ds_blog_tags' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_tags',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'designssquare_com_theme_blocks-ds_blog_archive' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_archive',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'designssquare_com_theme_blocks-ds_recent_tweets' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_recent_tweets',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for normal blog page');
  t('designssquare.com.theme.smartbox');
  $export['smartbox_blog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'smartbox_contact';
  $context->description = 'contact context for smartbox theme';
  $context->tag = 'designssquare.com.theme.smartbox';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'contact' => 'contact',
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
          'weight' => '-10',
        ),
        'designssquare_com_theme_blocks-ds_contact_info' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_contact_info',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'designssquare_lib_template_api-contact_form_teaser' => array(
          'module' => 'designssquare_lib_template_api',
          'delta' => 'contact_form_teaser',
          'region' => 'node_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('contact context for smartbox theme');
  t('designssquare.com.theme.smartbox');
  $export['smartbox_contact'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'smartbox_left_sidebar';
  $context->description = 'right sidebar layout of Drupal Theme - Smartbox';
  $context->tag = 'designssquare.com.theme.smartbox';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'left-sidebar' => 'left-sidebar',
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
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'designssquare_com_theme_blocks-ds_recent_tweets' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_recent_tweets',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'designssquare_com_theme_blocks-ds_blog_recent_posts_sidebar' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_recent_posts_sidebar',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'designssquare_com_theme_blocks-ds_blog_categories' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_categories',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'designssquare_com_theme_blocks-ds_blog_tags' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_tags',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'designssquare_com_theme_blocks-ds_blog_archive' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_archive',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'designssquare_com_theme_blocks-ds_blog_recent_posts' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_recent_posts',
          'region' => 'node_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.theme.smartbox');
  t('right sidebar layout of Drupal Theme - Smartbox');
  $export['smartbox_left_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'smartbox_right_sidebar';
  $context->description = 'right sidebar layout of Drupal Theme - Smartbox';
  $context->tag = 'designssquare.com.theme.smartbox';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'right-sidebar' => 'right-sidebar',
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
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'designssquare_com_theme_blocks-ds_blog_categories' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_categories',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'designssquare_com_theme_blocks-ds_blog_tags' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_tags',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'designssquare_com_theme_blocks-ds_blog_archive' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_archive',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'designssquare_com_theme_blocks-ds_blog_recent_posts_sidebar' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_recent_posts_sidebar',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'designssquare_com_theme_blocks-ds_recent_tweets' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_recent_tweets',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'designssquare_com_theme_blocks-ds_blog_recent_posts' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_recent_posts',
          'region' => 'node_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.theme.smartbox');
  t('right sidebar layout of Drupal Theme - Smartbox');
  $export['smartbox_right_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'smartbox_statewide';
  $context->description = 'the state wide context of the Drupal Theme - Smartbox';
  $context->tag = 'designssquare.com.theme.smartbox';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~smartbox_right_sidebar' => '~smartbox_right_sidebar',
        '~smartbox_left_sidebar' => '~smartbox_left_sidebar',
        '~smartbox_blog' => '~smartbox_blog',
        '~smartbox_contact' => '~smartbox_contact',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
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
        'designssquare_com_theme_blocks-ds_slider_flex_full' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_slider_flex_full',
          'region' => 'node_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.theme.smartbox');
  t('the state wide context of the Drupal Theme - Smartbox');
  $export['smartbox_statewide'] = $context;

  return $export;
}
