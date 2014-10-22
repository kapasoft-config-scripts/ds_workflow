<?php
/**
 * @file
 * theme-settings.php
 *
 * Provides theme settings for espresso based themes when admin theme is not.
 *
 * @see theme/settings.inc
 */


/**
 * Implements hook_form_FORM_ID_alter().
 */
define('DESIGNSSQUARE_THEME', 'public://designssquare_com/theme/espresso');
define('MAX_SIZE_LIMIT_DS_THEME', (int)(ini_get('upload_max_filesize')));

function espresso_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {

    // Work-around for a core bug affecting admin themes.
    // @see https://drupal.org/node/943212
    if (isset($form_id)) {
        return;
    }
    // Include theme settings file.
//    bootstrap_include('bootstrap', 'theme/settings.inc');
    // Alter theme settings form.
//    _bootstrap_settings_form($form, $form_state);

    $form['espresso'] = array(
        '#type' => 'vertical_tabs',
        '#attached' => array(
            'js'  => array(drupal_get_path('theme', 'bootstrap') . '/js/bootstrap.admin.js'),
        ),
        '#prefix' => '<h2><small>' . t('Espresso Settings') . '</small></h2>',
        '#weight' => -11,
    );

    // Components.
    $form['layouts'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layouts'),
        '#group' => 'espresso',
    );
    //Layout Style.
    $form['layouts']['style'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layouts Style'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );
    $form['layouts']['style']['espresso_layout'] = array(
        '#type' => 'radios',
        '#title' => t('Espresso Layout'),
        '#default_value' => theme_get_setting('espresso_layout'),
        '#options' => array(
            'boxed' => t('Boxed'),
            'semiboxed' => t('Semiboxed'),
            'wide' => t('Wide'),
        ),
    );

    //Color Schemes
    $form['schemes'] = array(
        '#type' => 'fieldset',
        '#title' => t('Color Schemes'),
        '#group' => 'espresso',
    );
    //Color Schemes.
    $form['schemes']['color'] = array(
        '#type' => 'fieldset',
        '#title' => t('Color Schemes'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );
    $form['schemes']['color']['espresso_color_scheme'] = array(
        '#type' => 'select',
        '#title' => t('Color Schemes'),
        '#default_value' => theme_get_setting('espresso_color_scheme'),
        '#options' => array(
            'blue' => t('Blue'),
            'brown' => t('brown'),
            'gray' => t('Gray'),
            'green' => t('Green'),
            'khaki' => t('Khaki'),
            'orange' => t('Orange'),
            'red' => t('Red'),
            'teal' => t('Teal'),
            'yellow' => t('Yellow'),
        ),
    );
    //Backgrounds
    $form['backgrounds'] = array(
        '#type' => 'fieldset',
        '#title' => t('Background'),
        '#group' => 'espresso',
    );

    $form['backgrounds']['ds_theme_predefined_background'] = array(
        '#type' => 'select',
        '#title' => t('Available Backgrounds'),
        '#default_value' => isset($form_state['value']['ds_theme_predefined_background']) ? $form_state['value']['ds_theme_predefined_background'] : theme_get_setting('ds_theme_predefined_background'),
        '#description' => t('Select background image from already predefined backgrounds'),
        '#options' => array(
            '001' => t('001'),
            '002' => t('002'),
            '003' => t('003'),
            '004' => t('004'),
            '005' => t('005'),
            '006' => t('006'),
            '007' => t('007'),
            '008' => t('008'),
            '009' => t('009'),
            '010' => t('010'),
            '011' => t('011'),
            '012' => t('012'),
        ),
    );

    $form['backgrounds']['ds_custom_bg_enabled'] = array(
        '#title' => t('Select for custom background image to be enabled '),
        '#type' => 'checkbox',
        '#default_value' => isset($form_state['value']['ds_custom_bg_enabled']) ? $form_state['value']['ds_custom_bg_enabled'] : theme_get_setting('ds_custom_bg_enabled'),
    );

    $form['backgrounds']['ds_theme_custom_background'] = array(
        '#title' => t('Custom Background'),
        '#type' => 'managed_file',
        '#description' => t('Upload a your custom background image, allowed extensions: jpg, jpeg, png, gif'),
//        '#default_value' => isset($form_state['value']['ds_theme_custom_background']) ? $form_state['value']['ds_theme_custom_background'] : theme_get_setting('ds_theme_custom_background'),
        '#default_value' => variable_get('ds_theme_custom_background', theme_get_setting('ds_theme_custom_background')),
        '#upload_location' => DESIGNSSQUARE_THEME.'/theme-settings',
        '#upload_validators' => array(
            'file_validate_extensions' => array('jpg jpeg png gif'),
            // Pass the maximum file size in bytes
            'file_validate_size' => array(MAX_SIZE_LIMIT_DS_THEME*1024*1024),
        ),
        '#process' => array('ds_designssquare_lib_process_file_managed'),
    );

}

//function ds_theme_espresso_submit($form, &$form_state){
//    drupal_set_message(t('theme settings saved'));
//}