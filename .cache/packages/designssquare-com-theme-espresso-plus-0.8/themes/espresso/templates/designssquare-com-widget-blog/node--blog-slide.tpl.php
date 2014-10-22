<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>

<li style="width: 573px; float: left; display: block;">
    <?php if($blog_entry['has_audio']):?>
        <div class="right thumbnail col-sm-10 teaser-img-small audio-slide"><?php print $post_media;?></div>
    <?php else: ?>
        <div class="right thumbnail col-sm-4 teaser-img-small"><?php print $post_media;?></div>
    <?php endif;?>

    <h2><a href="<?php print $blog_entry['path_alias'];?>"><?php print $blog_entry['title'];?></a></h2>

<?php print views_trim_text(array('max_length' => 150), $blog_entry['body']).'...';?>

<p><a href="<?php print $blog_entry['path_alias'];?>"><strong><?php print $blog_entry['botton_label'] ?></strong> <i class="icon-arrow-right icon-white"></i></a>
</p>
</li>