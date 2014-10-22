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