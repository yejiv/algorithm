#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& A, string& B)
{
    return A + B > B + A;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> table(numbers.size());
    
    for(int i = 0; i < numbers.size(); ++i)
        table[i] = to_string(numbers[i]);
    
    sort(table.begin(), table.end(), cmp);
    
    for(auto& A : table) answer += A;
    
    if (answer[0] == '0') return "0";
    
    return answer;
}
                