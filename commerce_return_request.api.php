<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * Allows modules to alter the node, submission, and $context['args']
 *
 * @param $node
 *   The Webform node on which this submission was made.
 * @param $submission
 *   The Webform submission that was just inserted into the database.
 * @param $args
 *   An array of "args" that is currently used to connect a line item id.
 *   The line item id is $arg[5]. Read the original code to see how the $args
 *   variable is used.
 */
function hook_commerce_return_request_insert_alter(&$node, &$submission, &$args) {

}

/**
 * Allows modules to act after the Return Request is saved.
 *
 * @param $crr_id
 *   The result object (?) of the insert statement.
 * @param $node
 *   The Webform node on which this submission was made.
 * @param $submission
 *   The Webform submission that was just inserted into the database.
 * @param $args
 *   An array of "args" that is currently used to connect a line item id.
 *   The line item id is $arg[5]. Read the original code to see how the $args
 *   variable is used.
 */
function hook_commerce_return_request_insert($crr_id, $node, $submission, $args) {

}

/**
 * Enables modules to alter the saved message.
 *
 * @param string $message
 *   To alter, just set the value of the message to send to drupal_set_message.
 *   Set to false if you want to hide the message.
 */
function hook_commerce_return_request_insert_message_alter(&$message) {

}

/**
 * Enables modules to alter the redirect after save.
 *
 * @param string $path
 *   To alter, just set the value of the path. Set to false if you want to skip
 *   the redirect.
 * @param array $args
 *   Useful context, includes all aruments used to generate the path.
 */
function hook_commerce_return_request_insert_redirect_alter(&$path, $args) {

}

/**
 * Enables modules to alter the rendering of the submission.
 *
 * @param $renderable
 *   A render array that includes the submission data.
 * @param $args
 *   An array of "args" that is currently used to connect a line item id.
 *   The line item id is $arg[5]. Read the original code to see how the $args
 *   variable is used.
 */
function hook_commerce_return_request_submission_pre_render_alter($renderable, $args) {

}

/**
 * Enables modules to alter the rendering of the submission.
 *
 * @param $renderable
 *   A render array that includes the submission data.
 * @param $args
 *   An array of "args" that is currently used to connect a line item id.
 *   The line item id is $arg[5]. Read the original code to see how the $args
 *   variable is used.
 */
function hook_commerce_return_request_submission_post_render_alter($renderable, $args) {

}

/**
 * Allows modules to alter the deleting of submissions.
 *
 * @param bool $continue
 *   True means delete, false means skip delete.
 * @param $submission
 *   The Webform submission that will be deleted from the database.
 */
function hook_commerce_return_request_delete_alter(&$continue, &$submission) {

}

/**
 * Allows modules to react to the deleting of submissions.
 *
 * @param $node
 *   The Webform node on which this submission was made.
 * @param $submission
 *   The Webform submission that was just inserted into the database.
 */
function hook_commerce_return_request_delete($node, $submission) {

}
