api = 2
core = 7.x

;;core
projects[drupal][type] = core
projects[drupal][version] = 7.26

;;blog module
widget[lib][name]=lib
widget[lib][order]=1
widget[lib][ver]=v.0.2.2

widget[sample_data][name]=sample_data
widget[sample_data][order]=2
widget[sample_data][ver]=v.0.1

widget[utils_ckeditor][name]=utils_ckeditor
widget[utils_ckeditor][order]=5
widget[utils_ckeditor][ver]=v0.1.0

widget[blog][name]=blog
widget[blog][order]=1
widget[blog][ver]=v0.1.15

;;action[get_widget_make][name]=get_widget_make
;;action[get_widget_make][order]=0
;;action[get_widget_make][result]=widget_make_file

;;action[config_depend][name]=configure_all_dependencies
;;action[config_depend][order]=1
;;action[config_depend][make_file]=widget_make_file

;;actions
action[enable_blog][name]=enable_artifact
action[enable_blog][order]=10
action[enable_blog][tag]=blog,init
action[enable_blog][param][]=designssquare_lib
action[enable_blog][param][]=designssquare_lib_sample_data
action[enable_blog][param][]=designssquare_com_blog


action[permit_blog_public_dir][name]=permit_public_dir
action[permit_blog_public_dir][order]=10
action[permit_blog_public_dir][tag]=blog,kickstart

action[sample][name]=enable_artifact
action[sample][order]=11
action[sample][tag]=blog,kickstart
action[sample][param][]=designssquarecom_blog_example_data

action[revert_espresso][name]=revert_feature
action[revert_espresso][order]=12
action[revert_espresso][tag]=blog,revert
action[revert_espresso][param][]=designssquarecom_blog_structure
action[revert_espresso][param][]=designssquarecom_blog_example_data


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


;;module related
 projects[] = audiofield
 projects[] = context
 projects[] = videojs
 projects[] = libraries
 projects[] = strongarm
 projects[uuid][version] = 1.x-dev
 projects[uuid_features][version] = 1.x-dev
 projects[] = views
 projects[] = entity
 projects[] = ctools
 projects[] = features
 projects[] = ckeditor
 projects[] = imce
 projects[] = videojs

 ;;for JW Player
 ;projects[] = jw_player
 ;projects[] = video
 ;projects[] = video_presets