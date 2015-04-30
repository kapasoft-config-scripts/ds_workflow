<?php
/**
* DesignsSquare.com Template API template file - login.tpl.php with following TAPI:
* 1. $login_tapi
*   - array of variables for login form with the following API:
*                $login_tapi['form_id']::[STRING](form id for login form)<br>
*                $login_tapi['form_action']::[STRING] (action for login form)<br>
*                $login_tapi['user_name']::[STRING](name attribute for input field of username) <br>
*                $login_tapi['pass_name']::[STRING](name attribute for input field of password)<br>
*                $login_tapi['hidden_build_id']::[STRING](hidden field necessary for login form)<br>
*                $login_tapi['hidden_form_id']::[STRING](hidden field necessary for login form)
*                //action links<br>
*                $login_tapi['actions']::[ARRAY](list of actions for users )<br>
*                $login_tapi['actions']['register']['path']::[STRING](url to the page with registration form)<br>
*                $login_tapi['actions']['register']['text']::[STRING](text for the link)<br>
*                $login_tapi['actions']['login']['path']::[STRING](url to the page with user login form)<br>
*                $login_tapi['actions']['login']['text']::[STRING](text for the link)<br>
*                $login_tapi['actions']['password-reset']['path']::[STRING](url to the page with form to reset password)<br>
*                $login_tapi['actions']['password-reset']['text']::[STRING](text for the link)<br>
* 2. $vars_tapi
*    - Drupal $variables passed on(regions in $vars_tapi[page][region-id])
**/
?>
<form class="login-form" id="<?php print $login_tapi['form_id'];?>" action="<?php print $login_tapi['form_action']; ?>" method="post">
    <h3 class="form-title">Login to your account</h3>

    <?php print $vars_tapi['messages'] ?>
    <div class="form-group">
        <label class="control-label visible-ie8 visible-ie9">Username</label>
        <div class="input-icon">
            <i class="fa fa-user"></i>
            <input class="form-control placeholder-no-fix" type="text" autocomplete="off" placeholder="Username" name="<?php print $login_tapi['user_name'];?>"/>
        </div>
    </div>
    <div class="form-group">
        <label class="control-label visible-ie8 visible-ie9">Password</label>
        <div class="input-icon">
            <i class="fa fa-lock"></i>
            <input class="form-control placeholder-no-fix" type="password" autocomplete="off" placeholder="Password" name="<?php print $login_tapi['pass_name'];?>"/>
        </div>
    </div>
    <?php print $login_tapi['hidden_build_id'];?>
    <?php print $login_tapi['hidden_form_id'];?>
    <div class="form-actions">
        <label class="checkbox">
            <input type="checkbox" name="remember" value="1"/> Remember me </label>
        <button type="submit" class="btn blue pull-right">
            Login <i class="m-icon-swapright m-icon-white"></i>
        </button>
    </div>
    <div class="login-options">
        <h4>Or login with</h4>
        <ul class="social-icons">
            <li>
                <a class="facebook" data-original-title="facebook" href="#">
                </a>
            </li>
            <li>
                <a class="twitter" data-original-title="Twitter" href="#">
                </a>
            </li>
            <li>
                <a class="googleplus" data-original-title="Goole Plus" href="#">
                </a>
            </li>
            <li>
                <a class="linkedin" data-original-title="Linkedin" href="#">
                </a>
            </li>
        </ul>
    </div>
    <div class="forget-password">
        <h4>Forgot your password ?</h4>
        <p>
            no worries, click <a href="javascript:;" id="forget-password">
                here </a>
            to reset your password.
        </p>
    </div>
    <div class="create-account">
        <p>
            Don't have an account yet ?&nbsp; <a href="javascript:;" id="register-btn">
                Create an account </a>
        </p>
    </div>
</form>