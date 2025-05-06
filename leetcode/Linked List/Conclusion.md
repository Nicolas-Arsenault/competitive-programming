![[comparison_of_time_complexity.png]]

## Merge Two Sorted Lists
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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        //Edge cases
        if(list1 == null && list2 == null) return null;
        if(list1 == null) return list2;
        if(list2 == null) return list1;
        
        //Pred head and keep track of prev node (to arrange the links)
        ListNode pred = new ListNode(-1);
        ListNode prev = pred;
        
        //Go through the whole list of l1 or l2...
        while(list1 != null && list2 != null)
        {
            //Verify smallest and rearrange links
            if(list1.val <= list2.val)
            {
                prev.next = list1;
                list1 = list1.next;
            }
            else
            {
                prev.next = list2;
                list2 = list2.next;
            }
            
            prev = prev.next;
        }
        
        //Rearrange rest of list.
        prev.next = list1 == null ? list2 : list1;
        
        return pred.next;
        
    }
}
```

## Add two numbers

```
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        int remainder = 0;
        ListNode pred = new ListNode(-1);
        ListNode prev = pred;
        
        while (l1 != null || l2 != null || remainder > 0) {
            sum = remainder;
            
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            
            remainder = sum / 10;
            sum %= 10;
            
            prev.next = new ListNode(sum);
            prev = prev.next;
        }
        
        return pred.next;
    }
}

```


## To REVIEW LATER
## Flatten a Multilevel DoublyLlinked list - DFS and RECURSION

```
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    
    private Node dfs(Node prev, Node curr)
    {
        if(curr == null) return prev;
        curr.prev = prev;
        prev.next = curr;

        Node tempNext = curr.next;

        Node tail = dfs(curr,curr.child);
        curr.child = null;

        return dfs(tail, tempNext);
    }

    public Node flatten(Node head) {
        
        if(head == null) return null;

        Node sentinel = new Node(0,null,head,null);

        dfs(sentinel, head);

        sentinel.next.prev=null;
        return sentinel.next;

    }
}
```

## Insert into a cyclic sorted list

```
class Solution {
    public Node insert(Node head, int insertVal) {
        if (head == null) {
            Node newNode = new Node(insertVal);
            newNode.next = newNode;
            return newNode;
        }

        Node prev = head;
        Node curr = head.next;
        boolean inserted = false;

        do {
            if (prev.val <= insertVal && insertVal <= curr.val) {
                // Normal case: insertVal is between prev and curr
                inserted = true;
            } else if (prev.val > curr.val) {
                // Wrap-around point: max to min
                if (insertVal >= prev.val || insertVal <= curr.val) {
                    inserted = true;
                }
            }

            if (inserted) {
                Node newNode = new Node(insertVal, curr);
                prev.next = newNode;
                return head;
            }

            prev = curr;
            curr = curr.next;

        } while (prev != head);

        // If we didn't insert in the loop, insert anywhere (e.g., all values are the same)
        Node newNode = new Node(insertVal, curr);
        prev.next = newNode;
        return head;
    }
}

```

## Rotate list:

```
class Solution {
    public ListNode rotateRight(ListNode head, int k) {

        if(head == null || head.next == null || k == 0) return head;
        
        int len = 1;
        ListNode curr = head;
        
        while(curr.next != null)
        {
            curr = curr.next;
            len ++;
        }
        
        curr.next = head;
        k %= len; // k % len
        int tailPos = len -k;
        ListNode tail = head;
        
        for(int i = 0; i < tailPos - 1; i ++) tail = tail.next;
        
        ListNode newHead = tail.next;
        tail.next = null;
        
        return newHead;
    }
}

```

## Copy List with Random Pointer
```
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        
        if(head == null) return null;
        
        HashMap<Node,Node> nodeMap = new HashMap<>();
        
        Node curr = head;
        nodeMap.put(curr, new Node(curr.val));
        
        while(curr != null)
        {
            Node currClone = nodeMap.get(curr);
            
            if(curr.random != null && !nodeMap.containsKey(curr.random))
            {
                nodeMap.put(curr.random, new Node(curr.random.val));
            }
            
            Node randomClone = nodeMap.get(curr.random);
            currClone.random = randomClone;
            
            if(curr.next != null && !nodeMap.containsKey(curr.next))
            {
                nodeMap.put(curr.next, new Node(curr.next.val));
            }
            
            Node nextClone = nodeMap.get(curr.next);
            currClone.next = nextClone;
            
            currClone = currClone.next;
            curr = curr.next;
        }
        
        return nodeMap.get(head);
    }
}
```


