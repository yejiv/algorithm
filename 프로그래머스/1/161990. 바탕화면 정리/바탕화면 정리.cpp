#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {-1, -1, -1, -1};
    int height = wallpaper.size(); 
    int weight = wallpaper[0].size(); 

    for(int i = 0; i < weight; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            if (answer[1] == -1 && wallpaper[j][i] == '#')
                answer[1] = i;
            if (answer[3] == -1 && wallpaper[j][weight - i - 1] == '#')
                answer[3] = weight - i;
        }
        if (answer[1] != -1 && answer[3] != -1)
            break;
    }
    
    for(int i = 0; i < height; ++i)
    {
        if (answer[0] == -1 && string::npos != wallpaper[i].find("#"))
            answer[0] = i;
        if (answer[2] == -1 && string::npos != wallpaper[height - i - 1].find("#"))
            answer[2] = height - i;
        if (answer[0] != -1 && answer[2] != -1)
            break;
    }
    
    return answer;
}