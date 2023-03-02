#include <stdio.h>
#include <math.h>


int main(){
int i, cantidad, ans, flag, arreglo[3000];
    while(scanf("%d", &cantidad) != EOF){
        i = 0;
        flag = 0;
        while(i < cantidad){
            scanf("%d", &arreglo[i]);
            if(i > 0 && flag == 0){
                ans = fabs(arreglo[i] - arreglo[i-1]);
                if(ans >= cantidad){
                    flag = 1;
                }
            }
            i++;           
        }
        if(flag == 0){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }
    }
    return 0;
}