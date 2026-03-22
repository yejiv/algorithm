#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string s = "";
    int size = food.size();
    
    for (int i = 1; i < size; ++i) 
        for (int j = 0; j < food[i] / 2 ; ++ j) 
            s +=  to_string(i);
    
    answer = s;
    reverse(s.begin(), s.end());
    answer += '0' + s;

    return answer;
}