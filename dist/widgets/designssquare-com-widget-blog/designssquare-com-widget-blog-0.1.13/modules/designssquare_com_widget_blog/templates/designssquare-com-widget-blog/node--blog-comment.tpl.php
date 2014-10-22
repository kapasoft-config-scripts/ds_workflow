<ul class="unstyled commentsul">
<?php
foreach($ds_blog_comments as $comment_id => $comment){
    $comment_tapi = $comment['comment_tapi'];
?>

    <li class="comment even thread-even depth-1">
        <div class="seppp">
            <div>
                <div class="blog_item_comments_description">

                    <div class="hidden-phone" style="float: left; margin-right: 0px;">
                        <?php print '<img alt="" src="' . $comment_tapi['author']['avatar_url'] . '" class="avatar img-polaroid avatar-70 photo avatar-default" height="70" width="70"/>';?>
                    </div>

                    <?php print '<h6 style="margin-bottom: 4px;">By <span class="colored"><a href="#" rel="external nofollow" class="url">' .$comment_tapi['author']['name'] . '</a></span>';?>
                    <?php print '<a style="color: inherit; padding-left: 7px;" href="http://html.orange-idea.com/builder/hello-world/#comment-26">' . $comment_tapi['date'] . '</a>';?>
                    </h6>

                    <hr style="margin-top: 0px; margin-bottom: 10px;"/>

                    <div style="font-style: italic;">
                        <?php print $comment_tapi['content']; ?>
                    </div>

                </div>
            </div>
        </div>
    </li>
<?php
}
?>
</ul>