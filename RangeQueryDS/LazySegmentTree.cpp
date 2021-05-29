struct LazySegmentTree {
    vector<int> tree, lazy_tree;
    int size, unit_element1, unit_element2;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        unit_element1 = inf, unit_element2 = 0;
        tree.resize(2 * size, unit_element1);
        lazy_tree.resize(2 * size, unit_element2);
    }

    void build(vector<int> &a, int v, int l, int r) {
        if (l == r) {
            tree[v] = (l < sz(a) ? a[l] : unit_element1);
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size - 1);
    }

    void push(int v) {
        tree[2 * v + 1] += lazy_tree[v];
        tree[2 * v + 2] += lazy_tree[v];
        lazy_tree[2 * v + 1] += lazy_tree[v];
        lazy_tree[2 * v + 2] += lazy_tree[v];
        lazy_tree[v] = 0;
    }

    void range_update(int v, int lx, int rx, int l, int r, int to_add) {
        if (rx < l || lx > r) return;
        if (l <= lx && rx <= r) {
            tree[v] += to_add;
            lazy_tree[v] += (lx != rx ? to_add : 0LL);
            return;
        }
        push(v);
        int mid = (lx + rx) / 2;
        range_update(2 * v + 1, lx, mid, l, r, to_add);
        range_update(2 * v + 2, mid + 1, rx, l, r, to_add);
        tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }

    void range_update(int l, int r, int to_add) {
        range_update(0, 0, size - 1, l, r, to_add);
    }

    int query(int v, int l, int r, int lx, int rx) {
        if (r < lx || l > rx) return unit_element1;
        if (l <= lx && r >= rx) {
            if (lazy_tree[v] && (lx != rx)) push(v);
            return tree[v];
        }
        push(v);
        int mid = (lx + rx) / 2;
        int ans1 = query(2 * v + 1, l, r, lx, mid);
        int ans2 = query(2 * v + 2, l, r, mid + 1, rx);
        return min(ans1, ans2);
    }

    int query(int l, int r) {
        return query(0, l, r, 0, size - 1);
    }

    int merge(int a, int b) {
        return min(a, b);
    }

} st;
