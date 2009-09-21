<?php
// $Id$

/**
 * @file
 * Provide views data and handlers for the interlink module.
 */

/**
 * Implementation of hook_view_data().
 */
function interlink_views_data()  {
  $data['interlink_term']['table']['group'] = t('Node');

  // Let Views know that our example table joins to the 'node'
  // base table. This means it will be available when listing
  // nodes and automatically make its fields appear.
  $data['interlink_term']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'object_id',
      'extra' => array(
        array('field' => 'object_type', 'value' => 'node', 'operator' => '=')
      ),
    ),
  );

  $data['interlink_term']['term'] = array(
    'title' => t('Interlinked'),
    'help' => t('Whether the node acts as interlinked (glossary) term.'),
    'filter' => array(
      'handler' => 'interlink_views_handler_filter_linked',
      'label' => t('Filter nodes that act as interlinked (glossary) term?'),
      'type' => 'yes-no',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function interlink_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'interlink') . '/views',
    ),
    'handlers' => array(
      'interlink_views_handler_filter_linked' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
    ),
  );
}

