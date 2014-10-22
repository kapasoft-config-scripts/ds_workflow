<h3><?php print $view->display[$view->current_display]->display_title; ?></h3>
    <div class="flexslider <?php print $slider_tapi['class']; ?>">
        <ul class="ds-blog-direction-nav">
            <li><a href="#" class="ds-blog-flex-prev" style="top:<?php print $slider_tapi['nav_left_top']?>;right:<?php print $slider_tapi['nav_left_offset']; ?>"></a></li>
            <li><a href="#" class="ds-blog-flex-next" style="top:<?php print $slider_tapi['nav_right_top']?>;right:<?php print $slider_tapi['nav_right_offset']; ?>"></a></li>
        </ul>
        <ul class="slides">

<?php foreach ($view->result as $id => $row): ?>
    <?php print $row->blog_slide;?>
<?php endforeach; ?>

        </ul>
</div>