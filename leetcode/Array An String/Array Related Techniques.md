3. [Binary search](https://leetcode.com/explore/learn/card/binary-search/) is also an important technique used to search a specific element in a sorted array.
4. We have introduced two-pointer technique in this chapter. It is not easy to use this technique flexibly. This technique can also be used to solve:

- [Slow-pointer and fast-pointer problem in Linked List](https://leetcode.com/explore/learn/card/linked-list/214/linked-list-two-pointer/)
- Sliding Window Problem

## Rotate Array - Reversing 

```
class Solution {
    public void rotate(int[] nums, int k) {
        
        
        k %= nums.length;
        
        //reverse all elements
        reverse(nums, 0, nums.length - 1);
        
        
        //reverse first k elements
        reverse(nums, 0, k - 1);
        
        //reverse remaining elements
        reverse(nums, k, nums.length - 1);
        
    }
    
    private void reverse(int[] nums, int start, int end)
    {
        while(start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            
            start ++;
            end --;
        }
    }
}


```

### Pascal's triangle 2
```
class Solution {
    public List<Integer> getRow(int rowIndex) {
            
        List<List<Integer>> triangle = new ArrayList<>();
        List<Integer> firstRow = new ArrayList<>();
        firstRow.add(1);
        
        triangle.add(firstRow);
        
        for(int i = 1; i <= rowIndex; i++ )
        {
            List<Integer> currRow = new ArrayList<>();
            currRow.add(1);
            List<Integer> prevRow = triangle.get(i-1);
            
            for(int j = 0; j < prevRow.size() - 1; j ++)
            {
                currRow.add(prevRow.get(j) + prevRow.get(j+1));
            }
            
            
            currRow.add(1);
            triangle.add(currRow);
        }
        
        return triangle.get(rowIndex);
        
    }
}
```

## Reverse Words in a string

```
class Solution {
    public String reverseWords(String s) {
        
        int begin = 0;
        int end = 0;
        
        s = s.trim().replaceAll(" +", " ");
        
        s = reverse(s.toCharArray(), 0, s.length() - 1);
        
        while(end < s.length())
        {
            
            if(s.charAt(end) == ' ' || end == s.length() - 1)
            {
                if(end == s.length() - 1)
                {
                    s = reverse(s.toCharArray(), begin, end);
                }
                else
                {
                    s = reverse(s.toCharArray(), begin, end - 1);
                }
                
                begin = end + 1;
            }
            end ++;
            
        }
        
      //  s.trim().replaceAll(" +", " ");
        
        return s;
        
    }
    
    private String reverse(char words[],int begin, int end)
    {
        while(begin < end)
        {
            char temp = words[begin];
            words[begin] = words[end];
            words[end] = temp;
            
            begin ++;
            end--;
        }
        
        return String.valueOf(words);
    }
}
```

## Reverse Words in a String ll

```
class Solution {
    public String reverseWords(String s) {
        
        int start = 0, end = 0;
        char[] words = s.toCharArray();
        
        while(end < s.length())
        {
            if(s.charAt(end) == ' ' || end == s.length() - 1)
            {
                if(s.charAt(end) == ' ')
                {
                    reverse(words, start, end - 1);
                }
                else
                {
                    reverse(words, start, end);
                }
                
                start = end + 1;
            }
            end ++;
        }
        
        return (new String(words));
        
    }
    
    private void reverse(char[] word, int start, int end)
    {
        while(start < end)
        {
            char temp = word[start];
            word[start] = word[end];
            word[end] = temp;
            
            start ++;
            end --;
        }
    }
}
```


## Remove dupes from sorted array:
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

## Move zeroes

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

