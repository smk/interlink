<?php
// $Id$

/**
 * @file
 * Views filter class for the interlink module.
 */

/**
 * Filter by whether a node acts as interlinked (glossray) term.
 */
class interlink_views_handler_filter_linked extends views_handler_filter_boolean_operator {
  function query() {
    $this->ensure_my_table();
    $operator = !empty($this->value) ? 'IS NOT NULL' : 'IS NULL';
    $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field $operator");
  }
}
