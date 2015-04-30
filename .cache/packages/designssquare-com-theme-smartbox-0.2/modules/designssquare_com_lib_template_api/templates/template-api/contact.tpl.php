<?php
/**
* Designssquare.com Template API template file - contact.tpl.php with following TAPI:
* 1. $contact_tapi
*  - array of variables for contact form:
*                $contact_tapi['id']::[NUMBER](the contact form id)<br>
*                $contact_tapi['action']::[STRING](the action for the form)<br>
*                //NAME INPUT<br>
*                $contact_tapi['name_name']::[STRING](the name attribute for input field of Name)<br>
*                $contact_tapi['name_label']::[STRING](the label of name input field)<br>
*                $contact_tapi['name_type']::[STRING](the type of name input field)<br>
*                $contact_tapi['name_value']::[STRING](the name of current user or value as configured in External Configs for anonymous user. See <a href="#!/configuration">External Configs</a>)<br>
*                //SUBJECT INPUT<br>
*                $contact_tapi['subject_name']::[STRING](the name attribute for input field of Subject)<br>
*                $contact_tapi['subject_value']::[STRING](the value of subject input field)<br>
*                $contact_tapi['subject_label']::[STRING](the label of subject input field)<br>
*                $contact_tapi['subject_type']::[STRING](the type of subject input field)<br>
*                $contact_tapi['subject_value']::[STRING](the default subject line as configured in External Configs. See <a href="#!/configuration">External Configs</a>)<br>
*                //EMAIL INPUT<br>
*                $contact_tapi['email_name']::[STRING](the name attribute for input field of Email)<br>
*                $contact_tapi['email_label']::[STRING](the label of email input field)<br>
*                $contact_tapi['email_type']::[STRING](the type of email input field)<br>
*                $contact_tapi['email_value']::[STRING](the email of current user or value as configured in External Configs for anonymous users. See <a href="#!/configuration">External Configs</a>)<br>
*                //MESSAGE INPUT<br>
*                $contact_tapi['message_name']::[STRING](the name attribute for input field of Message)<br>
*                $contact_tapi['message_label']::[STRING](the label of message input field)<br>
*                $contact_tapi['message_value']::[STRING](the message default value as configured in External Configs. See <a href="#!/configuration">External Configs</a>)<br>
*                //SUBMIT INPUT<br>
*                $contact_tapi['submit_name']::[STRING](the name attribute for submit button)<br>
*                $contact_tapi['submit_id']::[STRING](the id for submit button)<br>
*                $contact_tapi['submit_label']::[STRING](the label for submit button)<br>
*                //HIDDEN INPUT[need to be included]<br>
*                $contact_tapi['hidden_input']::[STRING]<br>
*                $contact_tapi['hidden_input2']::[STRING]<br>
*                $contact_tapi['hidden_input3']::[STRING]
**/
?>
<form id="<?php print $contact_tapi['id'] ?>" action="<?php print $contact_tapi['action'] ?>" method="post">
        <h3 class="form-section">Feedback</h3>
        <p>
            Lorem ipsum dolor sit amet, Ut wisi enim ad minim veniam, quis nostrud exerci. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat consectetuer
        </p>
        <div class="form-group">
            <div class="input-icon">
                <i class="fa fa-check"></i>
                <input type="text" class="form-control" name="<?php print $contact_tapi['subject_name']?>" placeholder="<?php print $contact_tapi['subject_value'] ?>">
            </div>
        </div>
        <div class="form-group">
            <div class="input-icon">
                <i class="fa fa-user"></i>
                <input type="text" class="form-control" name="<?php print $contact_tapi['name_name'];?>" placeholder="<?php print $contact_tapi['name_value'];?>">
            </div>
        </div>
        <div class="form-group">
            <div class="input-icon">
                <i class="fa fa-envelope"></i>
                <input type="email" class="form-control" name="<?php print $contact_tapi['email_name']?>" placeholder="<?php print $contact_tapi['email_value'];?>">
            </div>
        </div>
        <div class="form-group">
            <textarea class="form-control" rows="3=6" name="<?php print $contact_tapi['message_name'] ?>" placeholder="<?php print $contact_tapi['message_value'] ?>"></textarea>
        </div>
        <?php print $contact_tapi['hidden_input']?>
        <?php print $contact_tapi['hidden_input2']?>
        <?php print $contact_tapi['hidden_input3']?>
        <button type="submit" name="<?php print $contact_tapi['submit_name']?>" id="<?php print $contact_tapi['submit_id'] ?>" class="btn green">Submit</button>
    </form>