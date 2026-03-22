#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    vector<int> table[10];
    int row = n / w + 1;
    int idx;
    int idxTable[100];
    int answer = 1;
    
    for(int i = 0 ; i < row; ++ i )
    {
        for(int j = 0 ; j < w; ++ j)
        {
            if (i * w + j + 1 > n)
                break;
            int CurIdx = (i % 2 == 0) ? j : w - j - 1;
            table[CurIdx].push_back(i * w + j + 1);
            idxTable[i * w + j] = CurIdx;
        }
    } 
    
    while(table[idxTable[num - 1]].back() > num)
    {
        table[idxTable[num - 1]].pop_back();
        ++answer; 
    }
    
    return answer;
}