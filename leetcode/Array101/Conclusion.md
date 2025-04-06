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

TreeSet sorts automatically

```
class Solution {
    public int thirdMax(int[] nums) {
        
        TreeSet<Integer> sortedSet = new TreeSet<Integer>();
        
        for(int num : nums)
        {
            //we want to keep the set sorted and 3 elements at most...
            
            if(sortedSet.contains(num))
            {
                continue;
            }
            
            //if size is 3, we want to remove the smallest element
            if(sortedSet.size() == 3)
            {
                if(sortedSet.first() < num)
                {
                    sortedSet.pollFirst();
                    sortedSet.add(num);
                }
            }
            else
            {
                sortedSet.add(num);
            }
        }
        
        if(sortedSet.size() == 3)
        {
            return sortedSet.first();
        }
        
        return sortedSet.last();
        
    }
}
```

### Find all Numbers Disappeared in an Array

Usning a HashMap:

```
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        
        // Hash table for keeping track of the numbers in the array
        // Note that we can also use a set here since we are not 
        // really concerned with the frequency of numbers.
        HashMap<Integer, Boolean> hashTable = new HashMap<Integer, Boolean>();
        
        // Add each of the numbers to the hash table
        for (int i = 0; i < nums.length; i++) {
            hashTable.put(nums[i], true);
        }
        
        // Response array that would contain the missing numbers
        List<Integer> result = new LinkedList<Integer>();
        
        // Iterate over the numbers from 1 to N and add all those
        // that don't appear in the hash table. 
        for (int i = 1; i <= nums.length; i++) {
            if (!hashTable.containsKey(i)) {
                result.add(i);
            }
        }
        
        return result;
    }
}
```


OR


Intuition:
We use the array values to set their index to a negative number to "mark" that this value is seen. All positive values will be unseen, and returned.

```
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        
        List<Integer> list = new ArrayList<>();
        
        for(int i = 0; i < nums.length; i ++)
        {
            int index = Math.abs(nums[i]) - 1;
            
            if(nums[index] > 0)
            {
                nums[index] *= -1;
            }
        }
        
        for(int i = 0; i < nums.length; i ++)
        {
            if(nums[i] > 0)
            {
                list.add(i + 1);
            }
        }
        
        return list;
        
    }
}
```


### Squares of a Sorted **Array**

We get a sorted array with negative in it, we use two pointers left and right to compare values and add them to an array...


```
class Solution {
    
    
    public int[] sortedSquares(int[] nums) {
        
        int[] result = new int[nums.length];
        int right = nums.length -1;
        int left = 0;
        
        //go through the whole array, but keep track of the position of where to add the element in result
        for(int i = nums.length -1; i >=0; i --)
        {
            int square = 0;
            if(Math.abs(nums[left]) > Math.abs(nums[right]))
            {
                square = nums[left] * nums[left];
                left ++;
            }else
            {
                square = nums[right] * nums[right];
                right --;
            }
            
            result[i] = square;
        }
        return result;
        
    }
}
```

