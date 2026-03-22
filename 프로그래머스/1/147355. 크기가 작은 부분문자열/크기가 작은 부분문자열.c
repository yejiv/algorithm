#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    int T_lenth = strlen(t);
    int P_lenth = strlen(p);
    int lenth = T_lenth - P_lenth;
        
    for(int i = 0; i < lenth + 1; ++i)
    {
        for(int j = 0; j < P_lenth; ++j)
        {
            if (t[i + j] > p[j])
                break;
            
            if (t[i + j] < p[j] || ((j + 1 == P_lenth) && (t[i + j] == p[j])))
            {
                ++ answer;
                break;
            }
        }
    }
    
    return answer;
}