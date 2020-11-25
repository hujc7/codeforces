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
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    for (int i = 0; i + 1 < n; i += 2) {
        swap(v[i], v[i+1]);
    }

    if (n % 2 == 1 && n >= 3) swap(v[n-3], v[n-1]);
    rep(i, 0, n) cout << v[i] << " ";
    cout << nndl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}