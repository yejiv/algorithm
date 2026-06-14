#include <string>
#include <vector>
using namespace std;

string token(const string& origin)
{
    string rt = "";
    
    for(int i = 0; i < origin.size(); ++i)
    {
        if (origin[i] == '#')
            rt[rt.size() - 1] = tolower(rt.back());
        else
            rt += origin[i];
    }
    
    return rt;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int answer_length = 0;
    
    m = token(m);
    
    for(const auto & music : musicinfos)
    {
        int startHour = stoi(music.substr(0, 2));
        int startMinute = stoi(music.substr(3, 2));
        int endHour = stoi(music.substr(6, 2));
        int endMinute = stoi(music.substr(9, 2));
        int length = (endHour * 60 + endMinute) - (startHour * 60 + startMinute);
        
        size_t comma = music.rfind(",");
        string keynote = token(music.substr(comma + 1));
        
        string played_melody = "";
        for (int i = 0; i < length; ++i)
            played_melody += keynote[i % keynote.size()];
        
        if (played_melody.find(m) != string::npos && answer_length < length)
        {
            answer = music.substr(12, comma - 12);
            answer_length = length;
        }
    }
    
    return answer;
}