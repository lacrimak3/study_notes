#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> ans;
    int n = genres.size();
    unordered_map<string, int> gm;
    unordered_map<string, vector<pair<int, int>>> gp;
    for(int i = 0; i < n; i++){
        string &s = genres[i];
        if(gm.count(s) == 0) gm[s] = -plays[i];
        else gm[s] -= plays[i];
        gp[s].push_back({-plays[i], i});
    }
    vector<pair<int, string>> a;
    for(auto it : gm)
        a.push_back({it.second, it.first});
    sort(a.begin(), a.end());
    for(auto it : a){
        sort(gp[it.second].begin(), gp[it.second].end());
        for(int i = 0; i < gp[it.second].size(); i++){
            ans.push_back(gp[it.second][i].second);
            if(i == 1) break;
        }
    }
    return ans;
}