<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_configurations_structure_data.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_taxonomy_default_vocabularies() {
  return array(
    'ds_gallery_items_tags' => array(
      'name' => 'DS Gallery Item Tags',
      'machine_name' => 'ds_gallery_items_tags',
      'description' => 'tags for items of Gallery such as image, video,etc',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'ds_gallery_tags' => array(
      'name' => 'DS Gallery Tags',
      'machine_name' => 'ds_gallery_tags',
      'description' => 'tags for DesignsSquare.com Gallery Widget',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'field_ds_gallery_categories' => array(
      'name' => 'DS Gallery Categories',
      'machine_name' => 'field_ds_gallery_categories',
      'description' => 'Categories for DS Gallery Widget',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
