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
int yn[55];
int rcn[55];
int  sola[55];
string fun(int iaa)
{
    string ss;
    ss.push_back('A');

    int nz = ceil(iaa*1.00/26.00);

    for(int i=1; i<=nz; i++)
    {
        ss.pb( ('a'+((iaa+i)-1)%26 ) );
    }

    return ss;

}
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        for(int i=1; i<=n-k+1; i++)
        {
            string s;
            cin>>s;
            if(s=="YES")
                yn[i] = 1;
            else
                yn[i] = 0;

        }


        for(int i=1; i<=n-k+1; i++)
        {
            rcn[i] = 0;
            int cnt = 0;
            for(int j=i+1; j<=n; j++)
            {
                if(yn[j]==1)
                    break;
                else
                    cnt++;
            }

            rcn[i] = cnt;

        }


        if(yn[1])
        {
            for(int i=1; i<=k; i++)
                sola[i] = i;
        }
        else
        {
            for(int i=1; i<=k; i++)
                sola[i] = i;

            int cov = rcn[1];
            if(cov>k-2)
            {
                cov = k-2;
            }

            sola[cov+2] = sola[cov+1];
        }


        for(int ii=k+1; ii<=n; ii++)
        {
            int ni = ii-k+1;
            if(yn[ni])
            {
                sola[ii] = ii;
            }
            else
            {
                if(yn[ni-1])
                {
                    int cov = rcn[ni];
                    if(cov>k-2)
                    {
                        cov = k-2;
                    }

                    sola[ii] = sola[ii-k+cov+1];

                }
                else
                {
                    sola[ii] = ii;
                }

            }


        }

        for(int i=k+1; i<=n; i++)
        {
            int state = 1;
            map<int, int>th;
            for(int j=i-1; j>=(i-k); j--)
            {
                if(th[ sola[j] ])
                {
                    state = 0;
                    th.clear();
                    break;
                }
                sola[j] = 1;
            }

            th.clear();
            int ni = i-k+1;
            if(yn[ni])
            {
                sola[i] = i;
            }
            else
            {
                sola[i] = sola[i-k+2];
            }



        }


        for(int i=1;i<=k;i++)
        {
            sola[i] = i;
        }

        if(yn[1]==0)
        {
            sola[1] = sola[2];
        }

        for(int i=k+1;i<=n;i++)
        {
            int ni = i-k+1;
            if(yn[ni])
            {
                sola[i] = i;
            }
            else
            {
                sola[i] = sola[ni];
            }

        }

        if(k==2)
        {

            sola[1] = 1;

            for(int i=2; i<=n; i++)
            {
                if(yn[i-1])
                {
                    sola[i] = i;
                }
                else
                {
                    sola[i] = sola[i-1];
                }
            }



        }

        for(int i=1; i<=n; i++)
            cout<<fun(sola[i])<<" ";
        cout<<endl;



    }

    return 0;
}