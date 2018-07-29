#include <bits/stdc++.h>
 
#define pii pair <int,int>
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
#define ms(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define oo 1<<29
#define dd double
#define ll long long
#define EPS 10E-10
#define ff first
#define ss second
#define MAX 1000007
#define CIN ios_base::sync_with_stdio(0)
#define SZ(a) (int)a.size()
#define getint(a) scanf("%d",&a)
#define getint2(a,b) scanf("%d%d",&a,&b)
#define getint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define loop(i,n) for(int i=0;i<n;i++)
#define TEST_CASE(t) for(int z=1;z<=t;z++)
#define PRINT_CASE printf("Case %d: ",z)
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define inf 1000000
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define I int
 
using namespace std;
 
/* Bits operation */
int Set(int n,int pos)  { return n = n | 1<<pos;}
bool check(int n,int pos) { return n & 1<<pos;}
int Reset(int n, int pos) { return n=n & ~(1<<pos);}
/*----------------*/
 
 int lps[MAX];
 
 void computePrefixFunction(string P)
 {
     int n=SZ(P);
     int k=-1;
     lps[0]=-1;
     for(int i=1;i<n;i++)
     {
         while(k>-1 && P[i]!=P[k+1])
            k=lps[k];
         if(P[i]==P[k+1])
            k++;
         lps[i]=k;
     }
 }
 
 void KMP(string& T, string& P)
 {
     int m=SZ(P);
     int n=SZ(T);
     computePrefixFunction(P);
     int k=-1;
     for(int i=0;i<n;i++)
     {
         while(k>-1 && T[i]!=P[k+1])
            k=lps[k];
         if(T[i]==P[k+1])
            k++;
         if(k==m-1)
         {
             cout<<"Pattern found in position "<<i-k<<endl;
             k=lps[k];
         }
     }
 }
 
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    string text,pattarn;
    while(cin>>text>>pattarn)
    {
        KMP(text,pattarn);
    }
    return 0;
}
