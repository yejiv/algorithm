#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(true)
    {
        ++ answer;
        a = (a + 1) >> 1;
        b = (b + 1) >> 1;
        if (a == b)  break;
    }
    return answer;
}