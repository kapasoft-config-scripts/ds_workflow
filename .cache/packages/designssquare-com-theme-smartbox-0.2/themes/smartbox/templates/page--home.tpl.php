<!-- Promo Section -->
      <section class="section section-alt">
        <div class="row-fluid">
          <div class="flexslider" data-flex-animation="slide" data-flex-controlsalign="center" data-flex-controlsposition="inside" data-flex-directions="hide" data-flex-speed="7000" id="intro">
            <ul class="slides">
              <li>
                <div class="super-hero-unit">
                  <figure>
                    <img alt="some image" src="<?php print base_path() . path_to_theme()?>/smartbox/images/assets/landscapes/landscape-2-1250x420.jpg">
                    <figcaption class="flex-caption">
                      <h1 class="super">
    Bold
                        <span class="lighter">
                          &amp;
                        </span>
    Beautiful
                      </h1>
                    </figcaption>
                  </figure>
                </div>
              </li>
              <li>
                <div class="super-hero-unit">
                  <figure>
                    <img alt="some image" src="<?php print base_path() . path_to_theme()?>/smartbox/images/assets/landscapes/landscape-3-1250x420.jpg">
                    <figcaption class="flex-caption">
                      <h1 class="super">
    Creative
                        <span class="lighter">
                          &amp;
                        </span>
    Responsive
                      </h1>
                    </figcaption>
                  </figure>
                </div>
              </li>
              <li>
                <div class="super-hero-unit">
                  <figure>
                    <img alt="some image" src="<?php print base_path() . path_to_theme()?>/smartbox/images/assets/landscapes/landscape-1-1250x420.jpg">
                    <figcaption class="flex-caption">
                      <h1 class="super">
    Adaptive
                        <span class="lighter">
                          &amp;
                        </span>
    Awesome
                      </h1>
                    </figcaption>
                  </figure>
                </div>
              </li>
            </ul>
          </div>
        </div>
      </section>

<?php print render($title_suffix); ?>
<?php print $messages; ?>
<?php if (!empty($tabs)): ?>
    <?php print render($tabs); ?>
<?php endif; ?>
<?php if (!empty($action_links)): ?>
    <ul class="action-links"><?php print render($action_links); ?></ul>
<?php endif; ?>
<?php print render($page['content']); ?>

<?php print render($page['node_bottom']); ?>

