<div class="<?php print $context['classes'];?>">
    <?php print render($block_api['contextual_links']);?>
    <h3><?php print $block_api['title']; ?></h3>
    <?php print $block_api['content'];?>
    <p><a href="<?php print $block_api['link_to_twitter']; ?>" class="btn btn-info btn-mini"><strong><?php print $block_api['button_text']; ?></strong></a></p>
</div>