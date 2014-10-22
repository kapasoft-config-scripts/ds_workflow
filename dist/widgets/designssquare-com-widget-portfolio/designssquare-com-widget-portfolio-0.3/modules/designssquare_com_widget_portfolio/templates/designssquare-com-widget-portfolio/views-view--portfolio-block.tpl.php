
<div class="widget contextual-links-region">
<?php print render($ds_contextual_links);?>

    <?php if ($exposed): ?>
        <div class="view-filters">
            <?php print $exposed; ?>
        </div>
    <?php endif; ?>

    <?php if ($attachment_before): ?>
        <div class="attachment attachment-before">
            <?php print $attachment_before; ?>
        </div>
    <?php endif; ?>
    <?php if(isset($views_title) && !empty($views_title)): ?>
            <h3 class="widget-title"><?php print $views_title;?></h3>
    <?php endif ?>
    <?php if ($rows): ?>
            <?php print $rows; ?>
    <?php elseif ($empty): ?>
        <div class="view-empty">
            <?php print $empty; ?>
        </div>
    <?php endif; ?>
</div>