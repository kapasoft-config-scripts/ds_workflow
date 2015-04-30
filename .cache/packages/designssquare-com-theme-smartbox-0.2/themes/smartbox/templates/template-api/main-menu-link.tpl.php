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
<li
    <?php echo 'class="';?>

<?php
if ($link_tapi['active']) {
    echo 'active ';
}
if ($link_tapi['has_sub_menu']) {
    echo 'dropdown';
}
echo '"';
?>
>
    <?php if ($link_tapi['has_sub_menu']): ?>
        <a class="dropdown-toggle" data-toggle="dropdown" href="#">
    <?php else: ?>
        <a href="<?php print $link_tapi['url'];?>">
       <?php endif ?>
            <?php print $link_tapi['title'] ?>

<!--                <span class="selected"></span>-->
<!--                <span class="open"></span>-->
            <?php if($link_tapi['has_sub_menu']): ?>
                <b class="caret"></b>
                    <?php print drupal_render($link_tapi['sub_menu']); ?>
            <?php endif ?>
         </a>
</li>


