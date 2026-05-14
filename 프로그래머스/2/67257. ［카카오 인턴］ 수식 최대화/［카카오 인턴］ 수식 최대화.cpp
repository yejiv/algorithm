#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<long long> g_num;
string g_operator;

long long c(const char c, const long long num1, const long long num2)
{
    if      (c == '+') return num1 + num2;
    else if (c == '-') return num1 - num2;
    else if (c == '*') return num1 * num2;
}

long long f(const string order)
{
    vector<long long> table1 = g_num;
    vector<long long> table2;
    string op = g_operator;
    
    for(const auto & A : order)
    {        
        for(int i = 0; i < op.size(); ++i)
        {
            if (op[i] != A)
                table2.push_back(table1[i]);
            else
                table1[i + 1] = c(A, table1[i], table1[i + 1]);
        }
        
        table2.push_back(table1.back());
        op.erase(remove(op.begin(), op.end(), A), op.end());
        table1 = move(table2);
        table2.clear();
    }
    
    return abs(table1[0]);
}

long long solution(string expression) {
    long long answer = 0;
    
    int idx = -1;
    string s;
    while(++idx < expression.size())
    {
        if(!isdigit(expression[idx]))
        {
            g_operator.push_back(expression[idx]);
            g_num.push_back(stoi(s));
            s = "";
        }
        else
            s.push_back(expression[idx]);
    }
    
    g_num.push_back(stoi(s));

    s = g_operator;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    do{
            answer = max(f(s), answer);
    }while(next_permutation(s.begin(), s.end()));
    
    return answer;
}
