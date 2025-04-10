`rectangular grid` rather than a line.

```
// "static void main" must be defined in a public class.
public class Main {
    private static void printArray(int[][] a) {
        for (int i = 0; i < a.length; ++i) {
            System.out.println(a[i]);
        }
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; a[i] != null && j < a[i].length; ++j) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        System.out.println("Example I:");
        int[][] a = new int[2][5];
        printArray(a);
        System.out.println("Example II:");
        int[][] b = new int[2][];
        printArray(b);
        System.out.println("Example III:");
        b[0] = new int[3];
        b[1] = new int[5];
        printArray(b);
    }
}
```

**2. In Java, the two-dimensional array is actually a one-dimensional array which contains M elements, each of which is an array of N integers.**

![[Pasted image 20250408095019.png]]

we can also define a dynamic two-dimensional array. Actually, it can be just `a nested dynamic array`

##  Diagonal Traverse

```
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        
        if(matrix == null || matrix.length ==0)
        {
            return new int[0]; //0
        }
        
        int row = matrix.length, col = matrix[0].length;
        int indexRow = 0;
        int indexCol = 0;
        int counter = 0;
        int[] result = new int[row * col];
        
        while(counter < row * col)
        {
            result[counter++] = matrix[indexRow][indexCol];
            
            boolean isEven = (indexRow + indexCol) % 2 == 0;
            
            if(isEven)
            {
                //top right
                if(indexRow > 0 && indexCol < col - 1)
                {
                    indexRow --;
                    indexCol ++;
                }
                //go to the right
                else if(indexCol < col -1)
                {
                    indexCol ++;
                }
                //go down
                else if(indexRow < row -1)
                {
                    indexRow ++;
                }
            }
            else
            {
                //bot left
                if(indexRow < row -1 && indexCol > 0)
                {
                    indexRow ++;
                    indexCol --;
                }
                //bot
                else if(indexRow < row - 1)
                {
                    indexRow ++;
                }
                //right
                else if(indexCol < col - 1)
                {
                    indexCol ++;
                }
            }
        }
        
        return result;
        
    }
}

```

### Spiral matrix

```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
     
        List<Integer> result = new ArrayList<>();
        
        if(matrix.length == 0 || matrix == null)
        {
            return result;
        }
        
        
        
        //keep track of our direction
        int direction = 0;
        
        //pointers
        int bot = matrix.length - 1, up = 0, left = 0, right = matrix[0].length - 1; 
        
        //will do one last loop when all pointers are equal. (center element)
        while(left <= right && up <= bot)
        {
            switch(direction)
            {
                    //we move to the right
                case 0:
                    for(int i = left; i <= right; i++)
                    {
                        result.add(matrix[up][i]);
                    }
                    up ++;
                    break;
                    
                    //we move to bottom
                case 1:
                    for(int i = up; i <= bot; i ++)
                    {
                        result.add(matrix[i][right]);
                    }
                    right --;
                    break;
                    
                    //we move to the left
                case 2:
                    for(int i = right; i >= left; i --)
                    {
                        result.add(matrix[bot][i]);
                    }
                    bot--;
                    break;
                    
                    //move up
                case 3:
                    for(int i = bot; i >= up; i --)
                    {
                        result.add(matrix[i][left]);
                    }
                    left ++;
                    break;
            }
            
            direction = (direction +1) % 4; //basically makes it so that direction is always 1-3
        }
        
        return result;
        
    }
}
```

### Pascal's triangle - Dynamic Programming
Algorithm technique.

Basically, solving subproblems first and then solving the larger problem using these subproblems. 

```
class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> result = new ArrayList<>();
        //we know that the first row is only a one...
        result.add(new ArrayList<>());
        result.get(0).add(1);
        
        for(int row = 1; row < numRows; row ++)
        {
            List<Integer> currRow = new ArrayList<>();
            List<Integer> prevRow = result.get(row - 1);
            
            //starts by 1...
            currRow.add(1);
            
            //go through the prev row
            for(int i = 1; i < prevRow.size(); i ++)
            {
                currRow.add(prevRow.get(i - 1) + prevRow.get(i));
            }
            
            
            //ends by 1
            currRow.add(1);
            result.add(currRow);
        }
        
        
        
        return result;
    }
}
```