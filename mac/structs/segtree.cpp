#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    const static int N = 1e5;
    int n;
    int t[2 * N];
    Segtree(int n) { this->n = n; }

    void build(vector<int>& arr) {
        for (int i = 0; i < this->n; i++) t[this->n+i] = arr[i];
        for (int i = this->n - 1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
    };

    void modify(int p, int v) {
        for (t[p += this->n] = v; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += this->n, r += this->n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans += t[l++];
            if (r&1) ans += t[--r];
        }
        return ans;
    }
};