<!--
Designssquare.com Template API template file - footer.tpl.php with following TAPI:
1. $footer_tapi
   - array of variable for footer with following API:
        @ToDo
2. $vars_tapi
    - Drupal $variables passed on(regions in $vars_tapi[page][region-id])
-->
<div class="page-footer">
    <div class="page-footer-inner">
        <?php print render($vars_tapi['page']['footer'])?>
    </div>
    <div class="page-footer-tools">
		<span class="go-top">
		<i class="fa fa-angle-up"></i>
		</span>
    </div>
</div>
