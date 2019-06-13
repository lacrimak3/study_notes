#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MOD = 1e7 + 7;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> mp;
    for(int i = 0; i < clothes.size(); i++){
        if(mp.count(clothes[i][1]) == 0) mp[clothes[i][1]] = 1;
        else mp[clothes[i][1]]++;
    }
    answer = 1;
    for(auto it : mp){
        answer *= it.second + 1;
    }
    answer -= 1;
    return answer;
}