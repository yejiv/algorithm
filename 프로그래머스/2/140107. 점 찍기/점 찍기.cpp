#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (long long y = 0; y <= d; y += k) 
    {
        long long T = (long long)(d - y) * (d + y); 
        long long x = sqrt(T);
        answer += x / k + 1;
    }
    
    return answer;
}