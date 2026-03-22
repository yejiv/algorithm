#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int num) {

    char* answer = (char*)malloc(sizeof(char) * 5);
    
	(num % 2 == 0) ? strcpy(answer, "Even") : strcpy(answer, "Odd");
   
    return answer;
}