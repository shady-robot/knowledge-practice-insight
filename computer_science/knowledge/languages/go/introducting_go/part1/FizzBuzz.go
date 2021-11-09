//
// FizzBuzz.go
// Copyright (C) 2021 shady <shady@MrRobot.local>
//
// Distributed under terms of the MIT license.
//

package main

import "fmt"

func main(){
    num := 100
    fizzBuzzA(num)

    fizzBuzzB(num)
}

func fizzBuzzB(num int){
    for i:=1; i<=num; i++ {
        printout := false
        if i%3 == 0 {
            fmt.Print("Fizz")
            printout = true
        }
        if i%5 == 0 {
            fmt.Print("Buzz")
            printout = true
        }
        if printout {
            fmt.Println()
        }
    }
}

func fizzBuzzA(num int){
    for i:=1; i<=num; i++ {
        if i%3 == 0 && i%5 == 0 {
            fmt.Println("FizzBuzz")
        } else {
            if i%3 == 0 {
                fmt.Println("Fizz")
            }
            if i%5 == 0 {
                fmt.Println("Buzz")
            }
        }
    }
}
