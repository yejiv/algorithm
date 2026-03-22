#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int max = 1;
    int row = park.size();
    int col = park[0].size();
    
    sort(mats.begin(), mats.end());
    
    for(int i = 0; i < row; ++ i)
    {
        for(int j = 0; j < col; ++ j)
        {
            if ("-1" != (park[i][j]))
                continue;
            
            int size = 1;
            
            while(j + size < col && i + size < row)
            {
                bool flag = false;
                
                for(int k = 0; k < size + 1; ++ k)
                {
                    if (("-1" != park[i + k][j + size]) || ("-1" != park[i + size][j + k]))
                    {
                        flag = true; break;
                    }
                }
                
                if (flag)
                    break;
                
                if (size >= mats.back())
                    return size;
                
                 ++size;
            }
            if (size > max)
                max = size;
        }
    }
    
    for(int i = 0; i < mats.size() - 1; ++i)
        if (mats[i] <= max && mats[i + 1] > max)
            return mats[i];
    
    return -1;
}