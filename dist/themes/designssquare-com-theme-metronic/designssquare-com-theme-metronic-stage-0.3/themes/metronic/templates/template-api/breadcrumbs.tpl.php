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
<!--    <li class="pull-right">-->
        <?php print render($vars_tapi['page']['breadcrumbs_sidebar'])?>
<!--    </li>-->
</ul>