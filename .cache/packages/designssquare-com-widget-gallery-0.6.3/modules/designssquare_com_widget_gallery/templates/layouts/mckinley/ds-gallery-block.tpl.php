<div id="ds-mckinley-block" class="ds-widget ds-widget-gallery-block ds-widget-gallery-mckinley-block">
    <?php if (isset($gallery_view_tapi['views_title']) && !empty($gallery_view_tapi['views_title'])): ?>
        <h3 ><?php print $gallery_view_tapi['views_title'];?></h3>
    <?php endif ?>
    <div class="ds-gallery-mckinley-block-flexslider">
        <div class="flex-viewport" style="overflow: hidden; position: relative;">
            <ul class="slides" style="width: 1000%; -webkit-transition: 0s; transition: 0s; -webkit-transform: translate3d(-270px, 0px, 0px);">
                <?php print render($rows); ?>
            </ul>
        </div>
        <ul class="flex-direction-nav">
            <li>
                <a class="flex-prev" href="#">Previous</a>
            </li>
            <li>
                <a class="flex-next" href="#">
                    Next
                </a>
            </li>
        </ul>
    </div>
    <script type="text/javascript">
        jQuery(document).ready(function($){
            var animation = $.browser.msie || $.browser.opera ? 'fade' : 'slide';
            $('.ds-gallery-mckinley-block-flexslider').flexslider({
                animation: animation,
                slideshowSpeed: 8000,
                animationSpeed: 300,
                selectors: 'ul > li',
                directionNav: true,
                slideshow: true,

                pauseOnAction: false,
                controlNav: false,
                touch: true
            });
        });
    </script>
</div>