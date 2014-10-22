api = 2
core = 7.x

;;core
projects[drupal][type] = core
projects[drupal][version] = 7.26

;;custom modules
widget[lib][name]=lib
widget[lib][order]=1
widget[lib][ver]=v.0.2.2
widget[sample_data][name]=sample_data
widget[sample_data][order]=2
widget[sample_data][ver]=v.0.1
widget[theme_blocks_plus][name]=theme_blocks_plus
widget[theme_blocks_plus][order]=3
widget[theme_blocks_plus][ver]=v0.1.0
widget[espresso_theme][name]=espresso_theme_plus
widget[espresso_theme][order]=4
widget[espresso_theme][ver]=plus-v0.1.3
widget[utils_ckeditor][name]=utils_ckeditor
widget[utils_ckeditor][order]=5
widget[utils_ckeditor][ver]=v0.1.0

;;themes
theme[bootstrap][name]=bootstrap
theme[bootstrap][order]=1
theme[bootstrap][ver]=v0.1
theme[espresso][name]=espresso
theme[espresso][order]=2
theme[espresso][ver]=v0.7

;;actions
action[enable][name]=enable_artifact
action[enable][order]=6
action[enable][tag]=espresso,init
action[enable][param][]=designssquare_lib
action[enable][param][]=designssquare_lib_sample_data
action[enable][param][]=designssquare_com_theme_espresso
action[enable][param][]=bootstrap
action[enable][param][]=espresso

action[default_theme][name]=set_default_theme
action[default_theme][order]=8
action[default_theme][tag]=espresso,init
action[default_theme][param][]=espresso

action[sample][name]=enable_artifact
action[sample][order]=9
action[sample][tag]=espresso,kickstart
action[sample][param][]=designssquare_com_theme_espresso_sample_data

action[revert_espresso][name]=revert_feature
action[revert_espresso][order]=10
action[revert_espresso][tag]=espresso,revert
action[revert_espresso][param][]=designssquare_com_theme_espresso_structure
action[revert_espresso][param][]=designssquare_com_theme_espresso_sample_data


;;dev modules
;projects[] = module_filter
;projects[] = devel
;projects[] = simplehtmldom
;projects[simplehtmldom][version] = 1.12
;projects[] = devel_themer
;projects[] = coffee
;projects[] = diff
;projects[] = admin_menu
;projects[] = features_diff


;;theme related
projects[jquery_update][version] = 2.x-dev
projects[] = token
projects[] = context
projects[] = ctools
projects[] = features
;;projects[] = libraries
projects[] = strongarm
projects[] = features_extra
projects[] = views
projects[] = entity
;;projects[] = entityreference
;;projects[] = image_url_formatter
projects[] = pathauto
;;projects[] = feeds_tamper
projects[uuid][version] = 1.x-dev
projects[uuid_features][version] = 1.x-dev