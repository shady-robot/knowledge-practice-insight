# Go

`package main`

This is known as a package declaration, and every Go program must start with it.
Packages are Go's way of organizing and reusing code.

* Executable: executed directly from the terminal
* Libraries: collections of code that can be reused.

## Variables

Defining multiple variables.

```go
var x string x = "Hello, World"
var x = "Hello, World"
var a, b, c int

var (
    a = 5
    b = 10
    c = 15
)
```

## Control loop

```go
for i:=1; i<=10; i++ {
    fmt.Println(i)
}

switch i {
    case 0: fmt.Println("Zero")
    case 1: fmt.Println("One")
    case 2: fmt.Println("Two")
    default: fmt.Println("Beyong")
}
```

## Arrays, slices, and maps

### Array

An array is a numbered sequence of elements of a single type with a fixed length.

```go
var x [5]int
x[4] = 100

x := [5]float64{ 98, 93, 77, 82, 83 }

var total float64 = 0
for _, value := range x {
    total +=  value
}
```

### Slices

A slice is a segment of an array. Like arrays, slices are indexable and have a
length. This length is allowed to change.

```go
var x []float64
slice1 := []int{1,2,3}
slice2 := appned(slice1, 4, 5)
```

### Maps

A map is an unordered collection of key-value pairs. Maps are used to look up a
value by its associated key.

```go
x := make(map[string]int)
x["key"] = 10

value, ok = x["key"]

if name,ok := elements[Un]; ok {
    fmt.Println(name, ok)
}
```

Accessing an element of a map can return two values instead of just one. The
first value is the result of the lookup, the second tells us whether or not the
lookup was successful.

## Functions

A function is an independent section of code that maps zero or more input
parameters to zero or more output parameters.

```go
# By using an ellipsis(...)  before the type name, which indicates that it takes
# zero or more of those parameters.

func add(args ...int) int{
    total := 0
    for _, v := range args {
        total += v
    }
    return total
}
```

## Source Code

* [FahrenheitCelsius.go](./FahrenheitCelsius.go)
* [FizzBuzz.go](./FizzBuzz.go)
* [SmallestNum.go](./SmallestNum.go)
* [Swap.go](./Swap.go)
