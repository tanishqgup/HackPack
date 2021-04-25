vector<vector<int>> generate_subsequence(vector<int> &v) {
	int length = (int)v.size();
	vector<vector<int>> ans;
	for (int i = 1; i < (1 << length); i++) {
		vector<int> now;
		int cur = i, idx = 0;
		while (cur) {
			if (cur & 1) now.pb(v[idx]);
			cur >>= 1, idx++;
		}
		ans.pb(now);
	}
	return ans;
}
