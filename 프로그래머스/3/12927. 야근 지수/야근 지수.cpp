#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    sort(works.begin(), works.end(), greater<>());
    
    while(n)
    {
        int i = 0;
        int curnum = works[i];
        
        if (curnum == 0) break;;
        
        while(n && curnum == works[i]) 
        {
            -- works[i ++];  -- n;
        }
    }
    
    for(int i = 0; i < works.size(); ++i)
        answer += pow(works[i], 2);
   
    return answer;
}