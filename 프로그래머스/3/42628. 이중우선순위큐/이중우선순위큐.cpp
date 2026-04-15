#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer {0, 0};
    multiset<int> s;
    int sum(0);
    
    for(auto &A : operations)
    {            
        if (A == "D 1")
        {
            if (sum) { s.erase(--s.end()); --sum; }
        }
        else if (A == "D -1")
        {
            if (sum) { s.erase(s.begin()); --sum; }
        }
        else
        {
            s.insert(stoi(A.substr(2))); 
            ++sum; 
        } 
    }
    
    if (sum) { answer[0] = *(--s.end()); answer[1] = *s.begin(); }
    
    return answer;
}