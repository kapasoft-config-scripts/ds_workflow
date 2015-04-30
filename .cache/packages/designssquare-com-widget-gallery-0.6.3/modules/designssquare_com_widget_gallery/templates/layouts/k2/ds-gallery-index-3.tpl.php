<?php if (isset($gallery_view_tapi['views_title']) && !empty($gallery_view_tapi['views_title'])): ?>
    <!--    <div class="col-sm-12">-->
    <h3><?php print $gallery_view_tapi['views_title']; ?></h3>
    <!--    </div>-->
<?php endif ?>
<?php if ($rows): ?>
    <div class="tabbable tabbable-custom boxless">
        <!--<div class="col-sm-12">-->
        <div class="tab-content">
            <div class="tab-pane active" id="tab_1">
                <div class="margin-top-10">
                    <ul class="mix-filter">
                        <li class="filter" data-filter="all">
                            All
                        </li>
                        <?php foreach ($gallery_view_tapi['categories'] as $cat) : ?>
                            <li class="filter" data-filter="<?php print $cat['name_safe'] ?>">
                                <?php print $cat['name'] ?>
                            </li>
                        <?php endforeach; ?>
                    </ul>
                    <div class="row mix-grid thumbnails ds-gallery-index">
                        <?php print render($rows); ?>
                    </div>
                </div>
                <!-- END FILTER -->
            </div>
        </div>
    </div>

<?php endif; ?>