<?php
/**
 * @file
 * designssquare_com_theme_metronic_configurations_structure_data.box.inc
 */

/**
 * Implements hook_default_box().
 */
function designssquare_com_theme_metronic_configurations_structure_data_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'metronic_actions';
  $box->plugin_key = 'simple';
  $box->title = 'Actions Box';
  $box->description = 'Actions Box';
  $box->options = array(
    'body' => array(
      'value' => '						<li class="btn-group">
<button type="button" class="btn blue dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" data-delay="1000" data-close-others="true">
							<span>Actions</span><i class="fa fa-angle-down"></i>
							</button>
							<ul class="dropdown-menu pull-right" role="menu">
								<li>
									<a href="#">Action</a>
								</li>
								<li>
									<a href="#">Another action</a>
								</li>
								<li>
									<a href="#">Something else here</a>
								</li>
								<li class="divider">
								</li>
								<li>
									<a href="#">Separated link</a>
								</li>
							</ul>
</li>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['metronic_actions'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'metronic_copyrights';
  $box->plugin_key = 'simple';
  $box->title = 'Copyrights';
  $box->description = 'Metronic Copyrights Box';
  $box->options = array(
    'body' => array(
      'value' => ' 2014 &copy; Metronic design by keenthemes. Drupalized by DesignsSquare',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['metronic_copyrights'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'metronic_dashboard_box';
  $box->plugin_key = 'simple';
  $box->title = 'Dashboard Date Box';
  $box->description = 'Dashboard Date Box';
  $box->options = array(
    'body' => array(
      'value' => '    <li class="pull-right">
<div id="dashboard-report-range" class="dashboard-date-range tooltips" data-placement="top" data-original-title="Change dashboard date range"> <i class="icon-calendar"></i><span></span><i class="fa fa-angle-down"></i></div>

</li>',
      'format' => 'full_html',
    ),
  );
  $export['metronic_dashboard_box'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'metronic_footer_copyrights';
  $box->plugin_key = 'simple';
  $box->title = 'Footer Copyrigths Box';
  $box->description = 'Footer Copyrigths Box';
  $box->options = array(
    'body' => array(
      'value' => '2014 &copy; KeenThemes & DesignsSquare.com',
      'format' => 'full_html',
    ),
  );
  $export['metronic_footer_copyrights'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'metronic_notifications';
  $box->plugin_key = 'simple';
  $box->title = 'Notifications Box2';
  $box->description = 'Notifications Box';
  $box->options = array(
    'body' => array(
      'value' => '<!-- BEGIN NOTIFICATION DROPDOWN --><li class="dropdown dropdown-extended dropdown-notification" id="header_notification_bar"><a class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" data-close-others="true" href="#"><i class="icon-bell"></i> <span class="badge badge-default">8</span> </a><ul class="dropdown-menu"><li><p>You have 14 new notifications</p></li><li><div class="slimScrollDiv" style="position: relative; overflow: hidden; width: auto; height: 250px;"><ul class="dropdown-menu-list scroller" style="overflow: hidden; width: auto; height: 250px;" data-initialized="1"><li><a href="#"><span class="label label-sm label-icon label-success"> <i class="fa fa-plus"></i> </span> New user registered. <span class="time"> Just now </span> </a></li><li><a href="#"><span class="label label-sm label-icon label-danger"> <i class="fa fa-bolt"></i> </span> Server #12 overloaded. <span class="time"> 15 mins </span> </a></li><li><a href="#"><span class="label label-sm label-icon label-warning"> <i class="fa fa-bell-o"></i> </span> Server #2 not responding. <span class="time"> 22 mins </span> </a></li><li><a href="#"><span class="label label-sm label-icon label-info"> <i class="fa fa-bullhorn"></i> </span> Application error. <span class="time"> 40 mins </span> </a></li><li><a href="#"><span class="label label-sm label-icon label-danger"> <i class="fa fa-bolt"></i> </span> Database overloaded 68%. <span class="time"> 2 hrs </span> </a></li><li><a href="#"><span class="label label-sm label-icon label-danger"> <i class="fa fa-bolt"></i> </span> 2 user IP blocked. <span class="time"> 5 hrs </span> </a></li><li><a href="#"><span class="label label-sm label-icon label-warning"> <i class="fa fa-bell-o"></i> </span> Storage Server #4 not responding. <span class="time"> 45 mins </span> </a></li><li><a href="#"><span class="label label-sm label-icon label-info"> <i class="fa fa-bullhorn"></i> </span> System Error. <span class="time"> 55 mins </span> </a></li><li><a href="#"><span class="label label-sm label-icon label-danger"> <i class="fa fa-bolt"></i> </span> Database overloaded 68%. <span class="time"> 2 hrs </span> </a></li></ul><div class="slimScrollBar" style="width: 7px; position: absolute; top: 0px; opacity: 0.4; border-top-left-radius: 7px; border-top-right-radius: 7px; border-bottom-right-radius: 7px; border-bottom-left-radius: 7px; z-index: 99; right: 1px; display: block; background: rgb(187, 187, 187);"> </div><div class="slimScrollRail" style="width: 7px; height: 100%; position: absolute; top: 0px; display: none; border-top-left-radius: 7px; border-top-right-radius: 7px; border-bottom-right-radius: 7px; border-bottom-left-radius: 7px; opacity: 0.2; z-index: 90; right: 1px; background: rgb(234, 234, 234);"> </div></div></li><li class="external"><a href="#">See all notifications <i class="m-icon-swapright"></i> </a></li></ul></li><!-- END NOTIFICATION DROPDOWN --><!-- BEGIN INBOX DROPDOWN --><li class="dropdown dropdown-extended dropdown-inbox" id="header_inbox_bar"><a class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" data-close-others="true" href="#"><i class="icon-envelope-open"></i> <span class="badge badge-default">5</span> </a><ul class="dropdown-menu"><li><p>You have 12 new messages</p></li><li><div class="slimScrollDiv" style="position: relative; overflow: hidden; width: auto; height: 250px;"><ul class="dropdown-menu-list scroller" style="overflow: hidden; width: auto; height: 250px;" data-initialized="1"><li><a href="inbox.html?a=view"><span class="photo"> <img alt="" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar2.jpg"> </span> <span class="subject"> <span class="from"> Lisa Wong </span> <span class="time"> Just Now </span> </span> <span class="message"> Vivamus sed auctor nibh congue nibh. auctor nibh auctor nibh... </span> </a></li><li><a href="inbox.html?a=view"><span class="photo"> <img alt="" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar3.jpg"> </span> <span class="subject"> <span class="from"> Richard Doe </span> <span class="time"> 16 mins </span> </span> <span class="message"> Vivamus sed congue nibh auctor nibh congue nibh. auctor nibh auctor nibh... </span> </a></li><li><a href="inbox.html?a=view"><span class="photo"> <img alt="" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar1.jpg"> </span> <span class="subject"> <span class="from"> Bob Nilson </span> <span class="time"> 2 hrs </span> </span> <span class="message"> Vivamus sed nibh auctor nibh congue nibh. auctor nibh auctor nibh... </span> </a></li><li><a href="inbox.html?a=view"><span class="photo"> <img alt="" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar2.jpg"> </span> <span class="subject"> <span class="from"> Lisa Wong </span> <span class="time"> 40 mins </span> </span> <span class="message"> Vivamus sed auctor 40% nibh congue nibh... </span> </a></li><li><a href="inbox.html?a=view"><span class="photo"> <img alt="" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar3.jpg"> </span> <span class="subject"> <span class="from"> Richard Doe </span> <span class="time"> 46 mins </span> </span> <span class="message"> Vivamus sed congue nibh auctor nibh congue nibh. auctor nibh auctor nibh... </span> </a></li></ul><div class="slimScrollBar" style="width: 7px; position: absolute; top: 0px; opacity: 0.4; border-top-left-radius: 7px; border-top-right-radius: 7px; border-bottom-right-radius: 7px; border-bottom-left-radius: 7px; z-index: 99; right: 1px; display: block; background: rgb(187, 187, 187);"> </div><div class="slimScrollRail" style="width: 7px; height: 100%; position: absolute; top: 0px; display: none; border-top-left-radius: 7px; border-top-right-radius: 7px; border-bottom-right-radius: 7px; border-bottom-left-radius: 7px; opacity: 0.2; z-index: 90; right: 1px; background: rgb(234, 234, 234);"> </div></div></li><li class="external"><a href="inbox.html">See all messages <i class="m-icon-swapright"></i> </a></li></ul></li><!-- END INBOX DROPDOWN --><!-- BEGIN TODO DROPDOWN --><li class="dropdown dropdown-extended dropdown-tasks" id="header_task_bar"><a class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" data-close-others="true" href="#"><i class="icon-calendar"></i> <span class="badge badge-default">6</span> </a><ul class="dropdown-menu extended tasks"><li><p>You have 12 pending tasks</p></li><li><div class="slimScrollDiv" style="position: relative; overflow: hidden; width: auto; height: 250px;"><ul class="dropdown-menu-list scroller" style="overflow: hidden; width: auto; height: 250px;" data-initialized="1"><li><a href="#"><span class="task"> <span class="desc"> New release v1.2 </span> <span class="percent"> 30% </span> </span> <span class="progress"> <span style="width: 40%;" class="progress-bar progress-bar-success" aria-valuenow="40" aria-valuemin="0" aria-valuemax="100"> <span class="sr-only"> 40% Complete </span> </span> </span> </a></li><li><a href="#"><span class="task"> <span class="desc"> Application deployment </span> <span class="percent"> 65% </span> </span> <span class="progress progress-striped"> <span style="width: 65%;" class="progress-bar progress-bar-danger" aria-valuenow="65" aria-valuemin="0" aria-valuemax="100"> <span class="sr-only"> 65% Complete </span> </span> </span> </a></li><li><a href="#"><span class="task"> <span class="desc"> Mobile app release </span> <span class="percent"> 98% </span> </span> <span class="progress"> <span style="width: 98%;" class="progress-bar progress-bar-success" aria-valuenow="98" aria-valuemin="0" aria-valuemax="100"> <span class="sr-only"> 98% Complete </span> </span> </span> </a></li><li><a href="#"><span class="task"> <span class="desc"> Database migration </span> <span class="percent"> 10% </span> </span> <span class="progress progress-striped"> <span style="width: 10%;" class="progress-bar progress-bar-warning" aria-valuenow="10" aria-valuemin="0" aria-valuemax="100"> <span class="sr-only"> 10% Complete </span> </span> </span> </a></li><li><a href="#"><span class="task"> <span class="desc"> Web server upgrade </span> <span class="percent"> 58% </span> </span> <span class="progress progress-striped"> <span style="width: 58%;" class="progress-bar progress-bar-info" aria-valuenow="58" aria-valuemin="0" aria-valuemax="100"> <span class="sr-only"> 58% Complete </span> </span> </span> </a></li><li><a href="#"><span class="task"> <span class="desc"> Mobile development </span> <span class="percent"> 85% </span> </span> <span class="progress progress-striped"> <span style="width: 85%;" class="progress-bar progress-bar-success" aria-valuenow="85" aria-valuemin="0" aria-valuemax="100"> <span class="sr-only"> 85% Complete </span> </span> </span> </a></li><li><a href="#"><span class="task"> <span class="desc"> New UI release </span> <span class="percent"> 18% </span> </span> <span class="progress progress-striped"> <span style="width: 18%;" class="progress-bar progress-bar-important" aria-valuenow="18" aria-valuemin="0" aria-valuemax="100"> <span class="sr-only"> 18% Complete </span> </span> </span> </a></li></ul><div class="slimScrollBar" style="width: 7px; position: absolute; top: 0px; opacity: 0.4; border-top-left-radius: 7px; border-top-right-radius: 7px; border-bottom-right-radius: 7px; border-bottom-left-radius: 7px; z-index: 99; right: 1px; display: block; background: rgb(187, 187, 187);"> </div><div class="slimScrollRail" style="width: 7px; height: 100%; position: absolute; top: 0px; display: none; border-top-left-radius: 7px; border-top-right-radius: 7px; border-bottom-right-radius: 7px; border-bottom-left-radius: 7px; opacity: 0.2; z-index: 90; right: 1px; background: rgb(234, 234, 234);"> </div></div></li><li class="external"><a href="#">See all tasks <i class="m-icon-swapright"></i> </a></li></ul></li>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['metronic_notifications'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'metronic_themer_styler';
  $box->plugin_key = 'simple';
  $box->title = 'Theme Styler Box';
  $box->description = 'Theme Styler Box';
  $box->options = array(
    'body' => array(
      'value' => ' <div class="toggler">
    </div>
    <div class="toggler-close">
    </div>
    <div class="theme-options">
        <div class="theme-option theme-colors clearfix">
						<span>
						THEME COLOR </span>
            <ul>
                <li class="color-default current tooltips" data-style="default" data-original-title="Default">
                </li>
                <li class="color-darkblue tooltips" data-style="darkblue" data-original-title="Dark Blue">
                </li>
                <li class="color-blue tooltips" data-style="blue" data-original-title="Blue">
                </li>
                <li class="color-grey tooltips" data-style="grey" data-original-title="Grey">
                </li>
                <li class="color-light tooltips" data-style="light" data-original-title="Light">
                </li>
                <li class="color-light2 tooltips" data-style="light2" data-html="true" data-original-title="Light 2">
                </li>
            </ul>
        </div>
        <div class="theme-option">
						<span>
						Layout </span>
            <select class="layout-option form-control input-small">
                <option value="fluid" selected="selected">Fluid</option>
                <option value="boxed">Boxed</option>
            </select>
        </div>
        <div class="theme-option">
						<span>
						Header </span>
            <select class="page-header-option form-control input-small">
                <option value="fixed" selected="selected">Fixed</option>
                <option value="default">Default</option>
            </select>
        </div>
        <div class="theme-option">
						<span>
						Sidebar </span>
            <select class="sidebar-option form-control input-small">
                <option value="fixed">Fixed</option>
                <option value="default" selected="selected">Default</option>
            </select>
        </div>
        <div class="theme-option">
						<span>
						Sidebar Position </span>
            <select class="sidebar-pos-option form-control input-small">
                <option value="left" selected="selected">Left</option>
                <option value="right">Right</option>
            </select>
        </div>
        <div class="theme-option">
						<span>
						Footer </span>
            <select class="page-footer-option form-control input-small">
                <option value="fixed">Fixed</option>
                <option value="default" selected="selected">Default</option>
            </select>
        </div>
    </div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['metronic_themer_styler'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'quick_sidebar_box';
  $box->plugin_key = 'simple';
  $box->title = 'Quick Sidebar Box';
  $box->description = 'Quick Sidebar Box';
  $box->options = array(
    'body' => array(
      'value' => '<p><i class="icon-close"></i></p>

<div class="page-quick-sidebar-wrapper">
<div class="page-quick-sidebar">
<div class="nav-justified">
<ul class="nav nav-tabs nav-justified">
	<li class="active">Users <span class="badge badge-danger">2</span></li>
	<li>Alerts <span class="badge badge-success">7</span></li>
	<li class="dropdown">More<i class="fa fa-angle-down"></i>
	<ul class="dropdown-menu pull-right" role="menu">
		<li><i class="icon-bell"></i> Alerts</li>
		<li><i class="icon-info"></i> Notifications</li>
		<li><i class="icon-speech"></i> Activities</li>
		<li class="divider">&nbsp;</li>
		<li><i class="icon-settings"></i> Settings</li>
	</ul>
	</li>
</ul>

<div class="tab-content">
<div class="tab-pane active page-quick-sidebar-chat" id="quick_sidebar_tab_1">
<div class="page-quick-sidebar-chat-users" data-rail-color="#ddd" data-wrapper-class="page-quick-sidebar-list">
<h3 class="list-heading">Staff</h3>

<ul class="media-list list-items">
	<li class="media">
	<div class="media-status"><span class="badge badge-success">8</span></div>
	<img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar3.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Bob Nilson</h4>

	<div class="media-heading-sub">Project Manager</div>
	</div>
	</li>
	<li class="media"><img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar1.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Nick Larson</h4>

	<div class="media-heading-sub">Art Director</div>
	</div>
	</li>
	<li class="media">
	<div class="media-status"><span class="badge badge-danger">3</span></div>
	<img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar4.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Deon Hubert</h4>

	<div class="media-heading-sub">CTO</div>
	</div>
	</li>
	<li class="media"><img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar2.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Ella Wong</h4>

	<div class="media-heading-sub">CEO</div>
	</div>
	</li>
</ul>

<h3 class="list-heading">Customers</h3>

<ul class="media-list list-items">
	<li class="media">
	<div class="media-status"><span class="badge badge-warning">2</span></div>
	<img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar6.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Lara Kunis</h4>

	<div class="media-heading-sub">CEO, Loop Inc</div>

	<div class="media-heading-small">Last seen 03:10 AM</div>
	</div>
	</li>
	<li class="media">
	<div class="media-status"><span class="label label-sm label-success">new</span></div>
	<img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar7.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Ernie Kyllonen</h4>

	<div class="media-heading-sub">Project Manager,<br />
	SmartBizz PTL</div>
	</div>
	</li>
	<li class="media"><img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar8.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Lisa Stone</h4>

	<div class="media-heading-sub">CTO, Keort Inc</div>

	<div class="media-heading-small">Last seen 13:10 PM</div>
	</div>
	</li>
	<li class="media">
	<div class="media-status"><span class="badge badge-success">7</span></div>
	<img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar9.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Deon Portalatin</h4>

	<div class="media-heading-sub">CFO, H&amp;D LTD</div>
	</div>
	</li>
	<li class="media"><img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar10.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Irina Savikova</h4>

	<div class="media-heading-sub">CEO, Tizda Motors Inc</div>
	</div>
	</li>
	<li class="media">
	<div class="media-status"><span class="badge badge-danger">4</span></div>
	<img alt="..." class="media-object" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar11.jpg" />
	<div class="media-body">
	<h4 class="media-heading">Maria Gomez</h4>

	<div class="media-heading-sub">Manager, Infomatic Inc</div>

	<div class="media-heading-small">Last seen 03:10 AM</div>
	</div>
	</li>
</ul>
</div>

<div class="page-quick-sidebar-item">
<div class="page-quick-sidebar-chat-user">
<div class="page-quick-sidebar-nav"><i class="icon-arrow-left"></i>Back</div>

<div class="page-quick-sidebar-chat-user-messages">
<div class="post out"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar3.jpg" />
<div class="message"><span class="arrow"></span> Bob Nilson <span class="datetime">20:15</span> <span class="body"> When could you send me the report ? </span></div>
</div>

<div class="post in"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar2.jpg" />
<div class="message"><span class="arrow"></span> Ella Wong <span class="datetime">20:15</span> <span class="body"> Its almost done. I will be sending it shortly </span></div>
</div>

<div class="post out"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar3.jpg" />
<div class="message"><span class="arrow"></span> Bob Nilson <span class="datetime">20:15</span> <span class="body"> Alright. Thanks! :) </span></div>
</div>

<div class="post in"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar2.jpg" />
<div class="message"><span class="arrow"></span> Ella Wong <span class="datetime">20:16</span> <span class="body"> You are most welcome. Sorry for the delay. </span></div>
</div>

<div class="post out"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar3.jpg" />
<div class="message"><span class="arrow"></span> Bob Nilson <span class="datetime">20:17</span> <span class="body"> No probs. Just take your time :) </span></div>
</div>

<div class="post in"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar2.jpg" />
<div class="message"><span class="arrow"></span> Ella Wong <span class="datetime">20:40</span> <span class="body"> Alright. I just emailed it to you. </span></div>
</div>

<div class="post out"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar3.jpg" />
<div class="message"><span class="arrow"></span> Bob Nilson <span class="datetime">20:17</span> <span class="body"> Great! Thanks. Will check it right away. </span></div>
</div>

<div class="post in"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar2.jpg" />
<div class="message"><span class="arrow"></span> Ella Wong <span class="datetime">20:40</span> <span class="body"> Please let me know if you have any comment. </span></div>
</div>

<div class="post out"><img alt="" class="avatar" src="/sites/default/files/designssquare_com_theme_metronic/assets/admin/layout/img/avatar3.jpg" />
<div class="message"><span class="arrow"></span> Bob Nilson <span class="datetime">20:17</span> <span class="body"> Sure. I will check and buzz you if anything needs to be corrected. </span></div>
</div>
</div>

<div class="page-quick-sidebar-chat-user-form">
<div class="input-group"><input class="form-control" placeholder="Type a message here..." type="text" />
<div class="input-group-btn"><button class="btn blue" type="button"><i class="icon-paper-clip"></i></button></div>
</div>
</div>
</div>
</div>
</div>

<div class="tab-pane page-quick-sidebar-alerts" id="quick_sidebar_tab_2">
<div class="page-quick-sidebar-alerts-list">
<h3 class="list-heading">General</h3>

<ul class="feeds list-items">
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-info"><i class="fa fa-check"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">You have 4 pending tasks. <span class="label label-sm label-warning "> Take action <i class="fa fa-share"></i> </span></div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">Just now</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-success"><i class="fa fa-bar-chart-o"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">Finance Report for year 2013 has been released.</div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">20 mins</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-danger"><i class="fa fa-user"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">You have 5 pending membership that requires a quick review.</div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">24 mins</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-info"><i class="fa fa-shopping-cart"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">New order received with <span class="label label-sm label-success"> Reference Number: DR23923 </span></div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">30 mins</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-success"><i class="fa fa-user"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">You have 5 pending membership that requires a quick review.</div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">24 mins</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-info"><i class="fa fa-bell-o"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">Web server hardware needs to be upgraded. <span class="label label-sm label-warning"> Overdue </span></div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">2 hours</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-default"><i class="fa fa-briefcase"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">IPO Report for year 2013 has been released.</div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">20 mins</div>
	</div>
	</li>
</ul>

<h3 class="list-heading">System</h3>

<ul class="feeds list-items">
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-info"><i class="fa fa-check"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">You have 4 pending tasks. <span class="label label-sm label-warning "> Take action <i class="fa fa-share"></i> </span></div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">Just now</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-danger"><i class="fa fa-bar-chart-o"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">Finance Report for year 2013 has been released.</div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">20 mins</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-default"><i class="fa fa-user"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">You have 5 pending membership that requires a quick review.</div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">24 mins</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-info"><i class="fa fa-shopping-cart"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">New order received with <span class="label label-sm label-success"> Reference Number: DR23923 </span></div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">30 mins</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-success"><i class="fa fa-user"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">You have 5 pending membership that requires a quick review.</div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">24 mins</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-warning"><i class="fa fa-bell-o"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">Web server hardware needs to be upgraded. <span class="label label-sm label-default "> Overdue </span></div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">2 hours</div>
	</div>
	</li>
	<li>
	<div class="col1">
	<div class="cont">
	<div class="cont-col1">
	<div class="label label-sm label-info"><i class="fa fa-briefcase"></i></div>
	</div>

	<div class="cont-col2">
	<div class="desc">IPO Report for year 2013 has been released.</div>
	</div>
	</div>
	</div>

	<div class="col2">
	<div class="date">20 mins</div>
	</div>
	</li>
</ul>
</div>
</div>

<div class="tab-pane page-quick-sidebar-settings" id="quick_sidebar_tab_3">
<div class="page-quick-sidebar-settings-list">
<h3 class="list-heading">General Settings</h3>

<ul class="list-items borderless">
	<li>Enable Notifications <input checked="checked" class="make-switch" data-off-color="default" data-off-text="OFF" data-on-color="success" data-on-text="ON" data-size="small" type="checkbox" /></li>
	<li>Allow Tracking <input class="make-switch" data-off-color="default" data-off-text="OFF" data-on-color="info" data-on-text="ON" data-size="small" type="checkbox" /></li>
	<li>Log Errors <input checked="checked" class="make-switch" data-off-color="default" data-off-text="OFF" data-on-color="danger" data-on-text="ON" data-size="small" type="checkbox" /></li>
	<li>Auto Sumbit Issues <input class="make-switch" data-off-color="default" data-off-text="OFF" data-on-color="warning" data-on-text="ON" data-size="small" type="checkbox" /></li>
	<li>Enable SMS Alerts <input checked="checked" class="make-switch" data-off-color="default" data-off-text="OFF" data-on-color="success" data-on-text="ON" data-size="small" type="checkbox" /></li>
</ul>

<h3 class="list-heading">System Settings</h3>

<ul class="list-items borderless">
	<li>Security Level <select class="form-control input-inline input-sm input-small"><option value="1">Normal</option><option selected="selected" value="2">Medium</option><option value="e">High</option> </select></li>
	<li>Failed Email Attempts <input class="form-control input-inline input-sm input-small" value="5" /></li>
	<li>Secondary SMTP Port <input class="form-control input-inline input-sm input-small" value="3560" /></li>
	<li>Notify On System Error <input checked="checked" class="make-switch" data-off-color="default" data-off-text="OFF" data-on-color="danger" data-on-text="ON" data-size="small" type="checkbox" /></li>
	<li>Notify On SMTP Error <input checked="checked" class="make-switch" data-off-color="default" data-off-text="OFF" data-on-color="warning" data-on-text="ON" data-size="small" type="checkbox" /></li>
</ul>

<div class="inner-content"><button class="btn btn-success"><i class="icon-settings"></i> Save Changes</button></div>
</div>
</div>
</div>
</div>
</div>
</div>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['quick_sidebar_box'] = $box;

  return $export;
}
