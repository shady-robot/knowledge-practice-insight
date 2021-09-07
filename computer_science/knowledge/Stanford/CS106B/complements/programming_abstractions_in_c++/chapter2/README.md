# Functions and Libraries

## The idea of function

### functions in programming

Functions are "self contained" modules of code that accomplish a
specific task. Functions usually "take in" data, process it, and
"return" a result. Once a function is written, it can be used over and over
and over again. Functions can be "called" from the inside of other functions.

### The advantages of using functions

* Avoid repetition of codes.
* Increases program readability.
* Divide a complex problem into simpler ones.
* Reduces chances of error.
* Modifying a program becomes easier by using function.

## Libraries

> In computer science, a library is a collection of non-volatile resources used
> by computer programs, often for software development. These may include
> configuration data, documentation, help data, message templates, pre-written
> code and subroutines, classes, values or type specifications.

Whenever a library makes some service available to the programs that include it,
computer scientists say that the library exports that service. One of the design
goals of any library is to hide the complexity involved in the underlying
implementation.

## Defining functions in C++

A parameter is a placeholder for one of the arguments supplied in the function
call and acts in most respects like a local variable. The only difference is
that each parameter is initialized automatically to hold the value of the
corresponding argument.

A function that does not return a value and is instead executed for its effect
is often called a procedure. Procedures are indicated in the definition of a
function by using the reserved word void as the result type.

### Function prototypes

When the C++ compiler encounters a function call in your program, it needs to
have some information about that function in order to generate the correct code.
The compiler needs to know what arguments the function requires and what type of
value it returns. That information is usually provided by a prototype, which is
simply the header line of the function followed by a semicolon.

### Overloading

In C++, it is legal to give the same name to more than one function as long as
the pattern of arguments is different. When the compiler encounters a call to
a function with that name, it checks to see what arguments have been provided
and chooses the version of the function that fits those arguments. Using the
same name for more than one version of a function is called overloading. The
pattern of arguments taken by a function -- which refers only to the number and
types of the arguments and not the parameter names --  is called its signature.

### Default parameters

The parameter variables still appear in the function header line, but the
prototype for the function specifies the values that those parameters should
have if they do not appear in the call. Such parameters are called default
parameters. To indicate that a parameter is optional, you need to do is include
an initial value in the declaration of that parameter in the function prototype.

* The specification of the default value appears only in the function prototype
* and not in the function definition.
* Any default parameters must appear at the end of the parameter list.

## The mechanics of function calls

stack frame

return type problem

### The combinations function

Given a set containing n distinct elements, how many ways can you choose a
subset with k elements?

[Combination.cpp](./codes/Combinations.cpp)

## Reference parameters

If you want to change the value of the calling argument--and there are often
compelling reasons for doing so--you can change the parameter from the usual
kind of C++ parameter into a reference parameter by adding an ampersand between
the type and the name in the function header.

```c++
void setToZero(int &var){
    var = 0;
}
```

This style of parameter passing is known as call by reference. In C++, one of
the most common uses of call by reference occurs when a function needs to
return more than one value to the calling program.

[Quadratic.cpp](./codes/Quadratic.cpp)

## Interfaces and implementations

A typical interface will export several definitions, which are typically
functions, types, or constants. Each individual definition is called an
interface entry.
In C++, the interface and implementation are usually written as two separate
files. The name of the interface file ends with `.h`, which marks it as a header
file. The implementation appears in a file with the same root, but with
the suffix `.cpp`.

### Exporting constant definitions

In C++, constant written in this form are private to the source file that
contains them and cannot be exported through an interface. You need to add
the keyword `extern` to both its definition and the prototype declaration
in the interface.

```c++
/* gmath.h: Constants */
extern const double PI;

/* gmath.cpp */
extern const double PI = 3.141592653589;
```

## Principles of interface design

A function gives its caller access to a set of steps that together implement a
single operation. A library gives its client access to a set of functions and
types that implement what computer scientists describe as a programming
abstraction.

* Unified: An interface should define a consistent abstraction with a clear
  unifying theme.
* Simple: To the extent that the underlying implementation is itself complex,
  the interface must seek to hide that complexity from the client.
* Sufficient. When clients use an abstraction, the interface must provide
  sufficient functionality to meet their needs.
* General: A well-designed interface should be flexible enough to meet the needs
  of many different clients.
* Stable: The functions defined in an interface should continue to have
  precisely the same structure and effect, even if the underlying implementation
  changes.

The interface is written for the benefit of the client and should contain only
what the client needs to know.

## Designing a random number library

Computers do in fact use a deterministic procedure to generate what we call
random numbers. "Random" numbers generated by an algorithmic process inside a
computer are referred to as pseudorandom numbers to underscore the fact that no
truly random activity is involved.
