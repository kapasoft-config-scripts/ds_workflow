if (!window.VIRTUAL_HOSTY) {
    /**
     * @class VIRTUAL_HOSTY
     * @singleton
     */
    window.VIRTUAL_HOSTY = (function ($) {

        var base_url = window.BASE_URL || '/',
            log_on = false;

        var _parse_url = function(){
            if(base_url != '/'){
                //running from virtual dir
                $('img').each(function(){
                    var final_url = $(this).attr('src');
                    if(final_url.indexOf(base_url) == -1){
                        //don't have base url, lets add
                        if(final_url.indexOf(window.location.origin) == 0){
                            //full path
                            var path = base_url + '/' + final_url.substring(window.location.origin.length);
                            final_url = window.location.origin + path.replace(/\/{2,}/g, '/');
                        }else{
                            //relative path
                            var path = base_url + '/' + $(this).attr('src');
                            final_url = path.replace(/\/{2,}/g, '/');
                        }
                    }
                    if(log_on){console.log('img path ' + $(this).attr('src') + ' converted to ' + final_url)};
                    $(this).attr('src',final_url);
                });
            }
        }

        var _init = function () {
            $(window.document).ready(function ($) {
               _parse_url();
            });
        }

        var VIRTUAL_HOSTY = {
            set_base: function (some_val) {
                base_url = some_val;
            },
            get_base: function () {
                return base_url;
            },
            init: function(){
              _init();
            },
            turnOnDebug: function () {
                log_on = true;
            }

        }
        return VIRTUAL_HOSTY;
    })(jQuery);
}


//VIRTUAL_HOSTY.turnOnDebug();
//VIRTUAL_HOSTY.init();
