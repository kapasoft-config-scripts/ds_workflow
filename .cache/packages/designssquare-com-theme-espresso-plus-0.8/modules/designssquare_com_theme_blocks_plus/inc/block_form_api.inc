<?php
define('MODULE_DEST', 'public://designssquare_com_theme_blocks/assets');
define('MAX_SIZE_LIMIT_DS', (int)(ini_get('upload_max_filesize')));

module_load_include('module', 'designssquare_lib'); //include get_block_context api


/*********General********/
function ds_block_edit_form($form, &$form_submit)
{

    switch ($form_submit['build_info']['args'][0]) {
        case 'ds_social':
            $form += _social_block_form();
            $form_title = 'Block Widget - Social';
            break;
        case 'ds_about':
            $form += _about_block_form();
            $form_title = 'Block Widget - About';
            break;
        case 'ds_about_teaser':
            $form += _about_block_teaser_form();
            $form_title = 'Block Widget - About Teaser';
            break;
        case 'ds_copy_rights':
            $form += _copy_rights_block_form();
            $form_title = 'Block Widget - Copy Rights';
            break;
        case 'ds_contact_info':
            $form += _contact_info_block_form();
            $form_title = 'Block Widget - Contact Info';
            break;
        case 'ds_announcement':
            $form += _announcement_block_form();
            $form_title = 'Block Widget - Announcement';
            break;
        case 'ds_recent_tweets':
            $form += _recent_tweets_block_form();
            $form_title = 'Block Widget - Recent Tweets';
            break;
        case 'ds_blog_categories':
            $form += _blog_categories_block_form();
            $form_title = 'Block Widget - Categories';
            break;
        case 'ds_blog_archive':
            $form += _blog_archive_block_form();
            $form_title = 'Block Widget - Archive';
            break;
        case 'ds_blog_recent_posts_sidebar':
            $form += _blog_recent_posts_block_form();
            $form_title = 'Block Widget - Recent Posts';
            break;
        case 'ds_testimonial':
            $form += _testimonial_block_form();
            $form_title = 'Block Widget - Testimonial';
            break;
    }

    $form['form_header'] = array(
        '#markup' => '<h2>' . $form_title . '</h2>',
        '#weight' => -15,
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

function ds_block_edit_form_submit($form, &$form_state)
{

    switch ($form_state['build_info']['args'][0]) {
        case 'ds_copy_rights':
            _copy_rights_block_form_process($form_state);
            break;
        case 'ds_contact_info':
            _contact_info_block_form_process($form_state);
            break;
        case 'ds_announcement':
            _announcement_block_form_process($form_state);
            break;
        case 'ds_about_teaser':
            _about_block_teaser_form_process($form_state);
            break;
        case 'ds_about':
            _about_block_form_process($form_state);
            break;
        case 'ds_social':
            _social_block_form_process($form_state);
            break;
        case 'ds_recent_tweets':
            _recent_tweets_block_form_process($form_state);
            break;
        case 'ds_blog_categories':
            _blog_categories_block_form_process($form_state);
            break;
        case 'ds_blog_archive':
            _blog_archive_block_form_process($form_state);
            break;
        case 'ds_blog_recent_posts_sidebar':
            _blog_recent_posts_block_form_process($form_state);
            break;
        case 'ds_testimonial':
            _testimonial_block_form_process($form_state);
            break;
    }
// Display a message upon successful submission.
    drupal_set_message(t("Widget was updated successfully!"));
}

/******BLOCK - ABOUT TEASER ********/
function _about_block_teaser_form()
{
    return array(
        'ds_about_teaser__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_about_teaser__content_block__title', ''),
        ),
        'ds_about_teaser__content_block__content' => array(
//            '#type' => 'textarea',
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
            '#default_value' => variable_get('ds_about_teaser__content_block__content', ''),
        ),
        'ds_about_teaser__content_block__reference' => array(
            '#type' => 'textfield',
            '#prefix' => t('Page To Reference'),
            '#suffix' => t('(i.e. about/about-company/designs-square-com)'),
            '#default_value' => variable_get('ds_about_teaser__content_block__reference', ''),
        ),
        'ds_about_teaser__content_block__image' => array(
            '#title' => t('Image'),
            '#type' => 'managed_file',
            '#description' => t('Upload a file, allowed extensions: jpg, jpeg, png, gif'),
            '#default_value' => variable_get('ds_about_teaser__content_block__image', ''),
            '#upload_location' => MODULE_DEST . '/img',
            '#upload_validators' => array(
                'file_validate_extensions' => array('jpg jpeg png gif'),
                // Pass the maximum file size in bytes
                'file_validate_size' => array(MAX_SIZE_LIMIT_DS * 1024 * 1024),
            ),
            '#process' => array('ds_designssquare_lib_process_file_managed'),
        )
    );
}

function _about_block_teaser_form_process($form_state)
{
    variable_set('ds_about_teaser__content_block__title', $form_state['values']['ds_about_teaser__content_block__title']);
    variable_set('ds_about_teaser__content_block__content', $form_state['values']['ds_about_teaser__content_block__content']['value']);
    variable_set('ds_about_teaser__content_block__image', $form_state['values']['ds_about_teaser__content_block__image']);
    variable_set('ds_about_teaser__content_block__reference', $form_state['values']['ds_about_teaser__content_block__reference']);
}

function _about_block_teaser_feed($block_id)
{

    $title = variable_get('ds_about_teaser__content_block__title', '');
    $content = variable_get('ds_about_teaser__content_block__content', '');
    $img_fid = variable_get('ds_about_teaser__content_block__image', '');
    $reference_page = '/' . variable_get('ds_about_teaser__content_block__reference', '#');
    if (!empty($img_fid)) {
        $file = file_load($img_fid);
        $img_url = (isset($file) && isset($file->uri)) ? file_create_url($file->uri) : '';
    } else {
        $img_url = '#';
    }

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_about_teaser')),
    );


    global $user;

    $block_api = array(
        'title' => $title,
        'content' => $content,
        'image' => $img_url,
        'ref_page' => $reference_page,
        'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
    );


    $context = get_block_context('ds_about_teaser');

    return array(
        'block_api' => $block_api,
        'context' => $context,
    );
}

/******BLOCK - ABOUT ********/
function _about_block_form()
{
    return array(
        'ds_about__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_about__content_block__title', ''),
        ),
        'ds_about__content_block__content' => array(
//            '#type' => 'textarea',
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
            '#default_value' => variable_get('ds_about__content_block__content', ''),
        ),
//        'ds_about__content_block__reference' => array(
//            '#type' => 'textfield',
//            '#prefix' => t('Page To Reference'),
//            '#suffix' => t('(i.e. about/about-company/designs-square-com)'),
//            '#default_value' => variable_get('ds_about__content_block__reference', ''),
//        ),
//        'ds_about__content_block__image' => array(
//            '#title' => t('Image'),
//            '#type' => 'managed_file',
//            '#description' => t('Upload a file, allowed extensions: jpg, jpeg, png, gif'),
//            '#default_value' => variable_get('ds_about__content_block__image', ''),
//            '#upload_location' => MODULE_DEST . '/img',
//            '#upload_validators' => array(
//                'file_validate_extensions' => array('jpg jpeg png gif'),
//                // Pass the maximum file size in bytes
//                'file_validate_size' => array(MAX_SIZE_LIMIT_DS * 1024 * 1024),
//            ),
//            '#process' => array('ds_designssquare_lib_process_file_managed'),
//        )
    );
}

function _about_block_form_process($form_state)
{
    variable_set('ds_about__content_block__title', $form_state['values']['ds_about__content_block__title']);
    variable_set('ds_about__content_block__content', $form_state['values']['ds_about__content_block__content']['value']);

}

function _about_block_feed($block_id)
{

    $title = variable_get('ds_about__content_block__title', '');
    $content = variable_get('ds_about__content_block__content', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_about')),
    );


    global $user;

    $block_api = array(
        'title' => $title,
        'content' => $content,
        'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
    );

    $context = get_block_context('ds_about');

    return array(
        'block_api' => $block_api,
        'context' => $context,
    );
}

/******BLOCK - Social/Elsewhere ********/
function _social_block_form()
{
    return array(
        'ds_social__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_social__content_block__title', ''),
        ),
        'ds_social__content_block__content' => array(
//            '#type' => 'textarea',
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
//            '#title' => t('Enter content for the block'),
            '#default_value' => variable_get('ds_social__content_block__content', ''),
        ),

    );

}

function _social_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && $form_state['form_id'] == 'block_admin_configure') {
        variable_set('ds_social__content_block__title', $form_state['ds_social__content_block__title']);
        variable_set('ds_social__content_block__content', $form_state['ds_social__content_block__content']);
    } else {
        variable_set('ds_social__content_block__title', $form_state['values']['ds_social__content_block__title']);
        variable_set('ds_social__content_block__content', $form_state['values']['ds_social__content_block__content']['value']);
    }
}

function _social_block_feed($block_id)
{

    $title = variable_get('ds_social__content_block__title', '');
    $content = variable_get('ds_social__content_block__content', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_social')),
    );

    //generate block_api
    global $user;
    $block_api = array(
        'title' => $title,
        'content' => $content,
        'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
    );

    //generate block context based on block_id
    switch ($block_id) {
        case 'ds_social':
            $context = get_block_context('ds_social');
            break;
        case 'ds_social_sidebar':
            $context = get_block_context('ds_social_sidebar');
            break;
    }

    return array(
        'block_api' => $block_api,
        'context' => $context,
    );
}

/******BLOCK - Copyrights ******/
function _copy_rights_block_form()
{
    return array(
        'ds_copy_rights__content_block__content' => array(
//            '#type' => 'textarea',
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
            '#default_value' => variable_get('ds_copy_rights__content_block__content', ''),
        ),
    );

}

function _copy_rights_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && $form_state['form_id'] == 'block_admin_configure') {
        variable_set('ds_copy_rights__content_block__content', $form_state['ds_copy_rights__content_block__content']);
    } else {
        variable_set('ds_copy_rights__content_block__content', $form_state['values']['ds_copy_rights__content_block__content']['value']);
    }
}

function _copy_rights_block_feed()
{

    $content = variable_get('ds_copy_rights__content_block__content', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_copy_rights')),
    );


    global $user;
    return array(
        'block_api' => array(
            'content' => $content,
            'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
        ),
        'context' => get_block_context('ds_copy_rights'),
    );
}

/******BLOCK - Contact Info ******/
function _contact_info_block_form()
{
    return array(
        'ds_contact_info__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_contact_info__content_block__title', ''),
        ),

        // Demonstrating a fieldset.
        'review_one' => array(
            '#title' => 'Contact Info',
            '#type' => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            'ds_contact_info__content_block__phone' => array(
                '#type' => 'textfield',
                '#prefix' => t('Phone'),
                '#default_value' => variable_get('ds_contact_info__content_block__phone', ''),
            ),
            'ds_contact_info__content_block__email' => array(
                '#type' => 'textfield',
                '#prefix' => t('Email'),
                '#default_value' => variable_get('ds_contact_info__content_block__email', ''),
            ),
            'ds_contact_info__content_block__address' => array(
                '#type' => 'textfield',
                '#prefix' => t('Address'),
                '#default_value' => variable_get('ds_contact_info__content_block__address', ''),
            ),
        ),
    );
}

function _contact_info_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && $form_state['form_id'] == 'block_admin_configure') {
        variable_set('ds_contact_info__content_block__title', $form_state['ds_contact_info__content_block__title']);
        variable_set('ds_contact_info__content_block__phone', $form_state['ds_contact_info__content_block__phone']);
        variable_set('ds_contact_info__content_block__email', $form_state['ds_contact_info__content_block__email']);
        variable_set('ds_contact_info__content_block__address', $form_state['ds_contact_info__content_block__address']);
    } else {
        variable_set('ds_contact_info__content_block__title', $form_state['values']['ds_contact_info__content_block__title']);
        variable_set('ds_contact_info__content_block__phone', $form_state['values']['ds_contact_info__content_block__phone']);
        variable_set('ds_contact_info__content_block__email', $form_state['values']['ds_contact_info__content_block__email']);
        variable_set('ds_contact_info__content_block__address', $form_state['values']['ds_contact_info__content_block__address']);
    }
}

function _contact_info_block_feed()
{

    $title = variable_get('ds_contact_info__content_block__title', '');
    $phone = variable_get('ds_contact_info__content_block__phone', '');
    $email = variable_get('ds_contact_info__content_block__email', '');
    $address = variable_get('ds_contact_info__content_block__address', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_contact_info')),
    );

    global $user;
    return array(
        'block_api' => array(
            'title' => $title,
            'phone' => $phone,
            'email' => $email,
            'address' => $address,
            'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
        ),
        'context' => get_block_context('ds_contact_info'),
    );
}

/*******BLOCK - Announcement******/
function _announcement_block_form()
{
    return array(
        'ds_announcement__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_announcement__content_block__title', ''),
        ),
        'ds_announcement__content_block__content' => array(
//            '#type' => 'textarea',
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
            '#default_value' => variable_get('ds_announcement__content_block__content', ''),
        ),

    );

}

function _announcement_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && $form_state['form_id'] == 'block_admin_configure') {
        variable_set('ds_announcement__content_block__content', $form_state['ds_announcement__content_block__content']);
        variable_set('ds_announcement__content_block__title', $form_state['ds_announcement__content_block__title']);
    } else {
        variable_set('ds_announcement__content_block__content', $form_state['values']['ds_announcement__content_block__content']['value']);
        variable_set('ds_announcement__content_block__title', $form_state['values']['ds_announcement__content_block__title']);
    }
}

function _announcement_block_feed()
{

    $content = variable_get('ds_announcement__content_block__content', '');
    $title = variable_get('ds_announcement__content_block__title', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_announcement')),
    );


    global $user;
    return array(
        'block_api' => array(
            'content' => $content,
            'title' => $title,
            'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
        ),
        'context' => get_block_context('ds_announcement'),
    );
}

/******BLOCK - Recent Posts**********/
function _recent_tweets_block_form()
{
    return array(
        'ds_recent_tweets__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_recent_tweets__content_block__title', ''),
        ),
        'ds_recent_tweets__content_block__link' => array(
            '#type' => 'textfield',
            '#prefix' => t('Link To Twitter'),
            '#suffix' => t('(i.e. twitter.com/company)'),
            '#default_value' => variable_get('ds_about__content_block__link', ''),
        ),
        'ds_recent_tweets__content_block__button_text' => array(
            '#type' => 'textfield',
            '#prefix' => t('Button Text'),
            '#default_value' => variable_get('ds_about__content_block__button_text', t('Follow me on Twitter')),
        ),
        'ds_recent_tweets__content_block__content' => array(
//            '#type' => 'textarea',
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
            '#default_value' => variable_get('ds_recent_tweets__content_block__content', ''),
        ),

    );

}

function _recent_tweets_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && $form_state['form_id'] == 'block_admin_configure') {
        variable_set('ds_recent_tweets__content_block__title', $form_state['ds_recent_tweets__content_block__title']);
        variable_set('ds_recent_tweets__content_block__link', $form_state['ds_recent_tweets__content_block__link']);
        variable_set('ds_recent_tweets__content_block__button_text', $form_state['ds_recent_tweets__content_block__button_text']);
        variable_set('ds_recent_tweets__content_block__content', $form_state['ds_recent_tweets__content_block__content']['value']);
    } else {
        variable_set('ds_recent_tweets__content_block__title', $form_state['values']['ds_recent_tweets__content_block__title']);
        variable_set('ds_recent_tweets__content_block__link', $form_state['values']['ds_recent_tweets__content_block__link']);
        variable_set('ds_recent_tweets__content_block__button_text', $form_state['values']['ds_recent_tweets__content_block__button_text']);
        variable_set('ds_recent_tweets__content_block__content', $form_state['values']['ds_recent_tweets__content_block__content']['value']);
    }
}

function _recent_tweets_block_feed()
{
    $title = variable_get('ds_recent_tweets__content_block__title', '');
    $link_to_twitter = '/' . variable_get('ds_recent_tweets__content_block__link', '#');
    $button_text = variable_get('ds_recent_tweets__content_block__button_text', t('Follow me on Twitter'));
    $content = variable_get('ds_recent_tweets__content_block__content', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_recent_tweets')),
    );


    global $user;
    return array(
        'block_api' => array(
            'title' => $title,
            'content' => $content,
            'button_text' => $button_text,
            'link_to_twitter' => $link_to_twitter,
            'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
        ),
        'context' => get_block_context('ds_recent_tweets'),
    );
}

/******BLOCK - Blog Categories**********/
function _blog_categories_block_form()
{
    return array(
        'ds_blog_categories__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_blog_categories__content_block__title', ''),
        ),
        'ds_blog_categories__content_block__content' => array(
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
            '#default_value' => variable_get('ds_blog_categories__content_block__content', ''),
        ),

    );

}

function _blog_categories_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && ($form_state['form_id'] == 'block_admin_configure')) {
        variable_set('ds_blog_categories__content_block__title', $form_state['ds_blog_categories__content_block__title']);
        variable_set('ds_blog_categories__content_block__content', $form_state['ds_blog_categories__content_block__content']);
    } else {
        variable_set('ds_blog_categories__content_block__title', $form_state['values']['ds_blog_categories__content_block__title']);
        variable_set('ds_blog_categories__content_block__content', $form_state['values']['ds_blog_categories__content_block__content']['value']);
    }
}

function _blog_categories_block_feed()
{
    $title = variable_get('ds_blog_categories__content_block__title', '');
    $content = variable_get('ds_blog_categories__content_block__content', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_blog_categories')),
    );


    global $user;
    return array(
        'block_api' => array(
            'title' => $title,
            'content' => $content,
            'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
        ),
        'context' => get_block_context('ds_blog_categories'),
    );
}


/******BLOCK - Blog Archive**********/
function _blog_archive_block_form()
{
    return array(
        'ds_blog_archive__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_blog_archive__content_block__title', ''),
        ),
        'ds_blog_archive__content_block__content' => array(
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
            '#default_value' => variable_get('ds_blog_archive__content_block__content', ''),
        ),

    );

}

function _blog_archive_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && ($form_state['form_id'] == 'block_admin_configure')) {
        variable_set('ds_blog_archive__content_block__title', $form_state['ds_blog_archive__content_block__title']);
        variable_set('ds_blog_archive__content_block__content', $form_state['ds_blog_archive__content_block__content']);
    } else {
        variable_set('ds_blog_archive__content_block__title', $form_state['values']['ds_blog_archive__content_block__title']);
        variable_set('ds_blog_archive__content_block__content', $form_state['values']['ds_blog_archive__content_block__content']['value']);
    }
}

function _blog_archive_block_feed()
{
    $title = variable_get('ds_blog_archive__content_block__title', '');
    $content = variable_get('ds_blog_archive__content_block__content', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_blog_archive')),
    );


    global $user;
    return array(
        'block_api' => array(
            'title' => $title,
            'content' => $content,
            'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
        ),
        'context' => get_block_context('ds_blog_archive'),
    );
}


/******BLOCK - Recent Posts**********/
function _blog_recent_posts_block_form()
{
    return array(
        'ds_blog_recent_posts_sidebar__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_blog_recent_posts_sidebar__content_block__title', ''),
        ),
        'ds_blog_archive__content_block__content' => array(
            '#type' => 'text_format',
            '#format' => 'full_html',
            '#rows' => '5',
            '#prefix' => t('Content'),
            '#default_value' => variable_get('ds_blog_recent_posts_sidebar__content_block__content', ''),
        ),

    );

}

function _blog_recent_posts_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && ($form_state['form_id'] == 'block_admin_configure')) {
        variable_set('ds_blog_recent_posts_sidebar__content_block__title', $form_state['ds_blog_recent_posts_sidebar__content_block__title']);
        variable_set('ds_blog_recent_posts_sidebar__content_block__content', $form_state['ds_blog_recent_posts_sidebar__content_block__content']);
    } else {
        variable_set('ds_blog_recent_posts_sidebar__content_block__title', $form_state['values']['ds_blog_recent_posts_sidebar__content_block__title']);
        variable_set('ds_blog_recent_posts_sidebar__content_block__content', $form_state['values']['ds_blog_recent_posts_sidebar__content_block__content']['value']);
    }
}

function _blog_recent_posts_block_feed()
{
    $title = variable_get('ds_blog_recent_posts_sidebar__content_block__title', '');
    $content = variable_get('ds_blog_recent_posts_sidebar__content_block__content', '');

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_blog_recent_posts_sidebar')),
    );


    global $user;
    return array(
        'block_api' => array(
            'title' => $title,
            'content' => $content,
            'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
        ),
        'context' => get_block_context('ds_blog_recent_posts_sidebar'),
    );
}

/*creates hook for other modules to pass in variables
 *
 *@param: id of the block
 *
 *@return: array of altered content
*/
//function get_block_context($block_id){
//    $context = array();
//
//    //defaults
//    $context['classes'] = '';//final list of classes
//    $context['classes_array'] = array();//array of each class before combined into one string
//    $context['classes_array'][] = 'contextual-links-region';
//
//    drupal_alter('ds_block_context', $context, $block_id);
//
//    //preprocess
//    $context['classes'] = implode(' ', $context['classes_array'] );
//    return $context;
//}

/******BLOCK - Testimonial ******/
function _testimonial_block_form()
{
    return array(
        'ds_testimonial__content_block__title' => array(
            '#type' => 'textfield',
            '#prefix' => t('Title'),
            '#default_value' => variable_get('ds_testimonial__content_block__title', ''),
        ),
        'review_one' => array(
            '#title' => 'Review One',
            '#type' => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            'ds_testimonial__content_block__reviewer1' => array(
                '#type' => 'textfield',
                '#prefix' => t('Reviewer'),
                '#default_value' => variable_get('ds_testimonial__content_block__reviewer1', ''),
            ),
            'ds_testimonial__content_block__review1' => array(
//            '#type' => 'textarea',
                '#type' => 'text_format',
                '#format' => 'full_html',
                '#rows' => '5',
                '#prefix' => t('Review'),
                '#default_value' => variable_get('ds_testimonial__content_block__review1', ''),
            ),
        ),

        'review_two' => array(
            '#title' => 'Review Two',
            '#type' => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            'ds_testimonial__content_block__reviewer2' => array(
                '#type' => 'textfield',
                '#prefix' => t('Reviewer'),
                '#default_value' => variable_get('ds_testimonial__content_block__reviewer2', ''),
            ),
            'ds_testimonial__content_block__review2' => array(
//            '#type' => 'textarea',
                '#type' => 'text_format',
                '#format' => 'full_html',
                '#rows' => '5',
                '#prefix' => t('Review'),
                '#default_value' => variable_get('ds_testimonial__content_block__review2', ''),
            ),
        ),

        'review_three' => array(
            '#title' => 'Review Three',
            '#type' => 'fieldset',
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            'ds_testimonial__content_block__reviewer3' => array(
                '#type' => 'textfield',
                '#prefix' => t('Reviewer'),
                '#default_value' => variable_get('ds_testimonial__content_block__reviewer3', ''),
            ),
            'ds_testimonial__content_block__review3' => array(
//            '#type' => 'textarea',
                '#type' => 'text_format',
                '#format' => 'full_html',
                '#rows' => '5',
                '#prefix' => t('Review'),
                '#default_value' => variable_get('ds_testimonial__content_block__review3', ''),
            ),
        ),

    );

}

function _testimonial_block_form_process($form_state)
{
    if (isset($form_state['form_id']) && $form_state['form_id'] == 'block_admin_configure') {
//        ds_testimonial__content_block__title
        variable_set('ds_testimonial__content_block__title', $form_state['ds_testimonial__content_block__title']);
        variable_set('ds_testimonial__content_block__review1', $form_state['ds_testimonial__content_block__review1']);
        variable_set('ds_testimonial__content_block__reviewer1', $form_state['ds_testimonial__content_block__reviewer1']);
        variable_set('ds_testimonial__content_block__review2', $form_state['ds_testimonial__content_block__review2']);
        variable_set('ds_testimonial__content_block__reviewer2', $form_state['ds_testimonial__content_block__reviewer2']);
        variable_set('ds_testimonial__content_block__review3', $form_state['ds_testimonial__content_block__review3']);
        variable_set('ds_testimonial__content_block__reviewer3', $form_state['ds_testimonial__content_block__reviewer3']);
    } else {
        variable_set('ds_testimonial__content_block__title', $form_state['values']['ds_testimonial__content_block__title']);
        variable_set('ds_testimonial__content_block__review1', $form_state['values']['ds_testimonial__content_block__review1']['value']);
        variable_set('ds_testimonial__content_block__reviewer1', $form_state['values']['ds_testimonial__content_block__reviewer1']);
        variable_set('ds_testimonial__content_block__review2', $form_state['values']['ds_testimonial__content_block__review2']['value']);
        variable_set('ds_testimonial__content_block__reviewer2', $form_state['values']['ds_testimonial__content_block__reviewer2']);
        variable_set('ds_testimonial__content_block__review3', $form_state['values']['ds_testimonial__content_block__review3']['value']);
        variable_set('ds_testimonial__content_block__reviewer3', $form_state['values']['ds_testimonial__content_block__reviewer3']);
    }
}

function _testimonial_block_feed($block_id)
{
    $title = variable_get('ds_testimonial__content_block__title', '');
    $reviews = array();
    if ($review = variable_get('ds_testimonial__content_block__review1', false)) {
        $reviews[] = array(
            'reviewer' => variable_get('ds_testimonial__content_block__reviewer1', ''),
            'review' => $review,
        );
    }

    if ($review = variable_get('ds_testimonial__content_block__review2', false)) {
        $reviews[] = array(
            'reviewer' => variable_get('ds_testimonial__content_block__reviewer2', ''),
            'review' => $review,
        );
    }

    if ($review = variable_get('ds_testimonial__content_block__review3', false)) {
        $reviews[] = array(
            'reviewer' => variable_get('ds_testimonial__content_block__reviewer3', ''),
            'review' => $review,
        );
    }

    module_load_include('module', 'contextual');
    $contextual_links = contextual_element_info();
    $contextual_links['contextual_links']['#contextual_links'] = array(
        'designssquare_com_theme_blocks' => array('designssquare-blocks', array('ds_testimonial')),
    );

    global $user;
    return array(
        'block_api' => array(
            'title' => $title,
            'reviews' => $reviews,
            'contextual_links' => ($user->uid == 0) ? '' : $contextual_links['contextual_links']
        ),
        'context' => get_block_context($block_id),
    );
}
