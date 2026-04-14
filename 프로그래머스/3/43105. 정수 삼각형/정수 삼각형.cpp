#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i = 1; i < triangle.size(); ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            int left(0); int right(0);
            if (j > 0) left = triangle[i - 1][j - 1];
            if (j < triangle[i].size() - 1) right = triangle[i - 1][j];
            triangle[i][j] += max(left, right);
        }
    }
    
    return *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
}