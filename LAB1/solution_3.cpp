#include<cstdio>
#include <iostream>
#include <ostream>
const int maxn = 2005;
long long matrix[maxn][maxn];
long long rowsum[maxn][maxn];
int main(){
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%lld",&matrix[i][j]);
        }
    }
    for(int i=0;i<=n;++i){
        rowsum[i][0] = 0;
    }
    for(int j=0;j<=m;++j){
        rowsum[0][j] = 0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            rowsum[i][j] = rowsum[i][j-1]+rowsum[i-1][j] -rowsum[i-1][j-1]  + matrix[i][j];
        }
    }
  /*  for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            printf("%d ",rowsum[i][j]);

        }
        printf("\n");
    }*/
    scanf("%d",&q);

    for(int i=1;i<=q;++i){
        int x,y,a,b;
        scanf("%d %d %d %d",&x,&y,&a,&b);
        long long ans = rowsum[x+a-1][y+b-1]+rowsum[x-1][y-1]-rowsum[x-1][y+b-1]-rowsum[x+a-1][y-1];
        printf("%lld\n",ans);
    }
    return 0;
}
