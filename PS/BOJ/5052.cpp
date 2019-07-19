#include <iostream>
using namespace std;

const int TrieNode = 10;
struct Trie{
    Trie *nxt[TrieNode];
    bool finish;
    bool nxtChild;
    Trie(){
        for(int i = 0; i < TrieNode; i++) nxt[i] = 0;
        finish = nxtChild = false;
    }
    ~Trie(){
        for(int i = 0; i < TrieNode; i++){
            if(nxt[i]) delete nxt[i];
        }
    }
    bool insert(char *key){
        if(*key == '\0'){
            finish = true;
            if(nxtChild) return 0;
            else return 1;
        }
        int nxtKey = *key - '0';
        if(!nxt[nxtKey])
            nxt[nxtKey] = new Trie;
        nxtChild = true;
        bool ok = nxt[nxtKey]->insert(key + 1);
        return !finish && ok;
    }
};
const int N = 10001;
int T;
int n;
char a[11];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        Trie *root = new Trie;
        bool ok = true;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a;
            if(ok && root->insert(a) == 0) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        delete root;
    }
    return 0;
}