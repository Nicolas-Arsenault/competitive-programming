JavaScript est **sensible à la casse** et utilise l'ensemble de caractères **Unicode**. On pourrait donc tout à fait utiliser le mot früh comme nom de variable 

## [Commentaires](https://developer.mozilla.org/fr/docs/Web/JavaScript/Guide/Grammar_and_types#commentaires)

```
// un commentaire sur une ligne

/* un commentaire plus
   long sur plusieurs lignes
 */
```

## [Déclarations](https://developer.mozilla.org/fr/docs/Web/JavaScript/Guide/Grammar_and_types#déclarations)
[`var`](https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Statements/var)

On déclare une variable, éventuellement en initialisant sa valeur.

[`let`](https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Statements/let)

On déclare une variable dont la portée est celle du bloc courant, éventuellement en initialisant sa valeur.

[`const`](https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Statements/const)

On déclare une constante nommée, dont la portée est celle du bloc courant, accessible en lecture seule.

Voici des exemples de variables valides : `Nombre_touches`, `temp99`, `$credit`, et `_nom`.

## Déclaration variables
- En utilisant le mot-clé [`var`](https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Statements/var), par exemple : `var x = 42`. Cette syntaxe peut être utilisée pour déclarer des variables [locales ou globales](https://developer.mozilla.org/fr/docs/Web/JavaScript/Guide/Grammar_and_types#portées) selon le contexte d'exécution.
- En utilisant le mot-clé [`const`](https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Statements/const) ou le mot-clé [`let`](https://developer.mozilla.org/fr/docs/Web/JavaScript/Reference/Statements/let), par exemple avec `let y = 13`. Cette syntaxe peut être utilisée pour déclarer une variable dont la portée sera celle du bloc.

Si une variable n'a pas de valeur -> undefined

```
var input;
if (input === undefined) {
  faireCeci();
} else {
  faireCela();
}
```

La valeur `undefined` se comporte comme le booléen `false` lorsqu'elle est utilisée dans un contexte booléen.

ex:

```
var monTableau = new Array();
if (!monTableau[0]) {
  maFunction();
}
```

undefined est converti en Not a Number lorsqu'elle est utilisée dans une opératrion matématique

```
var a;
a + 2; // NaN
```

null => 0 dans une opération mathématique

```
var n = null;
console.log(n * 32); // Le log affichera 0
```

