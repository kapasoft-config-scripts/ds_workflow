var Portfolio = function () {


    return {
        //main function to initiate the module
        init: function () {
            $('.mix-grid').mixitup();
        }

    };

}();

(function ($) {
//get largest height for gallery thumb
    var $maxHeight = 0;

// find all items
    var $allItems = $(".ds-gallery-node iframe, .ds-gallery-node .video-js, .ds-gallery-node img.img-responsive");
//fix hover not working in IE by JS script instead CSS transitions
    $('.mix').each(
        function(){
            $(this).mouseover(function() {
                $(this).find('.mix-details').css(
                    {
                        'bottom': "0",
                        'transition': "all 0.5s ease",
                        '-o-transition': 'all 0.5s ease',
                        '-ms-transition': 'all 0.5s ease',
                        '-moz-transition': 'all 0.5s ease',
                        '-webkit-transition': 'all 0.5s ease'
                    }
                );
            });
            $(this).mouseout(function() {
                $(this).find('.mix-details').css(
                    {
                        'bottom': "-100%",
                        'transition': "all 0.5s ease",
                        '-o-transition': 'all 0.5s ease',
                        '-ms-transition': 'all 0.5s ease',
                        '-moz-transition': 'all 0.5s ease',
                        '-webkit-transition': 'all 0.5s ease'
                    }
                );
            });
        }
    );



//find max height and resize the height
    $(document).ready(function() {
        $allImageThumbs = $(".ds-gallery-node img.img-responsive");
        //use image items only to determine height
        $allImageThumbs.each(function () {
                $(this).parent().parent().show();
                var $currentHeight = $(this).height();
                if ($currentHeight > $maxHeight) {
                    $maxHeight = $currentHeight;
                }
            }
        );
        //if there ir not image items then use other determine max height
        if($maxHeight == 0){
            var $allThumbs = $(".ds-gallery-node .mix");
            $allThumbs.each(function () {
                    var $currentHeight = $(this).height();
                    if ($currentHeight > $maxHeight) {
                        $maxHeight = $currentHeight;
                    }
                }
            );
        }
        //resize the height
        $allItems.each(function () {
            $(this).css('height', $maxHeight + 'px');
        });
    });
})(jQuery);