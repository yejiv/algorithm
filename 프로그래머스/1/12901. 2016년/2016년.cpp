#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int day = 0;
    
    for(int i = 0; i < a; ++ i)
        day += month[i];
    
    return week[(5 + day + b - 1) % 7];
}