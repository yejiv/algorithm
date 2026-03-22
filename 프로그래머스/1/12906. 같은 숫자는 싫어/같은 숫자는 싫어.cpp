#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    if (arr.size())
        answer.push_back(arr[0]);
    
    for(auto& A : arr)
    {
        if (answer.back() == A)
            continue;
        answer.push_back(A);
    }

    return answer;
}