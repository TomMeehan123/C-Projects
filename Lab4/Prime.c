 /* 
 * Solution to exercise 5.4: Use the Sieve of Eratosthenes to 
 * find all the prime numbers below 3500. This method works as follows:
 * 
 * 1. Create a list of consecutive integers from two to n: (2, 3, 4, ..., n).
 * 2. Initially, let p equal 2, the first prime number.
 * 3. Strike from the list all multiples of p less than or equal to n.
 * 4. Find the first number remaining on the list greater than p (this
 *    number is the next prime); replace p with this number. 
 * 5. Repeat steps 3 and 4 until you cannot find a number greater than p
 *    in step 4.
 * 6. All the remaining numbers on the list are prime.
 */

#include <stdlib.h>
#include <stdio.h>

// change this to increase/decrease upper limit for primes
#define LIMIT 200

int main()
{
  /*
   * The following algorithm is used for the Sieve of Eratosthenes
   *
   * Initialise primeArray with all numbers from 2 to 3500
   * Let p equal 2
   * do 
   *    for each multiple of p less than 3500
   *        remove multiple of p from primeArray (set element to -1)
   *    p = next element in primeArray > p 
   * until all elements > p are removed from primeArray 
   * now any element != -1 in primeArray is a prime number
   */
  
  int primeArray[LIMIT + 1];  // elements use indices from 0 to 3500
                              // to simplify operations this solutions
                              // uses indices 2 - 3500
  int p,index;
  int counter; // used for pausing output
  
  // Initialise primeArray with all numbers from 2 to 3500
  // (indices 0 and 1 are not used)
  primeArray[0] = -1;
  primeArray[1] = -1;
  for (index=2; index<=LIMIT; ++index)
    primeArray[index] = index;
  
  // Let p equal 2
  p = 2;
  do {
    // for each multiple of p less than 3500
    //    remove multiple of p from primeArray (set element to -1)
    for (int multiplier=2; multiplier<=(LIMIT)/p; ++multiplier){
      primeArray[multiplier*p] = -1;
    }
    // p = next element in primeArray > p, ie. find next element
    // in primeArray not -1
    for (index=p+1; index<=LIMIT; ++index) {
      if (primeArray[index] != -1) {
	// new p found
	p = primeArray[index];
	// terminate for loop
	break;
      }
      if (index == LIMIT)
	// no p found, set p > 3500
	p = LIMIT + 1;
    }
    // until all elements > p are removed from primeArray 
  } while (p<LIMIT);
  
  // output results
  counter = 0;
  for (index=2; index<=LIMIT; ++index) {
    if (primeArray[index] != -1) {
      printf("%i is prime\n", primeArray[index]);
      // increment counter
      ++counter;
    }
    // stop every 10 numbers
    if (counter == 10) {
      getchar();
      counter = 0;
    }
  }
  return 0;
}
