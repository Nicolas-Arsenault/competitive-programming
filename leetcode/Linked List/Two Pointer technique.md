Ex: Given a linked list, determine if it has a cycle in it.

- `If there is no cycle, the fast pointer will stop at the end of the linked list.`
- `If there is a cycle, the fast pointer will eventually meet with the slow pointer`

## Linked list cycle

We want to see if the linked list is circular (a node points back to another node).

We use two pointers. a fast one that hops 2 steps a time and a slow one.
if fast eventually catches up to the slow one, well it means that there IS a cycle right.

For this, we need to start the fast pointer ONE step ahead or EQUAL to the head. They will meet eventually.

```
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        
        if(head == null || head.next == null)
        {
            return false;
        }
        
        ListNode slow = head;
        ListNode fast = head;
            
        while(fast != null && fast.next != null && fast.next.next != null)
        {
            if(slow == fast)
            {
                return true;
            }
            
            slow = slow.next;
            fast = fast.next.next;
        }            
        
        return false;
    }
}
```


## Linked liost cycle 2

Now we need to return the node that start the cycle. For thiis we NEEEEEED to start both pointers at the BEGINNING. Once they meet, we do a new algo, which will give out the head of the cycle:

```
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                // Cycle detected
                ListNode ptr1 = head;
                ListNode ptr2 = slow;
                while (ptr1 != ptr2) {
                    ptr1 = ptr1.next;
                    ptr2 = ptr2.next;
                }
                return ptr1; // Start of the cycle
            }
        }

        return null; // No cycle
    }
}

```

## Intersection of two linked list

The idea here is to use one pointer for each list. When a pointer reaches the end (null), it is reassigned to the OTHER list's head, else, it just moves forward till both nodes are equal;.

WHAT THAT DOES:

Well, this makes it so that the pointers are now alligned properly, so you can determine the intersection.

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        ListNode ptr1 = headA;
        ListNode ptr2 = headB;
        
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1 == null ? headB : ptr1.next;
            ptr2 = ptr2 == null ? headA : ptr2.next;
        }
        
        return ptr1;
    }
}
```


## Remove Nth node from the end of the list

```
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) {
            return null;  // If the list is empty, return null.
        }

        int lengthList = 0;
        ListNode temp = head;
        
        // Calculate the length of the list
        while (temp != null) {
            temp = temp.next;
            lengthList++;
        }
        
        // If n equals the length of the list, return the next node (remove the head)
        if (lengthList == n) {
            return head.next;
        }
        
        // Calculate the index of the node to remove
        int targetIndex = lengthList - n;
        
        // Reset temp to the head of the list
        temp = head;
        
        // Traverse to the node just before the one to remove
        while (targetIndex > 1) {
            temp = temp.next;
            targetIndex--;
        }
        
        // Remove the nth node
        temp.next = temp.next.next;
        
        return head;
    }
}

```

## Summary:

**Always examine if the node is null before you call the next field.**

**Carefully define the end conditions of your loop.**

Complexity analisys:

`how many times we will run our loop`

If there is no cycle, the fast pointer takes `N/2 times` to reach the end of the linked list, where N is the length of the linked list.

If there is a cycle, the fast pointer needs `M times` to catch up the slower pointer, where M is the length of the cycle in the list.

Obviously, M <= N. So we will run the loop `up to N times`. And for each loop, we only need constant time. So, the time complexity of this algorithm is `O(N)` in total.

