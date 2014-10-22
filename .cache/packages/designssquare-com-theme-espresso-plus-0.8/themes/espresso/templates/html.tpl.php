<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces;?>>
<head profile="<?php print $grddl_profile; ?>">
  <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>

    <!-- Favicon -->
    <link rel="shortcut icon" href="img/favicon.ico">
    <!-- IE -->
    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <?php print '<script src="'.base_path().path_to_theme().'/js/html5shiv.js"></script>'."\n";?>
        <?php print '<script src="'.base_path().path_to_theme().'/js/respond.min.js"></script>'."\n";?>
    <![endif]-->
    <!--[if lte IE 8]>
    <?php print '<link href="'.base_path().path_to_theme().'/css/ie8.css" rel="stylesheet">'."\n";?>
    <![endif]-->
<!--    <link href="http://fonts.googleapis.com/css?family=Oswald:400,700" rel="stylesheet" type="text/css">-->

</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
<!--  <div id="skip-link">-->
<!--    <a href="#main-content" class="element-invisible element-focusable">--><?php //print t('Skip to main content'); ?><!--</a>-->
<!--  </div>-->
  <?php print $page_top; ?>
    <div class="main-container container">
        <?php include path_to_theme() .'/templates/section--header.php';?>

        <?php print $page; ?>

        <?php include path_to_theme() .'/templates/section--footer.php';?>
    </div><!--end of main-container--->
<!-- Background Image -->
<div class="background">
    <img src="<?php print $espresso_bg_img; ?>" class="image" alt="background">
</div>
  <?php print $page_bottom; ?>
</body>
</html>
