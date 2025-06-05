
## Hash Set Usage
```
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        // 1. initialize the hash set
        Set<Integer> hashSet = new HashSet<>();     
        // 2. add a new key
        hashSet.add(3);
        hashSet.add(2);
        hashSet.add(1);
        // 3. remove the key
        hashSet.remove(2);        
        // 4. check if the key is in the hash set
        if (!hashSet.contains(2)) {
            System.out.println("Key 2 is not in the hash set.");
        }
        // 5. get the size of the hash set
        System.out.println("The size of has set is: " + hashSet.size());     
        // 6. iterate the hash set
        for (Integer i : hashSet) {
            System.out.print(i + " ");
        }
        System.out.println("are in the hash set.");
        // 7. clear the hash set
        hashSet.clear();
        // 8. check if the hash set is empty
        if (hashSet.isEmpty()) {
            System.out.println("hash set is empty now!");
        }
    }
}
```


## Find Duplicates By Hash Set
```
/*
 * Template for using hash set to find duplicates.
 */
boolean findDuplicates(List<Type> keys) {
    // Replace Type with actual type of your key
    Set<Type> hashset = new HashSet<>();
    for (Type key : keys) {
        if (hashset.contains(key)) {
            return true;
        }
        hashset.add(key);
    }
    return false;
}

```


## Contains Duplicate

```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        Set<Integer> set = new HashSet<>();
        
        if(nums.length == 0) return false;
        
        for(Integer num : nums)
        {
            if(set.contains(num))
            {
                return true;
            }
            else
            {
                set.add(num);
            }
        }
        
        return false;
        
    }
}
```

## Single Number

```
class Solution 
{
    public int singleNumber(int[] nums) 
    {
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(Integer num : nums)
        {
            map.put(num, map.getOrDefault(num,0) + 1);
        }
        
        for(Integer num : nums)
        {
            if(map.get(num) == 1)
            {
                return num;
            }
        }
        
        return -1;
    }
}
```

## Intersection of Two Arrays

```
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        
        Set<Integer> set1 = new HashSet<Integer>();
        Set<Integer> set2 = new HashSet<Integer>();
        
        
        for(int num : nums1)
        {
            set1.add(num);
        }
        
        for(int num : nums2)
        {
            set2.add(num);
        }
        
        set1.retainAll(set2); //Only keep items that are in both arrays
        
        int[] result = new int[set1.size()];
        int index = 0;
        
        for(int num : set1)
        {
            result[index++] = num;
        }
        
        return result;
    }
}
```

## Happy Numner

```
class Solution {
    
    private int getNext(int n)
    {
        int totalSum = 0;
        
        while(n > 0)
        {
            int d = n % 10; //utmost right part of the number
            n /= 10; //remove the utmost right part of the initial number
            totalSum += d * d;
        }
        
        return totalSum;
    }
    
    public boolean isHappy(int n) {
        
        Set<Integer> seen = new HashSet<>();
        
        while(n != 1 && !seen.contains(n))
        {
            seen.add(n);
            n = getNext(n);
        }
        
        return n ==1;
    }
}
```

