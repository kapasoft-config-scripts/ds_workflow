

<div class="module col-sm-3 contextual-links-region">
        <?php print render($project_tapi['ds_contextual_links']);?>
        <a href="<?php print $project_tapi['url']?>"><img src="<?php print $project_tapi['featured_img']['url']?>" alt="<?php print $project_tapi['featured_img']['url']?>" class="thumbnail img-responsive"></a>
        <h3><a href="<?php print base_path().'project'?>">Hummingbird Project</a></h3>
        <p><?php print $project_tapi['summary'];?></p>
</div>


