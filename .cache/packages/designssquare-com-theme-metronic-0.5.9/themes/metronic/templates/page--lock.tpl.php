
    <?php print $messages; ?>
    <img class="page-lock-img" src="<?php print $user_tapi['avatar']['url']?>" alt="">
    <div class="page-lock-info">
        <h1><?php print $user_tapi['name']?></h1>
			<span class="email">
			<?php print $user_tapi['email']?> </span>
			<span class="locked">
			Locked </span>
        <form class="form-inline" action="#">
            <div class="input-group input-medium">
                <input type="text" class="form-control" placeholder="Password">
					<span class="input-group-btn">
					<button type="submit" class="btn blue icn-only"><i class="m-icon-swapright m-icon-white"></i></button>
					</span>
            </div>
            <!-- /input-group -->
            <div class="relogin">
                <a href="<?php print $user_tapi['profile']['url'] ?>">
                    Not <?php print $user_tapi['name']?>?</a>
            </div>
        </form>
    </div>