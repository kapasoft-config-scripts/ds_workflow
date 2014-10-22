<div class="blog-post row contextual-links-region">
    <?php print render($blog_entry['contextual_links']);?>
    <div class="meta col-sm-2">
        <dl>
            <dt><p><i class="glyphicon glyphicon-calendar"></i> Date:</p></dt>
            <dd><?php print $blog_entry['date']['full'];?></dd>
            <dt><p><i class="glyphicon glyphicon-list"></i> Categories:</p></dt>
            <dd>
                <?php foreach($blog_entry['category'] as $key => $category) : ?>
                    <?php if($key + 1 < count($blog_entry['category'])): ?>
                        <a href="/<?php print $category['#href'] ?>"><?php echo $category['#title'].','?></a>
                    <?php else: ?>
                        <a href="/<?php print $category['#href'] ?>"><?php echo $category['#title']?></a>
                    <?php endif; ?>
                <?php endforeach;?>
            </dd>
            <dt><p><i class="glyphicon glyphicon-tag"></i> Tags:</p></dt>
            <dd>
                <?php foreach($blog_entry['tag'] as $key => $tag) : ?>
                    <?php if($key + 1 < count($blog_entry['tag'])): ?>
                        <a href="/<?php print $tag['#href'] ?>"><?php echo $tag['#title'].','?></a>
                    <?php else: ?>
                        <a href="/<?php print $tag['#href'] ?>"><?php echo $tag['#title']?></a>
                    <?php endif; ?>
                <?php endforeach;?>
            </dd>
        </dl>
    </div>
    <div class="entry col-sm-10">
        <h2><?php print $blog_entry['title']; ?></h2>

        <?php if($blog_entry['has_picture']) : ?>
            <img src="<?php print $blog_entry['picture']['url']?>" class="thumbnail img-responsive" alt="" />
        <?php elseif($blog_entry['has_video']) :  ?>
            <div class="thumbnail img-responsive"><?php print $blog_entry['video']['content'];?></div>
        <?php elseif($blog_entry['has_audio']) : ?>
<!--            <div class="right thumbnail col-sm-8 teaser-img-small">--><?php //print $blog_entry['audio']['content'];?><!--</div>-->
            <?php print $blog_entry['audio']['content']; ?>
        <?php endif; ?>
        <?php
        print $blog_entry['body'];
        ?>
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
        <div style="clear:both"></div>
        <hr>
        <!-- ABOUT AUTHOR-->
        <div class="span8">
            <div class="blog_item_description" style="margin-top: 30px;">
                <?php print '<img class="img-polaroid" src="'. $blog_entry['about_author']['avatar'] .'" style="float: left; margin-right: 20px; width: 80px; height: 80px;" alt="Builder avatar"/>';?>
                <?php print '<h5 style="margin-bottom: 5px; font-weight: 600 !important;">'. $blog_entry['about_author']['title'] .'</h5>';?>
                <?php print $blog_entry['about_author']['content'];?>
                <div class="clearfix"></div>
            </div>
        </div>
        <div style="clear:both"></div>
        <div class="blog-post row">
            <!--                <div class="meta col-sm-2 no-border">-->
            <!--                </div>-->
            <div class="entry col-sm-12">

                <ol class="blog-comments col-sm-12">
                    <?php if (!empty($content['comments']['comments'])) :?>
                        <?php print theme('ds_blog_comments', array('comments' => $content['comments']));?>
                    <?php endif; ?>
                </ol>

            </div>
            <!-- Render Comment Form--->
            <?php if (empty($content['comments']['comment_form'])) :?>
                <?php print render($content['links']['comment']);?>
            <?php else: ?>
                <h2 class="title comment-form"><?php print t('Add new comment'); ?></h2>
                <?php print render($content['comments']['comment_form']); ?>
                <?php //print theme('ds_blog_comment_form', array('comment' => $content['comments']));?>
            <?php endif; ?>
        </div>

    </div>
</div>



