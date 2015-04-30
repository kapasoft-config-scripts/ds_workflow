<?php
/**
* DesignsSquare.com Template API template file - breadcrumbs.tpl.php with the following TAPI:
* 1. $breadcrumbs_tapi
*   - array of breadcrumb items with following API:
*        $breadcrumbs[N]['url']::[STRING]
*        $breadcrumbs[N]['label']::[STRING]
*        $breadcrumbs[N]['first']::[BOOLEAN]
*        $breadcrumbs[N]['last']::[BOOLEAN]
* 2. $vars_tapi
*    - Drupal $variables passed on(regions in $vars_tapi[page][region-id])
**/
?>

<ul class="page-breadcrumb breadcrumb">
    <?php foreach ($breadcrumbs_tapi as $key => $breadcrumb):?>
    <li>
        <?php if($breadcrumb['first']):?>
        <i class="fa fa-home"></i>
        <?php endif?>

        <a href="<?php print $breadcrumb['url'] ?>"><?php print $breadcrumb['label']?></a>

        <?php if(!$breadcrumb['last']): ?>
        <i class="fa fa-angle-right"></i>
        <?php endif ?>

    </li>
    <?php endforeach; ?>
        <?php print render($vars_tapi['page']['breadcrumbs_sidebar'])?>
</ul>