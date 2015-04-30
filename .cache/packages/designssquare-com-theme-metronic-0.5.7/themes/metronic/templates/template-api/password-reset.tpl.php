<form class="forget-form" id="<?php print $password_reset_tapi['form_id'];?>" action="<?php print $password_reset_tapi['form_action'];?>" method="post">
    <h3>Forget Password ?</h3>
    <p>
        Enter your e-mail address below to reset your password.
    </p>
    <?php print $vars_tapi['messages'] ?>
    <div class="form-group">
        <div class="input-icon">
            <i class="fa fa-envelope"></i>
            <input class="form-control placeholder-no-fix" type="text" autocomplete="off" placeholder="Email" name="<?php print $password_reset_tapi['email_name'];?>"/>
        </div>
    </div>
    <?php echo $password_reset_tapi['hidden_build_id'];?>
    <?php echo $password_reset_tapi['hidden_form_id'];?>
    <div class="form-actions">
        <button type="button" id="back-btn" class="btn">
            <i class="m-icon-swapleft"></i><a href="<?php print $password_reset_tapi['actions']['login']['path']?>"> Back </a></button>
        <button type="submit" class="btn blue pull-right">
            Submit <i class="m-icon-swapright m-icon-white"></i>
        </button>
    </div>
</form>
