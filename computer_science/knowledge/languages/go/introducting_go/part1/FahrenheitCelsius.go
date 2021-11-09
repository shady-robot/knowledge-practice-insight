//
// FahrenheitCelsius.go
// Copyright (C) 2021 shady <shady@MrRobot.local>
//
// Distributed under terms of the MIT license.
//

package main

import "fmt"

func main(){
    fmt.Print("Enter a fahrenheit: ")
    var fahrenheit, celsius float64;
    fmt.Scanf("%f", &fahrenheit)

    celsius = (fahrenheit - 32) * 5 / 9

    fmt.Printf("Fahrenheit: %0.3f°F convert to Celsius: %0.3f°C\n", fahrenheit, celsius)
}
