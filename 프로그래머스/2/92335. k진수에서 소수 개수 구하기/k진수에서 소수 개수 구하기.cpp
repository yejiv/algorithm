#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long N, int k)
{
    int i = 1;
    
    if (N < 2) return false;
    
    while(++i <= sqrt(N))
    {
        if (N % i == 0) return false;
    }
    
    return true;
}

long long solution(int n, int k) {
    int answer = 0;
    string s = "";
    
    for(int i = 0; n > 0; ++i)
    {
        s = to_string(n % k) + s;
        n /= k;
    }

    long long curNum = 0;
    
    for(auto& c : s)
    {
        if (c == '0')
        {
            if (isPrime(curNum, k)) ++answer;
            curNum = 0;
        }
        else curNum = (curNum * 10) + (c - '0');
    }
    
    if (curNum && isPrime(curNum, k)) ++answer;

    return answer;
}