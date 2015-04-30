<?php if (isset($gallery_view_tapi['views_title']) && !empty($gallery_view_tapi['views_title'])): ?>
        <div class="col-sm-12">
    <h3><?php print $gallery_view_tapi['views_title']; ?></h3>
        </div>
<?php endif ?>
<div class="flexslider <?php print $gallery_view_tapi['slider_tapi']['class']; ?>">
    <ul class="ds-gallery-direction-nav">
        <li><a href="#" class="ds-gallery-flex-prev"></a></li>
        <li><a href="#" class="ds-gallery-flex-next"></a></li>
    </ul>
      
    <ul class="slides">
        <?php print render($rows) ?>
    </ul>
</div>