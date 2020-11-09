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

class SegmentTree {
public:
    using pii = pair<int, int>;
    int size;
    vector<pair<int, int>> v;
    const pair<int, int> INF =  make_pair(INT_MAX, 0);
    SegmentTree(int  n) {
        size = 1;
        while (size < n) size *= 2;
        v.assign(2*size, make_pair(0, 0));
    }

    void build_tree(vector<int>& a) {
        build_tree(a, 0, 0, size);
    }

    void set(int index, int val) {
        set(index, val, 0, 0, size);
    }

    pii query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
// private:
    void build_tree(vector<int>& a, int i, int l, int r) {
        if (r - l == 1) {
            if (l < a.size()) v[i] = make_pair(a[l], 1);
            return;
        }
        int mid = (l + r) / 2;
        build_tree(a, 2*i+1, l, mid);
        build_tree(a, 2*i+2, mid, r);
        v[i] = merge(v[2*i+1], v[2*i+2]);
    }

    void set(int index, int val, int i, int l, int r) {
        if (r - l == 1) {
            v[i] = make_pair(val, 1);
            return;
        }

        int mid = (l + r) / 2;
        if (index < mid) set(index, val, 2*i+1, l, mid);
        else set(index, val, 2*i+2, mid, r);
        v[i] = merge(v[2*i+1], v[2*i+2]);
    }

    pii query(int left, int right, int i, int l, int r) {
        if (r <= left || right <= l) return INF;
        if (left <= l && r <= right) return v[i];
        int mid = (l + r) / 2;
        return merge(query(left, right, 2*i+1, l, mid),
                     query(left, right, 2*i+2, mid, r));
    }

    pii merge(pii left, pii right) {
        if (left.first < right.first) return left;
        else if (left.first > right.first) return right;
        return make_pair(left.first, left.second + right.second);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    read(v);
    SegmentTree st(n);
    st.build_tree(v);
    while (m--) {
        int t, c1, c2; cin >> t >> c1 >> c2;
        if (t == 1) st.set(c1, c2);
        else {
            auto tmp = st.query(c1, c2);
            cout << tmp.first << " " << tmp.second << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}