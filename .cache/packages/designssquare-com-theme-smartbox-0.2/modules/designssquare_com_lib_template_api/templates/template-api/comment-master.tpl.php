<?php
/**DesignsSquare.com Template API template file - comment-master.tpl.php with the following TAPI:
 * 1. $comment_master_tapi
 *    $comment_master_tapi['comments_title']::[STRING](the title of Comments Section configurable via ds_comments_title variable. See <a href="#!/configuration">Configuration</a> Section for more details)<br>
 *    $comment_master_tapi['comment_count']::[STRING](count of the total comments)<br>
 *    $comment_master_tapi['comments']::[ARRAY](array of comments organized into Tree parent-child structure )<br>
 *    $comment_master_tapi['comment_form']::[ARRAY](a rendable array of comment form)<br>
 *
 * 2. The following Drupal provided
 *
 * @file
 * Default theme implementation to provide an HTML container for comments.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 *
 * @ingroup themeable
 *
 */
?>
<div id="comments">
    <div class="clear"></div>

    <?php if(count($comment_master_tapi['comments'])) : ?>
        <h3 id="comments-title">
            <?php print $comment_master_tapi['comments_title'] ?>
        </h3>
    <?php endif ?>
    <div class="row">
        <ol class="commentlist group">
            <?php print render($comment_master_tapi['comments']); ?>
        </ol>
    </div>
</div>
<?php if ($comment_master_tapi['comment_form']): ?>
    <?php print render($comment_master_tapi['comment_form']); ?>
<?php endif; ?>
