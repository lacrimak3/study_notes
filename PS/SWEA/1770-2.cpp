#define MAX 30000
#define MOVE(n, from, to) (((n >> from) & 3) << to)
 
struct block{
    int base;
    int depth;
    unsigned int key, op_key;
    block(): base(0), depth(0), key(0){}
    bool operator<(const block &other) const{
        return base < other.base;
    }
};
 
 
block _data[MAX];
unsigned int keyTable[MAX], keyCnt;
 
struct _vector{
    int a[40], len;
    bool init;
    _vector(): len(0), init(0){}
    int back(){
        if(!init){
            init = true;
            for(int i = 1, j; i < len; ++i){
                int key = a[i];
                for(j = i - 1; j >= 0 && _data[key] < _data[a[j]]; --j) a[j + 1] = a[j];
                a[j + 1] = key;
            }
        }
        return a[len - 1]; 
    }
    void push_back(int n){
        a[len++] = n;
    }
    void pop_back(){
        len--;
    }
    int size(){
        return len;
    }
    int operator[](int idx) const{
        return a[idx];
    }
    void clear(){
        len = 0;
        init = 0;
    }
    bool empty(){
        return len == 0;
    }
};
 
template <typename It>
void _swap(It &a, It &b){
    It c(a); a = b; b = c;
}
 
template <typename It>
void _sort(It begin, It end){
    if(begin == end) return;
    _swap(*begin, *((end - begin) / 2 + begin));
    It pi = begin;
    It le = begin + 1;
    It ri = end - 1;
    while(le <= ri){
        while(le <= ri && !(*pi < *le)) le++;
        while(le <= ri && !(*ri < *pi)) ri--;
        if(le <= ri) _swap(*le, *ri);
    }
    _swap(*pi, *ri);
    _sort(begin, ri);
    _sort(ri + 1, end);
}
 
void rotate(unsigned int &n){
    n = (MOVE(n, 30, 24) | MOVE(n, 28, 16) | MOVE(n, 26, 8) | MOVE(n, 24, 0) | MOVE(n, 22, 26) | MOVE(n, 20, 18) | MOVE(n, 18, 10) | MOVE(n, 16, 2) | MOVE(n, 14, 28) | MOVE(n, 12, 20) | MOVE(n, 10, 12) | MOVE(n, 8, 4) | MOVE(n, 6, 30) | MOVE(n, 4, 22) | MOVE(n, 2, 14) | MOVE(n, 0, 6));
}
int getIdx(int key){
    int l = 0, r = MAX - 1;
    while(l < r){
        int m = l + r + 1 >> 1;
        if(key < keyTable[m]) r = m - 1;
        else if(key >= keyTable[m]) l = m;
    }
    if(key == keyTable[r]) return r;
    return -1;
}
 
void makeHash(int a[4][4], int idx){
    unsigned int &key = _data[idx].key, &op_key = _data[idx].op_key;
    key = op_key = 0;
    int sh = 30;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            key += ((unsigned int)a[i][j] - _data[idx].base) << sh;
            op_key += (_data[idx].depth - ((unsigned int)a[i][3 - j] - _data[idx].base)) << sh;
            sh -= 2;
        }
    }
    unsigned int t1 = key, t2 = op_key;
    rotate(t1);
    rotate(t2);
    if(t1 < key) key = t1;
    if(t2 < op_key) op_key = t2;
    rotate(t1);
    rotate(t2);
    if(t1 < key) key = t1;
    if(t2 < op_key) op_key = t2;
    rotate(t1);
    rotate(t2);
    if(t1 < key) key = t1;
    if(t2 < op_key) op_key = t2;
    keyTable[keyCnt++] = key;
}
 
_vector table[MAX];
 
int makeBlock(int module[][4][4]){
    int ret = 0;
    keyCnt = 0;
    for(int k = 0; k < MAX; ++k){
        int maxv = -1, minv = 987654321;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                if(maxv < module[k][i][j]) maxv = module[k][i][j];
                if(minv > module[k][i][j]) minv = module[k][i][j];
            }
        }
        _data[k].base = minv;
        _data[k].depth = maxv - minv;
        makeHash(module[k], k);
    }
    _sort(keyTable, keyTable + MAX);
    for(int i = 0; i < MAX; ++i){
        table[getIdx(_data[i].key)].push_back(i);
    }
    for(int i = 0; i < MAX; ++i){
        int key = getIdx(_data[i].key);
        if(table[key].empty()) continue;
        int op_key = getIdx(_data[i].op_key);
        if(op_key == -1 || table[op_key].empty()){
            table[key].clear();
            continue;
        }
        while(table[key].size() && table[op_key].size()){
            if(key == op_key && table[key].size() == 1) break;
            int idx1 = table[key].back();
            table[key].pop_back();
            int idx2 = table[op_key].back();
            table[op_key].pop_back();
            ret += _data[idx1].base + _data[idx1].depth + _data[idx2].base;
        }
        table[key].clear();
        table[op_key].clear();
    }
    return ret;
}