#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> table(n + 1);

    table[0] = 1;
    table[1] = 1;
    
    for(int i = 2; i < n + 1; ++i)
        table[i] = (table[i - 2] + table[i - 1]) % 1234567;
    
    return table[n];
}