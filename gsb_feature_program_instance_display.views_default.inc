<?php
/**
 * @file
 * gsb_feature_program_instance_display.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gsb_feature_program_instance_display_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ee_programs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'EE Programs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'EE Programs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  /* Relationship: Content: Deadlines (field_application_deadlines) */
  $handler->display->display_options['relationships']['field_application_deadlines_value']['id'] = 'field_application_deadlines_value';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['table'] = 'field_data_field_application_deadlines';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['field'] = 'field_application_deadlines_value';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['delta'] = '-1';
  /* Relationship: Field collection item: Entity with the Deadlines (field_application_deadlines) */
  $handler->display->display_options['relationships']['field_application_deadlines_node']['id'] = 'field_application_deadlines_node';
  $handler->display->display_options['relationships']['field_application_deadlines_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_application_deadlines_node']['field'] = 'field_application_deadlines_node';
  $handler->display->display_options['relationships']['field_application_deadlines_node']['relationship'] = 'field_application_deadlines_value';
  /* Relationship: Field collection item: Location Category (field_program_location_category) */
  $handler->display->display_options['relationships']['field_program_location_category_tid']['id'] = 'field_program_location_category_tid';
  $handler->display->display_options['relationships']['field_program_location_category_tid']['table'] = 'field_data_field_program_location_category';
  $handler->display->display_options['relationships']['field_program_location_category_tid']['field'] = 'field_program_location_category_tid';
  $handler->display->display_options['relationships']['field_program_location_category_tid']['relationship'] = 'field_application_deadlines_value';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Text */
  $handler->display->display_options['fields']['field_deadline_text']['id'] = 'field_deadline_text';
  $handler->display->display_options['fields']['field_deadline_text']['table'] = 'field_data_field_deadline_text';
  $handler->display->display_options['fields']['field_deadline_text']['field'] = 'field_deadline_text';
  $handler->display->display_options['fields']['field_deadline_text']['relationship'] = 'field_application_deadlines_value';
  $handler->display->display_options['fields']['field_deadline_text']['label'] = '';
  $handler->display->display_options['fields']['field_deadline_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_deadline_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_deadline_text']['alter']['text'] = '[field_deadline_text] | ';
  $handler->display->display_options['fields']['field_deadline_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_deadline_text']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Field: Publication Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'field_application_deadlines_value';
  $handler->display->display_options['fields']['field_date']['label'] = 'Application Deadline';
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = '[field_deadline_text] [field_date]';
  $handler->display->display_options['fields']['field_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'day_month_and_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Sort criterion: Field: Publication Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['relationship'] = 'field_application_deadlines_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_program_target_id';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program_instance' => 'program_instance',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: All Topics (field_program_topics) */
  $handler->display->display_options['filters']['field_program_topics_tid']['id'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['table'] = 'field_data_field_program_topics';
  $handler->display->display_options['filters']['field_program_topics_tid']['field'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_topics_tid']['value'] = '';
  $handler->display->display_options['filters']['field_program_topics_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_program_topics_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['operator_id'] = 'field_program_topics_tid_op';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['operator'] = 'field_program_topics_tid_op';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['identifier'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    241 => 0,
    71 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    201 => 0,
    221 => 0,
    216 => 0,
    226 => 0,
    231 => 0,
    246 => 0,
    236 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
    206 => 0,
    211 => 0,
    251 => 0,
    256 => 0,
    261 => 0,
    266 => 0,
    271 => 0,
    276 => 0,
    281 => 0,
    291 => 0,
    296 => 0,
  );
  $handler->display->display_options['filters']['field_program_topics_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['vocabulary'] = 'program_topic';
  $handler->display->display_options['filters']['field_program_topics_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Program Category (field_program_category) */
  $handler->display->display_options['filters']['field_program_category_tid']['id'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['table'] = 'field_data_field_program_category';
  $handler->display->display_options['filters']['field_program_category_tid']['field'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_program_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['operator_id'] = 'field_program_category_tid_op';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['label'] = 'Program Category';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['operator'] = 'field_program_category_tid_op';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['identifier'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    241 => 0,
    71 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    201 => 0,
    221 => 0,
    216 => 0,
    226 => 0,
    231 => 0,
    246 => 0,
    236 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
    206 => 0,
    211 => 0,
    251 => 0,
    256 => 0,
    261 => 0,
    266 => 0,
    271 => 0,
    276 => 0,
    281 => 0,
    291 => 0,
    296 => 0,
  );
  $handler->display->display_options['filters']['field_program_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_program_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_category_tid']['vocabulary'] = 'program_category';
  $handler->display->display_options['filters']['field_program_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Publication Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['relationship'] = 'field_application_deadlines_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = 'not empty';
  /* Filter criterion: Content: Display (field_display_on_finder_select) */
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['id'] = 'field_display_on_finder_select_value';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['table'] = 'field_data_field_display_on_finder_select';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['field'] = 'field_display_on_finder_select_value';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['value'] = array(
    'visible' => 'visible',
  );
  /* Filter criterion: Content: Text (field_instance_text) */
  $handler->display->display_options['filters']['field_instance_text_value']['id'] = 'field_instance_text_value';
  $handler->display->display_options['filters']['field_instance_text_value']['table'] = 'field_data_field_instance_text';
  $handler->display->display_options['filters']['field_instance_text_value']['field'] = 'field_instance_text_value';
  $handler->display->display_options['filters']['field_instance_text_value']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'ee-programs';

  /* Display: Upcoming Application Deadlines */
  $handler = $view->new_display('panel_pane', 'Upcoming Application Deadlines', 'upcoming_deadlines');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_date' => 'field_date',
    'field_deadline_text' => 'field_deadline_text',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Publication Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['relationship'] = 'field_application_deadlines_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program_instance' => 'program_instance',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: All Topics (field_program_topics) */
  $handler->display->display_options['filters']['field_program_topics_tid']['id'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['table'] = 'field_data_field_program_topics';
  $handler->display->display_options['filters']['field_program_topics_tid']['field'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_topics_tid']['value'] = '';
  $handler->display->display_options['filters']['field_program_topics_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_program_topics_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['operator_id'] = 'field_program_topics_tid_op';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['operator'] = 'field_program_topics_tid_op';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['identifier'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    241 => 0,
    71 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    201 => 0,
    221 => 0,
    216 => 0,
    226 => 0,
    231 => 0,
    246 => 0,
    236 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
    206 => 0,
    211 => 0,
    251 => 0,
    256 => 0,
    261 => 0,
    266 => 0,
    271 => 0,
    276 => 0,
    281 => 0,
    291 => 0,
    296 => 0,
  );
  $handler->display->display_options['filters']['field_program_topics_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['vocabulary'] = 'program_topic';
  $handler->display->display_options['filters']['field_program_topics_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Program Category (field_program_category) */
  $handler->display->display_options['filters']['field_program_category_tid']['id'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['table'] = 'field_data_field_program_category';
  $handler->display->display_options['filters']['field_program_category_tid']['field'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_program_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['operator_id'] = 'field_program_category_tid_op';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['label'] = 'Program Category';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['operator'] = 'field_program_category_tid_op';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['identifier'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    241 => 0,
    71 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    201 => 0,
    221 => 0,
    216 => 0,
    226 => 0,
    231 => 0,
    246 => 0,
    236 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
    206 => 0,
    211 => 0,
    251 => 0,
    256 => 0,
    261 => 0,
    266 => 0,
    271 => 0,
    276 => 0,
    281 => 0,
    291 => 0,
    296 => 0,
  );
  $handler->display->display_options['filters']['field_program_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_program_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_category_tid']['vocabulary'] = 'program_category';
  $handler->display->display_options['filters']['field_program_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Display (field_display_on_finder_select) */
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['id'] = 'field_display_on_finder_select_value';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['table'] = 'field_data_field_display_on_finder_select';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['field'] = 'field_display_on_finder_select_value';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['value'] = array(
    'visible' => 'visible',
  );
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['group'] = 1;
  /* Filter criterion: Content: Application State (field_application_state) */
  $handler->display->display_options['filters']['field_application_state_value']['id'] = 'field_application_state_value';
  $handler->display->display_options['filters']['field_application_state_value']['table'] = 'field_data_field_application_state';
  $handler->display->display_options['filters']['field_application_state_value']['field'] = 'field_application_state_value';
  $handler->display->display_options['filters']['field_application_state_value']['relationship'] = 'field_application_deadlines_node';
  $handler->display->display_options['filters']['field_application_state_value']['value'] = array(
    2 => '2',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_application_state_value']['group'] = 1;
  /* Filter criterion: Field: Publication Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['relationship'] = 'field_application_deadlines_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'today';
  $handler->display->display_options['pane_title'] = 'Program Application Deadlines: Multiple Criteria';
  $handler->display->display_options['pane_category']['name'] = 'Customizable Content Lists';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['set_view_mode'] = 0;
  $handler->display->display_options['allow']['set_style_plugin'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Upcoming Programs */
  $handler = $view->new_display('panel_pane', 'Upcoming Programs', 'upcoming_programs');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'compact';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  /* Relationship: Content: Deadlines (field_application_deadlines) */
  $handler->display->display_options['relationships']['field_application_deadlines_value']['id'] = 'field_application_deadlines_value';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['table'] = 'field_data_field_application_deadlines';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['field'] = 'field_application_deadlines_value';
  $handler->display->display_options['relationships']['field_application_deadlines_value']['delta'] = '-1';
  /* Relationship: Field collection item: Entity with the Deadlines (field_application_deadlines) */
  $handler->display->display_options['relationships']['field_application_deadlines_node']['id'] = 'field_application_deadlines_node';
  $handler->display->display_options['relationships']['field_application_deadlines_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_application_deadlines_node']['field'] = 'field_application_deadlines_node';
  $handler->display->display_options['relationships']['field_application_deadlines_node']['relationship'] = 'field_application_deadlines_value';
  /* Relationship: Content: Program Format &amp; Location (field_program_location) */
  $handler->display->display_options['relationships']['field_program_location_value']['id'] = 'field_program_location_value';
  $handler->display->display_options['relationships']['field_program_location_value']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['relationships']['field_program_location_value']['field'] = 'field_program_location_value';
  $handler->display->display_options['relationships']['field_program_location_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_instance_date) */
  $handler->display->display_options['sorts']['field_instance_date_value_1']['id'] = 'field_instance_date_value_1';
  $handler->display->display_options['sorts']['field_instance_date_value_1']['table'] = 'field_data_field_instance_date';
  $handler->display->display_options['sorts']['field_instance_date_value_1']['field'] = 'field_instance_date_value';
  /* Sort criterion: Content: Instance Date Text Select (field_instance_date_text_select) */
  $handler->display->display_options['sorts']['field_instance_date_text_select_value']['id'] = 'field_instance_date_text_select_value';
  $handler->display->display_options['sorts']['field_instance_date_text_select_value']['table'] = 'field_data_field_instance_date_text_select';
  $handler->display->display_options['sorts']['field_instance_date_text_select_value']['field'] = 'field_instance_date_text_select_value';
  /* Sort criterion: Content: Text (field_instance_text) */
  $handler->display->display_options['sorts']['field_instance_text_value']['id'] = 'field_instance_text_value';
  $handler->display->display_options['sorts']['field_instance_text_value']['table'] = 'field_data_field_instance_text';
  $handler->display->display_options['sorts']['field_instance_text_value']['field'] = 'field_instance_text_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program_instance' => 'program_instance',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Keywords (field_tag) */
  $handler->display->display_options['filters']['field_tag_tid']['id'] = 'field_tag_tid';
  $handler->display->display_options['filters']['field_tag_tid']['table'] = 'field_data_field_tag';
  $handler->display->display_options['filters']['field_tag_tid']['field'] = 'field_tag_tid';
  $handler->display->display_options['filters']['field_tag_tid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_tag_tid']['value'] = '';
  $handler->display->display_options['filters']['field_tag_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tag_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tag_tid']['expose']['operator_id'] = 'field_tag_tid_op';
  $handler->display->display_options['filters']['field_tag_tid']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['field_tag_tid']['expose']['operator'] = 'field_tag_tid_op';
  $handler->display->display_options['filters']['field_tag_tid']['expose']['identifier'] = 'field_tag_tid';
  $handler->display->display_options['filters']['field_tag_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tag_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    256 => 0,
    21 => 0,
    71 => 0,
    241 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    201 => 0,
    221 => 0,
    216 => 0,
    226 => 0,
    231 => 0,
    246 => 0,
    236 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
    206 => 0,
    211 => 0,
    251 => 0,
    261 => 0,
    266 => 0,
    271 => 0,
    276 => 0,
    281 => 0,
    291 => 0,
    296 => 0,
    301 => 0,
    101 => 0,
    326 => 0,
  );
  $handler->display->display_options['filters']['field_tag_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_tag_tid']['vocabulary'] = 'tag';
  $handler->display->display_options['filters']['field_tag_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: All Topics (field_program_topics) */
  $handler->display->display_options['filters']['field_program_topics_tid']['id'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['table'] = 'field_data_field_program_topics';
  $handler->display->display_options['filters']['field_program_topics_tid']['field'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_topics_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_program_topics_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['operator_id'] = 'field_program_topics_tid_op';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['label'] = 'Program Topic';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['operator'] = 'field_program_topics_tid_op';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['identifier'] = 'field_program_topics_tid';
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    256 => 0,
    21 => 0,
    71 => 0,
    241 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    201 => 0,
    221 => 0,
    216 => 0,
    226 => 0,
    231 => 0,
    246 => 0,
    236 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
    206 => 0,
    211 => 0,
    251 => 0,
    261 => 0,
    266 => 0,
    271 => 0,
    276 => 0,
    281 => 0,
    291 => 0,
    296 => 0,
    301 => 0,
    101 => 0,
    326 => 0,
  );
  $handler->display->display_options['filters']['field_program_topics_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_program_topics_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_topics_tid']['vocabulary'] = 'program_topic';
  $handler->display->display_options['filters']['field_program_topics_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Program Category (field_program_category) */
  $handler->display->display_options['filters']['field_program_category_tid']['id'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['table'] = 'field_data_field_program_category';
  $handler->display->display_options['filters']['field_program_category_tid']['field'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['filters']['field_program_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_program_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['operator_id'] = 'field_program_category_tid_op';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['label'] = 'Program Category';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['operator'] = 'field_program_category_tid_op';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['identifier'] = 'field_program_category_tid';
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    241 => 0,
    71 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    201 => 0,
    221 => 0,
    216 => 0,
    226 => 0,
    231 => 0,
    246 => 0,
    236 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
    206 => 0,
    211 => 0,
    251 => 0,
    256 => 0,
    261 => 0,
    266 => 0,
    271 => 0,
    276 => 0,
    281 => 0,
    291 => 0,
    296 => 0,
  );
  $handler->display->display_options['filters']['field_program_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_program_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_category_tid']['vocabulary'] = 'program_category';
  $handler->display->display_options['filters']['field_program_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Application State (field_application_state) */
  $handler->display->display_options['filters']['field_application_state_value']['id'] = 'field_application_state_value';
  $handler->display->display_options['filters']['field_application_state_value']['table'] = 'field_data_field_application_state';
  $handler->display->display_options['filters']['field_application_state_value']['field'] = 'field_application_state_value';
  $handler->display->display_options['filters']['field_application_state_value']['relationship'] = 'field_application_deadlines_node';
  $handler->display->display_options['filters']['field_application_state_value']['value'] = array(
    3 => '3',
    2 => '2',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_application_state_value']['group'] = 1;
  /* Filter criterion: Content: Display (field_display_on_finder_select) */
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['id'] = 'field_display_on_finder_select_value';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['table'] = 'field_data_field_display_on_finder_select';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['field'] = 'field_display_on_finder_select_value';
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['value'] = array(
    'visible' => 'visible',
  );
  $handler->display->display_options['filters']['field_display_on_finder_select_value']['group'] = 1;
  /* Filter criterion: Field collection item: Location Category (field_program_location_category) */
  $handler->display->display_options['filters']['field_program_location_category_tid']['id'] = 'field_program_location_category_tid';
  $handler->display->display_options['filters']['field_program_location_category_tid']['table'] = 'field_data_field_program_location_category';
  $handler->display->display_options['filters']['field_program_location_category_tid']['field'] = 'field_program_location_category_tid';
  $handler->display->display_options['filters']['field_program_location_category_tid']['relationship'] = 'field_program_location_value';
  $handler->display->display_options['filters']['field_program_location_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_program_location_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_category_tid']['expose']['operator_id'] = 'field_program_location_category_tid_op';
  $handler->display->display_options['filters']['field_program_location_category_tid']['expose']['label'] = 'Location Category (field_program_location_category)';
  $handler->display->display_options['filters']['field_program_location_category_tid']['expose']['operator'] = 'field_program_location_category_tid_op';
  $handler->display->display_options['filters']['field_program_location_category_tid']['expose']['identifier'] = 'field_program_location_category_tid';
  $handler->display->display_options['filters']['field_program_location_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    256 => 0,
    21 => 0,
    71 => 0,
    241 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    201 => 0,
    221 => 0,
    216 => 0,
    226 => 0,
    231 => 0,
    246 => 0,
    236 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
    206 => 0,
    211 => 0,
    251 => 0,
    261 => 0,
    266 => 0,
    271 => 0,
    276 => 0,
    281 => 0,
    291 => 0,
    296 => 0,
    301 => 0,
    101 => 0,
    326 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_category_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_location_category_tid']['vocabulary'] = 'program_location';
  $handler->display->display_options['filters']['field_program_location_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Date -  start date (field_instance_date) */
  $handler->display->display_options['filters']['field_instance_date_value']['id'] = 'field_instance_date_value';
  $handler->display->display_options['filters']['field_instance_date_value']['table'] = 'field_data_field_instance_date';
  $handler->display->display_options['filters']['field_instance_date_value']['field'] = 'field_instance_date_value';
  $handler->display->display_options['filters']['field_instance_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_instance_date_value']['group'] = 2;
  $handler->display->display_options['filters']['field_instance_date_value']['default_date'] = 'today';
  /* Filter criterion: Content: Text (field_instance_text) */
  $handler->display->display_options['filters']['field_instance_text_value']['id'] = 'field_instance_text_value';
  $handler->display->display_options['filters']['field_instance_text_value']['table'] = 'field_data_field_instance_text';
  $handler->display->display_options['filters']['field_instance_text_value']['field'] = 'field_instance_text_value';
  $handler->display->display_options['filters']['field_instance_text_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_instance_text_value']['group'] = 2;
  $handler->display->display_options['pane_title'] = 'Programs: Multiple Criteria';
  $handler->display->display_options['pane_category']['name'] = 'Customizable Content Lists';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['set_view_mode'] = 'set_view_mode';
  $handler->display->display_options['allow']['set_style_plugin'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'field_program_topics_tid' => '',
      'field_program_category_tid' => '',
    ),
  );
  $export['ee_programs'] = $view;

  $view = new view();
  $view->name = 'gsb_program_instance_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'GSB Program Instance Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_authors' => 'field_authors',
    'field_pub_book_title' => 'field_pub_book_title',
    'field_place_of_publication' => 'field_place_of_publication',
    'field_publisher' => 'field_publisher',
    'field_pub_date_month' => 'field_pub_date_month',
    'field_pub_date_day' => 'field_pub_date_day',
    'field_year_of_publication' => 'field_year_of_publication',
    'field_volume_number' => 'field_volume_number',
    'field_issue_number' => 'field_issue_number',
    'field_page_count' => 'field_page_count',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Year (field_year_of_publication) */
  $handler->display->display_options['sorts']['field_year_of_publication_value']['id'] = 'field_year_of_publication_value';
  $handler->display->display_options['sorts']['field_year_of_publication_value']['table'] = 'field_data_field_year_of_publication';
  $handler->display->display_options['sorts']['field_year_of_publication_value']['field'] = 'field_year_of_publication_value';
  $handler->display->display_options['sorts']['field_year_of_publication_value']['order'] = 'DESC';
  /* Sort criterion: Content: Month (field_month) */
  $handler->display->display_options['sorts']['field_month_value']['id'] = 'field_month_value';
  $handler->display->display_options['sorts']['field_month_value']['table'] = 'field_data_field_month';
  $handler->display->display_options['sorts']['field_month_value']['field'] = 'field_month_value';
  $handler->display->display_options['sorts']['field_month_value']['order'] = 'DESC';
  /* Sort criterion: Content: Day (field_pub_date_day) */
  $handler->display->display_options['sorts']['field_pub_date_day_value']['id'] = 'field_pub_date_day_value';
  $handler->display->display_options['sorts']['field_pub_date_day_value']['table'] = 'field_data_field_pub_date_day';
  $handler->display->display_options['sorts']['field_pub_date_day_value']['field'] = 'field_pub_date_day_value';
  $handler->display->display_options['sorts']['field_pub_date_day_value']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'publication' => 'publication',
  );

  /* Display: EVA Field Form */
  $handler = $view->new_display('entity_view', 'EVA Field Form', 'eva_field_form');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'EVA Field Form';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_instance_label' => 'field_instance_label',
    'field_display_on_finder' => 'field_display_on_finder',
    'field_is_application_open' => 'field_is_application_open',
    'edit_node_modal' => 'edit_node_modal',
    'delete_node_modal' => 'delete_node_modal',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_instance_label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_display_on_finder' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_is_application_open' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node_modal' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node_modal' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: GSB: Modal node add link */
  $handler->display->display_options['header']['gsb_node_modal_add_link']['id'] = 'gsb_node_modal_add_link';
  $handler->display->display_options['header']['gsb_node_modal_add_link']['table'] = 'gsb__global';
  $handler->display->display_options['header']['gsb_node_modal_add_link']['field'] = 'gsb_node_modal_add_link';
  $handler->display->display_options['header']['gsb_node_modal_add_link']['bundle'] = 'program_instance';
  $handler->display->display_options['header']['gsb_node_modal_add_link']['text'] = 'Create a new program instance';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no program instances for this program.';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_target_id']['id'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['table'] = 'field_data_field_program';
  $handler->display->display_options['relationships']['field_program_target_id']['field'] = 'field_program_target_id';
  $handler->display->display_options['relationships']['field_program_target_id']['label'] = 'Program';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Instance Label */
  $handler->display->display_options['fields']['field_instance_label']['id'] = 'field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['table'] = 'field_data_field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['field'] = 'field_instance_label';
  $handler->display->display_options['fields']['field_instance_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_instance_label']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Display on program. */
  $handler->display->display_options['fields']['field_display_on_finder']['id'] = 'field_display_on_finder';
  $handler->display->display_options['fields']['field_display_on_finder']['table'] = 'field_data_field_display_on_finder';
  $handler->display->display_options['fields']['field_display_on_finder']['field'] = 'field_display_on_finder';
  $handler->display->display_options['fields']['field_display_on_finder']['label'] = 'Display';
  $handler->display->display_options['fields']['field_display_on_finder']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_display_on_finder']['alter']['text'] = '<span class="display-on-finder-data hide_this" data-nid="[nid]" data-display-finder="[field_display_on_finder-value]"></span>';
  $handler->display->display_options['fields']['field_display_on_finder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_on_finder']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_display_on_finder']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Field: Content: Edit link (in modal) */
  $handler->display->display_options['fields']['edit_node_modal']['id'] = 'edit_node_modal';
  $handler->display->display_options['fields']['edit_node_modal']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node_modal']['field'] = 'edit_node_modal';
  $handler->display->display_options['fields']['edit_node_modal']['label'] = '';
  $handler->display->display_options['fields']['edit_node_modal']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link (in modal) */
  $handler->display->display_options['fields']['delete_node_modal']['id'] = 'delete_node_modal';
  $handler->display->display_options['fields']['delete_node_modal']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node_modal']['field'] = 'delete_node_modal';
  $handler->display->display_options['fields']['delete_node_modal']['label'] = '';
  $handler->display->display_options['fields']['delete_node_modal']['element_label_colon'] = FALSE;
  /* Field: Content: Clone link (in modal) */
  $handler->display->display_options['fields']['clone_node_modal']['id'] = 'clone_node_modal';
  $handler->display->display_options['fields']['clone_node_modal']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['clone_node_modal']['field'] = 'clone_node_modal';
  $handler->display->display_options['fields']['clone_node_modal']['label'] = '';
  $handler->display->display_options['fields']['clone_node_modal']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_instance_date) */
  $handler->display->display_options['sorts']['field_instance_date_value']['id'] = 'field_instance_date_value';
  $handler->display->display_options['sorts']['field_instance_date_value']['table'] = 'field_data_field_instance_date';
  $handler->display->display_options['sorts']['field_instance_date_value']['field'] = 'field_instance_date_value';
  $handler->display->display_options['sorts']['field_instance_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_program_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program_instance' => 'program_instance',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'program',
  );
  $handler->display->display_options['show_on'] = 'form';
  $export['gsb_program_instance_listing'] = $view;

  return $export;
}
