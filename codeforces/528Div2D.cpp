#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;
int n,s,deg[2000005];
int main(){
    scanf("%d %d",&n,&s);
    for(int i = 1; i <= n - 1; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        deg[a] += 1;
        deg[b] += 1;
    }
    if(n == 2){
        printf("%d",s);
        exit(0);
    }
    int div = 0;
    for(int i = 1; i <= n; i++){
        div += (deg[i] == 1);
    }
    printf("%.9lf",2.0 * s / div);
    
    return 0;
}
