//
// GoroutineSleep.go

package main

import (
    "fmt"
    "time"
    "math/rand"
)

func f(n int){
    for i:=0; i<3; i++ {
        fmt.Println("Routines-", n, ": ", i)
        amt := time.Duration(rand.Intn(2500))
        time.Sleep(time.Millisecond * amt)
    }
}

func main(){
    for i:=0; i<10; i++ {
        go f(i)
    }
    var input string
    fmt.Scanln(&input)
}


