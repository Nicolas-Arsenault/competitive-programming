## Sorting algos
### Bubble sort

Compare two elements and reposition them. Takes O(n²)

```
class Solution {


    private void bubbleSort(int[] arr) {
        int n = arr.length;
        // Loop through the array for bubble sort passes.
        for (int i = 0; i < n - 1; ++i) {
            // Inner loop to compare and swap elements.
            for (int j = 0; j < n - i - 1; ++j) {
                // Compare and swap if elements are in the wrong order.
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}
```

### Counting sort

min and max value, then count the occurence of each value between those two, then rearrange the array

```
private void countingSort(int[] arr)

{

Map<Integer,Integer> counts = new HashMap<>();

  

int minVal = Arrays.stream(arr).min().getAsInt();

int maxVal = Arrays.stream(arr).max().getAsInt();

  

for(int val : arr)

{

counts.put(val, counts.getOrDefault(val,0) + 1); //maps the val to its count

}

  

int index = 0;

  

for(int val = minVal; val <= maxVal; ++val)

{

while(counts.getOrDefault(val,0) > 0)

{

arr[index] = val;

index += 1;

counts.put(val,counts.get(val) - 1);

}

}

```

### Max Consecutive Ones II - Sliding Window
we can flip only one zero to a one

```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int longestSequence = 0;
        int left = 0;
        int right = 0;
        int numZeroes = 0;

        while(right < nums.length)
        {
            if(nums[right] == 0)
            {
                numZeroes ++;
            }
            
            while(numZeroes == 2)
            {
	            //here  we narrow down the window to skip a 0
                if(nums[left] == 0)
                {
                    numZeroes --;
                }
                
                left ++;
            }
            
            longestSequence = Math.max(longestSequence, right - left + 1);
            right ++;
        }
        return longestSequence;
    }
}
```

### Third Maximum Number

