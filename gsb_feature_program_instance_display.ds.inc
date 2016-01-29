<?php
/**
 * @file
 * gsb_feature_program_instance_display.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function gsb_feature_program_instance_display_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'featured_program';
  $ds_view_mode->label = 'Featured Program';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['featured_program'] = $ds_view_mode;

  return $export;
}
