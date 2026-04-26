#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<long long, long long> table;
    
    for(auto& A : weights) table[A] ++;
    
    for(auto& A : table)
    {
        if (A.second >= 2) 
            answer += (A.second * (A.second - 1)) >> 1;
        if (A.first % 2 == 0 && table.end() != table.find(A.first * 3 / 2))
            answer += A.second * table[A.first * 3 / 2];
        if (table.end() != table.find(A.first * 2))
            answer += A.second * table[A.first * 2];
        if (A.first % 3 == 0 && table.end() != table.find(A.first * 4 / 3))
            answer += A.second * table[A.first * 4 / 3];
    }
       
    return answer;
}