<div class="row contextual-links-region" style="margin-bottom:50px;">
    <?php print render($blog_entry['contextual_links']);?>
    <div class="span8">
        <div class="row">
            <div class="span8">
                <?php if($blog_entry['has_picture']) :?>
        <!--Post with Image-->
                <div class="view view-first">
                    <?php print ' <img src="'.$blog_entry['picture']['url'].'" alt="' . $blog_entry['picture']['alt'] . '" />';?>
                    <div class="mask">
                        <?php print '<a href="' . $blog_entry['picture']['url'] . '" rel="prettyPhoto" title="'.$blog_entry['picture']['title'].'" class="info"></a>';?>
                        <?php print '<a href="' . $blog_entry['picture']['url'] . '" class="link"></a>' ?>
                    </div>
                </div>
    <?php elseif($blog_entry['has_video']) : ?>
        <!--Post with Video-->
                <div class="view view-first">
                    <?php print $blog_entry['video']['content'];?>
                </div>
    <?php elseif($blog_entry['has_audio']) : ?>
        <!--Post with Audio-->
                    <div class="blog-audio-big">
                        <?php print $blog_entry['audio']['content'];?>
                    </div>
                <?php endif; ?>
            </div>
        </div>
    </div>
    <!--Simple text post-->
    <div class="span8">
        <div class="blog_item">
            <!--Post info and Title-->
            <div class="blog_head">
                <div style=" margin-bottom:-5px !important;"></div>
            </div>

            <!--Post content-->
            <div class="blog_post_item_description">
                <div class="blog_head blog_inner">
                    <?php print '<h4>'.$blog_entry['title'].'</h4>';?>
                    <div class="meta">
                        <?php print '<span><b>By</b> <a href="#">' . $blog_entry['author'] . '</a></span>';?>
<!--                        <span><a href="#">DESIGN</a>, <a href="#">WORDPRESS</a></span>-->
                        <?php print '<span class="last-item"><a href="#">' . $blog_entry['comment_count'] . ' Comments</a></span>';?>
                    </div>
                </div>
                <?php print $blog_entry['body']; ?>
            </div>

        </div>
    </div>
    <div class="span8">
        <div class="share">
            <span style="float:left; margin-right:10px;">Share this:</span>
            <div style="float:left">
                <!-- AddThis Button BEGIN -->
                <div class="addthis_toolbox addthis_default_style ">
                    <a class="addthis_counter addthis_pill_style"></a>
                </div>
                <script type="text/javascript">var addthis_config = {"data_track_addressbar":true};</script>
                <script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=ra-4f88195d6026781e"></script>
                <!-- AddThis Button END -->
            </div>
        </div>
    </div>

    <!-- ABOUT AUTHOR-->
    <div class="span8">
        <div class="blog_item_description" style="margin-top: 30px;">
            <?php print '<img class="img-polaroid" src="'.$blog_entry['about_author']['avatar'].'" style="float: left; margin-right: 20px; width: 80px; height: 80px;" alt="author avatar"/>';?>
            <?php print '<h5 style="margin-bottom: 5px; font-weight: 600 !important;">'.$blog_entry['about_author']['title'].'</h5>';?>
            <?php print $blog_entry['about_author']['content']?>
            <div class="clearfix"></div>
        </div>
    </div>
<!--        --><?php //print render($about_author_block);?>
<!--    </div>-->

    <!-- START COMMENTS -->
    <div class="span8">
        <div class="comments_div">
            <?php print '<h3 style="font-weight: 600 !important; text-transform: uppercase !important;">' . $node->comment_count . ' Comment:</h3>';?>
            <!--Render Comments --->
            <?php if (!empty($content['comments']['comments'])) :?>
                <?php print theme('ds_blog_comments', array('comments' => $content['comments']));?>
            <?php endif; ?>
            <!-- Render Comment Form--->
            <?php if (empty($content['comments']['comment_form'])) :?>
                <?php print render($content['links']['comment']);?>
            <?php else: ?>
                <?php print theme('ds_blog_comment_form', array('comment' => $content['comments']));?>
            <?php endif; ?>
        </div>

    </div>

</div>

