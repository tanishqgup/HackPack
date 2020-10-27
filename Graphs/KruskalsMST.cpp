int mincost = 0;
void kruskalsMST() {
	DisjointSet dSet(nax);
	sort(all(adj));
	for (auto i : adj) {
		int from = i[1];
		int to = i[2];
		int cost = i[0];
		int s1 = dSet.Find(from);
		int s2 = dSet.Find(to);
		if (s1 != s2) {
			mincost += cost;
			dSet.Union(from, to);
		}
	}
}
