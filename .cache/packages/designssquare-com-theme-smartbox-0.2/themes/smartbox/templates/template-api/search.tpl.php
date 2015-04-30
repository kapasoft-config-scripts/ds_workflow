<?php
/*
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
*/
?>
<div class="sidebar-widget widget_search">
    <form id="<?php print $search_tapi['id']?>" action="<?php print $search_tapi['action'];?>" method="post">
        <div class="input-append row-fluid">
            <input class="span12" placeholder="search" type="text" id="<?php print $search_tapi['search_id']?>" name="<?php print $search_tapi['search_name']?>">
            <i class="icon-search"></i>
            <button class="btn hide" type="submit" id="<?php print $search_tapi['submit_id'] ?>">
                search
            </button>
        </div>
        <?php print $search_tapi['hidden_input'] ?>
        <?php print $search_tapi['hidden_input2'] ?>
        <?php print $search_tapi['hidden_input3'] ?>
    </form>
</div>
