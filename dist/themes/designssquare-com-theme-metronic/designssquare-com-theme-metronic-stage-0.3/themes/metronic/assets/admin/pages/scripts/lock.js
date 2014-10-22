var Lock = function () {

    return {
        //main function to initiate the module
        init: function () {

             $.backstretch([
		        "/sites/default/files/designssquare_com_theme_metronic/assets/admin/pages/media/bg/1.jpg",
    		    "/sites/default/files/designssquare_com_theme_metronic/assets/admin/pages/media/bg/2.jpg",
    		    "/sites/default/files/designssquare_com_theme_metronic/assets/admin/pages/media/bg/3.jpg",
    		    "/sites/default/files/designssquare_com_theme_metronic/assets/admin/pages/media/bg/4.jpg"
		        ], {
		          fade: 1000,
		          duration: 8000
		      });
        }

    };

}();