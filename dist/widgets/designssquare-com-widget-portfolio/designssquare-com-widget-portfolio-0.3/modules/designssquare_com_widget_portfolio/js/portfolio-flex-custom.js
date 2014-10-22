(function ($) {
    var dsFlexSlider = $('.portfolio-teaser-slider');
    $('.ds-portfolio-flex-next').bind("click", function(event) {
    event.preventDefault();
    dsFlexSlider.flexslider('next');
    });
$('.ds-portfolio-flex-prev').bind("click", function(event) {
    event.preventDefault();//prevents default action
    dsFlexSlider.flexslider('prev');
    });
})(jQuery);