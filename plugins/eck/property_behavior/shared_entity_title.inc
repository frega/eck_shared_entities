<?php
/**
 * @file
 * ECK shared entities shared title property behavior plugin.
 *
 * Provides a text field storing the title for the shared entity so that it can
 * be easily referenced/searched for.
 */

$plugin = array(
  'label' => 'Shared Entity Title (required for the shared flag)',
  'default_widget' => 'eck_shared_entities_shared_entity_title_property_widget',
);

/**
 * Returns array defining shared entity title widget.
 *
 * @param string $property
 *   Name of the property
 * @param array $vars
 *   Additional variables passed to property widget.
 *
 * @return array
 *   Return array of defining share entity title widget.
 */
function eck_shared_entities_shared_entity_title_property_widget($property, $vars) {
  $entity = $vars['entity'];
  list($id) = entity_extract_ids($entity->entityType(), $entity);

  $shared_entity_title_widget = array(
    '#type' => 'textfield',
    '#title' => t('Shared entity title'),
    '#default_value' => $entity->{$property},
    '#description' => t('Enter a descriptive title for this entity so that other users can find it.'),
    '#weight' => 91,
    '#hidden' => TRUE,
    '#disabled' => !(user_access('edit share flag for all entities') || user_access('edit share flag for ' . $entity->entityType() . ' ' . $entity->type . ' entities')),
    '#states' => array(
      'visible' => array(
        '[data-shared-entity-flag-' . $entity->entityType() . '="' . $id . '"]:input' => array('checked' => TRUE),
      ),
    ),
  );

  return $shared_entity_title_widget;
}
