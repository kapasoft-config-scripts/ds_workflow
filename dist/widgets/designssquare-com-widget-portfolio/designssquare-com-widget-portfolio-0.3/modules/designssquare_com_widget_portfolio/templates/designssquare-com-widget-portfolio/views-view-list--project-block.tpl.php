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


                  <?php foreach ($view->result as $id => $row): ?>
                      <div class="col-sm-4">
                          <a href="<?php print $row->project_tapi['url'] ?>" class="thumbnail img-responsive">
                              <img src="<?php print $row->project_tapi['featured_img']['url'] ?>"  alt="<?php print $row->project_tapi['featured_img']['alt'] ?>">
                          </a>
                      </div>
                  <?php endforeach; ?>
<div style="clear:both"></div>
