#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Line;
const ll LINF = 2e18;

struct LiChaoTree{
    ll f(Line l, ll x){
        return l.first * x + l.second;
    }
    struct Node{
        int left, right;
        ll xl, xr;
        Line l;
    };
    vector<Node> nodes;
    void init(ll minv, ll maxv){
        nodes.push_back({-1, -1, minv, maxv, {0, -LINF}});
    }

    void insert(int n, Line newline){
        ll xl = nodes[n].xl, xr = nodes[n].xr;
        ll xm = xl + xr >> 1;
        Line llow = nodes[n].l, lhigh = newline;
        if(f(llow, xl) > f(lhigh, xl)) swap(llow, lhigh);
        if(f(llow, xr) <= f(lhigh, xr)){
            nodes[n].l = lhigh;
            return;
        }
        else if(f(llow, xm) <= f(lhigh, xm)){
            nodes[n].l = lhigh;
            if(nodes[n].right == -1){
                nodes[n].right = nodes.size();
                nodes.push_back({-1, -1, xm + 1, xr, {0, -LINF}});
            }
            insert(nodes[n].right, llow);
        }
        else{
            nodes[n].l = llow;
            if(nodes[n].left == -1){
                nodes[n].left = nodes.size();
                nodes.push_back({-1, -1, xl, xm, {0, -LINF}});
            }
            insert(nodes[n].left, lhigh);
        }
    }
    ll getVal(int n, ll x){
        if(n == -1) return -LINF;
        ll xl = nodes[n].xl, xr = nodes[n].xr;
        ll xm = xl + xr >> 1;
        if(xm < x) return max(f(nodes[n].l, x), getVal(nodes[n].right, x));
        else return max(f(nodes[n].l, x), getVal(nodes[n].left, x));
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    LiChaoTree tree;
    tree.init(-1e12, 1e12);
    int Q;
    cin >> Q;
    while(Q--){
        ll type, a, b;
        cin >> type;
        if(type == 1){
            cin >> a >> b;
            tree.insert(0, {a, b});
        }
        else{
            cin >> a;
            cout << tree.getVal(0, a) << '\n';
        }
    }
    return 0;
}