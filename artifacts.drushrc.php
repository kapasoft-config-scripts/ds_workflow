<?php
//declaring repos
$repo_list = array();
$repo_list['module'] = 'https://github.com/kapasoft-drupal-modules/';
$repo_list['theme'] = 'https://github.com/kapasoft-drupal-themes/';
$repo_list['site'] = 'https://github.com/kapasoft-drupal-site-modules/';
$repo_list['utils'] = 'https://github.com/kapasoft-config-scripts/';

//declaring artifacts
$artifacts = array();
$artifacts['lib'] = array(
    'name' => 'lib',
    'module_name' => 'designssquare_lib',
    'final_name' => 'designssquare_com_lib',
    'repo' => $repo_list['utils'],
    'repo_name' => 'designssquare-utils',
    'work_dir_name' => 'designssquare_lib',
);
$artifacts['sample_data'] = array(
    'name' => 'sample_data',
    'module_name' => 'designssquare_lib_sample_data',
    'final_name' => 'designssquare_com_lib_sample_data',
    'repo' => $repo_list['utils'],
    'repo_name' => 'designssquare-lib-sample-data',
    'work_dir_name' => 'designssquare_lib_sample_data',
);
$artifacts['template_api'] = array(
    'name' => 'template_api',
    'module_name' => 'designssquare_lib_template_api',
    'final_name' => 'designssquare_com_lib_template_api',
    'repo' => $repo_list['utils'],
    'repo_name' => 'template_api',
    'work_dir_name' => 'designssquare_lib_template_api',
);
$artifacts['theme_blocks'] = array(
    'name' => 'theme_blocks',
    'repo' => $repo_list['module'],
    'repo_name' => 'designssquare_com_theme_blocks',
    'final_name' => 'designssquare_com_theme_blocks',
    'work_dir_name' => 'designssquare_theme_blocks',
);
$artifacts['theme_blocks_plus'] = array(
    'name' => 'theme_blocks_plus',
    'module_name' => 'designssquare_com_theme_blocks',
    'final_name' => 'designssquare_com_theme_blocks_plus',
    'repo' => $repo_list['module'],
    'repo_name' => 'designssquare_com_theme_blocks',
    'branch' => 'plus',
    'work_dir_name' => 'designssquare_com_theme_blocks_plus',
);

$artifacts['blog'] = array(
   'name' => 'blog',
    'module_name' => 'designssquare_com_blog',
    'final_name' => 'designssquare_com_widget_blog',
    'repo' => $repo_list['module'],
   'repo_name' => 'blog',
    'work_dir_name' => 'blog',
);
$artifacts['utils_ckeditor'] = array(
    'name' => 'utils_ckeditor',
    'module_name' => 'designssquare_com_ckeditor',
    'final_name' => 'designssquare_com_utils_ckeditor',
    'repo' => $repo_list['utils'],
    'repo_name' => 'designssquare-utils-ckeditor',
    'work_dir_name' => 'designssquare_utils_ckeditor'
);
$artifacts['portfolio'] = array(
    'name' => 'portfolio',
    'module_name' => 'designssquare_com_widget_portfolio',
    'final_name' => 'designssquare_com_widget_portfolio',
    'repo' => $repo_list['module'],
    'repo_name' => 'portfolio',
    'work_dir_name' => 'portfolio',
);

$artifacts['espresso_theme'] = array(
    'name' => 'espresso_theme',
    'module_name' => 'designssquare_com_theme_espresso',
    'final_name' => 'designssquare_com_theme_espresso',
    'repo' => $repo_list['module'],
    'repo_name' => 'espresso',
    'work_dir_name' => 'espresso_theme',
);
$artifacts['espresso_theme_plus'] = array(
    'name' => 'espresso_theme_plus',
    'module_name' => 'designssquare_com_theme_espresso',
    'final_name' => 'designssquare_com_theme_espresso_plus',
    'repo' => $repo_list['module'],
    'repo_name' => 'espresso',
    'branch' => 'plus',
    'work_dir_name' => 'espresso_theme_plus',
);
$artifacts['metronic_theme'] = array(
    'name' => 'metronic_theme',
    'module_name' => 'designssquare_com_theme_metronic',
    'final_name' => 'designssquare_com_theme_metronic',
    'repo' => $repo_list['module'],
    'repo_name' => 'metronic',
    'work_dir_name' => 'metronic_theme',
);
$artifacts['virtual_hosty'] = array(
    'name' => 'virtual_hosty',
    'module_name' => 'designssquare_utils_virtual_hosty',
    'final_name' => 'designssquare_com_virtual_hosty',
    'repo' => $repo_list['utils'],
    'repo_name' => 'virtual_hosty',
    'work_dir_name' => 'designssquare_utils_virtual_hosty',
);


/********THEMES*********/
$artifacts['bootstrap'] = array(
    'name' => 'bootstrap',
    'type' => 'theme',
    'repo' => $repo_list['theme'],
    'repo_name' => 'bootstrap',
    'final_name' => 'bootstrap',
    'work_dir_name' => 'bootstrap',
);
$artifacts['metronic'] = array(
    'name' => 'metronic',
    'type' => 'theme',
    'repo' => $repo_list['theme'],
    'repo_name' => 'metronic',
    'final_name' => 'metronic',
    'work_dir_name' => 'metronic',
);
$artifacts['espresso'] = array(
    'name' => 'espresso',
    'type' => 'theme',
    'repo' => $repo_list['theme'],
    'repo_name' => 'espresso',
    'final_name' => 'espresso',
    'work_dir_name' => 'espresso',
);


