#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point

#define pb(a) push_back(a)

#define sqr(x) ((x)*(x))

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ll long long

#define ull unsigned long long

#define SZ(a) int(a.size())

#define read() freopen("input.txt", "r", stdin)

#define write() freopen("output.txt", "w", stdout)


#define ms(a,b) memset(a, b, sizeof(a))

#define all(v) v.begin(), v.end()

#define PI acos(-1.0)

#define pf printf

#define sfi(a) scanf("%d",&a);

#define sfii(a,b) scanf("%d %d",&a,&b);

#define sfl(a) scanf("%lld",&a);

#define sfll(a,b) scanf("%lld %lld",&a,&b);

#define sful(a) scanf("%llu",&a);

#define sfulul(a,b) scanf("%llu %llu",&a,&b);

#define sful2(a,b) scanf("%llu %llu",&a,&b); // A little different

#define sfc(a) scanf("%c",&a);

#define sfs(a) scanf("%s",a);

#define getl(s) getline(cin,s);

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define vi vector<int>

#define vll vector<ll>

#define mii map<int,int>

#define mlli map<ll,int>

#define mib map<int,bool>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define cCASE(t) cout<<"Case "<<++t<<": ";

#define D(v,status) cout<<status<<" "<<v<<endl;

#define INF 1000000000   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define CONTEST 1
using namespace std;
char grid[1005][1005];
int lokgrid[1005][1005];
int concomp[1000005];
int n,m;
void dfs(int i, int j, int cnt)
{
    if(lokgrid[i][j]!=0)
    {
        return;
    }
    if(i==0 || j==0 || i>n || j>m)
        return;

    lokgrid[i][j] = cnt;

    dfs(i+1,j,cnt);
    dfs(i-1,j,cnt);
    dfs(i,j+1,cnt);
    dfs(i,j-1,cnt);


}
int main()
{

    sfii(n,m);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='*')
            {
                lokgrid[i][j] = -1;
            }
            else
            {
                lokgrid[i][j] = 0;
            }

        }

    }
    int cnt = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(lokgrid[i][j]==0)
            {
                dfs(i,j,cnt);
                cnt++;
            }
        }
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(lokgrid[i][j]!=-1)
            {
                concomp[ lokgrid[i][j] ]++;
            }
        }
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(grid[i][j]=='*')
            {
                int ans = 0;

                set<int>mys;
                mys.insert(lokgrid[i-1][j]);
                mys.insert(lokgrid[i+1][j]);
                mys.insert(lokgrid[i][j-1]);
                mys.insert(lokgrid[i][j+1]);

                for(auto it=mys.begin(); it!=mys.end(); it++)
                {
                    ans+=concomp[*it];
                }

                ans++;
                ans = ans%10;
                printf("%d",ans);

            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }





    return 0;
}
