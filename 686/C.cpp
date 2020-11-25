#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utility>
using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define rep(i,L,R) for (int i = L; i < R; ++i)
#define rrep(i,L,R) for (int i = R; i > L; --i)
#define each(x, a) for (auto& x: a)
#define nndl "\n"

using ul = unsigned long;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using ii = pair<int, int>;

template<class T> void read(T& x) {
    cin >> x;
}
template <class H, class... T>
void read(H& h, T&... t) {
    cin >> h;
    read(t...);
}
template<class T> void read(vector<T>& v) {
    each(x, v)
        read(x);
}
template<class A> void write(A x) {
	cout << x;
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
template<class T> void print(vector<T>& v) {
    each(x, v)
        write(x, " ");
    write("\n");
}

// code
void solve() {
    int n; cin >> n;
    unordered_map<int, vector<int>> indices;
    rep(i, 0, n) {
        int tmp; cin >> tmp;
        indices[tmp].push_back(i);
    }

    int res = INT_MAX;
    for (auto &p: indices) {
        int last = 0, cnt = 0;
        for (auto c: p.second) {
            if (last != c) cnt++;
            last = c+1;
        }
        if (last < n) cnt++;
        res = min(res, cnt);
    }

    cout << res << nndl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}