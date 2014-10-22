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

<div class="tagcloud">
    <?php foreach ($view->result as $id => $row): ?>
      <?php
        print '<a href="/'.taxonomy_term_uri($row->_entity_properties['entity object'])['path'].'" class="tag-link-' . $row->node_taxonomy_index_nid . '" title="'. $row->node_taxonomy_index_nid .' topics" style="font-size: ' .($row->node_taxonomy_index_nid/2 + 8) .'pt;">'.$row->taxonomy_term_data_name.'</a>';
      ?>
    <?php endforeach; ?>
</div>
