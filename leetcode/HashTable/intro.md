There are two different kinds of hash tables: hash set and hash map.

- The `hash set` is one of the implementations of a `set` data structure to store `no repeated values`.
- The `hash map` is one of the implementations of a `map` data structure to store `(key, value)` pairs.

## The Principle of Hash Table
The key idea of Hash Table is to use a hash function to `map keys to buckets`. To be more specific,

1. When we insert a new key, the hash function will decide which bucket the key should be assigned and the key will be stored in the corresponding bucket;
2. When we want to search for a key, the hash table will use the `same` hash function to find the corresponding bucket and search only in the specific bucket.


There are two essential factors that you should pay attention to when you are going to design a hash table.

## Keys to Design a Hash Table

### 1. Hash Function
in the previous article, we use y = x % 5 as a hash function, where x is the key value and y is the index of the assigned bucket.

The hash function will depend on `the range of key values` and `the number of buckets`.

![[hash_functions_table1.png]]

The idea is to try to assign the key to the bucket as `uniformly as you can`

Ideally, a perfect hash function will be a one-one mapping between the key and the bucket.

### 2. Collision Resolution
For instance, in our previous hash function (y = x % 5), both 1987 and 2 are assigned to bucket 2.

That is a `collision`.


A collision resolution algorithm should solve the following questions:

1. How to organize the values in the same bucket?
2. What if too many values are assigned to the same bucket?
3. How to search for a target value in a specific bucket?

These questions are related to `the capacity of the bucket` and `the number of keys` which might be mapped into `the same bucket` according to our hash function.

Typically, if N is constant and small, we can simply use an `array` to store keys in the same bucket. If N is variable or large, we might need to use `height-balanced binary search tree` instead.

## Design a HashSet
```
class MyHashSet {
    //0 to 1000000
    public final int MAX_VALUE = 1000000;
    public final int NB_BUCKETS = 100;
    public List<List<Integer>> table;
    
    public MyHashSet() {
        table = new ArrayList<>(NB_BUCKETS);
        
        for(int i = 0; i < NB_BUCKETS; i ++)
        {
            table.add(null);
        }
    }
    
    public void add(int key) {
        int index = key % NB_BUCKETS; //map to the right bucket
        List<Integer> child = table.get(index);
        
        if(child == null)
        {
            List<Integer> list = new LinkedList<>();
            list.add(key);
            table.set(index, list);
        }
        else
        {
            if(!child.contains(key))
            {
                child.add(key);
            }
        }
        
    }
    
    public void remove(int key) {
        
        int index = key % NB_BUCKETS; //map to the right bucket
        List<Integer> child = table.get(index);
        
        if(child != null)
        {
            child.remove(Integer.valueOf(key)); //remove element based on its value and not index...
        }
        
    }
    
    public boolean contains(int key) {
        
        int index = key % NB_BUCKETS;
        List<Integer> child = table.get(index);
        
        return child != null && child.contains(key);
        
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```

## Design a hashmap

```
class Pair<K, V> {
    public K key;
    public V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
}


class Bucket
{
    List<Pair<Integer,Integer>> bucket;
    
    public Bucket()
    {
        this.bucket = new LinkedList<Pair<Integer,Integer>>();
    }
    
    public Integer get(int key)
    {
        for(Pair<Integer,Integer> pair : bucket)
        {
            if(pair.key.equals(key))
            {
                return pair.value;
            }
        }
        return -1;
    }
    
    public void remove(int key)
    {
        boolean found = false;
        Pair<Integer,Integer> toRemove = null;
        for(Pair<Integer,Integer> pair : bucket)
        {
            if(pair.key.equals(key))
            {
                toRemove = pair;
            }
        }
        
        if(toRemove != null)
        {
            bucket.remove(toRemove);
        }

    }
    
    public void put(int key, int value)
    {
        for(Pair<Integer,Integer> pair : bucket)
        {
            if(pair.key.equals(key))
            {
                pair.value = value;
                return;
            }
        }
        
        Pair<Integer,Integer> pair = new Pair<Integer,Integer>(key,value);
        bucket.add(pair);
    }
    
}


class MyHashMap {
    
    public final int NB_BUCKETS = 2096;
    List<Bucket> hashTable;
    
    
    public MyHashMap() {
        this.hashTable = new ArrayList<Bucket>();
        
        for(int i = 0; i < NB_BUCKETS; i ++)
        {
            hashTable.add(new Bucket());
        }
    }
    
    public void put(int key, int value) {
        int index = key % NB_BUCKETS;
        
        hashTable.get(index).put(key,value);
        
    }
    
    public int get(int key) {
        int index = key % NB_BUCKETS;
        
        return hashTable.get(index).get(key);
    }
    
    public void remove(int key) {
        int index = key % NB_BUCKETS;
        
        hashTable.get(index).remove(key);
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
```

![[Pasted image 20250507200216.png]]


## Complexity Analysis

---

If there are `M` keys in total, we can achieve the space complexity of `O(M)` easily when using a hash table.

However, you might have noticed that the time complexity of hash table has a strong relationship with the design.

Most of us might have used `an array` in each bucket to store values in the same bucket. Ideally, the bucket size is small enough to be regarded as a `constant`. The time complexity of both insertion and search will be `O(1)`.

But in the worst case, the maximum bucket size will be `N`. And the time complexity will be `O(N)` for insertion and search.


### The Principle of Built-in Hash Table

---

The typical design of built-in hash table is:

1.  The key value can be any `hashable` type. And a value which belongs to a hashable type will have a `hashcode`. This code will be used in the mapping function to get the bucket index.
2.  Each bucket contains `an array` to store all the values in the same bucket initially.
3.  If there are too many values in the same bucket, these values will be maintained in a `height-balanced binary search tree` instead.

The average time complexity of both insertion and search is still `O(1)`. And the time complexity in the worst case is `O(logN)` for both insertion and search by using height-balanced BST. It is a trade-off between insertion and search.