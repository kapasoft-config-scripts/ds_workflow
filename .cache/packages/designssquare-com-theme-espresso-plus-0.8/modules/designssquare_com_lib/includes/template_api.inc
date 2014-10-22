<?php

/*******Theme Custom Settings******/
function _theme_settings($theme_name){
    $theme_tapi = array();

    //scheme-color
    $theme_tapi['color'] = variable_get('ds_theme_color', theme_get_setting('ds_theme_color'));

    //layout - boxed, wide, semi-wide
    $theme_tapi['layout'] = variable_get('ds_theme_layout', theme_get_setting('ds_theme_layout'));

    //background image - image full name
    $theme_tapi['bg-img'] = variable_get('ds_theme_gb_img', theme_get_setting('ds_theme_gb_img'));

    //background color - image full name
    $theme_tapi['bg-color'] = variable_get('ds_theme_bg_color', theme_get_setting('ds_theme_bg_color'));

    return $theme_tapi;
}

/******Event********/
function _event_teaser_tapi($event){
    $event_tapi = array();
    if(isset($event)){
        $event_tapi['url'] = base_path().drupal_get_path_alias('node/' . $event->nid); //url to a event
        $event_tapi['title'] = $event->title;
        $field_instance = field_get_items('node', $event, 'field_event_date');
        $event_date = strtotime($field_instance[0]['value']);
        $event_tapi['date'] = array();
        $event_tapi['date']['full'] = (isset($event_date)) ? date("j M, Y", $event_date) : '';
        $event_tapi['date']['day'] = (isset($event_date)) ? date("j", $event_date) : '';
        $event_tapi['date']['month'] = (isset($event_date)) ? date("M", $event_date) : '';
        $event_tapi['date']['year'] = (isset($event_date)) ? date("Y", $event_date) : '';
        $event_tapi['date']['hour'] = (isset($event_date)) ? date("H", $event_date) : '';
        $event_tapi['date']['min'] = (isset($event_date)) ? date("i", $event_date) : '';
    }else{
        $event_tapi['url'] = '';
        $event_tapi['title'] = '';
        $event_tapi['date'] = array();
        $event_tapi['date']['full'] = '';
        $event_tapi['date']['day'] =  '';
        $event_tapi['date']['month'] = '';
        $event_tapi['date']['year'] = '';
        $event_tapi['date']['hour'] = '';
    }

    return $event_tapi;
}

/*******Podcast******/
function _podcast_teaser_tapi($podcast)
{
    module_load_include('module', 'designssquare_lib');
    $podcast_tapi = array();

    if(isset($podcast)) {
        $podcast_tapi['url'] = base_path().drupal_get_path_alias('node/' . $podcast->nid); //url to a project
        $podcast_tapi['title'] = $podcast->title;
        $field_instance = field_get_items('node', $podcast, 'field_ds_podcast_summary');
        $field_value = ($field_instance) ? field_view_value('node', $podcast, 'field_ds_podcast_summary', $field_instance[0]) : '';
        $podcast_tapi['summary'] = htmlspecialchars_decode(render($field_value));

        $field_instance = field_get_items('node', $podcast, 'field_ds_podcast_featured_img');
        $field_value = ($field_instance) ? array_shift($field_instance) : '';
        $podcast_tapi['featured_img'] = array();
        $podcast_tapi['featured_img']['url'] = (isset($field_value['uri'])) ? file_create_url($field_value['uri']) : '';
        $podcast_tapi['featured_img']['alt'] = (isset($field_value['alt'])) ? $field_value['alt'] : '';

        //images size for the teaser
        $image_style = image_style_load('ds_podcast_teaser_img');
        if(empty($image_style)){
            $podcast_tapi['featured_img']['width'] = '';
            $podcast_tapi['featured_img']['height'] = '';
        }else{
            $thumb_effect = array_shift($image_style['effects']);
            $podcast_tapi['featured_img']['width'] = $thumb_effect['data']['width'].'px';
            $podcast_tapi['featured_img']['height'] = $thumb_effect['data']['height'].'px';
        }

        $field_instance = field_get_items('node', $podcast, 'field_ds_podcast_download');
        $field_value = ($field_instance) ? array_shift($field_instance) : '';
        $podcast_tapi['audio'] = array();
        $podcast_tapi['audio']['url'] = (isset($field_value['uri'])) ? file_create_url($field_value['uri']) : '';
        $podcast_tapi['audio']['alt'] = (isset($field_value['alt'])) ? $field_value['alt'] : '';
        $podcast_tapi['audio']['label'] = t('Play Podcast');
        $audio_render_array = field_view_field(
            'node',
            $podcast,
            'field_ds_podcast_download',
            array(
                'type' => 'audiofield_embedded',
                'label' => 'hidden',
                'field types' => array('file'),
                'description' => t('Displays an audio player and optional download link.'),
            )
        );
        $podcast_tapi['audio']['full'] = render($audio_render_array);
    }else{
        $podcast_tapi['url'] = ''; //url to a project
        $podcast_tapi['title'] = '';
        $podcast_tapi['summary'] = '';
        $podcast_tapi['audio'] = array();
        $podcast_tapi['audio']['url'] = '';
        $podcast_tapi['audio']['alt'] = '';
        $podcast_tapi['audio']['label'] = '';
        $podcast_tapi['audio']['full'] = '';
        $podcast_tapi['featured_img'] = array();
        $podcast_tapi['featured_img']['url'] = '';
        $podcast_tapi['featured_img']['alt'] = '';
    }

    //provide contextual links
    $podcast_tapi['ds_contextual_links'] = node_contextual_links($podcast);

    return $podcast_tapi;
}

function _podcast_tapi($node)
{
    $podcast_tapi = _podcast_teaser_tapi($node);

    if (isset($node) && !empty($node)) {
        $field_instance = field_get_items('node', $node, 'body');
        $content = ($field_instance) ? field_view_value('node', $node, 'body', $field_instance[0]) : '';
        $podcast_tapi['content'] = render($content);
        $field_instance = field_get_items('node', $node, 'field_ds_podcast_pub_date');
        $publication_timestamp = ($field_instance) ? $field_instance[0]['value'] : null;
        $podcast_tapi['date'] = array();
        $podcast_tapi['date']['full'] = (isset($publication_timestamp)) ? date("j M, Y", $publication_timestamp) : '';
        $podcast_tapi['date']['day'] = (isset($publication_timestamp)) ? date("j", $publication_timestamp) : '';
        $podcast_tapi['date']['month'] = (isset($publication_timestamp)) ? date("M", $publication_timestamp) : '';
        $podcast_tapi['date']['year'] = (isset($publication_timestamp)) ? date("Y", $publication_timestamp) : '';
    } else {
        $podcast_tapi['content'] = '';
        $podcast_tapi['date'] = array();
        $podcast_tapi['date']['full'] = '';
        $podcast_tapi['date']['day'] = '';
        $podcast_tapi['date']['month'] = '';
        $podcast_tapi['date']['year'] = '';
    }

    //images size for the block
    $podcast_tapi['block_img'] = array();
    $image_style = image_style_load('ds_podcast_block_img');
    if(empty($image_style)){
        $podcast_tapi['block_img']['width'] = '';
        $podcast_tapi['block_img']['height'] = '';
    }else{
        $thumb_effect = array_shift($image_style['effects']);
        $podcast_tapi['block_img']['width'] = $thumb_effect['data']['width'].'px';
        $podcast_tapi['block_img']['height'] = $thumb_effect['data']['height'].'px';
    }

    return $podcast_tapi;
}

/*******Newsletter******/
function _newsletter_teaser_tapi($newsletter)
{
    module_load_include('module', 'designssquare_lib');
    $newsletter_tapi = array();

    if(isset($newsletter)) {
        $newsletter_tapi['url'] = base_path().drupal_get_path_alias('node/' . $newsletter->nid); //url to a project
        $newsletter_tapi['title'] = $newsletter->title;
        $field_instance = field_get_items('node', $newsletter, 'field_ds_newsletter_summary');
        $field_value = ($field_instance) ? field_view_value('node', $newsletter, 'field_ds_newsletter_summary', $field_instance[0]) : '';
        $newsletter_tapi['summary'] = htmlspecialchars_decode(render($field_value));

        $field_instance = field_get_items('node', $newsletter, 'field_ds_newsletter_download');
        $field_value = ($field_instance) ? array_shift($field_instance) : '';
        $newsletter_tapi['download'] = array();
        $newsletter_tapi['download']['url'] = (isset($field_value['uri'])) ? file_create_url($field_value['uri']) : '';
        $newsletter_tapi['download']['alt'] = (isset($field_value['alt'])) ? $field_value['alt'] : '';
        $newsletter_tapi['download']['text'] = t('To Read More');
    }else{
        $newsletter_tapi['url'] = ''; //url to a project
        $newsletter_tapi['title'] = '';
        $newsletter_tapi['summary'] = '';
        $newsletter_tapi['download'] = array();
        $newsletter_tapi['download']['url'] = '';
        $newsletter_tapi['download']['alt'] = '';
    }

    //provide contextual links
    $newsletter_tapi['ds_contextual_links'] = node_contextual_links($newsletter);

    drupal_alter('newsletter_teaser_tapi', $newsletter_tapi);
    return $newsletter_tapi;
}

function _newsletter_tapi($node)
{
    $newsletter_tapi = _newsletter_teaser_tapi($node);

    if (isset($node) && !empty($node)) {
        $field_instance = field_get_items('node', $node, 'body');
        $content = ($field_instance) ? field_view_value('node', $node, 'body', $field_instance[0]) : '';
        $newsletter_tapi['content'] = render($content);
        $field_instance = field_get_items('node', $node, 'field_ds_newsletter_pub_date');
        $publication_timestamp = ($field_instance) ? $field_instance[0]['value'] : null;
        $newsletter_tapi['date'] = array();
        $newsletter_tapi['date']['full'] = (isset($publication_timestamp)) ? date("j M, Y", $publication_timestamp) : '';
        $newsletter_tapi['date']['day'] = (isset($publication_timestamp)) ? date("j", $publication_timestamp) : '';
        $newsletter_tapi['date']['month'] = (isset($publication_timestamp)) ? date("M", $publication_timestamp) : '';
        $newsletter_tapi['date']['year'] = (isset($publication_timestamp)) ? date("Y", $publication_timestamp) : '';
    } else {
        $newsletter_tapi['content'] = '';
        $newsletter_tapi['date'] = array();
        $newsletter_tapi['date']['full'] = '';
        $newsletter_tapi['date']['day'] = '';
        $newsletter_tapi['date']['month'] = '';
        $newsletter_tapi['date']['year'] = '';
    }

    return $newsletter_tapi;
}


/******GALLERY*******/
function _gallery_teaser_tapi($gallery)
{
    module_load_include('module', 'designssquare_lib');
    $gallery_tapi = array();

    if(isset($gallery)) {
        $gallery_tapi['url'] = base_path().drupal_get_path_alias('node/' . $gallery->nid); //url to a project
        $gallery_tapi['title'] = $gallery->title;

        $field_instance = field_get_items('node', $gallery, 'field_ds_gallery_page_intro');
        $field_value = ($field_instance) ? field_view_value('node', $gallery, 'field_ds_gallery_page_intro', $field_instance[0]) : '';
        $gallery_tapi['intro'] = htmlspecialchars_decode(render($field_value));

        $field_instance = field_get_items('node', $gallery, 'field_ds_gallery_summary');
        $field_value = ($field_instance) ? field_view_value('node', $gallery, 'field_ds_gallery_summary', $field_instance[0]) : '';
        $gallery_tapi['summary'] = htmlspecialchars_decode(render($field_value));
        $field_instance = field_get_items('node', $gallery, 'field_ds_gallery_featured_img');
        $field_value = ($field_instance) ? array_shift($field_instance) : '';
        $gallery_tapi['featured_img'] = array();
        $gallery_tapi['featured_img']['url'] = (isset($field_value['uri'])) ? file_create_url($field_value['uri']) : '';
        $gallery_tapi['featured_img']['alt'] = (isset($field_value['alt'])) ? $field_value['alt'] : '';
        //images size for the teaser
        $image_style = image_style_load('ds_foto_gallery_teaser');
        if(empty($image_style)){
            $gallery_tapi['featured_img']['width'] = '';
            $gallery_tapi['featured_img']['height'] = '';
        }else{
            $thumb_effect = array_shift($image_style['effects']);
            $gallery_tapi['featured_img']['width'] = $thumb_effect['data']['width'].'px';
            $gallery_tapi['featured_img']['height'] = $thumb_effect['data']['height'].'px';
        }

        //images size for the block
        $gallery_tapi['block_img'] = array();
        $image_style = image_style_load('ds_foto_gallery_block');
        if(empty($image_style)){
            $gallery_tapi['block_img']['width'] = '';
            $gallery_tapi['block_img']['height'] = '';
        }else{
            $thumb_effect = array_shift($image_style['effects']);
            $gallery_tapi['block_img']['width'] = $thumb_effect['data']['width'].'px';
            $gallery_tapi['block_img']['height'] = $thumb_effect['data']['height'].'px';
        }

    }else{
        $gallery_tapi['url'] = ''; //url to a project
        $gallery_tapi['title'] = '';
        $gallery_tapi['summary'] = '';
        $gallery_tapi['featured_img'] = array();
        $gallery_tapi['featured_img']['url'] = '';
        $gallery_tapi['featured_img']['alt'] = '';
    }

    //provide contextual links
    $gallery_tapi['ds_contextual_links'] = node_contextual_links($gallery);

    return $gallery_tapi;
}

function _gallery_tapi($node)
{
    $gallery_tapi = _gallery_teaser_tapi($node);

    //resize image at focus
    $gallery_tapi['gallery_focus_img'] = array();
    $image_style = image_style_load('ds_foto_gallery_single');
    if(empty($image_style)){
        $gallery_tapi['gallery_focus_img']['width'] = '';
        $gallery_tapi['gallery_focus_img']['height'] = '';
    }else{
        $thumb_effect = array_shift($image_style['effects']);
        $gallery_tapi['gallery_focus_img']['width'] = $thumb_effect['data']['width'].'px';
        $gallery_tapi['gallery_focus_img']['height'] = $thumb_effect['data']['height'].'px';
    }

    if (isset($node) && !empty($node)) {
        $field_instance = field_get_items('node', $node, 'body');
        $content = ($field_instance) ? field_view_value('node', $node, 'body', $field_instance[0]) : '';
        $gallery_tapi['content'] = render($content);
        $gallery_tapi['index'] = array();
        $gallery_tapi['index']['next'] = array();
        $id_next_node = next_node($node);
        if (isset($id_next_node)) {
            $gallery_tapi['index']['next']['is_present'] = TRUE;
            $gallery_tapi['index']['next']['url'] = base_path() . drupal_get_path_alias('node/' . $id_next_node);
            $gallery_tapi['index']['next']['text'] = t('Next');
        } else {
            $gallery_tapi['index']['next']['is_present'] = FALSE;
        }

        $id_previous_node = previous_node($node);
        $gallery_tapi['index']['previous'] = array();
        if (isset($id_previous_node)) {
            $gallery_tapi['index']['previous']['is_present'] = TRUE;
            $gallery_tapi['index']['previous']['text'] = t('Previous');
            $gallery_tapi['index']['previous']['url'] = base_path() . drupal_get_path_alias('node/' . $id_previous_node);
        } else {
            $gallery_tapi['index']['previous']['is_present'] = FALSE;
        }

        $gallery_tapi['gallery_img'] = array();
        $field_instance = field_get_items('node', $node, 'field_ds_gallery_images');
        if(isset($field_instance) && is_array($field_instance)){
            foreach ($field_instance as $key => $gallery_img) {
                $gallery_tapi['gallery_img'][$key]['url'] = (isset($gallery_img['uri'])) ? file_create_url($gallery_img['uri']) : '';
                $gallery_tapi['gallery_img'][$key]['alt'] = (isset($gallery_img['alt'])) ? $gallery_img['alt'] : '';
                $gallery_tapi['gallery_img'][$key]['title'] = (isset($gallery_img['title'])) ? $gallery_img['title'] : '';
            }
        }
    } else {
        $gallery_tapi['content'] = '';
        $gallery_tapi['index'] = array();
        $gallery_tapi['index']['next'] = array();
        $gallery_tapi['index']['next']['url'] = '';
        $gallery_tapi['index']['next']['text'] = '';
        $gallery_tapi['index']['previous'] = array();
        $gallery_tapi['index']['previous']['text'] = '';
        $gallery_tapi['index']['previous']['url'] = '';
        $gallery_tapi['gallery_img'] = array();
    }

    return $gallery_tapi;
}
/*****SERVICE*******/
function _service_teaser_tapi($service)
{
    module_load_include('module', 'designssquare_lib');
    $service_tapi = array();

    if(isset($service)) {
        $service_tapi['url'] = base_path().drupal_get_path_alias('node/' . $service->nid); //url to a project
        $service_tapi['title'] = $service->title;
        $field_instance = field_get_items('node', $service, 'field_ds_service_summary');
        $field_value = ($field_instance) ? field_view_value('node', $service, 'field_ds_service_summary', $field_instance[0]) : '';
        $summary = htmlspecialchars_decode(render($field_value));
        $service_tapi['summary'] = (isset($summary)) ? truncate_utf8($summary, 200, true, true) : '' ;

        $field_instance = field_get_items('node', $service, 'field_ds_service_featured_img');
        $field_value = ($field_instance) ? array_shift($field_instance) : '';
        $service_tapi['featured_img'] = array();
        $service_tapi['featured_img']['url'] = (isset($field_value['uri'])) ? file_create_url($field_value['uri']) : '';
        $service_tapi['featured_img']['alt'] = (isset($field_value['alt'])) ? $field_value['alt'] : '';

        //images size for the teaser
        $image_style = image_style_load('ds_service_teaser_img');
        if(empty($image_style)){
            $service_tapi['featured_img']['width'] = '';
            $service_tapi['featured_img']['height'] = '';
        }else{
            $thumb_effect = array_shift($image_style['effects']);
            $service_tapi['featured_img']['width'] = $thumb_effect['data']['width'].'px';
            $service_tapi['featured_img']['height'] = $thumb_effect['data']['height'].'px';
        }

    }else{
        $service_tapi['url'] = ''; //url to a project
        $service_tapi['title'] = '';
        $service_tapi['summary'] = '';
        $service_tapi['featured_img'] = array();
        $service_tapi['featured_img']['url'] = '';
        $service_tapi['featured_img']['alt'] = '';
    }

    //provide contextual links
    $service_tapi['ds_contextual_links'] = node_contextual_links($service);

    return $service_tapi;
}

function _service_tapi($node)
{
    $service_tapi = _service_teaser_tapi($node);

    if (isset($node) && !empty($node)) {
        $field_instance = field_get_items('node', $node, 'body');
        $content = ($field_instance) ? field_view_value('node', $node, 'body', $field_instance[0], 'full') : '';
        $service_tapi['content'] = render($content);
        $service_tapi['index'] = array();
        $service_tapi['index']['next'] = array();
        $id_next_node = next_node($node);
        if (isset($id_next_node)) {
            $service_tapi['index']['next']['is_present'] = TRUE;
            $service_tapi['index']['next']['url'] = base_path() . drupal_get_path_alias('node/' . $id_next_node);
            $service_tapi['index']['next']['text'] = t('Next');
        } else {
            $service_tapi['index']['next']['is_present'] = FALSE;
        }

        $id_previous_node = previous_node($node);
        $service_tapi['index']['previous'] = array();
        if (isset($id_previous_node)) {
            $service_tapi['index']['previous']['is_present'] = TRUE;
            $service_tapi['index']['previous']['text'] = t('Previous');
            $service_tapi['index']['previous']['url'] = base_path() . drupal_get_path_alias('node/' . $id_previous_node);
        } else {
            $service_tapi['index']['previous']['is_present'] = FALSE;
        }

//        $service_tapi['project_img'] = array();
//        $field_instance = field_get_items('node', $node, 'field_ds_service_images');
//        foreach ($field_instance as $key => $service_img) {
//            $service_tapi['project_img'][$key]['url'] = (isset($service_img['uri'])) ? file_create_url($service_img['uri']) : '';
//            $service_tapi['project_img'][$key]['alt'] = (isset($service_img['alt'])) ? $service_img['alt'] : '';
//        }
    } else {
        $service_tapi['content'] = '';
        $service_tapi['index'] = array();
        $service_tapi['index']['next'] = array();
        $service_tapi['index']['next']['url'] = '';
        $service_tapi['index']['next']['text'] = '';
        $service_tapi['index']['previous'] = array();
        $service_tapi['index']['previous']['text'] = '';
        $service_tapi['index']['previous']['url'] = '';
//        $service_tapi['project_img'] = array();
    }

    return $service_tapi;
}


/*****PORTFOLIO*******/
function _project_teaser_tapi($project)
{
    module_load_include('module', 'designssquare_lib');
    $project_tapi = array();

    if(isset($project)) {
        $project_tapi['url'] = base_path().drupal_get_path_alias('node/' . $project->nid); //url to a project
        $project_tapi['title'] = $project->title;
        $field_instance = field_get_items('node', $project, 'field_ds_portfolio_summary');
        $field_value = ($field_instance) ? field_view_value('node', $project, 'field_ds_portfolio_summary', $field_instance[0]) : '';
        $project_tapi['summary'] = htmlspecialchars_decode(render($field_value));
        $field_instance = field_get_items('node', $project, 'field_ds_portfolio_featured_img');
        $field_value = ($field_instance) ? array_shift($field_instance) : '';
        $project_tapi['featured_img'] = array();
        $project_tapi['featured_img']['url'] = (isset($field_value['uri'])) ? file_create_url($field_value['uri']) : '';
        $project_tapi['featured_img']['alt'] = (isset($field_value['alt'])) ? $field_value['alt'] : '';
    }else{
        $project_tapi['url'] = ''; //url to a project
        $project_tapi['title'] = '';
        $project_tapi['summary'] = '';
        $project_tapi['featured_img'] = array();
        $project_tapi['featured_img']['url'] = '';
        $project_tapi['featured_img']['alt'] = '';
    }

    //provide contextual links
    $project_tapi['ds_contextual_links'] = node_contextual_links($project);

    return $project_tapi;
}

function _project_tapi($node)
{
    $project_tapi = _project_teaser_tapi($node);

    if (isset($node) && !empty($node)) {
        $field_instance = field_get_items('node', $node, 'body');
        $content = ($field_instance) ? field_view_value('node', $node, 'body', $field_instance[0]) : '';
        $project_tapi['content'] = render($content);
        $project_tapi['index'] = array();
        $project_tapi['index']['next'] = array();
        $id_next_node = next_node($node);
        if (isset($id_next_node)) {
            $project_tapi['index']['next']['is_present'] = TRUE;
            $project_tapi['index']['next']['url'] = base_path() . drupal_get_path_alias('node/' . $id_next_node);
            $project_tapi['index']['next']['text'] = t('Next');
        } else {
            $project_tapi['index']['next']['is_present'] = FALSE;
        }

        $id_previous_node = previous_node($node);
        $project_tapi['index']['previous'] = array();
        if (isset($id_previous_node)) {
            $project_tapi['index']['previous']['is_present'] = TRUE;
            $project_tapi['index']['previous']['text'] = t('Previous');
            $project_tapi['index']['previous']['url'] = base_path() . drupal_get_path_alias('node/' . $id_previous_node);
        } else {
            $project_tapi['index']['previous']['is_present'] = FALSE;
        }

        $project_tapi['project_img'] = array();
        $field_instance = field_get_items('node', $node, 'field_ds_portfolio_images');
        foreach ($field_instance as $key => $project_img) {
            $project_tapi['project_img'][$key]['url'] = (isset($project_img['uri'])) ? file_create_url($project_img['uri']) : '';
            $project_tapi['project_img'][$key]['alt'] = (isset($project_img['alt'])) ? $project_img['alt'] : '';
        }
    } else {
        $project_tapi['content'] = '';
        $project_tapi['index'] = array();
        $project_tapi['index']['next'] = array();
        $project_tapi['index']['next']['url'] = '';
        $project_tapi['index']['next']['text'] = '';
        $project_tapi['index']['previous'] = array();
        $project_tapi['index']['previous']['text'] = '';
        $project_tapi['index']['previous']['url'] = '';
        $project_tapi['project_img'] = array();
    }

    return $project_tapi;
}

function _display_basic_tapi($display)
{

    //the minimal of display instance

    if (isset($display->type)) {
        $display_tapi = array();
        $display_tapi['name'] = $display->title;
        $display_tapi['url'] = base_path() . drupal_get_path_alias('node/' . $display->nid);

        $display_tapi['details'] = array();
        $field = field_get_items('node', $display, 'field_display_description');
        $field_ins = (isset($field[0])) ? field_view_value('node', $display, 'field_display_description', $field[0]) : '';
        $display_tapi['details']['description'] = (isset($field_ins)) ? html_entity_decode(render($field_ins)) : '';
        $display_tapi['details']['link_text'] = t('Details');
        $display_tapi['details']['sharer_description'] = (isset($display_tapi['details']['description'])) ? urlencode(html_entity_decode($display_tapi['details']['description'], ENT_COMPAT, 'UTF-8')) : '';

        //link for social networks sharing
        $display_tapi['sharer_url'] = (isset($display_tapi['url'])) ? urlencode(html_entity_decode($display_tapi['url'], ENT_COMPAT, 'UTF-8')) : '';

    } else {
        //default to nothing
        $display_tapi = array();
        $display_tapi['name'] = 'Display Not Set';
        $display_tapi['url'] = '';

        $display_tapi['details'] = array();
        $display_tapi['details']['description'] = '';
        $display_tapi['details']['link_text'] = t('Details');
        $display_tapi['details']['sharer_description'] = '';

        //link for social networks sharing
        $display_tapi['sharer_url'] = '';
    }
    return $display_tapi;
}

function _display_complete_tapi($display)
{

    //all info for display instance
    $display_tapi = _display_basic_tapi($display);

    if (isset($display->type)) {
        $display_tapi['seo'] = array();
        $field = field_get_items('node', $display, 'field_title_seo');
        $field_ins = field_view_value('node', $display, 'field_title_seo', $field[0]);
        $display_tapi['seo']['title'] = (isset($field[0])) ? render($field_ins) : '';
        $field = field_get_items('node', $display, 'field_description_seo');
        $field_ins = field_view_value('node', $display, 'field_description_seo', $field[0]);
        $display_tapi['seo']['description'] = (isset($field[0])) ? render($field_ins) : '';
        $field = field_get_items('node', $display, 'field_keywords_seo');
        $field_ins = field_view_value('node', $display, 'field_keywords_seo', $field[0]);
        $display_tapi['seo']['keywords'] = (isset($field[0])) ? render($field_ins) : '';

        $display_tapi['designer'] = array();
        $field = field_get_items('node', $display, 'field_designer_partnership');
        $field_ins = (isset($field[0])) ? field_view_value('node', $display, 'field_designer_partnership', $field[0]) : '';
        $display_tapi['designer']['is-partnership'] = (isset($field_ins['#title']) && $field_ins['#title'] == 'True') ? TRUE : FALSE;
        $field = field_get_items('node', $display, 'field_design_url');
        $field_ins = field_view_value('node', $display, 'field_design_url', $field[0]);
        $display_tapi['designer']['design-url'] = (isset($field[0])) ? render($field_ins) : '';

    } else {
        //display not set. default
        $display_tapi['seo'] = array();
        $display_tapi['seo']['title'] = '';
        $display_tapi['seo']['description'] = '';
        $display_tapi['seo']['keywords'] = '';

        $display_tapi['designer'] = array();
        $display_tapi['designer']['is-partnership'] = FALSE;
        $display_tapi['designer']['design-url'] = '';

    }
    return $display_tapi;
}

function _product_basic_tapi($product)
{
    //minimal info to display product teasers
    $product_tapi = array();
    $product_tapi['img'] = array();
    $field = field_get_items('commerce_product', $product, 'field_featured_image');
    $product_tapi['img']['url'] = (isset($field[0]['uri']) && !empty($field[0]['uri'])) ? url('sites/default/files/' . file_uri_target($field[0]['uri']), array('absolute' => true)) : base_path() . path_to_theme() . '/images/default-product-image.jpg';
    $product_tapi['img']['alt'] = (isset($field[0]['alt']) && !empty($field[0]['alt'])) ? $field[0]['alt'] : '';

    $product_tapi['discount'] = array();
    $field = field_get_items('commerce_product', $product, 'field_is_on_sale');
    $field_ins = field_view_value('commerce_product', $product, 'field_is_on_sale', $field[0]);
    $product_tapi['discount']['is-on-sale'] = (isset($field_ins['#title']) && $field_ins['#title'] == 'True') ? TRUE : FALSE;
    $field = field_get_items('commerce_product', $product, 'field_prior_sales_price');
    $field_ins = field_view_value('commerce_product', $product, 'field_prior_sales_price', $field[0]);
    $product_tapi['discount']['prior-sales-price'] = (isset($field_ins)) ? render($field_ins) : '';
    $product_tapi['discount']['sale-img-url'] = base_path() . drupal_get_path('module', 'designssquare_com_commerce') . "/images/bazar/bullets/sale.png";

    $field = field_get_items('commerce_product', $product, 'field_is_new_product');
    $field_ins = field_view_value('commerce_product', $product, 'field_is_new_product', $field[0]);
    $product_tapi['is-new-product'] = (isset($field_ins['#title']) && $field_ins['#title'] == 'True') ? TRUE : FALSE;
    $product_tapi['new-product-img-url'] = base_path() . drupal_get_path('module', 'designssquare_com_commerce') . "/images/bazar/bullets/new.png";


    $field = field_get_items('commerce_product', $product, 'field_product_description');
    $field_ins = field_view_value('commerce_product', $product, 'field_product_description', $field[0]);
    $product_tapi['details']['description'] = (isset($field_ins)) ? html_entity_decode(render($field_ins)) : '';
    $product_tapi['details']['description-summary'] = (isset($field[0]['summary'])) ? html_entity_decode(render($field[0]['summary'])) : truncate_utf8($product_tapi['details']['description'], 300, true, true);
//    $product_tapi['details']['url'] = base_path().drupal_get_path_alias('node/'.$display_node_id);//this has to be set outside the scope the id of node
    $product_tapi['details']['link_text'] = t('Details');
//    $product_tapi['details']['sharer_description'] = urlencode(html_entity_decode( $product_tapi['details']['description'] , ENT_COMPAT, 'UTF-8'));

    //product name
    $product_tapi['name'] = $product->title;
//    $product_tapi['url'] = base_path().drupal_get_path_alias('node/'.$display_node_id);

    $price = commerce_product_calculate_sell_price($product);
    $product_tapi['price'] = commerce_currency_format($price['amount'], $price['currency_code'], $product);
    $product_tapi['currency'] = $price['currency_code'];

    $product_tapi['wishlist']['url'] = '';
    $product_tapi['wishlist']['link_text'] = t('Wishlist');

    return $product_tapi;
}

function _add_to_cart_tapi($product)
{

    $display_id = (isset($product->display_id) && is_numeric($product->display_id)) ? $product->display_id : get_referencing_product_display_id($product);
    $display = (isset($display_id) && is_numeric($display_id)) ? node_load($display_id) : null;

    if (isset($display)) {
        $add_to_cart_form = field_view_field(
            'node',
            $display,
            'field_product',
            array(
                'type' => 'commerce_cart_add_to_cart_form',
                'label' => 'hidden',
                'settings' => array(
                    'show_quantity' => FALSE,
                    'default_quantity' => 1,
                    'combine' => TRUE,
                    'show_single_product_attributes' => FALSE,
                    'line_item_type' => 'product',
                ),
            )
        );
    } else {
        //display is not set for the product
        $add_to_cart_form = '';
        watchdog(WATCHDOG_NOTICE, 'Product display is missing for product with sku:' . $product->sku . ' (see _add_to_cart_tapi())');
    }

    $product_tapi = array();

    if (isset($add_to_cart_form[0])) {
        $form = $add_to_cart_form[0];
        $product_tapi['action'] = $form['#action'];
        $product_tapi['form_id_rendered'] = render($form['form_id']);
        $product_tapi['form_id'] = $form['#id'];
        $product_tapi['product_id'] = $product->product_id;
        $product_tapi['form_build_id'] = render($form['form_build_id']);
    } else {
        $product_tapi['action'] = "/";
        $product_tapi['form_id_rendered'] = "";
        $product_tapi['form_id'] = "";
        $product_tapi['product_id'] = "";
        $product_tapi['form_build_id'] = "";
    }


    $product_tapi['link_text'] = t('Add To Cart');

    return $product_tapi;
}

function _product_complete_tapi($product, $display_node_id = Null)
{
    //all info to display product in its own section
    $product_tapi = _product_basic_tapi($product, $display_node_id);
    $product_tapi['img-magnified'] = array();
    $field = field_get_items('commerce_product', $product, 'field_featured_image_magnified');
    $product_tapi['img-magnified']['url'] = (isset($field[0]['uri']) && !empty($field[0]['uri'])) ? url('sites/default/files/' . file_uri_target($field[0]['uri']), array('absolute' => true)) : '';
    $product_tapi['img-magnified']['alt'] = (isset($field[0]['alt']) && !empty($field[0]['alt'])) ? $field[0]['alt'] : '';

    $product_tapi['additional_info'] = array();
    $field = field_get_items('commerce_product', $product, 'field_drupal_version');
    $field_ins = field_view_value('commerce_product', $product, 'field_drupal_version', $field[0]);
    $product_tapi['additional_info']['drupal_version'] = (isset($field_ins['#title'])) ? $field_ins['#title'] : '';

    $field = field_get_items('commerce_product', $product, 'field_mobile_support');
    $field_ins = field_view_value('commerce_product', $product, 'field_mobile_support', $field[0]);
    $product_tapi['additional_info']['mobile_support'] = (isset($field_ins['#title']) && $field_ins['#title'] == 'Responsive') ? 'Yes' : 'No';

    $field = field_get_items('commerce_product', $product, 'field_design_framework');
    $field_ins = field_view_value('commerce_product', $product, 'field_design_framework', $field[0]);
    $product_tapi['additional_info']['design_framework'] = (isset($field_ins['#title'])) ? $field_ins['#title'] : '';

    $price = commerce_product_calculate_sell_price($product);
    $product_tapi['price'] = commerce_currency_format($price['amount'], $price['currency_code'], $product);
    $product_tapi['currency'] = $price['currency_code'];

    $category_list = array();
    $field = field_get_items('commerce_product', $product, 'field_product_category');
    if ($field) {
        foreach ($field as $key => $category_ins) {
            $category = field_view_value('commerce_product', $product, 'field_product_category', $category_ins);
            $category_list[] = $category['#title'];
        }
    }
    $product_tapi['categories'] = $category_list;

    $product_tapi['demo'] = array();
    $field = field_get_items('commerce_product', $product, 'field_demo_url');
    $demo_url_rendearable = field_view_value('commerce_product', $product, 'field_demo_url', $field[0]);
    $product_tapi['demo']['url'] = (isset($field[0])) ? render($demo_url_rendearable) : '';

    $field = field_get_items('commerce_product', $product, 'field_hide_demo_header');
    $field_ins = field_view_value('commerce_product', $product, 'field_hide_demo_header', $field[0]);
    $product_tapi['demo']['hide_header'] = (isset($field['#title']) && $field['#title'] == 'True') ? TRUE : FALSE;

    return $product_tapi;
}

//prepare user related variables for the html.tpl file
function _header_tapi_user()
{
    global $conf;
    global $user;
    $name = (!empty($conf['anonymous'])) ? $conf['anonymous'] : 'Hello Mate';
    $profile_img_url = base_path() . path_to_theme() . '/images/author.png';

    if ($user->uid) {
        //authenticated user
        $url = 'user/logout';
        $content = 'Logout';
        $profile_url = 'user';
        $profile_content = $user->name;
        $authenticated = True;
    } else {
        $url = 'user';
        $content = 'Login';
        $authenticated = False;
        $profile_url = '';
        $profile_content = '';
    }

    return array(
        'name' => $name,
        'avatar' => $profile_img_url,
        'login' => array(
            'url' => $url,
            'text' => $content,
        ),
        'profile' => array(
            'url' => $profile_url,
            'text' => $profile_content,
        ),
        'is_authenticated' => $authenticated,
    );
}

//prepare site related variables for the html.tpl file
//function _basic_tapi($node){
//    return array(
//        'slogan' => (!empty($node->field_slogan)) ? $node->field_slogan[LANGUAGE_NONE][0]['value'] : '',
//        'title' => (!empty($node->title)) ? $node->title : '',
//    );
//}
function _basic_tapi($node)
{
    $field = field_get_items('node', $node, 'field_page_slogan');
    $slogan = field_view_value('node', $node, 'field_page_slogan', $field[0]);

    return array(
        'title' => !empty($node->title) ? $node->title : '',
        'body' => !empty($node->body) ? $node->body : '',
        'slogan' => !empty($slogan) ? render($slogan) : '',
    );
}

function _simple_tapi($vars)
{
    return array(
        'title' => !empty($vars['title']) ? $vars['title'] : '',
        'body' => !empty($vars['body']) ? $vars['body'] : '',
        'slogan' => !empty($vars['slogan']) ? $vars['slogan'] : '',
        'intro' => !empty($vars['intro']) ? $vars['intro'] : '',
    );
}

function _page_tapi($vars)
{
    $page_tapi = array();
    if (isset($vars['node']) && !empty($vars['node'])) {
        $node = $vars['node'];
        $title_instance = field_get_items('node', $node, 'field_page_title');
        $page_title_val = (!empty($title_instance[0])) ? field_view_value('node', $node, 'field_page_title', $title_instance[0]) : '';
        $custom_title = htmlspecialchars_decode(render($page_title_val));
        $page_tapi['title'] = (!empty($custom_title)) ? $custom_title : $node->title;

        $info_instance = field_get_items('node', $node, 'field_page_information');
        $info_instance_val = (!empty($info_instance[0])) ? field_view_value('node', $node, 'field_page_information', $info_instance[0]) : '';
        $page_tapi['intro'] = htmlspecialchars_decode(render($info_instance_val));

        //*****backward compatable and should be using intro field instead the slogan
        $field = field_get_items('node', $node, 'field_page_slogan');
        $page_tapi['slogan'] = (!empty($field[0])) ? field_view_value('node', $node, 'field_page_slogan', $field[0]) : '';

    } else {
        $page_tapi = _simple_tapi($vars);
    }

    return $page_tapi;

}


function _checkout_tapi($node)
{
    $field = field_get_items('node', $node, 'field_checkout_message');
    $checkout_message = render(field_view_value('node', $node, 'field_checkout_message', $field[0]));
    $basic = _basic_tapi($node);
    $checkout_tapi = array(
        'checkout_message' => ($checkout_message) ? $checkout_message : '',
    );
    return array_merge($basic, $checkout_tapi);
}


//prepare site related variables for the html.tpl file
function _header_tapi_site()
{
    $head_tapi = array();
    /****Logo*****/
    $logo_path = variable_get('logo', theme_get_setting('logo'));
    $is_logo_enabled = variable_get('toggle_logo', theme_get_setting('toggle_logo'));
    $head_tapi['logo'] = array();
    $head_tapi['logo']['path'] = (!empty($logo_path)) ? $logo_path : '#';
    $head_tapi['logo']['is_enabled'] = (!empty($is_logo_enabled)) ? TRUE : FALSE;

    /****Site****/
    $site_frontpage = variable_get('site_frontpage', 'node');
    $site_name = variable_get('site_name', theme_get_setting('site_name'));
    $is_name_enabled = variable_get('toggle_name', theme_get_setting('toggle_name'));

    $head_tapi['site'] = array();
    $head_tapi['site']['name'] = (!empty($site_name)) ? $site_name : 'Cas<strong>ca</strong>de <i class="fa fa-bookmark"></i>';
    $head_tapi['site']['name_enabled'] = ($is_name_enabled) ? TRUE : FALSE;
    $head_tapi['site']['front_url'] = (!empty($site_frontpage)) ? base_path() . $site_frontpage : '#';

    /*****Slogan*****/
    $site_slogan = variable_get('site_slogan', theme_get_setting('slogan'));
    $is_slogan_enabled = variable_get('toggle_slogan', theme_get_setting('toggle_slogan'));
    $head_tapi['site_slogan'] = array();
    $head_tapi['site_slogan']['text'] = (!empty($site_slogan)) ? $site_slogan : '';
    $head_tapi['site_slogan']['is_enabled'] = (!empty($is_slogan_enabled)) ? $is_slogan_enabled : FALSE;
    $head_tapi['user'] = array();
    $head_tapi['user'] = _header_tapi_user();

    /*****Theme*****/
    $head_tapi['settings'] = array();
    $head_tapi['settings']['url'] = base_path() . 'admin/appearance/settings/cascade';
    $head_tapi['settings']['text'] = t(' Settings');

//    return array(
//        'slogan' => $slogan,
//        'site_name' => $site_name,
//        'home_url' => $path_to_home,
//        'logo_path' => $logo_path,
//    );

    /*********making backwards compatable**************/
    $head_tapi['slogan'] = $site_slogan;
    $head_tapi['site_name'] = $head_tapi['site']['name'];
    $head_tapi['home_url'] = $head_tapi['site']['front_url'];
    $head_tapi['logo_path'] = $head_tapi['logo']['path'];

    return $head_tapi;
}

function _search_tapi()
{
    $form = array();
    $search_form_array = drupal_get_form('search_block_form');
    //form specific
    $form['id'] = str_replace('_', '-', $search_form_array['#form_id']);
    $form['action'] = $search_form_array['#action'];

    //search key input field
    $form['search_id'] = $search_form_array['search_block_form']['#id'];
    $form['search_name'] = $search_form_array['search_block_form']['#name'];

    //submit input field
    $form['submit_name'] = 'op';
    $form['submit_id'] = 'edit-submit';

    //hidden fields
    $form['hidden_input'] = render($search_form_array['form_build_id']);
    $form['hidden_input2'] = render($search_form_array['form_id']);
    $form['hidden_input3'] = (isset($search_form_array['form_token'])) ? render($search_form_array['form_token']) : '';
    return $form;
}


function _contact_tapi()
{
    $contact_tapi = array();
    require_once drupal_get_path('module', 'contact') . '/contact.pages.inc';
    $contact_form_array = drupal_get_form('contact_site_form');
    //form specific
    $contact_tapi['id'] = str_replace('_', '-', $contact_form_array['#form_id']);
    $contact_tapi['action'] = $contact_form_array['#action'];

    //name input field
    $contact_tapi['name_name'] = $contact_form_array['name']['#name'];
    $contact_tapi['name_label'] = t('Your Name:');
    $contact_tapi['name_type'] = 'type';
    //subject input field
    $contact_tapi['subject_name'] = $contact_form_array['subject']['#name'];
    $contact_tapi['subject_value'] = 'From ' . $_SERVER['HTTP_HOST'];
    $contact_tapi['subject_label'] = t('Subject:');
    $contact_tapi['subject_type'] = 'text';

    //email input field
    $contact_tapi['email_name'] = $contact_form_array['mail']['#name'];
    $contact_tapi['email_label'] = t('Your Email:');
    $contact_tapi['email_type'] = 'email';

    //message input field
    $contact_tapi['message_name'] = $contact_form_array['message']['#name'];
    $contact_tapi['message_label'] = t('Your Message');

    //submit input field
    $contact_tapi['submit_name'] = 'op';
    $contact_tapi['submit_id'] = 'edit-submit';
    $contact_tapi['submit_label'] = t('Send');

    //category_field
//    $contact_tapi['category'] = render($contact_form_array['cid']);

    //hidden fields
    $contact_tapi['hidden_input'] = render($contact_form_array['form_build_id']);
    $contact_tapi['hidden_input2'] = render($contact_form_array['form_id']);
    $contact_tapi['hidden_input3'] = (isset($contact_form_array['form_token'])) ? render($contact_form_array['form_token']) : '';

    //
    drupal_alter('contact_tapi',$contact_tapi);
    return $contact_tapi;
}

function _comment_tapi($comment)
{
    $comment_tapi = array();
    //comment author
    $comment_tapi['author'] = array();
    $author = (isset($comment->uid) && is_numeric($comment->uid)) ? user_load($comment->uid) : null;
    $comment_tapi['author']['name'] = (isset($author->name)) ? $author->name : t('anonymous');
    $comment_tapi['author']['gravatar_url'] = (isset($author->picture)) ? file_create_url($author->picture->uri) : '/sites/default/file/avatar.jpg';
    $comment_tapi['author']['profile_url'] = (isset($author->uid)) ? '/user/' . $author->uid : '/';

    //comment info
    $comment_tapi['comment'] = array();
    $comment_tapi['comment']['subject'] = $comment->subject;
    $field_instance = field_get_items('comment', $comment, 'comment_body');
    $field_value = ($field_instance) ? field_view_value('comment', $comment, 'comment_body', $field_instance[0]) : '';
    $comment_tapi['comment']['content'] = render($field_value);
    $comment_tapi['comment']['date'] = (isset($comment->created)) ? date("F j, Y, g:i a", $comment->created) : 'July 25, 2111';

    //comment links
    if (user_access('administer comments') && user_access('post comments')) {
        $comment_tapi['links'] = array();
        $comment_tapi['links']['access'] = TRUE;
        $comment_tapi['links']['edit_url'] = "comment/$comment->cid/edit";
        $comment_tapi['links']['edit_text'] = t('Edit');
        $comment_tapi['links']['reply_url'] = "comment/reply/$comment->nid/$comment->cid";
        $comment_tapi['links']['reply_text'] = t('Reply');
        $comment_tapi['links']['delete_url'] = "comment/$comment->cid/delete";
        $comment_tapi['links']['delete_text'] = t('Delete');
    } else {
        //no access
        $comment_tapi['links']['access'] = FALSE;
    }

    return $comment_tapi;
}