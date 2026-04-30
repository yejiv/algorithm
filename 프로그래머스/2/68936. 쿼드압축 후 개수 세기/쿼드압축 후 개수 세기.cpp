#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer = {0 , 0};

void f(vector<vector<int>>& arr, int i, int j, int size)
{
    int num = arr[i][j];
    bool check = true;

    for(int m = 0; m < size; ++m)
    {
        for(int n = 0; n < size; ++n)
        {
            if (arr[i + m][j + n] != num) { check = false; break; }
        }
    }
    
    if (check) { ++ answer[num]; return; }
    
    size /= 2; 
    
    f(arr, i, j, size);
    f(arr, i + size, j, size);
    f(arr, i, j + size, size);
    f(arr, i + size, j + size, size);
}

vector<int> solution(vector<vector<int>> arr) {
    
    f(arr, 0, 0, arr.size());
    
    return answer;
}