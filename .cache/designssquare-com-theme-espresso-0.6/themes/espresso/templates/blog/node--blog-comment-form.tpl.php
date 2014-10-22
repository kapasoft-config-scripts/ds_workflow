

<?php if ($comment['comment_form']): ?>
    <?php print '<form class="form-horizontal" action="' . $comment['comment_form']['#action'] . '" method="post" id="'.$comment['comment_form']['#id'].'">';?>
<!--        <fieldset>-->
            <legend>Post Your Comment:</legend>
            <div class="control-group">
                <label class="control-label"><strong>Your Comment:</strong></label>
                <div class="controls">
                    <textarea  id="'.$comment['comment_form']['comment_body']['und'][0]['#id'].'" name="comment_body[und][0][value]" class="col-sm-5" rows="6"></textarea>
                </div>
            </div>
            <div class="control-group">
                <div class="control-label">
                    <label><strong>Your Name:</strong></label>
                </div>
                <div class="controls">
                    <input name="name" type="text" class="col-sm-4">
                </div>
            </div>
            <div class="control-group">
                <div class="control-label">
                    <label><strong>Subject</strong></label>
                </div>
                <div class="controls">
                    <input name="subject" type="text" class="col-sm-4">
                </div>
            </div>
            <?php print render($comment['comment_form']['form_build_id']);?>
            <?php print render($comment['comment_form']['form_id']);?>
            <?php print render($comment['comment_form']['form_token']);?>
            <div class="comment-submit">
                <button name="op" id="edit-submit" type="submit" value="Post Comment" class="btn btn-inverse">Submit Comment</button>
            </div>
<!--        </fieldset>-->
    </form>
<?php endif; ?>