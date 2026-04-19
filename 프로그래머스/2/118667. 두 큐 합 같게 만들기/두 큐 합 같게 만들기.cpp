#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long goal = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    
    for(auto &A : queue1)   sum1 += A;
    for(auto &A : queue2)   sum2 += A;
    
    if ((sum1 + sum2) % 2) return -1;
    
    goal = (sum1 + sum2) >> 1;

    int idx1 = 0;
    int idx2 = queue1.size();
    
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());

    while(idx2 < queue1.size())
    {
        if (sum1 > goal) sum1 -= queue1[idx1++];
        else if (sum1 < goal) sum1 += queue1[idx2++];
        else return answer;

        ++ answer;
    }
    
    return -1;
}