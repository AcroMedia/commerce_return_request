<?php

/**
 * @file
 * Provide views data and handlers for commerce_return_request.module.
 */

/**
 * Implements hook_views_data_alter().
 */
function commerce_return_request_views_data_alter(&$data) {
  $data['commerce_line_item']['return_link']['field'] = array(
    'title' => 'Return Request Link',
    'help' => 'Returns a link that sends you to a predefined webform.',
    'handler' => 'commerce_return_request_handler_commerce_line_item_return_link',
  );
}
