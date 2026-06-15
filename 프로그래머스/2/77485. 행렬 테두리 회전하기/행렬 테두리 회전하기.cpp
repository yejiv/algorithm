#include <string>
#include <vector>
#include <iostream>

using namespace std;

int rotate(vector<vector<int>>& table, const vector<int>& q)
{
    int tmp = table[q[0] - 1][q[1] - 1];
    int rt = tmp;
    
    for(int i = q[1]; i < q[3]; ++i)            //위
    {
        swap(tmp, table[q[0] - 1][i]);
        if (tmp < rt) rt = tmp;
    }

    for(int i = q[0]; i < q[2]; ++i)            //오른쪽
    {
        swap(tmp, table[i][q[3] - 1]);
        if (tmp < rt) rt = tmp;
    }
    
    for(int i = q[3] - 2; i + 1 >= q[1]; --i)   //아래
    {
        swap(tmp, table[q[2] - 1][i]);
        if (tmp < rt) rt = tmp;
    }
        
    for(int i = q[2] - 2; i + 1 >= q[0]; --i)   //왼쪽
    {
        swap(tmp, table[i][q[1] - 1]);
        if (tmp < rt) rt = tmp;
    }
    
    return rt;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> table(rows, vector<int>(columns));
    
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j)
            table[i][j] = i * columns + j + 1;
    
    for(const auto & q : queries)
        answer.push_back(rotate(table, q));
    
    return answer;
}