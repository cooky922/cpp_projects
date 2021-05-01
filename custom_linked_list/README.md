# Custom Linked List
This header contains the fundamentals of doubly linked list with abundant methods. This header requires at least C++ 20. 

# Private Fields
| Name | Type | Description |
| --- | --- | --- |
| `Node` | Class Template | Backbone of the structure |
| `head` | `Node<T>` Object | First node of the linked list |
| `tail` | `Node<T>` Object | Last node of the linked list (unused) |
| `current_node` | `Node<T>` Object | Current node of the linked list, used by `__at_node` method |
| `__at_node` | Private Method | Accessing nodes using the index | 
| `__at_node_from_tail` | Private Method | Accessing nodes starting from tail using the index | 
| `__get_head` | Private Method | Returning a reference to head |
| `__get_tail` | Private Method | Returning a reference to tail (alternative to `tail`) |

# Public Fields
## Main 
| Name | Type | Description | 
| --- | --- | --- |
| constructor | Constructor | Constructs the linked list | 
| destructor | Destructor | Destructs the linked list |
| `operator=` | Copy Assignment | Copies the content from other object to new |
| `assign` | Copy Assignment | Copies the content from other object to new |
| `swap` | Swapping | Swaps the content with other object |

## Element Access
| Name | Type | Description |
| --- | --- | --- |
| `at` | Access Method | Accessing the specified element with bounds checking |
| `operator[]` | Access Method | Accessing the specified element (reference) |
| `front` | Access Method | Accessing the first element |
| `back` | Access Method | Accessing the last element | 

## Iterators
| Name | Type | Description |
| --- | --- | --- |
| `begin` | Iterator Method | Returns an iterator to the beginning | 
| `end` | Iterator Method | Returns an iterator to the end |

## Capacity
| Name | Type | Description | 
| --- | --- | --- |
| `length` | Capacity Method | Returns a number of nodes in a linked list |
| `size` | Capacity Method | Synonymous with `length` |
| `is_empty` | Predicate Method | Checks whether the linked list is empty | 

## Search 
| Name | Type | Description | 
| --- | --- | --- |
| `contains` | Predicate Method | Checks whether the linked list has the specified element |
| `indexof` | TBA | Returns an index of the first occurrence of the specified element in a linked list otherwise returns `-1` |
| `count` | TBA | Counts the number of occurrences of the specified element in a linked list |

## Debugging
These methods aren't recommended and temporary because the sole purpose is the debugging of `Linked_List` element.
| Name | Type | Description |
| --- | --- | --- |
| `print` | TBA | Prints the linked list to the standard output |
| `println` | TBA | Prints the linked list to the standard output that ends with new line | 
| `stringify` | TBA | Returns a `std::string` object that stringified the linked list otherwise returns an empty string if the container is empty | 

## Conversion
| Name | Type | Description |
| --- | --- | --- | 
| `to_carray` | TBA | Converts a linked list to a raw array | 

## Modifiers
| Name | Type | Description | 
| --- | --- | --- |
| `push_front` | TBA | Adds an element to the beginning | 
| `push_back` | TBA | Adds an element to the end | 
| `insert_at` | TBA | Adds an element at the specified position | 
| `append` | TBA | Adds a list of elements to the end | 
| `prepend` | TBA | Adds a list of elements to the beginning |
| `pop_back` | TBA | Removes an element to the end |
| `pop_front` | TBA | Removes an element to the beginning |
| `remove_at` | TBA | Removes an element at the specified position |
| `remove` | TBA | Removes all elements that is equal to the specified element |
| `clear` | TBA | Removes all elements in a list |

# Actions 
## Modifying Sequence 
| Name | Description |
| --- | --- |
| `filter` | TBA | 
| `transform` | TBA | 
| `rotate` | TBA |
| `rotate_left` | TBA |
| `rotate_right` | TBA | 

## Minimum and Maximum 
| Name | Description | 
| --- | --- |
| `min_element` | TBA |
| `max_element` | TBA |

# To Be Added in the Future Implementation
* `filter_copy`
* `transform_copy`
* `rotate_copy`
* `rotate_left_copy`
* `rotate_right_copy`
* `fill` and `fill_copy`
* `fill_n` and `fill_copy_n`
* `for_each` and `for_each_n`
* `reverse` and `reverse_copy`
* `shuffle` and `shuffle_copy`
* `sort` and `sort_copy`
* Lexicographical Compare using `operator<=>`
