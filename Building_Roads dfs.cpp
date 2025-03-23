#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>>adj(202020);
vector<int>ans;
vector<bool>vis(202020);
 
 
void dfs(int i){
    vis[i]=true;
    for(auto it: adj[i]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
 
int main(){
    int n, m;
    cin>>n>>m;
    
        for(int j=0; j<m; j++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
            
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0; i<ans.size()-1; i++){
     
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}
