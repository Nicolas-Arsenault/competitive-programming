## Introduction 
The doubly linked list works in a similar way but has `one more reference field` which is known as `the "prev" field`. With this extra field, you are able to know the previous node of the current node.

![[screen-shot-2018-04-17-at-161130.png]]

```
// Definition for doubly-linked list.
class DoublyListNode {
    int val;
    DoublyListNode next, prev;
    DoublyListNode(int x) {val = x;}
}
```

- We have to `traverse from the head` to get the `i-th` node we want.

For addition and deletion, it will be a little more complicated since we need to take care of the "prev" field as well. We will go through these two operations in next two articles.

## Add Operation

If we want to insert a new node `cur` after an existing node `prev`, we can divide this process into two steps:

link `cur` with `prev` and `next`, where `next` is the original next node of `prev`;
![[screen-shot-2018-04-28-at-173045.png]]

Then
re-link the `prev` and `next` with `cur`.

![[screen-shot-2018-04-28-at-173055.png]]

##  Delete Operation - Doubly Linked List
If we want to delete an existing node `cur` from the doubly linked list, we can simply link its previous node `prev` with its next node `next`.

![[screen-shot-2018-04-17-at-161130 1.png]]

![[screen-shot-2018-04-18-at-142428.png]]

## Implement a doubly linked list (to redo)

```
public class ListNode {
    int val;
    ListNode next;
    ListNode prev;
    ListNode(int x) { val = x; }
}

class MyLinkedList {
    int size;
    ListNode head, tail; // two sentinels

    public MyLinkedList() {
        size = 0;
        head = new ListNode(0); // sentinel head
        tail = new ListNode(0); // sentinel tail
        head.next = tail;
        tail.prev = head;
    }

    public int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode curr = head.next;
        for (int i = 0; i < index; i++) curr = curr.next;
        return curr.val;
    }

    public void addAtHead(int val) {
        addAtIndex(0, val);
    }

    public void addAtTail(int val) {
        addAtIndex(size, val);
    }

    public void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;

        ListNode pred = head;
        for (int i = 0; i < index; i++) pred = pred.next;
        ListNode succ = pred.next;

        ListNode toAdd = new ListNode(val);
        toAdd.prev = pred;
        toAdd.next = succ;
        pred.next = toAdd;
        succ.prev = toAdd;

        size++;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        ListNode pred = head;
        for (int i = 0; i < index; i++) pred = pred.next;
        ListNode toDelete = pred.next;
        ListNode succ = toDelete.next;

        pred.next = succ;
        succ.prev = pred;

        size--;
    }
}

```

à