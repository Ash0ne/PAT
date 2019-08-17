#include<cstdio>
#include<algorithm>
using namespace std;

struct NODE
{
    int exp;
    double coe;
}nodeA[20], nodeB[20], nodeR[20];


int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%lf", &nodeA[i].exp, &nodeA[i].coe);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%d%lf", &nodeB[i].exp, &nodeB[i].coe);

    int i = 0, j = 0, k = 0;
    while(i!=n || j!=m){
        if(j == m || nodeA[i].exp > nodeB[j].exp){
            nodeR[k].exp = nodeA[i].exp;
            nodeR[k].coe = nodeA[i].coe;
            k++;i++;
        }
        else if(i == n || nodeA[i].exp < nodeB[j].exp){
            nodeR[k].exp = nodeB[j].exp;
            nodeR[k].coe = nodeB[j].coe;
            k++;j++;
        }
        else{
            nodeR[k].exp = nodeA[i].exp;
            nodeR[k].coe = nodeA[i].coe + nodeB[j].coe;
            if(nodeR[k].coe != 0.0) k++; //crack point
            i++;j++;
        }
    }
    printf("%d", k);
    for(int i = 0; i < k; i++){
        printf(" %d %.1lf", nodeR[i].exp, nodeR[i].coe);
    }
    printf("\n");
}