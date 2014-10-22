<?php

/**
 * renders each post using templates either node--blog-teaser-big.tpl.php or node-blog-teaser-small.tpl.php
 * depending on the individual post format
 */
?>


        <?php foreach ($view->result as $id => $row): ?>
               <?php print $row->blog_entry;?>
        <?php endforeach; ?>
