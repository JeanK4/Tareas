#include <stdio.h>


int main(){
	int i, j, casos, tiendas, ans = 0, ct;
	scanf("%d",&casos);
	for(j = 0; j < casos; j++){
		scanf("%d",&tiendas);
		int menor = 100, mayor = -2;
		for(i = 0; i < tiendas; i++){
			scanf("%d",&ct);
			if(ct < menor){
				menor = ct;
			}
			if(ct > mayor){
				mayor = ct;
			}
		}
		ans = (mayor - menor) * 2;
		printf("%d\n", ans);
		}
	return 0;
}