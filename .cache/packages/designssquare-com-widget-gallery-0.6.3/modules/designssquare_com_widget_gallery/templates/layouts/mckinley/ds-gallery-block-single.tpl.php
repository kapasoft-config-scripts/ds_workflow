<?php
/**
$gallery_tapi['url']::[STRING];<br>
$gallery_tapi['title']::[STRING];<br>
$gallery_tapi['featured_img']::[ARRAY];<br>
$gallery_tapi['featured_img']['url']::[STRING];<br>
$gallery_tapi['featured_img']['alt']::[STRING];<br>
$gallery_tapi['summary']::[STRING]<br>
$gallery_tapi['ds_contextual_links']::[RENDERABLE_ARRAY]<br>
 */
?>
<li class="clone" style="width: 270px; float: left; display: block;">
    <div class="thumb-gallery">
        <a href="<?php print $gallery_tapi['url']?>">
            <img
                 src="<?php print $gallery_tapi['featured_img']['url']?>"
                 class="attachment-featured_gallery_thumb"
                 alt="07"
                <?php print $gallery_tapi['styles']['block_thumb']['style']?>
                >
        </a>
    </div>
    <h4><?php print $gallery_tapi['title'] ?></h4>
</li>
