#include <bits/stdc++.h>
using namespace std;

int MAXN = 1e6;
vector<int> dsu(MAXN);
vector<int> size(MAXN, 1);


int find(int v) {
    if (dsu[v] == v) return v;
    return dsu[v] = find(dsu[v]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        dsu[b] = a;
        size[a] += size[b];
    }
}
