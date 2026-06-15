#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<long long> factorial;
    vector<int> arr;
    
    factorial.push_back(0);
    factorial.push_back(1);
    
    for(int i = 2; i < n; ++i)
        factorial.push_back(factorial[i - 1] * (i));
    
    for(int i = 0; i < n; ++i)
        arr.push_back(i + 1);

    --k;
    
    for(int i = 0; i < n - 1; ++i)
    {
        int idx = k / factorial[arr.size() - 1];
        answer.push_back(arr[idx]);
        k = k % factorial[arr.size() - 1];
        arr.erase(arr.begin() + idx);
    }
    
    answer.push_back(arr[0]);
    
    return answer;
}