#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MOD = 1e7 + 7;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> mp;
    for(int i = 0; i < phone_book.size(); i++){
        string s = "";
        for(int j = 0; j < phone_book[i].size(); j++){
            s += phone_book[i][j];
            if(mp.count(s) == 0) mp[s] = 1;
            else mp[s]++;
        }
    }
    for(int i = 0; i < phone_book.size(); i++){
        if(mp[phone_book[i]] > 1){
            answer = false;
            break;
        }
    }
    return answer;
}