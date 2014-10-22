    <!--WELCOME AREA-->
    <div class="tag_line">
        <div class="container">

            <div class="row">
                <div class="span12">

                    <div class="welcome">
                        <?php if (!empty($node->title)): ?>
                        <h3><span class="colored"><?php print $node->title; ?></span></h3>
                        <?php endif; ?>
                        <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
                    </div>

                    <?php print render($page['header']); ?>
                </div>
            </div>
        </div>
    </div>

    <!--/WELCOME AREA-->
    <!--MAIN CONTENT AREA-->
    <div class="main_content_area">
        <div class="container">
    <?php print $messages; ?>
    <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
    <?php endif; ?>
    <?php if (!empty($page['help'])): ?>
        <div class="well"><?php print render($page['help']); ?></div>
    <?php endif; ?>
    <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>

            <div class="row">
                <div class="span12">
                    <div class="row">
                        <?php if (!empty($page['sidebar_first'])): ?>
                            <div class="span3 page_sidebar">
                                <?php print render($page['sidebar_first']); ?>
                            </div>  <!-- /#sidebar-first -->
                        <?php endif; ?>
                        <div class="span9">
                                <?php print render($page['content']); ?>
                        </div>
                        <?php if (!empty($page['sidebar_second'])): ?>
                            <div class="span3 page_sidebar">
                                <?php print render($page['sidebar_second']); ?>
                            </div>  <!-- /#sidebar-second -->
                        <?php endif; ?>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <!--END MAIN CONTENT AREA-->
    <!--FOOTER-->

    <!-- START TWITTER FEED -->
    <div class="twitter-block">
        <?php print render($page['footer_top']); ?>
    </div>
    <!-- END TWITTER FEED -->

    <!-- START WIDGET AREA AND SOCIAL ICONS -->
    <div class="footer">
        <?php print render($page['footer_middle']); ?>
    </div>
    <!-- END WIDGET AREA AND SOCIAL ICONS -->

    <!--START BOTTOM LINE-->
    <div class="bottom_line">
        <?php print render($page['footer_bottom']); ?>
    </div>
    <!--END BOTTOM LINE-->
    <!--END FOOTER-->

    <!-- Le javascript
    ================================================== -->
    <!-- Placed at the end of the document so the pages load faster -->
<?php
//    echo '<script src="'. base_path().path_to_theme() .'/js/jquery.tweet.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/google-code-prettify/prettify.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/bootstrap.min.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/jquery.easing.1.3.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/superfish-menu/superfish.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/jquery.nivo.slider.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/jquery.prettyPhoto.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/jflickrfeed.min.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/testimonialrotator.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/jquery.waitforimages.js"></script>';
//    echo '<script src="'. base_path().path_to_theme() .'/js/jquery.isotope.min.js"></script>';
?>

    <?php //echo '<script src="'. base_path().path_to_theme() .'/js/custom.js"></script>';?>

<?php
//echo <<<'EOT'
//    <script>
//        /***************************************************
//         TWITTER FEED
//         ***************************************************/
//        jQuery.noConflict()(function ($) {
//            $(document).ready(function () {
//
//                $(".tweet").tweet({
//                    count: 1,
//                    username: "Orange_Idea_RU",
//                    loading_text: "loading twitter..."
//                });
//            });
//        });
//    </script>
//EOT;
?>
