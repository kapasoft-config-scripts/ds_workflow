<?php if (isset($gallery_view_tapi['views_title']) && !empty($gallery_view_tapi['views_title'])): ?>
    <!--    <div class="col-sm-12">-->
    <h3><?php print $gallery_view_tapi['views_title']; ?></h3>
    <!--    </div>-->
<?php endif ?>
<?php if ($rows): ?>
    <?php print render($rows); ?>
<?php endif; ?>