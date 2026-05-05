#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1;
    long long right = (long long)(*max_element(times.begin(), times.end())) * n;
    
    while(left <= right)
    {
        long long mid = (left + right) >> 1;
        long long p = 0;
        
        for(const auto & A : times)
            p += mid / (long long)A;
        
        if (p < n)
            left = mid + 1;
        else
        {
            answer = mid;
            right = mid - 1;
        }
    }
    
    return answer;
}