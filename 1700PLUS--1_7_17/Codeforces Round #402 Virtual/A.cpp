
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
int ar[1005];
int br[1005];
int main()
{
    int n;
    while(cin>>n)
    {
        int on =0,tw=0,th=0,fr=0,fv=0;
        for(int i=1; i<=n; i++)
        {
            cin>>br[i];
            if(br[i]==1)
                on++;
            else if(br[i]==2)
                tw++;
            else if(br[i]==3)
                th++;
            else if(br[i]==4)
                fr++;
            else
                fv++;
        }

        int on1 = on, tw1 = tw, th1 = th, fr1 = fr,
            fv1 = fv;

        for(int i=1; i<=n; i++)
        {
            cin>>ar[i];
            if(ar[i]==1)
                on++;
            else if(ar[i]==2)
                tw++;
            else if(ar[i]==3)
                th++;
            else if(ar[i]==4)
                fr++;
            else
                fv++;
        }


        if(on%2 || tw%2 || th%2 ||
                fr%2 || fv%2)
        {
            cout<<-1<<endl;
            return 0;
        }


        int ans = 0;

        if((on/2-on1)<0)
            ans+=(on/2-on1);
        if((tw/2-tw1)<0)
            ans+=(tw/2-tw1);
        if((th/2-th1)<0)
            ans+=(th/2-th1);
        if((fr/2-fr1)<0)
            ans+=(fr/2-fr1);
        if((fv/2-fv1)<0)
            ans+=(fv/2-fv1);
        ans = abs(ans);
        cout<<ans<<endl;





    }



    return 0;
}