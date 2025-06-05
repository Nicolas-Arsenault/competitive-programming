## The primitives: `string`, `number`, and `boolean`
## Arrays
you can use the syntax `number[]`

You may also see this written as `Array<number>`, which means the same thing.

## `any`
TypeScript also has a special type, `any`, that you can use whenever you don’t want a particular value to cause typechecking errors.

```
let obj: any = { x: 0 };// None of the following lines of code will throw compiler errors.// Using `any` disables all further type checking, and it is assumed// you know the environment better than TypeScript.obj.foo();obj();obj.bar = 100;obj = "hello";const n: number = obj;
```

The `any` type is useful when you don’t want to write out a long type just to convince TypeScript that a particular line of code is okay.

### `noImplicitAny`

When you don’t specify a type, and TypeScript can’t infer it from context, the compiler will typically default to `any`.

You usually want to avoid this, though, because `any` isn’t type-checked. Use the compiler flag [`noImplicitAny`](https://www.typescriptlang.org/tsconfig#noImplicitAny) to flag any implicit `any` as an error.

## [](https://www.typescriptlang.org/docs/handbook/2/everyday-types.html#type-annotations-on-variables)

## Type Annotations on Variables

When you declare a variable using `const`, `var`, or `let`, you can optionally add a type annotation to explicitly specify the type of the variable:

```
let myName: string = "Alice";
```

Wherever possible, TypeScript tries to automatically _infer_ the types in your code. For example, the type of a variable is inferred based on the type of its initializer:

```
// No type annotation needed -- 'myName' inferred as type 'string'let myName = "Alice";
```

### functions

### Parameter Type Annotations

```
function greet(name: string) 
{  console.log("Hello, " + name.toUpperCase() + "!!");
}
```

### Return Type Annotations

```
function getFavoriteNumber(): number {  return 26;}
```

#### [](https://www.typescriptlang.org/docs/handbook/2/everyday-types.html#functions-which-return-promises)Functions Which Return Promises

If you want to annotate the return type of a function which returns a promise, you should use the `Promise` type:

```
async function getFavoriteNumber(): Promise<number> {  return 26;}
```

### [](https://www.typescriptlang.org/docs/handbook/2/everyday-types.html#anonymous-functions)

### Anonymous Functions
```
const names = ["Alice", "Bob", "Eve"]; // Contextual typing for function - parameter s inferred to have type stringnames.forEach(function (s) {  console.log(s.toUpperCase());}); // Contextual typing also applies to arrow functionsnames.forEach((s) => {  console.log(s.toUpperCase());});
```

## Object Types

Its' a value with propreties

```
function printCoord(pt: { x: number; y: number }) 
{  console.log("The coordinate's x value is " + pt.x);
	console.log("The coordinate's y value is " + pt.y);
}

printCoord({ x: 3, y: 7 });
```

### Optional Properties
Object types can also specify that some or all of their properties are _optional_. To do this, add a `?` after the property name:

```
function printName(obj: { first: string; last?: string }) 
{  // ...
}
// Both OK
printName({ first: "Bob" });
printName({ first: "Alice", last: "Alisson" });
```

## Union Types
The first way to combine types you might see is a _union_ type. A union type is a type formed from two or more other types, representing values that may be _any one_ of those types.

```
function printId(id: number | string) 
{  
console.log("Your ID is: " + id);
}
```

can receive a number or a string

TypeScript will only allow an operation if it is valid for _every_ member of the union.

![[Pasted image 20250516133219.png]]

solution:

```
function printId(id: number | string) 
{  
	if (typeof id === "string") 
	{    // In this branch, id is of type 'string'    
		console.log(id.toUpperCase());  
	} else 
	{    // Here, id is of type 'number'    
		console.log(id);  
	}
}
```
Another example is to use a function like `Array.isArray()`:

## [](https://www.typescriptlang.org/docs/handbook/2/everyday-types.html#type-aliases)

## Type Aliases
```
type Point =  { 
	x: number;  y: number;
};
```

```
function printCoord(pt: Point) 
{  
	console.log("The coordinate's x value is " + pt.x);  
	console.log("The coordinate's y value is " + pt.y);
} 
```

You can actually use a type alias to give a name to any type at all, not just an object type. For example, a type alias can name a union type:

```
type ID = number | string;
```

Note that aliases are _only_ aliases

## Interfaces
An _interface declaration_ is another way to name an object type:

```
interface Point {  x: number;  y: number;}
```

TypeScript is only concerned with the _structure_ of the value we passed to `printCoord`

### [](https://www.typescriptlang.org/docs/handbook/2/everyday-types.html#differences-between-type-aliases-and-interfaces)Differences Between Type Aliases and Interfaces
the key distinction is that a type cannot be re-opened to add new properties vs an interface which is always extendable.

![[Pasted image 20250516134602.png]]

## [](https://www.typescriptlang.org/docs/handbook/2/everyday-types.html#type-assertions)Type Assertions

For example, if you’re using `document.getElementById`, TypeScript only knows that this will return _some_ kind of `HTMLElement`, but you might know that your page will always have an `HTMLCanvasElement` with a given ID.

In this situation, you can use a _type assertion_ to specify a more specific type:

```
const myCanvas = document.getElementById("main_canvas") as HTMLCanvasElement;
```

TypeScript only allows type assertions which convert to a _more specific_ or _less specific_ version of a type. This rule prevents “impossible” coercions like:

```
const x = "hello" as number;
```

Sometimes this rule can be too conservative and will disallow more complex coercions that might be valid. If this happens, you can use two assertions, first to `any` (or `unknown`, which we’ll introduce later), then to the desired type:

```
const a = expr as any as T;

```

![[Pasted image 20250516140401.png]]

```
// Change 1:

const req = { url: "https://example.com", method: "GET" as "GET" };

// Change 2

handleRequest(req.url, req.method as "GET");
```

or

```
const req = { url: "https://example.com", method: "GET" } as const;
handleRequest(req.url, req.method);
```

The `as const` suffix acts like `const` but for the type system, ensuring that all properties are assigned the literal type instead of a more general version like `string` or `number`.
## Literal types

```
function printText(s: string, alignment: "left" | "right" | "center") {  // ...}
```

can force to use only these options

## `null` and `undefined`

### `strictNullChecks` on

With [`strictNullChecks`](https://www.typescriptlang.org/tsconfig#strictNullChecks) _on_, when a value is `null` or `undefined`, you will need to test for those values before using methods or properties on that value. Just like checking for `undefined` before using an optional property, we can use _narrowing_ to check for values that might be `null`:

```
function doSomething(x: string | null) 
{  
	if (x === null) 
	{    
		// do nothing  
	} 
	else 
	{    
		console.log("Hello, " + x.toUpperCase());  
	}
}
```

### Non-null Assertion Operator (Postfix `!`)

TypeScript also has a special syntax for removing `null` and `undefined` from a type without doing any explicit checking. Writing `!` after any expression is effectively a type assertion that the value isn’t `null` or `undefined`:

```
function liveDangerously(x?: number | null)
{    
	// No error    
	console.log(x!.toFixed());  
} 
```   

## Enums
describing a value which could be one of a set of possible named constants.

## [](https://www.typescriptlang.org/docs/handbook/2/everyday-types.html#less-common-primitives)

## Less Common Primitives

bigint 

```
const oneHundred: bigint = BigInt(100);
```

```
const anotherHundred: bigint = 100n;
```

#### `symbol`


```
const firstName = Symbol("name");
const secondName = Symbol("name");
```

