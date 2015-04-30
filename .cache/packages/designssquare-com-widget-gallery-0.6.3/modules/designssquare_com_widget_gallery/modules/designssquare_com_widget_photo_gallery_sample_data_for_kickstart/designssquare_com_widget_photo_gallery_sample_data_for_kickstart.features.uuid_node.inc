<?php
/**
 * @file
 * designssquare_com_widget_photo_gallery_sample_data_for_kickstart.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function designssquare_com_widget_photo_gallery_sample_data_for_kickstart_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'title' => 'Gallery 5',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery',
  'language' => 'und',
  'created' => 1403367505,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '54c53a04-5c0e-4999-b6be-5be2b1ba07de',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_ds_gallery_featured_img' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'leaves-lg.jpg',
        'uri' => 'public://designssquare_com/widget/gallery/leaves-lg_1.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 131720,
        'status' => 1,
        'uuid' => '87adf29e-2d91-4079-87ef-638ec9a53609',
        'rdf_mapping' => array(),
        'alt' => '',
        'title' => '',
        'width' => 770,
        'height' => 500,
        'uuid_features_file_path' => 'public://designssquare_com/widget/gallery/leaves-lg_1.jpg',
      ),
    ),
  ),
  'field_ds_gallery_summary' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_gallery_page_intro' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_index_reference' => array(
    'und' => array(
      0 => array(
        'target_id' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
        'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
      ),
    ),
  ),
  'field_ds_gallery_categories' => array(
    'und' => array(
      0 => array(
        'tid' => 'ecc0efb6-2ac1-4113-8ed5-664de42ca235',
        'uuid' => 'ecc0efb6-2ac1-4113-8ed5-664de42ca235',
      ),
      1 => array(
        'tid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
        'uuid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
      ),
      2 => array(
        'tid' => 'fe947b2a-9d18-4291-be61-81f41d98c04e',
        'uuid' => 'fe947b2a-9d18-4291-be61-81f41d98c04e',
      ),
    ),
  ),
  'field_ds_gallery_tags' => array(
    'und' => array(
      0 => array(
        'tid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
        'uuid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
      ),
    ),
  ),
  'field_ds_gallery_item' => array(
    'und' => array(
      0 => array(
        'title' => 'Video',
        'ds_item_tag' => 'video',
        'image' => 0,
        'video' => array(
          'fid' => 138,
          'uid' => 1,
          'filename' => 'nature.mp4',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/video/nature.mp4',
          'filemime' => 'video/mp4',
          'filesize' => 1573484,
          'status' => 1,
          'timestamp' => 1421013840,
          'uuid' => '610586e4-4e54-434b-9367-651015ed94b3',
          'rdf_mapping' => array(),
        ),
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      1 => array(
        'title' => 'Image One',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 135,
          'uid' => 1,
          'filename' => 'leaves--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/leaves--lg.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 131720,
          'status' => 1,
          'timestamp' => 1420939348,
          'uuid' => 'd0c6d283-cf22-4671-b4b0-b38e6933935f',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      2 => array(
        'title' => 'Image Two',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 136,
          'uid' => 1,
          'filename' => 'snail--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/snail--lg.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 56316,
          'status' => 1,
          'timestamp' => 1420939348,
          'uuid' => '6f5ca173-c1a0-46c2-85b0-f349b9bb36bf',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      3 => array(
        'title' => 'Image Three',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 137,
          'uid' => 1,
          'filename' => 'flowers--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/flowers--lg.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 87190,
          'status' => 1,
          'timestamp' => 1420939348,
          'uuid' => 'a577a5a6-7c47-4f61-9799-5ccae0ecf41e',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      4 => array(
        'title' => 'Vimeo',
        'ds_item_tag' => 'video, vimeo',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => 45052672,
        'youtube_url' => '',
      ),
      5 => array(
        'title' => 'YouTube',
        'ds_item_tag' => 'video, youtube',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => 'Ixykj_V7ayo',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 11:18:25 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/photo-gallery-5',
);
  $nodes[] = array(
  'title' => 'Gallery 3',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery',
  'language' => 'und',
  'created' => 1403367363,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '56e887c3-0d19-43ef-8067-2d54354d4e8b',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_ds_gallery_featured_img' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'flowers-lg.jpg',
        'uri' => 'public://designssquare_com/widget/gallery/flowers-lg_1.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 87190,
        'status' => 1,
        'uuid' => '37b26fe8-0f59-4da4-ab5a-4835363024b6',
        'rdf_mapping' => array(),
        'alt' => '',
        'title' => '',
        'width' => 770,
        'height' => 500,
        'uuid_features_file_path' => 'public://designssquare_com/widget/gallery/flowers-lg_1.jpg',
      ),
    ),
  ),
  'field_ds_gallery_summary' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_gallery_page_intro' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_index_reference' => array(
    'und' => array(
      0 => array(
        'target_id' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
        'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
      ),
    ),
  ),
  'field_ds_gallery_categories' => array(
    'und' => array(
      0 => array(
        'tid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
        'uuid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
      ),
    ),
  ),
  'field_ds_gallery_tags' => array(
    'und' => array(
      0 => array(
        'tid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
        'uuid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
      ),
      1 => array(
        'tid' => 'c9b4ba86-2def-48ba-8962-2fc9573d4241',
        'uuid' => 'c9b4ba86-2def-48ba-8962-2fc9573d4241',
      ),
      2 => array(
        'tid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
        'uuid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
      ),
    ),
  ),
  'field_ds_gallery_item' => array(
    'und' => array(
      0 => array(
        'title' => 'Butterfly',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 139,
          'uid' => 1,
          'filename' => 'butterfly--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/butterfly--lg.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 205107,
          'status' => 1,
          'timestamp' => 1421014993,
          'uuid' => 'a7e95b9b-763a-4622-adda-c544e5367bbb',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      1 => array(
        'title' => 'Vimeo Video',
        'ds_item_tag' => 'vimeo, video',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => 45052672,
        'youtube_url' => '',
      ),
      2 => array(
        'title' => 'Green Bird',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 140,
          'uid' => 1,
          'filename' => 'birdgreen--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdgreen--lg.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 51161,
          'status' => 1,
          'timestamp' => 1421014993,
          'uuid' => '3b5f0f7e-d07a-4a26-8d4e-c34410915d9b',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      3 => array(
        'title' => 'YouTube Video',
        'ds_item_tag' => 'video, youtube',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => 'Ixykj_V7ayo',
      ),
      4 => array(
        'title' => 'Leaves',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 141,
          'uid' => 1,
          'filename' => 'leaves--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/leaves--lg_0.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 131720,
          'status' => 1,
          'timestamp' => 1421014993,
          'uuid' => '7052256b-11af-4104-b84c-4d90073939fc',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      5 => array(
        'title' => 'Video',
        'ds_item_tag' => 'picture',
        'image' => 0,
        'video' => array(
          'fid' => 142,
          'uid' => 1,
          'filename' => 'nature.mp4',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/video/nature_0.mp4',
          'filemime' => 'video/mp4',
          'filesize' => 1573484,
          'status' => 1,
          'timestamp' => 1421015070,
          'uuid' => '51b9af0a-346a-47e2-8850-b502d6e33e60',
          'rdf_mapping' => array(),
        ),
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 11:16:03 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/photo-gallery-3',
);
  $nodes[] = array(
  'title' => 'Gallery 6',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery',
  'language' => 'und',
  'created' => 1403367572,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '62fc85e6-c05d-4f2b-97db-fddf273b9ec4',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
        'summary' => '',
        'format' => 'filtered_html',
      ),
    ),
  ),
  'field_ds_gallery_featured_img' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'snail-lg.jpg',
        'uri' => 'public://designssquare_com/widget/gallery/snail-lg_1.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 56316,
        'status' => 1,
        'uuid' => '0a1783e0-a5f1-496e-884a-11a3bafc91b6',
        'rdf_mapping' => array(),
        'alt' => '',
        'title' => '',
        'width' => 770,
        'height' => 500,
        'uuid_features_file_path' => 'public://designssquare_com/widget/gallery/snail-lg_1.jpg',
      ),
    ),
  ),
  'field_ds_gallery_summary' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_gallery_page_intro' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_index_reference' => array(
    'und' => array(
      0 => array(
        'target_id' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
        'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
      ),
    ),
  ),
  'field_ds_gallery_categories' => array(
    'und' => array(
      0 => array(
        'tid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
        'uuid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
      ),
      1 => array(
        'tid' => 'fe947b2a-9d18-4291-be61-81f41d98c04e',
        'uuid' => 'fe947b2a-9d18-4291-be61-81f41d98c04e',
      ),
    ),
  ),
  'field_ds_gallery_tags' => array(
    'und' => array(
      0 => array(
        'tid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
        'uuid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
      ),
    ),
  ),
  'field_ds_gallery_item' => array(
    'und' => array(
      0 => array(
        'title' => 'Picture',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 143,
          'uid' => 1,
          'filename' => 'butterfly--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/butterfly--lg_0.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 205107,
          'status' => 1,
          'timestamp' => 1421016516,
          'uuid' => '248d1885-be6e-44a6-9c55-0864a412c2ae',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      1 => array(
        'title' => 'Vimeo',
        'ds_item_tag' => 'vimeo, video',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => 45052672,
        'youtube_url' => '',
      ),
      2 => array(
        'title' => 'Youtube ',
        'ds_item_tag' => 'video, youtube',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => 'Ixykj_V7ayo',
      ),
      3 => array(
        'title' => 'Flowers',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 144,
          'uid' => 1,
          'filename' => 'flowers--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/flowers--lg_0.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 87190,
          'status' => 1,
          'timestamp' => 1421016516,
          'uuid' => '112ae6eb-d42e-49bb-93bf-de1b275139eb',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      4 => array(
        'title' => 'Snail',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 147,
          'uid' => 1,
          'filename' => 'snail--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/snail--lg_0.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 56316,
          'status' => 1,
          'timestamp' => 1421016585,
          'uuid' => '3af46176-42ed-4862-9b0b-2c45ea67c721',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      5 => array(
        'title' => 'Nature Video',
        'ds_item_tag' => 'video',
        'image' => 0,
        'video' => array(
          'fid' => 146,
          'uid' => 1,
          'filename' => 'nature.mp4',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/video/nature_1.mp4',
          'filemime' => 'video/mp4',
          'filesize' => 1573484,
          'status' => 1,
          'timestamp' => 1421016516,
          'uuid' => '12e09386-04b0-47d1-8f64-9047b676cc03',
          'rdf_mapping' => array(),
        ),
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 11:19:32 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/photo-gallery-6',
);
  $nodes[] = array(
  'title' => 'Gallery Index',
  'log' => '',
  'status' => 1,
  'comment' => 1,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery_index',
  'language' => 'und',
  'created' => 1403398172,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
  'field_ds_gallery_page_intro' => array(),
  'field_breadcrumb_category' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 19:49:32 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/gallery-index',
);
  $nodes[] = array(
  'title' => 'Gallery 4',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery',
  'language' => 'und',
  'created' => 1403367432,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '9bbc168b-23e7-466b-b6f1-80661c5737b9',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_ds_gallery_featured_img' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'birdsepia-lg.jpg',
        'uri' => 'public://designssquare_com/widget/gallery/birdsepia-lg_1.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 157052,
        'status' => 1,
        'uuid' => '15130059-74c2-4241-a971-e4774279b2da',
        'rdf_mapping' => array(),
        'alt' => '',
        'title' => '',
        'width' => 770,
        'height' => 500,
        'uuid_features_file_path' => 'public://designssquare_com/widget/gallery/birdsepia-lg_1.jpg',
      ),
    ),
  ),
  'field_ds_gallery_summary' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_gallery_page_intro' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor ',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_index_reference' => array(
    'und' => array(
      0 => array(
        'target_id' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
        'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
      ),
    ),
  ),
  'field_ds_gallery_categories' => array(
    'und' => array(
      0 => array(
        'tid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
        'uuid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
      ),
    ),
  ),
  'field_ds_gallery_tags' => array(
    'und' => array(
      0 => array(
        'tid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
        'uuid' => '438ffcb0-14bd-41ca-845a-2aa669b08379',
      ),
      1 => array(
        'tid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
        'uuid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
      ),
    ),
  ),
  'field_ds_gallery_item' => array(
    'und' => array(
      0 => array(
        'title' => 'Bird Retro',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 148,
          'uid' => 1,
          'filename' => 'birdretro--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdretro--lg.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 226865,
          'status' => 1,
          'timestamp' => 1421026299,
          'uuid' => 'f649f1a1-ae12-47db-ac9b-4fbe87c035ef',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      1 => array(
        'title' => 'Vimeo',
        'ds_item_tag' => 'video, vimeo',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => 45052672,
        'youtube_url' => '',
      ),
      2 => array(
        'title' => 'Flowers',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 149,
          'uid' => 1,
          'filename' => 'flowers--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/flowers--lg_1.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 87190,
          'status' => 1,
          'timestamp' => 1421026299,
          'uuid' => 'e4d5f911-3373-4afa-a256-c36b02c8b7f2',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      3 => array(
        'title' => 'Video',
        'ds_item_tag' => 'video',
        'image' => 0,
        'video' => array(
          'fid' => 150,
          'uid' => 1,
          'filename' => 'nature.mp4',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/video/nature_2.mp4',
          'filemime' => 'video/mp4',
          'filesize' => 1573484,
          'status' => 1,
          'timestamp' => 1421026299,
          'uuid' => '815e33e1-588c-4001-997d-62c867a5054a',
          'rdf_mapping' => array(),
        ),
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      4 => array(
        'title' => 'YouTube',
        'ds_item_tag' => 'video, youtube',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => 'Ixykj_V7ayo',
      ),
      5 => array(
        'title' => 'Birds Sepia',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 151,
          'uid' => 1,
          'filename' => 'birdsepia-lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdsepia-lg.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 157052,
          'status' => 1,
          'timestamp' => 1421026299,
          'uuid' => 'e0a9ea10-4be7-4a45-952b-24a50d4fa1d4',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 11:17:12 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/photo-gallery-4',
);
  $nodes[] = array(
  'title' => 'Gallery 1',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery',
  'language' => 'und',
  'created' => 1403367142,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'a0e135c6-3eb4-48ad-9efd-da89fea41e89',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_ds_gallery_featured_img' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'butterfly-lg.jpg',
        'uri' => 'public://designssquare_com/widget/gallery/butterfly-lg.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 205107,
        'status' => 1,
        'uuid' => 'ef8502fa-f288-4977-a5e7-b31fa78b9f4a',
        'rdf_mapping' => array(),
        'alt' => '',
        'title' => '',
        'width' => 770,
        'height' => 500,
        'uuid_features_file_path' => 'public://designssquare_com/widget/gallery/butterfly-lg.jpg',
      ),
    ),
  ),
  'field_ds_gallery_summary' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_gallery_page_intro' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_index_reference' => array(
    'und' => array(
      0 => array(
        'target_id' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
        'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
      ),
    ),
  ),
  'field_ds_gallery_categories' => array(
    'und' => array(
      0 => array(
        'tid' => 'fe947b2a-9d18-4291-be61-81f41d98c04e',
        'uuid' => 'fe947b2a-9d18-4291-be61-81f41d98c04e',
      ),
    ),
  ),
  'field_ds_gallery_tags' => array(
    'und' => array(
      0 => array(
        'tid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
        'uuid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
      ),
    ),
  ),
  'field_ds_gallery_item' => array(
    'und' => array(
      0 => array(
        'title' => 'Retro Bird',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 152,
          'uid' => 1,
          'filename' => 'birdretro--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdretro--lg_0.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 226865,
          'status' => 1,
          'timestamp' => 1421026923,
          'uuid' => '628b3c29-d8bd-4cc3-ba44-ac9d9cffae39',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      1 => array(
        'title' => 'Bird Fat',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 153,
          'uid' => 1,
          'filename' => 'birdfat-lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdfat-lg.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 53129,
          'status' => 1,
          'timestamp' => 1421026923,
          'uuid' => 'ca22e4ba-0bcd-4ce9-948c-7a23cc66f514',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      2 => array(
        'title' => 'Video',
        'ds_item_tag' => 'video',
        'image' => 0,
        'video' => array(
          'fid' => 154,
          'uid' => 1,
          'filename' => 'nature.mp4',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/video/nature_3.mp4',
          'filemime' => 'video/mp4',
          'filesize' => 1573484,
          'status' => 1,
          'timestamp' => 1421026923,
          'uuid' => '8b4973a5-1e35-48bd-b801-931671058c0d',
          'rdf_mapping' => array(),
        ),
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      3 => array(
        'title' => 'Bird Sepia',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 155,
          'uid' => 1,
          'filename' => 'birdsepia-lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdsepia-lg_1.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 157052,
          'status' => 1,
          'timestamp' => 1421026923,
          'uuid' => '1b480a65-fbdc-473b-8488-65ce6922325f',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      4 => array(
        'title' => 'Vimeo',
        'ds_item_tag' => 'vimeo, video',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => 45052672,
        'youtube_url' => '',
      ),
      5 => array(
        'title' => 'YouTube',
        'ds_item_tag' => 'video, youtube',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => 'Ixykj_V7ayo',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 11:12:22 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/photo-gallery-1',
);
  $nodes[] = array(
  'title' => 'Gallery 2',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery',
  'language' => 'und',
  'created' => 1403367279,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'b5f13041-92fc-4d68-92df-6fa967ebdb59',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_ds_gallery_featured_img' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'birdgreen-lg.jpg',
        'uri' => 'public://designssquare_com/widget/gallery/birdgreen-lg_0.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 51161,
        'status' => 1,
        'uuid' => '0f843112-c856-4920-a270-2300035209a3',
        'rdf_mapping' => array(),
        'alt' => '',
        'title' => '',
        'width' => 770,
        'height' => 500,
        'uuid_features_file_path' => 'public://designssquare_com/widget/gallery/birdgreen-lg_0.jpg',
      ),
    ),
  ),
  'field_ds_gallery_summary' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_gallery_page_intro' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_index_reference' => array(
    'und' => array(
      0 => array(
        'target_id' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
        'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
      ),
    ),
  ),
  'field_ds_gallery_categories' => array(
    'und' => array(
      0 => array(
        'tid' => 'ecc0efb6-2ac1-4113-8ed5-664de42ca235',
        'uuid' => 'ecc0efb6-2ac1-4113-8ed5-664de42ca235',
      ),
      1 => array(
        'tid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
        'uuid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
      ),
    ),
  ),
  'field_ds_gallery_tags' => array(
    'und' => array(
      0 => array(
        'tid' => 'd05199c8-d170-40ae-b3ac-6fa8aa290b2a',
        'uuid' => 'd05199c8-d170-40ae-b3ac-6fa8aa290b2a',
      ),
      1 => array(
        'tid' => 'c9b4ba86-2def-48ba-8962-2fc9573d4241',
        'uuid' => 'c9b4ba86-2def-48ba-8962-2fc9573d4241',
      ),
    ),
  ),
  'field_ds_gallery_item' => array(
    'und' => array(
      0 => array(
        'title' => 'Butterfly',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 156,
          'uid' => 1,
          'filename' => 'butterfly--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/butterfly--lg_1.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 205107,
          'status' => 1,
          'timestamp' => 1421027649,
          'uuid' => 'e8f830df-a47f-41e5-9730-3a82fca748c6',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      1 => array(
        'title' => 'Vimeo',
        'ds_item_tag' => 'video, vimeo',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => 45052672,
        'youtube_url' => '',
      ),
      2 => array(
        'title' => 'Retro Bird',
        'ds_item_tag' => 'video',
        'image' => array(
          'fid' => 157,
          'uid' => 1,
          'filename' => 'birdretro--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdretro--lg_1.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 226865,
          'status' => 1,
          'timestamp' => 1421027649,
          'uuid' => 'f6320af3-abac-4df0-9aea-743d3a224be1',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      3 => array(
        'title' => 'YouTube Video',
        'ds_item_tag' => 'video, youtube',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => 'Ixykj_V7ayo',
      ),
      4 => array(
        'title' => 'Leaves',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 158,
          'uid' => 1,
          'filename' => 'leaves--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/leaves--lg_1.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 131720,
          'status' => 1,
          'timestamp' => 1421027649,
          'uuid' => 'd661e56b-e363-46c6-89c3-0fc950969076',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      5 => array(
        'title' => 'Video',
        'ds_item_tag' => 'video',
        'image' => 0,
        'video' => array(
          'fid' => 159,
          'uid' => 1,
          'filename' => 'nature.mp4',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/video/nature_4.mp4',
          'filemime' => 'video/mp4',
          'filesize' => 1573484,
          'status' => 1,
          'timestamp' => 1421027649,
          'uuid' => 'd2947977-3f57-4502-95be-f5d858d533e5',
          'rdf_mapping' => array(),
        ),
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 11:14:39 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/photo-gallery-2',
);
  $nodes[] = array(
  'title' => 'Gallery 8',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery',
  'language' => 'und',
  'created' => 1403367736,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'bc8e34ff-eb8d-4fc2-b7f8-fe32df257eb7',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_ds_gallery_featured_img' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'birdfat-lg.jpg',
        'uri' => 'public://designssquare_com/widget/gallery/birdfat-lg_3.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 53129,
        'status' => 1,
        'uuid' => '93c60039-0487-4f9c-871a-c0d762248414',
        'rdf_mapping' => array(),
        'alt' => '',
        'title' => '',
        'width' => 770,
        'height' => 500,
        'uuid_features_file_path' => 'public://designssquare_com/widget/gallery/birdfat-lg_3.jpg',
      ),
    ),
  ),
  'field_ds_gallery_summary' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_gallery_page_intro' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_index_reference' => array(
    'und' => array(
      0 => array(
        'target_id' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
        'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
      ),
    ),
  ),
  'field_ds_gallery_categories' => array(
    'und' => array(
      0 => array(
        'tid' => 'ecc0efb6-2ac1-4113-8ed5-664de42ca235',
        'uuid' => 'ecc0efb6-2ac1-4113-8ed5-664de42ca235',
      ),
    ),
  ),
  'field_ds_gallery_tags' => array(
    'und' => array(
      0 => array(
        'tid' => 'c9b4ba86-2def-48ba-8962-2fc9573d4241',
        'uuid' => 'c9b4ba86-2def-48ba-8962-2fc9573d4241',
      ),
    ),
  ),
  'field_ds_gallery_item' => array(
    'und' => array(
      0 => array(
        'title' => 'Bird Fat',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 160,
          'uid' => 1,
          'filename' => 'birdfat-lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdfat-lg_0.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 53129,
          'status' => 1,
          'timestamp' => 1421028260,
          'uuid' => '87519682-dc09-4ad2-9865-dc68f2942d73',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      1 => array(
        'title' => 'Video',
        'ds_item_tag' => 'video',
        'image' => 0,
        'video' => array(
          'fid' => 161,
          'uid' => 1,
          'filename' => 'nature.mp4',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/video/nature_5.mp4',
          'filemime' => 'video/mp4',
          'filesize' => 1573484,
          'status' => 1,
          'timestamp' => 1421028260,
          'uuid' => '12408b8f-0692-4b96-bd97-9e67a9c895e5',
          'rdf_mapping' => array(),
        ),
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      2 => array(
        'title' => 'Flowers',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 162,
          'uid' => 1,
          'filename' => 'flowers--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/flowers--lg_2.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 87190,
          'status' => 1,
          'timestamp' => 1421028260,
          'uuid' => 'e18fbfbf-7720-4b3e-a3eb-9b0876c06640',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      3 => array(
        'title' => 'Vimeo',
        'ds_item_tag' => 'video, vimeo',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => 45052672,
        'youtube_url' => '',
      ),
      4 => array(
        'title' => 'Bird Green',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 163,
          'uid' => 1,
          'filename' => 'birdgreen--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdgreen--lg_0.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 51161,
          'status' => 1,
          'timestamp' => 1421028260,
          'uuid' => '05b44a0c-ec99-4d08-97ce-b4f1e966037f',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      5 => array(
        'title' => 'YouTube',
        'ds_item_tag' => 'video, youtube',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => 'Ixykj_V7ayo',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 11:22:16 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/photo-gallery-8',
);
  $nodes[] = array(
  'title' => 'Gallery 7',
  'log' => '',
  'status' => 1,
  'comment' => 2,
  'promote' => 0,
  'sticky' => 0,
  'type' => 'ds_gallery',
  'language' => 'und',
  'created' => 1403367660,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'cc7eb6c7-fdf4-4f23-b137-96f10e274360',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '
<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
',
        'summary' => '',
        'format' => 'full_html',
      ),
    ),
  ),
  'field_ds_gallery_featured_img' => array(
    'und' => array(
      0 => array(
        'uid' => 1,
        'filename' => 'birdretro--lg.jpg',
        'uri' => 'public://designssquare_com/widget/gallery/birdretro--lg.jpg',
        'filemime' => 'image/jpeg',
        'filesize' => 226865,
        'status' => 1,
        'uuid' => '84f0745a-1ad9-4cd9-a14e-93c9ab5ee925',
        'rdf_mapping' => array(),
        'alt' => '',
        'title' => '',
        'width' => 770,
        'height' => 500,
        'uuid_features_file_path' => 'public://designssquare_com/widget/gallery/birdretro--lg.jpg',
      ),
    ),
  ),
  'field_ds_gallery_summary' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_gallery_page_intro' => array(
    'und' => array(
      0 => array(
        'value' => 'Lorem ipsum dolor ',
        'format' => NULL,
      ),
    ),
  ),
  'field_ds_index_reference' => array(
    'und' => array(
      0 => array(
        'target_id' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
        'uuid' => '887f4a83-deff-464f-a371-3a63dfc2ccde',
      ),
    ),
  ),
  'field_ds_gallery_categories' => array(
    'und' => array(
      0 => array(
        'tid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
        'uuid' => '6017bc9c-bc4a-454c-b7a0-d3955a52b461',
      ),
    ),
  ),
  'field_ds_gallery_tags' => array(
    'und' => array(
      0 => array(
        'tid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
        'uuid' => '8b2b210f-97fc-468d-88b2-3a1340659164',
      ),
      1 => array(
        'tid' => 'd05199c8-d170-40ae-b3ac-6fa8aa290b2a',
        'uuid' => 'd05199c8-d170-40ae-b3ac-6fa8aa290b2a',
      ),
    ),
  ),
  'field_ds_gallery_item' => array(
    'und' => array(
      0 => array(
        'title' => 'Retro Bird',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 164,
          'uid' => 1,
          'filename' => 'birdretro--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdretro--lg_2.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 226865,
          'status' => 1,
          'timestamp' => 1421029013,
          'uuid' => '7c483f06-914a-49ea-a263-b9d24dbf13b1',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      1 => array(
        'title' => 'Nature',
        'ds_item_tag' => 'video',
        'image' => 0,
        'video' => array(
          'fid' => 165,
          'uid' => 1,
          'filename' => 'nature.mp4',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/video/nature_6.mp4',
          'filemime' => 'video/mp4',
          'filesize' => 1573484,
          'status' => 1,
          'timestamp' => 1421029013,
          'uuid' => '41143877-9c9e-4ca8-b9f1-d6e5a9e3b452',
          'rdf_mapping' => array(),
        ),
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      2 => array(
        'title' => 'Vimeo',
        'ds_item_tag' => 'video, vimeo',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => 45052672,
        'youtube_url' => '',
      ),
      3 => array(
        'title' => 'YouTube',
        'ds_item_tag' => 'video, youtube',
        'image' => 0,
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => 'Ixykj_V7ayo',
      ),
      4 => array(
        'title' => 'Sepia',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 166,
          'uid' => 1,
          'filename' => 'birdsepia-lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/birdsepia-lg_2.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 157052,
          'status' => 1,
          'timestamp' => 1421029013,
          'uuid' => 'fd89616e-06b2-482d-93ce-b39f2811dcb7',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
      5 => array(
        'title' => 'Flowers',
        'ds_item_tag' => 'picture',
        'image' => array(
          'fid' => 167,
          'uid' => 1,
          'filename' => 'flowers--lg.jpg',
          'uri' => 'public://designssquare_com_widget_gallery/gallery-items/img/flowers--lg_3.jpg',
          'filemime' => 'image/jpeg',
          'filesize' => 87190,
          'status' => 1,
          'timestamp' => 1421029013,
          'uuid' => '2e2ef346-4226-43df-b1c2-04211cbc7f88',
          'rdf_mapping' => array(),
        ),
        'video' => 0,
        'vimeo_id' => '',
        'youtube_url' => '',
      ),
    ),
  ),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'comment_count' => 0,
  'date' => '2014-06-21 11:21:00 -0500',
  'user_uuid' => 'f527ad70-245c-4e57-bffa-53a810535f69',
  'alias_url' => 'content/photo-gallery-7',
);
  return $nodes;
}
