#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int s[24] = { 0 };
    int sum = 0;
    
    for(int i = 0; i < 24; ++i)
    {
        s[i] = max(players[i] / m - sum, 0);
        
        answer += s[i];
        sum += s[i];

        if (i >= k - 1) sum -= s[i - k + 1];
    }
    
    return answer;
}