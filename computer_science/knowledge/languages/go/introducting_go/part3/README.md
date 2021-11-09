# Go

## Testing

Each test function takes in a variable of type testing.T, which is used to raise
errors when a test fails. testing.T objects can also be used to log messages if
needed.

```go
package gmath

import "testing"

func TestAverage(t *testing.T){
    v := Average([]float64{1,2})
    if v != 1.5 {
        t.Error("Expected 1.5, got", v)
    }
}
```

refer to [gmath_test.go](./gmath/gmath_test.go) for detail.

## Concurrency

Go has rich support for concurrency using goroutines and channels.

### Goroutines

A goroutine is a function that is capable of running concurrently with other
functions. To create a goroutine, we use the keyword `go` followed by a function
invocation.

```go
func f(n int) {
    for i:=0; i<10; i++ {
        fmt.Println(n, ":", i)
        amt := time.Duration(rand.Intn(250))
        time.Sleep(time.Millisecond * amt)
    }
}

func main(){
    go f(0)
    var input string
    fmt.Scanln(&input)
}
```

### Channels

Channels provide a way for two goroutines to communicate with each other and
synchronize their execution. A channel type is represented with the keyword
`chan` followed by the type of the things that are passed on the channel.

## Source Code

* [gmath](./gmath)
* [GoroutineSleep.go](./GoroutineSleep.go)
* [PingPongChannel.go](./PingPongChannel.go)
