Approach  
take out string  
char array  
sort it  
convert to string  
use this string as a key  
then push all the related element to key

## Top K Frequent Elements

Map numbers to frequency
Make a priority queue (custom priority via constructor) and add elements to it (make sure its size is max k)
build result array


## Encode and Decode Strings

This problem is easy if we only use a delimiter, but this is a bad practice.
We can use a method where we put the length of the string, a delimiter.
Then we can access the length using a substring with indexOf method in java.
Then we just take the substring of that length after the delimiter and we repeat.
This ensures integrity of data..

## Product of Array Escept Self

I didnt manage to solve this question interly, but I was able to solve it after some hints (no code). 
The trick is calculating the prefix and suffix products. in an array, where each index represents the prefix/suffix up until this index. Then we pass through the result array and calculate by multiplying the suffix with the prefix.

## Valid sudoku

The thing here is that we can do it using only 2d arrays for each (row,col,box). The first index represents the number and the other one represents its frequence. We basically just add the second one and if it is > 1 its false... We calculate the box index using a flatening method (/3 * 3 + col/3)

## Longest Consecutive Sequence

The way to do this one is to check if a smaller number exist. If yes, we just continue. If no, this means it is possibly the smallest of its series. Therefore we will loop through and check if a +1 number exists in the hashset (we can build this in one pass). Therefore we count each time. This is maybe O(3n) or O(2N) which is basically O(N)

## Valid Paranthesis
the trick here is to use a stack and a map with each brackets mapped to its enclosing one. Therefore the insertions are easier. When a braket is open we add it to the stack and once one is closed we check if the top of the stack is the corresponding bracket... etc.

## Min Stack
Here we can use two stack. One stack for the actual stack and the other which keeps the min item to the top. We check for the min item while adding it and we pop the min stack if we are popping that item from the main stack. We can use a int[] arr pair for the minStack, where the index is used as the value and the 1 index is used as its count. We can increment it if we see the same value over.

## Evaluate Reverse Polish Notation

The trick using a stack here is pretty simple. When encountering an operator, the last 2 numbers of the stack are made against each other (the operation). Then pushed back to the stack for further processing. At the end, we have only 1 result. Instead of using switch case or else if, we can use a BiFunction<param1Type,param2Type,resultType> which will be a lambda function like (a,b) -> a + b;.
We can use this with a map to simplify the code. We map each symbol to its function. Then when we need to do the processing, we can just use .get() and use the .apply() function and giving it its params to execute the function. 

## Generate Parentheses

The trick of this problem is to use a Stringbuilder kinda like a stack, and use backtraking. Basically we want to explore each possible solutions using backtracking. If the left parenthesis is < n, then we can add more. if right parenthesis != left parethesis, then we can add some. etc... By using backtracking, we can explore all possibilities. 

## Daily temperature

The general trick Monotonic stacks are a good option when a problem involves comparing the size of numeric elements, with their order being relevant. We can use a stack to keep track of the elements and when we arrive on a new element we calculate the distance between the top of the stack and the current element. WE usually store indexes in the stack so its easier.

## Car Fleet

To solve this, I started by creating pairs for each cars and sorted them by position (lowest to highest) now, we can use a stack to see if some cars passes others and pop the cars accordingly. The resulting cars in the stack are the number of fleets. We return the size of the car

## Largest Rectangle in Histogram

This problem is quite tricky. The way I solved this is not the most optimal, I used the previous smallest element and next smallest element arrays for each item in the array. Then I looped one last time in the whole original array, and we can know that the current element is the smallest by excluding the smallest elements on both sides and calculating with the current height. 

The most optimal way to do this is essentially calculating as we go, checking if the previous item in the stack is bigger than the current one. popping it and checking the width with current index - stack.peek() (after popping the item, so we know the width) and x height. There will be remaining elements and we can apply a similar logic to them...

## Valid Palindrome
This problem was really easy. The only tricky part was knowing the regex lol. 
Otherwise, you use two pointers — right and left, and compare the chars until the pointers meet. if two chars are diff, it's not a palindrome...

## Two sum 2 Input array is sorted
The trick here is to use 2 pointers and increment/decrement them based on if their sum is smaller/bigger than the target, since the array is sorted

## 3sum
Here we just loop through the whole array with a for loop, and we do the same concept as two sum 2, but from that index onwards. The tricky part is how to avoid dulpicates. I used a hashset but that isnt optimal. You can just use skipping logic in the loop at certain places...

## Container with Most Water
We can solve this problem with two pointers by basically moving the smallest candle's pointer and calculating the areas. This ensures that wee grow the height always, even at the cost of reducing width— so we can find max
## Trapping rainwater
There is actually a way to do this with a stack but I dont think it is optimal. We can also do it in three pass which is technically O(3N) hence O(N), by getting each's candle prev max and next max. But, we want to solve it using two pointers. The trick here is that if we always move the pointer which points to the lowest height, we ensure that a higher height of the opposing side exists, so we can calculate the water based on the previous candle. So we set pointers on each side of the graph and move them while keeping track of the maxHeight of each and calculating the water based on that.

## Reverse a linked list
Here we can just loop, but we need to always keep track of the previous element and point to it.