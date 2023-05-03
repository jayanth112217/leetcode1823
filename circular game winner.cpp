class Solution {
    private:
     bool isover(vector<int>&vis,int n){
         int cnt=0;
       for(int i=0;i<n;i++){
           if(vis[i]==0) cnt++;
       }
       if(cnt==1) return true;
       return false;
     }
   private:
    int targetindex(vector<int>&vis,int n){
        for(int i=0;i<n;i++){
            if(vis[i]==0) {
                return i+1;
            }
        }
        return 0;
    }
public:
    int findTheWinner(int n, int k) {
      if(n==1 && k==1) return 1;
      vector<int>vis;
      for(int i=0;i<n;i++){
          vis.push_back(0);
      }
      int i=k-1;
      vis[i]=1;
      while(!isover(vis,n)){
       int temp = i;
       int cnt = 0;
       int ind;
       while(1){
          if(temp==n) temp=0;
          if(cnt==k-1) {
              ind=temp;
              break;
          }
          if(vis[temp]==0) {
              cnt++;
              if(temp==n-1) temp=0;
              else temp++;
              while(vis[temp]==1){
                  if(temp==n-1) temp=0;
                  else temp++;
              }
          }
           else temp++; 
       }
       vis[ind] = 1;
       cout<<ind<<endl;
       int flag=ind;
       while(vis[flag]==1){
          if(flag==n-1) flag=0;
          else flag++; 
       }
       i=flag;
      }
      return targetindex(vis,n);
    }
};