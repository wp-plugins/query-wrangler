<?php

// add default filters to the filter
add_filter('qw_filters', 'qw_filter_post_parent');

function qw_filter_post_parent($filters){

  $filters['post_parent'] = array(
    'title' => 'Post Parent',
    'description' => 'Use only with post type "Page" to show results with the chosen parent ID.',
    'form_callback' => 'qw_filter_post_parent_form',
    'query_display_types' => array('page','widget'),
  );
  return $filters;
}

function qw_filter_post_parent_form($filter)
{
  ?>
  <p>
    <input class="qw-js-title"
           type="text"
           name="<?php print $filter['form_prefix']; ?>[post_parent]"
           value="<?php print $filter['values']['post_parent']; ?>" />
  </p>
  <?php
}