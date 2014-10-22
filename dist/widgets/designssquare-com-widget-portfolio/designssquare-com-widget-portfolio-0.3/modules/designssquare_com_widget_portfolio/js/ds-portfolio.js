(function ($) {
    $('.ds_portfolio_image').click(function(e){
        e.preventDefault();
        var img_src = $(this).find('img').attr('src');
        $('#focus-image').attr('src',img_src);
    });
})(jQuery);
