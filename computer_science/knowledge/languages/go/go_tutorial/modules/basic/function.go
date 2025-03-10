package main

import (
	"fmt"
	"math"
)

// functions are values too. They can be passed around just like other values.

func compute(fn func(float64, float64) float64) float64 {
	return fn(3, 4)
}

func FunctionDemo() {
	hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}

	fmt.Println(hypot(5, 12))
	fmt.Println(compute(hypot))
	fmt.Println(compute(math.Pow))

}
