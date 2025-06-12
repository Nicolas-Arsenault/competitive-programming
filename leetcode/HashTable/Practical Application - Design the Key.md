 Design the Key

---

In the previous problems, the choice of key is comparatively straightforward. Unfortunately, sometimes you have to think it over to `design a suitable key` when using a hash table.

### An Example

---

Let's look at an example:

> Given an array of strings, group anagrams together.

As we know, a hash map can perform really well in grouping information by key. But we cannot use the original string as key directly. We have to design a proper key to present the type of anagrams. For instance, there are two strings "eat" and "ate" which should be in the same group. While "eat" and "act" should not be grouped together.

### Solution

---

Actually, `designing a key` is to `build a mapping relationship by yourself` between the original information and the actual key used by hash map. When you design a key, you need to guarantee that:

> 1. All values belong to the same group will be mapped in the same group.
> 
> 2. Values which needed to be separated into different groups will not be mapped into the same group.

This process is similar to design a hash function, but here is an essential difference. `A hash function satisfies the first rule but might not satisfy the second one.` But your mapping function should satisfy both of them.

In the example above, our mapping strategy can be: sort the string and use the sorted string as the key. That is to say, both "eat" and "ate" will be mapped to "aet".

The mapping strategy can be really `tricky` sometimes. We provide some exercise for you in this chapter and will give a summary after that.

## Group anagrams

```
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        if (strs.length == 0) return (new ArrayList<List<String>>());
        
        Map<String, List<String>> map = new HashMap<>();
        List<List<String>> result = new ArrayList<>();
        
        //Build Groups
        for(String word : strs)
        {
            
            String sortedWord = sortString(word);
            
            if(!map.containsKey(sortedWord))
            {
                System.out.println(sortedWord);
                map.put(sortedWord, new ArrayList<String>());
            }
        } 
        
        //Assign values to their corresponding group
        for(String word : strs)
        {
            String sortedWord = sortString(word);
            
            List<String> list = map.get(sortedWord);
            list.add(word);
            map.put(sortedWord, list);
        }
        
        //Build result
        for(Map.Entry<String, List<String>> entry : map.entrySet())
        {
            result.add(entry.getValue());
        }
        
         return result;
    }
    
            
    public String sortString(String word)
    {
        char[] charWord = word.toCharArray();
        Arrays.sort(charWord);
        return new String(charWord);
    }
}
```


OR 


```
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) 
    {
        if(strs.length == 0 ) return new ArrayList<>();
        
        Map<String, List<String>> map = new HashMap<>();
        
        for(String word : strs)
        {
            char[] arrWord = word.toCharArray();
            Arrays.sort(arrWord);
            String key = new String(arrWord);
            
            if(!map.containsKey(key))
            {
                map.put(key, new ArrayList<>());
            }
            
            map.get(key).add(word);
        }
        
        return (new ArrayList(map.values()));
    }     
}
```

