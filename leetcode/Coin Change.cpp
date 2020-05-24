class Solution {
public:

int coinChange(vector<int>& coins, int amount) {
	sort(coins.begin(), coins.end());
	long long dp[coins.size()+1][amount+1];

	dp[0][0] = 0;	
	for (int j = 1; j < amount+1; j++)
		dp[0][j] = INT_MAX;
	for (int i = 1; i < coins.size()+1; i++)
		dp[i][0] = 0;
				
	for (int i = 1; i < coins.size()+1; i++) {
		for (int j = 1; j < amount+1; j++) {
			if (coins[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else if (coins[i-1] == j)
				dp[i][j] = 1;
			else dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
		}
	}	
	int ans = dp[coins.size()][amount];
	return ans == INT_MAX ? -1 : ans;
}
};
