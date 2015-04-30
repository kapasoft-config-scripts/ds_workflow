<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_configurations_structure_data.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gallery_index';
  $context->description = 'context of the Gallery Index space';
  $context->tag = 'designssquare.com.widget.gallery';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ds_gallery_index' => 'ds_gallery_index',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'ds-gallery' => 'ds-gallery',
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
          'weight' => '-19',
        ),
        'views-ds_gallery_all-all' => array(
          'module' => 'views',
          'delta' => 'ds_gallery_all-all',
          'region' => 'content',
          'weight' => '-18',
        ),
        'views-ds_gallery_block-block' => array(
          'module' => 'views',
          'delta' => 'ds_gallery_block-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context of the Gallery Index space');
  t('designssquare.com.widget.gallery');
  $export['gallery_index'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'gallery_single';
  $context->description = '';
  $context->tag = 'designssquare.com.widget.gallery';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ds_gallery' => 'ds_gallery',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ds_gallery_block-block' => array(
          'module' => 'views',
          'delta' => 'ds_gallery_block-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.widget.gallery');
  $export['gallery_single'] = $context;

  return $export;
}
