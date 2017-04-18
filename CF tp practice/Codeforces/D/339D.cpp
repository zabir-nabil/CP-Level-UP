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
int n,m;
ll ar[150000];
ll tree[4*150000];
void build_tree(int root, int b, int e, int lev)
{
    if(lev==0)
    {
        tree[root] = ar[b];
        return;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc + 1;

    build_tree(lc,b,mid,lev-1);
    build_tree(rc,mid+1,e,lev-1);


    if(lev%2) // or case
    {
        tree[root] = (tree[lc]|tree[rc]);
    }
    else
    {
        tree[root] = (tree[lc]^tree[rc]);
    }


}
void update(int root, int b, int e,
            int lev, int pos, int val)
{
    if(b>pos || e<pos)
    {
        return;
    }
    else if(b==e && pos==b)
    {
        tree[root] = val;
        return;
    }

    int mid = (b+e)/2;
    int lc = root*2;
    int rc = lc + 1;

    update(lc,b,mid,lev-1,pos,val);
    update(rc,mid+1,e,lev-1,pos,val);


    if(lev%2) // or case
    {
        tree[root] = (tree[lc]|tree[rc]);
    }
    else
    {
        tree[root] = (tree[lc]^tree[rc]);
    }




}
int main()
{

    while(cin>>n>>m)
    {
        int nm = 1;

        for(int i=1; i<=n; i++)
            nm *=2;

        for(int i=1; i<=nm; i++)
        {
            sfl(ar[i]);
        }

        build_tree(1,1,nm,n);

        while(m--)
        {
            int p;
            ll nv;
            sfi(p);
            sfl(nv);

            update(1,1,nm,n,p,nv);

            pf("%lld\n",tree[1]);


        }


    }



    return 0;
}
