package main

import "fmt"

// Fizz if divisible by 3, buzz by 5, fizzbuzz for both
func main() {
	fmt.Println("~Fizzbuzz~")
	printFizzBuzzRange(0, 25)
}

func printFizzBuzzRange(start, end int) {
	for ; start <= end; start++ {
		printFizzBuzz(start)
	}
}

func printFizzBuzz(specific int) {
	if specific%3 == 0 && specific%5 == 0 {
		fmt.Println("FizzBuzz")
	} else if specific%3 == 0 {
		fmt.Println("Fizz")
	} else if specific%5 == 0 {
		fmt.Println("Buzz")
	} else {
		fmt.Println(specific)
	}
}
