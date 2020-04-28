#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>
#define MAX 1010
using namespace std;
int dp[MAX][MAX];

int main()
{    
    char c;
    char a[MAX];
    char b[MAX];
    cin>>a>>b;
    int la=strlen(a);
    int lb=strlen(b);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=la; i++)
    {
        for(int j=1; j<=lb; j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=la,j=lb;
    stack<char>s;
    while(dp[i][j])
    {
        if(dp[i][j]==dp[i-1][j])///来自于左方向
        {
            i--;
        }
        else if(dp[i][j]==dp[i][j-1])///来自于上方向
        {
            j--;
        }
        else if(dp[i][j]>dp[i-1][j-1])///来自于左上方向
        {
            i--;
            j--;
            s.push(a[i]);
        }
    }
    cout<<"最长子序列长度为："<<dp[la][lb]<<endl; 
    cout<<"最长子序列为："; 
    while(!s.empty())
    {
        c=s.top();
        cout<<c;
        s.pop();
    }
    return 0;
}

