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
            print '<li><a href="'.base_path().$path_alias.'" title="' . $row->node_title . '" ><span class="glyphicon glyphicon-list"></span>'.$row->node_title.'</a>';
            print '</li>';

            ?>
<?php endforeach; ?>
