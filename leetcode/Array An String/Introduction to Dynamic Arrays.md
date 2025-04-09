`ArrayList` in Java.

```
List<Integer> v0 = new ArrayList<>();
```

Integer Array to List:

```
Integer[] a = {0, 1, 2, 3, 4};
List<Integer> v1 = new ArrayList<>(Arrays.asList(a));
```

Length of array: v1.size()

Access element by index: v1.get(0)

Modify element: v2.set(0, 5)

Make copies:

```
List<Integer> v2 = v1;                      // another reference to v1
List<Integer> v3 = new ArrayList<>(v1);     // make an actual copy of v1
```

### Find pivot index - Prefix Sum

Find the index that separates the sum of the left and right equally

```
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, leftsum = 0;
        for (int x: nums) sum += x;
        for (int i = 0; i < nums.length; ++i) {
            if (leftsum == sum - leftsum - nums[i]) {
                return i;
            }

            leftsum += nums[i];
        }
        return -1;
    }
}
```

# Largest Number At Least Twice of Others
 