<?php
// $Id$
?>
<!--dl class="interlink-glossary"-->
  <dt id="node-<?php print $node->nid; ?>" class="node<?php if (!$status) { print ' node-unpublished'; } ?>"><dfn id="interlink-node-<?php print $node->nid; ?>"><?php print $title ?></dfn></dt>
  <dd>
    <div class="content clear-block">
      <?php print $content ?>
    </div>
  </dd>
<!--/dl-->
