// $Id$

Drupal.verticalTabs = Drupal.verticalTabs || {};

Drupal.verticalTabs.interlink = function() {
  function lineCount(text) {
    return text.replace(/^\s+|\s+$/g, '').split("\n").length;
  }

  var output;
  var abbreviations = $('#edit-interlink-abbreviations').val();
  var synonyms = $('#edit-interlink-synonyms').val();
  if (abbreviations) {
    output = Drupal.formatPlural(lineCount(abbreviations), '1 abbreviation', '@count abbreviations');
  }
  else {
    output = Drupal.t('No abbreviations');
  }
  output += ', ';
  if (synonyms) {
    output += Drupal.formatPlural(lineCount(synonyms), '1 synonym', '@count synonyms');
  }
  else {
    output += Drupal.t('no synonyms');
  }
  return output;
}
