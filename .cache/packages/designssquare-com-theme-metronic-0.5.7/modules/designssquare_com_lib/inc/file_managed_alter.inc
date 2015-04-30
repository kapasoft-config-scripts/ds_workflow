<?php

/*
 * Implementation for making files permanent on upload while clean on remove
 *
 * specify the following function in the file_managed element '#process'
 * */

function ds_designssquare_lib_process_file_managed($element, &$form_state, $form){
    $element = file_managed_file_process($element, $form_state, $form);

    //file upload
    if (isset($form_state['input']['_triggering_element_name']) && $form_state['input']['_triggering_element_name'] == $element['upload_button']['#name'] && !empty($element['#file'])) {
        //make file permanent
        $file = $element['#file'];
        // Change status to permanent.
        $file->status = FILE_STATUS_PERMANENT;

        //all permanent files need an entry in the 'file_usage' table
        //we also add variable name as the 'type' parameter, so we can export via Sample Data module
        file_usage_add($file, 'designssquare_lib', $element['#name'], '1');
        // Save.
        //@ToDo see how to update instead save because it creates double reference in the file_managed table(see 'count')
        file_save($file);

        //set variable as well
        variable_set($element['#name'], $file->fid);
    }

    //file removed
    if (isset($form_state['input']['_triggering_element_name']) && $form_state['input']['_triggering_element_name'] == $element['remove_button']['#name']) {
        //ensure file is removed
        if(isset($element['#file']->fid) && $file = file_load($element['#file']->fid)){
            //file exist, lets remove
            //the file is removed despite the count of references present
            db_delete('file_managed')->condition('fid', $file->fid)->execute();
            db_delete('file_usage')->condition('fid', $file->fid)->execute();
            entity_get_controller('file')->resetCache();
        }
    }

    return $element;
}

//submit function
//function ds_file_managed_submit($form, &$form_state){
//    drupal_set_message(t('theme settings saved'));
//}