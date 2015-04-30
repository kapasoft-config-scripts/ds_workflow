<?php
/**
 * Designssquare.com Template API template file - main-menu.tpl.php with following TAPI:
 * 1. $menu_tapi
 *  - array with variables for main menu with following API:
 *               $menu_tapi['depth']::[NUMBER](the depth of the menu. it can be sub-menu as well with different depth)<br>
 *               $menu_tapi['links']::[ARRAY](the links of the menu)<br>
 *               $menu_tapi['links'][N]['link_output']::[RENDERABLE ARRAY](the link of the menu to render via drupal_render)
*/
?>
<?php if($menu_tapi['depth'] == 0): ?>
    <ul class="page-sidebar-menu main-menu" data-auto-scroll="true" data-slide-speed="200">
<?php else:?>
    <ul class="sub-menu">
<?php endif?>
<?php foreach($menu_tapi['links'] as $link): ?>
    <?php print drupal_render($link['link_output']);?>
<?php endforeach;?>
</ul>