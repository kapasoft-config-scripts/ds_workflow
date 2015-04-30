<?php
function _lib_assets_list(){
    $module_dir = drupal_get_path('module', 'designssquare_lib');
    return array (
        'public://avatar.jpg' => array(
            'uri' => 'public://avatar.jpg',
            'filename' => 'avatar.jpg',
            'source' => $module_dir.'/assets/img/avatar.jpg',
        ),
    );
}