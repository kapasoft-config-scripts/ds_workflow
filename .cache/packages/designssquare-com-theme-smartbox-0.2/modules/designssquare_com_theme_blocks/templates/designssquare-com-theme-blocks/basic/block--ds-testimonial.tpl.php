<div class="testimonialrotator"  style="height: 240px;">
    <div class="testimonial" style="position: absolute; display: block;">
        <div class="main_testimonial">
            <div class="blockquote">Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Phasellus hendrerit. Pellentesque aliquet nibh nec urna. Ligula sollicitudin laoreet viverra, tortor libero sodales leo, eget blandit nunc tortor eu nibh. Nullam mollis. The readable content of a page when looking at its layout. It is a long established fact that a reader will be distracted by the readable content.</div>
        </div>
        <div class="the-author">Mikle / CEO Some Company</div>
    </div>
    <div class="testimonial" style="display: none;">
        <div class="main_testimonial">
            <div class="blockquote">Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like). It is a long established fact that. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Phasellus hendrerit. Pellentesque aliquet nibh nec urna.Sed pretium, ligula sollicitudin laoreet viverra, tortor libero sodales leo, eget blandit nunc tortor eu nibh. Nullam mollis.</div>
        </div>
        <div class="the-author">Jhon Doe</div>
    </div>
</div>

<script>
    (function($) {

        $.fn.testimonialrotator = function(o) {

            var defaults = {
                settings_slideshowTime : '5',
                settings_autoHeight : 'on'
            }

            o = $.extend(defaults, o);
            this.each( function() {
                var cthis = jQuery(this);
                var cchildren = cthis.children();
                var currNr=0;
                var timebuf=0;
                var slideshowTime = parseInt(o.settings_slideshowTime);
                setInterval(tick, 1000);
                cthis.height(cchildren.eq(currNr).height());
                cchildren.eq(0).css('position', 'absolute');
                function tick(){
                    timebuf++;
                    if(timebuf>slideshowTime){
                        timebuf=0;
                        gotoNext();
                    }
                }
                function gotoNext(){
                    var arg=currNr+1;
                    if(arg>cchildren.length-1){
                        arg=0;
                    }
                    cchildren.eq(currNr).fadeOut('slow');
                    cchildren.eq(arg).fadeIn('slow');
                    if(o.settings_autoHeight=='on'){
                        cthis.animate({'height' : cchildren.eq(arg).height()})
                    }
                    currNr=arg;
                }
                return this;
            })
        }
    })(jQuery)

    jQuery.noConflict()(function($){
        $(".testimonialrotator").testimonialrotator({
            settings_slideshowTime:3
        });
    });
</script>
