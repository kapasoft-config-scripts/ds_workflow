<ul class="dropdown-menu">
        <?php foreach($menu_tapi as $link): ?>
        <?php print drupal_render($link['link_output']);?>
    <?php endforeach;?>
</ul>