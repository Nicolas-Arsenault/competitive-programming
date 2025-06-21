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

## Group Shifted Strings
The hard part of this problem is more on finding the math to find the key.
But it makes sense, you just make it so that each time the first letter of the word is a, and shift the other letters acordingly. There, you have a key.

```
class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        
        Map<String, List<String>> map = new HashMap<>();
        
        for(String s : strings)
        {
            String key = getHash(s);
            
            if(!map.containsKey(key))
            {
                map.put(key,new ArrayList<>());
            }
            
            map.get(key).add(s);
        }
        
        List<List<String>> result = new ArrayList<>();
        for(List<String> list : map.values())
        {
            result.add(list);   
        }
        
        return result;
    }
    
    private char shiftString(char letter, int shift)
    {
        return (char)((letter - shift + 26) % 26 + 'a');
    }
    
    private String getHash(String s)
    {
        char[] arr = s.toCharArray();
        char shift = arr[0];
        char[] key = new char[arr.length];
        
        for(int i = 0; i < arr.length; i ++)
        {
            key[i] = shiftString(arr[i],shift);
        }
        
        return (new String(key));
    }
}
```


## Valid Sudoku

This question is quite tricky because we want to avoid going through each col and row.
The trick is, we need to determine what each value has in common: a row, a column and a box.
So we create hashmaps for all three of these. Now, instead of storing a list in the hashmap, we will use a hashset to see if a value is unique. Here the lambda expression is a function. K represents a key.


```
class Solution {
    public boolean isValidSudoku(char[][] board) {
    
        Map<Integer, HashSet<Character>> row = new HashMap<>();
        Map<Integer,HashSet<Character>> col = new HashMap<>();
        Map<String, HashSet<Character>> box = new HashMap<>();
        
        for(int i = 0; i < 9; i ++)
        {
            for(int j = 0; j < 9; j ++)
            {
                if(board[i][j] == '.') continue;
                
                String key = i/3 + "," + j/3;
                
                if(row.computeIfAbsent(i, k -> new HashSet<Character>()).contains(board[i][j]) ||
                    col.computeIfAbsent(j, k -> new HashSet<Character>()).contains(board[i][j]) ||
                    box.computeIfAbsent(key, k -> new HashSet<Character>()).contains(board[i][j]))
                {
                    return false;
                }
                
                row.get(i).add(board[i][j]);
                col.get(j).add(board[i][j]);
                box.get(key).add(board[i][j]);
            }
        }
        
        return true;
        
    }
}
```

## Find duplicate subtrees
Didnt really understand... need to redo

```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    final String NT = "X";

    Set<String> visited = new HashSet<>();

    Map<String, TreeNode> res = new HashMap<>();

    public List<TreeNode> findDuplicateSubtrees(TreeNode root){
        postOrderTraversal(root);
        return new LinkedList<>(res.values());
    }
    
    private String postOrderTraversal(TreeNode node){
        StringBuilder sb = new StringBuilder();
        String leftSubtree = NT, rightSubtree = NT;
        
        if(node.left != null)
        {
            leftSubtree = postOrderTraversal(node.left);
        }
        
        if(node.right != null)
        {
            rightSubtree = postOrderTraversal(node.right);
        }
        
        sb.append(node.val);
        
        sb.append(",");
        sb.append(leftSubtree);
        sb.append(",");
        sb.append(rightSubtree);
        
        String curSubtree = sb.toString();
        saveDupluicateSubtree(node,curSubtree);
        visited.add(curSubtree);
        return curSubtree;
    }
    private void saveDupluicateSubtree(TreeNode node, String key){
        if(visited.contains(key)){
            res.put(key,node);
        }
    }
}
```

## Design the Key - Summary
When the order of each element in the string/array doesn't matter, you can use the `sorted string/array` as the key.

If you only care about the offset of each value, usually the offset from the first value, you can use the `offset` as the key.

n a tree, you might want to directly use the `TreeNode` as key sometimes. But in most cases, the `serialization of the subtree` might be a better idea.

In a matrix, you might want to use `the row index` or `the column index` as key.

In a Sudoku, you can combine the row index and the column index to identify which `block` this element belongs to.

Sometimes, in a matrix, you might want to aggregate the values in the same `diagonal line`.

