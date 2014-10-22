<div class="blog-post row contextual-links-region">
    <?php print render($blog_entry['contextual_links']);?>
    <div class="meta col-sm-3 hidden-xs">
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
    <div class="entry col-sm-9">
        <h2><a href="<?php print $blog_entry['path_alias']; ?>"><?php print $blog_entry['title'];?></a></h2>
        <?php if ($blog_entry['has_picture']) : ?>
            <img src="<?php print $blog_entry['picture']['url'] ?>" class="thumbnail img-responsive" alt="" />
        <?php elseif($blog_entry['has_video']) : ?>
            <div class="thumbnail img-responsive"><?php print $blog_entry['video']['content']; ?></div>
        <?php elseif($blog_entry['has_audio']) : ?>
            <?php print $blog_entry['audio']['content']; ?>
        <?php endif; ?>

        <?php print $blog_entry['summary'];?>
        <p>
            <a href="<?php print $blog_entry['path_alias']; ?>">
                <strong><?php print $blog_entry['botton_label'] ?></strong>
                <span class="glyphicon glyphicon-arrow-right">

                </span>
            </a>
        </p>
        <p>
            <span class="glyphicon glyphicon-comment"></span>
            <strong><?php print $blog_entry['comment_count'];?> Comments</strong>
        </p>
    </div>
</div>