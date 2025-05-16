
## Install the compiler

`   npm install -g typescript   `

## Compile

```
tsc --noEmitOnError hello.ts
```
## Explicit types

Telling what the variable type is

```
function greet(person: string, date: Date) {  console.log(`Hello ${person}, today is ${date.toDateString()}!`);}
```

What we did was add _type annotations_ on `person` and `date`

Keep in mind, we don’t always have to write explicit type annotations

![[Pasted image 20250516090522.png]]


we can target the version of ECMASCRIPT by using the `--target es2015` option

