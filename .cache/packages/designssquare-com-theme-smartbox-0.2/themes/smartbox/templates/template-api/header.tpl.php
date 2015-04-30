<?php
/**
* Designssquare.com Template API template file - header.tpl.php with following TAPI:
* 1. $header_tapi
*   - array of header items with following API:
*                //logo img<br>
*                $header_tapi['logo']['path']::[STRING]<br>
*                $header_tapi['logo']['is_enabled']::[BOOLEAN] <br>
*                //site info<br>
*                $header_tapi['site']['name']::[STRING] <br>
*                $header_tapi['site']['name_enabled']::[BOOLEAN] <br>
*                $header_tapi['site']['front_url']::[STRING] <br>
*                //slogan<br>
*                $header_tapi['site_slogan']['text']::[STRING] <br>
*                $header_tapi['site_slogan']['is_enabled']::[STRING] <br>
*                //user<br>
*                $header_tapi['user']::[ARRAY] everything from User TAPI(_user_tapi()) <br>
*                $header_tapi['user']['name']::[STRING]<br>
*                $header_tapi['user']['avatar']['url']::[STRING] (url to profile img)<br>
*                $header_tapi['user']['avatar']['width']::[STRING] (the width from image style "Avatar")<br>
*                $header_tapi['user']['avatar']['height']::[STRING] (the height from image style "Avatar")<br>
*                $header_tapi['user']['email']::[STRING]<br>
*                $header_tapi['user']['link']['path']::[STRING](the path to user profile if registered user or login page for anonymous visitor )<br>
*                $header_tapi['user']['link']['text']::[STRING](the name of User or anonymous name like ' Mate' as configured in <a href="#!/configuration">external configurations</a>)<br>
*                $header_tapi['user']['login-link']['path']::[STRING](the path to login/logout )<br>
*                $header_tapi['user']['logi-link']['text']::[STRING](the text for link to login/logout)<br>
*                $header_tapi['user']['img']['url']::[STRING]<br>
*                $header_tapi['user']['img']['width']::[STRING](the width from image style "User Profile")<br>
*                $header_tapi['user']['img']['height']::[STRING](the height from image style "User Profile")<br>
*                $header_tapi['user']['is_authenticated']::[STRING]
*                //settings<br>
*                $header_tapi['settings']::[STRING]
* 2. $vars_tapi
*    - Drupal $variables passed on(regions in $vars_tapi['page']['region-id]')
**/
?>
<header id="masthead">
    <nav class="navbar navbar-static-top">
        <div class="navbar-inner">
            <div class="container-fluid">
                <a class="btn btn-navbar" data-target=".nav-collapse" data-toggle="collapse">
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </a>

                <h1 class="brand" >
                    <a href="<?php print $header_tapi['site']['front_url']; ?>">
                        <?php if ($header_tapi['logo']['is_enabled']): ?>
                            <img src="<?php print $header_tapi['logo']['path'] ?>" />
                        <?php endif;?>
                        <?php if($header_tapi['site']['name_enabled']) : ?>
                            <?php print $header_tapi['site']['name'] ?>
                        <?php endif;?>
                    </a>
                </h1>
                    <?php print render($vars_tapi['page']['header'])?>
            </div>
        </div>
    </nav>
</header>
