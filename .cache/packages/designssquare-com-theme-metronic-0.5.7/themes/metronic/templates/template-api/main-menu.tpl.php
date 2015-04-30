
<!-- BEGIN SIDEBAR MENU -->
<?php if($menu_tapi['depth'] == 0): ?>
    <ul class="page-sidebar-menu main-menu" data-auto-scroll="true" data-slide-speed="200">
<?php else:?>
    <ul class="sub-menu">
<?php endif?>
<?php foreach($menu_tapi['links'] as $link): ?>
    <?php print drupal_render($link['link_output']);?>
<?php endforeach;?>
</ul>