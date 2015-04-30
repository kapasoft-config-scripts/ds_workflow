<form id="<?php print $contact_tapi['id'] ?>" action="<?php print $contact_tapi['action'] ?>" method="post">
        <h3 class="form-section">Feedback</h3>
        <p>
            Lorem ipsum dolor sit amet, Ut wisi enim ad minim veniam, quis nostrud exerci. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat consectetuer
        </p>
        <div class="form-group">
            <div class="input-icon">
                <i class="fa fa-check"></i>
                <input type="text" class="form-control" name="<?php print $contact_tapi['subject_name']?>" placeholder="<?php print $contact_tapi['subject_value'];?>">
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
                <input type="email" class="form-control" name="<?php print $contact_tapi['email_name']?>" placeholder="<?php print $contact_tapi['email_value']?>">
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