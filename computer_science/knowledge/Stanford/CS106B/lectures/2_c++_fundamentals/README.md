# C++ Fundamentals

> If someone claims to have the perfect programming language, he is either a
> fool or a salesman or both. – Bjarne Stroustrup, Inventor of C++

## Lecture Meta

* Themes: C++ Fundamentals
* Textbook: Text Ch.1, 2.1-2.4
* [Slides][1]

## compiled VS interpreted

* **compiled language:** Compiled language are converted directly into machine
  code that the processor can execute, which tend to be more efficient.
* **interpreted language:** Interpreters run through a program line by line and
  execute each command.

Low-level programming languages are typically compiled, especially when
efficiency is the main concern, rather than cross-platform support.
Programming languages that support multiple compiling targets gives developers
more control to choose either execution speed or cross-platform compatibility.

## core programming fundamentals in C++

### variables

> A variable or scalar is a storage location (identified by a memory address)
> paired with an associated symbolic name, which contains some known or
> unknown quantity of information referred to as a value; or in easy terms,
> a variable is a container for a particular type of data (like integer, float,
> String and etc...).

#### Naming conventions

C++ uses the camelCace naming convention.

#### types and values

Assigning a data type, termed typing, gives meaning to a sequence of bits such
as a value in memory or some object such as a variable.

```c++
  int(or long)
  double
  string
  char
```

Since C++ is a **statically typed languages**, all types must be explicitly
defined when the variable is created, and a variable cannot change its type.

#### variable scope

The scope of a variable describes where in a program's text the variable may be
used, while the extent (or lifetime) describes when in a program's execution a
variable has a (meaningful) value. The scope of a variable is actually a
property of the name of the variable, and the extent is a property of the
variable itself.

### functions and parameters

#### function prototype

```c++
returnType functionName(varType parameter1, varType parameter2, ...)
```

#### function definition

```c++
returnType functionName(varType parameter1, varType parameter2, ...){
  returnType variable = /* Some fancy code. */
  /* Some more code to actually do things. */
  return variable;
}
```

[1]: https://web.stanford.edu/class/cs106b/lectures/02-cpp/Lecture2Slides.pdf
