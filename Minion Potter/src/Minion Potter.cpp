//============================================================================
// Name        : Minion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

char field[7][7]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
struct minion { string name; int numOfBananas;}player[3];
char moveplayer;
int temp1,temp2;
int posxbanana, posybanana,posxbomb,posybomb;
int score;

void clear(){
	for (int i=0; i<7; i++){
		for (int j=0; j<7; j++){
			if (field[i][j]=='J' || field[i][j]=='X'){
				field[i][j]=' ';
			}
		}
	}
}
void board(){
	for (int i=0; i<7; i++){
		for (int j=0; j<7; j++){
			cout<<field[i][j]<<" ";
		}
		cout<<endl;
	}
	field[temp1][temp2]='O';
}
void moveplay(){
	field[temp1][temp2]=' ';
	if (moveplayer=='a'){
		if (temp2!=0){
			field[temp1][temp2-1]='O';
			temp2=temp2-1;
		}
		if (temp2==0){
			field[temp1][temp2]='O';
		}
	}
	if (moveplayer=='d'){
		if (temp2!=6){
			field[temp1][temp2+1]='O';
			temp2=temp2+1;
		}
		if (temp2==6){
			field[temp1][temp2]='O';
		}
	}
}
void spawn(){
	posxbanana = rand() % 7;
	posybanana=0;
	if (field[posybanana][posxbanana]==' ')
		field[posybanana][posxbanana]='J';
	posxbomb = rand() % 7;
	posybomb=0;
	int chance = rand() % 3;
	if (chance == 0){
		if (field[posybomb][posxbomb]==' ')
			field[posybomb][posxbomb]='X';
	}
}
void move(){
	for (int i=6; i>=0; i--){
		for (int j=0; j<7; j++){
			if (field[i][j]=='J'){
				field[i][j]=' ';
				field[i+1][j]='1';
			}
			else if (field[i][j]=='X'){
				field[i][j]=' ';
				field[i+1][j]='2';
			}
		}
	}
	for (int i=6; i>=0; i--){
		for (int j=0; j<7; j++){
			if (field[i][j]=='1'){
				field[i][j]='J';
			}
			else if (field[i][j]=='2'){
				field[i][j]='X';
			}
		}
	}
}
void setscore(){
	if (field[temp1][temp2]=='J'){
		field[temp1][temp2]='O';
		score++;
	}
	else if(field[temp1][temp2]=='X'){
		field[temp1][temp2]='O';
		score=0;
		cout<<"Boom your bananas have been blasted"<<endl;
	}
	cout<<"score = "<<score<<endl;
}
void highscore(){
	if (player[0].numOfBananas>player[1].numOfBananas && player[0].numOfBananas>player[2].numOfBananas){
		cout<<player[0].name<<" got the highest score with "<<player[0].numOfBananas<<" bananas"<<endl;
	}
	else if (player[1].numOfBananas>player[0].numOfBananas && player[1].numOfBananas>player[2].numOfBananas){
		cout<<player[1].name<<" got the highest score with "<<player[1].numOfBananas<<" bananas"<<endl;
	}
	if (player[2].numOfBananas>player[1].numOfBananas && player[2].numOfBananas>player[0].numOfBananas){
			cout<<player[2].name<<" got the highest score with "<<player[2].numOfBananas<<" bananas"<<endl;
		}
}
int main() {
	srand (time(NULL));
	int a=1;

	do{
		score=0;
		temp1=6;
		temp2=3;
		field[temp1][temp2]='O';
		cout<<"Player number = "<<a<<endl;
		cout<<"Enter your name : ";
		cin>>player[a-1].name;
		cout<<endl;
	    int seconds;

	    cout << "Enter the number of seconds: ";
	    cin >> seconds;
	    cout << "Start ... " << endl << flush;

	    time_t start_time = time(nullptr);

	    while ( (time(nullptr) - start_time) < seconds){
			board();
			cout<<"Enter your choice of directions (a/d)";
			cin>>moveplayer;
			if (moveplayer=='a' || moveplayer=='d'){
				moveplay();
			}
			cout<<endl;
			move();
			cout<<endl;
			spawn();
			setscore();
	    }
	    cout << "Time's up!" << endl;
		board();
		player[a-1].numOfBananas=score;
		cout<<player[a-1].name<<" got "<<player[a-1].numOfBananas<<" bananas"<<endl;
		field[temp1][temp2]=' ';
		a++;
		cout<<endl;
		clear();
	}
	while(a<4);
	highscore();
	return 0;
}


//#include <iostream>
//#include <time.h>
//#include <fstream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//char field[7][7]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
//struct minion { string name; int numOfBananas;}player[3];
//
//void clear(){
//	for (int i=0; i<7; i++){
//		for (int j=0; j<7; j++){
//			if (field[i][j]=='J' || field[i][j]=='X'){
//				field[i][j]=' ';
//			}
//		}
//	}
//}
//void board(int temp1, int temp2){
//	for (int i=0; i<7; i++){
//		for (int j=0; j<7; j++){
//			cout<<field[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	field[temp1][temp2]='O';
//}
//void moveplay(int temp1, int temp2, char moveplayer){
//	field[temp1][temp2]=' ';
//	if (moveplayer=='a'){
//		if (temp2!=0){
//			field[temp1][temp2-1]='O';
//			temp2=temp2-1;
//		}
//		if (temp2==0){
//			field[temp1][temp2]='O';
//		}
//	}
//	if (moveplayer=='d'){
//		if (temp2!=6){
//			field[temp1][temp2+1]='O';
//			temp2=temp2+1;
//		}
//		if (temp2==6){
//			field[temp1][temp2]='O';
//		}
//	}
//}
//void spawn(int posxbanana, int posybanana, int posxbomb, int posybomb){
//	posxbanana = rand() % 7;
//	posybanana=0;
//	if (field[posybanana][posxbanana]==' ')
//		field[posybanana][posxbanana]='J';
//	posxbomb = rand() % 7;
//	posybomb=0;
//	int chance = rand() % 3;
//	if (chance == 0){
//		if (field[posybomb][posxbomb]==' ')
//			field[posybomb][posxbomb]='X';
//	}
//}
//void move(){
//	for (int i=6; i>=0; i--){
//		for (int j=0; j<7; j++){
//			if (field[i][j]=='J'){
//				field[i][j]=' ';
//				field[i+1][j]='1';
//			}
//			else if (field[i][j]=='X'){
//				field[i][j]=' ';
//				field[i+1][j]='2';
//			}
//		}
//	}
//	for (int i=6; i>=0; i--){
//		for (int j=0; j<7; j++){
//			if (field[i][j]=='1'){
//				field[i][j]='J';
//			}
//			else if (field[i][j]=='2'){
//				field[i][j]='X';
//			}
//		}
//	}
//}
//void setscore(int temp1, int temp2, int score){
//	if (field[temp1][temp2]=='J'){
//		field[temp1][temp2]='O';
//		score++;
//	}
//	else if(field[temp1][temp2]=='X'){
//		field[temp1][temp2]='O';
//		score=0;
//		cout<<"Boom your bananas have been blasted"<<endl;
//	}
//	cout<<"score = "<<score<<endl;
//}
//void highscore(){
//	if (player[0].numOfBananas>player[1].numOfBananas && player[0].numOfBananas>player[2].numOfBananas){
//		cout<<player[0].name<<" got the highest score with "<<player[0].numOfBananas<<" bananas"<<endl;
//	}
//	else if (player[1].numOfBananas>player[0].numOfBananas && player[1].numOfBananas>player[2].numOfBananas){
//		cout<<player[1].name<<" got the highest score with "<<player[1].numOfBananas<<" bananas"<<endl;
//	}
//	if (player[2].numOfBananas>player[1].numOfBananas && player[2].numOfBananas>player[0].numOfBananas){
//			cout<<player[2].name<<" got the highest score with "<<player[2].numOfBananas<<" bananas"<<endl;
//		}
//}
//int main() {
//	srand (time(NULL));
//	int a=1;
//	char moveplayer;
//	int temp1,temp2;
//	int posxbanana, posybanana,posxbomb,posybomb;
//	int score;
//	do{
//		score=0;
//		temp1=6;
//		temp2=3;
//		field[temp1][temp2]='O';
//		cout<<"Player number = "<<a<<endl;
//		cout<<"Enter your name : ";
//		cin>>player[a-1].name;
//		cout<<endl;
//	    int seconds;
//
//	    cout << "Enter the number of seconds: ";
//	    cin >> seconds;
//	    cout << "Start ... " << endl << flush;
//
//	    time_t start_time = time(nullptr);
//
//	    while ( (time(nullptr) - start_time) < seconds){
//			board(temp1, temp2);
//			cout<<"Enter your choice of directions (a/d)";
//			cin>>moveplayer;
//			if (moveplayer=='a' || moveplayer=='d'){
//				moveplay(temp1, temp2, moveplayer);
//			}
//			cout<<endl;
//			move();
//			cout<<endl;
//			spawn(posxbanana, posybanana, posxbomb, posybomb);
//			setscore(temp1, temp2, score);
//	    }
//	    cout << "Time's up!" << endl;
//		board(temp1, temp2);
//		player[a-1].numOfBananas=score;
//		cout<<player[a-1].name<<" got "<<player[a-1].numOfBananas<<" bananas"<<endl;
//		field[temp1][temp2]=' ';
//		a++;
//		cout<<endl;
//		clear();
//	}
//	while(a<4);
//	highscore();
//	return 0;
//}
