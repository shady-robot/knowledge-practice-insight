//
// gmath_test.go
// Copyright (C) 2021 shady <shady@MrRobot.local>
//
// Distributed under terms of the MIT license.
//

package gmath

import "testing"

func TestAverage(t *testing.T){
    v := Average([]float64{1,2})
    if v != 1.5 {
        t.Error("Expected 1.5, got", v)
    }

}

type testpair struct {
    values []float64
    average float64
    min float64
    max float64
}

var tests = []testpair{
    { []float64{1,2}, 1.5, 1, 2},
    { []float64{1,1,1,1,1,1,1}, 1, 1, 1},
    { []float64{-1, 1}, 0, -1, 1},
    { []float64{-1, 1, 2, -2, 4, -4}, 0, -4, 4},
}

func TestAveragePairs(t *testing.T) {
    for _, pair := range tests {
        v := Average(pair.values)
        if v != pair.average {
            t.Error(
                "For ", pair.values,
                "expected ", pair.average,
                "got ", v,
            )
        }
    }
}

func TestMinPairs(t *testing.T) {
    for _, pair := range tests {
        v := Min(pair.values)
        if v != pair.min {
            t.Error(
                "For ", pair.values,
                "expected ", pair.min,
                "got ", v,
            )
        }
    }
}

func TestMaxPairs(t *testing.T) {
    for _, pair := range tests {
        v := Max(pair.values)
        if v != pair.max {
            t.Error(
                "For ", pair.values,
                "expected ", pair.max,
                "got ", v,
            )
        }
    }
}
