```
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        // 1. initialize a hash map
        Map<Integer, Integer> hashmap = new HashMap<>();
        // 2. insert a new (key, value) pair
        hashmap.putIfAbsent(0, 0);
        hashmap.putIfAbsent(2, 3);
        // 3. insert a new (key, value) pair or update the value of existed key
        hashmap.put(1, 1);
        hashmap.put(1, 2);
        // 4. get the value of specific key
        System.out.println("The value of key 1 is: " + hashmap.get(1));
        // 5. delete a key
        hashmap.remove(2);
        // 6. check if a key is in the hash map
        if (!hashmap.containsKey(2)) {
            System.out.println("Key 2 is not in the hash map.");
        }
        // 7. get the size of the hash map
        System.out.println("The size of hash map is: " + hashmap.size()); 
        // 8. iterate the hash map
        for (Map.Entry<Integer, Integer> entry : hashmap.entrySet()) {
            System.out.print("(" + entry.getKey() + "," + entry.getValue() + ") ");
        }
        System.out.println("are in the hash map.");
        // 9. clear the hash map
        hashmap.clear();
        // 10. check if the hash map is empty
        if (hashmap.isEmpty()) {
            System.out.println("hash map is empty now!");
        }
    }
}
```

## Scenario I - Provide More Information

## Two Sum
```
class Solution {
    public int[] twoSum(int[] nums, int target) 
    {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int[] result = new int[2];
        for(int i = 0; i < nums.length; i ++)
        {
            map.put(nums[i], i);
            
        }
        
        for(int i = 0; i < nums.length; i++)
        {
            int remainder = target - nums[i];
            
            if(map.containsKey(remainder) && map.get(remainder) != i)
            {
                result[1] = map.get(remainder);
                result[0] = i;
                
            }
        }
        
        return result;
        
    }
}
```


## Isomorphic strings  *Had a hard time*

```
class Solution {

    public boolean isIsomorphic(String s, String t) {

        Map<Character, Character> StoT = new HashMap<>();

        Map<Character,Character> TtoS = new HashMap<>();

  

        for(int i = 0; i < s.length(); i ++)

        {

            Character c1 = s.charAt(i);

            Character c2 = t.charAt(i);

  

            if(!StoT.containsKey(c1) && !TtoS.containsKey(c2))

            {

                StoT.put(c1,c2);

                TtoS.put(c2,c1);

            }

  

            else if(!(c2.equals(StoT.get(c1)) && c1.equals(TtoS.get(c2))))

            {

                return false;

            }

        }

  
  

        return true;

    }

}
```

### Minimum index sum of two lists
```
class Solution {

    public String[] findRestaurant(String[] list1, String[] list2) {

        Map<String,Integer> map1 = new HashMap<>();

        Map<String,Integer> map2 = new HashMap<>();

        List<String> result = new ArrayList<>();

        int lowestIndexSum = Integer.MAX_VALUE;

  

        for(int i = 0; i < list1.length; i ++)

        {

            map1.put(list1[i],i);

        }

        for(int i = 0; i < list2.length; i ++)

        {

            map2.put(list2[i],i);

        }

        for(String item : list1)

        {

            if(map2.containsKey(item))

            {

                int tempMin = map2.get(item) + map1.get(item);

                if(tempMin < lowestIndexSum)

                {

                    result.clear();

                    lowestIndexSum = tempMin;

                    result.add(item);

                }

                else if(tempMin == lowestIndexSum)

                {

                    result.add(item);

                }

            }

        }

        String[] arr = new String[result.size()];

        return result.toArray(arr);    

    }

}
```

## Scenario II - Aggregate by Key

## Intersection of twoa arrays II
```
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        
        Map<Integer, Integer> count2 = new HashMap<>();
        List<Integer> result = new ArrayList<>();
        
        
        for(int num2 : nums2)
        {
            if(!count2.containsKey(num2))
            {
                count2.put(num2,1);
            }
            else
            {
                int value = count2.get(num2);
                value ++;
                count2.put(num2,value);
            }
        }
        
        
        for(int num : nums1)
        {
            if(count2.containsKey(num))
            {
                result.add(num);
                int value = count2.get(num);
                value --;
                
                if(value == 0)
                {
                    count2.remove(num);
                }
                else
                {
                    count2.put(num,value);                    
                }
                
            }
        }
        
       
        return result.stream().mapToInt(i -> i).toArray();
        
    }
}
```

## Contains Duplicate II

Remember that using put with the same key will replace the value at the place

```
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        
        for(int i = 0; i < nums.length; i ++)
        {
            int extracted = nums[i];
            
            if(map.containsKey(extracted))
            {
                int index = map.get(extracted);
                if(Math.abs(index - i) <= k)  return true;
            }
            
            map.put(extracted,i);
        }
        return false;
    }
}
```

## Logger Rate Limiter

```
class Logger {
    
    Map<String,Integer> timestamps;

    public Logger() {
        timestamps = new HashMap<>();
    }
    
    private void updateTimestamps(String message, int timestamp)
    {
        timestamps.put(message,timestamp + 10);
    }
    
    public boolean shouldPrintMessage(int timestamp, String message) 
    {
        if(!timestamps.containsKey(message))
        {
            updateTimestamps(message,timestamp);
            return true;
        }
        else if(timestamps.get(message) <= timestamp )
        {
            updateTimestamps(message,timestamp);
            return true;
        }
        
        return false;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */
```

