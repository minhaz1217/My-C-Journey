/*
4.27 (Pythagorean Triples) A right triangle can have sides that are all integers. The set of three
integer values for the sides of a right triangle is called a Pythagorean triple. These three sides must
satisfy the relationship that the sum of the squares of two of the sides is equal to the square of the
hypotenuse. Find all Pythagorean triples for side1, side2, and the hypotenuse all no larger than 500.
Use a triple-nested for loop that simply tries all possibilities. This is an example of “brute-force”
computing. It’s not aesthetically pleasing to many people. But there are many reasons why these
techniques are important. First, with computing power increasing at such a phenomenal pace, solutions
that would have taken years or even centuries of computer time to produce with the technology
of just a few years ago can now be produced in hours, minutes or even seconds. Recent
microprocessor chips can process a billion instructions per second! Second, as you’ll learn in more
advanced computer science courses, there are large numbers of interesting problems for which
there’s no known algorithmic approach other than sheer brute force. We investigate many kinds of
problem-solving methodologies in this book. We’ll consider many brute-force approaches to various
interesting problems.
*/
#include<stdio.h>
#include<math.h>
main(){
    int small,big,hypo, a= 50, sum1 = 0, sum2= 0;
    for(hypo = 0; hypo <=a;hypo++){
        for(big=0;big<=a;big++){
            for(small=0;small<=a;small++){
                sum1 = pow(small, 2) + pow(big,2);
                sum2 = pow(hypo,2);
                if(sum1 == sum2){
                    printf("%d^2 + %d^2 = %d^2\n", big, small, hypo);
                }
            }
        }
    }
}
