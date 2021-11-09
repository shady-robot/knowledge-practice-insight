//
// Swap.go
// Copyright (C) 2021 shady <shady@MrRobot.local>
//
// Distributed under terms of the MIT license.
//

package main

import "fmt"

func main(){
    x, y := 1, 2
    fmt.Printf("Before swap: x = %d y = %d\n", x, y)

    swap(&x, &y)
    fmt.Printf("After swap: x = %d y = %d\n", x, y)
}

func swap(x *int, y *int){
    temp := *y;
    *y = *x;
    *x = temp;
}

func swapUpgrade(x *int, y *int){
    *x,*y = *y,*x
}
