# DICTIONARY 고대어 사전
>https://algospot.com/judge/problem/read/DICTIONARY

## 문제
알파벳 소문자로 이루어진 고대어가 있다. 이 고대어 사전에 포함된 단어의 목록이 순서대로 주어질 때 이 언어에서 알파벳 순서를 계산하는 프로그램을 작성하시오. 알파벳들의 순서에 모순이 있다면 "INVALID HYPOTHESIS"를 출력한다.

## 입력
첫 줄에 테스트케이스의 개수 t (1 <= t <= 50)이 주어진다.  
각 테스트 케이스의 첫 줄에은 사전에 포함된 단어의 수 N (1 <= N <= 1000)이 주어진다. 그 후 N개의 줄에 사전에 포함된 단어가 순서대로 주어진다. 각 단어는 알파벳 소문자로 구성되어 있으며 길이는 20이하이다. 중복으로 출현하는 단어는 없다.

## 풀이
단어를 순서대로 두 개씩 비교해 순서를 그래프로 저장한다.  
예를 들어 ba와 aa라면 b와 a가 처음으로 다르므로 b -> a 간선이 존재하게 된다.  
그래프를 위상정렬해 출력한다. 사이클이 존재할 경우 "INVALID HYPOTHESIS"를 출력한다.  

```cpp
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> alpha[26];
        for (int i = 0; i < 26; ++i)
            alpha[i].clear();
        vector<string> a;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            a.push_back(s);
        }
        int ind[26] = { 0 };
        for (int i = 0; i < n - 1; ++i) {
            int len = (a[i].size() < a[i + 1].size() ? a[i].size() : a[i + 1].size());
            for (int j = 0; j < len; ++j) {
                if (a[i][j] != a[i + 1][j]) {
                    alpha[a[i][j] - 'a'].push_back(a[i + 1][j] - 'a');
                    ind[a[i + 1][j] - 'a']++;
                    break;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < 26; ++i)
            if (ind[i] == 0) q.push(i);
        vector<int> ans;
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            ans.push_back(c);
            for (int i : alpha[c]) {
                ind[i]--;
                if (ind[i] == 0) {
                    q.push(i);
                }
            }
        }
        if (ans.size() != 26)
            cout << "INVALID HYPOTHESIS";
        else {
            for (int i = 0; i < ans.size(); ++i)
                cout << char(ans[i] + 'a');
        }
        cout << '\n';
    }
    return 0;
}
```

Tags: `위상정렬`