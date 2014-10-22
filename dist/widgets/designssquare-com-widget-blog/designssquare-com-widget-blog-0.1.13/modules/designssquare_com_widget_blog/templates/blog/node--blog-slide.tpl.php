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
           print '             <li style="width: 573px; float: left; display: block;">';
           print '                 <div class="flex-caption blog_item">';
           print '                     <div class="blog_head">';
           print '                         <div class="date">';
           print '                             <h6><i class="icon-calendar icon-white"></i>'.$blog_entry['date']['full'].'</h6>';
           print '                         </div>';
           print '                         <h3><a href="' .$blog_entry['path_alias']. '">'.$blog_entry['title'].'</a></h3>';
           print '                     </div>';

           print '                     <div class="meta">';
           print '                         <span><b>By</b> <a href="">'. $blog_entry['author'] . '</a></span>';
           print '                         <span><a href="'.$blog_entry['path_alias'].'">Post tags</a></span>';
           print '                         <span class="last-item"><a href="'.$blog_entry['path_alias'].'">'. $blog_entry['comment_count'] .' Comments</a></span>';
           print '                     </div>';
           print views_trim_text(array('max_length' => 150), $blog_entry['body']).'...';
           print '                     <h6 class="read_more" style="margin-top: 10px !important;">';
           print '                         <a style="margin-top: 15px;" href="'.$blog_entry['path_alias'].'">'.$blog_entry['botton_label'].'</a>';
           print '                     </h6>';
           print '                 </div>';
           print '             </li>';
            ?>

