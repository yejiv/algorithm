#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    string blocked = message;
    
    for(auto& A : spoiler_ranges)
        for(int i = A[0] ; i <= A[1]; ++i)
            if (message[i] != ' ')
                blocked[i] = '*';
    
    vector<string> orig_words;
    vector<string> blocked_words;
    stringstream ss_orig(message);
    stringstream ss_blocked(blocked);
    string temp;
    
    while (ss_orig >> temp) orig_words.push_back(temp);
    while (ss_blocked >> temp) blocked_words.push_back(temp);
    
    unordered_set<string> unspoiled_set;
    
    for (int i = 0; i < blocked_words.size(); ++i)
        if (blocked_words[i].find('*') == string::npos)
            unspoiled_set.insert(orig_words[i]);
    
    unordered_set<string> read_words;
    
    for (int i = 0; i < orig_words.size(); ++i) 
    {
        string cur_orig = orig_words[i];
        string cur_blocked = blocked_words[i];
        
        bool is_spoiled = (cur_blocked.find('*') != string::npos);
        
        if (is_spoiled)
        {
            if (read_words.find(cur_orig) == read_words.end() && unspoiled_set.find(cur_orig) == unspoiled_set.end()) 
                ++answer;
        }
        read_words.insert(cur_orig);
    }
    
    return answer;
}