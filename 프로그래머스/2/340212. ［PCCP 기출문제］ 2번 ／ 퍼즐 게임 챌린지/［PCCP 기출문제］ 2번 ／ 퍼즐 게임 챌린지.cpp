#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long getElapsedTime(int level, vector<int>& diffs, vector<int>& times)
{
    long long ElapsedTime = 0;
    
    for(int i = 0; i < diffs.size(); ++ i)
    {
        if (level >= diffs[i])
            ElapsedTime += times[i];
        else
        {
            int time_prev = (i != 0) ? times[i - 1] : 0;
            ElapsedTime += (long long)(times[i] + time_prev) * (long long)(diffs[i] - level) + (long long)times[i];
        }
    }
    return ElapsedTime;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int start = 1;
    int end = *max_element(diffs.begin(), diffs.end());
    
    while(start < end)
    {
        int mid = start + ((end - start) >> 1);
        
        long long ElapsedTime = getElapsedTime(mid, diffs, times);
        
        if (ElapsedTime <= limit)   //만족함
            end = mid;
        else                        //만족하지 않음
            start = mid + 1;
    }
    
    return start;
}