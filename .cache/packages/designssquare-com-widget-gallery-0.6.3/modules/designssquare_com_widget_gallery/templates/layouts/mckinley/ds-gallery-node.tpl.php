<?php
/**
 * For click-focus functionality to work, the main focus image needs to have an id = "focus-image" and
 * the clickable images needs to have class="ds_portfolio_image"
 *
 * Here is available TAPI:
 *      $vars_tapi:  the Drupal $variable
 *      $gallery_tapi:  the DS Portfolio gallery TAPI
 * $gallery_tapi['url']::[STRING];<br>
$gallery_tapi['title']::[STRING];<br>
$gallery_tapi['featured_img']::[ARRAY];<br>
$gallery_tapi['featured_img']['url']::[STRING];<br>
$gallery_tapi['featured_img']['alt']::[STRING];<br>
$gallery_tapi['summary']::[STRING]<br>
$gallery_tapi['ds_contextual_links']::[RENDERABLE_ARRAY]<br>
$gallery_tapi['content']::[STRING];
$gallery_tapi['index']::[ARRAY];
$gallery_tapi['index']['next']::[ARRAY];
$gallery_tapi['index']['next']['url']::[STRING];
$gallery_tapi['index']['next']['text']::[STRING];
$gallery_tapi['index']['previous']::[ARRAY];
$gallery_tapi['index']['previous']['text']::[STRING];
$gallery_tapi['index']['previous']['url']::[STRING];
$gallery_tapi['gallery_img']::[ARRAY];
$gallery_tapi['gallery_img']['N']::[ARRAY];
$gallery_tapi['gallery_img']['N']['url']::[STRING];
$gallery_tapi['gallery_img']['N']['alt']::[STRING];
$gallery_tapi['tags']::[ARRAY](array of tags)
$gallery_tapi['tags']['all_names']::[ARRAY](array of all tags names)
$gallery_tapi['tags']['flattened_names']::[STRING](string of all safe tags names separated by space)
$gallery_tapi['tags']['collection']::[ARRAY](array of tag elements with key of safe_name)
$gallery_tapi['tags']['collection'][SAFE_NAME]::[ARRAY];
$gallery_tapi['tags']['collection'][SAFE_NAME]['name']::[STRING]
$gallery_tapi['tags']['collection'][SAFE_NAME]['url']::[STRING]
$gallery_tapi['tags']['collection'][SAFE_NAME]['is_last']::[BOOLEAN]
$gallery_tapi['categories']::[ARRAY](array of categories)
$gallery_tapi['categories']['all_names']::[ARRAY](array of all category names)
$gallery_tapi['categories']['flattened_names']::[STRING](string of all safe category names separated by space)
$gallery_tapi['categories']['collection']::[ARRAY](array of category elements with key of safe_name)
$gallery_tapi['categories']['collection'][SAFE_NAME]::[ARRAY];
$gallery_tapi['categories']['collection'][SAFE_NAME]['name']::[STRING]
$gallery_tapi['categories']['collection'][SAFE_NAME]['url']::[STRING];
$gallery_tapi['categories']['collection'][SAFE_NAME]['is_last']::[BOOLEAN]
 */
?>
<div class="posts">
<div id="post-" class="hentry-post group portfolio-post internal-post">
<!--<div class="row">-->
    <div id="portfolio" class="portfolio-full-description portfolio-full-big">
        <!-- START BIG LAYOUT -->
        <div class="page type-page status-publish hentry work group row">
            <div class="work-thumbnail col-md-12">
                <div class="thumb-wrapper">


                    <div class="work-thumbnail">
                        <div class="picture_overlay">
                            <img
                                src="<?php print $gallery_tapi['featured_img']['url'] ?>"
                                title="01"
                                class=" img-responsive thumbnail yit-image attachment-thumb_portfolio_fulldesc_big"
                                <?php print $gallery_tapi['styles']['node_thumb']['style']?>
                                >

<!--                            <div class="overlay">-->
<!--                                <div style="margin-top: -18.5px; margin-left: -18.5px;">-->
<!--                                    <p>-->
<!--                                        <a href="http://wp-bazar/wp-content/uploads/2013/01/0113.jpg" rel="lightbox_fulldesc" class="lightbox_fulldesc cboxElement"><img src="http://wp-bazar/wp-content/themes/bazar/images/icons/zoom.png" alt="Open Lightbox"></a>-->
<!--                                    </p>-->
<!--                                </div>-->
<!--                            </div>-->
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div class="row">
            <div class="work-description col-md-8" style="float:left;position:relative">
                <h3><?php print $gallery_tapi['title'] ?></h3>
                <?php print print $gallery_tapi['content']?>
            </div>
            <div class="work-skillsdate col-md-3" style="float:right;position:relative">
            <?php //print $gallery_tapi['details']?>
            </div>
            </div>
            <div class="clear"></div>
        </div>
        <!-- START SMALL LAYOUT -->

        <div class="clear"></div>
        <div id="ds-effect-5" class="ds-effects clearfix portfolio-full-description-related-gallerys row">
            <?php foreach($gallery_tapi['gallery_img'] as $gallery) :?>
            <div class="ds-img related_gallery col-sm-3" style="border-color: #e0dfdf;">
                        <img src="<?php print $gallery['url'] ?>" title="02" class="img-responsive thumbnail ds_gallery_extra_img">
                     <div class="ds-overlay">
                        <a href="<?php print $gallery['url'] ?>" rel="lightbox" class="ds-expand ch-info-lightbox ds_cboxElement">
                            x
                        </a>
                     </div>
            </div>
            <?php endforeach; ?>
            <script>
                jQuery('a.ds_cboxElement').colorbox();
            </script>
        </div>
    <?php
        // We hide the comments and links now so that we can render them later.
        hide($vars_tapi['content']['comments']);
        hide($vars_tapi['content']['links']);
        print render($vars_tapi['content']);
      ?>

        <?php print render($vars_tapi['content']['links']); ?>

        <?php print render($vars_tapi['content']['comments']); ?>
    </div><!--End content in middle-->

</div>

</div>
