package main

import (
	"fmt"
	"strings"
)

type Vertex struct {
	Lat, Long float64
}

var m map[string]Vertex

func MapDemo() {
	// The make function returns a map of the given type, initialized and ready for use.
	m = make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}
	fmt.Println(m["Bell Labs"])

	var n = map[string]Vertex{
		"Bell Labs": {40.3, 23.3},
		"Google":    {37.4, 122.1},
	}
	fmt.Println(n)
}

func WordCount(s string) map[string]int {
	words := strings.Fields(s)
	wordCount := make(map[string]int)
	for _, word := range words {
		wordCount[word]++
	}
	return wordCount
}
