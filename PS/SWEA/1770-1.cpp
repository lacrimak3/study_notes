#define MAX 30000

int base[MAX], len[MAX], hashval[MAX], hashidx[MAX];
struct lookup{
    int idx = 0;
    lookup(){}
    bool operator < (const lookup &other) const{
        if(base[idx] == base[other.idx]) return idx < other.idx;
        return base[idx] > base[other.idx];
    }
};
struct Node{
    int now, length;
    int list[100];
    bool empty() const{
        return now == length;
    }
};

lookup index[MAX];
Node table[MAX];
template <typename It>
void _swap(It &a, It &b);
template <typename It>
void _sort(It begin, It end);
int makehash(int a[4][4], int idx);
int getIdx(int val);
void rotate(int a[4][4]);
void flip(int a[4][4], int idx);
int test(int module[][4][4])
{
    int ret = 0;
    for(int k = 0; k < MAX; k++){
        table[k].now = table[k].length = 0;
        index[k].idx = k;
        int min_height = 20;
        len[k] = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(min_height > module[k][i][j])
                    min_height = module[k][i][j];
                if(len[k] < module[k][i][j]) len[k] = module[k][i][j];
            }
        }
        base[k] = min_height;
        int t = 0;
        hashval[k] = makehash(module[k], k);
    }
    _sort(index, index + MAX);
    _sort(hashval, hashval + MAX);
    for(int i = 0; i < MAX; i++){
        int idx = index[i].idx;
        hashidx[idx] = getIdx(makehash(module[idx], idx));
        table[hashidx[idx]].list[table[hashidx[idx]].length++] = idx;
    }
    for(int i = 0; i < MAX; i++){
        int idx = index[i].idx;
        if(table[hashidx[idx]].empty()) continue;
        table[hashidx[idx]].now++;
        flip(module[idx], idx);
        int maxv = -1, maxidx = -1, ridx;
        for(int j = 0; j < 4; j++){
            rotate(module[idx]);
            int tidx = getIdx(makehash(module[idx], idx));
            if(tidx == -1) continue;
            if(table[tidx].empty()) continue;
            int nidx = table[tidx].list[table[tidx].now];
            if(maxv < base[nidx]){
                maxv = base[nidx];
                maxidx = tidx;
                ridx = nidx;
            }
        }
        if(maxidx != -1){
            ret += base[ridx] + len[idx];
            table[hashidx[maxidx]].now++;
        }
    }
    return ret;
}

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

int makehash(int a[4][4], int idx){
    int t = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            t *= 3;
            t += a[i][j] - base[idx];
        }
    return t;
}

int getIdx(int val){
    int l = 0, r = MAX;
    while(l <= r){
        int mid = l + r >> 1;
        if(hashval[mid] == val) return mid;
        else if(hashval[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void flip(int a[4][4], int idx){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            a[i][j] = len[idx] - a[i][j] + base[idx];
        _swap(a[i][0], a[i][3]);
        _swap(a[i][1], a[i][2]);
    }
}

void rotate(int a[4][4]){
    int t[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            t[j][3 - i] = a[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = t[i][j];
        }
    }
}
