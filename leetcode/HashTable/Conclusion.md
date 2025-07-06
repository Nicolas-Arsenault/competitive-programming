## Jewels and stones
Fairly easy problem. Needed to map chars to their respective value and then compared the other string to the chars...

```
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Map<Character, Integer> jewelCount = new HashMap<>();
        int result = 0;
        //Build the keys:
        for(int i = 0; i < jewels.length(); i ++)
        {
            jewelCount.put(jewels.charAt(i),0);
        }
        
        for(int i = 0; i < stones.length(); i ++)
        {
            if(jewelCount.containsKey(stones.charAt(i)))
            {
                int count = jewelCount.get(stones.charAt(i));
                count ++;
                jewelCount.put(stones.charAt(i),count);
            }
        }
        
        
        for(Map.Entry<Character, Integer> entry : jewelCount.entrySet())
        {
            result += entry.getValue();
        }
        
        return result;
    }
}
```


SOLUTION :

```
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> set = new HashSet<>();
        int result = 0;
        
        for(char c : jewels.toCharArray())
        {
            set.add(c);
        }
        
        for(char c : stones.toCharArray())
        {
            if(set.contains(c))
            {
                result ++;
            }
        }
        
        return result;
    }
}
```

## Longest substring without duplicate chars.

Using a set and bruteforce was TLE, so I used a sliding window using a hashmap

```
class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        Map<Character, Integer> map = new HashMap<>();
        
        int right = 0;
        int left = 0;
        int res = 0;
        
        while(right < s.length())
        {
            char c = s.charAt(right);
            map.put(c, map.getOrDefault(c,0) + 1);
            
            while(map.get(c) > 1)
            {
                char l = s.charAt(left);
                map.put(l,map.get(l) - 1);
                left ++;
            }
            
            res = Math.max(res, right - left + 1);
            
            right ++;
        }
        
        return res;
    
    }
}
```

## Two Sum 3

I used a hashmap for quick lookup. I mapped the value (key) with its frequency. The hard part here was the edge case where the target was the same as our current value, which means we need to look at the frequency. The thing is, I didnt think about the fact that the check needs to be against the current entry we have...

```
class TwoSum {

    Map<Integer,Integer> map;
    
    public TwoSum() {
        map = new HashMap<>();
    }
    
    public void add(int number) {
        map.put(number,map.getOrDefault(number,0) + 1);
    }
    
    public boolean find(int value)
    {
        for(Map.Entry<Integer,Integer> entry : map.entrySet())
        {
            int target = value - entry.getKey();
            if(target != entry.getKey())
            {
                if(map.containsKey(target)) return true;
            }
            else 
            {
                if(entry.getValue() > 1) return true;
            }
            
            
        }
        return false;
    }
}


/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
```

## 4 Sum 2
This one was quite tricky, but the trick is building a map of the two first arrays sums linked to their frequency. After we can calculate the target easily using the two last arrays
```
class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        
        Map<Integer,Integer> map = new HashMap<>();
        int count = 0;
        
        for(int num : nums1)
        {
            for(int secNum : nums2)
            {
                map.put(num + secNum, map.getOrDefault(num+secNum,0) + 1);
            }
        }
        
        for(int num : nums3)
        {
            for(int secNum : nums4)
            {
                count += map.getOrDefault(-(num+secNum),0);
            }
        }
        
        
        
        return count;
    }
}
```

## Top K Frequent Elements

I used a Heap approach, which is O(NLogN).
Basically I first make a map of frequencies, then I sort them using a queue which acts like a heap (FIFO). Then I build the result array.

```
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> count = new HashMap<>();
        
        for(int num : nums)
        {
            count.put(num,count.getOrDefault(num,0) + 1);
        }
        
        Queue<Integer> heap = new PriorityQueue<>((n1,n2) -> count.get(n1) - count.get(n2));
        
        for(int n : count.keySet())
        {
            heap.add(n);
            if(heap.size() > k) heap.poll();
        }
        
        int[] result = new int[k];
        
        for(int i =0; i < k; i ++)
        {
            result[i] = heap.poll();
        }
        
        return result;
    }
}
```

## Unique word abbreviation

The tricky part is understanding the requirements, After that we can just map abbreviations to their word. We use a set in the map so that we dont place the same word twice. Then we can just do some checks against the map:

```
class ValidWordAbbr {

    private Map<String,Set<String>> map;
    
    public ValidWordAbbr(String[] dictionary) {
        map = new HashMap<>();
        
        for(String word : dictionary)
        {
           String abbreviation = getAbbreviation(word);
            
            if(map.containsKey(abbreviation))
            {
                Set<String> extracted = map.get(abbreviation);
                extracted.add(word);
                map.put(abbreviation,extracted);
            }
            else
            {
                Set<String> list = new HashSet<>();
                list.add(word);
                map.put(abbreviation,list);
            }
        }
        
    }
    
    private String getAbbreviation(String word)
    {
        if(word.length() == 2) return word;
        
        int length = word.length() - 2;
        String abbreviation = word.charAt(0) + String.valueOf(length) + word.charAt(length + 1);
        
        return abbreviation;
    }
    
    public boolean isUnique(String word) {
        
        
        if(!map.containsKey(getAbbreviation(word)))
        {
            return true;
        }
        else if(map.get(getAbbreviation(word)).size() == 1 && map.get(getAbbreviation(word)).contains(word))
        {
            return true;
        }
        
        return false;
        
    }
}
```

## Insert Delete GetRandom O(1)

The tricky part is keeping all of it O(1). Basically to be able to getRandom() we need to be able to play with indexes, so we will need a list for sure. The issue is that removing from a list is O(n) time. The way to remove in O(1) is by replacing the last element to the element's index we want to remove. Therefore the element wont exist anymore. Afterwards we just have to remove the last elemment (which we used to replace the target one). This takes O(1), since we dont need to go through the list. Afterwards, a hashmap is used to keep the searches O(1) for keys and such


```
class RandomizedSet {

    Map<Integer, Integer> map;
    List<Integer> list;
    Random rand;

    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        if(map.containsKey(val)) return false;
        
        map.put(val,map.size());
        list.add(list.size(),val);
        return true;
    }
    
    public boolean remove(int val) {

        if(!map.containsKey(val)) return false;
        
        int lastElement = list.get(list.size() - 1);
        int indx = map.get(val);
        list.set(indx, lastElement);
        map.put(lastElement,indx);
        
        list.remove(list.size() - 1);
        map.remove(val);
        return true;
    }
    
    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
        
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
```