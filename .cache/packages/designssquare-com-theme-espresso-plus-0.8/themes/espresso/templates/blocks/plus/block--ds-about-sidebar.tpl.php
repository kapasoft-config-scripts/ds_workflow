<div class="<?php print $context['classes'];?>">
<?php print render($block_api['contextual_links']);?>
    <h3 class="widget-title"><?php print $block_api['title']; ?></h3>
    <p><a href="<?php print $block_api['ref_page']; ?>">
            <img src="<?php print $block_api['image']; ?>" alt="Placeholder" width="70" height="54"class="right thumbnail img-responsive">
        </a>
        <?php print $block_api['content'];?>
    </p>
</div>