#include <vector>
#include <algorithm>
using namespace std;

int dp(const vector<int>& sticker)
{
    if (sticker.size() <= 3) return *max_element(sticker.begin(), sticker.end());
    
    vector<int> d(sticker.size());
    
    //0번째를 뽑는 경우
    d[0] = sticker[0];
    d[1] = sticker[0];
    
    for(int i = 2; i < sticker.size() - 1; ++i)
        d[i] = max(sticker[i] + d[i - 2], d[i - 1]);
    
    int ans1 = d[sticker.size() - 2];
    
    //0번째를 안 뽑는 경우
    d[0] = 0;
    d[1] = sticker[1];
    
    for(int i = 2; i < sticker.size(); ++i)
        d[i] = max(sticker[i] + d[i - 2], d[i - 1]);
    
    int ans2 = d[sticker.size() - 1];
    
    return max(ans1, ans2);
}

int solution(vector<int> sticker)
{
    int answer = 0;

    return dp(sticker);
}


