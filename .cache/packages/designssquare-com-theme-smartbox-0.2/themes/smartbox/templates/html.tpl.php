<!DOCTYPE html>
<!--[if IE 8 ]> <html lang="en" class="ie8"> <![endif]-->
<!--[if (gt IE 8)]><!--> <html lang="en"> <!--<![endif]-->
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces;?>>
<head profile="<?php print $grddl_profile; ?>">
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta content="Bootsrap based theme" name="description">
    <meta content="width=device-width, initial-scale=1.0" name="viewport">
    <meta content="yes" name="apple-mobile-web-app-capable">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
    <link href="favicon.ico" rel="shortcut icon">
    <link href="<?php print base_path() . path_to_theme()?>/smartbox/images/head/apple-touch-icon-144x144-precomposed.png" rel="apple-touch-icon-precomposed" sizes="144x144">
    <link href="<?php print base_path() . path_to_theme()?>/smartbox/images/head/apple-touch-icon-114x114-precomposed.png" rel="apple-touch-icon-precomposed" sizes="114x114">
    <link href="<?php print base_path() . path_to_theme()?>/smartbox/images/head/apple-touch-icon-72x72-precomposed.png" rel="apple-touch-icon-precomposed" sizes="72x72">
    <link href="<?php print base_path() . path_to_theme()?>/smartbox/images/head/apple-touch-icon-57x57-precomposed.png" rel="apple-touch-icon-precomposed">
  <?php print $styles; ?>
  <!-- HTML5 element support for IE6-8 -->
    <!--[if lt IE 9]>
    <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <?php print '<script src="' . base_path() . path_to_theme(). '/smartbox/head/javascripts/PIE.js"></script>';?>
    <![endif]-->
  <?php print $scripts; ?>
</head>
<body
    class="<?php print $classes; ?>"
    <?php print $attributes;?>
    <?php if($html_tapi['page_bg']['is_enabled']):?>
        data-background-size="full" data-background="#2d3039 url(<?php print $html_tapi['page_bg']['url'];?>) no-repeat top"
    <?php endif; ?>
    >
  <?php print $page_top; ?>
  <div class="wrapper">
      <?php print $header ?>
      <!-- Main Content -->
      <div id="content" role="main">
      <?php print $page; ?>
      </div>
  </div>
  <?php print $footer ?>
  <?php print $page_bottom; ?>
</body>
</html>
