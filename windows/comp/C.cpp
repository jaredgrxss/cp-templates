#include <bits/stdc++.h>
using namespace std;
 
 
bool partOf(string& s, int idx) {
	if (s.substr(idx, 4) == "1100") return true;
	if (idx - 1 >= 0 and s.substr(idx - 1, 4) == "1100") return true;
	if (idx - 2 >= 0 and s.substr(idx - 2, 4) == "1100") return true;
	if (idx - 3 >= 0 and s.substr(idx - 3, 4) == "1100") return true;
	return false;;
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) {
        string s; int q;
		cin >> s >> q;
		int present = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.substr(i, 4) == "1100") present++;
		}
		for (int i = 0; i < q; i++) {
			int idx, v; cin >> idx >> v;
			idx--;
			if (partOf(s, idx)) present--;
			s[idx] = (v == 1) ? '1' : '0';
			if (partOf(s, idx)) present++;
			if (present > 0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
    }
}