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
int offlineq_li[100001];
int offlineq_ri[100001];
int wall[2*100002];
bool there[100002];
set<int>range_tree;
int main()
{
    int tc,cas=0;
    sfi(tc);

    while(tc--)
    {
        sfi(n);

        for(int i=1; i<=n; i++)
        {
            sfii(offlineq_li[i],
                 offlineq_ri[i]);
        }

        for(int i=1; i<=2*n; i++)
            range_tree.insert(i);

        for(int qi=n; qi>=1; qi--)
        {
            int li = offlineq_li[qi];
            int ri = offlineq_ri[qi];

            //poster num = qi

            if(range_tree.empty())
                break;

            set<int>::iterator it =
                range_tree.lower_bound(li);

            vector<int>todel;

            for(set<int>::iterator itr=it; itr!=range_tree.end(); itr++)
            {
                int cnp = *itr;

                if(cnp>ri)
                    break;

                if(wall[cnp]==0)
                    wall[cnp] = qi;


                todel.pb(cnp);




            }

            for(int i=0; i<todel.size(); i++)
                range_tree.erase(todel[i]);

            todel.clear();




        }

        int num_poster = 0;

        for(int i=1; i<=2*n; i++)
        {
            int status =  wall[i];
            if(status==0)
                continue;
            if(!there[status])
            {
                num_poster++;
                there[ wall[i] ] = true;
            }
        }

        CASE(cas);
        pf("%d\n",num_poster);



        ms(wall,0);
        ms(there,false);
        range_tree.clear();
    }

    return 0;
}
