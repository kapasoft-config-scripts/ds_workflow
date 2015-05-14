api = 2
core = 7.x

;;core
projects[drupal][type] = core
projects[drupal][version] = 7.26

;;widget module
widget[lib][name]=lib
widget[lib][order]=1
widget[lib][ver]=v0.3.14

widget[sample_data][name]=sample_data
widget[sample_data][order]=2
widget[sample_data][ver]=v.0.3

widget[gallery][name]=gallery
widget[gallery][order]=1
widget[gallery][ver]=v0.1.17

;;action[get_widget_make][name]=get_widget_make
;;action[get_widget_make][order]=0
;;action[get_widget_make][result]=widget_make_file

;;action[config_depend][name]=configure_all_dependencies
;;action[config_depend][order]=1
;;action[config_depend][make_file]=widget_make_file

;;actions
action[enable_gallery][name]=enable_artifact
action[enable_gallery][order]=10
action[enable_gallery][tag]=gallery,init
action[enable_gallery][param][]=designssquare_lib
action[enable_gallery][param][]=designssquare_lib_sample_data
action[enable_gallery][param][]=designssquare_com_widget_gallery


action[permit_gallery_public_dir][name]=permit_public_dir
action[permit_gallery_public_dir][order]=10
action[permit_gallery_public_dir][tag]=gallery,config,kickstart

action[sample_gallery][name]=enable_artifact
action[sample_gallery][order]=11
action[sample_gallery][tag]=gallery,kickstart
action[sample_gallery][param][]=designssquare_com_widget_photo_gallery_sample_data_for_kickstart

action[revert_gallery][name]=revert_feature
action[revert_gallery][order]=12
action[revert_gallery][tag]=gallery,revert
action[revert_gallery][param][]=designssquare_com_widget_photo_gallery_configurations_structure_data
action[revert_gallery][param][]=designssquare_com_widget_photo_gallery_sample_data_for_kickstart



;;module related
projects[] = context
projects[] = videojs
projects[] = strongarm
projects[uuid][version] = 1.x-dev
projects[uuid_features][version] = 1.x-dev
projects[] = views
projects[] = entity
projects[] = eva
projects[] = entityreference
projects[] = features
projects[field_remove_item][version] = 1.x-dev

;WF_START

;;CONFIGURATIONS
action[dl_depend][name]=dl_project_dependencies
action[dl_depend][order]=3
action[dl_depend][tag]=download

action[config_depend][name]=configure_all_dependencies
action[config_depend][order]=5
action[config_depend][tag]=config

action[permit_public_dir][name]=permit_dir
action[permit_public_dir][order]=4
action[permit_public_dir][tag]=config,tune_up


action[clear_all][name]=clear_all
action[clear_all][order]=100
action[clear_all][tag]=clear,revert,dev

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
action[dd_dev][name]=download_module
action[dd_dev][order]=10
action[dd_dev][tag]=dev
action[dd_dev][param][]=simplehtmldom-7.x-1.12
action[dd_dev][param][]=devel_themer

action[en_dev][name]=enable_artifact
action[en_dev][order]=11
action[en_dev][tag]=dev
action[en_dev][param][]=simplehtmldom
action[en_dev][param][]=devel_themer

action[jquery_no_min][name]=set
action[jquery_no_min][order]=12
action[jquery_no_min][tag]=dev
action[jquery_no_min][param][]=jquery_update_compression_type
action[jquery_no_min][param][]="none"

action[create_tmp_dir][name]=create_dir
action[create_tmp_dir][order]=13
action[create_tmp_dir][tag]=dev
action[create_tmp_dir][param][]="sites/default/files/tmp"

action[permissions_tmp_dir][name]=permit_dir
action[permissions_tmp_dir][order]=13
action[permissions_tmp_dir][tag]=dev
action[permissions_tmp_dir][param][]="777"
action[permissions_tmp_dir][param][]="sites/default/files/tmp"

action[set_tmp_dir][name]=set
action[set_tmp_dir][order]=14
action[set_tmp_dir][tag]=dev
action[set_tmp_dir][param][]=file_temporary_path
action[set_tmp_dir][param][]="sites/default/files/tmp"

action[set_private_dir][name]=set
action[set_private_dir][order]=14
action[set_private_dir][tag]=dev
action[set_private_dir][param][]=file_private_path
action[set_private_dir][param][]="sites/default/files/tmp"


;;TUNE UP
action[tune_drupal][name]=enable_artifact
action[tune_drupal][order]=12
action[tune_drupal][tag]=tune_up
action[tune_drupal][param][]=admin_menu
action[tune_drupal][param][]=module_filter
action[tune_drupal][param][]=coffee
action[tune_drupal][param][]=context
action[tune_drupal][param][]=context_ui
action[tune_drupal][param][]=view
action[tune_drupal][param][]=view_ui

action[tune_up][name]=tune_up
action[tune_up][order]=12
action[tune_up][tag]=tune_up

;;Handle Virtual Directories
action[config_hosty][name]=enable_artifact
action[config_hosty][order]=13
action[config_hosty][tag]=hosty
action[config_hosty][param][]=designssquare_com_virtual_hosty

;WF_END