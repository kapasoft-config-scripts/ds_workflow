<?php
/**
 * @file
 * designssquare_com_theme_espresso_structure.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function designssquare_com_theme_espresso_structure_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'espresso_blog_entry';
  $context->description = 'layout for a blog entry - post';
  $context->tag = 'designssquare.com.theme.espresso';
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
          'weight' => '-10',
        ),
        'designssquare_com_theme_blocks-ds_about_sidebar' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_about_sidebar',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'designssquare_com_theme_blocks-ds_recent_tweets' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_recent_tweets',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'designssquare_com_theme_blocks-ds_blog_recent_posts_sidebar' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_recent_posts_sidebar',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'designssquare_com_theme_blocks-ds_blog_categories' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_categories',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'designssquare_com_theme_blocks-ds_blog_archive' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_archive',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'designssquare_com_theme_blocks-ds_blog_recent_posts' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_blog_recent_posts',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.theme.espresso');
  t('layout for a blog entry - post');
  $export['espresso_blog_entry'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'espresso_blog_posts';
  $context->description = 'layout for blog posts';
  $context->tag = 'designssquare.com.theme.espresso';
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
          'weight' => '-9',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-blog_block_view-recent_ver1' => array(
          'module' => 'views',
          'delta' => 'blog_block_view-recent_ver1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-ds_blog_categories-cat' => array(
          'module' => 'views',
          'delta' => 'ds_blog_categories-cat',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-ds_blog_tags-tag' => array(
          'module' => 'views',
          'delta' => 'ds_blog_tags-tag',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-ds_portfolio_block-projects' => array(
          'module' => 'views',
          'delta' => 'ds_portfolio_block-projects',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.theme.espresso');
  t('layout for blog posts');
  $export['espresso_blog_posts'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'espresso_home';
  $context->description = 'home page layout';
  $context->tag = 'designssquare.com.theme.espresso';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'home' => 'home',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'designssquare_com_theme_blocks-ds_announcement' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_announcement',
          'region' => 'row_one',
          'weight' => '-9',
        ),
        'views-ds_portfolio_teaser-projects' => array(
          'module' => 'views',
          'delta' => 'ds_portfolio_teaser-projects',
          'region' => 'row_two',
          'weight' => '-10',
        ),
        'designssquare_com_theme_blocks-ds_about' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_about',
          'region' => 'row_three',
          'weight' => '-9',
        ),
        'designssquare_com_theme_blocks-ds_recent_tweets' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_recent_tweets',
          'region' => 'row_three',
          'weight' => '-8',
        ),
        'views-ds_blog_slider-slider' => array(
          'module' => 'views',
          'delta' => 'ds_blog_slider-slider',
          'region' => 'row_three',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.theme.espresso');
  t('home page layout');
  $export['espresso_home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'espresso_site_wide';
  $context->description = 'state wide context for espresso theme';
  $context->tag = 'designssquare.com.theme.espresso';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'designssquare_com_theme_blocks-ds_copy_rights' => array(
          'module' => 'designssquare_com_theme_blocks',
          'delta' => 'ds_copy_rights',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'menu-menu-bottom-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-bottom-menu',
          'region' => 'footer_navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.theme.espresso');
  t('state wide context for espresso theme');
  $export['espresso_site_wide'] = $context;

  return $export;
}
