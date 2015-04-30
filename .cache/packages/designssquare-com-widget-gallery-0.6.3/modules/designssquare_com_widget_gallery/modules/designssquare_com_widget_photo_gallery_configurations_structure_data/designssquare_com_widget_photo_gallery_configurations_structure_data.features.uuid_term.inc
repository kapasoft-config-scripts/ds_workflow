<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_configurations_structure_data.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function designssquare_com_widget_photo_gallery_configurations_structure_data_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'personal',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
    'vocabulary_machine_name' => 'ds_gallery_tags',
  );
  $terms[] = array(
    'name' => 'vimeo',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4ff6a0ea-2346-4f61-b714-fdbc7f329699',
    'vocabulary_machine_name' => 'ds_gallery_items_tags',
  );
  $terms[] = array(
    'name' => 'Themes',
    'description' => '<p>themes category</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
    'vocabulary_machine_name' => 'field_ds_gallery_categories',
  );
  $terms[] = array(
    'name' => 'feature',
    'description' => '<p>tag for DS Gallery item</p>
',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '63cfbf22-1c29-45b4-a97a-360bd628b053',
    'vocabulary_machine_name' => 'ds_gallery_items_tags',
  );
  $terms[] = array(
    'name' => 'youtube',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '682d562b-0d45-4b7d-81b1-8967b57e80ae',
    'vocabulary_machine_name' => 'ds_gallery_items_tags',
  );
  $terms[] = array(
    'name' => 'corporate',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
    'vocabulary_machine_name' => 'ds_gallery_tags',
  );
  $terms[] = array(
    'name' => 'settings',
    'description' => '<p>tag for DS Gallery item</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'a54d9d97-8634-4bc7-bedd-4bc00e217e1c',
    'vocabulary_machine_name' => 'ds_gallery_items_tags',
  );
  $terms[] = array(
    'name' => 'video',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'aae8b309-da7e-4dbd-9aed-9343f1bd733d',
    'vocabulary_machine_name' => 'ds_gallery_items_tags',
  );
  $terms[] = array(
    'name' => 'Production',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'bd269dc8-986d-4b12-822a-121e4b37bc30',
    'vocabulary_machine_name' => 'ds_gallery_items_tags',
  );
  $terms[] = array(
    'name' => 'picture',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c108b780-7a29-4b18-89fd-0ce8b014f72f',
    'vocabulary_machine_name' => 'ds_gallery_items_tags',
  );
  $terms[] = array(
    'name' => 'real-estate',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c9b4ba86-2def-48ba-8962-2fc9573d4241',
    'vocabulary_machine_name' => 'ds_gallery_tags',
  );
  $terms[] = array(
    'name' => 'e-commerce',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd05199c8-d170-40ae-b3ac-6fa8aa290b2a',
    'vocabulary_machine_name' => 'ds_gallery_tags',
  );
  $terms[] = array(
    'name' => 'CKeditor Plugins',
    'description' => '<p>category for&nbsp;produts&nbsp;of type CKeditor plugins</p>
',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ecc0efb6-2ac1-4113-8ed5-664de42ca235',
    'vocabulary_machine_name' => 'field_ds_gallery_categories',
  );
  $terms[] = array(
    'name' => 'installation',
    'description' => '<p>tag for DS Gallery item</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'fa9dd62e-aaa0-4dc8-bcfa-c2109a7e7a55',
    'vocabulary_machine_name' => 'ds_gallery_items_tags',
  );
  $terms[] = array(
    'name' => 'Widgets',
    'description' => '<p>category for products of type widget</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'fe947b2a-9d18-4291-be61-81f41d98c04e',
    'vocabulary_machine_name' => 'field_ds_gallery_categories',
  );
  return $terms;
}
