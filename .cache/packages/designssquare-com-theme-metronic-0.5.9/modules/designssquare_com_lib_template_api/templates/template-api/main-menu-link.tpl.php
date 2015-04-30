<?php
/* DesignsSquare.com Template API template file - main-menu-link.tpl.php with the following TAPI:
1. $link_tapi
   - array of variables for main menu item with following API:
                $link_tapi['title']::[STRING](menu link name)<br>
                $link_tapi['url']::[STRING](path to page)<br>
                $link_tapi['active']::[BOOLEAN](if link part of active trail) <br>
                $link_tapi['depth']::[NUMBER] <br>
                $link_tapi['has_sub_menu']::[BOOLEAN](if link has sub menu) <br>
                $link_tapi['sub_menu']::[RENDERABLE ARRAY](theme function to render sub menu)
  */
?>
<li <?php if ($link_tapi['active']) {
    print 'class="start active open"';
} ?>>
    <?php if ($link_tapi['has_sub_menu']): ?>
        <a href="javascript:;">
       <?php else: ?>
        <a href="<?php print $link_tapi['url'];?>">
       <?php endif ?>

            <?php if($link_tapi['depth'] == 1):?>
                <?php print $link_tapi['title'] ?>
            <?php else: ?>
                <?php print $link_tapi['title'] ?>
            <?php endif ?>

            <?php if ($link_tapi['active']): ?>
                <span class="selected"></span>
                <span class="open"></span>
            <?php elseif($link_tapi['has_sub_menu']): ?>
                <span class="arrow"></span>
            <?php endif ?>
        </a>
            <?php print drupal_render($link_tapi['sub_menu']); ?>
</li>
