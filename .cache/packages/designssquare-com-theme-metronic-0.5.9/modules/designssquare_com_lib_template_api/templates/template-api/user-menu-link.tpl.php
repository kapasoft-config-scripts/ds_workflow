<?php
/*Designssquare.com Template API template file - user-menu.tpl.php with following TAPI:
1. $link_tapi
   - array of variables for user menu item with following API:
                $link_tapi['title']::[STRING](menu link name)<br>
                $link_tapi['url']::[STRING](path to page)<br>
                $link_tapi['active']::[BOOLEAN](if link part of active trail) <br>
                $link_tapi['depth']::[NUMBER] <br>
                $link_tapi['has_sub_menu']::[BOOLEAN](if link has sub menu) <br>
                $link_tapi['sub_menu']::[RENDERABLE ARRAY](theme function to render sub menu)*/
?>
<li>
    <a href="<?php print $link_tapi['url'];?>">
        <?php print $link_tapi['title'] ?>
<!--        <i class="icon-user"></i> My Profile -->
    </a>
</li>