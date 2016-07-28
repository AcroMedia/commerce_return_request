# Commerce Return Request

Not to be confused with the much more robust [Commerce Return Merchandise Authorization](https://www.drupal.org/project/commerce_rma),
this little module simply provides a link for each item on an order that you can use when viewing an order on the 
customer's account page, that when clicked, will load a webform of your choice inside your customer's account page. 
There is a small settings page where you can select which webform you want to use. This webform will include additional 
metadata (which product on which order) and tokens that can be used in the email.

You can control which line item types and product types are returnable on the settings form as well.

## Dependencies

* Drupal Commerce 1.x (specifically, commerce_line_item)
* [Webform](https://www.drupal.org/project/webform) 4.x
* [Entity Reference Autocomplete](https://www.drupal.org/project/entityreference_autocomplete)

## Installation

Simply download the module and save it to your favorite `sites/all/modules/contrib` type folder. Enable the module
either in the interface or using `drush en commerce_return_request` on the command line.

## Setup

1. Create a webform that you will use to collect feedback about the product being returned.
2. Go to the settings page under the `Store` dropdown menu and select which webform you want to use when the link is clicked.
3. Edit your customer's account order view (usually this link works: 
   `/admin/structure/views/view/commerce_line_item_table/edit/default`) **Note** You can also create a view that lists
   line items, but it must be line items and not orders. @see Roadmap below.
4. Add the global field called "Return Requested Line Item"
5. Watch in amazement as your customers delight in having an easy way to return the shoes that don't fit or the box of 
   lemon crisps that just weren't lemony enough.

## Roadmap

A great feature that we would love to see posted in the issue queue would be a duplication of our line-item based workflow
made for an entire Order. Basically, an additional settings form element that tracks a webform id for order-level
returns, and a views field that produces an appropriate link.

Another great feature would be to load the return request form in a modal popup. Again, patches welcome :)
