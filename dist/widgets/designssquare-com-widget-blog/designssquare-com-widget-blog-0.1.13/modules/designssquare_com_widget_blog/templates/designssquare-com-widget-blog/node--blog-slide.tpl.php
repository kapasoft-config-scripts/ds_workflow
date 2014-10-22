
<li style="width: 573px; float: left; display: block;">
<!--    <a class="link_image" href="--><?php //print $blog_entry['path_alias'] ?><!--" title="--><?php //print $blog_entry['title']; ?><!--">-->
        <?php print $post_media;?>
<!--    </a>-->

    <div class="flex-caption blog_item">
        <div class="blog_head">
            <div class="date">
                <h6><i class="icon-calendar icon-white"></i> <?php print $blog_entry['date']['full']; ?> </h6>
            </div>
            <h3><a href="<?php print $blog_entry['path_alias'] ?>"><?php print $blog_entry['title'] ?></a></h3>
        </div>

        <div class="meta">
            <span><b>By</b> <a href="#"><?php print $blog_entry['author'] ?></a></span>
            <span>
                <?php foreach($blog_entry['tag'] as $tag): ?>
                <a href="<?php print $tag['#href'];?>"><?php print $tag['#title']?></a>
                <?php endforeach; ?>
            </span>
            <span class="last-item"><a href="<?php print $blog_entry['path_alias'] ?>"><?php print $blog_entry['comment_count'] ?> Comments</a></span>
        </div>
        <?php print views_trim_text(array('max_length' => 150), $blog_entry['body']).'...'; ?>
        <h6 class="read_more" style="margin-top: 10px !important;">
            <a style="margin-top: 15px;" href="<?php print $blog_entry['path_alias']?>"><?php print $blog_entry['botton_label']; ?></a>
        </h6>
    </div>
</li>

