struct binary_lifting {
	int nodes, root, LOG, timer;
	vector<vector<int>> parent;
	vector<int> t_in, t_out;

	binary_lifting(int n, int cur_root, vector<vector<int>> &adj) {
		LOG = (int)log2(n) + 1, root = cur_root, nodes = n, timer = 1;
		parent.resize(n + 1, vector<int>(LOG, root));
		t_in.resize(n + 1), t_out.resize(n + 1);
		immediate_Parent(root, root, adj);
		for (int k = 1; k < LOG; k++) {
			for (int i = 1; i <= n; i++) {
				parent[i][k] = parent[parent[i][k - 1]][k - 1];
			}
		}
	}

	void immediate_Parent(int node, int par, vector<vector<int>> &adj) {
		parent[node][0] = par;
		t_in[node] = timer++;
		for (int nei : adj[node]) {
			if (nei == par) continue;
			immediate_Parent(nei, node, adj);
		}
		t_out[node] = timer++;
	}

	int kth_ancestor(int node, int k) {
		for (int i = LOG - 1; i >= 0; i--) {
			int jump_to_make = (1 << i);
			if (jump_to_make > k) continue;
			k -= jump_to_make;
			node = parent[node][i];
		}
		return node;
	}

	bool is_ancestor(int u, int v) {
		return (t_in[u] <= t_in[v] && t_out[u] >= t_out[v]);
	}

	int lca(int u, int v) {
		if (is_ancestor(u, v)) return u;
		if (is_ancestor(v, u)) return v;
		for (int i = LOG - 1; i >= 0; i--) {
			int new_node = parent[u][i];
			if (is_ancestor(new_node, v)) continue;
			u = new_node;
		}
		return parent[u][0];
	}
};
