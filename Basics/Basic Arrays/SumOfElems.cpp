class Solution{
public:
	int sum(int arr[], int n) {
		int add = 0;

		for(int i = 0; i < n; i++)
		{
			add += arr[i];
		}

		return add;
	}
};