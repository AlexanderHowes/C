/*
Alexander Howes
820184866
'$' is multiplication. Healy knows and im sure youve seen a few by now, since many of
the operands like * and & are commands

first i defined true and false because i like using booleans, screw you c
using a list called stack and CURR as a marker for the top of the stack as global variables,
this program has a push and pop method.
then it reads in command line arguments testing for the +&-/ chars, if its not one of those
it pushs the number
if it is one of those it preforms the operation, and since we were told to assume valid input,
i didnt worry about putting in extra error messages.

ERROR CHECKING: if more than 100 numbers inputted, returns "max size"
if there is erronous input, returns the top number and alerts user there were unused numbers
and to please recheck input
*/
#include <stdio.h>  
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define true 1
#define false 0
int stack[100];
int curr = -1;
int pop(){
    int data;
    if(curr != -1){
        data = stack[curr];
        stack[curr] = 0;
        curr = curr-1;   
        return data;
    }
    else{
        return -1;
    }
}
int push(int data){
    if(curr < 100){
        curr = curr+1;
        stack[curr] = data;
        return 0;
    }
}
int main(int argc, char *argv[]) {
    int i, a, fir, sec, data, flag = false;
    if(argc == 1){
        printf("%s", "invalid input, please put arithmetic after ./a");
    }
    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"+")== 0){
            fir = pop();
            sec = pop();
            data = sec + fir;
            push(data);
            flag = true;
        }
        if(strcmp(argv[i],"-")== 0){
            fir = pop();
            sec = pop();
            data = sec - fir;
            push(data);
            flag = true;
        }
        if(strcmp(argv[i],"$")== 0){
            fir = pop();
            sec = pop();
            data = sec*fir;
            push(data);
            flag = true;
        }
        if(strcmp(argv[i],"/")== 0){
            fir = pop();
            sec = pop();
            data = sec/fir;
            push(data);
            flag = true;
        }
        if(flag == false){
            if(curr<100){
                a = atoi(argv[i]);
                push(a);
            }
            else{
                printf("%s", "max size");
                break;
            }
        }
        flag = false;
    }
    printf("%s", "result is: ");
    printf("%i", stack[curr]);
    if(curr>0){
      printf("\n%s", "There were unused numbers in calculation, please recheck input.");  
    }
return 0;
}