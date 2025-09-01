package main
import "fmt"

func main() {
 //Enter your code here. Read input from STDIN. Print output to STDOUT
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++{
		var x long int
		var k int64
		fmt.Scan(&x, &k)
		result := x/k
		fmt.Println(result)
	}
}