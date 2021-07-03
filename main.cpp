#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<cstring>
#include<conio.h>
#include<cstdlib>
#include<sstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Base{
	public:
		enum result{Kaybetmek,Beraberlik,Kazanmak
		};
		virtual Compare(Base*)=0;
};
class Red: public Base{
	public:
		Red();
		Compare(Base*) ;
};
class DarkRed: public Base{
	public:
		DarkRed(){
			string kart="D";
		}
		Compare(Base*) ;
};
class Blue: public Base{
	public:
		Blue(){
			string kart="B";
		}
		Compare(Base*) ;
};
class Green: public Base{
	public:
		Green(){
			string kart="G";
		}
		Compare(Base*) ;
};
class List:public Base{
	public:
		Red::Red(){
			string kart="R";
		};
		DarkRed::D D;
		Blue B();
		Green G();
		Compare(Base*) ;
	
};
int main() {
	Base *kart1[21];
	Base *kart2[21];
	string oyuncu_1;		
	string oyuncu_2;
	int oyuncu_1_Kazanma=0;
	int oyuncu_1_Kaybetme=0;
	int Beraberlik=0;
	int oyuncu_2_Kazanma=0;
	int oyuncu_2_Kaybetme=0;
	ifstream dosyaOku;
    dosyaOku.open("Kartlar.txt");	
    while(!dosyaOku.eof()){ 
		getline(dosyaOku,oyuncu_1);
		stringstream oyuncu_1_sectigi_kartlar(oyuncu_1);
		getline(dosyaOku,oyuncu_2);
		stringstream oyuncu_2_sectigi_kartlar(oyuncu_2);
		cout<<"Oyuncu 1 sectigi kartlar : "<<oyuncu_1<<endl;
		cout<<"Oyuncu 2 sectigi kartlar : "<<oyuncu_2<<endl;
		for(int i=0;i<oyuncu_1.length();i++){
			getline(oyuncu_1_sectigi_kartlar,oyuncu_1,',');
			getline(oyuncu_2_sectigi_kartlar,oyuncu_2,',');
			switch(oyuncu_1){
			case 'R':
				kart1[i]=new List::R();
				break;
			case 'D':
				kart1[i]=new List::D();
				break;
			case 'G':
				kart1[i]=new List::G();
				break;
			case 'B':
				kart1[i]=new List::B();
				break;
			}
			switch(oyuncu_2){
			case 'R':
				kart2[i]=new List::R();
				break;
			case 'D':
				kart2[i]=new List::D();
				break;
			case 'G':
				kart2[i]=new List::G();
				break;
			case 'B':
				kart2[i]=new List::B();
				break;
			}
			if(kart1[i]=="R"&&kart2[i]=="R"){
				beraberlik++;
			}
			else if(kart1[i]=="R"&&kart2[i]=="D"){
				oyuncu_2_Kazanma++;
			}
			else if(kart1[i]=="R"&&kart2[i]=="G"){
				oyuncu_1_Kazanma++;
			}
			else if(kart1[i]=="R"&&kart2[i]=="B"){
				oyuncu_2_Kazanma++;
			}
			else if(kart1[i]=="D"&&kart2[i]=="R"){
				oyuncu_1_Kazanma++;
			}
			else if(kart1[i]=="D"&&kart2[i]=="D"){
				beraberlik++;
			}
			else if(kart1[i]=="D"&&kart2[i]=="G"){
				oyuncu_2_Kazanma++;
			}
			else if(kart1[i]=="D"&&kart2[i]=="B"){
				oyuncu_1_Kazanma++;
			}
			else if(kart1[i]=="G"&&kart2[i]=="R"){
				oyuncu_2_Kazanma++;
			}
			else if(kart1[i]=="G"&&kart2[i]=="D"){
				oyuncu_1_Kazanma++;
			}
			else if(kart1[i]=="G"&&kart2[i]=="G"){
				beraberlik++;
			}
			else if(kart1[i]=="G"&&kart2[i]=="B"){
				oyuncu_1_Kazanma++;
			}
			else if(kart1[i]=="B"&&kart2[i]=="R"){
				oyuncu_1_Kazanma++;
			}
			else if(kart1[i]=="B"&&kart2[i]=="D"){
				oyuncu_2_Kazanma++;
			}
			else if(kart1[i]=="B"&&kart2[i]=="G"){
				oyuncu_2_Kazanma++;
			}
			else if(kart1[i]=="B"&&kart2[i]=="B"){
				Beraberlik++;
			}
		}
	}
	cout<<"Oyuncu 1 Kazanma :"<<oyuncu_1_Kazanma<<"\t";
	cout<<"Beraberlik :"<<Beraberlik<<"\t";
	cout<<"Kaybetme :"<<oyuncu_1_Kaybetme<<endl;
	cout<<"Oyuncu 2 Kazanma :"<<oyuncu_2_Kazanma<<"\t";
	cout<<"Beraberlik :"<<Beraberlik<<"\t";
	cout<<"Kaybetme :"<<oyuncu_2_Kaybetme<<endl;
	int sonuc1=0,sonuc2=0;
	sonuc1=oyuncu_1_Kazanma*2+Beraberlik;
	sonuc2=oyuncu_2_Kazanma*2+Beraberlik;
	cout<<"Oyuncu 1 puan : "<<sonuc1<<endl;
	cout<<"Oyuncu 2 puan : "<<sonuc2<<endl;
	if(sonuc1<sonuc2)
		cout<<"Oyuncu 2 Kazandý."<<endl;
	else if(sonuc2<sonuc1)
		cout<<"Oyuncu 1 Kazandý."<<endl;
	else
		cout<<"Oyun Berabere"<<endl;
		
	return 0;
}
