#include <stdio.h>
#include <stdbool.h>
int main()
{
int v[10] = {2,9,4,7,6,5,8,3,10,1};
int n = sizeof(v)/4;
bool troca;
for(int i=0; i < n; i++){
    troca=false;
    for(int j=0; j < n; j++){
        if(v[j]>v[j+1]) {
            int aux=v[j+1];
            v[j+1]=v[j];
            v[j]=aux;
            troca=true;
        }
    }
    for(int i=0; i < n; i++){
        printf("%d", v[i]);
        if(i <= n-2){
            printf(" , ");
        }
    }
    printf("\n");
}
return 0;
}