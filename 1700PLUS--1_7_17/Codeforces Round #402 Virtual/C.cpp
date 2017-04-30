
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
ll ar[2*100006];
ll br[2*100006];
struct dp
{
    ll diff;
    int idx;
};
dp diff[2*100005];
bool cp(dp d1,dp d2)
{
    return d1.diff>d2.diff;
}
int n,k;
int main()
{

    cin>>n>>k;

    for(int i=1; i<=n; i++)
        sfl(ar[i]);

    for(int i=1; i<=n; i++)
        sfl(br[i]);


    for(int i=1; i<=n; i++)
    {
        diff[i].diff = -(ar[i] - br[i]);
        diff[i].idx = i;
    }


    sort(diff+1,diff+n+1,cp);

    ll ans = 0;

    for(int i=1; i<=k; i++)
    {
        ans += ar[ diff[i].idx ];

    }

    for(int i=k+1; i<=n; i++)
    {
        if(diff[i].diff>=0)
        {
            ans += ar[ diff[i].idx ];
        }
        else

        {
            ans += br[ diff[i].idx ];
        }
    }





    cout<<ans<<endl;
    return 0;
}