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

<div class="tabbable tabbable-custom boxless">
    <!--<div class="col-sm-12">-->
    <div class="tab-content">
        <div class="tab-pane active" id="tab_1">
            <div class="margin-top-10">
                <ul class="mix-filter">
                    <li class="filter" data-filter="all">
                        All
                    </li>
                    <?php foreach ($gallery_tapi['items_tags']['collection'] as $tag) : ?>
                        <li class="filter" data-filter="<?php print $tag['safe_name'] ?>">
                            <?php print $tag['name'] ?>
                        </li>
                    <?php endforeach; ?>
                </ul>
                <div class="row mix-grid ds-gallery-node">
                    <?php foreach($gallery_tapi['items_tapi'] as $item): ?>
                        <div class="col-md-6 col-sm-6 mix <?php print $item['tags']['flatten_names'] ?>"
                            <?php print $gallery_tapi['styles']['node_thumb']['ui_style']?>
                            >
                            <div class="mix-inner">
                                <?php if($item['has_picture']) : ?>
                                    <img
                                        <?php if(empty($gallery_tapi['styles']['node_thumb']['ui_style'])):?>
                                            class="img-responsive"
                                        <?php endif;?>
                                        src="<?php print $item['picture']['url']?>"
                                        alt=""
                                        <?php print $gallery_tapi['styles']['node_thumb']['style']?>
                                        >
                                    <div class="mix-details"
                                        <?php print $gallery_tapi['styles']['node_thumb']['style']?>
                                        >
                                        <h4><?php print $item['title']?></h4>
                                        <a class="mix-preview fancybox-button" href="<?php print $item['picture']['url']?>"
                                           title="<?php print $item['title']?>" data-rel="fancybox-button">
                                            <i class="fa fa-search"></i>
                                        </a>
                                    </div>
                                <?php elseif($item['has_video'] && $item['video']['is_frame']) :?>
                                    <?php print $item['video']['content'] ?>
                                    <div class="mix-details"
                                        <?php print $gallery_tapi['styles']['node_thumb']['style']?>
                                        >
                                        <h4><?php print $item['title']?></h4>
                                        <a class="mix-preview fancybox-button" data-fancybox-type="iframe" href="<?php print $item['video']['url']?>"
                                           title="<?php print $item['title']?>" data-rel="fancybox-button">
                                            <i class="fa fa-search"></i>
                                        </a>
                                    </div>
                                <?php endif;?>
                            </div>
                        </div>
                    <?php endforeach; ?>
                </div>
            </div>
            <!-- END FILTER -->
        </div>
    </div>
</div>

<?php
// We hide the comments and links now so that we can render them later.
hide($vars_tapi['content']['comments']);
hide($vars_tapi['content']['links']);
print render($vars_tapi['content']);
?>

<?php print render($vars_tapi['content']['links']); ?>

<?php print render($vars_tapi['content']['comments']); ?>
