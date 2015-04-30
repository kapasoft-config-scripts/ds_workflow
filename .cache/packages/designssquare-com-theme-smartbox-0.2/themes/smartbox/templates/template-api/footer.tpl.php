<?php
/**
* Designssquare.com Template API template file - footer.tpl.php with following TAPI:
* 1. $footer_tapi
*   - array of variable for footer with following API:
*        @ToDo
* 2. $vars_tapi
*    - Drupal $variables passed on(regions in $vars_tapi[page][region-id])
**/
?>
<footer id="footer" role="contentinfo">
    <div class="wrapper wrapper-transparent">
        <div class="container-fluid">
            <div class="row-fluid">
                <?php print render($vars_tapi['page']['footer'])?>
            </div>
        </div>
    </div>
</footer>