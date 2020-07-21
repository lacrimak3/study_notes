#include <bits/stdc++.h>
using namespace std;

const int TrieNode = 26;
struct Trie {
    Trie* nxt[TrieNode];
    bool finish;
    int cnt;
    Trie() {
        for (int i = 0; i < TrieNode; i++) nxt[i] = 0;
        finish = false;
        cnt = 0;
    }
    ~Trie() {
        for (int i = 0; i < TrieNode; i++)
            if (nxt[i]) delete nxt[i];
    }
    void insert(char* key) {
        if (*key == 0) {
            cnt++;
            finish = true;
            return;
        }
        int nxtKey = *key - 'a';
        if (!nxt[nxtKey])
            nxt[nxtKey] = new Trie;
        cnt++;
        nxt[nxtKey]->insert(key + 1);
    }

    Trie* find(const char* key) {
        if (*key == 0) return this;
        int nxtKey = *key - 'a';
        if (!nxt[nxtKey]) return 0;
        return nxt[nxtKey]->find(key + 1);
    }
};
const int MOD = 1e9 + 7;
int n;
string s;
int d[200001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Trie* root = new Trie;
    for (int i = 0; i < n; i++) {
        char t[301];
        cin >> t;
        int p = 1;
        root->insert(t);
    }
    cin >> s;
    s = ' ' + s;
    d[0] = 1;
    deque<Trie*> q;
    for (int i = 1; i < s.length(); i++) {
        if (q.size() >= 300) q.pop_back();
        char t[2];
        t[0] = s[i];
        t[1] = 0;
        Trie* tmp = root->find(t);
        q.push_front(tmp);
        if (tmp != 0)
            d[i] = (d[i] + 1LL * d[i - 1] * tmp->cnt) % MOD;

        for (int j = 1; j < q.size(); j++) {
            tmp = q[j];
            if (!tmp) continue;
            tmp = tmp->find(t);
            q[j] = tmp;
            if (tmp != 0 && d[i - j - 1])
                d[i] = (d[i] + 1LL * d[i - j - 1] * tmp->cnt) % MOD;
        }
    }
    cout << d[s.length() - 1];
    return 0;
}