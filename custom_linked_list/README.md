# Custom Linked List
This header contains the fundamentals of doubly linked list with abundant methods. This header requires at least C++ 20. 

# Private Members
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

# Main 
| Name | Type | Description | 
| --- | --- | --- |
| constructor | Constructor | Constructs the linked list | 
| destructor | Destructor | Destructs the linked list |
| `operator=` | Copy Assignment | Copies the content from other object to new |
| `assign` | Copy Assignment | Copies the content from other object to new |
| `swap` | Swapping | Swaps the content with other object |

# Element Access
| Name | Type | Description |
| --- | --- | --- |
| `at` | Access Method | Accessing the specified element with bounds checking |
| `operator[]` | Access Method | Accessing the specified element (reference) |
| `front` | Access Method | Accessing the first element |
| `back` | Access Method | Accessing the last element | 

# Iterators
| Name | Type | Description |
| --- | --- | --- |
| `begin` | Iterator Method | Returns an iterator to the beginning | 
| `end` | Iterator Method | Returns an iterator to the end |

# Capacity
| Name | Type | Description | 
| --- | --- | --- |
| `length` | Capacity Method | Returns a number of nodes in a linked list |
| `size` | Capacity Method | Synonymous with `length` |
| `is_empty` | Predicate Method | Checks whether the linked list is empty | 

# Search 
| Name | Type | Description | 
| --- | --- | --- |
| `contains` | Predicate Method | Checks whether the linked list has the specified element |
| `indexof` | TBA | Returns an index of the first occurrence of the specified element in a linked list otherwise returns `-1` |
| `count` | TBA | Counts the number of occurrences of the specified element in a linked list |
