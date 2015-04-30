<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function metronic_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {
  // Work-around for a core bug affecting admin themes.
  // @see https://drupal.org/node/943212
  if (isset($form_id)) {
    return;
  }

  _metronic_settings_form($form, $form_state);
}

function _metronic_settings_form(&$form, $form_state) {

    module_load_include('inc', 'designssquare_lib_template_api', 'includes/template_api');
    $theme_tapi = _theme_settings_tapi();
    $form['metronic'] = array(
        '#type' => 'vertical_tabs',
        '#attached' => array(
            'js'  => array(drupal_get_path('theme', 'bootstrap') . '/js/bootstrap.admin.js'),
        ),
        '#prefix' => '<h2><small>' . t('Metronic Settings') . '</small></h2>',
        '#weight' => -20,
    );

    // Components.

    $form['site_styler'] = array(
        '#type' => 'fieldset',
        '#title' => t('Site Styler'),
        '#group' => 'metronic',
    );
    // Anchors.
//    $form['site_styler']['options'] = array(
//        '#type' => 'fieldset',
//        '#title' => t('Status'),
//        '#collapsible' => TRUE,
//        '#collapsed' => TRUE,
//    );
//    $form['site_styler']['options']['styler_status'] = array(
//        '#type' => 'select',
//        '#title' => t('Site Styler Status'),
//        '#default_value' => theme_get_setting('styler_status'),
//        '#options' => array(
//            1 => t('Enabled'),
//            0 => t('Disabled'),
//        )
//    );

    //Layout Style.
    $form['site_styler']['style'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layouts Style'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['site_styler']['style'][$theme_tapi['layout']['index']] = array(
        '#type' => 'radios',
        '#title' => t('Layout'),
        '#default_value' => $theme_tapi['layout']['value'],
        '#options' => array(
            'fluid' => t('fluid'),
            'boxed' => t('boxed'),
        ),
    );


    //Color Schemes.
    $form['site_styler']['color'] = array(
        '#type' => 'fieldset',
        '#title' => t('Color Schemes'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['site_styler']['color'][$theme_tapi['color']['index']] = array(
        '#type' => 'select',
        '#title' => t('Color Schemes'),
        '#default_value' => $theme_tapi['color']['value'],
        '#options' => array(
            'default' => t('default'),
            'darkblue' => t('dark blue'),
            'blue' => t('blue'),
            'grey' => t('grey'),
            'light' => t('light'),
            'light2' => t('light2'),
        ),
    );

    //Header
    $form['site_styler']['header'] = array(
        '#type' => 'fieldset',
        '#title' => t('Header'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['site_styler']['header'][$theme_tapi['header']['index']] = array(
        '#type' => 'select',
        '#title' => t('Header'),
        '#default_value' => $theme_tapi['header']['value'],
        '#options' => array(
            'default' => t('default'),
            'fixed' => t('fixed'),
        ),
    );


    //Sidebar
    $form['site_styler']['sidebar'] = array(
        '#type' => 'fieldset',
        '#title' => t('Sidebar'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['site_styler']['sidebar'][$theme_tapi['sidebar']['index']] = array(
        '#type' => 'select',
        '#title' => t('Sidebar'),
        '#default_value' => $theme_tapi['sidebar']['value'],
        '#options' => array(
            'default' => t('default'),
            'fixed' => t('fixed'),
        ),
    );
    $form['site_styler']['sidebar'][$theme_tapi['sidebar_position']['index']] = array(
        '#type' => 'select',
        '#title' => t('Sidebar Position'),
        '#default_value' => $theme_tapi['sidebar_position']['value'],
        '#options' => array(
            'left' => t('left'),
            'right' => t('right'),
        ),
    );


    //Footer
    $form['site_styler']['footer'] = array(
        '#type' => 'fieldset',
        '#title' => t('Footer'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['site_styler']['footer'][$theme_tapi['footer']['index']] = array(
        '#type' => 'select',
        '#title' => t('Footer'),
        '#default_value' => $theme_tapi['footer']['value'],
        '#options' => array(
            'default' => t('default'),
            'fixed' => t('fixed'),
        ),
    );

    $form['user_styler'] = array(
        '#type' => 'fieldset',
        '#title' => t('User Styler'),
        '#group' => 'metronic',
    );
    // Anchors.
    $form['user_styler']['options'] = array(
        '#type' => 'fieldset',
        '#title' => t('Options'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['user_styler']['options']['user_styler_client'] = array(
        '#type' => 'checkbox',
        '#title' => t('Style on every request in user browser'),
        '#default_value' => theme_get_setting('user_styler_client'),
        '#description' => t('The style is generated in user browser on every request (not recommended for performance)'),
    );

    $form['user_styler']['options']['user_styler_server'] = array(
        '#type' => 'checkbox',
        '#title' => t('Style once on server'),
        '#default_value' => theme_get_setting('user_styler_server'),
        '#description' => t('Stylesheet generated once for each user and stored till the end of session (not recommended for cost effectiveness of server)'),
    );
}
