<?php
// $Id$

/**
 * @file
 * Contains the glossary node view row style plugin.
 */

/**
 * Plugin which performs a node_view on the resulting object.
 *
 * Most of the code on this object is in the theme function.
 */
class interlink_views_plugin_row_node_view extends views_plugin_row_node_view {
  function option_definition() {
    $options = parent::option_definition();

    // Enforce build mode.
    $options['build_mode'] = array('default' => 'interlink');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Enforce build mode.
    $form['build_mode']['#disabled'] = TRUE;
  }
}
