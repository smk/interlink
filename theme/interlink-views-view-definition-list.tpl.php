<?php
// $Id$

/**
 * @file
 * View template to display a definition list.
 *
 * - $title : The title of this group of rows.  May be empty.
 * @ingroup views_templates
 */
?>
<div class="interlink glossary">
  <?php if (!empty($title)): ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <dl class="interlink-glossary">
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
  </dl>
</div>