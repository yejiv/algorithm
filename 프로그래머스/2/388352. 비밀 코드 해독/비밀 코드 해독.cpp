#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    int m = 5;
    
    vector<int> p(n, 0);
    fill(p.end() - m, p.end(), 1);

    do {
        bool flag = true;
        
        for(int i = 0; i < q.size(); ++i)
        {
            int count = 0;
            
            for(int j = 0; j < q[i].size(); ++j)
            {
                if (p[q[i][j] - 1] == 1)
                    ++count;
            }
            
            if (count != ans[i]) 
            {
                flag = false;
                break;
            }
        }
        
        if (flag) ++answer; 
        
    } while (next_permutation(p.begin(), p.end()));
    
    return answer;
}