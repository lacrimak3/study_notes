#include <iostream>
using namespace std;
const int TrieNode = 26;
struct Trie{
    Trie *nxt[TrieNode];
    bool finish;
    Trie(){
        for(int i = 0; i < TrieNode; i++) nxt[i] = 0;
        finish = false;
    }
    ~Trie(){
        for(int i = 0; i < TrieNode; i++)
            if(nxt[i]) delete nxt[i];
    }
    void insert(char *key){
        if(*key == 0){
            finish = true;
            return;
        }
        int nxtKey = *key - 'a';
        if(!nxt[nxtKey])
            nxt[nxtKey] = new Trie;
        nxt[nxtKey]->insert(key + 1);
    }
    bool find(char *key){
        if(*key == 0){
            if(finish) return true;
            else return false;
        }
        int nxtKey = *key - 'a';
        if(!nxt[nxtKey]) return false;
        return nxt[nxtKey]->find(key + 1);
    }
};
int n, m, ans;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    Trie *root = new Trie;
    for(int i = 0; i < n; i++){
        char t[501];
        cin >> t;
        root->insert(t);
    }
    for(int i = 0; i < m; i++){
        char t[501];
        cin >> t;
        if(root->find(t)) ans++;
    }
    cout << ans;
    delete root;
    return 0;
}