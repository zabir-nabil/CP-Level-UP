#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file

#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#include <ext/pb_ds/detail/standard_policies.hpp>

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

#define INF 1000000000000000   //10e9

#define EPS 1e-9

#define flc fflush(stdout); //For interactive programs , flush while using pf (that's why __c )

#define endl "\n"

#define CONTEST 1
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

unordered_map<int,bool> exist;

ordered_set ost;
int main()
{
    CIN;
    int q;
    cin>>q;

    int cursz = 0;

    while(q--)
    {
        char cmd;
        cin>>cmd;
        int x;
        if(cmd=='I')
        {

            cin>>x;
            if(!exist[x])
            {
                ost.insert(x);
                exist[x] = 1;
                cursz++;
            }


        }
        else if(cmd=='D')
        {
            cin>>x;
            if(exist[x])
            {
                ost.erase(x);
                exist[x] = 0;
                cursz--;
            }
        }
        else if(cmd=='K')
        {
            cin>>x;
            if(x>cursz)
            {
                cout<<"invalid"<<endl;
            }
            else
            {
                cout<<*ost.find_by_order(x-1)<<endl;
            }

        }
        else
        {
            cin>>x;

                cout<<ost.order_of_key(x)<<endl;



        }


    }




    return 0;
}
