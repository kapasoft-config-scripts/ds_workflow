<?php if (isset($gallery_view_tapi['views_title']) && !empty($gallery_view_tapi['views_title'])): ?>
    <h3 style="color: rgb(217, 217, 217);"><?php print $gallery_view_tapi['views_title'];?></h3>
<?php endif ?>
<?php if ($rows): ?>
    <?php print render($rows); ?>
<?php endif; ?>

