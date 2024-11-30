#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <random>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <tuple>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

void testcase() {
	int n; cin >> n;
	vector<int> h(n);
	for (int& i : h) cin >> i;
	int mx = 1, cur = 1;
	for (int i = 1; i < n; i++) {
		if (h[i] >= h[i - 1]) { cur++; }
		else cur = 1;
		mx = max(mx, cur);
	}
	cout << n - mx << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int t = 0; t < tc; t++) testcase();
	return 0;
}
