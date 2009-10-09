<?php
// $Id$

/**
 * @file
 * Default views on behalf of the interlink module.
 */

/**
 * Implementation of hook_views_default_views().
 */
function interlink_views_default_views() {
  /*
   * View 'interlink_glossary_nodes'
   */
  $view = new view;
  $view->name = 'interlink_glossary_nodes';
  $view->description = 'A list of all interlinked node contents, by letter.';
  $view->tag = 'interlink';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = TRUE;
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('arguments', array(
    'title' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'glossary' => 1,
      'limit' => '1',
      'case' => 'upper',
      'path_case' => 'lower',
      'transform_dash' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'default_argument_user' => 0,
      'default_argument_fixed' => 'a',
      'default_argument_php' => '',
      'validate_argument_vocabulary' => array(),
      'validate_argument_type' => 'tid',
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'term' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'term',
      'table' => 'interlink_term',
      'field' => 'term',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
    'role' => array(),
    'perm' => '',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('use_ajax', '1');
  $handler->override_option('items_per_page', 36);
  $handler->override_option('use_pager', '1');
  $handler->override_option('distinct', 1);
  $handler->override_option('style_plugin', 'interlink');
  $handler->override_option('row_plugin', 'interlink');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'interlink',
    'links' => 1,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->override_option('path', 'glossary');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Glossary',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('attachment', 'Attachment', 'attachment');
  $handler->override_option('arguments', array(
    'title' => array(
      'default_action' => 'summary asc',
      'style_plugin' => 'unformatted_summary',
      'style_options' => array(
        'count' => 1,
        'override' => 0,
        'items_per_page' => '25',
        'inline' => 1,
        'separator' => ' | ',
      ),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'glossary' => 1,
      'limit' => '1',
      'case' => 'upper',
      'path_case' => 'lower',
      'transform_dash' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'default_argument_user' => 0,
      'default_argument_fixed' => 'a',
      'validate_argument_vocabulary' => array(),
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('attachment_position', 'before');
  $handler->override_option('inherit_arguments', 0);
  $handler->override_option('inherit_exposed_filters', FALSE);
  $handler->override_option('displays', array(
    'default' => 'default',
    'page' => 'page',
  ));
  $views[$view->name] = $view;

  return $views;
}
