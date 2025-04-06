```
public static boolean linearSearch(int[] array, int length, int element)
{
	if(array == null || length == 0)
	{
		return false;
	}

	for(int i = 0; i < length; i ++)
	{
		if(array[i] == element)
		{
			return true;
		}
	}
	
	return false;
}
```

### Binary Search

If the elements in the Array are in _sorted order

Binary search is where we repeatedly look at the middle element in the Array, and determine whether the element we're looking for must be to the left, or to the right. Each time we do this, we're able to halve the number of elements we still need to search, making binary search a lot faster than linear search!

### Check if N and its double exist- Set
```
class Solution {
    public boolean checkIfExist(int[] arr) {
    Set<Integer> seen = new HashSet<>();

    for(int i = 0; i < arr.length; i ++)
    {
        if(seen.contains(arr[i] * 2) || 
        (arr[i] % 2 == 0 && seen.contains(arr[i] / 2)))
        {
            return true;
        }

        seen.add(arr[i]);
    }

        return false;
    }
}
```

