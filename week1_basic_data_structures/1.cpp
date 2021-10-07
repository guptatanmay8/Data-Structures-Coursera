#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define sz(a) (int)(a.size())
#define pb push_back
#define all(c) c.begin(),c.end()
#define tr(it,a,c) for(auto it=c.begin()+a;it!=c.end();it++)
#define fr(i,a,n)   for(int i=a;i<n;i++)
#define present(c,x) (c.find(x)!=c.end()) //for set/map etc.
#define cpresent(c,x) (find(all(c),x)!=c.end())
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vp;
int N=100001;
int mod=1e9+7;


int min(int a,int b){if(a<b) return a; else return b;}
int max(int a,int b){if(a>b) return a; else return b;}
int power(int a,int b){int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int p, int q){if(p%q==0) return q; else{return gcd(q,p%q);}} 
bool comp(int a, int b) 
{ 
    return (a > b); 
}

bool comp1(pi a, pi b)
{
    if(a.first==b.first)return a.second<b.second;
    else return a.first>b.first;
}

template<typename T> 
istream& operator>>(istream& in, vector<T>& v)
{
    for (T& x : v) in >> x; return in;
}

template<typename T> 
ostream& operator<<(ostream& out, vector<T>& v)
{
    for (T& x : v) out << x<<" "; return out;
}

// template<typename T>
int sum1(vector<int>& v)
{
    int sum=0;
    // for(auto x: v)sum+=x;
    fr(i,0,v.size())sum+=v[i];
    return sum;
}

bool checkdivision(string s1,string s2)
{
    if(s2.size()%s1.size()!=0)return false;
    fr(i,0,s2.size()/s1.size())
    {
        fr(j,0,s1.size())
        {
            if(s2[s1.size()*i+j]!=s1[j])
            {
                return false;
            }
        }
    }
    return true;
}

// bool isprime(int n)
// {
//     if(n==1)return false;
//     if(n==2||n==3)return true;
//     if(n>3)
//     {
//         fr(i,2,sqrt(n)+1)
//         {
//             if(n%i==0)return false;
//         }
//         return true;
//     }

// }

// int ischeck(vi v)
// {
//     fr(i,1,v.size())
//     {
        
//         if(v[i]<v[i-1])return 0;
//         v[i]= v[i]-v[i-1];
//         v[i-1]=0;

//     }
//     if(v.back()==0)return 1;
//     return 0;

// }

vi SieveOfEratosthenes(int n)
{
    // Create a boolean array 
    // "prime[0..n]" and initialize
    // all entries it as true. 
    // A value in prime[i] will
    // finally be false if i is 
    // Not a prime, else true.
    vi prime(n + 1,1);
    // memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, 
        // then it is a prime
        if (prime[p] == 1) 
        {
            // Update all multiples 
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple 
            // of p and are less than p^2 
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
      
        }
    }
    return prime;
 
}

 void solve()
{
    string s;
    cin>>s;
    // cout<<s;
    stack<pair<char,int>> s1;
    int n=s.size();
    fr(i,0,n)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {   
            s1.push({s[i],i+1});

        }
        else if(s[i]=='}')
        {
            pair<char,int> p1 = s1.top();
            if(p1.first=='{')
            {
                s1.pop();
            }
            else
            {
                cout<<i+1;
                return;
            }
        }
        else if(s[i]==']')
        {
            pair<char,int> p1 = s1.top();
            if(p1.first=='[')
            {
                s1.pop();
            }
            else
            {
                cout<<i+1;
                return;
            }
        }
        else if(s[i]==')')
        {
            pair<char,int> p1 = s1.top();
            if(p1.first=='(')
            {
                s1.pop();
            }
            else
            {
                cout<<i+1;
                return;
            }
        }

    }
    if(s1.size()==0)
    {
        cout<<"Success";
    }
    else
    {
        cout<<s1.top().second;
    }


}

signed main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    // vi prime(1e6 + 1,1);
    // // memset(prime, true, sizeof(prime));
 
    // for (int p = 2; p * p <= 1e6; p++)
    // {
    //     // If prime[p] is not changed, 
    //     // then it is a prime
    //     if (prime[p] == 1) 
    //     {
    //         // Update all multiples 
    //         // of p greater than or
    //         // equal to the square of it
    //         // numbers which are multiple 
    //         // of p and are less than p^2 
    //         // are already been marked.
    //         for (int i = p * p; i <= 1e6; i += p)
    //             prime[i] = 0;
      
    //     }
    // }
    // return prime;
    // cout<<prime[79];
    // int t;
    // cin>>t;
    // while(t--)
    // {
    //     solve();
    //     // cout<<endl;
        
    // }
    solve();
    return 0;   
}   
x