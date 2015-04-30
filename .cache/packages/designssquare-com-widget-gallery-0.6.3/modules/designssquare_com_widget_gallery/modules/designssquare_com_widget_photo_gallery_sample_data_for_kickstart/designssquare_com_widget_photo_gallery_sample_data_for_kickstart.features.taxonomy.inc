<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_sample_data_for_kickstart.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function designssquare_com_widget_photo_gallery_sample_data_for_kickstart_taxonomy_default_vocabularies() {
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
  );
}
