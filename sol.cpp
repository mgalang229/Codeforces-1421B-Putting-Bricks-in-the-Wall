#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<vector<char>> a(n, vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		
		/*
		S0000
		01000
		11110
		10010
		1111F
		*/
		
		vector<pair<int, int>> vec;
		if (a[0][1] != a[1][0] && a[n - 1][n - 2] != a[n - 2][n - 1]) {
			vec.push_back(make_pair(1, 2));
			if ((a[0][1] ^ ('0' ^ '1')) == a[n - 2][n - 1]) {
				vec.push_back(make_pair(n - 1, n));
			} else {
				vec.push_back(make_pair(n, n - 1));
			}
		} else {
			if (a[0][1] == a[1][0] && a[n - 1][n - 2] != a[n - 2][n - 1]) {
				if (a[0][1] == a[n - 2][n - 1]) {
					vec.push_back(make_pair(n - 1, n));
				} else {
					vec.push_back(make_pair(n, n - 1));
				}
			} else if (a[n - 1][n - 2] == a[n - 2][n - 1] && a[0][1] != a[1][0]) {
				if (a[n - 1][n - 2] == a[0][1]) {
					vec.push_back(make_pair(1, 2));
				} else {
					vec.push_back(make_pair(2, 1));
				}
			} else if (a[0][1] == a[n - 1][n - 2]) {
				vec.push_back(make_pair(1, 2));
				vec.push_back(make_pair(2, 1));
			}
		}
		cout << (int) vec.size() << '\n';
		for (auto& e : vec) {
			cout << e.first << " " << e.second << '\n';
		}
	}
	return 0;
}
