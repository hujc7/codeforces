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
const int maxn = 501;
using T = short;

const T INF = 501;
T dfs(T index, T last, T x, vi& v, vector<vector<T>>& dp) {
    if (index == v.size()) return 0;
    // check for validity
    if (v[index] < last && x < last) return INF;

    T& val = dp[index][x];
    if (val != -1) return val;

    T res = INF;
    if (last <= x && x < v[index]) res = min(res, T(dfs(index+1, x, v[index], v, dp) + 1));
    if (last <= v[index]) res = min(res, dfs(index+1, v[index], x, v, dp));
    
    return val = res;
}

void solve() {
    int n, x; cin >> n >> x;
    vi v(n);
    read(v);

    vector<vector<T>> dp(n, vector<T>(501, -1));

    int res = dfs(0, 0, x, v, dp);
    cout << (res == INF ? -1 : res) << nndl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}