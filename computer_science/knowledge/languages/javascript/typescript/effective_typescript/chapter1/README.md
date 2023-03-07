# TypeScript Introduction

TypeScript is a superset of Javascript. TypeScript files use a `.ts`(or `.tsx`)
extension, rather than the `.js`(or `.jsx`) extension of a Javascript file. One
of the goals of TypeScript's type system is to detect code that will throw an
exception at runtime, without having to run your code.

How dose TypeScript decide when to model Javascript's runtime behavior and when
to go beuyond it. By adopting TypeScript you're trusting the judgement of the
team that builds it.

TypeScript adds a type system that models Javascript's runtime behavior and
tries to spot code which will throw exceptions at runtime.

Many of TypeScript's configuration settings control where it looks for source
files, and what sort of output it generates. But a few control core aspects of
the language itself. To use it effectively, you should understand the most
important of these settings: `noImplicitAny` and `strictNullChecks`.

* `noImplicitAny` controls whether variables must have known types.
* `strictNullChecks` controls whether `null` and `undefined` are permissible
  value in every type.

The TypeScript compuler includes several settings which affect core aspects of
the language.

## The TypeScript Compiler(tsc)

* It converts next-generation TypeScript/Javascript to an old version of
  Javascript that work in browsers.
* It checks your code for type errors.

You cannot check TypeScript Types at Runtime. TypeScript types are erasable:
part of compilation to JavaScript is simply remove all the `interfaces`, `types`
, and type annotations from your code.

* Type Operations cannot affect runtime values.
* Runtime types may not be the same as declared types.
* You cannot overload a function based on TypeScript types.
* TypeScript Types have no effect on runtime performance.
  * While there is no runtime overhead, the TypeScript compiler will introduce
    build time overhead.
  * The code that TypeScript emits to support older runtimes may incur a
    performance overhead vs native implementations.
