<?php



function espresso_js_alter(&$javascript) {
    module_load_include('module', 'designssquare_lib');
    //remove default so we can add theme specific version
    unset($javascript[drupal_get_path('theme','bootstrap').'/js/bootstrap.js']);

    //bring legacy support for jquery below 1.7
    include_jquery_legacy_support($javascript);
}


function espresso_preprocess_html(&$variables) {
    module_load_include('inc', 'designssquare_lib', 'includes/template_api');//for header tapi
    module_load_include('module', 'designssquare_lib');//for menu block
    $reqUrl = $_GET['q'];

    //header menu
    $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    //footer menu
    $variables['bottom_nav'] = menu_tree('menu-bottom-menu');
    $variables['bottom_nav']['#theme_wrappers'] = array('menu_tree__bottom');


//        _default_css();
//        _default_js();

    if ((arg(0) == 'node') && is_numeric(arg(1)) && ($node = node_load(arg(1)))) {
//            $widget = 'field_widgets';
//            $widget_list = field_get_items('node', $node, 'field_widgets');
//            (is_array($widget_list) && count($widget_list)) ? _add_widgets($widget_list, $node) : '';

        }

    $variables['head_tapi'] = _header_tapi_site($variables);

    //remove classes from body tag
    $variables['classes_array'] = array();

    //making regions available in html scope
    include_blocks($variables, 'html');

    //make contact template api available
//    $variables['contact_tapi'] = _contact_tapi();

    //retrieve header and background images
//    $variables['header_img'] = _header_img();
//    $variables['background_img'] = _background_img();
    //Custom Theme Settings
    $variables['espresso_bg_img'] = _background_img();
//    $variables['espresso_bg_img'] = variable_get('ds_theme_predefined_background',theme_get_setting('ds_theme_predefined_background')).'.jpg';

    //adding styles
    drupal_add_css(path_to_theme().'/assets/css/custom.css', array('group' => CSS_THEME + 2,'type' => 'file'));
}



function espresso_preprocess_comment(&$vars, $hook){
    module_load_include('inc', 'designssquare_lib', 'includes/template_api');//for header tapi

    $vars['comment_tapi'] = _comment_tapi($vars['comment']);
}


//function espresso_preprocess_block(&$vars, $hook){
//    switch($vars['block_html_id']){
//        case 'block-designssquare-com-theme-blocks-ds-blog-recent-posts':
//        case 'block-designssquare-com-theme-blocks-ds-about':
//        case 'block-designssquare-com-theme-blocks-ds-recent-tweets':
//        case 'block-designssquare-com-theme-blocks-ds-about-sidebar':
//        case 'block-designssquare-com-theme-blocks-ds-social':
//        case 'block-designssquare-com-theme-blocks-ds-blog-categories':
//        case 'block-designssquare-com-theme-blocks-ds-blog-archive':
//        case 'block-designssquare-com-theme-blocks-ds-portfolio-sidebar':
//        case 'block-designssquare-com-theme-blocks-ds-announcement':
//            $vars['theme_hook_suggestions'][] = 'block__no_wrap';
//            break;
//    }
//}

function espresso_preprocess_region(&$vars, $hook){
    switch($vars['region']){
        case 'block-designssquare-com-theme-espresso-ds-announcement':
            $vars['theme_hook_suggestions'][] = 'region__no_wrap';
            break;
    }
}

function espresso_preprocess_node(&$variables){
    module_load_include('inc', 'designssquare_lib', 'includes/template_api');//for contact tapi
    module_load_include('module', 'designssquare_lib');//for menu block

    //making regions available in html scope
    include_blocks($variables);

    /*******Page Var******/
    $variables['page_tapi'] = array();
    if(!empty($variables['node'])){
        $node = $variables['node'];

        switch($node->type){
            case 'contact':
//                $contact_title = field_get_items('node', $node, 'field_contact_form_title');
//                $contact_title_final = (is_array($contact_title[0]) && !empty($contact_title[0])) ? field_view_value('node', $node, 'field_contact_form_title', $contact_title[0]) : '';
//                $variables['contact_form_title'] = render($contact_title_final);
////                $variables['contact_sidebar'] = htmlspecialchars_decode(render($contact_title_final));
//
//                //make sidebar available
//                $contact_sidebar = field_get_items('node', $node, 'field_contact_side_bar');
//                $contact_sidebar_final = (is_array($contact_sidebar[0]) && !empty($contact_sidebar[0])) ? field_view_value('node', $node, 'field_contact_side_bar', $contact_sidebar[0]) : '';
//                $variables['contact_sidebar'] = htmlspecialchars_decode(render($contact_sidebar_final));

                //make contact template api available
                $variables['contact_tapi'] = _contact_tapi();
                $variables['theme_hook_suggestions'][] = 'node__contact';
                break;
            case 'basic_page_3_columns':
                $columns = array();
                $field_instance = field_get_items('node', $node, 'field_column_one');
                $field_value = ($field_instance) ?  field_view_value('node', $node, 'field_column_one', $field_instance[0]) : '';
                $columns['first'] = htmlspecialchars_decode(render($field_value));
                $field_instance = field_get_items('node', $node, 'field_column_two');
                $field_value = ($field_instance) ?  field_view_value('node', $node, 'field_column_two', $field_instance[0]) : '';
                $columns['second'] = htmlspecialchars_decode(render($field_value));
                $field_instance = field_get_items('node', $node, 'field_column_three');
                $field_value = ($field_instance) ?  field_view_value('node', $node, 'field_column_three', $field_instance[0]) : '';
                $columns['third'] = htmlspecialchars_decode(render($field_value));
                $variables['columns'] = $columns;
                $variables['theme_hook_suggestions'][] = 'node__basic_three_columns';
                break;
        }

    }
}

function espresso_preprocess_page(&$variables){
//    $node = $variables['node'];
    $reqUrl = $_GET['q'];


    /*******Page Var******/
    $variables['page_tapi'] = array();
    if(!empty($variables['node'])){
        $node = $variables['node'];

        switch($node->type){
            case 'home':
//                $variables['page_tapi'] = _home_tapi($node);
                //@ToDo consider move to page__espresso template
                $variables['theme_hook_suggestions'][] = 'page__home';
                break;
            case 'basic_page_3_columns':
//            case 'contact':
            case 'project':
            case 'portfolio':
//                $variables['page_tapi'] = _home_tapi($node);
                $variables['theme_hook_suggestions'][] = 'page__no_columns';
                break;
            case 'contact':
                $variables['title'] = '';
                break;
        }

    }else{
//        $variables['page_tapi']['title']= (!empty($variables['$title'])) ? $variables['$title'] : '';
//        $variables['page_tapi']['intro'] = '';
    }


    /*******User Login, Registration, Password*******/
    if(preg_match ('/user/', $reqUrl) && !$variables['logged_in']){
//        $variables['user_tapi'] = _user_tapi();
//        $variables['user_tapi']['is_authenticated'] = true;
//
//        $variables['user_login_link'] = url('user');
//        $variables['theme_hook_suggestions'][] = 'page__user';

    }else{
        //for user profile
//        $variables['user_tapi'] = _user_tapi();
//        $variables['user_tapi']['is_authenticated'] = true;
    }


    module_load_include('inc', 'designssquare_lib', 'includes/template_api');//for header tapi
    module_load_include('module', 'designssquare_lib');//for menu block

    $variables['head_tapi'] = _header_tapi_site($variables);

    //remove classes from body tag
//    $variables['classes_array'] = array();

    //making regions available in html scope
//    include_blocks($variables);

}

function _background_img(){
    $bg_img = base_path().path_to_theme().'/assets/img/'.variable_get('ds_theme_predefined_background',theme_get_setting('ds_theme_predefined_background')).'.jpg';//default
    $bg_enabled = variable_get('ds_custom_bg_enabled',theme_get_setting('ds_custom_bg_enabled'));



    if( $bg_enabled && $background_fid = variable_get('ds_theme_custom_background',theme_get_setting('ds_theme_custom_background'))){
        $file = file_load($background_fid);
        $bg_img = ($file) ? file_create_url($file->uri) :  $bg_img;
    }

    return $bg_img;
}

/*********Menus******/
function espresso_menu_tree(&$variables) {
    return '<ul class="navigation">' . $variables['tree'] . '</ul>';
}

function espresso_menu_tree__bottom(&$variables){
    return '<ul class="row">' . $variables['tree'] . '</ul>';
}


