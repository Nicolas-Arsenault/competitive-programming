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


