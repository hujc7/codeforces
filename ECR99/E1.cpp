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

ll x[4], y[4];
ll xt[4], yt[4];

void solve() {
    // vector<ll> x(4), y(4);
    rep(i, 0, 4) {
        cin >> x[i] >> y[i];
    }

    // vector<ll> xt(4), yt(4);
    vi index(4);

    ll res = LLONG_MAX;
    rep(st, 0, 2) {
        rep(idx1, 0, 4) rep(idx2, 0, 4) rep(idy1, 0, 4) {
            ll x1 = x[idx1];
            ll x2 = x[idx2];
            ll y1 = y[idy1];

            if (x1 > x2)
                continue;

            for (int k = -1; k <= 1; k += 2) {
                ll y2 = y1 + k * abs(x2 - x1);

                // vector<vector<ll>> pts = {{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
                xt[0] = xt[1] = x1;
                xt[2] = xt[3] = x2;
                yt[0] = yt[2] = y1;
                yt[1] = yt[3] = y2;

                iota(all(index), 0);

                do {
                    ll cur = 0;
                    rep(i, 0, 4)
                        cur += abs(xt[index[i]] - x[i]) + abs(yt[index[i]] - y[i]);

                    res = min(res, cur);
                } while (next_permutation(all(index)));
            }
        }

        rep(i, 0, 4)
            swap(x[i], y[i]);
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