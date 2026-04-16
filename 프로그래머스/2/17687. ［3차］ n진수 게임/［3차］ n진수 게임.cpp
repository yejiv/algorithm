#include <string>
#include <vector>

using namespace std;

string table = "0123456789ABCDEF";

string ToBase(int base, int num)
{
    string rt = "";
    
    while(num)
    {
        rt = table[num % base] + rt;
        num /= base;
    }
    
    return rt;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string number = "01";
    int num = 2;
    
    while(number.size() < (t - 1) * m + p) 
        number += ToBase(n, num++);
 
    for(int i = p - 1; answer.size() < t; i += m)
        answer += number[i];
    
    return answer;
}