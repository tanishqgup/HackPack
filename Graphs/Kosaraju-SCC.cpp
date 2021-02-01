void dfs(int node, vector<int> &ordering, vector<bool> &visited) {
    visited[node] = 1;
    for (int nei : adj[node]) {
        if (!visited[nei]) {
            dfs(nei, ordering, visited);
        }
    }
    ordering.pb(node);
}

void dfs2(int node, vector<bool> &visited, vector<int> &now) {
    now.pb(node);
    visited[node] = 1;
    for (auto nei : radj[node]) {
        if (!visited[nei]) {
            dfs2(nei, visited, now);
        }
    }
}

vector<vector<int>> SCC() {
    vector<int> ordering;
    vector<bool> visited(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, ordering, visited);
        }
    }
    visited.assign(n + 1, 0);
    vector<vector<int>> ans;
    for (int i = sz(ordering) - 1; i >= 0; i--) {
        if (!visited[ordering[i]]) {
            vector<int> now;
            dfs2(ordering[i], visited, now);
            ans.pb(now);
        }
    }
    return ans;
}
