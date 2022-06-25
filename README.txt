This is an over engineered Fizz Buzz Program that takes as many number text combos as you want

It is optimised for large sets of FizzBuzz combos with smallest common divisors 
Where there is a list (vector of vectors) of the smallest common divisors that dont divide among themselfs
E.g. 2,3,5 (so mainly prime numbers)
That checks for the rest of FizzBuzz combos only if it finds a divisor it the first dimention of the list.
E.g. first dimention has numbers: 3 , 4 , 5
so it looks like this on its second dimention
 3|  4|  5
 6|  8| 10
 9|   
12|
15|

and so on