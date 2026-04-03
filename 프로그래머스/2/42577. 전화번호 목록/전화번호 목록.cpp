#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> bucket;
    
    for(auto& A : phone_book)
        bucket.insert(A);
    
    for(auto& A : phone_book)
    {
        string str = "";
        for(int i = 0; i < A.size() - 1; ++i)
        {
            str += A[i];
            if (bucket.find(str) != bucket.end()) return false; 
        }
    }
    
    return true;
}