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

<div class="flexslider <?php print $slider_tapi['class']; ?>">
    <ul class="ds-portfolio-direction-nav">
        <li><a href="#" class="ds-portfolio-flex-prev"></a></li>
        <li><a href="#" class="ds-portfolio-flex-next"></a></li>
    </ul>
     <ul class="slides">
                  <?php foreach ($view->result as $id => $row): ?>
                        <li>
                          <?php print $row->portfolio_project;?>
                        </li>
                  <?php endforeach; ?>

    </ul>

</div>


