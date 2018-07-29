#include <bits/stdc++.h>
 
#define pii             pair <int,int>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define MP              make_pair
#define db              double
#define ll              long long
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define VI              vector <int>
#define DBG             pf("Hi\n")
#define MOD             100007
#define MAX             100007
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long
 
 
using namespace std;
 
vector<int>graph[MAX];
int n,m,cnt;
bool visited[MAX],artpoint[MAX];
int back_edge[MAX],dis[MAX],degroot,dfsnum,root;
 
void Find_Art(int u)
{
    visited[u]=1;
    dfsnum++;
    back_edge[u]=dis[u]=dfsnum;
    loop(i,SZ(graph[u]))
    {
        int v=graph[u][i];
        if(!visited[v])
        {
            Find_Art(v);
            if(u==root)
            {
                degroot++;
                if(degroot>=2)
                {
                    artpoint[root]=1;
                }
            }
 
            back_edge[u]=min(back_edge[u],back_edge[v]);
            if(back_edge[v]>=dis[u] && u!=root)
            {
                artpoint[u]=1;
            }
 
        }
        else
            back_edge[u]=min(back_edge[u],dis[v]);
    }
}
 
void allclear()
{
    loop(i,n+5)
    {
        graph[i].clear();
        visited[i]=0;
        artpoint[i]=0;
        back_edge[i]=0;
        dis[i]=0;
    }
    cnt=dfsnum=degroot=0;
}
 
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        sff(n,m);
        allclear();
        int a,b;
        loop(i,m)
        {
            sff(a,b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
 
        root=1;
        Find_Art(1);
 
        REP(i,1,n+1)
        if(artpoint[i]) cnt++;
        PRINT_CASE;
        cout<<cnt<<endl;
    }
    return 0;
}
