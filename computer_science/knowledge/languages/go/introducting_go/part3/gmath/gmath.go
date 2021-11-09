//
// math.go
// Copyright (C) 2021 shady <shady@MrRobot.local>
//
// Distributed under terms of the MIT license.
//

package gmath

import "math"

func Average(xs []float64) float64 { 
    total := float64(0)
    for _,x := range xs{
        total += x 
    }
    return total / float64(len(xs)) 
}

func Min(xs []float64) float64 {
    min := math.Inf(1)
    for _, x := range xs {
        if x < min {
            min = x
        }
    }
    return min
}

func Max(xs []float64) float64 {
    max := math.Inf(-1)
    for _, x := range xs {
        if x > max {
            max = x
        }
    }
    return max
}
