#include <string>
#include <vector>
using namespace std;

int solution(string name) {
    int answer = 0;
    
    int m[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int n = name.size();
    int move_min = n - 1;
    
    for(int i = 0; i < n; i++)
    {
        answer += m[name[i]-'A'];
        
        int t = i + 1;
        while( t < n && name[t] == 'A') t++;
        
        move_min = min(move_min, min(i + i + (n - t), i + (n - t) + (n - t)));
    }
    
    answer += move_min;
    
    return answer;
}