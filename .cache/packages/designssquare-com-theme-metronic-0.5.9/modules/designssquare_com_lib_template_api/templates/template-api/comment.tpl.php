<?php
/**DesignsSquare.com Template API template file - comment.tpl.php with the following TAPI:
 * 1. $comment_tapi
 *
//AUTHOR INFO<br>
$comment_tapi['author']::[ARRAY](info about the comment author)<br>
$comment_tapi['author']['name']::[STRING](the name of the comment author)<br>
$comment_tapi['author']['avatar_url']::[STRING](url to the avatar for comment author. If not
specified, it defaults to '/sites/default/file/avatar.jpg)<br>
$comment_tapi['author']['profile_url']::[STRING](url to the profile of comment author)<br>
//COMMENT INFO<br>
$comment_tapi['comment']::[ARRAY](info about the comment itself)
$comment_tapi['comment']['subject']::[STRING](the subject of the comment)<br>
$comment_tapi['comment']['content']::[STRING](the content of the comment)<br>
$comment_tapi['comment']['date']::[STRING](the label of subject input field)<br>
$comment_tapi['subject_type']::[STRING](the date of comment submitted)<br>
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

<li class="comment byuser bypostauthor even thread-even depth-1">
    <div class="offset0 span9">
        <div class="comment-container">
            <div class="border-bottom-line border"></div>
            <div class="vertical-top-line border"></div>
            <div class="row">
                <div class="comment-author vcard span3">
                    <div class="row">
                        <div class="span1"><span class="border"><img alt="" src="http://0.gravatar.com/avatar/8fb03a0c2a120a0eb5b4d36b72ccbf40?s=64&amp;d=http%3A%2F%2F0.gravatar.com%2Favatar%2Fad516503a11cd5ca435acc9bb6523536%3Fs%3D64&amp;r=G" class="avatar avatar-64 photo" height="64" width="64"></span></div>
                          <div class="comment-meta commentmetadata reply comment-author-name comment-date span2">
                            <!-- author name -->
                            <cite class="fn">corrado</cite>
                            <!-- date -->
                            <a class="date" href="http://demo.yithemes.com/bazar/nice-clean-the-best-for-your-blog/#comment-10">
                                Jan, 23 - 2013</a>

                            <!-- reply -->
                            <a class="comment-reply-link" href="/bazar/nice-clean-the-best-for-your-blog/?replytocom=10#respond" onclick="return addComment.moveForm(&quot;comment-10&quot;, &quot;10&quot;, &quot;respond&quot;, &quot;26&quot;)"><img class="comment-reply-link" src="http://demo.yithemes.com/bazar/wp-content/themes/bazar/theme/templates/comments/images/comment-reply-link.png" title="reply" alt="+">reply</a>                                </div><!-- .reply -->
                    </div>
                </div><!-- .comment-author .vcard -->

                <div class="comment-content span6">
                    <div class="border borderstrong">
                        <div class="border">

                            <div class="comment-body"><p>also another nice feedback here, uh uh</p>
                            </div>
                        </div>
                    </div>
                </div><!-- .comment-meta .commentmetadata -->
            </div>
        </div><!-- #comment-##  -->
    </div>
</li>