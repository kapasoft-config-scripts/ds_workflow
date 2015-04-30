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
<!--<div class="nav-collapse collapse">-->

<?php if($menu_tapi['depth'] == 0): ?>
<div class="navbar">
    <ul class="nav pull-right">
        <?php foreach($menu_tapi['links'] as $link): ?>
            <?php print drupal_render($link['link_output']);?>
        <?php endforeach;?>
    </ul>
</div>
<?php else:?>
    <ul class="dropdown-menu" role="menu" aria-labelledby="dLabel">
        <?php foreach($menu_tapi['links'] as $link): ?>
            <?php print drupal_render($link['link_output']);?>
        <?php endforeach;?>
    </ul>
<?php endif;?>

