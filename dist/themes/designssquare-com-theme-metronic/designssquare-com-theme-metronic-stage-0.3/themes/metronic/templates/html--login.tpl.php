<!DOCTYPE html>
<!--[if IE 8]> <html lang="en" class="ie8 no-js"> <![endif]-->
<!--[if IE 9]> <html lang="en" class="ie9 no-js"> <![endif]-->
<!--[if !IE]><!-->
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces;?> class="no-js">
<!--<![endif]-->
<!-- BEGIN HEAD -->
<head profile="<?php print $grddl_profile; ?>">
  <meta charset="utf-8">
    <meta content="width=device-width, initial-scale=1" name="viewport"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $scripts; ?>
    <?php print $styles; ?>


    <!-- END THEME STYLES -->
    <link rel="shortcut icon" href="favicon.ico"/>
</head>
<!-- DOC: Apply "page-header-fixed-mobile" and "page-footer-fixed-mobile" class to body element to force fixed header or footer in mobile devices -->
<!-- DOC: Apply "page-sidebar-closed" class to the body and "page-sidebar-menu-closed" class to the sidebar menu element to hide the sidebar by default -->
<!-- DOC: Apply "page-sidebar-hide" class to the body to make the sidebar completely hidden on toggle -->
<!-- DOC: Apply "page-sidebar-closed-hide-logo" class to the body element to make the logo hidden on sidebar toggle -->
<!-- DOC: Apply "page-sidebar-hide" class to body element to completely hide the sidebar on sidebar toggle -->
<!-- DOC: Apply "page-sidebar-fixed" class to have fixed sidebar -->
<!-- DOC: Apply "page-footer-fixed" class to the body element to have fixed footer -->
<!-- DOC: Apply "page-sidebar-reversed" class to put the sidebar on the right side -->
<!-- DOC: Apply "page-full-width" class to the body element to have full width page without the sidebar menu -->
<body class="login">


<div class="logo">
    <a href="/">
        <img src="<?php print $header_tapi['logo']['path']?>" alt=""/>
    </a>
</div>
<!-- END LOGO -->
<!-- BEGIN SIDEBAR TOGGLER BUTTON -->
<div class="menu-toggler sidebar-toggler">
</div>
<!-- END SIDEBAR TOGGLER BUTTON -->
<!-- BEGIN LOGIN -->
<div class="content">
<!-- BEGIN LOGIN FORM -->
    <?php print $page; ?>
<!-- END REGISTRATION FORM -->
</div>
<!-- END LOGIN -->
<!-- BEGIN COPYRIGHT -->
<div class="copyright">
    <?php print render($variables['region']['login_footer'])?>
</div>
<script>
    window.$ = window.jQuery;
</script>
  <!--[if lt IE 9]>
  <script src="<?php print base_path().path_to_theme() ?>/assets/global/plugins/respond.min.js"></script>
  <script src="<?php print base_path().path_to_theme() ?>/assets/global/plugins/excanvas.min.js"></script>
  <![endif]-->
  <?php print $page_bottom; ?>
</body>
</html>
