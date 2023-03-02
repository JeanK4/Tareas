#include <stdio.h>

int main(){
	int i, j, n, casos, pos1, pos2, suma, gasolinera, gaso1[100001], gaso2[100001];
	scanf("%d", &casos);
	for(i = 0; i < casos; i++){
		scanf("%d", &gasolinera);
		for(j = 0; j < gasolinera*2; j++){
			if(j < gasolinera){
			scanf("%d", &gaso1[j]);
			}
			else{
			scanf("%d", &gaso2[j-gasolinera]);
			}
		}
		suma = 0;
		pos1 = 0;
		pos2 = 0;
		for(n = 0; n < gasolinera; n++){
			suma += gaso1[n] - gaso2[n];
			if(suma < 0){
				pos1 = n+1;
				pos2 += suma;
				suma = 0;
			}
		}
		if(suma + pos2 < 0){
			printf("Case %d: Not possible\n", i+1);
		}
		else{
			printf("Case %d: Possible from station %d\n", i+1, pos1+1);
		}
	}
	return 0;
}	