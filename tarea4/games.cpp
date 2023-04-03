#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int people, l, m, tam;
	string x, y;
	bool z, flag1, flag2;
	string ans, ans1;
	scanf("%d", &people);
	string arreglo[1000];
	while(people != 0){
		l = 0;
		m = 0;
		flag1 = false;
		flag2 = false;
		for(int i = 0; i < people; i++){
			cin >> arreglo[i];
		}
		vector<string> vec1(arreglo, arreglo + people);
		sort(vec1.begin(), vec1.end());
		x = vec1[(people / 2) - 1];
		y = vec1[(people / 2)];
		//cout << x << "  " << y << endl;
		z = (x.size() < y.size());
		if((x[0]+1) == y[0] && x.size() > y.size()){
			while(flag1 == false){
				if(x[l] == 'Z'){
					ans.push_back('Z');
				}
				else if(x[l] != y[l] && x[l]+1 == y[l]){
					ans.push_back(x[l]);
				}
				else if(x[l] != y[l]){             			
					ans.push_back(x[l]+1);		   
					flag1 = true;
				}
				l++;
			}
			ans1.push_back(y[0]);
			if(ans1.size() < y.size() && ans1 > ans){
				ans = "";
				ans.push_back(y[0]);
			}
			else if(ans.size() == x.size() && ans > x){
				ans = x;
			}
		}
		else if(z == true){
			if(x.size() == 1){
				ans.push_back(x[0]);
			}
			else{
				tam = x.size();
				while(m < tam && flag2 == false){
					if(x[m] == 'Z'){
						ans.push_back('Z');
					}
					else if(x[m] != y[m]){
						ans.push_back(x[m]+1);
						flag2 = true;
					}
					else{
						ans.push_back(x[m]);
					}
					m++;
				}
			}
			if(ans.size() == x.size() && x < ans){
				ans = x;
			}
		}
		else if(z == false){
			tam = x.size();
			while(m < tam && flag2 == false){
				if(x[m] == 'Z'){
					ans.push_back('Z');
				}
				else if(x[m] != y[m] && x[m]+1 == y[m] && ans.size()+1 == y.size()){
					ans.push_back(x[m]);
					flag2 = true;
				}
				else if(x[m] != y[m]){
					ans.push_back(x[m]+1);
					flag2 = true;
				}
				else{
					ans.push_back(x[m]);
				}
				m++;
			}
			if(ans.size() == x.size() && ans > x){
				ans = x;
			}
			else if(ans.size() == y.size() && ans < x){
				if(x[m]+1 > 'Z'){
					ans.push_back('Z');
				}
				else{
				ans.push_back(x[m]+1);	
				}
				if(ans.size() == x.size() && ans > x){
					ans.pop_back();
					ans.push_back(x[m]);
				}
				else if(ans.size() < x.size() && ans < x){
					if(x[m]+1 > 'Z'){
						ans.push_back('Z');
					}
					else{
						ans.push_back(x[m]+1);	
					}
				}
				if(ans.size() == x.size() && ans > x){
					ans = x;
				}
			}
		}
		cout << ans << endl;
		ans = "";
		ans1 = "";
		scanf("%d", &people);
	}
	return 0;
}