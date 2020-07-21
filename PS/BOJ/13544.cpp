#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1 << 18;

struct MergesortTree {
    vector<int> a[SIZE];

    void construct(int size) {
        for (int i = size / 2 - 1; i > 0; i--) {
            vector<int> &c = a[i], &l = a[i * 2], &r = a[i * 2 + 1];
            a[i].resize(l.size() + r.size());
            for (int j = 0, p = 0, q = 0; j < c.size(); j++) {
                if (q == r.size() || (p < l.size() && l[p] < r[q]))
                    c[j] = l[p++];
                else
                    c[j] = r[q++];
            }
        }
    }

    int greater(int s, int e, int k, int node = 1, int ns = 0, int ne = SIZE / 2) {
        if (ne <= s || e <= ns) return 0;
        if (s <= ns && ne <= e)
            return a[node].end() - upper_bound(a[node].begin(), a[node].end(), k);
        int mid = (ns + ne) / 2;
        return greater(s, e, k, node * 2, ns, mid) + greater(s, e, k, node * 2 + 1, mid, ne);
    }
};


int n, m, l;
MergesortTree st;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int size = 1;
    while(size < n) size <<= 1;
    size <<= 1;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        st.a[size/2 + i].push_back(t);
    }
    st.construct(size);
    cin >> m;
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        cout << (l = st.greater((a^l) - 1, b^l, c^l, 1, 0, size / 2)) << '\n';
    }
    return 0;
}