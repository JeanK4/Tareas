#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string minuscula(string nombre){
	string ans;
	for(int i = 0; i < nombre.size(); i++){
		if(nombre[i] >= 'A' && nombre[i] <= 'Z'){
			ans.push_back(nombre[i]+32);
		}
		else{
			ans.push_back(nombre[i]);
		}
	}
	return ans;
}

struct equipo{
	string name;	
	int points = 0;
	int games = 0;
	int goals1 = 0;
	int goals2 = 0;
	int diff = 0;

bool operator <(const equipo& eq){
	bool ans;
	if(points != eq.points)
		ans = points > eq.points;
	else if((goals1 - eq.goals1) != (goals2 - eq.goals2))
		ans = (goals1 - eq.goals1) > (goals2 - eq.goals2);
	else if(goals1 != eq.goals1)
		ans = goals1 > eq.goals1;
	else{
      ans = minuscula(name) < minuscula(eq.name);
	}
	return ans;
}

};

int main(){
	bool flag;
	char trash;
	int l, team, game, g1, g2, p1, p2;
	string equi1, equi2, N = "N/A";
	scanf("%d %d", &team, &game);
	while(team != 0 && game != 0){
		struct equipo teams[100];
		for(int i = 0; i < team; i++)
			cin >> teams[i].name;
		for(int j = 0; j < game; j++){
			flag = false;
			l = 0;
			cin >> equi1;
			cin >> g1;
			cin >> trash;
			cin >> g2;
			cin >> equi2;
 			if(g1 == g2){
				p1 = 1;
				p2 = 1;
			}
			else if(g1 > g2){
				p1 = 3;
				p2 = 0;
			}
			else{
				p1 = 0;
				p2 = 3;
			}
			while(l < team && flag == false){
				if(teams[l].name == equi1){
					teams[l].points += p1;
					teams[l].games += 1;
					teams[l].goals1 += g1;
					teams[l].goals2 += g2;
					teams[l].diff += (g1 - g2);
					flag = true;
				}
				l++;
			}
			flag = false;
			l = 0;
			while(l < team && flag == false){
				if(teams[l].name == equi2){
					teams[l].points += p2;
					teams[l].games += 1;
					teams[l].goals1 += g2;
					teams[l].goals2 += g1;
					teams[l].diff += (g2 - g1);
					flag = true;
				}	
				l++;
			}
		}
		vector<equipo> vec1(teams, teams + team);
		sort(vec1.begin(),vec1.end());
		for(int d = 0; d < vec1.size(); d++){
			if(d == 0){
				printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", d+1, vec1[d].name.c_str(), vec1[d].points, vec1[d].games, vec1[d].goals1, vec1[d].goals2, vec1[d].diff, vec1[d].points / (vec1[d].games*3.0)*100);
			}
			else if(vec1[d].points == vec1[d-1].points && (vec1[d-1].goals1 - vec1[d-1].goals2) == (vec1[d].goals1 - vec1[d].goals2) && vec1[d].goals1 == vec1[d-1].goals1){
				if(vec1[d].games == 0){
					printf("   %16s%4d%4d%4d%4d%4d%7s\n", vec1[d].name.c_str(), vec1[d].points, vec1[d].games, vec1[d].goals1, vec1[d].goals2, vec1[d].diff, N.c_str());
				}
				else{
					printf("   %16s%4d%4d%4d%4d%4d%7.2f\n", vec1[d].name.c_str(), vec1[d].points, vec1[d].games, vec1[d].goals1, vec1[d].goals2, vec1[d].diff, vec1[d].points / (vec1[d].games*3.0)*100);
				}
			}
			else{
				if(vec1[d].games == 0){
					printf("%2d.%16s%4d%4d%4d%4d%4d%7s\n", d+1, vec1[d].name.c_str(), vec1[d].points, vec1[d].games, vec1[d].goals1, vec1[d].goals2, vec1[d].diff, N.c_str());
				}
				else{
					printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", d+1, vec1[d].name.c_str(), vec1[d].points, vec1[d].games, vec1[d].goals1, vec1[d].goals2, vec1[d].diff, vec1[d].points / (vec1[d].games*3.0)*100);
				}
			}
		}
		scanf("%d %d", &team, &game);
		if(team != 0 && game != 0)
			printf("\n");
	}
	return 0;
}