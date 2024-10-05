#define name Spy007
#include <bits/stdc++.h>

using namespace std;

const int nmax=2e5;

int n;
int a[nmax+5];
long long Result;
long long cnt[nmax+5], IT[4*nmax+5], pos[nmax+5], Sum[nmax+5];
vector <int> val;

void update_IT(int l, int r, int node, int pos, long long val)
{
    if (l>r || pos>r || pos<l) return;
    if (l==r)
    {
        IT[node]+=val;
        return;
    }
    int mid=(l+r)/2;
    update_IT(l,mid,node*2,pos,val);
    update_IT(mid+1,r,node*2+1,pos,val);
    IT[node]=IT[node*2]+IT[node*2+1];
}

long long get_IT(int l, int r, int node, int u, int v)
{
    if (l>r || u>v || u>r || v<l) return 1ll*0;
    if (u<=l && r<=v) return IT[node];
    int mid=(l+r)/2;
    return (get_IT(l,mid,node*2,u,v)+get_IT(mid+1,r,node*2+1,u,v));
}

vector <int> Number_Compression(vector <int> val)
{
    vector <int> ans;
    sort(val.begin(),val.end());
    ans.push_back(val[0]);
    for (int i=1;i<val.size();i++)
    if (val[i]!=val[i-1]) ans.push_back(val[i]);
    return ans;
}

void Input(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        val.push_back(a[i]);
    }
    val=Number_Compression(val);
}

void Solve(void)
{
    for (int i=1;i<=n;i++)
    {
        int loc;
        loc=lower_bound(val.begin(),val.end(),a[i])-val.begin()+1;
        long long Temp=get_IT(1,n,1,1,loc-1)+get_IT(1,n,1,loc+1,val.size());

        if (pos[loc]!=0 && i-pos[loc]>1)
        {
            Sum[loc]+=(i-pos[loc]-1)*cnt[loc];
        }

        Temp-=Sum[loc];
        Result+=Temp;

        cnt[loc]++;
        pos[loc]=i;
        Temp=i-cnt[loc];
        update_IT(1,n,1,loc,Temp);
    }
    cout<<Result<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("INPUT.inp","r",stdin);
    //freopen("INPUT.out","w",stdout);
    Input();
    Solve();
    return 0;
}