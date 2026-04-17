#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int dist;
    
    for(int i = 0; i <= stations.size(); ++i)
    {
        if (i == 0)
            dist = stations[0] - w - 1;
        else if (i == stations.size())
            dist = n - stations.back() - w;
        else
            dist = stations[i] - stations[i - 1] - (w * 2) - 1;
        
        if (dist > 0) answer += (dist + w * 2) / (w * 2 + 1);
    }
    
    return answer;
}
