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
using ll = long long;
struct Node {
    ll pref, suff, seg, sum;

    static Node single(int x) {
        if (x > 0) return {x, x, x, x};
        return {0, 0, 0, x};
    }

    static Node merge(Node l, Node r) {
        return {
            max(l.pref, l.sum + r.pref),
            max(r.suff, l.suff + r.sum),
            max({l.seg, r.seg, l.suff + r.pref}),
            l.sum + r.sum
        };
    }

    static const Node INF;
};

const Node Node::INF = {0, 0, 0, 0};

template <class T>
class SegmentTree {
public:
    int size;
    vector<T> v;
    SegmentTree(int  n) {
        size = 1;
        while (size < n) size *= 2;
        v.resize(2*size);
    }

    void build_tree(vector<int>& a) {
        build_tree(a, 0, 0, size);
    }

    void set(int index, int val) {
        set(index, val, 0, 0, size);
    }

    T query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
// private:
    void build_tree(vector<int>& a, int i, int l, int r) {
        if (r - l == 1) {
            if (l < a.size()) v[i] = T::single(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build_tree(a, 2*i+1, l, mid);
        build_tree(a, 2*i+2, mid, r);
        v[i] = T::merge(v[2*i+1], v[2*i+2]);
    }

    void set(int index, int val, int i, int l, int r) {
        if (r - l == 1) {
            v[i] = T::single(val);
            return;
        }

        int mid = (l + r) / 2;
        if (index < mid) set(index, val, 2*i+1, l, mid);
        else set(index, val, 2*i+2, mid, r);
        v[i] = T::merge(v[2*i+1], v[2*i+2]);
    }

    T query(int left, int right, int i, int l, int r) {
        if (r <= left || right <= l) return T::INF;
        if (left <= l && r <= right) return v[i];
        int mid = (l + r) / 2;
        return T::merge(query(left, right, 2*i+1, l, mid),
                        query(left, right, 2*i+2, mid, r));
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    read(v);
    SegmentTree<Node> st(n);
    st.build_tree(v);
    cout << st.query(0, n).seg << "\n";
    while (m--) {
        int c1, c2; cin >> c1 >> c2;
        st.set(c1, c2);
        cout << st.query(0, n).seg << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}