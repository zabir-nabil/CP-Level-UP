

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
int n;
ll ar[100009];
bool can(ll v)
{
    ll po = v;
    ar[0] = 0;
    for(int i=1;i<=n;i++)
    {
        ll diff = ar[i] - ar[i-1];

        if(diff>po)
        {
            return false;
        }
        else if(diff==po)
        {
            po--;
        }


    }

    return true;

}
int main()
{
    int tc,cas=0;
    sfi(tc);
    while(tc--)
    {
        sfi(n);

        loop(i,1,n)
        {
            sfl(ar[i]);
        }


        //bs

        ll lo = 0, hi = 1000000005;
        ll ans = -1;
        if(can(0))
        {
            //
            ans = 0;
        }
        if(ans==-1)
        while(lo<=hi)
        {
            ll mid = (lo+hi)/2;

            if(can(mid) && !can(mid-1))
            {
                ans = mid;
                break;
            }
            else if(can(mid))
            {
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }


        }

        CASE(cas);
        pf("%lld\n",ans);







    }



    return 0;
}
