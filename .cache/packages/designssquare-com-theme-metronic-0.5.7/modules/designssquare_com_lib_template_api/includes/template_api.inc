<?php

function _breadcrumb_tapi($node = null)
{
    $breadcrumb_tapi = ds_menu_get_active_breadcrumb();
    if (empty($breadcrumb_tapi)) {
        $breadcrumb_tapi[0] = _breadcrumb_link(); //set home page
    }

    // Optionally get rid of the homepage link.
    $show_breadcrumb_home = theme_get_setting('bootstrap_breadcrumb_home');
    if (!$show_breadcrumb_home) {
        array_shift($breadcrumb_tapi);
    }

    $breadcrumb_tapi[0]['first'] = true;
    $breadcrumb_tapi[0]['last'] = false;

    //set last breadcrumb
    if (theme_get_setting('bootstrap_breadcrumb_title') && !empty($breadcrumb_tapi)) {
        $item = menu_get_item();
        $breadcrumb_tapi[] = array(
            // If we are on a non-default tab, use the tab's title.
            'label' => !empty($item['tab_parent']) ? check_plain($item['title']) : drupal_get_title(),
            'url' => (isset($item['href'])) ? '/' . $item['href'] : $item['path'],
            'last' => true,
            'first' => false,
        );

        //fix search string
        if ($item['original_map'][0] == 'search') {
            $breadcrumb_tapi[count($breadcrumb_tapi) - 1]['label'] = end($item['page_arguments']);
        }
    }

    drupal_alter('breadcrumb_tapi', $breadcrumb_tapi);
    return $breadcrumb_tapi;
}

function _breadcrumb_link()
{
    $breadcrumb_tapi = array();
    $breadcrumb_tapi['url'] = '#';
    $breadcrumb_tapi['label'] = '';
    $breadcrumb_tapi['first'] = false;
    $breadcrumb_tapi['last'] = false;
    if (isset($node) && is_array($node)) {
        $breadcrumb_tapi['url'] = (isset($node->nid)) ? drupal_get_path_alias('node/' . $node->nid) : $node['nid'];
        $breadcrumb_tapi['label'] = (isset($node->title)) ? $node->title : $node['title'];
    } elseif (isset($node)) {
        $breadcrumb_tapi['label'] = $node;
    } else {
        $breadcrumb_tapi['url'] = '/';
        $breadcrumb_tapi['label'] = t('Home');
    }
    return $breadcrumb_tapi;
}

/*******Theme Custom Settings******/
function _theme_settings_tapi()
{
    $theme_tapi = array();

    //scheme-color
    $theme_tapi['color'] = array();
    $theme_tapi['color']['index'] = 'ds_theme_color';
    $theme_tapi['color']['value'] = variable_get('ds_theme_color', theme_get_setting('ds_theme_color'));

    //layout - boxed, wide, semi-wide
    $theme_tapi['layout'] = array();
    $theme_tapi['layout']['index'] = 'ds_theme_layout';
    $theme_tapi['layout']['value'] = variable_get('ds_theme_layout', theme_get_setting('ds_theme_layout'));

    //background image - image full name
    $theme_tapi['bg-img'] = array();
    $theme_tapi['bg-img'] = 'ds_theme_gb_img';
    $theme_tapi['bg-img'] = variable_get('ds_theme_gb_img', theme_get_setting('ds_theme_gb_img'));

    //background color - image full name
    $theme_tapi['bg-color'] = array();
    $theme_tapi['bg-color']['index'] = 'ds_theme_bg_color';
    $theme_tapi['bg-color']['value'] = variable_get('ds_theme_bg_color', theme_get_setting('ds_theme_bg_color'));

    //header
    $theme_tapi['header'] = array();
    $theme_tapi['header']['index'] = 'ds_theme_header';
    $theme_tapi['header']['value'] = variable_get('ds_theme_header', theme_get_setting('ds_theme_header'));

    //sidebar
    $theme_tapi['sidebar'] = array();
    $theme_tapi['sidebar']['index'] = 'ds_theme_sidebar';
    $theme_tapi['sidebar']['value'] = variable_get('ds_theme_sidebar', theme_get_setting('ds_theme_sidebar'));


    $theme_tapi['sidebar_position'] = array();
    $theme_tapi['sidebar_position']['index'] = 'ds_theme_sidebar_pos';
    $theme_tapi['sidebar_position']['value'] = variable_get('ds_theme_sidebar_pos', theme_get_setting('ds_theme_sidebar_pos'));

    //footer
    $theme_tapi['footer'] = array();
    $theme_tapi['footer']['index'] = 'ds_theme_footer';
    $theme_tapi['footer']['value'] = variable_get('ds_theme_footer', theme_get_setting('ds_theme_footer'));

    drupal_alter('theme_tapi', $theme_tapi);
    return $theme_tapi;
}

//prepare user related variables for the html.tpl file
//function _header_tapi_user()
//{
//    global $conf;
//    global $user;
//    $name = (!empty($conf['anonymous'])) ? $conf['anonymous'] : 'Hello Mate';
//    $profile_img_url = base_path() . path_to_theme() . '/images/author.png';
//
//    if ($user->uid) {
//        //authenticated user
//        $url = 'user/logout';
//        $content = 'Logout';
//        $profile_url = 'user';
//        $profile_content = $user->name;
//        $authenticated = True;
//    } else {
//        $url = 'user';
//        $content = 'Login';
//        $authenticated = False;
//        $profile_url = '';
//        $profile_content = '';
//    }
//
//    return array(
//        'name' => $name,
//        'avatar' => $profile_img_url,
//        'login' => array(
//            'url' => $url,
//            'text' => $content,
//        ),
//        'profile' => array(
//            'url' => $profile_url,
//            'text' => $profile_content,
//        ),
//        'is_authenticated' => $authenticated,
//    );
//}

//prepare site related variables for the html.tpl file
//function _basic_tapi($node){
//    return array(
//        'slogan' => (!empty($node->field_slogan)) ? $node->field_slogan[LANGUAGE_NONE][0]['value'] : '',
//        'title' => (!empty($node->title)) ? $node->title : '',
//    );
//}
//function _basic_tapi($node)
//{
//    $field = field_get_items('node', $node, 'field_page_slogan');
//    $slogan = field_view_value('node', $node, 'field_page_slogan', $field[0]);
//
//    return array(
//        'title' => !empty($node->title) ? $node->title : '',
//        'body' => !empty($node->body) ? $node->body : '',
//        'slogan' => !empty($slogan) ? render($slogan) : '',
//    );
//}

function _simple_tapi($vars)
{
    return array(
        'title' => !empty($vars['title']) ? $vars['title'] : drupal_get_title(),
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
        $page_tapi['title'] = (!empty($custom_title)) ? $custom_title : (isset($node->title)) ? $node->title : '';

        $info_instance = field_get_items('node', $node, 'field_page_information');
        $info_instance_val = (!empty($info_instance[0])) ? field_view_value('node', $node, 'field_page_information', $info_instance[0]) : '';
        $page_tapi['intro'] = htmlspecialchars_decode(render($info_instance_val));

        //*****backward compatable and should be using intro field instead the slogan
        $field = field_get_items('node', $node, 'field_page_slogan');
        $page_tapi['slogan'] = (!empty($field[0])) ? field_view_value('node', $node, 'field_page_slogan', $field[0]) : '';

    } else {
        $page_tapi = _simple_tapi($vars);
    }

    //for user login set title
    global $user;
    if (empty($page_tapi['title']) && preg_match('/user\/password/', $_GET['q']) && !$user->uid) {
        $page_tapi['title'] = t('Request New Password');
    }elseif(empty($page_tapi['title']) && preg_match('/user\/register/', $_GET['q']) && !$user->uid){
        $page_tapi['title'] = t('Create New Account');
    }elseif(empty($page_tapi['title']) && preg_match('/user/', $_GET['q']) && !$user->uid){
        $page_tapi['title'] = t('Log In');
    }elseif(empty($page_tapi['title']) && preg_match('/user/', $_GET['q']) && $user->uid){
        $page_tapi['title'] = t('User Account');
    }

    /******SEARCH******/
    if(arg(0) == 'search'){
        $page_tapi['title'] = t('Search Results');
    }

    drupal_alter('page_tapi', $page_tapi);
    return $page_tapi;

}

//prepare site related variables for the html.tpl file
function _header_tapi()
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

    /****USER****/
    $head_tapi['user'] = array();
    $head_tapi['user'] = _user_tapi();

    /*****Theme*****/

    $head_tapi['settings'] = array();
    $head_tapi['settings']['url'] = base_path() . 'admin/appearance/settings/' . $GLOBALS['theme'];
    $head_tapi['settings']['text'] = t(' Settings');

    /*********making backwards compatable**************/
    $head_tapi['slogan'] = $site_slogan;
    $head_tapi['site_name'] = $head_tapi['site']['name'];
    $head_tapi['home_url'] = $head_tapi['site']['front_url'];
    $head_tapi['logo_path'] = $head_tapi['logo']['path'];

    /*******conventions******/
    $main_menu_name = 'main-menu';
//    $main_menu_links = ds_build_menu($main_menu_name);
//    $head_tapi['main-menu'] = _menu_tapi($main_menu_links, 0, $main_menu_name);
    $head_tapi['main-menu'] = ds_build_menu($main_menu_name);

    $user_menu_name = 'user-menu';
//    $user_menu_links = ds_build_menu($user_menu_name);
//    $head_tapi['user-menu'] = _menu_tapi($user_menu_links, 0, $user_menu_name);
    $head_tapi['user-menu'] = ds_build_menu($user_menu_name);


    drupal_alter('header_tapi', $head_tapi);
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

    drupal_alter('search_tapi', $form);
    return $form;
}

//@ToDo implement category support
function _contact_tapi($category = 'contact')
{
    global $user;
    $contact_tapi = array();
    require_once drupal_get_path('module', 'contact') . '/contact.pages.inc';
    $contact_form_array = drupal_get_form('contact_site_form');
    //form specific
    $contact_tapi['id'] = str_replace('_', '-', $contact_form_array['#form_id']);
    $contact_tapi['action'] = $contact_form_array['#action'];

    //name input field
    $contact_tapi['name_name'] = $contact_form_array['name']['#name'];
    $contact_tapi['name_label'] = t('Your Name:');
    $contact_tapi['name_type'] = 'text';
    if(isset($user->name)){
        $name_value = $user->name;
    }else{
        $ext_name_value = theme_get_setting('ds_contact_anonymous_name');
        $name_value = (isset($ext_name_value)) ? $ext_name_value : t('Your  Name');
    }
    $contact_tapi['name_value'] = $name_value;
    //subject input field
    $contact_tapi['subject_name'] = $contact_form_array['subject']['#name'];
    $contact_tapi['subject_value'] = 'From ' . $_SERVER['HTTP_HOST'];
    $contact_tapi['subject_label'] = t('Subject:');
    $contact_tapi['subject_type'] = 'text';
    $contact_tapi['subject_value'] = ($subject_value = theme_get_setting('ds_contact_subject_value')) ? $subject_value : t('Inquiring');

    //email input field
    $contact_tapi['email_name'] = $contact_form_array['mail']['#name'];
    $contact_tapi['email_label'] = t('Your Email:');
    $contact_tapi['email_type'] = 'email';
    if(isset($user->mail)){
        $email_value = $user->mail;
    }else{
        $ext_email_value = theme_get_setting('ds_contact_anonymous_email');
        $email_value = (isset($ext_email_value)) ? $ext_email_value : t('fan@DesignsSquare.com');
    }
    $contact_tapi['email_value'] = $email_value;

    //message input field
    $contact_tapi['message_name'] = $contact_form_array['message']['#name'];
    $contact_tapi['message_label'] = t('Your Message');
    $contact_tapi['message_value'] = ($message_value = theme_get_setting('ds_contact_message_value')) ? $message_value : t('Your Message');


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

    drupal_alter('contact_tapi', $contact_tapi);
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

    drupal_alter('comment_tapi', $comment_tapi);
    return $comment_tapi;
}

function _footer_tapi()
{
    return array();
}


function _menu_link_tapi($link, $depth, $sub_menu)
{
    $link_tapi = array();
    $link_tapi['title'] = $link['link_title'];
    $link_tapi['active'] = $link['in_active_trail'];
    $link_tapi['url'] = base_path() . drupal_get_path_alias($link['link_path']);
    $link_tapi['has_sub_menu'] = (isset($sub_menu) && !empty($sub_menu)) ? true : false;
    $link_tapi['sub_menu'] = (isset($sub_menu) && !empty($sub_menu)) ? $sub_menu : '';
    $link_tapi['depth'] = $depth;
    drupal_alter('menu_link_tapi', $link_tapi, $depth, $link['menu_name']);
    return $link_tapi;
}

function _menu_tapi($links, $depth, $menu_name = '')
{
    $menu_tapi = array();
    $menu_tapi['depth'] = $depth;
    $menu_tapi['links'] = $links;
    drupal_alter('menu_tapi', $menu_tapi, $menu_name);
    return $menu_tapi;
}

function _user_tapi()
{
    global $user;
    $name = ($user_anonymous_name = theme_get_setting('ds_user_anonymous_name')) ? $user_anonymous_name : 'Mate';

    $profile_img_url = ($profile_img_url_var = theme_get_setting('ds_profile_img_url')) ? $profile_img_url_var : base_path() . drupal_get_path('module', 'designssquare_lib_template_api') . '/assets/author.png';

    if ($user->uid) {
        //authenticated user
        $user_profile = user_load($user->uid);
        if (isset($user_profile->picture) && $user_profile->picture != "0") {
            //avatar photo is set
            $profile_img_url = image_style_url("medium", $user_profile->picture->uri);
        }
        $name = ' ' . $user->name;
        $login_link_path = base_path() . 'user/logout';
        $login_link_text = ($logout_menu_item = theme_get_setting('ds_logout_menu_item_text')) ? $logout_menu_item : t(' Logout');
        $profile_url = base_path() . 'user/' . $user->uid;
        $authenticated = True;
    } else {
        $login_link_path = base_path() . 'user';
        $login_link_text = ($login_menu_item = theme_get_setting('ds_login_menu_item_text')) ? $login_menu_item : t(' Login');
        $authenticated = False;
        $profile_url = $login_link_path;
    }

    $profile_link_text = ($profile_menu_item = theme_get_setting('ds_profile_menu_item_text')) ? $profile_menu_item : t(' My Profile');


    //profile style
    $profile_width = '259';
    $profile_height = '150';
    if ($profile_style = image_style_load('ds_user_profile')) {
        foreach ($profile_style['effects'] as $effect) {
            if ($effect['name'] == 'image_resize') {
                $profile_width = (isset($effect['data']['width'])) ? $effect['data']['width'] : '259';
                $profile_height = (isset($effect['data']['height'])) ? $effect['data']['height'] : '150';
            }
        }
    } else {
        //ds_user_profile images style is not present...read external configurations
        $profile_width = ($theme_profile_width = theme_get_setting('ds_user_profile_width')) ? $theme_profile_width : '259';
        $profile_height = ($theme_profile_height = theme_get_setting('ds_user_profile_height')) ? $theme_profile_height : '150';
    }


    //avatar style
    $avatar_width = '29';
    $avatar_height = '29';
//    $avatar_style = image_style_load('ds_avatar');
    if ($avatar_style = image_style_load('ds_avatar')) {
        foreach ($avatar_style['effects'] as $effect) {
            if ($effect['name'] == 'image_resize') {
                $avatar_width = (isset($effect['data']['width'])) ? $effect['data']['width'] : '29';
                $avatar_height = (isset($effect['data']['height'])) ? $effect['data']['height'] : '29';
            }
        }
    } else {
        //ds_avatar images style is not present...read external configurations
        $avatar_width = ($theme_avatar_width = theme_get_setting('ds_avatar_width')) ? $theme_avatar_width : '29';
        $avatar_height = ($theme_avatar_height = theme_get_setting('ds_avatar_height')) ? $theme_avatar_width : '29';
    }

    $email = (isset($user->mail)) ? $user->mail : (($default_user_email = theme_get_setting('ds_default_user_email')) ? $default_user_email : 'fan@designssquare.org');

    $user_tapi = array(
        'name' => $name,
        'avatar' => array(
            'url' => $profile_img_url,
            'width' => $avatar_width,
            'height' => $avatar_height,
        ),
        'email' => $email,
        'login-link' => array(
            'path' => $login_link_path,
            'text' => $login_link_text
        ),
        'link' => array(
            'path' => $profile_url,
            'text' => $profile_link_text,
        ),
        'img' => array(
            'url' => $profile_img_url,
            'width' => $profile_width,
            'height' => $profile_height
        ),
        'is_authenticated' => $authenticated,
    );

    drupal_alter('user_tapi', $user_tapi);
    return $user_tapi;
}

function _user_pass_tapi()
{
    $password = array();
    $pass_form_name = 'user-pass';
    $pass_form = drupal_get_form('user_pass');
    $password['form_action'] = $pass_form['#action'];
    $password['form_id'] = $pass_form_name;
    $password['email_name'] = 'name';
    $password['hidden_form_id'] = render($pass_form['form_id']);
    $password['hidden_build_id'] = render($pass_form['form_build_id']);

    //other actions
    $password['actions'] = _user_actions();

    drupal_alter('password_reset_tapi', $password);
    return $password;
}

function _user_registration_tapi()
{
    $registration = array();
    $register_form_name = 'user_register_form';
    $register_form = drupal_get_form($register_form_name);
    $registration['form_action'] = $register_form['#action'];
    $registration['form_id'] = 'user-register-form';
    $registration['user_name'] = 'name';
    $registration['email_name'] = 'mail';
    $registration['hidden_build_id'] = render($register_form['form_build_id']);
    $registration['hidden_form_id'] = render($register_form['form_id']);

    //other actions
    $registration['actions'] = _user_actions();

    drupal_alter('registration_tapi', $registration);
    return $registration;
}

function _user_login_tapi()
{
    $login = array();
    $login_form = drupal_get_form('user_login');
    $login['form_action'] = $login_form['#action'];
    $login['form_id'] = 'user-login';
    $login['user_name'] = 'name';
    $login['pass_name'] = 'pass';
    $login['hidden_form_id'] = render($login_form['form_id']);
    $login['hidden_build_id'] = render($login_form['form_build_id']);

    //other actions
    $login['actions'] = _user_actions();

    drupal_alter('login_tapi', $login);
    return $login;
}

function _status_message_tapi($clear = false){

    //initiate supported messages
    $status_message_tapi = array();
    $status_message_tapi['status'] = array();
    $status_message_tapi['status']['enabled'] = false;
    $status_message_tapi['status']['heading'] = ($ds_massage_status_heading = theme_get_setting('ds_message_status_heading')) ? $ds_massage_status_heading : t(' ');
    $status_message_tapi['status']['size'] = 0;
    $status_message_tapi['status']['messages'] = array();
    $status_message_tapi['error'] = array();
    $status_message_tapi['error']['enabled'] = false;
    $status_message_tapi['error']['heading'] = ($ds_massage_error_heading = theme_get_setting('ds_message_error_heading')) ? $ds_massage_error_heading : t(' ');
    $status_message_tapi['error']['size'] = 0;
    $status_message_tapi['error']['messages'] = array();
    $status_message_tapi['warning'] = array();
    $status_message_tapi['warning']['enabled'] = false;
    $status_message_tapi['warning']['heading'] = ($ds_massage_warning_heading = theme_get_setting('ds_message_warning_heading')) ? $ds_massage_warning_heading : t(' ');
    $status_message_tapi['warning']['size'] = 0;
    $status_message_tapi['warning']['messages'] = array();
    $status_message_tapi['info'] = array();
    $status_message_tapi['info']['enabled'] = false;
    $status_message_tapi['info']['heading'] = ($ds_massage_info_heading = theme_get_setting('ds_message_info_heading')) ? $ds_massage_info_heading : t(' ');
    $status_message_tapi['info']['size'] = 0;
    $status_message_tapi['info']['messages'] = array();

    //loop through each message type
    foreach (drupal_get_messages(null, $clear) as $type => $messages) {
           foreach($messages as $key => $message){
               $status_message_tapi[$type]['enabled'] = true;
               $status_message_tapi[$type]['size'] = $status_message_tapi[$type]['size'] + 1;
               $status_message_tapi[$type]['messages'] = array(
                   'message' => $message
               );
           }
    }


    drupal_alter('status_message_tapi', $status_message_tapi);

    return $status_message_tapi;
}


function rebuild_menu_tree(&$tree, $menu_name, $depth = 0, $active_trail_list = array())
{
    $depth++;

    foreach ($tree as &$link) {
        if (!$link['link']['hidden']) {
            $link['sub_menu'] = '';
            //check if part of active trail
            if (false !== array_search($link['link']['link_path'], $active_trail_list)) {
                $link['link']['in_active_trail'] = true;
            }
            //go into deeper
            if (isset($link['below']) && !empty($link['below'])) {
                rebuild_menu_tree($link['below'], $menu_name, $depth, $active_trail_list);
                $menu_tapi = _menu_tapi($link['below'], $depth);
                $link['sub_menu'] = array(
                    '#theme' => 'template_api_' . $menu_name,
                    '#menu_tapi' => $menu_tapi,
                );
            }

            $link_tapi = _menu_link_tapi($link['link'], $depth, $link['sub_menu']);
            $link['link_output'] = array(
                '#theme' => 'template_api_' . $menu_name . '_link',
                '#link_tapi' => $link_tapi,
            );
        }
    }
}

function filter_active_path($menu_item)
{
    return (isset($menu_item['link_path'])) ? base_path() . $menu_item['link_path'] : base_path() . $menu_item['path'];
}

//wrapper around the internal _menu_tapi()
function menu_tapi($menu_name)
{
    $menu = str_replace('-', '_', $menu_name);
    $tree = menu_tree_all_data($menu_name, NULL);
    rebuild_menu_tree($tree, $menu);
    return $tree;
}

/**
 * retrieves all user actions with related link path
 */
function _user_actions()
{
    return array(
        'register' => array(
            'path' => base_path() . 'user/register',
            'text' => ($register_text = (theme_get_setting('ds_user_register_text'))) ? $register_text : 'Create an account',
        ),
        'login' => array(
            'path' => base_path() . 'user',
            'text' => ($log_in_text = (theme_get_setting('ds_user_login_text'))) ? $log_in_text : 'Log in',
        ),
        'password-reset' => array(
            'path' => base_path() . 'user/password',
            'text' => ($pass_reset_text = theme_get_setting('ds_user_pass_reset_text')) ? $pass_reset_text : 'reset your password',
        ),
    );
}

