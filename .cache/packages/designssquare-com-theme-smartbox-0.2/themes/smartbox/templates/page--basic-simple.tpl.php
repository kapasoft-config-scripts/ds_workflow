<section class="section section-alt section-padded section-dark">
    <div class="row-fluid">
        <div class="super-hero-unit">
            <h1 class="super animated fadeinup delayed">
                <?php print $page_tapi['intro'] ?>
            </h1>
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

