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
  $data['interlink_term']['table']['group'] = t('Interlink');

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
    'title' => t('Acts as interlinked term'),
    'help' => t('Whether the node acts as interlinked term.'),
    'filter' => array(
      'handler' => 'interlink_views_handler_filter_linked',
      'label' => t('Filter nodes that act as interlinked term?'),
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

/**
 * Implementation of hook_views_plugins().
 */
function interlink_views_plugins() {
  $path = drupal_get_path('module', 'interlink');
  return array(
    'module' => 'interlink',
    'row' => array(
      'interlink' => array(
        'title' => t('Node as glossary'),
        'help' => t("Display the node with standard node view using the 'interlink' build mode."),
        'handler' => 'interlink_views_plugin_row_node_view',
        'parent' => 'node',
        'path' => $path . '/views',
        'theme' => 'interlink_views_view_row_node',
        'theme path' => $path . '/theme',
        'base' => array('node'), // only works with 'node' as base.
        'uses options' => TRUE,
        'type' => 'normal',
        #'help topic' => 'style-node',
      ),
    ),
    'style' => array(
      'interlink' => array(
        'title' => t('Glossary list'),
        'help' => t('Displays rows as glossary using an HTML definition list.'),
        'handler' => 'interlink_views_plugin_style_definition_list',
        'path' => $path . '/views',
        'theme' => 'interlink_views_view_definition_list',
        'theme path' => $path . '/theme',
        'uses row plugin' => TRUE,
        'uses options' => FALSE,
        'type' => 'normal',
        #'help topic' => 'style-list',
      ),
    ),
  );
}
