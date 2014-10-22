<div id="header" class="row">
    <div class="col-sm-4">
        <h1 class="logo">

                <a href="<?php print $head_tapi['site']['front_url']?>">
                    <?php if($head_tapi['logo']['is_enabled']):  ?>
                        <img src="<?php print $head_tapi['logo']['path']?>" alt="site logo"/>
                    <?php elseif($head_tapi['site']['name_enabled']): ?>
                        <?php print $head_tapi['site']['name'];?>
                    <?php endif; ?>
                </a>

        </h1>
        <?php if($head_tapi['site_slogan']['is_enabled']): ?>
            <p class="tagline"><?php print $head_tapi['site_slogan']['text']; ?></p>
        <?php endif;?>
    </div>
    <div class="col-sm-8">
        <?php //print render($page['navigation']);?>
        <?php print render($region['navigation']);?>
    </div>
</div>