/****
 *
 * $options = {}
 * $options.height = '250';
 * $options.target_id = '.mix iframe'; //Selectors used to retrieve height and adjust height
 *
 *
 * To Trigger
 *jQuery(document).ready(function() {
 *   DS_EQUALIZER.equalize({target_id: '.ds-gallery-node iframe, .ds-gallery-node .video-js, .ds-gallery-node img, .ds-gallery-node .mix-inner, .ds-gallery-node .mix-details', height: '250'});
 * });
 */

if (!window.DS_EQUALIZER) {
    /**
          * @singleton
          */
    window.DS_EQUALIZER = (function ($) {

        var $options = {},
            $log_on = false;

        //finds the max height of all items
        var _find_max = function (options) {
            var $allItems = $(options.target_id),
                $maxHeight = 0;

            //loop through each item to find the max value
            $allItems.each(function () {
//                $(this).parent().parent().show();
                var $currentHeight = $(this).height();
                if ($currentHeight > $maxHeight) {
                    $maxHeight = $currentHeight;
                }
            });
            return $maxHeight;
        }

        //equalize the height
        var _equalize = function (options) {
            $(window.document).ready(function ($) {
                var $height = 0;

                if (typeof options.height != 'undefined') {
                    $height = options.height;
                    if($log_on){console.log('height provided ' + $height)}
                }else{
                    $height = _find_max(options);
                    if($log_on){console.log('height was not provided. Found max height: ' + $height)}
                }

                //resize the height
                $(options.target_id).each(function () {
                    $(this).css('height', $height + 'px');
                });
            });
        }

        //public interface...the API for your widget
        return {
            equalize: function (options) {
                _equalize(options);
            },
            max_height: function (options) {//public function called to initialize widget
                return _find_max(options);
            },
            turnOnDebug: function () {//public function to turn on logging
                $log_on = true;
            }
        }
    })(jQuery);
}