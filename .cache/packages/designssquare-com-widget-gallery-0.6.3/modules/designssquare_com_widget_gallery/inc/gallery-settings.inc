<?php
module_load_include('module', 'designssquare_lib');

function ds_gallery_settings()
{
    $all = & drupal_static(__FUNCTION__);
    if (!isset($all)) {
        $all = array();
        $all['index'] = _gallery_settings_index();
        $all['block'] = _gallery_settings_block();
        $all['teaser'] = _gallery_settings_teaser();
        $all['node'] = _gallery_settings_node();
        $all['general'] = _gallery_settings_general();
    }
    return $all;
}

//retrieves gallery index settings
function _gallery_settings_general()
{
    $settings = & drupal_static(__FUNCTION__);
    if (!isset($settings)) {
        $settings = array();
        $settings['default_index_name'] = variable_get('ds_gallery_breadcrumbs_default_index_name', 'Galleries');
        $settings['default_index_url'] = variable_get('ds_gallery_breadcrumbs_default_index_url', 'ds-gallery');
//        $settings['vimeo_frame_width'] = variable_get('ds_gallery_vimeo_frame_width', '640');
//        $settings['vimeo_frame_height'] = variable_get('ds_gallery_vimeo_frame_height', '390');
//        $settings['youtube_frame_width'] = variable_get('ds_gallery_youtube_frame_width', '640');
//        $settings['youtube_frame_height'] = variable_get('ds_gallery_youtube_frame_height', '390');
    }
    return $settings;
}

//retrieves gallery index settings
function _gallery_settings_index()
{
    $settings = & drupal_static(__FUNCTION__);
    if (!isset($settings)) {
        $settings = array();
        $settings['layout'] = variable_get('ds_gallery_index_settings_layouts', 'k2');
        $settings['columns'] = variable_get('ds_gallery_index_settings_columns', 4);
        $settings['thumb_style'] = variable_get('ds_gallery_index_settings_thumb_style', 'no');
        $settings['thumb_height'] = variable_get('ds_gallery_index_settings_thumb_height', '150');
    }
    return $settings;
}

//retrieves gallery block settings
function _gallery_settings_block()
{
    $settings = & drupal_static(__FUNCTION__);
    if (!isset($settings)) {
        $settings = array();
        $settings['layout'] = variable_get('ds_gallery_block_settings_layouts', 'everest');
        $settings['columns'] = variable_get('ds_gallery_block_settings_columns', 3);
        $settings['thumb_style'] = variable_get('ds_gallery_block_settings_thumb_style', 'no');
        $settings['thumb_height'] = variable_get('ds_gallery_block_settings_thumb_height', '150');
    }
    return $settings;
}

//retrieves gallery teaser settings
function _gallery_settings_teaser()
{
    $settings = & drupal_static(__FUNCTION__);
    if (!isset($settings)) {
        $settings = array();
        $settings['layout'] = variable_get('ds_gallery_teaser_settings_layouts', 'everest');
        $settings['thumb_style'] = variable_get('ds_gallery_teaser_settings_thumb_style', 'no');
        $settings['thumb_height'] = variable_get('ds_gallery_teaser_settings_thumb_height', '150');
    }
    return $settings;
}

//retrieves gallery teaser settings
function _gallery_settings_node()
{
    $settings = & drupal_static(__FUNCTION__);
    if (!isset($settings)) {
        $settings = array();
        $settings['layout'] = variable_get('ds_gallery_node_settings_layouts', 'k2');
        $settings['columns'] = variable_get('ds_gallery_node_settings_columns', 4);
        $settings['thumb_style'] = variable_get('ds_gallery_node_settings_thumb_style', 'no');
        $settings['thumb_height'] = variable_get('ds_gallery_node_settings_thumb_height', '150');
//        $settings['video_frame_width'] = variable_get('ds_gallery_video_frame_width', '640');
//        $settings['video_frame_height'] = variable_get('ds_gallery_video_frame_height', '390');
    }
    return $settings;
}

function gallery_admin_interface($form, $form_state)
{
    $gallery_settings = ds_gallery_settings();
    $form['#old_values'] = array();

    $form['ds_widget_gallery'] = array(
        '#type' => 'vertical_tabs',
        '#attached' => array(
            'js' => array(drupal_get_path('module', 'designssquare_com_widget_gallery') . '/js/bootstrap.admin.js'),
        ),
        '#prefix' => '<h2><small>' . t('DesignsSquare.com Widget Gallery Settings') . '</small></h2>',
        '#weight' => -20,
    );

    /***GENERAL***/
    $form['ds_general_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('General'),
        '#group' => 'ds_widget_gallery',
    );

    //GENERAL - Breadcrumbs
    $form['ds_general_settings']['breadcrumbs'] = array(
        '#type' => 'fieldset',
        '#title' => t('Breadcrumbs'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );
    $form['ds_general_settings']['breadcrumbs']['ds_gallery_breadcrumbs_default_index_name'] = array(
        '#title' => t('Name of Default Index'),
        '#type' => 'textfield',
        '#default_value' => $gallery_settings['general']['default_index_name'],
        '#description' => t('It is used at breadcrumbs when index not specified for project'),
    );
    $form['ds_general_settings']['breadcrumbs']['ds_gallery_breadcrumbs_default_index_url'] = array(
        '#title' => t('Url of Default Index'),
        '#type' => 'textfield',
        '#default_value' => $gallery_settings['general']['default_index_url'],
        '#description' => t('It is used at breadcrumbs when index not specified for project'),
    );



//    //Vimeo
//    $form['ds_general_settings']['vimeo'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Vimeo'),
//        '#collapsible' => TRUE,
//        '#collapsed' => FALSE,
//    );
//    $form['ds_general_settings']['vimeo']['ds_gallery_vimeo_frame_width'] = array(
//        '#title' => t('Frame Width'),
//        '#type' => 'textfield',
//        '#default_value' => $gallery_settings['video']['vimeo_frame_width'],
//        '#description' => t('Vimeo frame width'),
//    );
//    $form['ds_general_settings']['vimeo']['ds_gallery_vimeo_frame_height'] = array(
//        '#title' => t('Frame Height'),
//        '#type' => 'textfield',
//        '#default_value' => $gallery_settings['video']['vimeo_frame_height'],
//        '#description' => t('Vimeo frame height'),
//    );
//
//    //YouTube
//    $form['ds_general_settings']['youtube'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('YouTube'),
//        '#collapsible' => TRUE,
//        '#collapsed' => FALSE,
//    );
//    $form['ds_general_settings']['youtube']['ds_gallery_youtube_frame_width'] = array(
//        '#title' => t('Frame Width'),
//        '#type' => 'textfield',
//        '#default_value' => $gallery_settings['video']['youtube_frame_width'],
//        '#description' => t('YouTube frame width'),
//    );
//    $form['ds_general_settings']['youtube']['ds_gallery_youtube_frame_height'] = array(
//        '#title' => t('Frame Height'),
//        '#type' => 'textfield',
//        '#default_value' => $gallery_settings['video']['youtube_frame_height'],
//        '#description' => t('YouTube frame height'),
//    );

    /***INDEX***/
    $form['index_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('Index'),
        '#group' => 'ds_widget_gallery',
    );
    //Layout Style.
    $form['index_settings']['layouts'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layouts'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );
    $form['index_settings']['layouts']['ds_gallery_index_settings_layouts'] = array(
        '#type' => 'radios',
        '#title' => t(''),
        '#default_value' => $gallery_settings['index']['layout'],
        '#options' => array(
            'k2' => t('K2'),
            'everest' => t('Everest'),
        ),
    );
    $form['#old_values']['ds_gallery_index_settings_layouts'] =  $gallery_settings['index']['layout'];

    $form['index_settings']['columns'] = array(
        '#type' => 'fieldset',
        '#title' => t('Columns'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );

    $form['index_settings']['columns']['ds_gallery_index_settings_columns'] = array(
        '#type' => 'radios',
        '#title' => t(''),
        '#default_value' => $gallery_settings['index']['columns'],
        '#options' => array(
            4 => t('Four'),
            3 => t('Three'),
            2 => t('Two')
        ),
    );
    $form['#old_values']['ds_gallery_index_settings_columns'] =  $gallery_settings['index']['columns'];

    //Thumbs
    $form['index_settings']['thumbs'] = array(
        '#type' => 'fieldset',
        '#title' => t('Thumbnails'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );

    // Anchors.
    $form['index_settings']['thumbs']['ds_gallery_index_settings_thumb_style'] = array(
        '#type' => 'radios',
        '#title' => t('Enable "DS Gallery Index Thumb" style(admin/config/media/image-styles) to scale Gallery thumbnails in the index scope'),
        '#default_value' => $gallery_settings['index']['thumb_style'],
        '#options' => array(
            'yes' => t('Yes (this will overwrite columns configurations)'),
            'no_design' => t('NO (the theme design scales thumbnails)'),
            'no' => t('NO (this keeps the width 100% and set the height to default provided below)'),
        ),
    );
    $form['#old_values']['ds_gallery_index_settings_thumb_style'] =  $gallery_settings['index']['thumb_style'];

    $form['index_settings']['thumbs']['ds_gallery_index_settings_thumb_height'] = array(
        '#title' => t('Default Height'),
        '#type' => 'textfield',
        '#default_value' => $gallery_settings['index']['thumb_height'],
        '#description' => t('default height of the thumb in block without any measurement unit at the end(i.e. 300)'),
    );
    $form['#old_values']['ds_gallery_index_settings_thumb_height'] =  $gallery_settings['index']['thumb_height'];



    /*****BLOCKS******/
    $form['block_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('Block'),
        '#group' => 'ds_widget_gallery',
    );

    $form['block_settings']['layouts'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layouts'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );

    // Anchors.
    $form['block_settings']['layouts']['ds_gallery_block_settings_layouts'] = array(
        '#type' => 'radios',
        '#title' => t(''),
        '#default_value' => $gallery_settings['block']['layout'],
        '#options' => array(
            'mckinley' => t('McKinley (slider)'),
            'everest' => t('Everest (thumbnail pattern)'),
        ),
    );
    $form['#old_values']['ds_gallery_block_settings_layouts'] =  $gallery_settings['block']['layout'];

    //Column .
    $form['block_settings']['columns'] = array(
        '#type' => 'fieldset',
        '#title' => t('Columns'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );

    // Anchors.
    $form['block_settings']['columns']['ds_gallery_block_settings_columns'] = array(
        '#type' => 'radios',
        '#title' => t(''),
        '#default_value' => $gallery_settings['block']['columns'],
        '#options' => array(
            4 => t('Four'),
            3 => t('Three'),
            2 => t('Two')
        ),
    );
    $form['#old_values']['ds_gallery_block_settings_columns'] =  $gallery_settings['block']['columns'];

    //Thumbs
    $form['block_settings']['thumbs'] = array(
        '#type' => 'fieldset',
        '#title' => t('Thumbnails'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );

    // Anchors.
    $form['block_settings']['thumbs']['ds_gallery_block_settings_thumb_style'] = array(
        '#type' => 'radios',
        '#title' => t('Enable "DS Gallery Block Thumb" style(admin/config/media/image-styles) to scale Gallery thumbnails in the block'),
        '#default_value' => $gallery_settings['block']['thumb_style'],
        '#options' => array(
            'yes' => t('Yes (this will overwrite columns configurations)'),
            'no_design' => t('NO (the theme design scales thumbnails)'),
            'no' => t('NO (this keeps the width 100% and set the height to default provided below)'),
        ),
    );
    $form['#old_values']['ds_gallery_block_settings_thumb_style'] =  $gallery_settings['block']['thumb_style'];

    $form['block_settings']['thumbs']['ds_gallery_block_settings_thumb_height'] = array(
        '#title' => t('Default Height'),
        '#type' => 'textfield',
        '#default_value' => $gallery_settings['block']['thumb_height'],
        '#description' => t('default height of the thumb in block without any measurement unit at the end(i.e. 300)'),
    );
    $form['#old_values']['ds_gallery_block_settings_thumb_height'] =  $gallery_settings['block']['thumb_height'];



    /***TEASER****/
    $form['teaser_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('Teaser'),
        '#group' => 'ds_widget_gallery',
    );

    //Layout Style.
    $form['teaser_settings']['layouts'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layouts'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );

    // Anchors.
    $form['teaser_settings']['layouts']['ds_gallery_teaser_settings_layouts'] = array(
        '#type' => 'radios',
        '#title' => t(''),
        '#default_value' => $gallery_settings['teaser']['layout'],
        '#options' => array(
            'everest' => t('Everest'),
        ),
    );
    $form['#old_values']['ds_gallery_teaser_settings_layouts'] =  $gallery_settings['teaser']['layout'];

    // Thumbs.
    //Layout Style.
    $form['teaser_settings']['thumbs'] = array(
        '#type' => 'fieldset',
        '#title' => t('Thumbnails'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['teaser_settings']['thumbs']['ds_gallery_teaser_settings_thumb_style'] = array(
        '#type' => 'radios',
        '#title' => t('Enable "DS Gallery Teaser Thumb" style(admin/config/media/image-styles) to scale Gallery thumbnails in the teaser'),
        '#default_value' => $gallery_settings['teaser']['thumb_style'],
        '#options' => array(
            'yes' => t('Yes (this will overwrite columns configurations)'),
            'no_design' => t('NO (the theme design scales thumbnails)'),
            'no' => t('NO (this keeps the width 100% and set the height to default provided below)'),
        ),
    );
    $form['#old_values']['ds_gallery_teaser_settings_thumb_style'] =  $gallery_settings['teaser']['thumb_style'];

    $form['teaser_settings']['thumbs']['ds_gallery_teaser_settings_thumb_height'] = array(
        '#title' => t('Default Height'),
        '#type' => 'textfield',
        '#default_value' => $gallery_settings['teaser']['thumb_height'],
        '#description' => t('default height of the thumb in block without any measurement unit at the end(i.e. 300)'),
    );
    $form['#old_values']['ds_gallery_teaser_settings_thumb_height'] =  $gallery_settings['teaser']['thumb_height'];





    /***NODE****/
    $form['node_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('Node'),
        '#group' => 'ds_widget_gallery',
    );

    //Layout Style.
    $form['node_settings']['layouts'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layouts'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );


    // Anchors.
    $form['node_settings']['layouts']['ds_gallery_node_settings_layouts'] = array(
        '#type' => 'radios',
        '#title' => t(''),
        '#default_value' => $gallery_settings['node']['layout'],
        '#options' => array(
//            'everest' => t('Everest'),
//            'mckinley' => t('McKinley'),
            'k2' => t('K2'),
        ),
    );

    $form['#old_values']['ds_gallery_node_settings_layouts'] =  $gallery_settings['node']['layout'];

    //Column .
    $form['node_settings']['columns'] = array(
        '#type' => 'fieldset',
        '#title' => t('Columns'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );

    // Anchors.
    $form['node_settings']['columns']['ds_gallery_node_settings_columns'] = array(
        '#type' => 'radios',
        '#title' => t(''),
        '#default_value' => $gallery_settings['node']['columns'],
        '#options' => array(
            4 => t('Four'),
            3 => t('Three'),
            2 => t('Two')
        ),
    );
    $form['#old_values']['ds_gallery_node_settings_columns'] =  $gallery_settings['node']['columns'];

    $form['node_settings']['thumbs'] = array(
        '#type' => 'fieldset',
        '#title' => t('Thumbnails'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );

    // Anchors.
    $form['node_settings']['thumbs']['ds_gallery_node_settings_thumb_style'] = array(
        '#type' => 'radios',
        '#title' => t('Enable "DS Gallery Node Thumb" style(admin/config/media/image-styles) to scale Gallery thumbnails in the node scope'),
        '#default_value' => $gallery_settings['node']['thumb_style'],
        '#options' => array(
            'yes' => t('Yes (this will overwrite columns configurations)'),
            'no_design' => t('NO (the theme design scales thumbnails)'),
            'no' => t('NO (this keeps the width 100% and set the height to default provided below)'),
        ),
    );
    $form['#old_values']['ds_gallery_node_settings_thumb_style'] =  $gallery_settings['node']['thumb_style'];

    $form['node_settings']['thumbs']['ds_gallery_node_settings_thumb_height'] = array(
        '#title' => t('Default Height'),
        '#type' => 'textfield',
        '#default_value' => $gallery_settings['node']['thumb_height'],
        '#description' => t('default height of the thumb in block without any measurement unit at the end(i.e. 300)'),
    );
    $form['#old_values']['ds_gallery_node_settings_thumb_height'] =  $gallery_settings['node']['thumb_height'];


    //Video
//    $form['node_settings']['video'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Video'),
//        '#collapsible' => TRUE,
//        '#collapsed' => TRUE,
//    );
//    $form['node_settings']['video']['ds_gallery_video_frame_width'] = array(
//        '#title' => t('Frame Width'),
//        '#type' => 'textfield',
//        '#default_value' => $gallery_settings['node']['video_frame_width'],
//        '#description' => t('set 1 for 100%; 0 to use column width'),
//    );
//    $form['node_settings']['video']['ds_gallery_video_frame_height'] = array(
//        '#title' => t('Frame Height'),
//        '#type' => 'textfield',
//        '#default_value' => $gallery_settings['node']['video_frame_height'],
//        '#description' => t('set 1 for 100%; 0 for default height of other items in column'),
//    );

    $form['#submit'][] = 'ds_theme_rebuild';
    return system_settings_form($form);
}

/**
 * Retrieve the height of node thumbnails per configurations
**/
function _get_gallery_node_heigth(){
    $gallery_node_settings = _gallery_settings_node();
    $height = '';
    if($gallery_node_settings['thumb_style'] == 'yes' || $gallery_node_settings['thumb_style'] == 'no'){
        //scaling by Media Image or set by default height
        $gallery_styles = _gallery_style_tapi();
        $height = $gallery_styles['node_thumb']['height'];
    }
return $height;
}

/**
 * Retrieve the height of index thumbnails per configurations
 **/
function _get_gallery_index_heigth(){
    $gallery_index_settings = _gallery_settings_index();
    $height = '';
    if($gallery_index_settings['thumb_style'] == 'yes' || $gallery_index_settings['thumb_style'] == 'no'){
        //scaling by Media Image or set by default height
        $gallery_styles = _gallery_style_tapi();
        $height = $gallery_styles['index_thumb']['height'];
    }
    return $height;
}

/**
 * Retrieve the height of index thumbnails per configurations
 **/
function _get_gallery_block_heigth(){
    $gallery_block_settings = _gallery_settings_block();
    $height = '';
    if($gallery_block_settings['thumb_style'] == 'yes' || $gallery_block_settings['thumb_style'] == 'no'){
        //scaling by Media Image or set by default height
        $gallery_styles = _gallery_style_tapi();
        $height = $gallery_styles['block_thumb']['height'];
    }
    return $height;
}