struct sparse_table {
    int size_of_array, K;
    int unit_element;
    vector<vector<int>> table;
    vector<int> log;
    bool logs_initiated, table_builded;

    void init(int N) {
        table_builded = false;
        logs_initiated = false;
        size_of_array = N, K = 1;
        #warning change unit_element accordingly
        unit_element = inf;
        int KK = 1;
        while (KK < N) K++, KK *= 2;
        table = vector<vector<int>>(N, vector<int>(K, unit_element));
    }

    void build(vector<int> &v) {
        table_builded = true;
        for (int i = 0; i < size_of_array; i++) {
            table[i][0] = v[i];
        }
        for (int i = 1; i < K; i++) {
            for (int j = 0; j < size_of_array; j++) {
                int next_idx = j + (1 << (i - 1));
                bool next_possible = (next_idx < size_of_array ? true : false);
                table[j][i] = merge(table[j][i - 1], (next_possible ? table[next_idx][i - 1] : unit_element));
            }
        }
    }

    int query(int l, int r) {
        if (!table_builded) {
            cout << "Table not builded yet" << endl;
            return -1;
        }
        int ans = 0;
        for (int i = K - 1; i >= 0; i--) {
            if (l + (1 << i) - 1 <= r) {
                ans = merge(ans, table[l][i]);
                l = l + (1 << i);
            }
        }
        return ans;
    }

    void initLogs() {
        logs_initiated = true;
        log = vector<int>(size_of_array + 1);
        log[1] = 0;
        for (int i = 2; i <= size_of_array; i++) {
            log[i] = log[i / 2] + 1;
        }
    }

    int minQuery(int l, int r) {
        if (!logs_initiated) {
            cout << "Logs are not initiated" << endl;
            return -1;
        }
        if (!table_builded) {
            cout << "Table not builded yet" << endl;
            return -1;
        }
        int j = log[r - l + 1];
        return merge(table[l][j], table[r - (1 << j) + 1][j]);
    }

    int merge(int a, int b) {
        #warning change function accordingly;
        return min(a, b);
    }
};
