```
DVD[] dvdCollection = new DVD[15];

  

Public class DVD

{

Public String name;

Public int releaseYear;

Public String director;

}


DVD avengers = new DVD();
dvdCollection[7] = avengers; //adds to 6th elememt

DVD overwrite = new DVD();
dvdCollection[7] = overwrite; //overwrites the 6th element

DVD extract = dvdCollection[7]; //access an element
```

### Looping through an array:

```
int[] squareNumbers = new int[10];

for(int i = 0 ;i < 10; i ++)
{
	int square = (i + 1) * (i + 1);
	squareNumbers[i] = square;
}
```

## Foreach

```
for(int square : squareNumbers)
{
	System.out.println(square);
}
```


## Get size of array
```
array.length;
```

### Max consecutive ones
```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) 
    {
        int maxCount = 0;
        int count = 0;
        
        for(int i =0; i < nums.length; i ++)
        {
            if(nums[i] == 1)
            {
                count ++;
            }
            else
            {
                count = 0;
            }
            
            if(count > maxCount)
            {
                maxCount = count;
            }
        }
        
        return maxCount;
    }
}
```

### Find numbers with even number of digits

```
class Solution {
    public int findNumbers(int[] nums) {
        
        int counter =0;
        
        for(int i = 0; i < nums.length; i ++)
        {
            String num = String.valueOf(nums[i]);
            if(num.length() % 2 == 0)
            {
                counter ++;
            }
        }
        
        return counter;
        
    }
}
```

### Squares of a sorted Array

```
class Solution {
    public int[] sortedSquares(int[] nums) {
        
        //1. squareRoot
        
        for(int i = 0; i < nums.length; i ++)
        {
            nums[i] = nums[i] * nums[i];
        }
        
        Arrays.sort(nums);
        
        return nums;
        
    }
}
```