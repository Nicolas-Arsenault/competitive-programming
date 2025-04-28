
## Reverse Linked list

One solution is to `iterate the nodes in original order and move them to the head of the list one by one`

![[screen-shot-2018-04-14-at-163143.png]]

![[screen-shot-2018-04-14-at-163336.png]]

![[screen-shot-2018-04-14-at-163525.png]]

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        
        //base case
        if(head == null)
        {
            return null;
        }
        
        //declaration
        ListNode curr = head, prev = null;
        
        while(curr != null)
        {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
        
    }
}
```

https://www.youtube.com/watch?v=DyP73kuqeTQ


## Remove linked list elements

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
public ListNode removeElements(ListNode head, int val) {
    // Remove all head nodes with value == val
    while (head != null && head.val == val) {
        head = head.next;
    }

    ListNode temp = head;

    // Remove all other nodes with value == val
    while (temp != null && temp.next != null) {
        if (temp.next.val == val) {
            temp.next = temp.next.next;
        } else {
            temp = temp.next;
        }
    }

    return head;
}

}
```

## Odd even Linked List (to revise)

rearrange a linked list by odd and then even numbers

```
/**

 * Definition for singly-linked list.

 * public class ListNode {

 *     int val;

 *     ListNode next;

 *     ListNode() {}

 *     ListNode(int val) { this.val = val; }

 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }

 * }

 */

class Solution {

    public ListNode oddEvenList(ListNode head) {

        if(head == null) return null;

  

        ListNode odd = head;

        ListNode even = head.next, evenHead = even;

  

        while(even != null && even.next != null)

        {

            odd.next = even.next; // link all the odds one together

            odd = odd.next;

            even.next = odd.next;

            even = even.next;

        }

        odd.next = evenHead;

        return head;

    }

}
```

## Palindrome linked list

we copy all into an array and then use the two pointer technique

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        
        if(head == null) return false;
        
        List<Integer> arr = new ArrayList<>();
        
        ListNode temp = head;
        
        while(temp != null)
        {
            arr.add(temp.val);
            temp = temp.next;
        }
        
        int rightPtr = arr.size() - 1;
        int leftPointer = 0;
        
        while(leftPointer <rightPtr ){
            
            if(arr.get(leftPointer) != arr.get(rightPtr))
            {
                return false;
            }
            leftPointer ++;
            rightPtr--;
        }
        
        return true;
        
    }
}
```

###  Summary - Linked List Classic Problems

**1. Going through some test cases will save you time.**
It is not easy to debug when using a linked list. Therefore, it is always useful to try several different examples on your own to validate your algorithm before writing code.

**2. Feel free to use several pointers at the same time.**
Sometimes when you design an algorithm for a linked-list problem, there might be several nodes you want to track at the same time. You should keep in mind which nodes you need to track and feel free to use several different pointers to track these nodes at the same time.

If you use several pointers, it will be better to give them suitable names in case you have to debug or review your code in the future.

**3. In many cases, you need to track the previous node of the current node.**

You are not able to trace back the previous node in a singly linked list. So you have to store not only the current node but also the previous node. This is different in a doubly linked list which we will cover in the later chapter.

