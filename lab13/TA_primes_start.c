#include <stdio.h>
#include <time.h>
#include <math.h>  // don't forget to compile with -lm
#include <stdlib.h>
#include <string.h> // for memset
/* clock information from here: https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/#:~:text=1%20Using%20time%20%28%29%20function%20in%20C%20%26,C%2B%2B.%20...%205%20Using%20chrono%3A%3Ahigh_resolution_clock%20in%20C%2B%2B.%20
*/
//int k = (int)sqrt(x) + 1;


/* checks if x is prime, if so, returns 1, otherwise returns 0 */
int isItPrime(int x){
    int j;
    int isPrime = 1;
        
        for(j=2; j<x; j++){
            if(x%j == 0){
                /* it's not prime */
                isPrime = 0;
                break;
            }
        }
        if(isPrime){            /* could just be 'return isPrime;'   */
            return 1;
        } else {
            return 0;
        }
} // end isItPrime

void print_primes(int n){
    int i;
    int count = 0;
    printf("The primes under %d are: ", n);
    for(i = 2; i <= n; i++){
        if(isItPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nThe total number of primes found is: %d", count);
    return;
}  // end print_primes



void print_primesb(int n){
    int i;
    int j;
    int isPrime = 1;
    int count = 0;
    printf("The primes under %d are: ", n);
    for(i = 3; i <=n; i = i + 2){
        int k = (int)sqrt(i) + 1; // need to round up?
        for(j=2; j<k; j++){
            if(i%j == 0){
                /* it's not prime */
                isPrime = 0;
                break;
            }
        }
        if(isPrime){
            printf("%d ", i);
            count++;
        } else {
            isPrime = 1;  // reset
        }
    }
    printf("\nThe total number of primes found is: %d", count);
    return;
}  // end print_primesb


void print_primes_sieveE(int n){
    // Sieve of Erasthosthenes
    //bool allPrimes[n + 1]; // an array of bits to hold the answers
    int *allPrimes = malloc(sizeof(int)*(n+1));
    //memset(allPrimes, 1, sizeof(n+1)); // set all bits to 1 (true)
    int count = 0;

    int p;
    allPrimes[0] = 0;
    allPrimes[1] = 0;
    // set all bits to 1
    for(p=2; p < n; p++){
        allPrimes[p] = 1;
    }


    for(p=2; p*p <=n; p++){
        // if p is a prime, mark all multiples of p as non-primes
        //printf("%d, %d\n", p, allPrimes[p]);
        if(allPrimes[p] == 1){
            int i;
            for(i = p*p; i<=n; i+=p){
                allPrimes[i] = 0;
            }
        }

    }

    // print them all
    printf("The primes under %d are: ", n);
    printf("2 ");
    for(p=2; p<=n; p++){
        if(allPrimes[p] == 1){
            printf("%d ", p);
            count++;
        }
    }
    printf("\n");
    printf("\nThe total number of primes found is: %d\n", count);

    return;
}


int main(int argc, char *argv[]){
    // variables for timing
    time_t start;
    time_t end;

    // for the clock
    clock_t c_start = clock();  // start clock
    clock_t c_stop;
    clock_t diff;

    // start the clock timer
    time(&start); /* can also use start = time(NULL) */

    // ==============================
    // ====== set these =======
    int n = 100000;    // find all the primes from 1 to n

    // call the function
    print_primes(n);  // don't try this for n = 1,000,000
    //print_primesb(n);
    //print_primes_sieveE(n);
    // =============================

    // stop the clock
    time(&end);
    c_stop = clock();
    diff = c_stop - c_start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;

    // calc the total time and print
    double time_taken = (end - start);
    printf("\nReal time taken is approx: %.5f sec\n", time_taken);
    printf("CPU time taken is: %d sec %d msec\n", msec/1000, msec%1000);

    return 0;
}

/*
this is for part 2 of the performance optimization discussion.
I'll typically run each of the following, recording the time.
    -- to set the number of primes, see line 132
    -- to change the function being run, see lines 135-137
- a. baseline (as-is) for 100K primes
    -- I'll run 100K primes until the times get so small, then switch to 1M primes
- b. then I'll compile with -O3 and check the time [making the compiler do the work is easy]
    -- note: after this one time I do not turn on optimization so I can get a good comparison across the different code modifications
- c. n/2.  Modify line 16 to 'j <= x/2'
    -- talk about how important the algorithm is to the time.
    -- And why we don't need to check every number up to x to see if it is a factor,
        since the largest factor can't be any bigger than n/2
- d. sqrt(n).  Modfify line 16 to 'j <= sqrt(x)'
    -- because the smallest factor can't be any larger than the sqrt(n), 
        and we only need to find one factor, the first or smallest factor,
        to prove the number is not prime
[this begins the items we discussed in class]
- e. Swap a costly instruction for a less costly instruction. 
    -- In line 16, instead of j <= sqrt(x), change to 'j * j <= x'
    -- here we swap sqrt, which is costly for * (multiplication), which is much less costly
- f. Code Movement.  if we don't need something inside a loop, move it out
    -- Add line 15: int k = (int)sqrt(x) + 1;   [not sure we need the +1, just accounting for rounding]
    -- and modify line 16 to 'j <= k'
    -- in this case, the value of the sqrt(x) will never change, let's calculate that once
    -- a very common item in other code:  for... x < len(myString), or x < myArraySize,
        these are items we can move outside the loop, they only waste calculation time each time through the loop
- g. Reduce Functions
    -- each time a function is called, a stack frame has to be created, variables need to be copied, it all has to be undone on 'return'
    -- this may make your code less modular, less readable, which is a trade-off, 
        but might help if you're trying to squeeze the last few nanoseconds of performance from your code
    -- Comment line 135, uncomment line 136 [the two functions were combined into one function with print_primesb()]
- h. But the algorithm is key.  Sieve of Erasthothenes
    -- comment line 136, uncomment line 137
    -- I will run at 1M, then also try 10M primes (line 132)
*/

/*
Timing information
print_primes(n);  // don't try this for n = 1,000,000
    brute force
    100K | 9592 primes | 1 sec | 1.5
print_primes2(n);
    add i/2
    100K | 9593 primes | 1 sec | 0.734      (one extra prime? see line 49?)
print_primes3(n);
    add sqrt(i)
    100K | 9592 primes | 0 sec | 0.0
    1M | 78498 primes | 0 sec | 0.234
    10M | 664579 primes | 8 sec | 5.609
print_primes4(n);
    don't check even #s
    100K | 9591 primes | 1 sec | 1.171      (one less prime? fixed)
print_primes5(n);
    add sqrt(i), don't check even
    1M | 78497 primes | 1 sec | .281        (one less prime? fixed)
    10M | 664578 primes | 8 sec | 6.437     (one less prime? fixed)
print_primes_sieveE(n);
    Sieve of E
    10M | 664579 primes | 2 sec | 343 msec

*/