#define MAX 30000
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define NULL 0

template <typename A, typename B>
struct _pair{
    A first;
    B second;
    _pair(A a, B b): first(a), second(b){}
    _pair(){}
    bool operator < (const _pair &other) const{
        if(first == other.first) return second < other.second;
        else return first < other.first;
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

struct Node{
    int idx;
    Node* link = NULL;
};

Node *table[MAX];
int base[MAX], len[MAX], hashVal[MAX], cps[MAX];
bool check[MAX];
_pair<int, int> bid[MAX];

int makeHash(int a[4][4]);
int flip(int a[4][4], int idx);
int rotate(int a[4][4]);
int getIdx(int val);

int makeBlock(int module[][4][4]){
    int ret = 0;
    for(int i = 0; i < MAX; i++){
        check[i] = false;
        base[i] = 10;
        len[i] = 0;
        cps[i] = 0;
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                base[i] = min(base[i], module[i][j][k]);
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++){
                module[i][j][k] = module[i][j][k] - base[i];
                len[i] = max(len[i], module[i][j][k]);
            }
        bid[i] = {base[i] + len[i], i};
        cps[i] = makeHash(module[i]);
    }
    _sort(bid, bid + MAX);
    _sort(cps, cps + MAX);
    Node *newNode = NULL;
    for(int i = 0; i < MAX; i++){
        int idx = bid[i].second;
        int hash = getIdx(makeHash(module[idx]));
        hashVal[idx] = hash;
        newNode = new Node;
        newNode -> idx = idx;
        newNode -> link = NULL;
        if(table[hash] == NULL){
            table[hash] = newNode;
        }
        else{
            newNode -> link = table[hash];
            table[hash] = newNode;
        }
    }
    Node *del;
    for(int i = MAX - 1; i >= 0; i--){
        int idx = bid[i].second;
        if(check[idx]) continue;
        check[idx] = true;
        int tmp = hashVal[idx];
        del = table[tmp];
        table[tmp] = table[tmp] -> link;
        delete del;
        tmp = flip(module[idx], idx);
        int maxv = -1, maxr = 0, ridx;
        for(int k = 0; k < 4; k++){
            if(tmp != -1 && table[tmp]){
                int tidx = table[tmp] -> idx;
                if(maxv < base[tidx]){
                    maxv = base[tidx];
                    ridx = tidx;
                    maxr = tmp;
                }
            }
            tmp = rotate(module[idx]);
        }
        if(maxv != -1){
            ret += base[idx] + base[ridx] + len[idx];
            del = table[maxr];
            table[maxr] = table[maxr] -> link;
            check[ridx] = true;
            delete del;
        }
    }
    for(int i = 0; i < MAX; i++){
        int hash = hashVal[i];
        while(table[hash]){
            del = table[hash];
            table[hash] = table[hash] -> link;
            delete del;
        }
        hashVal[i] = 0;
    }
    return ret;
}

int makeHash(int a[4][4]){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ret *= 3;
            ret += a[i][j];
        }
    }
    return ret;
}

int flip(int a[4][4], int idx) {
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++){
            a[i][j] = len[idx] - a[i][j];
        }
        _swap(a[i][0], a[i][3]);
        _swap(a[i][1], a[i][2]);
    }
    return getIdx(makeHash(a));
}

int rotate(int a[4][4]) {
    int b[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            b[j][3 - i] = a[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = b[i][j];
        }
    }
    return getIdx(makeHash(a));
}

int getIdx(int val){
    int l = 0, r = MAX;
    while(l <= r){
        int m = l + r >> 1;
        if(cps[m] > val) r = m - 1;
        else if(cps[m] < val) l = m + 1;
        else return m;
    }
    return -1;
}