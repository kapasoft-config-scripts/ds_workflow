<div class="<?php print $context['classes'];?>">
    <?php print render($block_api['contextual_links']);?>
    <h6><?php print $block_api['title'] ?></h6><hr>
    <div class="textwidget">
        <ul class="unstyled">
            <li><i class="icon-user icon-white"></i><?php print $block_api['phone'] ?></li>
            <li><i class="icon-envelope icon-white"></i> <?php print $block_api['email'] ?></li>
            <li><i class="icon-map-marker icon-white"></i> <?php print $block_api['address'] ?></li>
        </ul>
    </div>
</div>