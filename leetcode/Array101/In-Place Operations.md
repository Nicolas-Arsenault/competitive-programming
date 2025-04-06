
when we dont create a new array, but modify the input array

### Replace elements with Greatest Element on Right Side

```
class Solution {
    public int[] replaceElements(int[] arr) {
        
        int maxVal = -1;
        
        for(int i = arr.length -1; i >= 0; i --)
        {
            int extract = arr[i];
            arr[i] = maxVal;
            
            if(extract > maxVal)
            {
                maxVal = extract;
            }
            
        }
        
        return arr;
    }
}
```

### A Better Repeated Deletion Algorithm

> Given a _sorted array_, remove the duplicates such that each element appears only once.
> ![[Pasted image 20250405131656.png]]

Using two pointers we can do that easily:

```
class Solution {
    public int removeDuplicates(int[] nums) {
        
        int writer = 1;
        
        for(int reader = 1; reader < nums.length; reader++)
        {
            if(nums[reader - 1] != nums[reader])
            {
                nums[writer++] = nums[reader];
            }
        }
        
        return writer;
        
    }
}
```


In-place operations are valuable when appropriate because they reduce the _space complexity_ of an algorithm. Instead of requiring O(N)O(N) space, we can reduce it down to O(1)O(1).

### Move Zeroes - Two Pointer

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

```
class Solution {
    public void moveZeroes(int[] nums) {
        
        int writer = 0;
        
        for(int reader = 0; reader < nums.length; reader++)
        {
            if(nums[reader] != 0)
            {
                nums[writer++] = nums[reader];
            }
        }
        
        while(writer <= nums.length - 1)
        {
            
            nums[writer++] = 0;
        }
        
    }
}
```

### Sort Array By Parity - Two pointers

Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.

Return _**any array** that satisfies this condition_.

**Input:** nums = [3,1,2,4]
**Output:** [2,4,3,1]

```
class Solution {
    public int[] sortArrayByParity(int[] nums) {
     
        int writer = 0;
        
        for(int reader = 0; reader < nums.length; reader++)
        {
            if(nums[reader] % 2 == 0)
            {
                int temp = nums[reader];
                nums[reader] = nums[writer];
                nums[writer++] = temp;
            }
        }
        
        return nums;
    }
}
```

### Remove elements - two pointer

remove the element val from the array

```
class Solution {
    public int removeElement(int[] nums, int val) {
    
        int writer = 0;
        
        for(int reader = 0; reader < nums.length; reader++)
        {
            if(nums[reader] != val)
            {
                nums[writer++] = nums[reader];
            }
        }
        
        return writer;
    }
        
}
```

