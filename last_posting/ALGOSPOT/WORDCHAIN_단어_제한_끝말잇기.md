# WORDCHAIN 단어 제한 끝말잇기
>https://algospot.com/judge/problem/read/WORDCHAIN

## 문제
단어 제한 끝말잇기는 일반적인 끝말잇기와 달리 사용할 수 있는 단어가 제한적이다. 사용할 수 있는 단어들의 목록이 주어질 때, 단어들을 전부 사용하고 게임을 끝낼 수 있는지, 그럴 수 있다면 어떤 순서로 단어를 사용해야 하는지를 계산하는 프로그램을 작성하시오. 단어를 전부 사용할 수 없다면 "IMPOSSIBLE"을 출력한다.  

## 입력
첫 줄에 테스트케이스의 개수 T (1 <= T <= 50)이 주어진다. 각 테스트 케이스의 첫 줄에는 사용할 수 있는 단어의 수 N (1 <= N <= 100)이 주어지고 그 다음 N개의 줄에 단어가 주어진다. 각 단어는 알파벳 소문자로 구성되어 있으며, 길이는 2 이상 10 이하이다. 중복으로 출현하는 단어는 없다.

## 풀이
각 단어를 간선으로하는 그래프에서 오일러 서킷 또는 오일러 트레일이 존재하는지 여부를 확인하면 된다.  
예를 들어 dog라는 단어는 d에서 g로 가는 간선을 나타내는 것이다.  

오일러 서킷은 모든 정점의 outdegree와 indegree가 같을 때 존재한다. 오일러 트레일은 outdegree가 indegree보다 하나 큰 정점에서 오일러 서킷과 동일한 방법으로 찾을 수 있다.  
오일러 서킷/트레일이 존재한다면 사용 순서대로 단어를 출력한다.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int n;
vector<string> g[26][26];
vector<vector<int > > adj;
vector<int> outdegree, indegree;

void getEulerCircuit(int here, vector<int>& circuit);
vector<int> getEulerTrailOrCircuit();
bool checkEuler();

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        adj = vector<vector<int> >(26, vector<int>(26, 0));
        indegree = outdegree = vector<int>(26, 0);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                g[i][j].clear();
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int a = s[0] - 'a', b = s[s.size() - 1] - 'a';
            g[a][b].push_back(s);
            adj[a][b]++;
            outdegree[a]++;
            indegree[b]++;
        }

        if (!checkEuler()) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        vector<int> circuit = getEulerTrailOrCircuit();
        if (circuit.size() != n + 1) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        reverse(circuit.begin(), circuit.end());
        string p;
        for (int i = 1; i < circuit.size(); ++i) {
            int a = circuit[i - 1], b = circuit[i];
            if (p.size()) p += " ";
            p += g[a][b].back();
            g[a][b].pop_back();
        }
        cout << p << '\n';
    }
    return 0;
}

void getEulerCircuit(int here, vector<int>& circuit) {
    for (int there = 0; there < adj[here].size(); ++there) {
        while (adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}
vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;
    for (int i = 0; i < 26; ++i) {
        if (outdegree[i] == indegree[i] + 1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    for(int i=0; i<26; ++i)
        if (outdegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    return circuit;
}

bool checkEuler() {
    int plus1 = 0, minus1 = 0;
    for (int i = 0; i < 26; ++i) {
        int delta = outdegree[i] - indegree[i];
        if (delta < -1 || delta > 1) return false;
        if (delta == 1) plus1++;
        if (delta == -1) minus1++;
    }
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}
```

Tags: `오일러`, `dfs`, `다시 풀어볼 문제`