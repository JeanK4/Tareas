#include <stdio.h>


int main(){
	int i = 0, k, dpx, dpy, flag = 1;
	scanf("%d",&k);
	scanf("%d %d",&dpx,&dpy);
	while(k != 0){
		int a, b;
		if(flag == 0){
			scanf("%d %d",&dpx,&dpy);
		}
		for(i = 0; i < k ; i++){
			scanf("%d %d",&a,&b);
			if(a == dpx || b == dpy){
				printf("divisa\n");
			}
			else if(a < dpx && b > dpy){
				printf("NO\n");
			}
			else if(a > dpx && b > dpy){
				printf("NE\n");
			}
			else if(a < dpx && b < dpy){
				printf("SO\n");
			}
			else{
				printf("SE\n");
			}
		}
		flag = 0;
		scanf("%d",&k);
	}
	return 0;
}