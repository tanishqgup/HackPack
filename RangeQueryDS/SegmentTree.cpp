struct SegTree {
    int size;
    vector<int> tree;
    int unit_element;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        #warning change unit_element accordingly
        unit_element = 0;
        tree.assign(2 * size, unit_element);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 0) {
            if (rx < (int)a.size()) {
                tree[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid + 1, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size - 1);
    }

    int query(int x, int l, int r, int lx, int rx) {
        if (r < lx || l > rx) return unit_element;
        if (lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        int left = query(2 * x + 1, l, r, lx, mid);
        int right = query(2 * x + 2, l, r, mid + 1, rx);
        return merge(left, right);
    }

    int query(int l, int r) {
        return query(0, l, r, 0, size - 1);
    }

    void update(int x, int lx, int rx, int l, int r, int v) {
        if (rx < l || lx > r) return;
        if (rx == l && lx == l) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        update(2 * x + 1, lx, mid, l, r, v);
        update(2 * x + 2, mid + 1, rx, l, r, v);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(0, 0, size - 1, i, i, v);
    }

    int merge(int a, int b) {
        #warning change merge function accordingly
        return a + b;
    }

} st;
