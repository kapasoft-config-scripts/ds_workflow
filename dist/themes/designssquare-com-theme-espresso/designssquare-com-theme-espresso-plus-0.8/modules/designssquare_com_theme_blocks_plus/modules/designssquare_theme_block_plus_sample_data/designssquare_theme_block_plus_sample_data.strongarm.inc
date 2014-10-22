<?php
/**
 * @file
 * designssquare_theme_block_plus_sample_data.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function designssquare_theme_block_plus_sample_data_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_about__content_block__content';
  $strongarm->value = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua  Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua ';
  $export['ds_about__content_block__content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    'fid' => '56',
    'uid' => '1',
    'filename' => 'bio.jpg',
    'uri' => 'public://designssquare_com_theme_blocks/assets/img/bio.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => '3993',
    'status' => '1',
    'timestamp' => '1402840043',
    'uuid' => '64b4a691-5b53-428a-8809-7de009d9f70f',
    'rdf_mapping' => array(),
  );
  $strongarm->name = 'ds_about__content_block__image';
  $strongarm->value = '56';
  $export['ds_about__content_block__image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_about__content_block__reference';
  $strongarm->value = 'about';
  $export['ds_about__content_block__reference'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_about__content_block__title';
  $strongarm->value = 'About Me';
  $export['ds_about__content_block__title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_announcement__content_block__content';
  $strongarm->value = '<h2 class="lead">A clean, minimal, responsive blog &amp; portfolio theme for businesses &amp; creatives</h2>
';
  $export['ds_announcement__content_block__content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_blog_archive__content_block__content';
  $strongarm->value = '    <ul class="nav">
        <li><a href="archives.html"><span class="glyphicon glyphicon-calendar"></span> 2007</a></li>
        <li><a href="archives.html"><span class="glyphicon glyphicon-calendar"></span> 2008</a></li>
        <li><a href="archives.html"><span class="glyphicon glyphicon-calendar"></span> 2009</a></li>
        <li><a href="archives.html"><span class="glyphicon glyphicon-calendar"></span> 2010</a></li>
        <li><a href="archives.html"><span class="glyphicon glyphicon-calendar"></span> 2011</a></li>
        <li><a href="archives.html"><span class="glyphicon glyphicon-calendar"></span> 2012</a></li>
    </ul>';
  $export['ds_blog_archive__content_block__content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_blog_archive__content_block__title';
  $strongarm->value = 'Archive';
  $export['ds_blog_archive__content_block__title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_blog_categories__content_block__content';
  $strongarm->value = '<ul class="nav">
	<li><a href="categories.html"><span class="glyphicon glyphicon-list"></span> Books</a></li>
	<li><a href="categories.html"><span class="glyphicon glyphicon-list"></span> Travel</a></li>
	<li><a href="categories.html"><span class="glyphicon glyphicon-list"></span> Portfolio</a></li>
	<li><a href="categories.html"><span class="glyphicon glyphicon-list"></span> Music</a></li>
</ul>
';
  $export['ds_blog_categories__content_block__content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_blog_categories__content_block__title';
  $strongarm->value = 'Categories';
  $export['ds_blog_categories__content_block__title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_blog_recent_posts_sidebar__content_block__content';
  $strongarm->value = '<ul class="nav">
	<li><a href="/"><span class="glyphicon glyphicon-folder-close"></span> The Emerald City of Oz</a></li>
	<li><a href="/"><span class="glyphicon glyphicon-folder-close"></span> Yellow Brick Road</a></li>
	<li><a href="/"><span class="glyphicon glyphicon-folder-close"></span> Somewhere Over The Rainbow</a></li>
</ul>
';
  $export['ds_blog_recent_posts_sidebar__content_block__content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_blog_recent_posts_sidebar__content_block__title';
  $strongarm->value = 'Recent Posts';
  $export['ds_blog_recent_posts_sidebar__content_block__title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_copy_rights__content_block__content';
  $strongarm->value = '<p>&copy; Copyright Espresso Theme</p>';
  $export['ds_copy_rights__content_block__content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_recent_tweets__content_block__button_text';
  $strongarm->value = 'Follow me on Twitter';
  $export['ds_recent_tweets__content_block__button_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_recent_tweets__content_block__content';
  $strongarm->value = '        <blockquote>
        Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua
    </blockquote>';
  $export['ds_recent_tweets__content_block__content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_recent_tweets__content_block__link';
  $strongarm->value = '#';
  $export['ds_recent_tweets__content_block__link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_recent_tweets__content_block__title';
  $strongarm->value = 'Recent Tweets';
  $export['ds_recent_tweets__content_block__title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_social__content_block__content';
  $strongarm->value = '    <ul class="nav">
        <li><a href="/"><span class="glyphicon glyphicon-link"></span> Twitter</a></li>
        <li><a href="/"><span class="glyphicon glyphicon-link"></span> Facebook</a></li>
        <li><a href="/"><span class="glyphicon glyphicon-link"></span> Flickr</a></li>
        <li><a href="/"><span class="glyphicon glyphicon-link"></span> Last.fm</a></li>
    </ul>';
  $export['ds_social__content_block__content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->file = array(
    0 => '',
  );
  $strongarm->name = 'ds_social__content_block__title';
  $strongarm->value = 'Elsewhere';
  $export['ds_social__content_block__title'] = $strongarm;

  return $export;
}
