<section class="section section-alt">
    <div class="row-fluid">
        <div class="super-hero-unit">
            <figure>
                <img alt="<?php print $page_tapi['header_bg']['alt']?>" title="$page_tapi['header_bg']['title']" src="<?php print $page_tapi['header_bg']['url']?>">
                <figcaption class="flex-caption">
                    <h1 class="super animated fadeinup delayedmore">
                        <?php print $page_tapi['intro'] ?>
                    </h1>
                </figcaption>
            </figure>
        </div>
    </div>
</section>


<?php print render($title_suffix); ?>
<?php print $messages; ?>
<?php if (!empty($tabs)): ?>
    <?php print render($tabs); ?>
<?php endif; ?>
<?php if (!empty($action_links)): ?>
    <ul class="action-links"><?php print render($action_links); ?></ul>
<?php endif; ?>
<?php print render($page['content']); ?>

<?php print render($page['node_bottom']); ?>

