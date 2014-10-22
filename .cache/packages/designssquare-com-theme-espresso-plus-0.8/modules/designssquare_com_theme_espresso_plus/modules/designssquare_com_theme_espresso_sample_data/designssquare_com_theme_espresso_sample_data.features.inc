<?php
/**
 * @file
 * designssquare_com_theme_espresso_sample_data.features.inc
 */

/**
 * Implements hook_content_assets_default_settings().
 */
function designssquare_com_theme_espresso_sample_data_content_assets_default_settings() {
$content_assets = array();

$content_assets = array(
  'public://avatar.jpg' => array(
    'uri' => 'public://avatar.jpg',
    'filename' => 'avatar.jpg',
  ),
  'public://designssquare_theme/espresso/img/001.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/001.jpg',
    'filename' => '001.jpg',
  ),
  'public://designssquare_theme/espresso/img/002.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/002.jpg',
    'filename' => '002.jpg',
  ),
  'public://designssquare_theme/espresso/img/003.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/003.jpg',
    'filename' => '003.jpg',
  ),
  'public://designssquare_theme/espresso/img/004.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/004.jpg',
    'filename' => '004.jpg',
  ),
  'public://designssquare_theme/espresso/img/005.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/005.jpg',
    'filename' => '005.jpg',
  ),
  'public://designssquare_theme/espresso/img/006.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/006.jpg',
    'filename' => '006.jpg',
  ),
  'public://designssquare_theme/espresso/img/007.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/007.jpg',
    'filename' => '007.jpg',
  ),
  'public://designssquare_theme/espresso/img/008.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/008.jpg',
    'filename' => '008.jpg',
  ),
  'public://designssquare_theme/espresso/img/009.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/009.jpg',
    'filename' => '009.jpg',
  ),
  'public://designssquare_theme/espresso/img/010.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/010.jpg',
    'filename' => '010.jpg',
  ),
  'public://designssquare_theme/espresso/img/011.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/011.jpg',
    'filename' => '011.jpg',
  ),
  'public://designssquare_theme/espresso/img/012.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/012.jpg',
    'filename' => '012.jpg',
  ),
  'public://designssquare_theme/espresso/img/background.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/background.jpg',
    'filename' => 'background.jpg',
  ),
  'public://designssquare_theme/espresso/img/bio-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/bio-lg.jpg',
    'filename' => 'bio-lg.jpg',
  ),
  'public://designssquare_theme/espresso/img/bio.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/bio.jpg',
    'filename' => 'bio.jpg',
  ),
  'public://designssquare_theme/espresso/img/birdfat-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/birdfat-lg.jpg',
    'filename' => 'birdfat-lg.jpg',
  ),
  'public://designssquare_theme/espresso/img/birdgreen-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/birdgreen-lg.jpg',
    'filename' => 'birdgreen-lg.jpg',
  ),
  'public://designssquare_theme/espresso/img/birdretro-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/birdretro-lg.jpg',
    'filename' => 'birdretro-lg.jpg',
  ),
  'public://designssquare_theme/espresso/img/birdsepia-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/birdsepia-lg.jpg',
    'filename' => 'birdsepia-lg.jpg',
  ),
  'public://designssquare_theme/espresso/img/butterfly-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/butterfly-lg.jpg',
    'filename' => 'butterfly-lg.jpg',
  ),
  'public://designssquare_theme/espresso/img/flowers-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/flowers-lg.jpg',
    'filename' => 'flowers-lg.jpg',
  ),
  'public://designssquare_theme/espresso/img/glyphicons-halflings-white.png' => array(
    'uri' => 'public://designssquare_theme/espresso/img/glyphicons-halflings-white.png',
    'filename' => 'glyphicons-halflings-white.png',
  ),
  'public://designssquare_theme/espresso/img/glyphicons-halflings.png' => array(
    'uri' => 'public://designssquare_theme/espresso/img/glyphicons-halflings.png',
    'filename' => 'glyphicons-halflings.png',
  ),
  'public://designssquare_theme/espresso/img/gravatar-icon.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/gravatar-icon.jpg',
    'filename' => 'gravatar-icon.jpg',
  ),
  'public://designssquare_theme/espresso/img/leaves-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/leaves-lg.jpg',
    'filename' => 'leaves-lg.jpg',
  ),
  'public://designssquare_theme/espresso/img/slice.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/slice.jpg',
    'filename' => 'slice.jpg',
  ),
  'public://designssquare_theme/espresso/img/snail-lg.jpg' => array(
    'uri' => 'public://designssquare_theme/espresso/img/snail-lg.jpg',
    'filename' => 'snail-lg.jpg',
  ),
);
return $content_assets;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function designssquare_com_theme_espresso_sample_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_menu_alias_default_settings().
 */
function designssquare_com_theme_espresso_sample_data_menu_alias_default_settings() {
$menu_alias = array();

$menu_alias = array(
  'main-menu' => array(
    'definition' => array(
      'menu_name' => 'main-menu',
      'title' => 'Main menu',
      'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    ),
    'links' => array(
      'home' => array(
        'menu_name' => 'main-menu',
        'plid' => 0,
        'link_path' => 'home',
        'link_title' => 'Home',
        'options' => array(
          'attributes' => array(),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 0,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'home',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'ds-blog' => array(
        'menu_name' => 'main-menu',
        'plid' => 0,
        'link_path' => 'ds-blog',
        'link_title' => 'BLOG',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 1,
        'weight' => 2,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'ds-blog',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'about' => array(
        'menu_name' => 'main-menu',
        'plid' => 0,
        'link_path' => 'about',
        'link_title' => 'About',
        'options' => array(
          'attributes' => array(),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 4,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'about',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'contact' => array(
        'menu_name' => 'main-menu',
        'plid' => 0,
        'link_path' => 'contact',
        'link_title' => 'Contact',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 5,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'contact',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'user' => array(
        'menu_name' => 'main-menu',
        'plid' => 0,
        'link_path' => 'user',
        'link_title' => 'Subscribe',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 7,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'user',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'ds-portfolio' => array(
        'menu_name' => 'main-menu',
        'plid' => 0,
        'link_path' => 'ds-portfolio',
        'link_title' => 'Portfolio',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 10,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'ds-portfolio',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
    ),
  ),
  'menu-bottom-menu' => array(
    'definition' => array(
      'menu_name' => 'menu-bottom-menu',
      'title' => 'Bottom Menu',
      'description' => 'menu at the bottom of the page',
    ),
    'links' => array(
      'user' => array(
        'menu_name' => 'menu-bottom-menu',
        'plid' => 0,
        'link_path' => 'user',
        'link_title' => 'Subscribe',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 0,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'user',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'contact' => array(
        'menu_name' => 'menu-bottom-menu',
        'plid' => 0,
        'link_path' => 'contact',
        'link_title' => 'Contact',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 2,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'contact',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'about' => array(
        'menu_name' => 'menu-bottom-menu',
        'plid' => 0,
        'link_path' => 'about',
        'link_title' => 'About',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 3,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'about',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'ds-portfolio' => array(
        'menu_name' => 'menu-bottom-menu',
        'plid' => 0,
        'link_path' => 'ds-portfolio',
        'link_title' => 'Portfolio',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 4,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'ds-portfolio',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
      'ds-blog' => array(
        'menu_name' => 'menu-bottom-menu',
        'plid' => 0,
        'link_path' => 'ds-blog',
        'link_title' => 'Blog',
        'options' => array(
          'attributes' => array(
            'title' => '',
          ),
        ),
        'module' => 'menu',
        'hidden' => 0,
        'external' => 0,
        'has_children' => 0,
        'expanded' => 0,
        'weight' => 5,
        'depth' => 1,
        'customized' => 1,
        'p1' => 'ds-blog',
        'p2' => 0,
        'p3' => 0,
        'p4' => 0,
        'p5' => 0,
        'p6' => 0,
        'p7' => 0,
        'p8' => 0,
        'p9' => 0,
        'updated' => 0,
      ),
    ),
  ),
);
return $menu_alias;
}

/**
 * Implements hook_strongarm_override_default_settings().
 */
function designssquare_com_theme_espresso_sample_data_strongarm_override_default_settings() {
$strongarm_override = array();

$strongarm_override[] = array(
  'name' => 'site_403',
  'value' => 'user',
);
$strongarm_override[] = array(
  'name' => 'site_404',
  'value' => 'home',
);
$strongarm_override[] = array(
  'name' => 'site_default_country',
  'value' => '',
);
$strongarm_override[] = array(
  'name' => 'site_frontpage',
  'value' => 'home',
);
$strongarm_override[] = array(
  'name' => 'site_mail',
  'value' => 'admin@example.com',
);
$strongarm_override[] = array(
  'name' => 'site_name',
  'value' => 'Espresso Theme',
);
$strongarm_override[] = array(
  'name' => 'site_slogan',
  'value' => 'A clean, minimal, responsive blog &amp; portfolio theme for businesses &amp; creatives',
);
return $strongarm_override;
}

/**
 * Implements hook_variable_assets_default_settings().
 */
function designssquare_com_theme_espresso_sample_data_variable_assets_default_settings() {
$variable_assets = array();

$variable_assets = array(
  'ds_about__content_block__image' => array(
    'fid' => 68,
    'uid' => 1,
    'filename' => 'bio-lg.jpg',
    'uri' => 'public://designssquare_com_theme_blocks/assets/img/bio-lg_3.jpg',
    'filemime' => 'image/jpeg',
    'filesize' => 61377,
    'status' => 1,
    'timestamp' => 1404858307,
    'uuid' => 'c87b8bbd-9146-4e15-b695-30092057cc24',
    'rdf_mapping' => array(),
  ),
);
return $variable_assets;
}
