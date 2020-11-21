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
// unordered_map<int, int> memo;
const int INF = 1e8;
void dfs(int n, int depth, int& res) {
    if (n == 1) {  
        res = min(res, depth);
        return;
    }
    if (depth >= res) return;
    // auto it = memo.find(n);
    // if (it != memo.end()) return it->second;

    for (int i = 2; i*i <= n; ++i) {
        if (n % i != 0) continue;
        dfs(i, depth+1, res);
    }

    dfs(n-1, depth+1, res);

    // return memo[n] = res;
    return;
}

void solve() {
    int t; cin >> t;

    while (t--) {
        int c; cin >> c;
        int res = INT_MAX;
        dfs(c, 0, res);
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}