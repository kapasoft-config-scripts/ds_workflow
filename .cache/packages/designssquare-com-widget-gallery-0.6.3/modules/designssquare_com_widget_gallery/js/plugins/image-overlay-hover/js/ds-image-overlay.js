$(document).ready(function(){
    if (Modernizr.touch) {
        // show the close overlay button
        $(".ds-close-overlay").removeClass("hidden");
        // handle the adding of hover class when clicked
        $(".ds-img").click(function(e){
            if (!$(this).hasClass("hover")) {
                $(this).addClass("hover");
            }
        });
        // handle the closing of the overlay
        $(".ds-close-overlay").click(function(e){
            e.preventDefault();
            e.stopPropagation();
            if ($(this).closest(".ds-img").hasClass("hover")) {
                $(this).closest(".ds-img").removeClass("hover");
            }
        });
    } else {
        // handle the mouseenter functionality
        $(".ds-img").mouseenter(function(){
            $(this).addClass("hover");
        })
            // handle the mouseleave functionality
            .mouseleave(function(){
                $(this).removeClass("hover");
            });
    }
});