#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int inf = 2e9 + 7;

const ll Inf = 1e18 + 7;

const int maxn = 3e3 + 5;

const int mod = 1e9 + 7;



int dp[maxn][maxn];  //dp[i][j]��ʾǰi��ͶjԪ���������

int f[maxn][maxn];   //f[i][j]��ʾ��i��Ͷ��jԪ���������

int x[maxn][maxn];   //x[i][j]��ʾǰi��Ͷ��jԪʱ��i����Ͷ��

int ans[maxn];       //��ʾ�������ʱÿ����Ͷ��



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

	printf("Ͷ�ʵ����������%dԪ\n", dp[n][m]);

	for (int i = 1; i <= n; ++i)

	{

		printf("�Ե�%d����Ŀ��Ͷ��Ϊ%dԪ\n", i, ans[i]);

	}

}
