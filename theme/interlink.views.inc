<?php
// $Id$

/**
 * Template preprocessor for theme_interlink_view_row_node().
 */
function template_preprocess_interlink_views_view_row_node(&$vars) {
  $options = $vars['options'];

  // Make sure the variables are defined.
  $vars['node'] = '';
  $vars['comments'] = '';

  $nid = $vars['row']->{$vars['field_alias']};
  if (!is_numeric($nid)) {
    return;
  }

  $node = node_load($nid);

  if (empty($node)) {
    return;
  }

  $node->view = $vars['view'];
  $node->build_mode = 'interlink';
  // TODO Links?
  $vars['node'] = node_view($node, FALSE, FALSE, $options['links']);

  // TODO Comments?
  if (!empty($options['comments']) && function_exists('comment_render')) {
    $vars['comments'] = comment_render($node);
  }
}
