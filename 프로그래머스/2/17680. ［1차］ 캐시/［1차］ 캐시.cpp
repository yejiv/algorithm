#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list <string> q(cacheSize);
    
    for(int i = 0; i < cities.size(); ++i)
    {
        for(int j = 0; j < cities[i].size(); ++j)
            cities[i][j] = toupper(cities[i][j]);
        
        auto it = find(q.begin(), q.end(), cities[i]);
        
        if (it == q.end())
            answer += 5;
        else
        {
            q.erase(it);
            ++ answer;
        }
        
        if (cacheSize) q.push_back(cities[i]);
        if (q.size() > cacheSize) q.pop_front();
    }
        
    return answer;
}