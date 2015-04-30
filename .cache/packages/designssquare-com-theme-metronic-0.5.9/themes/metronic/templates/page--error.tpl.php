
<!-- BEGIN SIDEBAR -->
<?php if ($page['sidebar_first']): ?>
    <div class="page-sidebar-wrapper">
        <?php print render($page['sidebar_first']); ?>

        <!-- DOC: Set data-auto-scroll="false" to disable the sidebar from auto scrolling/focusing -->
        <!-- DOC: Change data-auto-speed="200" to adjust the sub menu slide up/down speed -->
    </div>
<?php endif; ?>

<!-- END SIDEBAR -->
<!-- BEGIN CONTENT -->
<div class="page-content-wrapper">
<div class="page-content">
<!-- BEGIN SAMPLE PORTLET CONFIGURATION MODAL FORM-->
<div class="modal fade" id="portlet-config" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
     aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true"></button>
                <h4 class="modal-title">Modal title</h4>
            </div>
            <div class="modal-body">
                Widget settings form goes here
            </div>
            <div class="modal-footer">
                <button type="button" class="btn blue">Save changes</button>
                <button type="button" class="btn default" data-dismiss="modal">Close</button>
            </div>
        </div>
        <!-- /.modal-content -->
    </div>
    <!-- /.modal-dialog -->
</div>
<!-- /.modal -->
<!-- END SAMPLE PORTLET CONFIGURATION MODAL FORM-->
<!-- BEGIN STYLE CUSTOMIZER -->
<div class="theme-panel hidden-xs hidden-sm">
   <?php print render($page['theme_panel']);?>
</div>
<!-- END STYLE CUSTOMIZER -->
<!-- BEGIN PAGE HEADER-->
<div class="row">
    <div class="col-md-12">
        <!-- BEGIN PAGE TITLE & BREADCRUMB-->
        <h3 class="page-title">
            <?php print render($title_prefix); ?>
            <?php print $page_tapi['title'];?>
            <?php print render($title_suffix); ?>
            <small><?php print $page_tapi['intro'];?></small>
        </h3>
        <?php if ($breadcrumb): ?>
            <?php print $breadcrumb; ?>
        <?php endif; ?>
        <!-- END PAGE TITLE & BREADCRUMB-->
        <?php print $messages; ?>
    </div>
</div>
<!-- END PAGE HEADER-->
    <?php if ($page['highlighted']): ?>
        <div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
    <?php if ($tabs): ?>
        <div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
    <?php print render($page['help']); ?>
    <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    <?php print $feed_icons; ?>
<div class="row">
    <div class="col-md-12 page-404">
<?php print render($page['content']); ?>
        <form action="<?php print $search_tapi['action'] ?>" id="<?php print $search_tapi['id'] ?>" method="post">
            <div class="input-group input-medium" style="margin-left:auto; margin-right:auto;margin-top:30px;">
                <input type="text" id="<?php print $search_tapi['search_id']?>" name="<?php print $search_tapi['search_name']?>" class="form-control" placeholder="keyword...">
								<span class="input-group-btn">
								<button type="submit" id="<?php print $search_tapi['submit_id']?>" name="<?php print $search_tapi['submit_name']?>" class="btn blue"><i class="fa fa-search"></i></button>
								</span>
            </div>
            <?php print $search_tapi['hidden_input']?>
            <?php print $search_tapi['hidden_input2']?>
            <?php print $search_tapi['hidden_input3']?>
            <!-- /input-group -->
        </form>
    </div>
</div>
</div>
</div>
<!-- END CONTENT -->

<!-- BEGIN QUICK SIDEBAR -->
<?php print render($page['quick_sidebar'])?>
    <!-- END QUICK SIDEBAR -->


