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
