#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


char translate(string codigo){
	int i = 0;
	char ans = ' ';
	bool flag = false;
	char code[53][7] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
	                  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
	                  "..-", "...-", ".--", "-..-", "-.--", "--..","-----", ".----", "..---", 
	                  "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-",
	                  "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", 
	                  ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};

	char letter[53] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
                     '4', '5', '6', '7', '8', '9', '.', ',', '?', '\'', '!', '/', '(',
                 	 ')', '&', ':', ';', '=', '+', '-', '_', '"', '@'};

	while(i < 53 && flag == false){
		if(codigo == code[i]){
			ans = letter[i];
			flag = true;
		}
		i++;
	}
	return ans;
}

int main(){
	int casos, ct = 1, i, j;
	string ans;
	string linea, temp, trash;
	bool flag = false;
	scanf("%d\n", &casos);
	for(i = 0; i < casos; i++){
		getline(cin, linea);
		for(j = 0; j < linea.size(); j++){
			if(linea[j] != ' '){
				temp.push_back(linea[j]);
				flag = false;
			}
			else if(linea[j] == ' ' && flag == false){
				ans.push_back(translate(temp));
				temp = "";
				if(linea[j+1] == ' ' && flag == false){
					ans.push_back(' ');
					flag = true;
				}
			}
			if(j == linea.size()-1){
				ans.push_back(translate(temp));
			}	
		}
		if(i < casos-1){
			printf("Message #%d\n",ct);
			printf("%s\n\n", ans.c_str()); 
		}
		else{
			printf("Message #%d\n",ct);
			printf("%s\n", ans.c_str());
		}
		ct++;
	ans = "";
	temp = "";
	}
	return 0;
}
