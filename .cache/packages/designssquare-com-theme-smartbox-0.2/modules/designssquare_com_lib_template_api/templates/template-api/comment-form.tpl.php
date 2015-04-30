<?php
/*Designssquare.com Template API template file - comment-form.tpl.php with following TAPI:
1. $comment_form_tapi
   - array of variables for contact form:
                $comment_form_tapi['id']::[NUMBER](the comment form id)<br>
                $comment_form_tapi['action']::[STRING](the action for the form)<br>
                //NAME INPUT<br>
                $comment_form_tapi['name_name']::[STRING](the name attribute for input field of Name)<br>
                $comment_form_tapi['name_label']::[STRING](the label of name input field)<br>
                $comment_form_tapi['name_type']::[STRING](the type of name input field)<br>
                $comment_form_tapi['name_value']::[STRING](the name of current user or value as configured in Configurations for anonymous user. See <a href="#!/configuration">Configurations</a> section)<br>
                //SUBJECT INPUT<br>
                $comment_form_tapi['subject_name']::[STRING](the name attribute for input field of Subject)<br>
                $comment_form_tapi['subject_label']::[STRING](the label of subject input field)<br>
                $comment_form_tapi['subject_type']::[STRING](the type of subject input field)<br>
                $comment_form_tapi['subject_value']::[STRING](the default subject line as configured in Configurations. See <a href="#!/configuration">Configurations section</a>)<br>
                //EMAIL INPUT<br>
                $comment_form_tapi['email_name']::[STRING](the name attribute for input field of Email)<br>
                $comment_form_tapi['email_label']::[STRING](the label of email input field)<br>
                $comment_form_tapi['email_type']::[STRING](the type of email input field)<br>
                $comment_form_tapi['email_value']::[STRING](the email of current user or value as configured in Configurations for anonymous users. See <a href="#!/configuration">Configurations section</a>)<br>
                //MESSAGE INPUT<br>
                $comment_form_tapi['message_name']::[STRING](the name attribute for input field of Message)<br>
                $comment_form_tapi['message_label']::[STRING](the label of message input field)<br>
                $comment_form_tapi['message_value']::[STRING](the message default value as configured in Configurations. See <a href="#!/configuration">Configurations section</a>)<br>
                //SUBMIT INPUT<br>
                $comment_form_tapi['submit_name']::[STRING](the name attribute for submit button)<br>
                $comment_form_tapi['submit_id']::[STRING](the id for submit button)<br>
                $comment_form_tapi['submit_label']::[STRING](the label for submit button)<br>
                //HIDDEN INPUT[need to be included]<br>
                $comment_form_tapi['hidden_input']::[STRING]<br>
                $comment_form_tapi['hidden_input2']::[STRING]<br>
                $comment_form_tapi['hidden_input3']::[STRING]<br>*/
?>
<div id="comments">
    <div id="respond" class="comment-respond">
        <h3 id="reply-title" class="comment-reply-title">Leave a Reply
            <small><a rel="nofollow" id="cancel-comment-reply-link" href="/?p=23#respond" style="display:none;">Cancel
                    reply</a></small>
        </h3>
        <form action="<?php print $comment_form_tapi['action'] ?>" method="post" id="commentform" class="comment-form">
            <div class="row"><p class="comment-form-author span3">
                    <!--<label for="author">Name</label><i class="icon-user"></i>--><input id="author" name="<?php print $comment_form_tapi['name_name'];?>"
                                                                                           type="text" value=""
                                                                                           size="30"
                                                                                           aria-required="true"
                                                                                           placeholder="<?php print $comment_form_tapi['name_value'];?>"></p>

                <p class="comment-form-email  span3">
                    <!--<label for="email">Email</label><i class="icon-envelope"></i>--><input id="email" name="<?php print $comment_form_tapi['email_name'];?>"
                                                                                               type="text" value=""
                                                                                               size="30"
                                                                                               aria-required="true"
                                                                                               placeholder="<?php print $comment_form_tapi['email_value'];?>"></p>

                <p class="comment-form-url  span3">
                    <!--<label for="url">Website</label><i class="icon-globe"></i>--><input id="url" name="url"
                                                                                            type="text" value=""
                                                                                            size="30"
                                                                                            placeholder="WEBSITE"></p>

                <p class="comment-form-comment">
                    <!--<label for="comment">Your comment</label><i class="icon-pencil"></i>--><textarea id="comment"
                                                                                                         name="<?php print $comment_form_tapi['message_name'];?>"
                                                                                                         cols="45"
                                                                                                         rows="8"
                                                                                                         placeholder="<?php print $comment_form_tapi['message_value'];?>"></textarea>
                </p>

                <div class="clear"></div>
                <p class="form-submit">
                    <input name="<?php print $comment_form_tapi['submit_name'];?>" type="submit" id="commentsubmit" class="submit" value="<?php print $comment_form_tapi['submit_label'];?>">
                    <?php print $comment_form_tapi['hidden_input'];?>
                    <?php print $comment_form_tapi['hidden_input2'];?>
                    <?php print $comment_form_tapi['hidden_input3'];?>
                </p>
            </div>
        </form>
    </div>
    <!-- #respond -->
</div>