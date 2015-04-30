<?php

///******GALLERY*******/
function _gallery_teaser_tapi($gallery)
{
    if (isset($gallery->nid)) {
        $gallery_tapi = & drupal_static(__FUNCTION__ . $gallery->nid);
    } else {
        $gallery_tapi = & drupal_static(__FUNCTION__);
    }
    if (!isset($gallery_tapi)) {
        module_load_include('module', 'designssquare_lib');
        $gallery_tapi = array();

        if (isset($gallery)) {
            $gallery_tapi['url'] = base_path() . drupal_get_path_alias('node/' . $gallery->nid); //url to a gallery
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

            /***Tags**/
            $gallery_tapi['tags'] = _ds_gallery_retrieve_tags($gallery);

            /***Categories**/
            $gallery_tapi['categories'] = _ds_gallery_retrieve_categories($gallery);

        } else {
            $gallery_tapi['url'] = ''; //url to a gallery
            $gallery_tapi['title'] = '';
            $gallery_tapi['summary'] = '';
            $gallery_tapi['featured_img'] = array();
            $gallery_tapi['featured_img']['url'] = '';
            $gallery_tapi['featured_img']['alt'] = '';
            $gallery_tapi['tags'] = array();
            $gallery_tapi['tags']['all_names'] = '';
            $gallery_tapi['tags']['flattened_names'] = '';
            $gallery_tapi['categories'] = array();
            $gallery_tapi['categories']['all_names'] = '';
            $gallery_tapi['categories']['flattened_names'] = '';
        }

        //provide contextual links
        $gallery_tapi['ds_contextual_links'] = node_contextual_links($gallery);
        //provide styles
//        $gallery_tapi['styles'] = _gallery_style_tapi();
    }
    return $gallery_tapi;
}

function _gallery_item_tapi($node)
{
    if (isset($node->nid)) {
        $gallery_item_tapi = & drupal_static(__FUNCTION__ . $node->nid);
    } else {
        $gallery_item_tapi = & drupal_static(__FUNCTION__);
    }
    if (!isset($gallery_item_tapi)) {
        $gallery_item_tapi = array();
        if (isset($node) && !empty($node)) {
            $field_instance = field_get_items('node', $node, 'field_ds_gallery_item');
            if (isset($field_instance) && is_array($field_instance)) {
                module_load_include('inc', 'designssquare_lib', 'includes/template_api');
                foreach ($field_instance as $key => $item) {
                    $gallery_item_tapi[$key] = ds_item_tapi($item, 'gallery_node');
                }
            }
        }
    }
    return $gallery_item_tapi;
}


function _gallery_tapi($node)
{
    if (isset($node->nid)) {
        $gallery_tapi = & drupal_static(__FUNCTION__ . $node->nid);
    } else {
        $gallery_tapi = & drupal_static(__FUNCTION__);
    }
    if (!isset($gallery_tapi)) {
        $gallery_tapi = _gallery_teaser_tapi($node);

        //resize image at focus
//        $gallery_tapi['gallery_focus_img'] = array();
//        $image_style = image_style_load('ds_foto_gallery_single');
//        if (empty($image_style)) {
//            $gallery_tapi['gallery_focus_img']['width'] = '';
//            $gallery_tapi['gallery_focus_img']['height'] = '';
//        } else {
//            $thumb_effect = array_shift($image_style['effects']);
//            $gallery_tapi['gallery_focus_img']['width'] = $thumb_effect['data']['width'] . 'px';
//            $gallery_tapi['gallery_focus_img']['height'] = $thumb_effect['data']['height'] . 'px';
//        }

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

//            $gallery_tapi['gallery_img'] = array();
//            $field_instance = field_get_items('node', $node, 'field_ds_gallery_images');
//            if (isset($field_instance) && is_array($field_instance)) {
//                foreach ($field_instance as $key => $gallery_img) {
//                    $gallery_tapi['gallery_img'][$key]['url'] = (isset($gallery_img['uri'])) ? file_create_url($gallery_img['uri']) : '';
//                    $gallery_tapi['gallery_img'][$key]['alt'] = (isset($gallery_img['alt'])) ? $gallery_img['alt'] : '';
//                    $gallery_tapi['gallery_img'][$key]['title'] = (isset($gallery_img['title'])) ? $gallery_img['title'] : '';
//                }
//            }
        } else {
            $gallery_tapi['content'] = '';
            $gallery_tapi['index'] = array();
            $gallery_tapi['index']['next'] = array();
            $gallery_tapi['index']['next']['url'] = '';
            $gallery_tapi['index']['next']['text'] = '';
            $gallery_tapi['index']['previous'] = array();
            $gallery_tapi['index']['previous']['text'] = '';
            $gallery_tapi['index']['previous']['url'] = '';
//            $gallery_tapi['gallery_img'] = array();
        }

        //styles
        $gallery_tapi['styles'] = _gallery_style_tapi();
    }
    return $gallery_tapi;
}

function _gallery_node_tapi($node)
{
    if (isset($node->nid)) {
        $gallery_tapi = & drupal_static(__FUNCTION__ . $node->nid);
    } else {
        $gallery_tapi = & drupal_static(__FUNCTION__);
    }
    if (!isset($gallery_tapi)) {
        module_load_include('inc', 'designssquare_lib', 'includes/template_api');
        $gallery_tapi = _gallery_tapi($node);
        $gallery_tapi['items_tapi'] = _gallery_item_tapi($node);
        $gallery_tapi['items_tags'] = _ds_retrieve_items_tags($gallery_tapi['items_tapi']);

        //provide styles
        $gallery_tapi['styles'] = _gallery_style_tapi();

    }
    return $gallery_tapi;
}


function _gallery_view_tapi($view)
{
    if (isset($view->name)) {
        $gallery_view_tapi = & drupal_static(__FUNCTION__ . $view->name);
    } else {
        $gallery_view_tapi = & drupal_static(__FUNCTION__);
    }
    if (!isset($gallery_view_tapi)) {
        $gallery_view_tapi = array();
        $gallery_view_tapi['tags'] = array();
        $gallery_view_tapi['categories'] = array();
        if (isset($view->result) && is_array($view->result)) {
            $all_tags = array();
            $all_cats = array();
            foreach ($view->result as $id => $row) {
                $gallery = $row->_entity_properties['entity object'];
                $gallery_tag_tapi = _ds_gallery_retrieve_tags($gallery);
                $all_tags = array_merge($all_tags, $gallery_tag_tapi['collection']);
                $gallery_cat_tapi = _ds_gallery_retrieve_categories($gallery);
                $all_cats = array_merge($all_cats, $gallery_cat_tapi['collection']);
            }
        }
        $gallery_view_tapi['tags'] = $all_tags;
        $gallery_view_tapi['categories'] = $all_cats;

        //handling title
        $display_id = $view->current_display;
        $gallery_view_tapi['views_title'] = (isset($display_id) && isset($view->display[$display_id])) ? $view->display[$display_id]->display_title : '';

        //styles
        $gallery_view_tapi['styles'] = _gallery_style_tapi();
    }
    return $gallery_view_tapi;
}

//copy of _gallery_view_tapi with node list instead of view from taxonomy request
function _gallery_index_tapi($node_list)
{
    $gallery_view_tapi = & drupal_static(__FUNCTION__ . $_GET['q']);
    if (!isset($gallery_view_tapi)) {
        $gallery_view_tapi = array();
        $gallery_view_tapi['tags'] = array();
        $gallery_view_tapi['categories'] = array();
        if (isset($node_list) && is_array($node_list)) {
            $all_tags = array();
            $all_cats = array();
            foreach ($node_list as $gallery) {
//                if (isset($row['#node'])) {
//                    $gallery = $row['#node'];
                $gallery_tag_tapi = _ds_gallery_retrieve_tags($gallery);
                $all_tags = array_merge($all_tags, $gallery_tag_tapi['collection']);
                $gallery_cat_tapi = _ds_gallery_retrieve_categories($gallery);
                $all_cats = array_merge($all_cats, $gallery_cat_tapi['collection']);
//                }
            }
        }
        $gallery_view_tapi['tags'] = (isset($all_tags)) ? $all_tags : '';
        $gallery_view_tapi['categories'] = (isset($all_cats)) ? $all_cats : '';

        //handling title
        $gallery_view_tapi['views_title'] = '';
    }
    return $gallery_view_tapi;
}


function _ds_gallery_retrieve_tags($node)
{
    if (isset($node->nid)) {
        $gallery_tapi = & drupal_static(__FUNCTION__ . $node->nid);
    } else {
        $gallery_tapi = & drupal_static(__FUNCTION__);
    }
    if (!isset($gallery_tapi)) {
        $gallery_tapi = array();
        $gallery_tapi['collection'] = array();
        $field_instance = field_get_items('node', $node, 'field_ds_gallery_tags');
        $tags_count = count($field_instance);
        $tag_names = array();
        $tag_names_safe = array();
        if (isset($field_instance) && is_array($field_instance)) {
            foreach ($field_instance as $key => $tid) {
                $tag = taxonomy_term_load($tid['tid']);
//                $safe_name = (isset($tag->name)) ? strtolower(str_replace(' ', '_', $tag->name)) : $key;
                $safe_name = (isset($tag->name)) ? str_replace(' ', '_', $tag->name) : $key;
                $url = base_path() . drupal_get_path_alias('taxonomy/term/' . $tag->tid);
                $gallery_tapi['collection'][$safe_name]['url'] = (isset($url)) ? $url : '';
                $gallery_tapi['collection'][$safe_name]['name'] = (isset($tag->name)) ? $tag->name : '';
                $tag_names[] = $gallery_tapi['collection'][$safe_name]['name'];
                $gallery_tapi['collection'][$safe_name]['name_safe'] = (isset($safe_name)) ? $safe_name : '';
                $tag_names_safe[] = (isset($safe_name)) ? $safe_name : '';
                $gallery_tapi['collection'][$safe_name]['is_last'] = (($tags_count - 1) == $key) ? true : false;
            }
        } else {
            watchdog('designssquare_com_widget_gallery', 'Gallery Tags are not present or none assigned to gallery node field - field_ds_gallery_tags');
        }
        $unique_tag_names = array_unique($tag_names_safe);
        $gallery_tapi['flattened_names'] = ($unique_tag_names) ? implode(' ', $unique_tag_names) : '';
        $gallery_tapi['all_names'] = ($tag_names) ? array_unique($tag_names) : '';
    }
    return $gallery_tapi;
}

//function _ds_gallery_retrieve_items_tags($items){
//    $tag_names = array();
////    $temp_tags = array();
////    $tag_names['names'] = array();
//    $tag_names['collection'] = array();
//    foreach($items as $item ){
//        $tags = $item['tags']['raw'];
//        foreach($tags as $tag){
//            $tag_names['collection'][$tag] =  array();
//            $tag_names['collection'][$tag]['name'] = $tag;
//            $tag_names['collection'][$tag]['safe_name'] = str_replace(' ', '_', strtolower($tag));
//        }
//    }
////    $tag_names['names'] = array_unique($tag_names['collection']);
//    $tag_names['flatten_safe_names']= array_reduce($tag_names['collection'], '_merge_safe_names');
//    return $tag_names;
//}

/**Turns tag names into safe names by lowercasing and adding '_' for spaces
 * @param $n
 *
 */
function _safe_tags($n)
{
    return str_replace(' ', '_', strtolower($n));
}

function _merge_safe_names($carry, $tag)
{
    return $carry . ' ' . $tag['safe_name'];
}

function _ds_gallery_retrieve_categories($node)
{
    if (isset($node->nid)) {
        $gallery_tapi = & drupal_static(__FUNCTION__ . $node->nid);
    } else {
        $gallery_tapi = & drupal_static(__FUNCTION__);
    }
    if (!isset($gallery_tapi)) {
        $gallery_tapi = array();
        $gallery_tapi['collection'] = array();
        $field_instance = field_get_items('node', $node, 'field_ds_gallery_categories');
        $categories_count = count($field_instance);
        $category_names = array();
        $category_names_safe = array();
        if (isset($field_instance) || is_array($field_instance)) {
            foreach ($field_instance as $key => $tid) {
                $tag = taxonomy_term_load($tid['tid']);
                $safe_name = (isset($tag->name)) ? strtolower(str_replace(' ', '_', $tag->name)) : $key;
                $url = base_path() . drupal_get_path_alias('taxonomy/term/' . $tag->tid);
                $gallery_tapi['collection'][$safe_name]['url'] = (isset($url)) ? $url : '';
                $gallery_tapi['collection'][$safe_name]['name'] = (isset($tag->name)) ? $tag->name : '';
                $category_names[] = $gallery_tapi['collection'][$safe_name]['name'];

                $safe_name = strtolower(str_replace(' ', '_', $gallery_tapi['collection'][$safe_name]['name']));
                $gallery_tapi['collection'][$safe_name]['name_safe'] = (isset($safe_name)) ? $safe_name : '';
                $category_names_safe[] = $gallery_tapi['collection'][$safe_name]['name_safe'];
                $gallery_tapi['collection'][$safe_name]['is_last'] = (($categories_count - 1) == $key) ? true : false;
            }
        } else {
            watchdog('designssquare_com_widget_gallery', 'Gallery Categories are no present or not assigned to field - field_ds_gallery_categories');
        }
        $unique_category_names = array_unique($category_names_safe);
        $gallery_tapi['flattened_names'] = (isset($unique_category_names)) ? implode(' ', $unique_category_names) : '';
        $gallery_tapi['all_names'] = (isset($category_names)) ? array_unique($category_names) : '';
    }
    return $gallery_tapi;
}

function _gallery_style_tapi()
{
    $gallery_style_tapi = & drupal_static(__FUNCTION__);
    if (!isset($gallery_style_tapi)) {
        module_load_include('inc', 'designssquare_com_widget_gallery', 'inc/gallery-settings');
        $gallery_style_tapi = array();

        /**TEASER****/
        //gallery thumb size of gallery items in the teaser
        $teaser_settings = _gallery_settings_teaser();
        $gallery_style_tapi['teaser_thumb'] = array();
        $image_style = image_style_load('ds_gallery_teaser_thumb');
        if(empty($image_style)){
            watchdog(WATCHDOG_ERROR, "Image Styles - ds_gallery_teaser_thumb is missing");
        }
        $gallery_style_tapi['teaser_thumb']['style'] = '';
        $teaser_style_enabled = ($teaser_settings['thumb_style'] == 'yes') ? true : false;


        if (!empty($image_style) && $teaser_style_enabled) {
            $thumb_effect = array_shift($image_style['effects']);
            $gallery_style_tapi['teaser_thumb']['width'] = $thumb_effect['data']['width'];
            $gallery_style_tapi['teaser_thumb']['height'] = $thumb_effect['data']['height'];
            $gallery_style_tapi['teaser_thumb']['style'] = "style='width:" . $gallery_style_tapi['teaser_thumb']['width'] . "px;height:" . $gallery_style_tapi['teaser_thumb']['height'] . "px;'";
        } elseif ($teaser_style_enabled['thumb_style'] == "no") {
            //NO to keep width 100% and set height to default provided below
            $gallery_style_tapi['teaser_thumb']['width'] = '100';
            $gallery_style_tapi['teaser_thumb']['height'] = $teaser_settings['thumb_height'];
            $gallery_style_tapi['teaser_thumb']['style'] = "style='width:" . $gallery_style_tapi['teaser_thumb']['width'] . "%;height:" . $gallery_style_tapi['teaser_thumb']['height'] . "px;'";
        }else{
            //else let the design manage style
            $gallery_style_tapi['teaser_thumb']['width'] = '';
            $gallery_style_tapi['teaser_thumb']['height'] = '';
        }

        /***BLOCK********/
        //thumb size of gallery items in the block
        $gallery_style_tapi['block_thumb'] = array();
        $image_style = image_style_load('ds_gallery_block_thumb');
        if(empty($image_style)){
            watchdog(WATCHDOG_ERROR, "Image Styles - ds_gallery_block_thumb is missing");
        }
        $gallery_style_tapi['block_thumb']['ui_style'] = '';
        $gallery_style_tapi['block_thumb']['design_style'] = '';
        $gallery_style_tapi['block_thumb']['style'] = '';
        //grab gallery admin settings
        $index_settings = _gallery_settings_block();
        $index_style_enabled = ($index_settings['thumb_style'] == 'yes') ? true : false;

        if (!empty($image_style) && $index_style_enabled) {
            $thumb_effect = array_shift($image_style['effects']);
            $gallery_style_tapi['block_thumb']['width'] = $thumb_effect['data']['width'];
            $gallery_style_tapi['block_thumb']['height'] = $thumb_effect['data']['height'];
            $gallery_style_tapi['block_thumb']['ui_style'] = "style='width:" . $gallery_style_tapi['block_thumb']['width'] . "px;height:" . $gallery_style_tapi['block_thumb']['height'] . "px;'";
            $gallery_style_tapi['block_thumb']['style'] = $gallery_style_tapi['block_thumb']['ui_style'];
        } elseif($index_settings['thumb_style'] == "no") {
            $gallery_style_tapi['block_thumb']['width'] = '100';
            $gallery_style_tapi['block_thumb']['height'] = $index_settings['thumb_height'];
            $gallery_style_tapi['block_thumb']['design_style'] = "style='width:" . $gallery_style_tapi['block_thumb']['width'] . "%;height:" . $gallery_style_tapi['block_thumb']['height'] . "px;'";
            $gallery_style_tapi['block_thumb']['style'] = $gallery_style_tapi['block_thumb']['design_style'];
        }else{
            //else let the design manage style
            $gallery_style_tapi['block_thumb']['width'] = '';
            $gallery_style_tapi['block_thumb']['height'] = '';
        }

        /**INDEX**/
        //thumb size of gallery items in the index
        $gallery_style_tapi['index_thumb'] = array();
        $image_style = image_style_load('ds_gallery_index_thumb');
        if(empty($image_style)){
            watchdog(WATCHDOG_ERROR, "Image Styles - ds_gallery_index_thumb is missing");
        }
        $gallery_style_tapi['index_thumb']['ui_style'] = '';
        $gallery_style_tapi['index_thumb']['design_style'] = '';
        $gallery_style_tapi['index_thumb']['style'] = '';
        //grab gallery admin settings
        $index_settings = _gallery_settings_index();
        $index_style_enabled = ($index_settings['thumb_style'] == 'yes') ? true : false;

        if (!empty($image_style) && $index_style_enabled) {
            $thumb_effect = array_shift($image_style['effects']);
            $gallery_style_tapi['index_thumb']['width'] = $thumb_effect['data']['width'];
            $gallery_style_tapi['index_thumb']['height'] = $thumb_effect['data']['height'];
            $gallery_style_tapi['index_thumb']['ui_style'] = "style='width:" . $gallery_style_tapi['index_thumb']['width'] . "px;height:" . $gallery_style_tapi['index_thumb']['height'] . "px;'";
            $gallery_style_tapi['index_thumb']['style'] = $gallery_style_tapi['index_thumb']['ui_style'];
        } elseif($index_settings['thumb_style'] == "no") {
            $gallery_style_tapi['index_thumb']['width'] = '100';
            $gallery_style_tapi['index_thumb']['height'] = $index_settings['thumb_height'];
            $gallery_style_tapi['index_thumb']['design_style'] = "style='width:" . $gallery_style_tapi['index_thumb']['width'] . "%;height:" . $gallery_style_tapi['index_thumb']['height'] . "px;'";
            $gallery_style_tapi['index_thumb']['style'] = $gallery_style_tapi['index_thumb']['design_style'];
        }else{
            //else let the design manage style
            $gallery_style_tapi['index_thumb']['width'] = '';
            $gallery_style_tapi['index_thumb']['height'] = '';
        }




        /***NODE**/
        $gallery_style_tapi['node_thumb'] = array();
        $image_style = image_style_load('ds_gallery_node_thumb');
        if(empty($image_style)){
            watchdog(WATCHDOG_ERROR, "Image Styles - ds_gallery_node_thumb is missing");
        }
        $gallery_style_tapi['node_thumb']['ui_style'] = '';
        $gallery_style_tapi['node_thumb']['design_style'] = '';
        $gallery_style_tapi['node_thumb']['style'] = '';
        //grab gallery admin settings
        $node_settings = _gallery_settings_node();
        $node_style_enabled = ($node_settings['thumb_style'] == 'yes') ? true : false;

        if (!empty($image_style) && $node_style_enabled) {
            $thumb_effect = array_shift($image_style['effects']);
            $gallery_style_tapi['node_thumb']['width'] = $thumb_effect['data']['width'];
            $gallery_style_tapi['node_thumb']['height'] = $thumb_effect['data']['height'];
            $gallery_style_tapi['node_thumb']['ui_style'] = "style='width:" . $gallery_style_tapi['node_thumb']['width'] . "px;height:" . $gallery_style_tapi['node_thumb']['height'] . "px;'";
            $gallery_style_tapi['node_thumb']['style'] = $gallery_style_tapi['node_thumb']['ui_style'];
        } elseif($node_settings['thumb_style'] == "no") {
            $gallery_style_tapi['node_thumb']['width'] = '100';
            $gallery_style_tapi['node_thumb']['height'] = $node_settings['thumb_height'];
            $gallery_style_tapi['node_thumb']['design_style'] = "style='width:" . $gallery_style_tapi['node_thumb']['width'] . "%;height:" . $gallery_style_tapi['node_thumb']['height'] . "px;'";
            $gallery_style_tapi['node_thumb']['style'] = $gallery_style_tapi['node_thumb']['design_style'];
        }else{
            //else let the design manage style
            $gallery_style_tapi['node_thumb']['width'] = '';
            $gallery_style_tapi['node_thumb']['height'] = '';
        }

    }
    return $gallery_style_tapi;
}