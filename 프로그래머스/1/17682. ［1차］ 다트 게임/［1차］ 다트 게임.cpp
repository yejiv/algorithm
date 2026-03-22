#include <string>
#include <vector>
#include <cmath>

using namespace std;


int GetNum(char A, char B);
void GetScore(int Score, char bonus);
void Option(char A);

vector<int> vScore;


int solution(string dartResult) {
    int answer = 0;
        int size = dartResult.size();
    
    for (int i = 0; i < size; ++i)
    {
        int num = GetNum(dartResult[i], dartResult[i + 1]);
    
        if (num == 10)
            ++ i;
    
        if (num >= 0)
            GetScore(num, dartResult[++i]);
        else
            Option(dartResult[i]);
    }
    
    for (auto& a : vScore)
        answer += a;
    
    return answer;
}


int GetNum(char A, char B) {

    if (A < '0' || A > '9')
        return -1;

    if ('0' == B)
        return 10;

    return A - 48;
}

void GetScore(int Score, char bonus)
{
    switch (bonus)
    {
    case 'S':
        vScore.push_back(Score);
        break;

    case 'D':
        vScore.push_back(pow(Score, 2));
        break;

    case 'T':
        vScore.push_back(pow(Score, 3));
        break;
    }
}

void Option(char A)
{
    int idx = vScore.size() - 1;

    switch (A)
    {
    case '*':
        vScore[idx] *= 2;
        if (idx != 0)
            vScore[idx - 1] *= 2;
        break;

    case '#':
        vScore[idx] *= -1;
        break;
    }
}

