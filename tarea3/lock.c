#include <stdio.h>


int main(){
	int d1, d2, d3, d4, degrees, flag = 1, cases, res;
	scanf("%d %d %d %d",&d1,&d2,&d3,&d4);
	while(d1 != 0 || d2 != 0 || d3 != 0 || d4 != 0){
		cases = 3;
		degrees = 1080;
		if(cases == 3){
			if(d1 > d2){
				res = (d1 - d2)*9;
				degrees += res;
			}
			else if(d1 < d2){
				res = ((40 - d2) +d1)*9;
				degrees += res;
			}
		cases --;
		}
		if(cases == 2){
			if(d2 < d3){	
				res = (d3 - d2)*9;
				degrees += res;
			}
			else if(d2 > d3){
				res = ((40 - d2) + d3)*9;
				degrees += res;
			}
		cases --;
		}
		if(cases == 1){
			if(d3 > d4){
				res = (d3 - d4)*9;
				degrees += res;
			}
			else if(d3 < d4){
				res = (d3 + (40 - d4))*9;
				degrees += res;
			}
		cases --;
		}
		printf("%d\n",degrees);
		scanf("%d %d %d %d",&d1,&d2,&d3,&d4);
	}
	return 0;
}
