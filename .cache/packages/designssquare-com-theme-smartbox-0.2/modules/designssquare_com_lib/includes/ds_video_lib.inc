<?php



/**
 * retrieves and construct video output from node with particular field as parameter
 * @return
 *      video output in rendable array
 */
function construct_video($node, $format_name, $field_name = 'field_video_file')
{
    $video_output = array();
    $video_intance = $node->$field_name;
    if (!empty($video_intance['und'][0])) {
        $video_settings = _videojs_settings($format_name);
        //video file
        $video_render_array = field_view_field(
            'node',
            $node,
            'field_video_file',
            array(
                'type' => 'videojs',
                'label' => 'hidden',
                'settings' => $video_settings,
            )
        );

        if ($video_settings['width'] == 1) {
            $video_render_array[0]['#attributes']['width'] = '100%';
        }

        $video_output = $video_render_array;
    }
    return $video_output;
}

/**
 * retrieves and construct video output from node with particular field as parameter
 * @return
 *      video output renderable array
 */
function construct_videojs($file_id, $format_name = '')
{
    if (!module_exists('videojs')) {
        watchdog('designssquare_com_widget_gallery', 'VideoJs module is not present', NULL, WATCHDOG_ALERT);
    }

    $file = file_load($file_id);
    if (isset($file) && !empty($file)) {

        $items = array();
        $items[] = array(
            'uri' => $file->uri,
            'filemime' => $file->filemime,
        );
        $video_settings = _videojs_settings($format_name);
        //video file
        $video_render_array = array(
//            '#theme' => 'videojs_view',
            '#theme' => 'videojs',
            '#items' => $items,
            '#player_id' => 'vidoejs-' . $file_id,
            '#attributes' => $video_settings,
        );
//            field_view_field(
//            'node',
//            $node,
//            'field_video_file',
//            array(
//                'type' => 'videojs',
//                'label' => 'hidden',
//                'settings' => $video_settings,
//            )
//        );

        if ($video_render_array['#attributes']['width'] == 1) {
            $video_render_array['#attributes']['width'] = '100%';
        }
        if ($video_render_array['#attributes']['height'] == 1) {
            $video_render_array['#attributes']['height'] = '100%';
        }
        $video_output = $video_render_array;
    }
    return $video_output;
}

function construct_vimeo($node, $format_name, $field_name = 'field_video_id')
{
    $vimeo_output = array();
    $vimeo_instance = $node->$field_name;
    if (!empty($vimeo_instance[LANGUAGE_NONE][0]['value'])) {
        //vimeo video
        $vimeo_frame_size = _vimeo_settings($format_name);
        if ($vimeo_frame_size['width'] == 1 || $vimeo_frame_size['height'] == 1) {
            $vimeo_output = '<iframe class="img-responsive" src="http://player.vimeo.com/video/' . $node->field_video_id[LANGUAGE_NONE][0]['value'] . '?badge=0" width="100%" height="100%" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
        } else {
            $vimeo_output = '<iframe class="img-responsive" src="http://player.vimeo.com/video/' . $node->field_video_id[LANGUAGE_NONE][0]['value'] . '?badge=0" width="' . $vimeo_frame_size['width'] . 'px" height="' . $vimeo_frame_size['height'] . 'px" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
        }
    }

    return $vimeo_output;
}

function construct_vimeo_output($vimeo_id, $format_name = '')
{
    $vimeo_output = array();

    if (isset($vimeo_id) && !empty($vimeo_id)) {
        //vimeo video
        $vimeo_frame_size = _vimeo_settings($format_name);
        if ($vimeo_frame_size['width'] == 1 || $vimeo_frame_size['height'] == 1) {
            $vimeo_output = '<iframe class="img-responsive"  src="http://player.vimeo.com/video/' . $vimeo_id . '?badge=0" width="100%" height="100%" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
        } else {
            $vimeo_output = '<iframe src="http://player.vimeo.com/video/' . $vimeo_id . '?badge=0" width="' . $vimeo_frame_size['width'] . '" height="' . $vimeo_frame_size['height'] . '" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
        }
    }

    return $vimeo_output;
}

function construct_youtube_output($youtube_url, $format_name = '')
{
    $youtube_output = array();

    if (isset($youtube_url) && !empty($youtube_url)) {
        $youtube_frame_size = _youtube_settings($format_name);
        if ($youtube_frame_size['width'] == 1 || $youtube_frame_size['height'] == 1) {
//            $youtube_output = '<iframe src="http://' . $youtube_url . '" width="100%" height="100%" frameborder="0" allowFullScreen></iframe>';
            $youtube_output = '<iframe class="img-responsive"  width="100%" height="100%" src="http://www.youtube.com/embed/' . $youtube_url . '" frameborder="0" allowfullscreen></iframe>';
        } else {
            $youtube_output = '<iframe src="http://www.youtube.com/embed/' . $youtube_url . '" width="' . $youtube_frame_size['width'] . '" height="' . $youtube_frame_size['height'] . '" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';
        }
    }

    return $youtube_output;
}

/*****SETTINGS********/
function _videojs_settings($post_format = '')
{
    switch ($post_format) {
        case 'slider':
            $video_style = image_style_load('ds_blog_video_post_slider');
            if (empty($video_style)) {
                $width = '570';
                $height = '330';
            } else {
                $thumb_effect = array_shift($video_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'Big':
            $video_style = image_style_load('ds_blog_video_post_big');
            if (empty($video_style)) {
                $width = '780';
                $height = '468';
            } else {
                $thumb_effect = array_shift($video_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'Small':
            $video_style = image_style_load('ds_blog_video_post_small');
            if (empty($video_style)) {
                $width = '370';
                $height = '222';
            } else {
                $thumb_effect = array_shift($video_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'gallery_node':
            $dimension = get_node_video_dimensions();
            $width = $dimension['width'];
            $height = $dimension['height'];
            break;
        default:
            $width = '200';
            $height = '200';
    }

    return array(
        'width' => $width,
        'height' => $height,
        'posterimage_field' => NULL,
        'posterimage_style' => NULL,
    );
}

function _vimeo_settings($post_format)
{
    switch ($post_format) {
        case 'slider':
            $vimeo_style = image_style_load('ds_blog_vimeo_post_slider');
            if (empty($vimeo_style)) {
                $width = '320';
                $height = '240';
            } else {
                $thumb_effect = array_shift($vimeo_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'Big':
            $vimeo_style = image_style_load('ds_blog_vimeo_post_big');
            if (empty($vimeo_style)) {
                $width = '624';
                $height = '468';
            } else {
                $thumb_effect = array_shift($vimeo_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'Small':
            $vimeo_style = image_style_load('ds_blog_vimeo_post_small');
            if (empty($vimeo_style)) {
                $width = '200';
                $height = '150';
            } else {
                $thumb_effect = array_shift($vimeo_style['effects']);
                $width = $thumb_effect['data']['width'];
                $height = $thumb_effect['data']['height'];
            }
            break;
        case 'gallery_node':
            $dimension = get_node_video_dimensions();
            $width = $dimension['width'];
            $height = $dimension['height'];
            break;
        default:
            $width = '100%';
            $height = '200';
    }

    return array(
        'width' => $width,
        'height' => $height,
    );
}


function _youtube_settings($post_format)
{
    switch ($post_format) {
        case 'gallery_node':
            $dimension = get_node_video_dimensions();
            $width = $dimension['width'];
            $height = $dimension['height'];
            break;
        default:
            $width = '100%';
            $height = '200';
    }

    return array(
        'width' => $width,
        'height' => $height,
    );
}

function get_node_video_dimensions()
{
    $video_dimensions = & drupal_static(__FUNCTION__);

    if (!isset($video_dimensions)) {
        $video_dimensions = array();
        //default settings vor video
        $colums_node_width = array(
            2 => '454',
            3 => '292',
            4 => '212',
        );

        $colums_node_height = array(
            2 => '295',
            3 => '190',
            4 => '138',
        );

        module_load_include('inc', 'designssquare_com_widget_gallery', 'inc/gallery-template-api');
        $gallery_settings = _gallery_style_tapi();
        if (!empty($gallery_settings['node_thumb']['ui_style'])) {
            //scaling from UI
            $video_dimensions['width'] = $gallery_settings['node_thumb']['width'];
            $video_dimensions['height'] = $gallery_settings['node_thumb']['height'];
        } elseif (!empty($gallery_settings['node_thumb']['design_style'])) {
            //100% width with default height
            $video_dimensions['width'] = '100%';
            $video_dimensions['height'] = $gallery_settings['node_thumb']['height'];
        } else {
            $video_dimensions['width'] = '100%';
            $columns = variable_get('ds_gallery_node_settings_columns', 4);
            $video_dimensions['height'] = $colums_node_height[$columns];

        }
    }
    return $video_dimensions;
}