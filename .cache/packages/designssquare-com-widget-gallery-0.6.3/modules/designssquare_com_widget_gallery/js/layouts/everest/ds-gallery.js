(function ($) {
    $('.ds_portfolio_image').click(function(e){
        e.preventDefault();
//        var img_src = $(this).find('img').attr('src');
        var img_src = $(this).attr('src');
        $('#focus-image').attr('src',img_src);
    });
})(jQuery);
