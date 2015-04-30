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

<div class="comments-form">
    <h3 class="comment-form small-screen-center">
        Add your comment
    </h3>
    <form action="<?php print $comment_form_tapi['action'] ?>" method="post" id="commentform" class="comment-form">
        <fieldset>
            <div class="control-group">
                <div class="controls">
                    <input id="name" name="<?php print $comment_form_tapi['name_name'];?>"
                           type="text"
                           class="input-xlarge"
                           placeholder="<?php print $comment_form_tapi['name_value'];?>">
                </div>
            </div>
            <div class="control-group">
                <div class="controls">
                    <input id="email"
                           class="input-xlarge"
                           name="<?php print $comment_form_tapi['email_name'];?>"
                           type="text"
                           placeholder="<?php print $comment_form_tapi['email_value'];?>">
                </div>
            </div>
            <div class="control-group">
                <div class="controls">
                    <textarea id="message"
                              class="input-xxlarge"
                              name="<?php print $comment_form_tapi['message_name'];?>"
                              rows="5"
                              placeholder="<?php print $comment_form_tapi['message_value'];?>"></textarea>
                </div>
            </div>
            <div class="control-group">
                <div class="controls small-screen-center">
                    <button class="btn btn-primary" type="submit" name="<?php print $comment_form_tapi['submit_name'];?>"><?php print $comment_form_tapi['submit_label'];?></button>
                    <?php print $comment_form_tapi['hidden_input'];?>
                    <?php print $comment_form_tapi['hidden_input2'];?>
                    <?php print $comment_form_tapi['hidden_input3'];?>
                </div>
            </div>
        </fieldset>
    </form>
</div>

