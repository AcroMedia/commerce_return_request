<?php

/**
 * @file
 * Definition of commerce_return_request_handler_commerce_line_item_return_link.
 */

/**
 * Field handler to present a link to the return form.
 *
 * @ingroup views_field_handlers
 */
class commerce_return_request_handler_commerce_line_item_return_link extends views_handler_field_entity {

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => 'Return Requested', 'translatable' => TRUE);
    $options['text'] = array('default' => 'View Return Request', 'translatable' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text for Return Link'),
      '#default_value' => $this->options['text'],
    );
    $form['text_view'] = array(
      '#type' => 'textfield',
      '#title' => t('Text for Return Link'),
      '#default_value' => $this->options['text_view'],
    );
    parent::options_form($form, $form_state);

    // The path is set by render_link function so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

  function render($values) {
    if ($line_item = $this->get_value($values)) {
      $order = commerce_order_load(intval($line_item->order_id));
      // Create path and send to order owner's return form.
      if (_crr_can_be_returned($order, $line_item)) {
        // Determine if a return exists.
        $sids = _crr_lineitem_submission($line_item->line_item_id);
        if (!empty($sids)) {
          $path = '/user/' . $order->uid . '/orders/' . $order->order_number . '/return/submission/' . $sids[0];
//          return l($this->options['text_view'], $path);
          return l("View Return Request", $path);

        }
        else {
          // Else allow them to return it.
          $path = '/user/' . $order->uid . '/orders/' . $order->order_number . '/return/' . $line_item->line_item_id;
          return l($this->options['text'], $path);
        }
      }
    }
  }
}
