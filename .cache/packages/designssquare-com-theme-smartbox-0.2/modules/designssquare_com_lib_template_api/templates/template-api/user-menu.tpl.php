<?php
/*DesignsSquare.com Template API template file - user-menu.tpl.php with the following TAPI:
1. $menu_tapi
   - array with variables for user menu with the following API:
                $menu_tapi['depth']::[NUMBER](the depth of the menu. it can be sub-menu as well with different depth)<br>
                $menu_tapi['links']::[ARRAY](the links of the menu)<br>
                $menu_tapi['links'][N]['link_output']::[RENDERABLE ARRAY](the link of the menu to render via drupal_render)*/
?>
<ul class="dropdown-menu">
        <?php foreach($menu_tapi['links'] as $link): ?>
        <?php print drupal_render($link['link_output']);?>
    <?php endforeach;?>
</ul>