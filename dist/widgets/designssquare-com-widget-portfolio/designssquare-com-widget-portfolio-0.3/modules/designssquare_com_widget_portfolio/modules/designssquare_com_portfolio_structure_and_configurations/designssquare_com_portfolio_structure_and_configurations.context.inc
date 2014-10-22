<?php
/**
 * @file
 * designssquare_com_portfolio_structure_and_configurations.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function designssquare_com_portfolio_structure_and_configurations_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portfolio_index';
  $context->description = '';
  $context->tag = 'designssquare.com.widget.portfolio';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ds_portfolio_index' => 'ds_portfolio_index',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'ds-portfolio' => 'ds-portfolio',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ds_portfolio_projects-projects' => array(
          'module' => 'views',
          'delta' => 'ds_portfolio_projects-projects',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-ds_portfolio_block-projects' => array(
          'module' => 'views',
          'delta' => 'ds_portfolio_block-projects',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('designssquare.com.widget.portfolio');
  $export['portfolio_index'] = $context;

  return $export;
}
