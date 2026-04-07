#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    unordered_map <string, list<string>> bucket;
    int pos[2] = {0, 0};
    
    for(auto& A : dirs)
    {
        int prev_pos[2] = {pos[0], pos[1]};
        
        switch(A)
        {
        case 'U' : 
            if (pos[1] + 1 > 5) continue;
            ++pos[1]; break;
        case 'D' :
            if (pos[1] - 1 < -5) continue;
            --pos[1]; break;
        case 'R' :
            if (pos[0] + 1 > 5) continue;
            ++pos[0]; break;
        case 'L' :
            if (pos[0] - 1 < -5) continue;
            --pos[0]; break;
        }
                
        string s = to_string(prev_pos[0]) + to_string(prev_pos[1]);
        string e = to_string(pos[0]) + to_string(pos[1]);
        
        if (find(bucket[s].begin(), bucket[s].end(), e) != bucket[s].end()) continue;
        bucket[s].push_back(e);
        bucket[e].push_back(s);
        ++ answer;
    }
    
    return answer;
}