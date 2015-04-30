<?php
/**DesignsSquare.com Template API template file - comment.tpl.php with the following TAPI:
 * 1. $comment_tapi
 *
//AUTHOR AUTHOR<br>
$comment_tapi['author']::[ARRAY](info about the comment author)<br>
$comment_tapi['author']['name']::[STRING](the name of the comment author)<br>
$comment_tapi['author']['avatar_url']::[STRING](url to the avatar for comment author. If not
specified, it defaults to '/sites/default/file/avatar.jpg)<br>
$comment_tapi['author']['profile_url']::[STRING](url to the profile of comment author)<br>
//COMMENT INFO<br>
$comment_tapi['comment']::[ARRAY](info about the comment itself)
$comment_tapi['comment']['subject']::[STRING](the subject of the comment)<br>
$comment_tapi['comment']['content']::[STRING](the content of the comment)<br>
$comment_tapi['comment']['date']::[STRING](the date of the comment)<br>
//COMMENT DATE RAW<br>
$comment_tapi['comment']['date_raw']::[ARRAY](date broken into month, day, year)<br>
$comment_tapi['comment']['date_raw']['day']::[STRING](the day of comment submitted)<br>
$comment_tapi['comment']['date_raw']['year']::[STRING](the year of comment submitted)<br>
$comment_tapi['comment']['date_raw']['month']::[STRING](the month of comment submitted)<br>
$comment_tapi['subject_type']::[STRING](the date of comment submitted)<br>
//OTHER
$comment_tapi['depth']::[NUMBER](the depth level of the comment with root at 0)
$comment_tapi['children_comments']::[ARRAY](rendable array with all children comments if any)
//COMMENT LINKS<br>
$comment_tapi['links']::[ARRAY](info of the action links for the comment)
$comment_tapi['links']['access']::[BOOLEAN](determines if action links should be displayd for the
current user)<br>
$comment_tapi['links']['edit_url']::[STRING](url to edit action of comment)<br>
$comment_tapi['links']['edit_text']::[STRING](text of the EDIT link)<br>
$comment_tapi['links']['reply_url']::[STRING](url to reply action of comment)<br>
$comment_tapi['links']['reply_text']::[STRING](text of the REPLAY link)<br>
$comment_tapi['links']['delete_url']::[STRING](url to delete action of the comment)<br>
$comment_tapi['links']['delete_text']::[STRING](text of the DELETE link)<br>
 */

?>

<div class="media media-comment">
    <div class="round-box box-mini pull-left">
        <a class="box-inner" href="#">
            <img alt="" class="media-objects img-circle" src="<?php print $comment_tapi['author']['avatar_url'] ?>">
        </a>
    </div>
    <div class="media-body">
        <div class="media-inner">
            <h5 class="media-heading">
                <?php print $comment_tapi['author']['name']?>, <?php print $comment_tapi['comment']['date_raw']['day'].' '. $comment_tapi['comment']['date_raw']['month'].', '.$comment_tapi['comment']['date_raw']['year']?>.
                <?php if($comment_tapi['links']['access']):?>
                    <a class="comment-reply pull-right" href="<?php print $comment_tapi['links']['reply_url'] ?>">
                        <?php print $comment_tapi['links']['reply_text']?>
                    </a>
                <?php endif;?>
            </h5>
            <p>
                <?php print $comment_tapi['comment']['content'];?>
            </p>
        </div>
        <?php if(isset($comment_tapi['children_comments'])):?>
            <?php print drupal_render($comment_tapi['children_comments']); ?>
        <?php endif?>
    </div>
</div>