<?php



/**
 * retrieves and construct video output from node with particular field as parameter
 * @return
 *      video output in html
 */
function construct_audio($node)
{
    $audio_render_array = field_view_field(
        'node',
        $node,
        'field_audio',
        array(
            'type' => 'audiofield_embedded',
            'label' => 'hidden',
            'field types' => array('file'),
            'description' => t('Displays an audio player and optional download link.'),
        )
    );
    return $audio_render_array;
}