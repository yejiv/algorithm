#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start = 1;
    long long end = (long long)(*max_element(times.begin(), times.end())) * n;
    
    while(start <= end)
    {
        long long mid = (end + start) >> 1;
        long long acc = 0;
        
        for(const auto & A : times)
            acc += mid / (long long)A;
        
        if (acc < n)    //시간을 더 줘야함
            start = mid + 1;
        else            //시간을 더 줄여서 최적화
        {
            end = mid - 1;
            answer = mid;
        }
    }
    
    return answer;
}