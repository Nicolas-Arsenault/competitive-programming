
we can use a writer and reader pointer. One fast  runner and one slow runner

The key to solving this kind of problems is to

> Determine the movement strategy for both pointers.

## Remove element
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

##  Max Consecutive Ones

```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) 
    {
        int count = 0;
        int maxCount = 0;
        
        for(int num : nums)
        {
            if(num == 1)
            {
                count ++;
                maxCount = Math.max(maxCount,count);
            }
            else
            {
                count = 0;
            }
        }
        
        return maxCount;
        
    }
}
```

## minimum size subarray sum - Sliding Window


we try to minimize the window size as little as possible before extending it again


```
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        
        int left = 0;
        int sum = 0;
        int result = Integer.MAX_VALUE;
        
        for(int right = 0; right < nums.length; right ++)
        {
            sum += nums[right];
            
            while(sum >= target)
            {
                result = Math.min(result, (right - left) + 1);
                sum -= nums[left];
                left ++;
            }
        }
        
        return result == Integer.MAX_VALUE ? 0 : result;
        
    }
}

```

