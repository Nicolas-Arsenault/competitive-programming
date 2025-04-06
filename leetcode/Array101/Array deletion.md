### Deleting From the End of an Array
we use a length variable to keep track of the last element we added, then we reduce the length by 1. Next time we write to the array, it will overwrite the last element:

```
int[] intArr = new int[10];

int length = 0;

//add elements to the first 6 indexes
for(int i =0; i < 6; i ++)
{
	intArr[length] = i;
	length ++;
}

//will overwrite the last value next time we iterate...
length --;
```

### Deleting From the Start of an Array
![[Pasted image 20250403190144.png]]

we move all values to the left from index 1

```
for(int i = 1; i < length; i ++)
{
	intArr[i - 1] = intArr[i];
}

//since we shifted all values to the left, we created a free spot at the end...
length --;
```

### Deleting From Anywhere in the Array

![[Pasted image 20250403190549.png]]

all the elements to the right of the element we want to delete will be shifted by one to the left, then we reduce the size by one

```
//lets say we want ot delete the elementa at index 1
for(int i =2; i < length; i ++)
{
	intArr[i-1] = intArr[i];
}

length --;
```

## Remove element - Two Pointers

```
class Solution {
    public int removeElement(int[] nums, int val) {
    
        int writer = 0; //will point to the place to write
        
    //reader will point to the data its reading
    //see https://www.youtube.com/watch?v=QzZ7nmouLTI
        for(int reader = 0; reader < nums.length; reader++)
        {
            if(nums[reader] != val)
            {
                nums[writer] = nums[reader];
                writer ++;
            }
        }
        
        return writer;
    }
    
}
```

### Remove duplicates from array - two pointer

```
class Solution {
    public int removeDuplicates(int[] nums) {
        
        int writer = 0;
        
        for(int reader = 0; reader < nums.length; reader ++)
        {   
            if(nums[reader] != nums[writer])
            {
                nums[++writer] = nums[reader];
            }
        }
        
        return writer + 1;
        
    }
}
```