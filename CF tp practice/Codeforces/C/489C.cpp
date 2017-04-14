

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
int mxdg[105];
int mndg[105];
int main()
{
    int m,s;
    while(cin>>m>>s)
    {
        if(s==0 && m==1)
        {
            cout<<0<<" "<<0<<endl;
            continue;
        }
        else if(s==0)
        {
            cout<<-1<<" "<<-1<<endl;
            continue;
        }
        int ans = 1;
        int mxs = s;
        for(int i=1; i<=m; i++)
        {
            int cd = 0;
            if(mxs>=9)
                cd = 9;
            else
                cd = mxs;
            mxdg[i] = cd;
            mxs -= mxdg[i];
            if(mxs<0)
                mxs=0;
        }

        int mns = s-1;

        for(int i=m; i>=2; i--)
        {
            int cd = 0;
            if(mns>=9)
                cd = 9;
            else
                cd = mns;
            mndg[i] = cd;
            mns -= mndg[i];
            if(mns<0)
                mns=0;

        }

        if(mns>=0)
        {
            if(mns+1<=9)
            {
                mndg[1] = mns+1;
            }
            else
            {
                ans = 0;
            }
        }
        else
        {
            ans = 0;
        }

        if(mxdg[1]<1 || mndg[1]<1)
            ans=0;

        if(ans==0)
        {
            cout<<-1<<" "<<-1<<endl;

        }
        else
        {
            for(int i=1; i<=m; i++)
                cout<<mndg[i];
            cout<<" ";
            for(int i=1; i<=m; i++)
                cout<<mxdg[i];
            cout<<endl;
        }




    }




    return 0;
}
