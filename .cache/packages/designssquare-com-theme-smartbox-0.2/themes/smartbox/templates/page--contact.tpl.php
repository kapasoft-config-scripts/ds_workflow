
<?php print render($title_suffix); ?>
<?php print $messages; ?>
<?php if (!empty($tabs)): ?>
    <?php print render($tabs); ?>
<?php endif; ?>
<?php if (!empty($action_links)): ?>
    <ul class="action-links"><?php print render($action_links); ?></ul>
<?php endif; ?>

<section class="section section-alt">
    <div id="map"></div>
</section>

<section class="section section-padded">
    <div class="container-fluid">
        <?php print render($page['content']); ?>
        <hr>
        <div class="row-fluid">
            <div class="span6">
                <?php print render($contact_form);?>
            </div>
            <div class="span6 contact-details">
                <?php if ($page['sidebar_second']): ?>
                    <?php print render($page['sidebar_second']); ?>
                <?php endif; ?>
            </div>
        </div>
    </div>
</section>


<?php print render($page['node_bottom']); ?>

