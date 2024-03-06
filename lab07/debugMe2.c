#include<stdio.h>
#include<stdarg.h>  // for variatic function
#include<unistd.h>  // for sleep
#include<stdlib.h> // for atoi
#include "debugMe.h"

#define TRUE 1
#define FALSE 0



/*
This function is a variadic (takes various numbers of arguments)
  helper function to print the countdown
arguments: int the number of arguments, and int(s) to print
return: nothing
For more on variadic functions:     https://en.cppreference.com/w/c/variadic
                                    https://linux.die.net/man/3/va_arg
*/
void countdown(int num_args, ... ){
    va_list args;
    va_start(args, num_args);

    int i;
    for(i = 0; i < num_args; i++){
        int value = va_arg(args, int);
        printf("\n\t\t\t%d", value);
        sleep(1);
    }
    printf("\n");
    
    va_end(args);

    return;
} // end countdown




int main(int argc, char **argv){

    // start the countdown process
    countdown(3, 3, 2, 1);
    

    return 0;
}
