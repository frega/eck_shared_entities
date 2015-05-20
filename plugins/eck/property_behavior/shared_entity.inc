<?php
/**
 * @file
 * ECK shared entities shared flag property behavior plugin.
 *
 * Provides a checkbox widget to toggle whether the eck entity can be shared
 * across host entities.
 */

$plugin = array(
  'label' => 'Shared Entity Flag',
  'default_widget' => 'eck_shared_entities_shared_entity_property_widget',
);

/**
 * Returns array defining share entity flag widget.
 *
 * @param string $property
 *   Name of the property
 * @param array $vars
 *   Additional variables passed to property widget.
 *
 * @return array
 *   Return array of defining share entity flag widget.
 */
function eck_shared_entities_shared_entity_property_widget($property, $vars) {
  $entity = $vars['entity'];
  list($id) = entity_extract_ids($entity->entityType(), $entity);

  $shared_entity_widget = array(
    '#type' => 'checkbox',
    '#title' => t('Share entity'),
    '#default_value' => $entity->{$property},
    '#description' => t('Share this @label entity to make it available for reuse.', array('@label' => $entity->type)),
    '#attributes' => array('data-shared-entity-flag-' . $entity->entityType() => $id),
    '#weight' => 90,
    '#disabled' => !(user_access('edit share flag for all entities') || user_access('edit share flag for ' . $entity->entityType() . ' ' . $entity->type . ' entities')),
  );

  return $shared_entity_widget;
}
