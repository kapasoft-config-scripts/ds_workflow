<!-- BEGIN SIDEBAR MENU -->

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
