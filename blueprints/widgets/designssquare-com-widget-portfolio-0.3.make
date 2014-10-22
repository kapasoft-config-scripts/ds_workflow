api = 2
core = 7.x

;;core
projects[drupal][type] = core
projects[drupal][version] = 7.26

;;WIDGETS
widget[lib][name]=lib
widget[lib][order]=1
widget[lib][ver]=v.0.2.2

widget[sample_data][name]=sample_data
widget[sample_data][order]=2
widget[sample_data][ver]=v.0.1

widget[portfolio][name]=portfolio
widget[portfolio][order]=3
widget[portfolio][ver]=0.2.1

;;ACTIONS
action[enable_portfolio][name]=enable_artifact
action[enable_portfolio][order]=10
action[enable_portfolio][tag]=portfolio,init
action[enable_portfolio][param][]=designssquare_lib
action[enable_portfolio][param][]=designssquare_lib_sample_data
action[enable_portfolio][param][]=designssquare_com_widget_portfolio


action[permit_portfolio_public_dir][name]=permit_public_dir
action[permit_portfolio_public_dir][order]=10
action[permit_portfolio_public_dir][tag]=portfolio,kickstart

action[portfolio_sample][name]=enable_artifact
action[portfolio_sample][order]=11
action[portfolio_sample][tag]=portfolio,kickstart
action[portfolio_sample][param][]=designssquare_com_portfolio_sample_data_kickstart

action[revert_portfolio][name]=revert_feature
action[revert_portfolio][order]=12
action[revert_portfolio][tag]=portfolio,revert
action[revert_portfolio][param][]=designssquare_com_portfolio_structure_and_configurations
action[revert_portfolio][param][]=designssquare_com_portfolio_sample_data_kickstart