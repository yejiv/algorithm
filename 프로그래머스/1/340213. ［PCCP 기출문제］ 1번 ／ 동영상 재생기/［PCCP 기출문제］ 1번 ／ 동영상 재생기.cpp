#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int pos_second(0), video_len_second(0), op_second[2];
    
    pos_second = (stoi(pos)) * 60 + (stoi(pos.data() + 3));
    video_len_second = (stoi(video_len)) * 60 + (stoi(video_len.data() + 3));
    op_second[0] = (stoi(op_start)) * 60 + (stoi(op_start.data() + 3));
    op_second[1] = (stoi(op_end)) * 60 + (stoi(op_end.data() + 3));
    
    if (pos_second >= op_second[0] && pos_second <= op_second[1])
            pos_second = op_second[1];
    
    for(auto& com : commands)
    {
        if (com == "prev")
        {
            pos_second -= 10;
            if (pos_second < 0) pos_second = 0;
        }
        else if (com == "next")
        {
            pos_second += 10;
            if (pos_second > video_len_second) pos_second = video_len_second;
        }
        if (pos_second >= op_second[0] && pos_second <= op_second[1])
            pos_second = op_second[1];
    }
    
    if (pos_second / 60 < 10) answer += '0';
    answer += to_string(pos_second / 60) + ":";
    if (pos_second % 60 < 10) answer += '0';
    answer += to_string(pos_second % 60);
    
    return answer;
}