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
  and not in the function definition.
* Any default parameters must appear at the end of the parameter list.

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

One of the best ways to validate the design of an interface is to write
applications that use it.

The rand function generate each new random value by applying a set of
mathematical calculations to the last value it produced. The initial value -
the value that is used to get the entire process started - is called the seed
for the random number generator.

![Random Steps](./images/random_step.png)

### static local variable

The rules of C++ ensure that static local variables are initialized exactly once
and, moreover, that the initialization occurs before the function containing
them is called.

Local variables have `automatic duration` by default, which means they are
created at the point of definition, and destroyed when the block is exited.
Using the `static` keyword on a local variable changes its duration from
`automatic duration` to `static duration`. This means the varaible is now
created at the start of the program, and destroyed at the end of the program.
Static local variables are only initialized the first time the code is executed,
not on subsequent calls.

```c++
static bool initialized = false;
```

### compile multiple cpp files

Use the following method only if you don't care about makefile.

```shell
# wildcard
g++ *.cpp -o output

# specify all cpp file
g++ filename1.cpp filename2.cpp main.cpp -o output

# generate .o file separately.
g++ -c myclass.cpp
g++ -c main.cpp
g++ myclass.o main.o
./a.out
```

## Review Questions

<details>
  <summary>What is a predicate function?</summary>

  A predicate is a function that tests for some condition involving its
  arguments and returns nil if the condition is false, or some non-nil value if
  the condition is true. You use predicate functions to check if your input
  meets some condition.

  > A logical expression which evaluates to TRUE or FALSE, normally to direct
  the execution path in code.

</details>

<details>
  <summary>What is meant by the term overloading? How does the C++ compiler use
  signatures to implement overloading?</summary>

  Overloading refers to a set of processes in computer programming by which one
  special word or symbol may be given multiple meanings.

  C++ allows specification of more than one function of the same name in the
  same scope. These functions are called overloaded functions. Overloaded
  functions enable you to supply different semantics for a function, depending
  on the types and number of arguments.

  refer the [overloading](#overloading) section above.

</details>

<details>
  <summary>What is a stack frame?</summary>

  The call stack is divided up into contiguous pieces called stack framew, or
  frames for short; each frame is the data associated with one call to one
  function. The frame contains the arguments given to the function, the
  function's local variables, and the address at which the function is
  executing.

  When your program is started, the stack has only one frame, that of the
  function main(). This is called the initial frame or the outermost frame.
  Each time a function is called, a new frame is made. Each time a function
  returns, the frame for that function invocation is eliminated. If a function
  is recursive, there can be many frames for the same function. The frame for
  the function in which execution is actually occurring is called the innermost
  frame. This is the most recently created of all the stack frames that still
  exist.

  Inside your program, stack frames are identified by their addresses. A stack
  frame consists of many bytes, each of which has its own address; each kind of
  computer has a convention for choosing one byte whose address serves as the
  address of the frame. Usually this address is kept in a register called the
  frame pointer register while execution is going on in that frame.

</details>

## Exercises

* exercises-6

  ![exercises-6](./images/chapter2_ex6.png)
  solution: [Prime.cpp](./codes/exercises/Prime.cpp)

* exercises-10

  ![exercises-10](./images/chapter2_ex10.png)
  solution: [ReverseDigits.cpp](./codes/ReverseDigits.cpp)

* exercises-16

  ![exercises-16](./images/chapter2_ex16.png)
  solution: [ReverseDigits.cpp](./codes/ReverseDigits.cpp)

## Source Code

* [HelloWorld.cpp](./codes/HelloWorld.cpp)
* [PowerOfTwo.cpp](./codes/PowerOfTwo.cpp)