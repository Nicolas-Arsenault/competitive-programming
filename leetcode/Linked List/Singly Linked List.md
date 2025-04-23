##  Introduction - Singly Linked List

`a reference field` to link to the next node.

![[Pasted image 20250417125348.png]]

In most cases, we will use the `head` node (the first node) to represent the whole list.

`O(N)` time to traverse and find an element

## Add Operation - Singly Linked List

1. Initialize a new node `cur` with the given value;
![[Pasted image 20250417125618.png]]
2. Link the "next" field of `cur` to prev's next node `next`;
![[Pasted image 20250417125709.png]]

3. Link the "next" field in `prev` to `cur`.

`O(1)` time if you have a reference to `prev`

### Add a Node at the Beginning

- Initialize a new node `cur`;
- Link the new node to our original head node `head`.
- Assign `cur` to `head`.

ex: we insert node 9 

![[Pasted image 20250417125850.png]]

and redefine the head

![[Pasted image 20250417125854.png]]

## Delete Operation - Singly Linked List

If we want to delete an existing node `cur` from the singly linked list, we can do it in two steps:

Find cur's previous node `prev` and its next node `next`;

![[Pasted image 20250417130352.png]]

Link `prev` to cur's next node `next`.

![[Pasted image 20250417130358.png]]

`O(N)` time

### Delete the First Node

![[Pasted image 20250417130504.png]]

Then move the head

![[Pasted image 20250417130515.png]]

