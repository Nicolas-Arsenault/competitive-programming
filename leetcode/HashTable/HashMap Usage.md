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