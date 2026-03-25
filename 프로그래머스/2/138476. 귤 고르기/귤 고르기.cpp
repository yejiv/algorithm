#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> num;
    
    sort(tangerine.begin(), tangerine.end());
    
    int cnt = 1; 
    for(int i = 0; i < tangerine.size() - 1; ++i)
    {
        if (tangerine[i] == tangerine[i + 1])
            ++ cnt;
        else
        {
            num.push_back(cnt);
            cnt = 1;
        }
    }
    num.push_back(cnt);
    
    sort(num.begin(), num.end(), greater<>());
     
    int sum = 0;
    for(int i = 0; i < num.size(); ++ i)
    {
        sum += num[i];
        ++ answer;
        if (sum >= k)
            break;
    }
    
    return answer;
}