//
// SmallestNum.go
//

/*
Write a program that finds the smallest number in this list:
x := []int{ 48,96,86,68,
        57,82,63,70,
        37,34,83,27,
        19,97, 9,17,
}
*/

package main

import "fmt"

func main() {

    x := []int{ 
        48,96,86,68,
        57,82,63,70,
        37,34,83,27,
        19,97, 9,17,
    }
    small := x[0]
    for _, value := range x {
        if value < small {
            small = value 
        }
    }
    fmt.Println("The smallest num is ", small)
}
