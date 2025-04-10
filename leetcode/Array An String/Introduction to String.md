comparaison == :
	compare si cest la meme reference
comparaison .equals:
	compare la valeur de la string
comparaison compareTo:
	compare chaque charactère


```
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) 
    {
        // initialize
        String s1 = "Hello World";
        
        System.out.println("s1 is \"" + s1 + "\"");
        
        String s2 = s1;
        
        System.out.println("s2 is another reference to s1.");
        
        String s3 = new String(s1);
        
        System.out.println("s3 is a copy of s1.");
        
        // compare using '=='
        
        System.out.println("Compared by '==':");
        
        // true since string is immutable and s1 is binded to "Hello World"
        
        System.out.println("s1 and \"Hello World\": " + (s1 == "Hello World"));
        
        // true since s1 and s2 is the reference of the same object
        
        System.out.println("s1 and s2: " + (s1 == s2));
        
        // false since s3 is refered to another new object
        
        System.out.println("s1 and s3: " + (s1 == s3));
        
        // compare using 'equals'
        
        System.out.println("Compared by 'equals':");
        
        System.out.println("s1 and \"Hello World\": " + s1.equals("Hello World"));
        
        
        System.out.println("s1 and s2: " + s1.equals(s2));
        
        System.out.println("s1 and s3: " + s1.equals(s3));
        
        // compare using 'compareTo'
        
        
        System.out.println("Compared by 'compareTo':");
        
        System.out.println("s1 and \"Hello World\": " + (s1.compareTo("Hello World") == 0));
        
        System.out.println("s1 and s2: " + (s1.compareTo(s2) == 0));
        
        System.out.println("s1 and s3: " + (s1.compareTo(s3) == 0));
        
    }
}
```

### Immutable or Mutable
`Immutable` means that you can't change the content of the string once it's initialized.

1. In some languages (like C++), the string is `mutable`. That is to say, you can modify the string just like what you did in an array. 
2. In some other languages (like Java), the string is `immutable`. This feature will bring several problems. We will illustrate the problems and solutions in the next article.

Compare to an array, there are some extra operations we can perform on a string. Here are some examples:

```
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        String s1 = "Hello World";
        // 1. concatenate
        s1 += "!";
        System.out.println(s1);
        // 2. find
        System.out.println("The position of first 'o' is: " + s1.indexOf('o'));
        System.out.println("The position of last 'o' is: " + s1.lastIndexOf('o'));
        // 3. get substring
        System.out.println(s1.substring(6, 11));
    }
}
```

time for these operations is O(N);

Never forget to take the time complexity of built-in operations into consideration when you compute the time complexity for your solution.

###  Immutable String - Problems & Solutions

String concatenation in java is MUCH slower than c++...
because it allocates a new string, copies everything and adds the string.

so it's `O(n2)`.

**1. If you did want your string to be mutable, you can convert it to** **a char** **array****.**


```
public class Main {
    public static void main(String[] args) {
        String s = "Hello World";
        char[] str = s.toCharArray();
        str[5] = ',';
        System.out.println(str);
    }
}
```

**If you have to concatenate strings often, it will be better to use some other data structures like** **`StringBuilder`****. The below code runs** **in** **`O(n)`** **complexity****.**

```
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        int n = 10000;
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < n; i++) {
            str.append("hello");
        }
        String s = str.toString();
    }
}
```

### Add Binary

