<li>
    <div class="contextual-links-region">
        <?php print render($gallery_tapi['ds_contextual_links']); ?>
        <a href="<?php print $gallery_tapi['url'] ?>">
            <img
                src="<?php print $gallery_tapi['featured_img']['url'] ?>"
                alt="<?php print $gallery_tapi['featured_img']['url'] ?>"
                class="thumbnail"
                <?php print $gallery_tapi['styles']['teaser_thumb']['style']?>
                >
        </a>
        <h3><a href="<?php print $gallery_tapi['url'] ?>"><?php print $gallery_tapi['title']; ?></a></h3>
        <?php print $gallery_tapi['summary']; ?>
    </div>
</li>