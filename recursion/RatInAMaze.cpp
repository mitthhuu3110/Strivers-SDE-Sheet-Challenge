class Solution{
	void helper(int i, int j, vector<vector<int>> &m, int n, vector<string> &res, string move, vector<vector<int>> &vis){
		if(i == n-1 && j == n-1){
			res.push_back(move);
		}
		//down
		if(i+1 < n && !vis[i+1][j] && m[i+1][j] == 1){
			vis[i][j] = 1;
			helper(i+1, j, m, n, res, move, vis);
			vis[i][j] = 0;
		}

		//left
		if(j-1 >= 0 && !vis[i][j-1] && m[i][j-1] == 1){
			vis[i][j] = 1;
			helper(i, j-1, m, n, res, move, vis);
			vis[i][j] = 0;
		}

		//right
		if(j+1 < n && !vis[i][j] && m[i][j] == 1){
			vis[i][j] = 1;
			helper(i, j+1, m, n, res, move, vis);
			vis[i][j] = 0;
		}

		//up
		if(i-1 >= 0 && !vis[i][j] && m[i][j] == 1){
			vis[i][j] = 1;
			helper(i-1, j, m, n, res, move, vis);
			vis[i][j] = 0;
		}
	}


public:
	vector<vector<int>> findPath(vector<vector<int>> &m, int n){
		vector<vector<int>> res;
		vector<vector<int>> vis(n, vector<int> (n, 0));
		if(m[0][0] == 1) helper(0, 0, m, n, res, "", vis);
		return res;
	}
};
