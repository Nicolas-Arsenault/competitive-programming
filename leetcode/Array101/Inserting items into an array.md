
### Insert element at beginning of array

```
for(int i = 3; i >= 0; i --)
{
	intArray[i+1] = intArray[i];
}

intArray[0] = 20;
```

## Insert anywhere in the array

We need to shift to the right all the elements from that index onwards
```

//if we want to insert an element at index 2
//we need to shift elements from there to the right

for(int i = 4; i >= 2; i --)
{
	intArray[i+1] = intArray[i]
}

intArray[2] = 30;
```


### Duplicate zeros problem!

```
class Solution {
    public void duplicateZeros(int[] arr) {
        
        int arrSize = arr.length - 1;
        
        //Go through the whole aray
        for(int i = 0; i < arrSize; i ++)
        {
            if(arr[i] == 0)
            {
                //right shift all the values in the array
                for(int j = arrSize - 1; j > i; j--)
                {
                    arr[j+1] = arr[j];
                }
                
                arr[i + 1] = 0;
                i++;
            }
        }
        
    }
}
```

### Merge sorted arrays

```
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        
        for(int i = m; i < nums1.length; i ++)
        {
            nums1[i] = nums2[i - m];
        }
        
        Arrays.sort(nums1);
        
    }
}
```