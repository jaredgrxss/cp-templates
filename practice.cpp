#include <bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return g;
}


struct SegTree{
    int n;
    vector<int> t;

    SegTree(int n){
        this->n = n;
        t.assign(4*n, 0);
    }

    void build(int v, int tl, int tr, vector<int> a){
        if(tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm, a);
            build(v*2+1, tm+1, tr, a);
            t[v] = t[v*2] + t[v*2+1];

        }
    }

    int sum(int v, int tl, int tr, int l, int r){
        if (l > r) {
            return 0;
        }

        if (l == tl && r == tr) {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(tm,r)) +
            sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int n_v){
        if (tl == tr)
            t[v] = n_v;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, n_v);
            else
                update(v*2, tm+1, tr, pos, n_v);
            t[v] = t[v*2] + t[v*2+1];
        }
    }




};




int main(){

    int x = 1, y = 0;
    cout << egcd(80,55, x, y) << " " << x << " " << y << endl; 



    return 0;
}