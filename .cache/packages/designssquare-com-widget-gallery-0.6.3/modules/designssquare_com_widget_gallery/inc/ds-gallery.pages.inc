<?php

function gallery_display(){

    $nid = db_select('node', 'n')
        ->fields('n', array('nid'))
        ->fields('n', array('type'))
        ->condition('n.type', 'ds_gallery_index')
        ->range(0, 1)
        ->orderBy('nid', 'DESC')
        ->execute()
        ->fetchCol();

    if (isset($nid[0]) && is_numeric($nid[0])) {
        //prepare content for rendering including set cache, activate context,etc
        init_content($nid[0]);
    }

    return array(
        '#theme' => 'render_gallery',
        '#view_mode' => 'full',
        '#type' => 'page',
    );
}