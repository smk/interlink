// $Id$

Drupal.verticalTabs = Drupal.verticalTabs || {};

Drupal.verticalTabs.interlink = function() {
  var synonyms = $('#edit-synonyms').val();
  if (synonyms) {
    var count = synonyms.replace(/^\s+|\s+$/g, '').split("\n").length;
    return Drupal.formatPlural(count, '1 synonym', '@count synonyms');
  }
  else {
    return Drupal.t('No synonyms');
  }
}
