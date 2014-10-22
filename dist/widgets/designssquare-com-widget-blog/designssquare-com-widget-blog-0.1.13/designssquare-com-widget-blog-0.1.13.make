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
;WF_START

;;CONFIGURATIONS
action[dl_depend][name]=dl_project_dependencies
action[dl_depend][order]=3
action[dl_depend][tag]=download

action[config_depend][name]=configure_all_dependencies
action[config_depend][order]=5
action[config_depend][tag]=config

action[permit_public_dir][name]=permit_public_dir
action[permit_public_dir][order]=4
action[permit_public_dir][tag]=config


action[clear_all][name]=clear_all
action[clear_all][order]=100
action[clear_all][tag]=clear,revert

;;EDITOR
action[enable_editor][name]=enable_artifact
action[enable_editor][order]=7
action[enable_editor][tag]=editor
action[enable_editor][param][]=ckeditor,imce

action[config_editor][name]=configure_editor
action[config_editor][order]=7
action[config_editor][tag]=editor
action[config_editor][param][]=designssquare_com_ckeditor

;;AUDIO
action[configure_audio][name]=configure_audio
action[configure_audio][order]=3
action[configure_audio][tag]=audio
action[configure_audio][param][module_name]=designssquare_lib
action[configure_audio][param][audio-player]=wpaudioplayer

;;VIDEO
action[configure_video][name]=configure_video
action[configure_video][order]=4
action[configure_video][tag]=video
action[configure_video][param][module_name]=designssquare_lib
action[configure_video][param][vidoe-lib]=video-js


;;BUG FIXES
;;to avoid inifite loop https://github.com/drush-ops/drush/issues/791#issuecomment-54494839
action[features_extra][name]=download_module
action[features_extra][order]=0
action[features_extra][tag]=config,block_bug
action[features_extra][param][]=features_extra

action[fe_block][name]=enable_artifact
action[fe_block][order]=1
action[fe_block][tag]=config,block_bug
action[fe_block][param][]=fe_block

;;DEV related
action[en_dev][name]=enable_artifact
action[en_dev][order]=11
action[en_dev][tag]=dev
action[en_dev][param][]=admin_menu
action[en_dev][param][]=module_filter
action[en_dev][param][]=coffee


;WF_END