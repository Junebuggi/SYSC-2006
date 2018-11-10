/* SYSC 2006 Winter 2018 Lab 2, Part 2.
 *
 * Incomplete implementations of the functions that will be coded during the lab. 
 */

#include <stdlib.h>
#include <math.h>

#include "exercises.h"

/* Returns n! for n >= 0. (0! is defined to be 1.)
   Note that the return type is int, and n! grows rapidly as n increases,
   so this function should only be used for fairly small values of n; 
   i.e., if ints are implemented as 32-bit values, n must be <= 15.
*/
int factorial(int n)
{
	int factorial = 1;
	for(int i = n; i > 0; --i){
		factorial *= (i);
	}

    return factorial;
}

/* Returns the number of different ordered subsets of k objects picked
   from a set of n objects, for n > 0, k > 0, n >= k.
	
 */
int ordered_subsets(int n, int k)
{

    return factorial(n)/factorial(n-k);
}

/* Returns the binomial coefficient (n k); that is, the number of 
   combinations of k objects that can be chosen from a set of n objects, 
   for n > 0, k > 0, n >= k.
	n! / ((k!)(n - k)!) 

 */
int binomial(int n, int k)
{
    return factorial(n)/ (factorial(k) * factorial(n-k));
}

/* Returns the cosine of x (measured in radians) by calculating
 * the first n terms of the infinite series expansion of cosine.
	cos x = 1 - x
2
/2! + x
4
/4! - x
6
/6! + …
 */
double cosine(double x, int n)
{
	double sum = 0.0;
	double sum2 = 0.0;
	for(int i = 2; i <= n; i += 4){
		sum +=  pow(x, i)/factorial(i) ;
	}
	for(int i = 4; i <= n; i += 4){
		sum2 +=  pow(x, i)/factorial(i) ;
	}


    return 1 - sum + sum2;
}

