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
      <?php
            $path_alias = drupal_get_path_alias('node/'.$row->nid);
            print '<li><a href="'.base_path().$path_alias.'" title="' . $row->node_title . '" class="bg-link">'.$row->node_title.'</a>';
            print '        <div class="small-meta">'.format_date($row->node_created, 'medium', 'd M Y').' / <a href="'.base_path(). $path_alias .'" title="Comment on ' . $row->node_title . '">' . $row->node_comment_statistics_comment_count  . ' Comment</a></div>';
            print '        <!-- /small-meta -->';
            print '        <div class="clear"></div>';
            print '</li>';

            ?>
<?php endforeach; ?>
