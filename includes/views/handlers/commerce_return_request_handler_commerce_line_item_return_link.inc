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
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text for Return Link'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);

    // The path is set by render_link function so don't allow to set it.
    $form['alter']['path'] = array('#access' => FALSE);
    $form['alter']['external'] = array('#access' => FALSE);
  }

  function render($values) {
    if ($lineitem = $this->get_value($values)) {
      $allowed_status = variable_get('commerce_return_request_order_statuses');
      $order = commerce_order_load($lineitem->order_id);

      // Step 1) Determine if order is in the right status
      if (in_array($order->status, $allowed_status)) {

        // Step 2) Determine if line item is can be returned.
        $allowed_li_types = variable_get('commerce_return_request_li_type');
        if (in_array($lineitem->type, $allowed_li_types)) {

          // Step 3) Determine if product type is allowed to be returnable.
          // @todo Make this product id location more stable.
          // @todo Use entity meta data wrappers.
          $product = commerce_product_load($lineitem->commerce_product['und'][0]['product_id']);
          $allowed_prod_types = variable_get('commerce_return_request_prod_type');
          if (in_array($product->type, $allowed_prod_types)) {
            // Step 4) Create path and send to order owner's return form.
            $path = '/user/' . $order->uid . '/orders/' . $order->order_number . '/return/' . $lineitem->line_item_id;
            return l($this->options['text'], $path);
          } else {
            dpm("Product type incorrect for return link.");
          }
        } else {
          dpm("Line item type incorrect for return link.");
        }
      } else {
        dpm("Order status incorrect for return link.");
      }
    }
  }
}
