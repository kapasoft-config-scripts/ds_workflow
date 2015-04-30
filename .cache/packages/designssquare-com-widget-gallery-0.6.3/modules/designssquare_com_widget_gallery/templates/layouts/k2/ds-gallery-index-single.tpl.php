<?php
/**
$gallery_tapi['url']::[STRING];<br>
$gallery_tapi['title']::[STRING];<br>
$gallery_tapi['featured_img']::[ARRAY];<br>
$gallery_tapi['featured_img']['url']::[STRING];<br>
$gallery_tapi['featured_img']['alt']::[STRING];<br>
$gallery_tapi['summary']::[STRING]<br>
$gallery_tapi['ds_contextual_links']::[RENDERABLE_ARRAY]<br>]
$gallery_tapi['content']::[STRING];<br>
$gallery_tapi['index']::[ARRAY];<br>
$gallery_tapi['index']['next']::[ARRAY];<br>
$gallery_tapi['index']['next']['url']::[STRING];<br>
$gallery_tapi['index']['next']['text']::[STRING];<br>
$gallery_tapi['index']['previous']::[ARRAY];<br>
$gallery_tapi['index']['previous']['text']::[STRING];<br>
$gallery_tapi['index']['previous']['url']::[STRING];<br>
$gallery_tapi['gallery_img']::[ARRAY];<br>
$gallery_tapi['gallery_img']['N']::[ARRAY];<br>
$gallery_tapi['gallery_img']['N']['url']::[STRING];<br>
$gallery_tapi['gallery_img']['N']['alt']::[STRING];<br>
$gallery_tapi['tags']::[ARRAY](array of tags)<br>
$gallery_tapi['tags']['all_names']::[ARRAY](array of all tags names)<br>
$gallery_tapi['tags']['flattened_names']::[STRING](string of all safe tags names separated by space)<br>
$gallery_tapi['tags']['collection']::[ARRAY](array of tag elements with key of safe_name)<br>
$gallery_tapi['tags']['collection'][SAFE_NAME]::[ARRAY];<br>
$gallery_tapi['tags']['collection'][SAFE_NAME]['name']::[STRING]<br>
$gallery_tapi['tags']['collection'][SAFE_NAME]['url']::[STRING]<br>
$gallery_tapi['tags']['collection'][SAFE_NAME]['is_last']::[BOOLEAN]<br>
$gallery_tapi['categories']::[ARRAY](array of categories)<br>
$gallery_tapi['categories']['all_names']::[ARRAY](array of all category names)<br>
$gallery_tapi['categories']['flattened_names']::[STRING](string of all safe category names separated by space)<br>
$gallery_tapi['categories']['collection']::[ARRAY](array of category elements with key of safe_name)<br>
$gallery_tapi['categories']['collection'][SAFE_NAME]::[ARRAY];<br>
$gallery_tapi['categories']['collection'][SAFE_NAME]['name']::[STRING]<br>
$gallery_tapi['categories']['collection'][SAFE_NAME]['url']::[STRING];<br>
$gallery_tapi['categories']['collection'][SAFE_NAME]['is_last']::[BOOLEAN]<br>

 */
?>
<div class="contextual-links-region col-md-3 col-sm-4 mix <?php print $gallery_tapi['categories']['flattened_names'] ?>"
    <?php print $gallery_tapi['styles']['index_thumb']['ui_style']?>
    >
    <?php print render($gallery_tapi['ds_contextual_links']);?>
    <div class="mix-inner">
        <img
            <?php if(empty($gallery_tapi['styles']['index_thumb']['ui_style'])):?>
                class="img-responsive"
            <?php endif;?>
            src="<?php print $gallery_tapi['featured_img']['url']?>"
            alt=""
            <?php print $gallery_tapi['styles']['index_thumb']['style']?>
            >

        <div class="mix-details">
            <h4><?php print $gallery_tapi['title']?></h4>
            <div class='preview-links '>
            <a class="mix-link preview-link" href="<?php print $gallery_tapi['url'];?>">
                <i class="fa fa-link"></i>
            </a>
            <a class="mix-preview fancybox-button preview-link" href="<?php print $gallery_tapi['featured_img']['url']?>"
               title="<a href='<?php print $gallery_tapi['url']?>'><?php print $gallery_tapi['title'] ?></a>" data-rel="fancybox-button">
                <i class="fa fa-search"></i>
            </a>
            </div>
        </div>
    </div>
</div>

