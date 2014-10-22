<div class="<?php print $context['classes']; ?>">
    <?php print render($block_api['contextual_links']); ?>
    <div class="row-fluid">
        <div class="span12">
            <h3><?php print $block_api['title']?></h3>
            <div class="sidebar">
                <div class="testimonialrotator"  style="height: 240px;">
                    <?php foreach($block_api['reviews'] as $key => $review) : ?>
                        <div class="testimonial" style="position: absolute; display: block;">
                            <div class="main_testimonial">
                                <div class="blockquote"><?php print $review['review']?></div>
                            </div>
                            <div class="the-author"><?php print $review['reviewer']?></div>
                        </div>
                    <?php endforeach;?>

<!--                    <div class="testimonial" style="display: none;">-->
<!--                        <div class="main_testimonial">-->
<!--                            <div class="blockquote">--><?php //print $block_api['review2']?><!--</div>-->
<!--                        </div>-->
<!--                        <div class="the-author">--><?php //print $block_api['reviewer2']?><!--</div>-->
<!--                    </div>-->
<!--                    <div class="testimonial" style="display: none;">-->
<!--                        <div class="main_testimonial">-->
<!--                            <div class="blockquote">--><?php //print $block_api['review3']?><!--</div>-->
<!--                        </div>-->
<!--                        <div class="the-author">--><?php //print $block_api['reviewer3']?><!--</div>-->
<!--                    </div>-->
                </div>
            </div>
        </div>
    </div>


    <script>
        (function ($) {

            $.fn.testimonialrotator = function (o) {

                var defaults = {
                    settings_slideshowTime: '5',
                    settings_autoHeight: 'on'
                }

                o = $.extend(defaults, o);
                this.each(function () {
                    var cthis = jQuery(this);
                    var cchildren = cthis.children();
                    var currNr = 0;
                    var timebuf = 0;
                    var slideshowTime = parseInt(o.settings_slideshowTime);
                    setInterval(tick, 1000);
                    cthis.height(cchildren.eq(currNr).height());
                    cchildren.eq(0).css('position', 'absolute');
                    function tick() {
                        timebuf++;
                        if (timebuf > slideshowTime) {
                            timebuf = 0;
                            gotoNext();
                        }
                    }

                    function gotoNext() {
                        var arg = currNr + 1;
                        if (arg > cchildren.length - 1) {
                            arg = 0;
                        }
                        cchildren.eq(currNr).fadeOut('slow');
                        cchildren.eq(arg).fadeIn('slow');
                        if (o.settings_autoHeight == 'on') {
                            cthis.animate({'height': cchildren.eq(arg).height()})
                        }
                        currNr = arg;
                    }

                    return this;
                })
            }
        })(jQuery)

        jQuery.noConflict()(function ($) {
            $(".testimonialrotator").testimonialrotator({
                settings_slideshowTime: 3
            });
        });
    </script>

</div>

