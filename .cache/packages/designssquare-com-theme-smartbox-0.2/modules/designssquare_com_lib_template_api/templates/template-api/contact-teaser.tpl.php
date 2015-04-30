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
<div id="cta-3" class="widget-3 widget-last home-widget span3 cta">
    <div class="border-1 border">
        <div class="border-2 border">
            <h3>STAY UPDATED</h3>
            Stay updated with Bazar to enjoy our special promotions!
            <div class="text-image" style="text-align:left"></div>
            <form action="<?php print $contact_tapi['action']?>" method="post" id="<?php print $contact_tapi['id']?>">
                <div class="newsletter-call3 group">
                    <input type="hidden" value="Subscribe Email" name="<?php print $contact_tapi['subject_name'] ?>">
                    <input type="hidden" value="Website" name="<?php print $contact_tapi['name_name'] ?>">
                    <div class="newsletter-input">
                        <input type="text" class="email-field text-field autoclear"
                               placeholder="INSERT YOUR MAIL ADDRESS" id="email" name="<?php print $contact_tapi['email_name']?>">
                    </div>
                    <input type="hidden" class="email-field text-field autoclear"
                           value="Subscribe Email Form submission" name="<?php print $contact_tapi['message_name'] ?>">
                </div>
                <div class="newsletter-submit">
                    <input type="submit" name="<?php $contact_tapi['submit_name'] ?>" class="submit-field" value="SUBSCRIBE">
                </div>
                <?php
                print $contact_tapi['hidden_input'];
                print $contact_tapi['hidden_input2'];
                print $contact_tapi['hidden_input3'];
                ?>
            </form>
            <div class="clear">
            </div>
        </div>
    </div>
</div>