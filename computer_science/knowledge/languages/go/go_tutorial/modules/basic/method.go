package main

import (
	"fmt"
	"math"
)

type VertexA struct {
	X, Y float64
}

func (v VertexA) Abc() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func MethodDemo() {
	v := VertexA{3, 4}
	fmt.Println(v.Abc())
}
