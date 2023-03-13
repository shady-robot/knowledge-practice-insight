# TypeScript's Type System

* `tsc`: The TypeScript compiler
* `tsserver`: The TypeScript standalone server

Type declarations can be an excellent way to see what can be done with
TypeScript, how the library you're using is modeled, and how you might debug
errors.

## Think of Types as sets of values

A variable has a type, which has a set of possible values. This is known as the
domain of the type. The smallest set is the empty set, which contains no values.
It corresponds to the `never` type in TypeScript.

Union types correspond to unions of sets of values.

