<?php if ($comment['comment_form']): ?>
    <div id="respond" style="padding-top:40px;">
        <h4 style="font-weight:600 !important; margin-bottom:12px;">Leave a Reply</h4>

        <?php print '<form class="form" action="' . $comment['comment_form']['#action'] . '" method="post" id="'.$comment['comment_form']['#id'].'">';?>
        <br>
        <input  class="span4" type="text" placeholder="Subject" name="subject" value="" />
        <?php print render($comment['comment_form']['form_build_id']);?>
        <?php print render($comment['comment_form']['form_id']);?>
        <?php print render($comment['comment_form']['form_token']);?>
        <?php print '<textarea type="text" placeholder="Message" id="'.$comment['comment_form']['comment_body']['und'][0]['#id'].'" name="comment_body[und][0][value]" rows="5" style="width:98%"></textarea><br>';?>
        <button name="op" id="edit-submit" value="Save" type="submit"  class="btn btn-small">Post comment</button>
        <p></p>
        </form>
    </div>
<?php endif; ?>