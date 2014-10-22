(function ($) {
    var dsFlexSlider = $('.blog_teaser_slider');
    $('.ds-blog-flex-next').bind("click", function(event) {
    event.preventDefault();
    dsFlexSlider.flexslider('next');
    });
$('.ds-blog-flex-prev').bind("click", function(event) {
    event.preventDefault();//prevents default action
    dsFlexSlider.flexslider('prev');
    });
})(jQuery);