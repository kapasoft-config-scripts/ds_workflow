      <?php
                    print '<div class="row contextual-links-region" style="margin-bottom:50px;">';
                    print render($blog_entry['contextual_links']);
                    print '  <div class="span9">';
                    print '            <div class="blog_item">';
      if($blog_entry['has_picture'] || $blog_entry['has_video'] || $blog_entry['has_audio']) :
            if ($blog_entry['has_picture']) :
                //post with Picture
                    print '                 <div class="row">';
                    print '                    <!-- Featured image -->';
                    print '                    <div class="span4 node-post-left">';
                    print '                          <div class="view view-first">';
                    print '                                <img src="' . $blog_entry['picture']['url'] . '" alt="" />';
                    print '                                <div class="mask">';
                    print '                                    <a href="' . $blog_entry['picture']['url'] . '" rel="prettyPhoto" title="'.$blog_entry['picture']['title'].'" class="info"></a>';
                    print '                                    <a href="' . $blog_entry['picture']['url'] . '" class="link"></a>';
                    print '                                </div>';
                    print '                            </div>';
                    print '                             <div class="clearfix"></div>';
                    print '                    </div>';
            elseif($blog_entry['has_video']) :
                    print '                <div class="row">';
                    print '                    <div class="span4 node-post-left">';
                    print '                        <div class="view view-first">';
                    print                               $blog_entry['video']['content'];
                    print '                        </div>';
                    print '                    </div>';
            elseif($blog_entry['has_audio']) :
                print '                <div class="row">';
                print '                    <div class="span4 node-post-left">';
                print '                      <div class="blog-entry-small">';
                print                               $blog_entry['audio']['content'];
                print '                        </div>';
                print '                    </div>';
            endif;
                print '                    <div class="span5 node-post-right">';
                print '                        <!--Post info and Title-->';
                print '                        <div class="blog_head">';
                print '                            <div class="date">';
                print '                                <h6><i class="icon-calendar icon-white"></i>' . $blog_entry['date']['full'] . '</h6>';
                print '                            </div>';
                print '                            <h3><a href="' .$blog_entry['path_alias']. '">' .$blog_entry['title']. '</a></h3>';
                print '                            <div class="meta">';
                print '                                <span><b>By</b> <a href="#">' .$blog_entry['author']. '</a></span>';
//                    print '                                <span><a href="#">VIDEO</a>, <a href="#">MUSIC</a></span>';
                print '                                <span class="last-item"><a href="/' . $blog_entry['path_alias'] . '">' . $blog_entry['comment_count'] . ' Comments</a></span>';
                print '                            </div>';
                print '                              <!--Post content-->';
                print '                            <div class="blog_item_description">';
                print '                                <p>';
                print                                       $blog_entry['summary'];
                print '                                </p>';
                print                              '<!--Read more link-->';
                print '                              <h6><a href="/'.$blog_entry['path_alias'].'">Read more...</a></h6>';
                print '                            </div>';
                print '                            <div style=" margin-bottom:-5px !important;"></div>';
                print '                        </div>';
                print '                    </div>';
                print '                </div>';
        else :
            print '                <!--Simple text post-->';
            print '                        <div class="blog_head">';
            print '                            <div class="date">';
            print '                                <h6><i class="icon-calendar icon-white"></i>' . $blog_entry['date']['full'] . '</h6>';
            print '                            </div>';
            print '                            <h3><a href="/' . $blog_entry['path_alias'] . '">'. $blog_entry['title'] . '</a></h3>';
            print '                            <div class="meta">';
            print '                                <span><b>By</b> <a href="#">' . $blog_entry['author'] . '</a></span>';
//            print '                                <span><a href="#">Post tags</a></span>';
            print '                                <span class="last-item"><a href="'. $blog_entry['path_alias'] .'">' . $blog_entry['comment_count'] . ' Comments</a></span>';
            print '                            </div>';
            print '                            <div style=" margin-bottom:-5px !important;"></div>';
            print '                        </div>';
            print '                        <!--Post content-->';
            print '                        <div class="blog_item_description">';
            print '                            <p>';
            print                                      $blog_entry['summary'];
            print '                            </p>';
            print '                            <!--Read more link-->';
            print '                            <h6><a href="'. $blog_entry['path_alias'] .'">'.$blog_entry['botton_label'].'</a></h6>';
            print '                        </div>';
            endif;

            print '                    </div>';
            print '                </div>';
            print '            </div>';
      ?>