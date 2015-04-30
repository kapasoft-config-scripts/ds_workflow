<!--
DesignsSquare.com Template API template file - search.tpl.php with the following TAPI:
1. $search_tapi
   - array of variables for search form with following API:
                $search_tapi['id']::[STRING](search form id)<br>
                $search_tapi['action']::[STRING] (search form action)<br>
                $search_tapi['search_id']::[STRING](search input field id) <br>
                $search_tapi['search_name']::[STRING](search input field name)<br>
                $search_tapi['submit_name']::[STRING](submit button name)<br>
                $search_tapi['submit_id']::[STRING](submit button id)<br>
                $search_tapi['hidden_input']::[RENDERED ARRAY](hidden input 1)<br>
                $search_tapi['hidden_input2']::[RENDERED ARRAY](hidden input 2)<br>
                $search_tapi['hidden_input3']::[RENDERED ARRAY](hidden input 3)<br>
-->

<ul class="page-sidebar-menu" data-auto-scroll="true" data-slide-speed="200">
    <!-- DOC: To remove the search box from the sidebar you just need to completely remove the below "sidebar-search-wrapper" LI element -->
    <li class="sidebar-search-wrapper">
        <!-- BEGIN RESPONSIVE QUICK SEARCH FORM -->
        <!-- DOC: Apply "sidebar-search-bordered" class the below search form to have bordered search box -->
        <!-- DOC: Apply "sidebar-search-bordered sidebar-search-solid" class the below search form to have bordered & solid search box -->
        <form class="sidebar-search" id="<?php print $search_tapi['id']?>" action="<?php print $search_tapi['action'];?>" method="post">
            <a href="javascript:;" class="remove">
                <i class="icon-close"></i>
            </a>

            <div class="input-group">
                <input type="text" class="form-control" placeholder="Search..." id="<?php print $search_tapi['search_id']?>" name="<?php print $search_tapi['search_name']?>">
							<span class="input-group-btn">
						        <a href="javascript:;" class="btn submit" id="<?php print $search_tapi['submit_id'] ?>"><i class="icon-magnifier"></i></a>
                            </span>
            </div>
            <?php print $search_tapi['hidden_input'] ?>
            <?php print $search_tapi['hidden_input2'] ?>
            <?php print $search_tapi['hidden_input3'] ?>
        </form>
        <!-- END RESPONSIVE QUICK SEARCH FORM -->
    </li>
</ul>