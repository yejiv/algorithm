#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> A(n + 1);
    
    for(int i = 2; i < n + 1; ++i)
        A[i] = i;

    for(int i = 2; i < n + 1; ++i)
    {
        if (A[i])
        {
            int mul = 2;
            while(A[i]  * mul <= n)
                A[i * mul++] = 0;
        }
    }
    
    for(int i = 2; i < n + 1; ++i)
        if (A[i])
            ++answer;
    
    return answer;
}