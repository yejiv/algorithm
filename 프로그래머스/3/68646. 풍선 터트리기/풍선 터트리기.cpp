#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> a) {
    int answer = 1;
    int min_left = a[0];
    vector<int> min_right(a.size());
    
    if (a.size() == 1) return answer;
    
    int min_element = a.back();
    for(int i = a.size() - 1; i >= 0; --i)
    {        
        min_right[i] = min_element;

        if (min_element > a[i])
            min_element = a[i];
    }
    
    for(int i = 0; i < a.size() - 1; ++i)
    {
        if (a[i] <= min_left || a[i] <= min_right[i])
            ++ answer;
        
        if (a[i] < min_left)
            min_left = a[i];
    }
    
    return answer;
}