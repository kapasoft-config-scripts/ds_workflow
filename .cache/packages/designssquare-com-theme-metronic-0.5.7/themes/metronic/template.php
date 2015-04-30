<?php


function metronic_preprocess_html(&$vars)
{
    $reqUrl = $_GET['q'];
    $type = 'some';
    //filter html,php tags
    module_load_include('inc', 'designssquare_lib', 'includes/template_api');
    $vars['head_title'] = removes_tags($vars['head_title']);

    //get the current content from cache
    $content = drupal_set_page_content();
    //indicate that you are not adding content but just reading it by setting static variable 'system...added' to False
    $system_main_content_added = & drupal_static('system_main_content_added');
    $system_main_content_added = FALSE;


    /*****Theme Settings******/
    $theme_settings_tapi = _theme_settings_tapi();
    //body class
    if ($theme_settings_tapi['header']['value'] == 'fixed') {
        $vars['classes_array'][] = 'page-header-fixed';
    }

    if ($theme_settings_tapi['layout']['value'] == 'boxed') {
        $vars['classes_array'][] = 'page-boxed';
        $vars['is_boxed'] = true;
    } else {
        $vars['is_boxed'] = false;
    }

    if ($theme_settings_tapi['sidebar_position']['value'] == 'right') {
        $vars['classes_array'][] = 'page-sidebar-reversed';
    }
    //sidebar only fixed if heater is fixed as well
    if ($theme_settings_tapi['header']['value'] == 'fixed' && $theme_settings_tapi['sidebar']['value'] == 'fixed') {
        $vars['classes_array'][] = 'page-sidebar-fixed';
    }

    if ($theme_settings_tapi['footer']['value'] == 'fixed') {
        $vars['classes_array'][] = 'page-footer-fixed';
    }

    $vars['classes_array'][] = 'page-quick-sidebar-over-content';


    //user,registration, password reset
    if (preg_match('/user/', $reqUrl) && !$vars['logged_in']) {
        $vars['user_login_tapi'] = _user_login_tapi();
        $vars['theme_hook_suggestions'][] = 'html__login';
        include_blocks_from_region('login_footer', $vars);
    }


    //locked screen
    $node = (isset($content['nodes']) && !empty($content['nodes'])) ? array_shift($content['nodes']) : null;
    if (!empty($node['#node'])) {
        $type = $node['#node']->type;
        switch ($type) {
            case 'lock_screen':
                $vars['header_tapi'] = _header_tapi();
                $vars['theme_hook_suggestions'][] = 'html__lock';
                break;
            case 'error_full':
                $vars['theme_hook_suggestions'][] = 'html__error';
                break;
            case 'error_full2':
                $vars['theme_hook_suggestions'][] = 'html__error2';
                break;
            case 'error_500_full':
                $vars['theme_hook_suggestions'][] = 'html__error_500full';
                break;
        }
    }

    //resolve metronic specific bootstrap css over the any other types
    if(!is_metronic_type($type)){
        $vars['classes_array'][] = 'no-metronic-specific';
    }

    //make user menu available
    //NO MORE NEEDED Its convention of TAPI
//    $vars['header']['#vars_tapi']['user_menu'] = array(
//        '#theme' => 'template_api_user_menu',
//        '#menu_tapi' => menu_tapi('user-menu'),
//    );

    //fix theme top bar to come down when Drupal admin menu to avoid conflict
    global $user;
//    if ($user->uid && user_has_role(array('moderator', 'administrator'))) {
    $roles = array_intersect_key(user_roles(), $user->roles);
    if ($user->uid && in_array('administrator',$roles)) {
        //authenticated user
        $inline_css = '.page-header.navbar{' . "\n";
        if(module_exists('admin_menu')){
            $inline_css .= 'top: 5px;z-index:100' . "\n";
        }else{
            $inline_css .= 'top: 20px;z-index:100' . "\n";
        }
        $inline_css .= '}' . "\n";
        drupal_add_css($inline_css, array('type' => 'inline', 'weight' => CSS_THEME));
    }

}

function metronic_preprocess_field(&$vars){
    if($vars['element']['#field_name'] == 'body'){
        $vars['theme_hook_suggestions'][] = 'field__no_wrap';
    }
}


function metronic_preprocess_node(&$vars)
{
    //per layout
    if (!empty($vars['node'])) {
        $node = $vars['node'];
        $type = $node->type;
        if(is_metronic_type($type)){
            $vars['theme_hook_suggestions'][] = 'node__no_wrap';
        }
    }
}

/**
 * checks if the particular type is of metronic theme
 * @param $type
 *        string of node type
 */
function is_metronic_type($type){
    switch ($type) {
        case 'lock_screen':
        case 'contact_us':
        case 'error':
        case 'error_full':
        case 'error_500_full':
        case 'error_full2':
        case 'error_500':
        case 'dashboard':
        case 'products':
        case 'orders':
        case 'order_view':
        case 'product_edit':
        case 'ui_tree':
        case 'progress_bar':
        case 'notifica8_notifications':
        case 'toastr_notifications':
        case 'extended_modals':
        case 'date_paginator':
        case 'nestable_list':
        case 'pickers':
        case 'custom_dropdowns':
        case 'form_tools':
        case 'editors':
        case 'ion_range_sliders':
        case 'noui_range_sliders':
        case 'jquery_ui_sliders':
        case 'form_wizard':
        case 'form_layouts':
        case 'form_x_editable':
        case 'form_validation':
        case 'multiple_file_upload':
        case 'dropzone_file_upload':
        case 'image_crop':
        case 'editable_datatables':
        case 'managed_datatables':
        case 'advanced_datatables':
        case 'ajax_datatables':
        case 'vector_maps':
        case 'ajax_portlets':
        case 'portfolio':
        case 'timeline':
        case 'blog':
        case 'blog_post':
        case 'news':
        case 'about_us':
        case 'calendar':
        case 'user':
        case 'login':
        case 'lock_screen':
        case 'invoice':
        case 'pricing_tables':
        case 'error':
        case 'error_full':
        case 'error_full2':
        case 'error_500':
        case 'error_500_full':
        case 'inbox':
            return true;
        default:
            return false;
    }
}

function metronic_preprocess_page(&$vars)
{
    //per layout
    if (!empty($vars['node'])) {
        $node = $vars['node'];
        $type = $node->type;
        switch ($type) {
            case 'contact_us':
                $vars['theme_hook_suggestions'][] = 'page__contact_us';
                break;
            case 'lock_screen':
                $vars['user_tapi'] = _user_tapi();
                $vars['theme_hook_suggestions'][] = 'page__lock';
                break;
            case 'error':
                $vars['search_tapi'] = _search_tapi();
                $vars['theme_hook_suggestions'][] = 'page__error';
                break;
            case 'error_full':
                $vars['search_tapi'] = _search_tapi();
                $vars['theme_hook_suggestions'][] = 'page__error_full';
                break;
            case 'error_500_full':
            case 'error_full2':
                $vars['theme_hook_suggestions'][] = 'page__error_full2';
                break;
            case 'error_500':
                $vars['theme_hook_suggestions'][] = 'page__error_500';
                break;
        }
    } else {
        $type = 'none';
    }


    $reqUrl = $_GET['q'];

    //user handling
    if (preg_match('/user/', $reqUrl) && !$vars['logged_in']) {
        $type = 'login';
        $vars['theme_hook_suggestions'][] = 'page__login';
        include_blocks_from_region('login_footer', $vars);
    } elseif (preg_match('/user/', $reqUrl) && $vars['logged_in']) {
        $type = 'user';
        $vars['theme_hook_suggestions'][] = 'page__user';
    }

    //handling css
    _default_css($type);

    //handling js
    _default_js();
    _plugin_js($type);
    _init_js($type);

}

//function metronic_css_ckeditor_alter(&$css_scripts, $vars){
//    $type = (isset($vars['node']) && isset($vars['node']->type)) ? $vars['node']->type : 'default';
//    $css_scripts = array_merge($css_scripts, array_map('_strip_path',_default_css_list($type)));
//}

//function _strip_path($script){
//    return (isset($script['path'])) ? $script['path'] : '';
//}

function _default_css($plugin_type)
{
    $is_metronic = is_metronic_type($plugin_type);
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/drupal/custom_metronic.css', array('type' => 'file', 'weight' => CSS_THEME + 4));

    //BEGIN GLOBAL MANDATORY STYLES -->
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/drupal/metronic_fonts.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/font-awesome/css/font-awesome.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/simple-line-icons/simple-line-icons.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap/css/bootstrap.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
    ($is_metronic) ? drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/uniform/css/uniform.default.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE)) : '';
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-switch/css/bootstrap-switch.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
//<!-- END GLOBAL MANDATORY STYLES -->

    _import_plugin_css($plugin_type);

//<!-- BEGIN THEME STYLES -->
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/css/components.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/css/plugins.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/layout/css/layout.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
    _include_theme_color();
    drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/layout/css/custom.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
}

function _include_theme_color()
{
    module_load_include('inc', 'designssquare_lib_template_api', 'includes/template_api');
    $theme_tapi = _theme_settings_tapi();
    $proposed_css = drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/layout/css/themes/' . $theme_tapi['color']['value'] . '.css';
    if (file_exists($proposed_css)) {
        $final_css = $proposed_css;
    } else {
        $final_css = drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/layout/css/themes/default.css';
    }
    drupal_add_css($final_css, array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
}

//function _plugin_css_list($type)
//{
//    $css_list = array();
//    $path_to_theme = drupal_get_path('theme', $GLOBALS['theme']);
//
//    switch ($type) {
//        case 'none':
//        case 'dashboard':
//            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
//        $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/gritter/css/jquery.gritter.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//        $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-daterangepicker/daterangepicker-bs3.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//        $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fullcalendar/fullcalendar/fullcalendar.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//        $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/jqvmap.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//        $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/tasks.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'products':
//        case 'orders':
//            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
//        $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//        $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//        $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'order_view':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datetimepicker/css/datetimepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'product_edit':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datetimepicker/css/datetimepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fancybox/source/jquery.fancybox.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'ui_tree':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jstree/dist/themes/default/style.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'progress_bar':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/pace/themes/pace-theme-flash.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'notifica8_notifications':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'toastr_notifications':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-toastr/toastr.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'extended_modals':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-modal/css/bootstrap-modal-bs3patch.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-modal/css/bootstrap-modal.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'date_paginator':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'nestable_list':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-nestable/jquery.nestable.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'pickers':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/clockface/css/clockface.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/css/datepicker3.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-timepicker/css/bootstrap-timepicker.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-colorpicker/css/colorpicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-daterangepicker/daterangepicker-bs3.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datetimepicker/css/datetimepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'custom_dropdowns':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-select/bootstrap-select.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-multi-select/css/multi-select.css', 'options' => array('type'=>'file', 'weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'form_tools':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-fileinput/bootstrap-fileinput.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-switch/css/bootstrap-switch.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-tags-input/jquery.tagsinput.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-markdown/css/bootstrap-markdown.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/typeahead/typeahead.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'editors':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-markdown/css/bootstrap-markdown.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-summernote/summernote.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'ion_range_sliders':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/ion.rangeslider/css/ion.rangeSlider.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/ion.rangeslider/css/ion.rangeSlider.Metronic.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'noui_range_sliders':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/nouislider/jquery.nouislider.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'jquery_ui_sliders':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-ui/jquery-ui-1.10.3.custom.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'form_wizard':
//        case 'form_layouts':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'form_x_editable':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-timepicker/css/bootstrap-timepicker.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datetimepicker/css/datetimepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-editable/bootstrap-editable/css/bootstrap-editable.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-editable/inputs-ext/address/address.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'form_validation':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-markdown/css/bootstrap-markdown.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'multiple_file_upload':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/blueimp-gallery/blueimp-gallery.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/css/jquery.fileupload.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/css/jquery.fileupload-ui.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'dropzone_file_upload':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/dropzone/css/dropzone.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'image_crop':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jcrop/css/jquery.Jcrop.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/image-crop.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//           break;
//        case 'editable_datatables':
//        case 'managed_datatables':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'advanced_datatables':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/extensions/Scroller/css/dataTables.scroller.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/extensions/ColReorder/css/dataTables.colReorder.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'ajax_datatables':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'vector_maps':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/jqvmap.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'ajax_portlets':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-toastr/toastr.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'portfolio':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fancybox/source/jquery.fancybox.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/portfolio.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'timeline':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/timeline.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'blog':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/blog.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/news.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'blog_post':
//            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/blog.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'news':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/news.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'about_us':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/about-us.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'calendar':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fullcalendar/fullcalendar/fullcalendar.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'user':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-fileinput/bootstrap-fileinput.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/profile.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'login':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/login-soft.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'lock_screen':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/lock.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'invoice':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/invoice.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'pricing_tables':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/pricing-table.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'error':
//        case 'error_full':
//        case 'error_full2':
//        case 'error_500':
//        case 'error_500_full':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/error.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//        case 'inbox':
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fancybox/source/jquery.fancybox.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/blueimp-gallery/blueimp-gallery.min.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/css/jquery.fileupload.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/css/jquery.fileupload-ui.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            $css_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/css/inbox.css', 'options' => array('type'=>'file','weight'=> CSS_THEME, 'preprocess' => FALSE));
//            break;
//    }
//
//    return $css_list;
//}

function _import_plugin_css($plugin_type)
{
    switch ($plugin_type) {
//        case 'none':
        case 'dashboard':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/gritter/css/jquery.gritter.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-daterangepicker/daterangepicker-bs3.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fullcalendar/fullcalendar/fullcalendar.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/jqvmap.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
//<!-- END PAGE LEVEL PLUGIN STYLES -->
//<!-- BEGIN PAGE STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/tasks.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
//<!-- END PAGE STYLES -->
            break;
        case 'products':
        case 'orders':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'order_view':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datetimepicker/css/datetimepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'product_edit':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datetimepicker/css/datetimepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fancybox/source/jquery.fancybox.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'ui_tree':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jstree/dist/themes/default/style.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'progress_bar':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/pace/themes/pace-theme-flash.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'notifica8_notifications':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'toastr_notifications':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-toastr/toastr.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'extended_modals':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-modal/css/bootstrap-modal-bs3patch.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-modal/css/bootstrap-modal.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'date_paginator':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'nestable_list':
            //<!-- BEGIN PAGE LEVEL PLUGIN STYLES -->
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-nestable/jquery.nestable.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'pickers':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/clockface/css/clockface.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/css/datepicker3.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-timepicker/css/bootstrap-timepicker.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-colorpicker/css/colorpicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . 'assets/global/plugins/bootstrap-daterangepicker/daterangepicker-bs3.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . 'assets/global/plugins/bootstrap-datetimepicker/css/datetimepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'custom_dropdowns':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-select/bootstrap-select.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-multi-select/css/multi-select.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'form_tools':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-fileinput/bootstrap-fileinput.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-switch/css/bootstrap-switch.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-tags-input/jquery.tagsinput.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-markdown/css/bootstrap-markdown.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/typeahead/typeahead.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'editors':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-markdown/css/bootstrap-markdown.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-summernote/summernote.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'ion_range_sliders':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/ion.rangeslider/css/ion.rangeSlider.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/ion.rangeslider/css/ion.rangeSlider.Metronic.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'noui_range_sliders':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/nouislider/jquery.nouislider.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'jquery_ui_sliders':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-ui/jquery-ui-1.10.3.custom.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'form_wizard':
        case 'form_layouts':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'form_x_editable':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-timepicker/css/bootstrap-timepicker.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datetimepicker/css/datetimepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-editable/bootstrap-editable/css/bootstrap-editable.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-editable/inputs-ext/address/address.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'form_validation':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-markdown/css/bootstrap-markdown.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'multiple_file_upload':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/blueimp-gallery/blueimp-gallery.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/css/jquery.fileupload.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/css/jquery.fileupload-ui.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'dropzone_file_upload':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/dropzone/css/dropzone.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'image_crop':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jcrop/css/jquery.Jcrop.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/image-crop.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'editable_datatables':
        case 'managed_datatables':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'advanced_datatables':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/extensions/Scroller/css/dataTables.scroller.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/extensions/ColReorder/css/dataTables.colReorder.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'ajax_datatables':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/css/datepicker.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'vector_maps':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/jqvmap.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'ajax_portlets':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-toastr/toastr.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'portfolio':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fancybox/source/jquery.fancybox.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/portfolio.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'timeline':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/timeline.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'blog':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/blog.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/news.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'blog_post':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/blog.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'news':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/news.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'about_us':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/about-us.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'calendar':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fullcalendar/fullcalendar/fullcalendar.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'user':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-fileinput/bootstrap-fileinput.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/profile.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'login':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/login-soft.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'lock_screen':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/lock.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'invoice':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/invoice.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'pricing_tables':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/pricing-table.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'error':
        case 'error_full':
        case 'error_full2':
        case 'error_500':
        case 'error_500_full':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/error.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
        case 'inbox':
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fancybox/source/jquery.fancybox.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/blueimp-gallery/blueimp-gallery.min.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/css/jquery.fileupload.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/css/jquery.fileupload-ui.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            drupal_add_css(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/css/inbox.css', array('type' => 'file', 'weight' => CSS_THEME, 'preprocess' => FALSE));
            break;
    }
}

//function metronic_js_ckeditor_alter(&$js_scripts, $vars){
//    $type = (isset($vars['node']) && isset($vars['node']->type)) ? $vars['node']->type : 'default';
//
////    $js_scripts = array_merge($js_scripts, array_map('_strip_path',_default_js_list()));
////    $js_scripts = array_merge($js_scripts, array_map('_strip_path',_plugin_js_list($type)));
////    $js_scripts = array_merge($js_scripts, array_map('_strip_path',_init_js_list($type)));
//    $path_to_theme = drupal_get_path('theme', $GLOBALS['theme']);
//
//    $js_scripts[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-1.11.0.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    $js_scripts[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-migrate-1.2.1.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//    $js_scripts = array_merge($js_scripts, _default_js_list());
//    $js_scripts = array_merge($js_scripts, _plugin_js_list($type));
//}
//
//function metronic_js_inline_ckeditor_alter(&$js_scripts, $vars){
//    $type = (isset($vars['node']) && isset($vars['node']->type)) ? $vars['node']->type : 'default';
//    $js_scripts = array_merge($js_scripts, _init_js_list($type));
//}


//function _default_js_list()
//{
//    $js_list = array();
//    $path_to_theme = drupal_get_path('theme', $GLOBALS['theme']);
//    //production
//    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-ui/jquery-ui-1.10.3.custom.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap/js/bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
////    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap/js/bootstrap.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-hover-dropdown/bootstrap-hover-dropdown.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-slimscroll/jquery.slimscroll.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery.blockui.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery.cokie.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/uniform/jquery.uniform.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-switch/js/bootstrap-switch.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//    return $js_list;
//}

function _default_js()
{
    //production
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-ui/jquery-ui-1.10.3.custom.min.js', array('scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap/js/bootstrap.min.js', array('scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-hover-dropdown/bootstrap-hover-dropdown.min.js', array('scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-slimscroll/jquery.slimscroll.min.js', array('scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery.blockui.min.js', array('scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery.cokie.min.js', array('scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/uniform/jquery.uniform.min.js', array('scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-switch/js/bootstrap-switch.min.js', array('scope' => 'footer', 'type' => 'file'));
}

function _plugin_js($type)
{
    switch ($type) {
//        case 'none';
        case 'dashboard':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/jquery.vmap.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.russia.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.world.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.europe.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.germany.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.usa.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/data/jquery.vmap.sampledata.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.min.js', array('scope' => 'footer', 'type' => 'file'));

            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.resize.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.categories.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery.pulsate.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-daterangepicker/moment.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-daterangepicker/daterangepicker.js', array('scope' => 'footer', 'type' => 'file'));
            // IMPORTANT! fullcalendar depends on jquery-ui-1.10.3.custom.min.js for drag & drop support
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fullcalendar/fullcalendar/fullcalendar.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-easypiechart/jquery.easypiechart.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery.sparkline.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/gritter/js/jquery.gritter.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/index.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/tasks.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'ecommerce_dashboard':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.resize.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.categories.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ecommerce-index.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'orders':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/scripts/datatable.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ecommerce-orders.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'order_view':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datetimepicker/js/bootstrap-datetimepicker.min.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/scripts/datatable.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ecommerce-orders-view.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'products':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/scripts/datatable.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ecommerce-products.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'product_edit':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));

            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datetimepicker/js/bootstrap-datetimepicker.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-maxlength/bootstrap-maxlength.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-touchspin/bootstrap.touchspin.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fancybox/source/jquery.fancybox.pack.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/plupload/js/plupload.full.min.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/scripts/datatable.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ecommerce-products-edit.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'ui_general':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery.pulsate.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-bootpag/jquery.bootpag.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/holder.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ui-general.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'ui_tree':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jstree/dist/jstree.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ui-tree.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            break;
        case 'progress_bar':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/pace/pace.min.js', array('scope' => 'header', 'weight' => JS_THEME - 2, 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            break;
        case 'notifica8_notifications':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ui-notific8.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            break;
        case 'toastr_notifications':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-toastr/toastr.min.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ui-toastr.js', array('scope' => 'footer', 'type' => 'file'));
            _shared_page_js();
            break;
        case 'alerts_dialogs':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootbox/bootbox.min.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ui-alert-dialog-api.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'extended_modals':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-modal/js/bootstrap-modalmanager.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-modal/js/bootstrap-modal.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ui-extended-modals.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'date_paginator':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/moment.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepaginator/bootstrap-datepaginator.min.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ui-datepaginator.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'nestable_list':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-nestable/jquery.nestable.js', array('scope' => 'footer', 'type' => 'file'));
            //BEGIN PAGE LEVEL SCRIPTS
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/ui-nestable.js', array('scope' => 'footer', 'type' => 'file'));
            _shared_page_js();
            break;
        case 'pickers':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-timepicker/js/bootstrap-timepicker.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/clockface/js/clockface.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-daterangepicker/moment.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-daterangepicker/daterangepicker.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-colorpicker/js/bootstrap-colorpicker.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datetimepicker/js/bootstrap-datetimepicker.min.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-pickers.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'custom_dropdowns':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-select/bootstrap-select.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-multi-select/js/jquery.multi-select.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-dropdowns.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'form_tools':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fuelux/js/spinner.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-fileinput/bootstrap-fileinput.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-inputmask/jquery.inputmask.bundle.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery.input-ip-address-control-1.0.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-pwstrength/pwstrength-bootstrap.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-switch/js/bootstrap-switch.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-tags-input/jquery.tagsinput.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-maxlength/bootstrap-maxlength.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-touchspin/bootstrap.touchspin.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/typeahead/handlebars.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/typeahead/typeahead.bundle.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/ckeditor/ckeditor.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-form-tools.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            drupal_add_js('https://www.google.com/recaptcha/api/challenge?k=6LcrK9cSAAAAALEcjG9gTRPbeA0yAVsKd8sBpFpR', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'weight' => 1005, 'type' => 'external'));
            break;
        case 'editors':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/wysihtml5-0.3.0.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-markdown/lib/markdown.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-markdown/js/bootstrap-markdown.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-summernote/summernote.min.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-editors.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'ion_range_sliders':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/ion.rangeslider/js/ion-rangeSlider/ion.rangeSlider.min.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-ion-sliders.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'noui_range_sliders':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/nouislider/jquery.nouislider.min.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();;
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-nouisliders.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'jquery_ui_sliders':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-jqueryui-sliders.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-nouisliders.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'knob_circle_dials':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-knob/js/jquery.knob.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/components-knob-dials.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'form_layouts':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/form-samples.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'form_x_editable':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/wysihtml5-0.3.0.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/locales/bootstrap-datepicker.zh-CN.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datetimepicker/js/bootstrap-datetimepicker.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/moment.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery.mockjax.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-editable/bootstrap-editable/js/bootstrap-editable.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-editable/inputs-ext/address/address.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-editable/inputs-ext/wysihtml5/wysihtml5.js', array('scope' => 'footer', 'type' => 'file'));


            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/form-editable.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'form_wizard':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-validation/js/jquery.validate.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-validation/js/additional-methods.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wizard/jquery.bootstrap.wizard.min.js', array('scope' => 'footer', 'type' => 'file'));

            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/form-wizard.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'form_validation':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-validation/js/jquery.validate.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-validation/js/additional-methods.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/wysihtml5-0.3.0.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/ckeditor/ckeditor.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-markdown/js/bootstrap-markdown.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-markdown/lib/markdown.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/form-validation.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'image_crop':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jcrop/js/jquery.color.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jcrop/js/jquery.Jcrop.min.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/form-image-crop.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'multiple_file_upload':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fancybox/source/jquery.fancybox.pack.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/vendor/jquery.ui.widget.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/vendor/tmpl.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/vendor/load-image.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/vendor/canvas-to-blob.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/blueimp-gallery/jquery.blueimp-gallery.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.iframe-transport.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-process.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-image.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-audio.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-video.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-validate.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-ui.js', array('scope' => 'footer', 'type' => 'file'));

            $jquery_transport = array(
                '#tag' => 'script',
                '#attributes' => array( // Set up an array of attributes inside the tag
                    'src' => drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/cors/jquery.xdr-transport.js',
                ),
                '#prefix' => '<!--[if (gte IE 8)&(lt IE 10)]>',
                '#value' => '',
                '#suffix' => '<![endif]-->',
            );
            drupal_add_html_head($jquery_transport, 'jquery_transport');

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/form-fileupload.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'dropzone_file_upload':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/dropzone/dropzone.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/form-dropzone.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'managed_datatables':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/table-managed.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'editable_datatables':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/table-editable.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'advanced_datatables':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/extensions/TableTools/js/dataTables.tableTools.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/extensions/ColReorder/js/dataTables.colReorder.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/extensions/Scroller/js/dataTables.scroller.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/table-advanced.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'ajax_datatables':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/scripts/datatable.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/table-ajax.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'ajax_portlets':
            //BEGIN PAGE LEVEL SCRIPTS
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-toastr/toastr.min.js', array('scope' => 'footer', 'type' => 'file'));
            _shared_page_js();
            break;
        case 'google_maps':
            drupal_add_js('http://maps.google.com/maps/api/js?sensor=false', array('scope' => 'footer', 'type' => 'external'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/gmaps/gmaps.min.js', array('scope' => 'footer', 'type' => 'file'));

            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/maps-google.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'draggable_portlets':
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/portlet-draggable.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'vector_maps':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/jquery.vmap.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.russia.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.world.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.europe.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.germany.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.usa.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jqvmap/jqvmap/data/jquery.vmap.sampledata.js', array('scope' => 'footer', 'type' => 'file'));

            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/maps-vector.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'visual_charts':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.resize.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.pie.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.stack.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.crosshair.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/flot/jquery.flot.categories.min.js', array('scope' => 'footer', 'type' => 'file'));

            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/charts.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'portfolio':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-mixitup/jquery.mixitup.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fancybox/source/jquery.fancybox.pack.js', array('scope' => 'footer', 'type' => 'file'));

            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/portfolio.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'calendar':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fullcalendar/fullcalendar/fullcalendar.min.js', array('scope' => 'footer', 'type' => 'file'));

            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/calendar.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'contact_us':
            drupal_add_js('http://maps.google.com/maps/api/js?sensor=true', array('scope' => 'footer', 'type' => 'external'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/gmaps/gmaps.min.js', array('scope' => 'footer', 'type' => 'file'));

            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/contact-us.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'login':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-validation/js/jquery.validate.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/backstretch/jquery.backstretch.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/select2/select2.min.js', array('scope' => 'footer', 'type' => 'file'));

            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/login-soft.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'user':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-fileinput/bootstrap-fileinput.js', array('scope' => 'footer', 'type' => 'file'));

            _shared_page_js();
            break;
        case 'lock_screen':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/backstretch/jquery.backstretch.min.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));

            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/lock.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        case 'inbox':
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/fancybox/source/jquery.fancybox.pack.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/wysihtml5-0.3.0.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/vendor/jquery.ui.widget.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/vendor/tmpl.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/vendor/load-image.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/vendor/canvas-to-blob.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/blueimp-gallery/jquery.blueimp-gallery.min.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.iframe-transport.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-process.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-audio.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-video.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-validate.js', array('scope' => 'footer', 'type' => 'file'));
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-ui.js', array('scope' => 'footer', 'type' => 'file'));

            $jquery_transport = array(
                '#tag' => 'script',
                '#attributes' => array( // Set up an array of attributes inside the tag
                    'src' => drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/cors/jquery.xdr-transport.js',
                ),
                '#prefix' => '<!--[if (gte IE 8)&(lt IE 10)]>',
                '#value' => '',
                '#suffix' => '<![endif]-->',
            );
            drupal_add_html_head($jquery_transport, 'jquery_transport');

            _shared_page_js();
            drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/pages/scripts/inbox.js', array('weight' => JS_THEME + 6, 'scope' => 'footer', 'type' => 'file'));
            break;
        default:
            //BEGIN PAGE LEVEL SCRIPTS
            _shared_page_js();
            break;
    }
}

//function _plugin_js_list($type)
//{
//    $js_list = array();
//    $path_to_theme = drupal_get_path('theme', $GLOBALS['theme']);
//
//    switch ($type) {
//        case 'none';
//        case 'dashboard':
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/jquery.vmap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.russia.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.world.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.europe.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.germany.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.usa.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/data/jquery.vmap.sampledata.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.resize.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.categories.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery.pulsate.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-daterangepicker/moment.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-daterangepicker/daterangepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            // IMPORTANT! fullcalendar depends on jquery-ui-1.10.3.custom.min.js for drag & drop support
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fullcalendar/fullcalendar/fullcalendar.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-easypiechart/jquery.easypiechart.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery.sparkline.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/gritter/js/jquery.gritter.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//        $js_list = array_merge($js_list, _shared_page_js_list());
//        $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/index.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//        $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/tasks.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'ecommerce_dashboard':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.resize.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.categories.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ecommerce-index.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'orders':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/scripts/datatable.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ecommerce-orders.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'order_view':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datetimepicker/js/bootstrap-datetimepicker.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/scripts/datatable.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ecommerce-orders-view.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'products':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/scripts/datatable.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ecommerce-products.js', 'options' => array('weight' =>JS_THEME + 6, 'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'product_edit':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datetimepicker/js/bootstrap-datetimepicker.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-maxlength/bootstrap-maxlength.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-touchspin/bootstrap.touchspin.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fancybox/source/jquery.fancybox.pack.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/plupload/js/plupload.full.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/scripts/datatable.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ecommerce-products-edit.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'ui_general':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery.pulsate.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-bootpag/jquery.bootpag.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/holder.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ui-general.js', 'options' => array('weight' =>JS_THEME + 6, 'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'ui_tree':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jstree/dist/jstree.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ui-tree.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            break;
//        case 'progress_bar':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jstree/dist/jstree.min.js', 'options' => array('scope'=>'header', 'weight' => JS_THEME - 2, 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            break;
//        case 'notifica8_notifications':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ui-notific8.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            break;
//        case 'toastr_notifications':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-toastr/toastr.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ui-toastr.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            break;
//        case 'alerts_dialogs':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootbox/bootbox.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ui-alert-dialog-api.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'extended_modals':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-modal/js/bootstrap-modalmanager.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-modal/js/bootstrap-modal.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ui-extended-modals.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'date_paginator':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/moment.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepaginator/bootstrap-datepaginator.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ui-datepaginator.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'nestable_list':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-nestable/jquery.nestable.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/ui-nestable.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            break;
//        case 'pickers':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-timepicker/js/bootstrap-timepicker.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/clockface/js/clockface.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-daterangepicker/moment.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-daterangepicker/daterangepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-colorpicker/js/bootstrap-colorpicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datetimepicker/js/bootstrap-datetimepicker.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-pickers.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'custom_dropdowns':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-select/bootstrap-select.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-multi-select/js/jquery.multi-select.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-dropdowns.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'form_tools':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fuelux/js/spinner.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-fileinput/bootstrap-fileinput.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-inputmask/jquery.inputmask.bundle.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery.input-ip-address-control-1.0.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-pwstrength/pwstrength-bootstrap.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-switch/js/bootstrap-switch.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-tags-input/jquery.tagsinput.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-maxlength/bootstrap-maxlength.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-touchspin/bootstrap.touchspin.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/typeahead/handlebars.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/typeahead/typeahead.bundle.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/ckeditor/ckeditor.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-form-tools.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> 'https://www.google.com/recaptcha/api/challenge?k=6LcrK9cSAAAAALEcjG9gTRPbeA0yAVsKd8sBpFpR', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'external','weight' => 1005,));
//            break;
//        case 'editors':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/wysihtml5-0.3.0.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-markdown/lib/markdown.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-markdown/js/bootstrap-markdown.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-summernote/summernote.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-editors.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'ion_range_sliders':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/ion.rangeslider/js/ion-rangeSlider/ion.rangeSlider.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-ion-sliders.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'noui_range_sliders':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/nouislider/jquery.nouislider.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-nouisliders.js', 'options' => array('weight' =>JS_THEME + 6, 'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'jquery_ui_sliders':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-jqueryui-sliders.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-nouisliders.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'knob_circle_dials':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-knob/js/jquery.knob.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/components-knob-dials.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'form_layouts':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/form-samples.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'form_x_editable':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/wysihtml5-0.3.0.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/locales/bootstrap-datepicker.zh-CN.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datetimepicker/js/bootstrap-datetimepicker.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/moment.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery.mockjax.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-editable/bootstrap-editable/js/bootstrap-editable.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-editable/inputs-ext/address/address.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-editable/inputs-ext/wysihtml5/wysihtml5.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/form-editable.js', 'options' => array('weight' =>JS_THEME + 6, 'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'form_wizard':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-validation/js/jquery.validate.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-validation/js/additional-methods.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wizard/jquery.bootstrap.wizard.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/form-wizard.js', 'options' => array('weight' =>JS_THEME + 6, 'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'form_validation':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-validation/js/jquery.validate.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-validation/js/additional-methods.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/wysihtml5-0.3.0.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/ckeditor/ckeditor.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-markdown/js/bootstrap-markdown.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-markdown/lib/markdown.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/form-validation.js', 'options' => array('weight' =>JS_THEME + 6, 'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'image_crop':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jcrop/js/jquery.color.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jcrop/js/jquery.Jcrop.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/form-image-crop.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'multiple_file_upload':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fancybox/source/jquery.fancybox.pack.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/vendor/jquery.ui.widget.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/vendor/tmpl.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/vendor/load-image.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/vendor/canvas-to-blob.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/blueimp-gallery/jquery.blueimp-gallery.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.iframe-transport.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-process.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-image.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-audio.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-video.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-validate.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-ui.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
////@ToDo make it work for IE
////            $jquery_transport = array(
////                '#tag' => 'script',
////                '#attributes' => array( // Set up an array of attributes inside the tag
////                    'src' => drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/cors/jquery.xdr-transport.js',
////                ),
////                '#prefix' => '<!--[if (gte IE 8)&(lt IE 10)]>',
////                '#value' => '',
////                '#suffix' => '<![endif]-->',
////            );
////            drupal_add_html_head($jquery_transport, 'jquery_transport');
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/form-fileupload.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'dropzone_file_upload':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/dropzone/dropzone.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/form-dropzone.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'managed_datatables':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/table-managed.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'editable_datatables':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/table-editable.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'advanced_datatables':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/extensions/TableTools/js/dataTables.tableTools.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/extensions/ColReorder/js/dataTables.colReorder.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/extensions/Scroller/js/dataTables.scroller.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/table-advanced.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'ajax_datatables':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/media/js/jquery.dataTables.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/datatables/plugins/bootstrap/dataTables.bootstrap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-datepicker/js/bootstrap-datepicker.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/scripts/datatable.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/table-ajax.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'ajax_portlets':
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-toastr/toastr.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            break;
//        case 'google_maps':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-notific8/jquery.notific8.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> 'http://maps.google.com/maps/api/js?sensor=false', 'options' => array('scope'=>'footer', 'type' => 'external'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/gmaps/gmaps.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/maps-google.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'draggable_portlets':
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/portlet-draggable.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'vector_maps':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/jquery.vmap.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.russia.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.world.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.europe.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.germany.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/maps/jquery.vmap.usa.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jqvmap/jqvmap/data/jquery.vmap.sampledata.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/maps-vector.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'visual_charts':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.resize.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.pie.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.stack.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.crosshair.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/flot/jquery.flot.categories.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/charts.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'portfolio':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-mixitup/jquery.mixitup.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fancybox/source/jquery.fancybox.pack.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/portfolio.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'calendar':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fullcalendar/fullcalendar/fullcalendar.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/calendar.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'contact_us':
//            $js_list[] = array('path'=> 'http://maps.google.com/maps/api/js?sensor=true', 'options' => array('scope'=>'footer', 'type' => 'external'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/gmaps/gmaps.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/contact-us.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'login':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-validation/js/jquery.validate.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/backstretch/jquery.backstretch.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/select2/select2.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/login-soft.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'user':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-fileinput/bootstrap-fileinput.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            break;
//        case 'lock_screen':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/backstretch/jquery.backstretch.min.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/lock.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        case 'inbox':
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/fancybox/source/jquery.fancybox.pack.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/wysihtml5-0.3.0.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/bootstrap-wysihtml5/bootstrap-wysihtml5.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/vendor/jquery.ui.widget.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/vendor/tmpl.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/vendor/load-image.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/vendor/canvas-to-blob.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/blueimp-gallery/jquery.blueimp-gallery.min.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.iframe-transport.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-process.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-audio.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-video.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-validate.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//            $js_list[] = array('path'=> $path_to_theme . '/assets/global/plugins/jquery-file-upload/js/jquery.fileupload-ui.js', 'options' => array('scope'=>'footer', 'type' => 'file'));
//
//            //@ToDo: make it work for IE
////            $jquery_transport = array(
////                '#tag' => 'script',
////                '#attributes' => array( // Set up an array of attributes inside the tag
////                    'src' => drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-file-upload/js/cors/jquery.xdr-transport.js',
////                ),
////                '#prefix' => '<!--[if (gte IE 8)&(lt IE 10)]>',
////                '#value' => '',
////                '#suffix' => '<![endif]-->',
////            );
////            drupal_add_html_head($jquery_transport, 'jquery_transport');
//
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            $js_list[] = array('path'=> $path_to_theme . '/assets/admin/pages/scripts/inbox.js', 'options' => array('weight' =>JS_THEME + 6,'scope'=>'footer', 'type' => 'file'));
//            break;
//        default:
//            //BEGIN PAGE LEVEL SCRIPTS
//            $js_list = array_merge($js_list, _shared_page_js_list());
//            break;
//    }
//
//    return $js_list;
//}

function _shared_page_js()
{
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/scripts/metronic.js', array('weight' => JS_THEME + 1, 'scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/layout/scripts/layout.js', array('weight' => JS_THEME + 2, 'scope' => 'footer', 'type' => 'file'));
    drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/assets/admin/layout/scripts/quick-sidebar.js', array('weight' => JS_THEME + 3, 'scope' => 'footer', 'type' => 'file'));
}

//function _shared_page_js_list(){
//    $js_scripts = array();
//    $path_to_theme = drupal_get_path('theme', $GLOBALS['theme']);
//    //production
//    $js_scripts[] = array('path'=> $path_to_theme . '/assets/global/scripts/metronic.js', 'options' => array('scope'=>'footer', 'weight' =>JS_THEME + 1,'type' => 'file'));
//    $js_scripts[] = array('path'=> $path_to_theme . '/assets/admin/layout/scripts/layout.js', 'options' => array('scope'=>'footer', 'weight' =>JS_THEME + 2,'type' => 'file'));
//    $js_scripts[] = array('path'=> $path_to_theme . '/assets/admin/layout/scripts/quick-sidebar.js', 'options' => array('scope'=>'footer', 'weight' =>JS_THEME + 3,'type' => 'file'));
//    return $js_scripts;
//}

function _init_js($type)
{
    $js_to_add = '';
    $js_to_add = 'jQuery(document).ready(function() {' . "\n";
    $js_to_add .= 'Metronic.init(); // init metronic core componets' . "\n";
    $js_to_add .= 'Layout.init(); // init layout' . "\n";
    $js_to_add .= 'QuickSidebar.init(); // init quick sidebar' . "\n";

    switch ($type) {
        case 'dashboard':
            $js_to_add .= 'Index.init();' . "\n";
            $js_to_add .= 'Index.initDashboardDaterange();' . "\n";
            $js_to_add .= 'Index.initJQVMAP(); // init index page\'s custom scripts' . "\n";
            $js_to_add .= 'Index.initCalendar(); // init index page\'s custom scripts' . "\n";
            $js_to_add .= 'Index.initCharts(); // init index page\'s custom scripts' . "\n";
            $js_to_add .= 'Index.initChat();' . "\n";
            $js_to_add .= 'Index.initMiniCharts();' . "\n";
            $js_to_add .= 'Index.initIntro();' . "\n";
            $js_to_add .= 'Tasks.initDashboardWidget();' . "\n";
            break;
        case 'ecommerce_dashboard':
            $js_to_add .= 'EcommerceIndex.init();' . "\n";
            break;
        case 'orders':
            $js_to_add .= 'EcommerceOrders.init();' . "\n";
            break;
        case 'order_view':
            $js_to_add .= 'EcommerceOrdersView.init();' . "\n";
            break;
        case 'products':
            $js_to_add .= 'EcommerceProducts.init();' . "\n";
            break;
        case 'product_edit':
            $js_to_add .= 'EcommerceProductsEdit.init();' . "\n";
            break;
        case 'ui_general':
            $js_to_add .= 'UIGeneral.init();' . "\n";
            break;
        case 'ui_tree':
            $js_to_add .= 'UITree.init();' . "\n";
            break;
        case 'notifica8_notifications':
            $js_to_add .= 'UINotific8.init();' . "\n";
            break;
        case 'toastr_notifications':
            $js_to_add .= 'UIToastr.init();' . "\n";
            break;
        case 'alerts_dialogs':
            $js_to_add .= 'UIAlertDialogApi.init();' . "\n";
            break;
        case 'extended_modals':
            $js_to_add .= 'UIExtendedModals.init();' . "\n";
            break;
        case 'date_paginator':
            $js_to_add .= 'UIDatepaginator.init();' . "\n";
            break;
        case 'nestable_list':
            $js_to_add .= 'UINestable.init();' . "\n";
            break;
        case 'pickers':
            $js_to_add .= 'ComponentsPickers.init();' . "\n";
            break;
        case 'custom_dropdowns':
            $js_to_add .= 'ComponentsDropdowns.init();' . "\n";
            break;
        case 'form_tools':
            $js_to_add .= 'ComponentsFormTools.init();' . "\n";
            break;
        case 'editors':
            $js_to_add .= 'ComponentsEditors.init();' . "\n";
            break;
        case 'ion_range_sliders':
            $js_to_add .= 'ComponentsIonSliders.init();' . "\n";
            break;
        case 'noui_range_sliders':
            $js_to_add .= 'ComponentsNoUiSliders.init();' . "\n";
            break;
        case 'jquery_ui_sliders':
            $js_to_add .= 'ComponentsjQueryUISliders.init();' . "\n";
            break;
        case 'knob_circle_dials':
            $js_to_add .= 'ComponentsKnobDials.init();' . "\n";
            break;
        case 'form_layouts':
            $js_to_add .= 'FormSamples.init();' . "\n";
            break;
        case 'form_x_editable':
            $js_to_add .= 'FormEditable.init();' . "\n";
            break;
        case 'form_wizard':
            $js_to_add .= 'FormWizard.init();' . "\n";
            break;
        case 'form_validation':
            $js_to_add .= 'FormValidation.init();' . "\n";
            break;
        case 'image_crop':
            $js_to_add .= 'FormImageCrop.init();' . "\n";
            break;
        case 'multiple_file_upload':
            $js_to_add .= 'FormFileUpload.init();' . "\n";
            break;
        case 'dropzone_file_upload':
            $js_to_add .= 'FormDropzone.init();' . "\n";
            break;
        case 'managed_datatables':
            $js_to_add .= 'TableManaged.init();' . "\n";
            break;
        case 'editable_datatables':
            $js_to_add .= 'TableEditable.init();' . "\n";
            break;
        case 'advanced_datatables':
            $js_to_add .= 'TableAdvanced.init();' . "\n";
            break;
        case 'ajax_datatables':
            $js_to_add .= 'TableAjax.init();' . "\n";
            break;
        case 'ajax_portlets':
            $js_to_add .= '//custom portlet reload handler' . "\n";
            $js_to_add .= "$('#my_portlet .portlet-title a.reload').click(function(e){" . "\n";
            $js_to_add .= '    e.preventDefault();  // prevent default event' . "\n";
            $js_to_add .= '    e.stopPropagation(); // stop event handling here(cancel the default reload handler)' . "\n";
            $js_to_add .= '    // do here some custom work:' . "\n";
            $js_to_add .= '    Metronic.alert({' . "\n";
            $js_to_add .= "    'type': 'danger', " . "\n";
            $js_to_add .= "    'icon': 'warning'," . "\n";
            $js_to_add .= "    'message': 'Custom reload handler!'," . "\n";
            $js_to_add .= "    'container': $('#my_portlet .portlet-body') " . "\n";
            $js_to_add .= "  });" . "\n";
            $js_to_add .= '})' . "\n";
            break;
        case 'draggable_portlets':
            $js_to_add .= 'PortletDraggable.init(); // init quick sidebar' . "\n";
            break;
        case 'google_maps':
            $js_to_add .= 'MapsGoogle.init(); // init quick sidebar' . "\n";
            break;
        case 'vector_maps':
            $js_to_add .= 'MapsVector.init(); // init quick sidebar' . "\n";
            break;
        case 'visual_charts':
            $js_to_add .= 'Charts.init();' . "\n";
            $js_to_add .= 'Charts.initCharts();' . "\n";
            $js_to_add .= 'Charts.initPieCharts();' . "\n";
            $js_to_add .= 'Charts.initBarCharts();' . "\n";
            break;
        case 'portfolio':
            $js_to_add .= 'Portfolio.init();' . "\n";
            break;
        case 'calendar':
            $js_to_add .= 'Calendar.init();' . "\n";
            break;
        case 'contact_us':
            $js_to_add .= 'ContactUs.init();' . "\n";
            break;
        case 'login':
            $js_to_add .= 'Login.init();' . "\n";
            $js_to_add .= '// init background slide images' . "\n";
            $js_to_add .= '$.backstretch([' . "\n";
            $js_to_add .= ' BASE_URL + "sites/default/files/designssquare_com_theme_metronic/assets/admin/pages/media/bg/1.jpg",' . "\n";
            $js_to_add .= ' BASE_URL + "sites/default/files/designssquare_com_theme_metronic/assets/admin/pages/media/bg/2.jpg",' . "\n";
            $js_to_add .= ' BASE_URL + "sites/default/files/designssquare_com_theme_metronic/assets/admin/pages/media/bg/3.jpg",' . "\n";
            $js_to_add .= ' BASE_URL + "sites/default/files/designssquare_com_theme_metronic/assets/admin/pages/media/bg/4.jpg"' . "\n";
            $js_to_add .= '], {' . "\n";
            $js_to_add .= '      fade: 1000,' . "\n";
            $js_to_add .= '      duration: 8000' . "\n";
            $js_to_add .= '	}' . "\n";
            $js_to_add .= ');' . "\n";
            break;
        case 'lock_screen':
            $js_to_add .= 'Lock.init();' . "\n";
            break;
        case 'inbox':
            $js_to_add .= 'Inbox.init();' . "\n";
            break;
    }
    $js_to_add .= '});';
    drupal_add_js($js_to_add, array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));

    if ($type == 'form_tools') {
        $js_to_add = 'var RecaptchaOptions = {' . "\n";
        $js_to_add .= "theme : 'custom'," . "\n";
        $js_to_add .= "custom_theme_widget: 'recaptcha_widget'" . "\n";
        $js_to_add .= "};" . "\n";
        drupal_add_js($js_to_add, array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));
    }

    if ($type == 'ui_general') {
        $js_to_add = "$('.demo-loading-btn')" . "\n";
        $js_to_add .= '    .click(function () {' . "\n";
        $js_to_add .= '        var btn = $(this)' . "\n";
        $js_to_add .= "btn.button('loading')" . "\n";
        $js_to_add .= 'setTimeout(function () {' . "\n";
        $js_to_add .= "btn.button('reset')" . "\n";
        $js_to_add .= "}, 3000)" . "\n";
        $js_to_add .= '});' . "\n";
        drupal_add_js($js_to_add, array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));
    }
}

//function _init_js_list($type)
//{
////    $js_to_add = "jQuery(document).ready(function() {" . "\n";
//    $js_to_add = "Metronic.init();" . "\n";
//    $js_to_add .= "Layout.init();" . "\n";
//    $js_to_add .= "QuickSidebar.init();" . "\n";
//
//    switch ($type) {
//        case 'none':
//        case 'dashboard':
//            $js_to_add .= 'Index.init();' . "\n";
//            $js_to_add .= 'Index.initDashboardDaterange();' . "\n";
//            $js_to_add .= 'Index.initJQVMAP();' . "\n";
//            $js_to_add .= 'Index.initCalendar();' . "\n";
//            $js_to_add .= 'Index.initCharts();' . "\n";
//            $js_to_add .= 'Index.initChat();' . "\n";
//            $js_to_add .= 'Index.initMiniCharts();' . "\n";
//            $js_to_add .= 'Index.initIntro();' . "\n";
//            $js_to_add .= 'Tasks.initDashboardWidget();' . "\n";
//            break;
//        case 'ecommerce_dashboard':
//            $js_to_add .= 'EcommerceIndex.init();' . "\n";
//            break;
//        case 'orders':
//            $js_to_add .= 'EcommerceOrders.init();' . "\n";
//            break;
//        case 'order_view':
//            $js_to_add .= 'EcommerceOrdersView.init();' . "\n";
//            break;
//        case 'products':
//            $js_to_add .= 'EcommerceProducts.init();' . "\n";
//            break;
//        case 'product_edit':
//            $js_to_add .= 'EcommerceProductsEdit.init();' . "\n";
//            break;
//        case 'ui_general':
//            $js_to_add .= 'UIGeneral.init();' . "\n";
//            break;
//        case 'ui_tree':
//            $js_to_add .= 'UITree.init();' . "\n";
//            break;
//        case 'notifica8_notifications':
//            $js_to_add .= 'UINotific8.init();' . "\n";
//            break;
//        case 'toastr_notifications':
//            $js_to_add .= 'UIToastr.init();' . "\n";
//            break;
//        case 'alerts_dialogs':
//            $js_to_add .= 'UIAlertDialogApi.init();' . "\n";
//            break;
//        case 'extended_modals':
//            $js_to_add .= 'UIExtendedModals.init();' . "\n";
//            break;
//        case 'date_paginator':
//            $js_to_add .= 'UIDatepaginator.init();' . "\n";
//            break;
//        case 'nestable_list':
//            $js_to_add .= 'UINestable.init();' . "\n";
//            break;
//        case 'pickers':
//            $js_to_add .= 'ComponentsPickers.init();' . "\n";
//            break;
//        case 'custom_dropdowns':
//            $js_to_add .= 'ComponentsDropdowns.init();' . "\n";
//            break;
//        case 'form_tools':
//            $js_to_add .= 'ComponentsFormTools.init();' . "\n";
//            break;
//        case 'editors':
//            $js_to_add .= 'ComponentsEditors.init();' . "\n";
//            break;
//        case 'ion_range_sliders':
//            $js_to_add .= 'ComponentsIonSliders.init();' . "\n";
//            break;
//        case 'noui_range_sliders':
//            $js_to_add .= 'ComponentsNoUiSliders.init();' . "\n";
//            break;
//        case 'jquery_ui_sliders':
//            $js_to_add .= 'ComponentsjQueryUISliders.init();' . "\n";
//            break;
//        case 'knob_circle_dials':
//            $js_to_add .= 'ComponentsKnobDials.init();' . "\n";
//            break;
//        case 'form_layouts':
//            $js_to_add .= 'FormSamples.init();' . "\n";
//            break;
//        case 'form_x_editable':
//            $js_to_add .= 'FormEditable.init();' . "\n";
//            break;
//        case 'form_wizard':
//            $js_to_add .= 'FormWizard.init();' . "\n";
//            break;
//        case 'form_validation':
//            $js_to_add .= 'FormValidation.init();' . "\n";
//            break;
//        case 'image_crop':
//            $js_to_add .= 'FormImageCrop.init();' . "\n";
//            break;
//        case 'multiple_file_upload':
//            $js_to_add .= 'FormFileUpload.init();' . "\n";
//            break;
//        case 'dropzone_file_upload':
//            $js_to_add .= 'FormDropzone.init();' . "\n";
//            break;
//        case 'managed_datatables':
//            $js_to_add .= 'TableManaged.init();' . "\n";
//            break;
//        case 'editable_datatables':
//            $js_to_add .= 'TableEditable.init();' . "\n";
//            break;
//        case 'advanced_datatables':
//            $js_to_add .= 'TableAdvanced.init();' . "\n";
//            break;
//        case 'ajax_datatables':
//            $js_to_add .= 'TableAjax.init();' . "\n";
//            break;
//        case 'ajax_portlets':
//            $js_to_add .= '//custom portlet reload handler' . "\n";
//            $js_to_add .= "$('#my_portlet .portlet-title a.reload').click(function(e){" . "\n";
//            $js_to_add .= '    e.preventDefault();' . "\n";
//            $js_to_add .= '    e.stopPropagation();' . "\n";
//            $js_to_add .= '    Metronic.alert({' . "\n";
//            $js_to_add .= "    'type': 'danger', " . "\n";
//            $js_to_add .= "    'icon': 'warning'," . "\n";
//            $js_to_add .= "    'message': 'Custom reload handler!'," . "\n";
//            $js_to_add .= "    'container': $('#my_portlet .portlet-body') " . "\n";
//            $js_to_add .= "  });" . "\n";
//            $js_to_add .= '})' . "\n";
//            break;
//        case 'draggable_portlets':
//            $js_to_add .= 'PortletDraggable.init(); // init quick sidebar' . "\n";
//            break;
//        case 'google_maps':
//            $js_to_add .= 'MapsGoogle.init(); // init quick sidebar' . "\n";
//            break;
//        case 'vector_maps':
//            $js_to_add .= 'MapsVector.init(); // init quick sidebar' . "\n";
//            break;
//        case 'visual_charts':
//            $js_to_add .= 'Charts.init();' . "\n";
//            $js_to_add .= 'Charts.initCharts();' . "\n";
//            $js_to_add .= 'Charts.initPieCharts();' . "\n";
//            $js_to_add .= 'Charts.initBarCharts();' . "\n";
//            break;
//        case 'portfolio':
//            $js_to_add .= 'Portfolio.init();' . "\n";
//            break;
//        case 'calendar':
//            $js_to_add .= 'Calendar.init();' . "\n";
//            break;
//        case 'contact_us':
//            $js_to_add .= 'ContactUs.init();' . "\n";
//            break;
//        case 'login':
//            $theme_path = drupal_get_path('theme','metronic');
//            $js_to_add .= 'Login.init();' . "\n";
//            $js_to_add .= '$.backstretch([' . "\n";
//            $js_to_add .= '   "'.$theme_path.'/assets/admin/pages/media/bg/1.jpg",' . "\n";
//            $js_to_add .= '    "'.$theme_path.'/assets/admin/pages/media/bg/2.jpg",' . "\n";
//            $js_to_add .= '    "'.$theme_path.'/assets/admin/pages/media/bg/3.jpg",' . "\n";
//            $js_to_add .= '    "'.$theme_path.'/assets/admin/pages/media/bg/4.jpg"' . "\n";
//            $js_to_add .= '], {' . "\n";
//            $js_to_add .= '      fade: 1000,' . "\n";
//            $js_to_add .= '      duration: 8000' . "\n";
//            $js_to_add .= '	}' . "\n";
//            $js_to_add .= ');' . "\n";
//            break;
//        case 'lock_screen':
//            $js_to_add .= 'Lock.init();' . "\n";
//            break;
//        case 'inbox':
//            $js_to_add .= 'Inbox.init();' . "\n";
//            break;
//    }
////    $js_to_add .= "});";
////    drupal_add_js($js_to_add, array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));
//    $init_js = array();
//    $init_js[] = array(
//        'path' => $js_to_add,
//        'options' => array(
//            'scope'=>'footer',
//            'weight' =>1000,
//            'type' => 'inline'
//        ),
//    );
//    if($type == 'form_tools'){
//        $js_to_add = 'var RecaptchaOptions = {' . "\n";
//        $js_to_add .= "theme : 'custom'," . "\n";
//        $js_to_add .= "custom_theme_widget: 'recaptcha_widget'" . "\n";
//        $js_to_add .= "};" . "\n";
//        $init_js[] = array(
//            'path' => $js_to_add,
//            'options' => array(
//                'scope'=>'footer',
//                'weight' =>1001,
//                'type' => 'inline'
//            ),
//        );
////        drupal_add_js($js_to_add, array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));
//    }
//
//    if($type == 'ui_general'){
//        $js_to_add = "$('.demo-loading-btn')" . "\n";
//        $js_to_add .= '    .click(function () {' . "\n";
//        $js_to_add .= '        var btn = $(this)' . "\n";
//        $js_to_add .= "btn.button('loading')" . "\n";
//        $js_to_add .= 'setTimeout(function () {' . "\n";
//        $js_to_add .= "btn.button('reset')" . "\n";
//        $js_to_add .= "}, 3000)" . "\n";
//        $js_to_add .= '});' . "\n";
//        $init_js[] = array(
//            'path' => $js_to_add,
//            'options' => array(
//                'scope'=>'footer',
//                'weight' =>1002,
//                'type' => 'inline'
//            ),
//        );
////        drupal_add_js($js_to_add, array('scope' => 'footer', 'type' => 'inline', 'weight' => 1000));
//    }
//
//    return $init_js;
//}

function metronic_js_alter(&$javascript)
{
    //use theme specific bootstrap
    unset($javascript[drupal_get_path('theme', 'bootstrap') . '/js/bootstrap.js']);

    //metronic theme has higher vers than jquery_update provides, so we replace
//    replace_jquery($javascript, drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-1.11.1.js', '1.11.1');
    replace_jquery($javascript, base_path().drupal_get_path('theme', $GLOBALS['theme']) . '/assets/global/plugins/jquery-1.11.0.min.js', '1.11.0');
}


function metronic_preprocess_block(&$variables)
{
    switch ($variables['block']->region) {
        default:
            $variables['theme_hook_suggestions'][] = 'block__no_wrap';
            break;
    }
}

function metronic_preprocess_region(&$variables)
{
    switch ($variables['region']) {
        case 'sidebar_first':
        case 'sidebar_second':
            break;
        default:
            $variables['theme_hook_suggestions'][] = 'region__no_wrap';
            break;
    }
}

//overriding theme_boxes_box to remove DIV wrappers
function metronic_boxes_box($variables)
{
    $block = $variables['block'];

    $empty = '';

    // Box is empty
    if ((empty($block['title']) || ($block['title'] == '<none>')) && empty($block['content'])) {

        // add a class to mark the box as empty
        $empty = ' box-empty';

        // show something if the block is empty but the user has the permission to edit it
        if (boxes_access_edit()) {
            $block['content'] = t('This box appears empty when displayed on this page. This is simply placeholder text.');
        } else {
            return;
        }
    }

    $output = $block['content'];
//    $output = "<div id='boxes-box-" . $block['delta'] . "' class='boxes-box" . (!empty($block['editing']) ? ' boxes-box-editing' : '') . $empty . "'>";
//    $output .= '<div class="boxes-box-content">' . $block['content'] . '</div>';
//    if (!empty($block['controls'])) {
//        $output .= '<div class="boxes-box-controls">';
//        $output .= $block['controls'];
//        $output .= '</div>';
//    }
//    if (!empty($block['editing'])) {
//        $output .= '<div class="box-editor">' . drupal_render($block['editing']) . '</div>';
//    }
    return $output;
}


/****Template API Hooks***/
//alter main menu link to hide text on minimized menu action
function metronic_menu_link_tapi_alter(&$link_tapi, $depth, $menu_name)
{
    if (($menu_name == 'main-menu') && $depth == 1) {
        $title = $link_tapi['title'];
        if ($begin = strpos($title, '</i>')) {
            $clean_title = substr($title, $begin + 4);
        } else {
            $clean_title = $link_tapi['title'];
        }
        $final_title = '<span class="title">' . $clean_title . '</span>';
        $link_tapi['title'] = ($begin) ? substr($link_tapi['title'], 0, $begin + 4) . $final_title : $final_title;
    }
}

//remove icons from the breadcrumbs except the home
function metronic_breadcrumb_tapi_alter(&$bredcrumb_tapi)
{
    foreach ($bredcrumb_tapi as $key => $breadcrumb) {
        $bredcrumb_tapi[$key]['label'] = strip_tags($breadcrumb['label']);
    }
}

//add styles per theme settings
function metronic_header_tapi_alter(&$header_tapi)
{
    $theme_settings_tapi = _theme_settings_tapi();

    if ($theme_settings_tapi['header']['value'] == 'fixed') {
        $header_tapi['class'] = 'navbar-fixed-top';
    } else {
        $header_tapi['class'] = '';
    }

    if ($theme_settings_tapi['layout']['value'] == 'boxed') {
        $header_tapi['layout'] = 'container';
    } else {
        $header_tapi['layout'] = '';
    }

    //ensure quick sidebar icon doesn't show when block is not active
    $header_tapi['show_sidebar'] = false;
    $quick_sidebar_blocks = get_blocks_from_region('quick_sidebar');
    $quick_indexes = array_keys($quick_sidebar_blocks);
    if(!empty($quick_sidebar_blocks) && in_array('boxes_quick_sidebar_box',$quick_indexes)){
        $header_tapi['show_sidebar'] = true;
    }
}

//function metronic_radio($variables) {
//    $element = $variables['element'];
//    $element['#attributes']['type'] = 'radio';
////    element_set_attributes($element, array('id', 'name', '#return_value' => 'value'));
////
////    if (isset($element['#return_value']) && $element['#value'] !== FALSE && $element['#value'] == $element['#return_value']) {
////        $element['#attributes']['checked'] = 'checked';
////    }
////    _form_set_class($element, array('form-radio'));
//
////    return '<input' . drupal_attributes($element['#attributes']) . ' />';
//    return '<input type="radio" class="form-radio" />';
//}

/**
 * Returns HTML for a set of radio button form elements.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #value, #options, #description, #required,
 *     #attributes, #children.
 *
 * @ingroup themeable
 */
//function metronic_radios($variables) {
//    $element = $variables['element'];
////    $attributes = array();
////    if (isset($element['#id'])) {
////        $attributes['id'] = $element['#id'];
////    }
////    $attributes['class'] = 'form-radios';
////    if (!empty($element['#attributes']['class'])) {
////        $attributes['class'] .= ' ' . implode(' ', $element['#attributes']['class']);
////    }
////    if (isset($element['#attributes']['title'])) {
////        $attributes['title'] = $element['#attributes']['title'];
////    }
////    return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
//    return (!empty($element['#children']) ? $element['#children'] : '');
//}


