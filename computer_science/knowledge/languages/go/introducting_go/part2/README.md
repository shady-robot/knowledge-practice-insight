# Go

## Structs

A struct is a type that contains named fields.

```go
type Circle struct {
    x float64
    y float64
    z float64
}

type Circle struct {
    x, y, z float64
}

var c Circle
c := new(Circle)
# This allocates memory for all the fields, sets each of them to their zero
# value, and return a pointer to the struct.
c := Circle{0, 0, 5}
```

In between the keyword func and the name of the function, we've added a receiver.
The receiver is like a parameter - it has a name and a type - but by creating the
function this way, it allows us to call the function using the `.` operator.

```go
func circleArea(c *Circle) float64 {
    return math.Pi * c.r * c.r
}

# Using methods
func (c *Circle) area() float64 {
    return math.Pi * c.r * c.r
}
```

## Interfaces

An interface is created using the type keyword, followed by a name and the
keyword interface. But instead of defining fields, we define a method set. A
method set is a list of methods that a type must have in order to implement the
interface.

```go
type Shape interface {
    area() float
}
```

## Packages

### Strings

Go includes a large number of functions to work with strings in the strings
packages.

```go
import (
    "fmt"
    "strings"
)

fmt.Println(strings.Contains("test", "es"))
fmt.Println(strings.Count("test", "t"))
fmt.Println(strings.HasPrefix("test", "te"))
fmt.Println(strings.HasSuffix("test", "st"))
fmt.Println(strings.Index("test", "e"))
fmt.Println(strings.Join([]string{"a","b"}, "-"))
fmt.Println(strings.Repeat("a", 5))
fmt.Println(strings.Replace("aaaa", "a", "b", 2))
fmt.Println(strings.Split("a-b-c-d-e", "-")))
```

### Input/Output

### Files and Folders

### Errors

```go
import "errors"

func main(){
    err := errors.New("error message")
}
```

### Documentation

Go has the ability to automatically generate documentation for packages we write
in a similar way to the standard package documentation.

```shell
godoc ./greetings

# Start a local godoc server
godoc -http=":6060"

```

## Source Code

* [StructInterface.go](./StructInterface.go)
* [HTTPServer.go](./HTTPServer.go)
