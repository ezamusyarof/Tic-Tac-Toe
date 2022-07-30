#include <iostream>
#include <Windows.h>
using namespace std;

int table[9];
string mark[9] = {" "," "," "," "," "," "," "," "," "};
int num=0;
int skor_kamu=0;
int skor_aku=0;
int game_sesion=0;

void menu();
void tampilan();
void game();
void pemenang();

void strategi(int x, int y, int z, int cur){
	if(mark[x]=="O"&&mark[y]=="O"&&num==cur&&mark[z]==" "){
		table[num]=z+1;
		mark[z]="X";
		num++;
	}
}

void strategi1(int x, int y, int z, int cur){
	if(mark[x]=="X"&&mark[y]=="X"&&num==cur&&mark[z]==" "){
		table[num]=z+1;
		mark[z]="X";
		num++;
	}
}

void kamu(){
	int user;
	cout << "       GILIRAN KAMU '_'" << endl;
	cout << "       Masukkan nomor => ";
	cin >> user;
	if(user==0||user>9){
		tampilan(); cout << endl; kamu();
	}else{
		for(int k=0; k<9; k++){
			if(table[k]==user){
				tampilan(); cout << endl; kamu(); break;
			}else if(k==8){
				table[num]=user;
				mark[user-1]="O";
				num++;
				tampilan();
				pemenang();
				break;
			}
		}
	}
}

void aku(){
	cout << "       GILIRANKU :)" << endl;
	cout << "       Tunggu, lagi mikir ..." << endl;
	Sleep(500);
	if(num!=9){
		game();
	}
	tampilan(); 
	pemenang();
}

void menu(){
	game_sesion++;
	num = 0;
	for(int i=0; i<9; i++){
		table[i]=0;
		mark[i]=" ";
	}
	
	for(int i=0; true; i++){
		system("cls");
		tampilan();
		while(true){
			tampilan();
			cout << endl;
			if(game_sesion%2==0){
				aku(); kamu();
			}else{
				kamu(); aku();
			}
			
		}
	}
}

void pemenang(){
	cout << endl;
	// posisi sama kesamping
	int i = 0;
	while(i<9){
		if(mark[i]=="O"&&mark[i+1]=="O"&&mark[i+2]=="O"){
			skor_kamu = skor_kamu + 10;
			cout << "      ~ Selamat kamu menang ~" << endl; Sleep(3000); menu(); break;
		}
		else if(mark[i]=="X"&&mark[i+1]=="X"&&mark[i+2]=="X"){
			skor_aku = skor_aku + 10;
			cout << "      ~ Yah, kamu kalah ... ~" << endl; Sleep(3000); menu(); break;
		}
		i=i+3;
	}
	// posisi sama kebawah
	for(int j=0; j<3; j++){
		if(mark[j]=="O"&&mark[j+3]=="O"&&mark[j+6]=="O"){
			skor_kamu = skor_kamu + 10;
			cout << "      ~ Selamat kamu menang ~" << endl; Sleep(3000); menu(); break;
		}
		else if(mark[j]=="X"&&mark[j+3]=="X"&&mark[j+6]=="X"){
			skor_aku = skor_aku + 10;
			cout << "      ~ Yah, kamu kalah ... ~" << endl; Sleep(3000); menu(); break;
		}
	}
	// posisi miring
	if((mark[0]=="O"&&mark[4]=="O"&&mark[8]=="O")||(mark[2]=="O"&&mark[4]=="O"&&mark[6]=="O")){
		skor_kamu = skor_kamu + 10;
		cout << "      ~ Selamat kamu menang ~" << endl; Sleep(3000); menu();
	}
	else if((mark[0]=="X"&&mark[4]=="X"&&mark[8]=="X")||(mark[2]=="X"&&mark[4]=="X"&&mark[6]=="X")){
		skor_aku = skor_aku + 10;
		cout << "      ~ Yah, kamu kalah ... ~" << endl; Sleep(3000); menu();
	}
	// posisi seri
	for(int k=0; k<9; k++){
		if(table[k]!=0&&k==8){
			cout << "      Hasil seri ... " << endl; Sleep(3000); menu(); break;
		}
	}
	
}

void game(){
	while(true){
		int boot, cur;
		boot = 1 + rand()%9;
		cur = num;
		
		strategi1(0,1,2,cur);
		strategi1(1,2,0,cur);
		strategi1(2,0,1,cur);
		strategi1(3,4,5,cur);
		strategi1(4,5,3,cur);
		strategi1(5,3,4,cur);
		strategi1(6,7,8,cur);
		strategi1(7,8,6,cur);
		strategi1(8,6,7,cur);
		
		strategi1(0,3,6,cur);
		strategi1(3,6,0,cur);
		strategi1(6,0,3,cur);
		strategi1(1,4,7,cur);
		strategi1(4,7,1,cur);
		strategi1(7,1,4,cur);
		strategi1(2,5,8,cur);
		strategi1(5,8,2,cur);
		strategi1(8,2,5,cur);
		
		strategi1(0,4,8,cur);
		strategi1(4,8,0,cur);
		strategi1(8,0,4,cur);
		strategi1(2,4,6,cur);
		strategi1(4,6,2,cur);
		strategi1(6,2,4,cur);
		
		strategi(0,1,2,cur);
		strategi(1,2,0,cur);
		strategi(2,0,1,cur);
		strategi(3,4,5,cur);
		strategi(4,5,3,cur);
		strategi(5,3,4,cur);
		strategi(6,7,8,cur);
		strategi(7,8,6,cur);
		strategi(8,6,7,cur);
		
		strategi(0,3,6,cur);
		strategi(3,6,0,cur);
		strategi(6,0,3,cur);
		strategi(1,4,7,cur);
		strategi(4,7,1,cur);
		strategi(7,1,4,cur);
		strategi(2,5,8,cur);
		strategi(5,8,2,cur);
		strategi(8,2,5,cur);
		
		strategi(0,4,8,cur);
		strategi(4,8,0,cur);
		strategi(8,0,4,cur);
		strategi(2,4,6,cur);
		strategi(4,6,2,cur);
		strategi(6,2,4,cur);
		
		if(cur==num){
		for(int k=0; k<9; k++){
			if(table[k]==boot){
				boot=0;
				break;
			}else if(k==8){
				table[num]=boot;
				mark[boot-1]="X";
				num++;
				break;
			}
		}
		}
		if(boot!=0){
			break;
		}
	}
}

string jarak(string a, int b){
	if(b<10){
		a="000";
	}else if(b<100){
		a="00";
	}else{
		a="0";
	}
	return a;
}

void tampilan(){
	system("cls");
	cout << endl;
	string s_kamu, s_aku, spasi=" ";
	s_kamu = jarak(s_kamu,skor_kamu);
	s_aku = jarak(s_aku,skor_aku);
	cout << "     +-----------------------+" << endl;
	cout << "     | T I C   T A C   T O E |" << endl;
	cout << "     +-----------------------+" << endl;
	cout << "     |                       |" << endl;
	cout << "     |     kamu  : " << s_kamu << skor_kamu << "      |" << endl;
	cout << "     |     aku   : " << s_aku << skor_aku << "      |" << endl;
	cout << "     |                       |" << endl;
	cout << "     |     +---+---+---+     |" << endl;
	cout << "     |     | " << mark[0] << " | " << mark[1] << " | " << mark[2] << " |     |" << endl;
	cout << "     |     +---+---+---+     |" << endl;
	cout << "     |     | " << mark[3] << " | " << mark[4] << " | " << mark[5] << " |     |" << endl;
	cout << "     |     +---+---+---+     |" << endl;
	cout << "     |     | " << mark[6] << " | " << mark[7] << " | " << mark[8] << " |     |" << endl;
	cout << "     |     +---+---+---+     |" << endl;
	cout << "     |                       |" << endl;
	cout << "     +-----------------------+" << endl;
}

int main(){
	menu();
}
