#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct piloto{
	int nom;
	int point;


bool operator <(const piloto& pil){
	bool ans;
		if(point != pil.point)
			ans = point > pil.point;
		else{
			ans = nom < pil.nom;
		}
	return ans;
}
};

int main(){
	int l, pos, a, posicion, z = 0;
	int gp, pilots;
	int point1, point2;
	bool flag, flag1;
	scanf("%d %d", &gp, &pilots);
	while(gp != 0 && pilots != 0){
		z += 1;
		piloto pospilots[50001];
		int x[100];
		for(int b = 0; b < gp; b++){
			for(int c = 0; c < pilots; c++){
				scanf("%d", &posicion);
				if(b == 0)
					pospilots[posicion-1].nom = c+1;
				else{
					pospilots[(pilots*b)+(posicion-1)].nom = c+1;
				}
			}
		}
		scanf("%d", &point1);
		for(int k = 0; k < point1; k++){
			for(int i = 0; i < pilots*gp; i++){
				pospilots[i].point = 0;
			}
			scanf("%d", &point2);
			for(int n = 0; n < point2; n++){
				scanf("%d", &x[n]);
			}
			for(int m = 0; m < gp; m++){
				pos = m*pilots;
				for(int j = 0; j < point2; j++){
					flag1 = false;
					if(m == 0){
						pospilots[j].point += x[j];
						}
					else{
						l = 0;
						while(l < pilots &&  flag1 == false){
							if(pospilots[pos].nom == pospilots[l].nom){
								pospilots[l].point += x[j];
								flag1 = true;
							}
							l++;			
						}
					}
					pos++;
				}
			}	
			vector<piloto> vec1(pospilots, pospilots + pilots);
			sort(vec1.begin(), vec1.end());
			a = 0;
			flag = false;
			if(vec1.size() > 1){
				while(a < vec1.size() && flag == false){
					if(vec1[a].point != vec1[a+1].point){
						printf("%d\n", vec1[a].nom);
						flag = true;
					}
					else{
						printf("%d ", vec1[a].nom);
					}
					a++;
				}
			}
			else{
				printf("%d\n", vec1[0].nom);
			}
		}
	scanf("%d %d", &gp, &pilots);
	}
	return 0;
}

