#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    long mul(brown + yellow);
    long sum ((brown + 4) / 2);
    int x(0), y(0);
    
    x = (sum + sqrt(sum * sum + (-4 * mul))) / 2;
    y = (sum - sqrt(sum * sum + (-4 * mul)))  / 2;
    
    vector<int> answer {x, y}; 
    
    if (answer[0] < answer[1]) swap(answer[0], answer[1]);
    
    return answer;
}