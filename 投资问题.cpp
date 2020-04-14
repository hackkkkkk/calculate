#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int inf = 2e9 + 7;

const ll Inf = 1e18 + 7;

const int maxn = 3e3 + 5;

const int mod = 1e9 + 7;



int dp[maxn][maxn];  //dp[i][j]表示前i件投j元的最大收益

int f[maxn][maxn];   //f[i][j]表示第i件投资j元的最大收益

int x[maxn][maxn];   //x[i][j]表示前i件投入j元时第i件的投资

int ans[maxn];       //表示收益最大时每个的投资



int main()

{

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)

	{

		for (int j = 1; j <= m; ++j)

		{

			scanf("%d", &f[i][j]);

		}

	}

	for (int i = 1; i <= n; ++i)

	{

		for (int j = 0; j <= m; ++j)

		{

			for (int k = 0; k <= j; ++k)

			{

				if (dp[i][j] < dp[i - 1][j - k] + f[i][k])

				{

					dp[i][j] = dp[i - 1][j - k] + f[i][k];

					x[i][j] = k;

				}

			}

		}

	}

	ans[n] = x[n][m];

	int tmp_m = m - ans[n];

	for (int i = n - 1; i >= 1; --i)

	{

		ans[i] = x[i][tmp_m];

		tmp_m -= ans[i];

	}

	printf("投资的最大收益是%d元\n", dp[n][m]);

	for (int i = 1; i <= n; ++i)

	{

		printf("对第%d个项目的投资为%d元\n", i, ans[i]);

	}

}
