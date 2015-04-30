<?php

function _default_smartbox_css($type)
{
    $css_scripts = & drupal_static(__FUNCTION__);
    if (!isset($css_scripts)) {
        $path_to_theme = base_path().drupal_get_path('theme', 'smartbox');
        $css_scripts = array();
        // GLOBAL STYLES -->
        $css_scripts[] = array('path' => $path_to_theme . '/smartbox/stylesheets/bootstrap.css', 'options' => array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
        $css_scripts[] = array('path' => $path_to_theme . '/smartbox/stylesheets/responsive.css', 'options' => array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
        $css_scripts[] = array('path' => $path_to_theme . '/smartbox/stylesheets/font-awesome-all.css', 'options' => array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
        $css_scripts[] = array('path' => $path_to_theme . '/smartbox/stylesheets/fancybox.css', 'options' => array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
        $css_scripts[] = array('path' => $path_to_theme . '/smartbox/stylesheets/theme.css', 'options' => array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
        $css_scripts[] = array('path' => $path_to_theme . '/smartbox/stylesheets/fonts.css', 'options' => array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
    }
    return $css_scripts;
}

function _default_smartbox_js($type)
{
    $js_scripts = & drupal_static(__FUNCTION__);
    if (!isset($js_scripts)) {
        $path_to_theme = base_path().drupal_get_path('theme', 'smartbox');
        $js_scripts = array();
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/jquery.min.js', 'options' => array('scope' => 'header', 'type' => 'file'));
        $js_scripts[] = array('path' =>  base_path() . drupal_get_path('module', 'designssquare_lib') . '/js/jquery/jquery-migrate.min.js', 'options' => array('scope' => 'header', 'type' => 'file'));
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/jquery.min.js', 'options' => array('scope' => 'header', 'type' => 'file'));
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/bootstrap.js', 'options' => array('scope' => 'footer', 'type' => 'file'));
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/bootstrap-dropdown.js', 'options' => array('scope' => 'footer', 'type' => 'file'));
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/jquery.flexslider-min.js', 'options' => array('scope' => 'footer', 'type' => 'file'));
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/jquery.tweet.js', 'options' => array('scope' => 'footer', 'type' => 'file'));
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/jquery.fancybox.pack.js', 'options' => array('scope' => 'footer', 'type' => 'file'));
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/jquery.fancybox-media.js', 'options' => array('scope' => 'footer', 'type' => 'file'));
        $js_scripts[] = array('path' => $path_to_theme . '/smartbox/javascripts/script.js', 'options' => array('scope' => 'footer', 'type' => 'file'));
    }
    return $js_scripts;
}

function _page_smartbox_js($type)
{
    $js_scripts = & drupal_static(__FUNCTION__);
    if (!isset($js_scripts)) {
        switch ($type) {
            case 'contact':
                $js_scripts[] = array('path' => base_path().drupal_get_path('theme', 'smartbox') . '/smartbox/javascripts/jquery.form.js', 'options' => array('scope' => 'footer', 'type' => 'file'));
                $js_scripts[] = array('path' => 'https://maps.googleapis.com/maps/api/js?sensor=false', 'options' => array('scope' => 'footer', 'type' => 'external'));
//            drupal_add_js('https://maps.googleapis.com/maps/api/js?sensor=false', array('type' => 'external', 'scope' => 'footer'));
                $js_to_add = 'var styles = [' . "\n";
                $js_to_add .= '{' . "\n";
                $js_to_add .= 'stylers: [' . "\n";
                $js_to_add .= '    { saturation: -85 }' . "\n";
                $js_to_add .= ']' . "\n";
                $js_to_add .= '},{' . "\n";
                $js_to_add .= '     featureType: \'road\',' . "\n";
                $js_to_add .= '    elementType: \'geometry\',' . "\n";
                $js_to_add .= '    stylers: [' . "\n";
                $js_to_add .= '       { hue: \'rgb(0,43,255)\' },' . "\n";
                $js_to_add .= '       { visibility: \'simplified\' }' . "\n";
                $js_to_add .= '   ]' . "\n";
                $js_to_add .= '},{' . "\n";
                $js_to_add .= '      featureType: \'road\',' . "\n";
                $js_to_add .= '   elementType: \'labels\',' . "\n";
                $js_to_add .= '   stylers: [' . "\n";
                $js_to_add .= '        { visibility: \'off\' }' . "\n";
                $js_to_add .= '   ]' . "\n";
                $js_to_add .= '}' . "\n";
                $js_to_add .= '],' . "\n";
                $js_to_add .= 'lat = 51.607,' . "\n";
                $js_to_add .= 'lng = -0.12248,' . "\n";
                $js_to_add .= 'styledMap = new google.maps.StyledMapType(styles,' . "\n";
                $js_to_add .= '    {name: \'Styled Map\'}),' . "\n";
                $js_to_add .= ' mapOptions = {' . "\n";
                $js_to_add .= '         zoom: 14,' . "\n";
                $js_to_add .= '    scrollwheel: false,' . "\n";
                $js_to_add .= '   center: new google.maps.LatLng( lat, lng ),' . "\n";
                $js_to_add .= '   mapTypeControlOptions: {' . "\n";
                $js_to_add .= '          mapTypeIds: [google.maps.MapTypeId.ROADMAP]' . "\n";
                $js_to_add .= '  }' . "\n";
                $js_to_add .= '},' . "\n";
                $js_to_add .= 'map = new google.maps.Map(document.getElementById(\'map\'), mapOptions),' . "\n";
                $js_to_add .= 'charlotte = new google.maps.LatLng( lat, lng ),' . "\n";
                $js_to_add .= 'marker = new google.maps.Marker({' . "\n";
                $js_to_add .= '    position: charlotte,' . "\n";
                $js_to_add .= '   map: map,' . "\n";
                $js_to_add .= '   title: \'Hello World\'' . "\n";
                $js_to_add .= ' });' . "\n";
                $js_to_add .= 'map.mapTypes.set(\'map_style\', styledMap);' . "\n";
                $js_to_add .= 'map.setMapTypeId(\'map_style\');' . "\n";

                $js_scripts[] = array('path' => $js_to_add, 'options' => array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));
            default:
        }

        $js_to_add = 'jQuery(document).ready(function() {' . "\n";
        $js_to_add .= "$('.dropdown-toggle').dropdown();";
        $js_to_add .= '});' . "\n";
        $js_scripts[] = array('path' => $js_to_add, 'options' => array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));
//    drupal_add_js($js_to_add, array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));

    }
    return $js_scripts;
}
