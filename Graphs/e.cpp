vector<int> dist(nax, inf);
void dijkstra(int src) {
	set<pair<int, int>> s;
	s.insert({0, src});// {cost, node}
	dist[src] = 0;
	while (!s.empty()) {
		pair<int, int> node = *s.begin();    // this node has been finalize
		s.erase(s.begin());
		dist[node.ss] = node.ff;
		for (auto nei : adj[node.ss]) {
			if (dist[nei.ff] == inf) {  // this node was never placed into set
				s.insert({nei.ss + node.ff, nei.ff});
				dist[nei.ff] = nei.ss + node.ff;
			}
			else if (s.find({dist[nei.ff], nei.ff}) != s.end()) {  // this node is present in set let's update it
				s.erase({dist[nei.ff], nei.ff});
				dist[nei.ff] = min(dist[nei.ff], nei.ss + node.ff);
				s.insert({dist[nei.ff], nei.ff});
			}
		}
	}
}