> Recursion is an approach to solving problems using a function that calls itself as a subroutine.

A recursive function should have the following properties so that it does not result in an infinite loop:

1. A simple `base case` (or cases) — a terminating scenario that does not use recursion to produce an answer.
2. A set of rules, also known as `recurrence relation` that reduces all other cases towards the base case.

Note that there could be multiple places where the function may call itself.

## Example
Print a string in reverse order.

## Reverse String

```
class Solution {
    public void reverseString(char[] s) {
        switchChars(0, s.length - 1, s);
         
    }
    
    private void switchChars(int left, int right, char[] s)
    {
        if(left >= right) return;
        
        char temp  = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left ++; 
        right --;
        switchChars(left, right, s);
    }
}
```

## Recursion Function

For a problem, if there exists a recursive solution, we can follow the guidelines below to implement it. 

For instance, we define the problem as the function F(X)F(X) to implement, where XX is the input of the function which also defines the scope of the problem.

Then, in the function F(X)F(X), we will:

1. Break the problem down into smaller scopes, such as x0∈X,x1∈X,...,xn∈Xx0​∈X,x1​∈X,...,xn​∈X;
2. Call function F(x0),F(x1),...,F(xn)F(x0​),F(x1​),...,F(xn​) _**recursively**_ to solve the subproblems of XX;
3. Finally, process the results from the recursive function calls to solve the problem corresponding to XX.

