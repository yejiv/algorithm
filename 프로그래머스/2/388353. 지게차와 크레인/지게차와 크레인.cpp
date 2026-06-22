#include <string>
#include <vector>
#include <queue>

using namespace std;

void TakeOut_crane(vector<string>& storage, char target, int& answer)
{
    int height = storage.size();
    int width = storage[0].size();
    
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            if (target == storage[i][j])
            {
                -- answer;
                storage[i][j] = '0';
            }
        }
    }
}

void TakeOut_Forklift(vector<string>& storage, char target, int& answer)
{
    int height = storage.size();
    int width = storage[0].size();
    
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = { 0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    bool visit[52][52] = {};
    vector<pair<int, int>> e;
    
    q.push({0,0});
    visit[0][0] = true;
    
    while(!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        
        if (storage[cur_y][cur_x] != '0')
        {
            if (storage[cur_y][cur_x] == target)
                e.push_back({cur_y, cur_x});
            continue;
        }
            
        for(int k = 0; k < 4; ++k)
        {
            int nx = cur_x + dx[k];
            int ny = cur_y + dy[k];
            
            if (nx < 0 || ny < 0 || nx >= width || ny >= height || visit[ny][nx]) continue;
            
            visit[ny][nx] = true;
            q.push({ny, nx});
        }
    }
   
    for(const auto & p : e)
    {
        storage[p.first][p.second] = '0';
        --answer;
    }
}

void MakePadding(vector<string>& src, vector<string>& dst)
{
    string s = "";
    for(int i = 0; i < src[0].size() + 2; ++i)
        s += '0';
    
    dst.push_back(s);
    
    for(const string & old : src)
        dst.push_back("0" + old + "0");
    
    dst.push_back(s);
}

int solution(vector<string> storage, vector<string> requests) 
{
    int answer = storage.size() * storage[0].size();
    vector<string> s;
    
    MakePadding(storage, s);

    for(const auto & r : requests)
    {
        if (r.size() > 1)
            TakeOut_crane(s, r[0], answer);
        else
            TakeOut_Forklift(s, r[0], answer);
    }
    
    return answer;
}