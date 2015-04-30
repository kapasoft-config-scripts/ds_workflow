<?php
/*DesignsSquare.com Template API template file - password-reset.tpl.php with following TAPI:
1. $password_reset_tapi
   - array of variables for registration form with the following API:
                $password_reset_tapi['form_id']::[STRING](form id for password reset form)<br>
                $password_reset_tapi['form_action']::[STRING] (action for password reset form)<br>
                $password_reset_tapi['email_name']::[STRING](name attribute for input field of email) <br>
                $password_reset_tapi['hidden_build_id']::[STRING](hidden field necessary for password reset form)<br>
                $password_reset_tapi['hidden_form_id']::[STRING](hidden field necessary for password reset form)<br>
                //action links<br>
                $password_reset_tapi['actions']::[ARRAY](list of actions for users )<br>
                $password_reset_tapi['actions']['register']['path']::[STRING](url to the page with registration form)<br>
                $password_reset_tapi['actions']['register']['text']::[STRING](text for the link)<br>
                $password_reset_tapi['actions']['login']['path']::[STRING](url to the page with user login form)<br>
                $password_reset_tapi['actions']['login']['text']::[STRING](text for the link)<br>
                $password_reset_tapi['actions']['password-reset']['path']::[STRING](url to the page with form to reset password)<br>
                $password_reset_tapi['actions']['password-reset']['text']::[STRING](text for the link)<br>
2. $vars_tapi
    - Drupal $variables passed on(regions in $vars_tapi[page][region-id])
*/
?>
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
