#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int v[4];
    
    for(int i = 0; i < 4; ++i) v[i] = land[0][i];
    
    for(int i = 1; i < land.size(); ++i)
    {
        vector<pair<int, int>> sorted(4);
        
        for(int k = 0; k < 4; ++k) sorted[k] = { v[k], k};
        sort(sorted.begin(), sorted.end(), greater<>());
        
        for(int k = 0; k < 4; ++k) 
            v[k] = (sorted[0].second != k) ? land[i][k] + sorted[0].first : land[i][k] + sorted[1].first;
    }
    
    return *max_element(begin(v), end(v));
}