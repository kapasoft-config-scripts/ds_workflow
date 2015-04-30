<?php
/**
 * For click-focus functionality to work, the main focus image needs to have an id = "focus-image" and
 * the clickable images needs to have class="ds_portfolio_image"
 *
 * Here is available TAPI:
 *      $vars_tapi:  the Drupal $variable
 *      $gallery_tapi:  the DS Portfolio gallery TAPI
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

<div class="row">
    <div class="col-sm-12">
        <div class="col-sm-12 col-md-8">
            <div class="row">
                <div class="col-sm-12 portfolio-large"><img
                        src="<?php print $gallery_tapi['featured_img']['url'];?>"
                        alt="<?php print $gallery_tapi['featured_img']['alt']; ?>"
                        class="thumbnail img-responsive" id="focus-image"
                        ></div>
            </div>
            <div class="row hidden-sm ds-gallery-node">
                <?php foreach($gallery_tapi['gallery_img'] as $gallery_img): ?>
                    <div class="col-sm-3 portfolio-thumb-small">
                        <a href="#"><img
                                src="<?php print $gallery_img['url'];?>"
                                alt="<?php print $gallery_img['alt'];?>"
                                class="thumbnail img-responsive ds_portfolio_image"
                                <?php print $gallery_tapi['styles']['node_thumb']['style']?>
                                ></a>
                    </div>
                <?php endforeach ?>
            </div>
        </div>
        <div class="col-sm-12 col-md-3 gallery-info">
            <ul class="pager">
                <?php if($gallery_tapi['index']['previous']['is_present']):?>
                <li class="previous">
                    <a href="<?php print $gallery_tapi['index']['previous']['url']?>">&larr; <?php print $gallery_tapi['index']['previous']['text']?></a>
                </li>
                <?php endif ?>
                <?php if($gallery_tapi['index']['next']['is_present']):?>
                <li class="next">
                    <a href="<?php print $gallery_tapi['index']['next']['url']?>"><?php print $gallery_tapi['index']['next']['text']?> &rarr;</a>
                </li>
                <?php endif ?>
            </ul>
            <h2><?php print $gallery_tapi['title'];?></h2>
            <?php print $gallery_tapi['content']?>
            <p><i class="icon-list icon-white"></i> <strong>Categories:</strong>
                <?php foreach($gallery_tapi['categories']['collection'] as $cat): ?>
                        <a href="<?php print $cat['url'] ?>"><?php print $cat['name'] ?>
                            <?php if(!$cat['is_last']) :?>
                              ,
                            <?php endif ?>
                        </a>
                <?php endforeach?>
            </p>
            <p><i class="icon-tag icon-white"></i> <strong>Tags:</strong>
                <?php foreach($gallery_tapi['tags']['collection'] as $tag): ?>
                    <a href="<?php print $tag['url'] ?>"><?php print $tag['name'] ?>
                        <?php if(!$tag['is_last']) :?>
                        ,
                        <?php endif ?>
                    </a>
                <?php endforeach?>
            </p>
        </div>
        <div style = "clear:both"></div>
        <?php
        // We hide the comments and links now so that we can render them later.
        hide($vars_tapi['comments']);
        hide($vars_tapi['links']);
        print render($vars_tapi['content']);
        ?>

        <?php print render($vars_tapi['links']); ?>

        <?php print render($vars_tapi['comments']); ?>
    </div><!--End content in middle-->

</div>


