# Collections

data structures
collection classes
abstract data type ADT
Standard Template Library, STL

A type defined in terms of its behavior rather than its representation is
called an abstract data type, which is often abbreviated to ADT. Abstract data
types are central to the object-oriented style of programming, which encourages
programmer to think about data structures in holistic way.

Being able to separate the behavior of a class from its underlying
implementation is a fundamental precept of object-oriented programming.

* simplicity: Hiding the internal representation from the client means that
  there are fewer details for the client to understand.
* Flexibility: Because a class is defined in terms of its public behavior, the
  programmer who implements one is free to change its underlying private
  representation.
* Security: The interface boundary acts as a wall that protects the
  implementation and the client from each other.

## The Vector class

### Specifying the base type of a Vector

In C++, collection classes specify the type of object they contain by including
the type name in angle brackets following the class name.

Classes that include a base-type specification are called parameterized classes
in the object-oriented community.

```c++
const int N_HOLES = 18;
Vector<int> golfScores(N_HOLES);
for (int i=0; i<vec.size(); i++){
    //loop body
}
```

### Constructor

C++ automatically initializes that variable by invoking a special method called
a constructor. The C++ compiler determines which version of the constructor to
call by looking at the arguments appearing in the declaration, just as it does
for overloaded functions.

### Representing two-dimensional structures

`Vector < Vector<int> > sudoku(9, Vector<int>(9))`

## The Stack class

A stack provides storage for a collection of data values, subject to the
restriction that values must be remove from a stack in opposite order from
which they were added.[LIFO]

The primary reason that stacks are important in programming is that nested
function calls behave in a stack-oriented fashion.

## The Queue class

A data structure that stores items using a FIFO discipline is called a queue.

* enqueue: Adds a new element to the end of the queue, which is called tail
* dequeue: Remove the element at the beginning of the queue,which is
  called head.

### models and simulations
