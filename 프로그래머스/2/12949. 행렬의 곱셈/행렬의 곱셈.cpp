#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int col = arr1.size();
    int row = arr2.size();
    vector<vector<int>> answer(col);

    for(int i = 0; i < col; ++ i)
    {
        vector<int> arr(arr2[0].size());
        for(int k = 0; k < arr2[0].size(); ++k )
        {
            int sum = 0;
            for(int j = 0; j < row; ++j) 
                sum += arr1[i][j] * arr2[j][k]; 
            arr[k] = sum;
        }
        answer[i] = arr;
    }
    
    return answer;
}