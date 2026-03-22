#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int lenth = strlen(s);
    char* answer = (char*)malloc(sizeof(char) * (lenth) + 1);
    strcpy(answer, s);
    int tmp = 0;
    
    for(int i = 0; i < lenth; ++i)
    {
        if (answer[i] >= 'A' && answer[i] <= 'Z' && tmp % 2 == 1)
            answer[i] += 'a' - 'A';
        else if (answer[i] >= 'a' && answer[i] <= 'z' && tmp % 2 == 0)
            answer[i] -= 'a' - 'A';
        
        ++tmp;
        
        if(answer[i] == ' ')
            tmp = 0;
    }
        
    return answer;
}