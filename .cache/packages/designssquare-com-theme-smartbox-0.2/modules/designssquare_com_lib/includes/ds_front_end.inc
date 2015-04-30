<?php

/***Imports css, js or inline js into current page
 * @ToDo refactor so we don't need to specify the import_type...it is moved in the $imports,perhaps
 * @param $import_type
 *          - specifies the type of import such as js script, css sheet or js inline
 * @param $imports
 *          - the list of imports in form of array(
 *                              'path'=>'path/to/import/fileOrStringOfImportLoad',
 *                              'options' => array('options of Drupal API drupal_add_js and drupal_add_css')
 */
function import_front_end($import_type, $imports)
{

    foreach ($imports as $key => $import) {
        switch ($import_type) {
            case 'css':
                drupal_add_css($import['path'], $import['options']);
                break;
            case 'js_inline':
            case 'js':
                drupal_add_js($import['path'], $import['options']);
                break;
        }
    }


}

function _get_path_values($n)
{
    return $n['path'];
}

/**
 * retrieves all values of index 'path'. Typically used for taking css_list and filtering out only path
 *
 */
function retrieve_path_values($css_list)
{
    $path_list = array_map('_get_path_values',$css_list);
    return $path_list;
}


