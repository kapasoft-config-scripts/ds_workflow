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

