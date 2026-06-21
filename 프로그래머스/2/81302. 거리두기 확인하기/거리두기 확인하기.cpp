#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isSafe(const vector<string>& place, int y, int x) 
{
    for (int ny = max(0, y - 2); ny <= min(4, y + 2); ++ny) 
    {
        for (int nx = max(0, x - 2); nx <= min(4, x + 2); ++nx)
        {
            if (ny == y && nx == x) continue; 
            if (place[ny][nx] != 'P') continue; 
            
            int dist = abs(ny - y) + abs(nx - x);
            
            if (dist > 2) continue; 

            if (dist == 1) return false; 
            
            if (ny == y) 
            { 
                if (place[y][(x + nx) / 2] != 'X') return false;
            } 
            else if (nx == x) 
            { 
                if (place[(y + ny) / 2][x] != 'X') return false;
            } 
            else 
            { 
                if (place[ny][x] != 'X' || place[y][nx] != 'X') return false;
            }
        }
    }
    return true;
}

int check(const vector<string>& place) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (place[i][j] == 'P') {
                if (!isSafe(place, i, j)) return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (const auto& place : places) {
        answer.push_back(check(place));
    }
    return answer;
}