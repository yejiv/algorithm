#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> alpha(26);
    
    for(int i = 0; i < 26; ++ i)
        alpha[i] = 'a' + i;
    
    for(auto& A : skip)
        alpha.erase(find(alpha.begin(), alpha.end(), A));
    
    int size = alpha.size();
    
    for(auto& A : s)
    {
        int idx = (find(alpha.begin(), alpha.end(), A) - alpha.begin() + index) % size;
        answer += alpha[idx];
    }
    
    return answer;
}