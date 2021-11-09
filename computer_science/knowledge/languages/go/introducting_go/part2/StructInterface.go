//
// StructInterface.go
//

package main

import (
    "fmt" 
    "math"
)

type Distance struct {
    x1, y1, x2, y2 float64
}

type Rectangle struct {
    x1, y1, x2, y2 float64
}

type Circle struct {
    x, y, r float64
}


type Shape interface {
    area() float64
    perimeter() float64
}

type MultiShape struct {
    shapes []Shape
}

func (d *Distance) distance() float64 {
    a := d.x2 - d.x1
    b := d.y2 - d.y1
    return math.Sqrt(a*a + b*b)
}


func (c *Circle) area() float64 {
    return math.Pi * c.r * c.r
}
func (c *Circle) perimeter() float64 {
    return 2 * math.Pi * c.r
}

func (r *Rectangle) area() float64 {
    d1 := Distance{r.x1, r.y1, r.x1, r.y2}
    d2 := Distance{r.x1, r.y1, r.x2, r.y1}
    l := d1.distance()
    w := d2.distance()
    return l * w
}

func (r *Rectangle) perimeter() float64 {
    d1 := Distance{r.x1, r.y1, r.x1, r.y2}
    d2 := Distance{r.x1, r.y1, r.x2, r.y1}
    l := d1.distance()
    w := d2.distance()
    return 2 * (l + w)
}

func (m *MultiShape) area() float64 {
    var area float64
    for _, s := range m.shapes {
        area += s.area()
    }
    return area
}

func main(){
    c := &Circle{0, 0, 5}
    r := &Rectangle{0, 0, 10, 10}
    multiShape := MultiShape {
        shapes: []Shape {
            c,
            r,
        },
    }
    fmt.Println(c.area())
    fmt.Println(r.area())
    fmt.Println(multiShape.area())

    // Output the perimeters of the shapes
    for _, shape := range multiShape.shapes {
        fmt.Println(shape.perimeter())
    }
}

