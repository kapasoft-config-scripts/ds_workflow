 <!-- BEGIN HEADER -->
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
    <?php print $header_tapi['user-menu']?>
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
<!-- END HEADER -->