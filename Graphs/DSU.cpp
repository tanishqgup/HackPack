class DisjointSet {
	vector<int> parent;
	vector<int> rank;
public:
	DisjointSet(int n) {
		parent.resize(n + 1, -1);
		rank.resize(n + 1, 1);
	}
	int Find(int x) {
		if (parent[x] == -1) {
			return x;
		}
		return parent[x] = Find(parent[x]);
	}
	void Union(int x, int y) {
		int s1 = Find(x);
		int s2 = Find(y);
		if (s1 == s2) {
			return;
		}
		if (rank[s1] > rank[s2]) {
			parent[s2] = s1;
			rank[s1] += rank[s2];
		}
		else {
			parent[s1] = s2;
			rank[s2] += rank[s1];
		}
	}
};
