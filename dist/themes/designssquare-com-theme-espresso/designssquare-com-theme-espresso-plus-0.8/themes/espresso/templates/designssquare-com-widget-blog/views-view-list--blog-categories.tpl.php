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

<ul class="nav">
    <?php foreach ($view->result as $id => $row): ?>
      <?php
           print '<li>';
           print       '<a href="/'.taxonomy_term_uri($row->_entity_properties['entity object'])['path'].'"><span class="glyphicon glyphicon-list"></span> '.$row->_entity_properties['entity object']->name.'</a>';
           print '</li>';
      ?>
    <?php endforeach; ?>
</ul>
