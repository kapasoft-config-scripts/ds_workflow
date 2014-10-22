<?php

function blog_display(){

    $nid_basic_page = db_select('node', 'n')
        ->fields('n', array('nid'))
        ->fields('n', array('type'))
        ->condition('n.type', 'blog_posts')
        ->range(0,1)
        ->orderBy('nid', 'DESC')
        ->execute()
        ->fetchCol();


    if(isset($nid_basic_page[0]) && is_numeric($nid_basic_page[0])){
        //load first shop node
        $node_to_render = node_load($nid_basic_page[0]);

//        $destination = drupal_get_path_alias("node/".$node_to_render->nid);
//        drupal_goto($destination);

        $content = node_view($node_to_render, 'full');

        //this seems to be standard Drupal content setup, so to be consistant
        $nodes = array(
            'nodes' => array(
                $node_to_render->nid => $content,
                '#sorted' => true,
            )
        );

        //set content in cache so its available for others
        drupal_set_page_content($nodes);

        //load context after content cache is set, so hook_context_load_alter receives the content
        if(module_exists('context')){
            $context = context_load('blog_posts');
            if(!isset($context) && empty($context)){
                drupal_set_message("Context - blog_index is not present", 'error');
            }elseif($context->disabled){
                watchdog(WATCHDOG_NOTICE, 'The widget context for blog_index is disabled');
            }else{
                context_set('context', $context->name, $context);
            }
        }else{
            watchdog(WATCHDOG_NOTICE, 'The module - context is not present. Unable set context for blog_posts');
        }
    }


    return array(
        '#theme' => 'render_blog',
        '#view_mode' => 'full',
        '#type' => 'page',
    );
//    }else{
//        drupal_set_message(t('It appears there is no Blog index created. Please, go to \'Content\'->\'Add Content\'->\'Blog Posts\'. Or enable \'designssquarecom_blog_example_data\' module to import sample data(consult documentation for importing Sample Data)'));
//        return array(
//            '#markup' => '',
//        );
//    }

}