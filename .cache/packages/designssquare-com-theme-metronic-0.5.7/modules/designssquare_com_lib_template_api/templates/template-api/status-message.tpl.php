<!--
DesignsSquare.com Template API template file - status-message.tpl.php with following TAPI:
1. $status_message_tapi
   - array of variable for messages - warning, error, status and info with following API:
                $status_message_tapi['status']['enabled']::[BOOLEAN] (true if there is any message of this kind, otherwise false)<br>
                $status_message_tapi['status']['heading']::[STRING] (Heading for the messsages of type Status)<br>
                $status_message_tapi['status']['size']::[STRING](Number of message)<br>
                $status_message_tapi['status']['messages'][N]::[ARRAY] (Array of messages)<br>
                $status_message_tapi['status']['messages'][N]::[STRING](The message itself)<br>
                //ERROR MESSAGE<br>
                $status_message_tapi['error']['enabled']::[BOOLEAN] (true if there is any message of this kind, otherwise false)<br>
                $status_message_tapi['error']['heading']::[STRING] (Heading for the messsages of type Status)<br>
                $status_message_tapi['error']['size']::[STRING](Number of message)<br>
                $status_message_tapi['error']['messages'][N]::[ARRAY] (Array of messages)<br>
                $status_message_tapi['error']['messages'][N]::[STRING](The message itself)<br>
                //WARNING MESSAGE<br>
                $status_message_tapi['warning']['enabled']::[BOOLEAN] (true if there is any message of this kind, otherwise false)<br>
                $status_message_tapi['warning']['heading']::[STRING] (Heading for the messsages of type Status)<br>
                $status_message_tapi['warning']['size']::[STRING](Number of message)<br>
                $status_message_tapi['warning']['messages'][N]::[ARRAY] (Array of messages)<br>
                $status_message_tapi['warning']['messages'][N]::[STRING](The message itself)<br>
                //WARNING MESSAGE<br>
                $status_message_tapi['info']['enabled']::[BOOLEAN] (true if there is any message of this kind, otherwise false)<br>
                $status_message_tapi['info']['heading']::[STRING] (Heading for the messsages of type Status)<br>
                $status_message_tapi['info']['size']::[STRING](Number of message)<br>
                $status_message_tapi['info']['messages'][N]::[ARRAY] (Array of messages)<br>
                $status_message_tapi['info']['messages'][N]::[STRING](The message itself)

-->


<!--WARNING Messages-->
<?php if($status_message_tapi['warning']['enabled']) : ?>
<div class="alert alert-warning alert-dismissible" role="alert">
    <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
    <strong><?php print $status_message_tapi['warning']['heading']?></strong>
    <?php foreach($status_message_tapi['warning']['messages'] as $key => $message): ?>
        <?php if($key == 0 && $status_message_tapi['warning']['size'] == 1 ) :?>
            <div><?php print $message;?></div>
        <?php else : ?>
        <li><?php print $message;?></li>
            <?php endif ?>
    <?php endforeach; ?>
</div>
<?php endif ?>

<!--ERROR Messages-->
<?php if($status_message_tapi['error']['enabled']) : ?>
    <div class="alert alert-danger alert-dismissible" role="alert">
        <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <strong><?php print $status_message_tapi['error']['heading']?></strong>
        <?php foreach($status_message_tapi['error']['messages'] as $key => $message): ?>
            <?php if($key == 0 && $status_message_tapi['error']['size'] == 1 ) :?>
                <div><?php print $message;?></div>
            <?php else : ?>
                <li><?php print $message;?></li>
            <?php endif ?>
        <?php endforeach; ?>
    </div>
<?php endif ?>

<!--STATUS Messages-->
<?php if($status_message_tapi['status']['enabled']) : ?>
    <div class="alert alert-success alert-dismissible" role="alert">
        <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <strong><?php print $status_message_tapi['status']['heading']?></strong>
        <?php foreach($status_message_tapi['status']['messages'] as $key => $message): ?>
            <?php if($key == 0 && $status_message_tapi['status']['size'] == 1 ) :?>
                <div><?php print $message;?></div>
            <?php else : ?>
                <li><?php print $message;?></li>
            <?php endif ?>
        <?php endforeach; ?>
    </div>
<?php endif ?>

<!--INFO Messages-->
<?php if($status_message_tapi['info']['enabled']) : ?>
    <div class="alert alert-info alert-dismissible" role="alert">
        <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>
        <strong><?php print $status_message_tapi['info']['heading']?></strong>
        <?php foreach($status_message_tapi['info']['messages'] as $key => $message): ?>
            <?php if($key == 0 && $status_message_tapi['info']['size'] == 1 ) :?>
                <div><?php print $message;?></div>
            <?php else : ?>
                <li><?php print $message;?></li>
            <?php endif ?>
        <?php endforeach; ?>
    </div>
<?php endif ?>