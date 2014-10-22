```html

Sample Data - to automate import/export sample data for Drupal Themes & Widgets
================================

This is an overview of the custom module - <a href="https://www.drupal.org/sandbox/kapacs/2287423" title="Sample Data">Sample Data</a> developed and used at <a href="http://designssquare.com" title="Drupal widgets and themes">DesignsSquare.com</a> that was published at Drupal.org for anyone that finds it useful

<b>Issue:</b> Widget or Theme needs sample data for kickstart. There is no automatic, easy and standard way to package Sample Data with all of its assets(i.e. images, videos,etc) part of single artifact deliverable for easy install in Drupal.

<b>Solution:</b> Use Features module along with Sample Data module for sample data exports/imports in an automotive manner without another dependency

The common practice to package widgets and themes at DesignsSquare.com delivered to client is by separating the deliverable into 3 parts - code, Structures&Configurations and Sample Data for KickStart all part of one deliverable via Features. The Sample Data part contains sample nodes, menu instances and assets referenced from content, fields and variables.

To automate the packaging process for Sample Data part of the deliverable, we have created Sample Data module. The Sample Data module does the following:
<ul>
<ol> <strong>1.</strong> Export/Imports nodes with Alias path </ol>
<ol> <strong>2.</strong> Export/Imports menus based on Alias path </ol>
<ol> <strong>3.</strong> Handle the assets – images, videos, etc for sample data. Specifically:
    <ul>
	<ol> <strong>A)</strong> assets referenced from sample content or other modules located in default public directory(i.e. sites/default/file)</ol>
        <ol> <strong>B)</strong> assets referenced by fields(both core type or custom type)</ol>
        <ol> <strong>C) </strong>assets referenced by variables </ol>
   </ul>
</ol>
<ol><strong>4.</strong> Overrides for context and StormArm variables</ol>
</ul>


Note: assets referenced by custom fields and variables need to use file_managed functionality to work

Read more in post - <a href="http://margotskapacs.com/2014/07/importexport-sample-data-and-assets-for-kickstart-all-via-features">Import/Export Sample Data And Assets For Kickstart All Via Features</a>
