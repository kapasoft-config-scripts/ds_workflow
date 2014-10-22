<li class="comment-element">
    <div class="row">
        <div class="comment-avatar">
            <a href="<?php print $comment_tapi['author']['profile_url'] ?>" rel="external nofollow"><img alt=""
                                                                                                         src="<?php print $comment_tapi['author']['gravatar_url'] ?>"
                                                                                                         width="40"
                                                                                                         height="40"
                                                                                                         class="thumbnail"></a>
        </div>
        <div class="comment-meta">
            <cite><a href="<?php print $comment_tapi['author']['profile_url']; ?>"
                     rel="external nofollow"><?php print $comment_tapi['author']['name']; ?></a></cite>
            <p>
                <a href="/"><?php print $comment_tapi['comment']['date']; ?></a>  ·
                <?php if($comment_tapi['links']['access']) : ?>
                    <a href="<?php print $comment_tapi['links']['edit_url']?>"><?php print $comment_tapi['links']['edit_text'] ?></a> ·
                    <a href="<?php print $comment_tapi['links']['reply_url']?>"><?php print $comment_tapi['links']['reply_text'] ?></a> ·
                    <a href="<?php print $comment_tapi['links']['delete_url']?>"><?php print $comment_tapi['links']['delete_text'] ?></a>
                <?php endif;?>
            </p>
        </div>
    </div>
    <div class="row">
        <div>
            <?php print $comment_tapi['comment']['content']; ?>
        </div>
    </div>
</li>
