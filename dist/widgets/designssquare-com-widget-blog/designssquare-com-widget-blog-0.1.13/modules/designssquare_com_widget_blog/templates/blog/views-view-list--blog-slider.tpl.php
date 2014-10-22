<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>

<?php
print '<h3>' .$view->display[$view->current_display]->display_title. '</h3>';
print '            <div class="slider">';
    print '                <div class="flexslider">';
        print '                    <ul class="slides">';
?>

<?php foreach ($view->result as $id => $row): ?>
    <?php print $row->blog_slide;?>
<?php endforeach; ?>

<?php
print '</ul>';
print '<!-- FlexSlider Nav -->';
print '<ul class="flex-direction-nav">';
print '    <li><a href="#" class="flex-prev"></a></li>';
print '    <li><a href="#" class="flex-next"></a>';
print '</ul>';
print '<!-- End FlexSlider Nav -->';
print '</div>';
print '</div>';
?>

