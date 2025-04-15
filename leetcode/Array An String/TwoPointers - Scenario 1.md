ex: 
> Reverse the elements in an array.

We can use two pointers at the same time to do the iteration: `one starts from the first element and another starts from the last element`

```
public static void reverse(int[] v, int N) {
    int i = 0;
    int j = N - 1;
    while (i < j) {
        swap(v, i, j);  // this is a self-defined function
        i++;
        j--;
    }
}
```

## Reverse String

```
class Solution {
    public void reverseString(char[] s) {
        
        if(s == null || s.length == 0) return;
        
        int left = 0;
        int right = s.length - 1;
        
        while(left < right)
        {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
}
```

### Two Sum II - Input array is sorted

We use two pointers and compare sum to the target to know which pointer to move...


```
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        
        int left = 0;
        int right = numbers.length - 1;
        
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            
            if(sum == target)
            {
                break;
            }
            
            if(sum > target)
            {
                right --;
            }
            else
            {
                left ++;
            }
        }
        
        
        return (new int[] {left + 1, right + 1});
    }
}
```