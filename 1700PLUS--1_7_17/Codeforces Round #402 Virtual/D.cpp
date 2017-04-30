
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
int order[2*100005];
int n;
string tt,pp;
string tkk;
bool can(int nr)
{
    string chk = "";

    tt = tkk;

    for(int i=1;i<=nr;i++)
    {
        tt[ order[i]-1 ] = 'R';
    }

    for(int i=0;i<n;i++)
    {
        if(tt[i]!='R')
            chk.push_back(tt[i]);
    }

    ///cout<<"NR "<<nr<<endl;
    ///cout<<chk<<endl;
    ///cout<<pp<<endl;

    int ci = 0;
    for(int i=0;i<chk.length();i++)
    {
        if(chk[i]==pp[ci])
        {
            ci++;
        }
        if(ci>=pp.length())
            break;
    }




    if(ci>=pp.length())
        return true;

    return false;


}
int main()
{

    cin>>tkk>>pp;
    n = tkk.length();

    for(int i=1;i<=n;i++)
        cin>>order[i];
    //can(9);
    int lo = 0, hi = n-1;
    int ans = n;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        bool cl = can(mid);
        bool ch = can(mid+1);

        if(mid==9)
            cl = can(mid);




        if(cl && !ch)
        {
            ans = mid;
            break;
        }
        else if(cl)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }

    }

    cout<<ans<<endl;




    return 0;
}