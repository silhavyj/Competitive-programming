class Solution {
public:
    

int maxSubarraySumCircular(vector<int>& A) {
	int sum1 = 0;
	int sum2 = 0;
	int min_sum = INT_MAX;
	int max_sum = INT_MIN;
	int total = 0;

	for (int a : A) {
		total += a;
		sum1 += a, sum2 += a;
		max_sum = max(max_sum, sum1);
		min_sum = min(min_sum, sum2);
		sum1 = max(0, sum1);
		sum2 = min(0, sum2);
	}
	if (total == min_sum)
			return max_sum;
	return max(max_sum, total-min_sum);
}


};
