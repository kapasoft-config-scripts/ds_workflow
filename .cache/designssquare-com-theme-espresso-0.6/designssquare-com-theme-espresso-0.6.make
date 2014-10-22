api = 2
core = 7.x

;;core
projects[drupal][type] = core
projects[drupal][version] = 7.26

;;custom modules

widget[lib][name]=lib
widget[lib][order]=5
widget[lib][ver]=v.0.2.2
widget[sample_data][name]=sample_data
widget[sample_data][order]=8
widget[sample_data][ver]=v.0.1
widget[theme_blocks][name]=theme_blocks
widget[theme_blocks][order]=7
widget[theme_blocks][ver]=v.0.1
widget[espresso_theme][name]=espresso_theme
widget[espresso_theme][order]=4
widget[espresso_theme][ver]=v0.1.2
widget[utils_ckeditor][name]=utils_ckeditor
widget[utils_ckeditor][order]=9
widget[utils_ckeditor][ver]=v0.1.0

;;themes
theme[bootstrap][name]=bootstrap
theme[bootstrap][order]=1
theme[bootstrap][ver]=v0.1.0
theme[espresso][name]=espresso
theme[espresso][order]=2
theme[espresso][ver]=v0.4

;;actions
action[dl_depend][name]=dl_project_dependencies
action[dl_depend][order]=0
action[dl_depend][tag]=config

action[dl_depend][name]=permit_public_dir
action[dl_depend][order]=0
action[dl_depend][tag]=config

action[config_depend][name]=configure_all_dependencies
action[config_depend][order]=0
action[config_depend][tag]=config

action[load][name]=enable_artifact
action[load][order]=1
action[load][tag]=init
action[load][param][]=designssquare_lib
action[load][param][]=designssquare_lib_sample_data
action[load][param][]=designssquare_com_theme_espresso
action[load][param][]=designssquare_com_theme_espresso_sample_data
action[load][param][]=bootstrap
action[load][param][]=bazar

action[config_editor][name]=configure_editor
action[config_editor][order]=2
action[config_editor][tag]=init,editor
action[config_editor][param][]=designssquare_com_ckeditor

action[default_theme][name]=set_default_theme
action[default_theme][order]=3
action[default_theme][tag]=init
action[default_theme][param][]=espresso

action[revert_structure][name]=revert_feature
action[revert_structure][order]=4
action[revert_structure][tag]=revert
action[revert_structure][param][]=designssquare_com_theme_espresso_configurations_structures
action[revert_structure][param][]=designssquare_com_theme_espresso_sample_data


;;dev modules
projects[] = module_filter
projects[] = devel
;projects[] = simplehtmldom
projects[simplehtmldom][version] = 1.12
projects[] = devel_themer
projects[] = coffee
projects[] = diff
projects[] = admin_menu
projects[] = features_diff


;;theme related
projects[jquery_update][version] = 2.x-dev
projects[] = audiofield
projects[] = token
projects[] = context
projects[] = ctools
projects[] = features
projects[] = libraries
projects[] = strongarm
projects[] = features_extra
projects[] = views
projects[] = entity
projects[] = entityreference
projects[] = image_url_formatter
projects[] = ckeditor
projects[] = imce
projects[] = pathauto
projects[] = feeds_tamper


;;for new menu exporter
projects[uuid][version] = 1.x-dev
projects[uuid_features][version] = 1.x-dev
;projects[] = uuid
;projects[] = uuid_features
;WF_START
action[en_dev][name]=enable_artifact
action[en_dev][order]=10
action[en_dev][tag]=dev
action[en_dev][param][]=admin_menu
action[en_dev][param][]=module_filter
;WF_END