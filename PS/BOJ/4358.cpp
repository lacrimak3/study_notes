#include <iostream>
using namespace std;
const int TrieNode = 130;
char tree[10001][31];
int len, index[10001], cnt[10001];
struct Trie{
    Trie *nxt[TrieNode];
    bool finish;
    int idx;
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
            idx = len;
            finish = true;
            return;
        }
        int nxtKey = *key;
        if(!nxt[nxtKey]) nxt[nxtKey] = new Trie;
        nxt[nxtKey]->insert(key + 1);
    }
    int find(char *key){
        if(*key == 0){
            if(finish) return idx;
            else return -1;
        }
        int nxtKey = *key;
        if(!nxt[nxtKey]) return -1;
        return nxt[nxtKey]->find(key + 1);
    }
};

template <typename It>
void _swap(It &a, It &b){
    It c(a); a = b; b = c;
}

template <typename It, typename Comp>
void _sort(It begin, It end, Comp cmp){
    if(begin == end) return;
    _swap(*begin, *((end - begin) / 2 + begin));
    It pi = begin;
    It le = begin + 1;
    It ri = end - 1;
    while(le <= ri){
        while(le <= ri && cmp(*pi, *le)) le++;
        while(le <= ri && cmp(*ri, *pi)) ri--;
        if(le <= ri) _swap(*le, *ri);
    }
    _swap(*pi, *ri);
    _sort(begin, ri, cmp);
    _sort(ri + 1, end, cmp);
}

int _strcmp(const char *s1, const char *s2){
    while(*s1 && *s2){
        if(*s1 != *s2) return (*s1 < *s2) ? -1 : 1;
        s1++; s2++;
    }
    if(*s1 != *s2) return (*s1 < *s2) ? -1 : 1;
    return 0;
}

bool cmp(int a, int b){
    return _strcmp(tree[a], tree[b]) >= 0;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char s[31];
    Trie *root = new Trie;
    int cntTree = 0;
    int idx;
    while(cin.getline(s, 31)){
        cntTree++;
        if((idx = root->find(s)) != -1){
            cnt[idx]++;
        }
        else{
            root->insert(s);
            for(int i = 0; s[i] != 0; i++)
                tree[len][i] = s[i];
            index[len] = len;
            cnt[len]++;
            len++;
        }
    }
    _sort(index, index + len, cmp);
    cout << fixed;
    cout.precision(4);
    for(int i = 0; i < len; i++){
        idx = index[i];
        cout << tree[idx] << ' ' << 1.0 * cnt[idx] / cntTree * 100 << '\n';
    }
    delete root;
    return 0;
}