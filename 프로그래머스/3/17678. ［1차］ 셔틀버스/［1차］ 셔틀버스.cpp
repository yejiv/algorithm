#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> crews;
    crews.reserve(timetable.size());
    
    for (const string& time : timetable) 
        crews.push_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));
    
    sort(crews.begin(), crews.end());
    
    int idx = 0;
    int busTime = 0;
    int lastBoardingTime = 0;
    int boarded = 0;
    
    for (int i = 0; i < n; ++i) 
    {
        busTime = 540 + i * t; 
        boarded = 0;
        
        while (boarded < m && idx < crews.size() && crews[idx] <= busTime) 
        {
            lastBoardingTime = crews[idx];
            idx++;
            boarded++;
        }
    }
    
    int conTime = (boarded < m) ? busTime : lastBoardingTime - 1;
    
    string h_str = "0" + to_string(conTime / 60);
    string m_str = "0" + to_string(conTime % 60);
    
    return h_str.substr(h_str.length() - 2) + ":" + m_str.substr(m_str.length() - 2);
}