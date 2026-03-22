#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> map;
    
    for(int i = 0; i < n; ++i)
        map.push_back(arr1[i] | arr2[i]);
    
    for(int low = 0; low < n;  ++low)
    {
        string newCol;
        
        for(int col = n - 1; col >= 0; --col)
        {
            if (map[low] & (int)pow(2, col))
                newCol += "#";
            else
                newCol += " "; 
        }
        
        answer.push_back(newCol);
    }
    
        
    return answer;
}