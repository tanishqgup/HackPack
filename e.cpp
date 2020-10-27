vector<int> ordering;
void toposort() {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		ordering.pb(node);
		for (auto i : adj[node]) {
			indegree[i]--;
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
	}
}