<!--
Designssquare.com Template API template file - header.tpl.php with following TAPI:
1. $header_tapi
   - array of header items with following API:
                //logo img<br>
                $header_tapi['logo']['path']::[STRING]<br>
                $header_tapi['logo']['is_enabled']::[BOOLEAN] <br>
                //site info<br>
                $header_tapi['site']['name']::[STRING] <br>
                $header_tapi['site']['name_enabled']::[BOOLEAN] <br>
                $header_tapi['site']['front_url']::[STRING] <br>
                //slogan<br>
                $header_tapi['site_slogan']['text']::[STRING] <br>
                $header_tapi['site_slogan']['is_enabled']::[STRING] <br>
                //user<br>
                $header_tapi['user']::[ARRAY] everything from User TAPI(_user_tapi()) <br>
                $header_tapi['user']['name']::[STRING]<br>
                $header_tapi['user']['avatar']['url']::[STRING] (url to profile img)<br>
                $header_tapi['user']['avatar']['width']::[STRING] (the width from image style "Avatar")<br>
                $header_tapi['user']['avatar']['height']::[STRING] (the height from image style "Avatar")<br>
                $header_tapi['user']['email']::[STRING]<br>
                $header_tapi['user']['link']['path']::[STRING](the path to user profile if registered user or login page for anonymous visitor )<br>
                $header_tapi['user']['link']['text']::[STRING](the name of User or anonymous name like ' Mate' as configured in <a href="#!/configuration">external configurations</a>)<br>
                $header_tapi['user']['login-link']['path']::[STRING](the path to login/logout )<br>
                $header_tapi['user']['logi-link']['text']::[STRING](the text for link to login/logout)<br>
                $header_tapi['user']['img']['url']::[STRING]<br>
                $header_tapi['user']['img']['width']::[STRING](the width from image style "User Profile")<br>
                $header_tapi['user']['img']['height']::[STRING](the height from image style "User Profile")<br>
                $header_tapi['user']['is_authenticated']::[STRING]
                //settings<br>
                $header_tapi['settings']::[STRING]
2. $vars_tapi
    - Drupal $variables passed on(regions in $vars_tapi['page']['region-id]')
-->

<div class="page-header navbar <?php print $header_tapi['class'];?>">
<!-- BEGIN HEADER INNER -->
<div class="page-header-inner <?php print $header_tapi['layout']; ?>">
<!-- BEGIN LOGO -->
<div class="page-logo">
    <a href="<?php print $header_tapi['site']['front_url']; ?>"  ><h3 style="margin-top:10px;margin-bottom:6px">
        <?php if ($header_tapi['logo']['is_enabled']): ?>
            <img src="<?php print $header_tapi['logo']['path'] ?>" alt="logo" class="logo-default" style="margin-top:0px;margin-bottom: 0px"/>
        <?php endif;?>
        <?php if($header_tapi['site']['name_enabled']) : ?>
            <?php print $header_tapi['site']['name'] ?>
        <?php endif;?>
        </h3>
    </a>

    <div class="menu-toggler sidebar-toggler hide">
        <!-- DOC: Remove the above "hide" to enable the sidebar toggler button on header -->
    </div>
</div>
<!-- END LOGO -->
<!-- BEGIN RESPONSIVE MENU TOGGLER -->
<a href="javascript:;" class="menu-toggler responsive-toggler" data-toggle="collapse" data-target=".navbar-collapse">
</a>
<!-- END RESPONSIVE MENU TOGGLER -->
<!-- BEGIN TOP NAVIGATION MENU -->
<div class="top-menu">
<ul class="nav navbar-nav pull-right">
    <?php print render($vars_tapi['page']['header'])?>
<!-- BEGIN USER LOGIN DROPDOWN -->
<li class="dropdown dropdown-user">
    <a href="#" class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" data-close-others="true">
        <img alt="" class="img-circle" src="<?php print $header_tapi['user']['avatar']['url'] ?>" style="width:<?php print $header_tapi['user']['avatar']['width']; ?>px;height: <?php print $header_tapi['user']['avatar']['height']; ?>px;"/>
					<span class="username">
					<?php print $header_tapi['user']['name']?> </span>
        <i class="fa fa-angle-down"></i>
    </a>
    <?php print render($vars_tapi['user_menu'])?>
</li>
<!-- END USER LOGIN DROPDOWN -->
<?php if($header_tapi['show_sidebar']): ?>
<!-- BEGIN QUICK SIDEBAR TOGGLER -->
<li class="dropdown dropdown-quick-sidebar-toggler">
    <a href="javascript:;" class="dropdown-toggle">
        <i class="icon-logout"></i>
    </a>
</li>
<!-- END QUICK SIDEBAR TOGGLER -->
<?php endif; ?>
</ul>
</div>
<!-- END TOP NAVIGATION MENU -->
</div>
<!-- END HEADER INNER -->
</div>
