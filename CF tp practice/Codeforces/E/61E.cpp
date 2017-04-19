

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


#define Nm 1000009
map<ll,int>mper;
ll tree2[Nm+5];
ll tree3[Nm+5];
ll sol2[Nm+5];
ll ar[Nm];

void update2(int pos)
{
    while(pos<=Nm)
    {
        tree2[pos]++;
        pos += (pos&(-pos));
    }

}
ll query2(int pos)
{
    ll sum = 0;
    while(pos>0)
    {
        sum+=tree2[pos];
        pos-=(pos&(-pos));
    }

    return sum;

}

void update3(int pos,ll v)
{
    while(pos<=Nm)
    {
        tree3[pos]+=v;
        pos += (pos&(-pos));
    }

}
ll query3(int pos)
{
    ll sum = 0;
    while(pos>0)
    {
        sum+=tree3[pos];
        pos-=(pos&(-pos));
    }

    return sum;

}
int main()
{
    int n;
    sfi(n);

    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        sfl(ar[i]);
        sol2[i] = ar[i];
    }

    sort(sol2+1,sol2+n+1);

    for(int i=1;i<=n;i++)
    {
        mper[ sol2[i] ] = ++cnt;
    }

    for(int i=n;i>=1;i--)
    {
        int mpv = mper[ ar[i] ];
        ll q = query2(mpv-1);
        sol2[i] = q;
        update2(mpv);
    }
    ll ans =0;
    for(int i=n;i>=1;i--)
    {
        int mpv = mper[ ar[i] ];
        ll q = query3(mpv-1);
        ans+=q;
        update3(mpv,sol2[i]);


    }

    cout<<ans<<endl;

    //



    return 0;
}
