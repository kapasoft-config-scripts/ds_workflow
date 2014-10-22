<?php
include_once DRUPAL_ROOT . '/includes/utility.inc';
include_once DRUPAL_ROOT . '/includes/file.inc';

$MODULE_NAME = 'designssquare_com_theme_espresso';
$PATH_TO_MODULE = drupal_get_path('module', $MODULE_NAME);
//source dir or location of the files to import relative to the module specified by variable - $MODULE_NAME
$BASE_SOURCE_REL_PATH = '/assets/img';
//the destination folder relatvie to the public dir of Drupal instance
$DESTINATION_DIR = 'designssquare_theme/espresso/img';

$output = "function _assets_list(){ \n";
$output .= "\$module_dir = drupal_get_path('module', '" . $MODULE_NAME . "');\n";
$output .= "     return array (\n";

$output .= write_file_array('', $MODULE_NAME, $PATH_TO_MODULE, $BASE_SOURCE_REL_PATH, $DESTINATION_DIR);

$output .= "     );\n";
$output .= "}\n";
drupal_set_message("<textarea rows=100 style=\"width: 100%;\">" . $output . '</textarea>');

function write_file_array($rel_path = '', $MODULE_NAME, $PATH_TO_MODULE, $BASE_SOURCE_REL_PATH, $DESTINATION_DIR)
{

    $output = '';
    $full_path = $PATH_TO_MODULE . $BASE_SOURCE_REL_PATH . $rel_path;
    if ($handle = opendir($full_path)) {
        while (false !== ($file = readdir($handle))) {
            if (is_dir($full_path . '/' . $file) && $file != '.' && $file != '..') {
                $output .= write_file_array('/' . $file, $MODULE_NAME, $PATH_TO_MODULE, $BASE_SOURCE_REL_PATH, $DESTINATION_DIR);
            } elseif ($file != '.' && $file != '..') {
                $uri = file_build_uri($DESTINATION_DIR . $rel_path . '/' . $file);
                $output .= "     '" . $uri . "' => array(\n";
                $output .= "     'uri' => '" . $uri . "',\n";
                $output .= "     'filename' => '" . $file . "',\n";
                $output .= "     'source' => \$module_dir.'" . $BASE_SOURCE_REL_PATH . $rel_path . '/' . $file . "',\n";
                $output .= "),\n";
            }
        }
        closedir($handle);
    }
    return $output;
}