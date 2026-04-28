#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(const auto & A : enemy)
    {
        n -= A;
        pq.push(A);
        
        if (n < 0)
        {
            if (k) { n += pq.top(); pq.pop(); --k; }
            else break;
        }
        
        ++ answer;
    }
    
    return answer;
}