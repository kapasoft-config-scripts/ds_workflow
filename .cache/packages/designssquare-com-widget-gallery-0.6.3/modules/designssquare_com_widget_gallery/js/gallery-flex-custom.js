(function ($) {
    var dsFlexSlider = $('.gallery-teaser-slider');
    $('.ds-gallery-flex-next').bind("click", function(event) {
    event.preventDefault();
    dsFlexSlider.flexslider('next');
    });
$('.ds-gallery-flex-prev').bind("click", function(event) {
    event.preventDefault();//prevents default action
    dsFlexSlider.flexslider('prev');
    });
})(jQuery);