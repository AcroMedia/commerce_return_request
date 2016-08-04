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
    $options['text_classes'] = array('default' => 'request-create', 'translatable' => FALSE);
    $options['text_view'] = array('default' => 'View Return Request', 'translatable' => TRUE);
    $options['text_view_classes'] = array('default' => 'request-view', 'translatable' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text for Return Link'),
      '#default_value' => $this->options['text'],
    );
    $form['text_classes'] = array(
      '#type' => 'textfield',
      '#title' => t('Classes for above link'),
      '#default_value' => $this->options['text_classes'],
    );
    $form['text_view'] = array(
      '#type' => 'textfield',
      '#title' => t('Text for View Return Request Link'),
      '#default_value' => $this->options['text_view'],
    );
    $form['text_view_classes'] = array(
      '#type' => 'textfield',
      '#title' => t('Classes for above link'),
      '#default_value' => $this->options['text_view_classes'],
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
        $sids = _crr_lineitem_to_sid($line_item->line_item_id);
        if (!empty($sids)) {
          $path = '/user/' . $order->uid . '/orders/' . $order->order_number . '/return/submission/' . $sids[0];
          // Give it a class and allow html (for easy icons)
          $options = array(
            "attributes" => array(
              "class" => $this->options['text_view_classes'],
            ),
            "html" => true,
          );
          return l($this->options['text_view'], $path, $options);

        }
        else {
          // Else allow them to return it.
          $path = '/user/' . $order->uid . '/orders/' . $order->order_number . '/return/' . $line_item->line_item_id;
          $options = array(
            "attributes" => array(
              "class" => $this->options['text_classes'],
            ),
            "html" => true,
          );
          return l($this->options['text'], $path, $options);
        }
      }
    }
  }
}
