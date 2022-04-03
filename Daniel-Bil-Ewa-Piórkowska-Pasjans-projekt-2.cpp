#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
class karta{
	public:
		karta();
		void zrob_talie(karta t[52]);
		void wyswietl();
		bool sprawdz1(karta p, karta q);
		bool sprawdz2(karta p, karta q);
		void zakrywanie(vector <karta>& kol,int q);
		void zrob_stos(stack<karta>& stos,int m);
		void stosy(karta p,stack <karta>& stos1,stack <karta>& stos2 ,stack <karta>& stos3 ,stack <karta>& stos4,queue <karta>& zapas);
		int	sprawdz_karte2(int z,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7);
		bool krol(karta p);
		~karta();
	private:	
	string kolor;
	int nr_kol;
	string figura;
	int nr_fig;
	bool odkryta;
};

karta::karta()
{	
	odkryta=true;
	nr_kol=0;
	nr_fig=0;
	kolor="X ";
	figura="";
}
karta::~karta(){
	
}
void kolejka(queue <karta> zapas);
void pokaz_menu();
void wyswietl_vec(vector<karta> kol_1,vector<karta> kol_2,vector<karta> kol_3,vector<karta> kol_4,vector<karta> kol_5,vector<karta> kol_6,vector<karta> kol_7);
void pomieszaj(queue <karta>& zapas);
void zakryj(vector <karta>& kol);
void umiesc_karte(karta &z,vector<karta>& kol_1,vector<karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,queue <karta>& zapas);
karta wez_karte(queue <karta>& zapas,vector<karta> kol_1,vector <karta> kol_2,vector<karta> kol_3,vector<karta> kol_4,vector<karta> kol_5,vector<karta> kol_6,vector<karta> kol_7);
void usun_z_kolejki(queue <karta>& zapas);
void dodaj_kolumnie(karta &x,queue <karta>& zapas,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2 ,stack <karta>& stos3 ,stack <karta>& stos4);
void dodaj_kolumnie1(karta &x,queue <karta>& zapas,vector<karta>& kol);
void sprawdz_karty(int z,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,queue <karta>& zapas);
void przeslij(int z,int h,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,vector<karta>& kol_8,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,queue <karta>& zapas);
void kolejna_funkcja(int z,int h,vector<karta> kol_1,vector <karta> kol_2,vector<karta> kol_3,vector<karta> kol_4,vector<karta> kol_5,vector<karta> kol_6,vector<karta> kol_7,vector<karta>& kol_8);
void wstaw_do_stos(int z,vector<karta>& kol_1,vector<karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,queue <karta>& zapas);
void wybierz_stos(int z,vector<karta>& kol_8,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,vector<karta>& kol_1,vector<karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,queue <karta>& zapas);
void wybierz_stos1(vector<karta>& kol, bool czy_wstawil);

void karta::zrob_talie(karta t[]){
	int m=0;	
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			switch (i){
				case 0:
					t[m].kolor="h";
					t[m].nr_kol=1;
					break;
				case 1:
					t[m].kolor="s";
					t[m].nr_kol=2;
					break;
				case 2:
					t[m].kolor="d";
					t[m].nr_kol=3;
					break;
				case 3:
					t[m].kolor="c";
					t[m].nr_kol=4;
					break;
			}
			switch(j){
				case 0:
					t[m].figura="2";
					t[m].nr_fig=2;
					break;
				case 1:
					t[m].figura="3";
					t[m].nr_fig=3;
					break;
				case 2:
					t[m].figura="4";
					t[m].nr_fig=4;
					break;
				case 3:
					t[m].figura="5";
					t[m].nr_fig=5;
					break;
				case 4:
					t[m].figura="6";
					t[m].nr_fig=6;
					break;
				case 5:
					t[m].figura="7";
					t[m].nr_fig=7;
					break;
				case 6:
					t[m].figura="8";
					t[m].nr_fig=8;
					break;
				case 7:
					t[m].figura="9";
					t[m].nr_fig=9;
					break;
				case 8:
					t[m].figura="10";
					t[m].nr_fig=10;
					break;
				case 9:
					t[m].figura="J";
					t[m].nr_fig=11;
					break;
				case 10:
					t[m].figura="D";
					t[m].nr_fig=12;
					break;
				case 11:
					t[m].figura="K";
					t[m].nr_fig=13;
					break;
				case 12:
					t[m].figura="A";
					t[m].nr_fig=1;
					break;
			}
			m++;
		}
	}	
}

void karta::wyswietl(){
	if(odkryta)
	cout<<setw(3)<<figura<<kolor;
	else cout<<setw(3)<<" ===";
}

void losowanie(int los[52]){	
	bool czy_wylosowana;
	int i=0;
	int liczba=0;
	do
	{
	liczba=rand() % 52;
	czy_wylosowana=false;
	 for(int j=0;j<i;j++){
		 if(los[j]==liczba)
            {
                czy_wylosowana=true;
                break;
            }
		}
        if(!czy_wylosowana)
		{
		  los[i]=liczba;
		  i++;
		}
	} while(i<52);
}

void stosy4(stack <karta> stos1,stack <karta> stos2,stack <karta> stos3,stack <karta> stos4){
	karta g;

	g=stos1.top();
	cout<<setw(3);
	g.wyswietl();

	g=stos2.top();
	cout<<setw(3);
	g.wyswietl();

	g=stos3.top();
	cout<<setw(3);
	g.wyswietl();

	g=stos4.top();
	cout<<setw(3);
	g.wyswietl();

}

int karta::sprawdz_karte2(int z,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7){
	int k=0;
	switch(z){
	case 1:{
		for(int i=0;i<kol_1.size();i++){
			if(kol_1[i].odkryta)k++;	
		}			
		return k;
	}
	case 2:{
		for(int i=0;i<kol_2.size();i++){
			if(kol_2[i].odkryta)k++;	
		}	
		return k;
	}
	case 3:{
		for(int i=0;i<kol_3.size();i++){
			if(kol_3[i].odkryta)k++;	
		}	
		return k;
	}
	case 4:{
		for(int i=0;i<kol_4.size();i++){
			if(kol_4[i].odkryta)k++;	
		}	
		return k;
	}
	case 5:{
		for(int i=0;i<kol_5.size();i++){
			if(kol_5[i].odkryta)k++;	
		}			
		return k;
	}
	case 6:{
		for(int i=0;i<kol_6.size();i++){
			if(kol_6[i].odkryta)k++;	
		}	
		return k;
	}
	case 7:{
		for(int i=0;i<kol_7.size();i++){
			if(kol_7[i].odkryta)k++;	
		}	
		return k;
	}	
	}
	return 0;
}

bool karta::krol(karta p){
		if(p.nr_fig==13){
		return true;
	}
	else{
		return false;
	}
}

void przeslij1(vector<karta>& kol,vector<karta>& kol_8,bool& tak){
	int k=0,l=0;
	k=kol_8.size()-1;
	l=kol.size()-1;
		if((kol.size()==0)&&(kol[0].krol(kol_8[k]))){
			for(int i=k;i>=0;i--){
				kol.push_back(kol_8[i]);
			}
			tak=true;
		}
		else if((kol.size()>0)&&(kol_8[k].sprawdz1(kol[l],kol_8[k]))){
			for(int i=k;i>=0;i--){
				kol.push_back(kol_8[i]);
			}
			tak=true;
		}
}

void przeslij2(vector<karta>& kol,int h){
	int r;
	for(int j=0;j<h;j++){
		kol.pop_back();
	}
		r=kol.size()-1;
		kol[r].zakrywanie(kol,1);	
}

void przeslij(int z,int h,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,vector<karta>& kol_8,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,queue <karta>& zapas){
	karta g;
	bool tak=false;
	int f=0;
			cout<<"-------------------------------------------"<<endl;
			kolejka(zapas);	
			cout<<"          ";
			stosy4(stos1,stos2,stos3,stos4);
			cout<<endl;
				cout<<"-------------------------------------------"<<endl;
			wyswietl_vec(kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7);
			cout<<"-------------------------------------------"<<endl;
	cout<<"w ktorej kolumnie chcesz je umiescic?"<<endl;
	cin>>f;
	system("cls");
		switch(f){
			case 1:
				przeslij1(kol_1,kol_8,tak);
				break;
			case 2:
				przeslij1(kol_2,kol_8,tak);			
				break;
			case 3:
				przeslij1(kol_3,kol_8,tak);	
				break;
			case 4:
				przeslij1(kol_4,kol_8,tak);	
				break;
			case 5:
				przeslij1(kol_5,kol_8,tak);
				break;
			case 6:
				przeslij1(kol_6,kol_8,tak);
				break;
			case 7:
				przeslij1(kol_7,kol_8,tak);
				break;	
		}
	if(tak){
		switch(z){
			case 1:
				przeslij2(kol_1,h);
				break;
			case 2:
				przeslij2(kol_2,h);
				break;
			case 3:
				przeslij2(kol_3,h);
				break;
			case 4:
				przeslij2(kol_4,h);
				break;
			case 5:
				przeslij2(kol_5,h);
				break;
			case 6:
				przeslij2(kol_6,h);
				break;
			case 7:
				przeslij2(kol_7,h);
				break;
		}
	}
}

void kolejna_funkcja1(vector<karta> kol,vector<karta>& kol_8,int h){
	karta b;
	for(int i=0;i<h;i++){
		b=kol.back();
		kol_8.push_back(b);
		kol.pop_back();
		}
}

void kolejna_funkcja(int z,int h,vector<karta> kol_1,vector <karta> kol_2,vector<karta> kol_3,vector<karta> kol_4,vector<karta> kol_5,vector<karta> kol_6,vector<karta> kol_7,vector<karta>& kol_8){
	switch(z){
		case 1:
			kolejna_funkcja1(kol_1,kol_8,h);
			break;
		case 2:
			kolejna_funkcja1(kol_2,kol_8,h);
			break;
		case 3:
			kolejna_funkcja1(kol_3,kol_8,h);
			break;
		case 4:
			kolejna_funkcja1(kol_4,kol_8,h);
			break;
		case 5:
			kolejna_funkcja1(kol_5,kol_8,h);
			break;
		case 6:
			kolejna_funkcja1(kol_6,kol_8,h);
			break;
		case 7:
			kolejna_funkcja1(kol_7,kol_8,h);
			break;		
	}
}

void sprawdz_karty(int z,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,queue <karta>& zapas){
	int g=0,h=0;
	vector <karta> kol_8;
	cout<<"ile kart chcesz wziac"<<endl;
	cin>>h;
	system("cls");
	switch(z){
		case 1:
			if(h>kol_1[0].sprawdz_karte2(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7))
				break;
			else{
				kolejna_funkcja(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8);
				przeslij(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8,stos1,stos2,stos3,stos4,zapas);
			}		
			break;
		case 2:
			if(h>kol_2[0].sprawdz_karte2(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7))
				break;		
			else{
				kolejna_funkcja(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8);
				przeslij(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8,stos1,stos2,stos3,stos4,zapas);
			}	
			break;
		case 3:
			if(h>kol_3[0].sprawdz_karte2(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7))
				break;
			else{
				kolejna_funkcja(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8);
				przeslij(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8,stos1,stos2,stos3,stos4,zapas);
			}					
			break;
		case 4:
			if(h>kol_4[0].sprawdz_karte2(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7))
				break;	
			else{
				kolejna_funkcja(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8);
				przeslij(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8,stos1,stos2,stos3,stos4,zapas);
			}		
			break;
		case 5:	
			if(h>kol_5[0].sprawdz_karte2(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7))
				break;	
			else{
				kolejna_funkcja(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8);
				przeslij(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8,stos1,stos2,stos3,stos4,zapas);
			}		
			break;
		case 6:
			if(h>kol_6[0].sprawdz_karte2(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7))
				break;
			else{
				kolejna_funkcja(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8);
				przeslij(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8,stos1,stos2,stos3,stos4,zapas);
			}					
				break;
		case 7:
			if(h>kol_7[0].sprawdz_karte2(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7))
				break;	
			else{
				kolejna_funkcja(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8);
				przeslij(z,h,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,kol_8,stos1,stos2,stos3,stos4,zapas);
			}
			break;		
	}
	
	cout<<"-------------------------------------------"<<endl;
	kolejka(zapas);	
	cout<<"          ";
	stosy4(stos1,stos2,stos3,stos4);
	cout<<endl;
}

void wybierz_stos1(vector<karta>& kol, bool czy_wstawil){
	int k;
	if(czy_wstawil){
		kol.pop_back();
		if(!kol.empty()){
			k=kol.size()-1;
			kol[k].zakrywanie(kol,1);	
		}
	}	
}

void wybierz_stos(int z,vector<karta>& kol_8,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,vector<karta>& kol_1,vector<karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,queue <karta>& zapas){
	bool czy_wstawil=false;
	karta g;
	g=kol_8.back();
		if(g.sprawdz2(stos1.top(),g)){
			stos1.push(g);
			czy_wstawil=true;
		}
		else if(g.sprawdz2(stos2.top(),g)){
			stos2.push(g);
			czy_wstawil=true;
		}
		else if(g.sprawdz2(stos3.top(),g)){
			stos3.push(g);
			czy_wstawil=true;
		}
		else if(g.sprawdz2(stos4.top(),g)){
			stos4.push(g);
			czy_wstawil=true;
		}	
	switch(z){
		case 1:
			wybierz_stos1(kol_1,czy_wstawil);
			break;
		case 2:
			wybierz_stos1(kol_2,czy_wstawil);
			break;
		case 3:
			wybierz_stos1(kol_3,czy_wstawil);
			break;
		case 4:
			wybierz_stos1(kol_4,czy_wstawil);
			break;
		case 5:
			wybierz_stos1(kol_5,czy_wstawil);
			break;
		case 6:
			wybierz_stos1(kol_6,czy_wstawil);
			break;
		case 7:
			wybierz_stos1(kol_7,czy_wstawil);
			break;
	}
	cout<<"-------------------------------------------"<<endl;
	kolejka(zapas);	
	cout<<"          ";
	stosy4(stos1,stos2,stos3,stos4);
	cout<<endl;
}

void wstaw_do_stos(int z,vector<karta>& kol_1,vector<karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,queue <karta>& zapas){
	vector <karta> kol_8;
	karta b,a;
	int g=0;
	switch(z){
		case 1:
			if(kol_1.size()==0)break;
			b=kol_1.back();			
			kol_8.push_back(b);	
			wybierz_stos(z,kol_8,stos1,stos2,stos3,stos4,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,zapas);		
			break;
		case 2:
			if(kol_2.size()==0)break;
			b=kol_2.back();
			kol_8.push_back(b);
			wybierz_stos(z,kol_8,stos1,stos2,stos3,stos4,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,zapas);
			break;
		case 3:
			if(kol_3.size()==0)break;
			b=kol_3.back();
			kol_8.push_back(b);
			wybierz_stos(z,kol_8,stos1,stos2,stos3,stos4,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,zapas);
			break;
		case 4:
			if(kol_4.size()==0)break;
			b=kol_4.back();
			kol_8.push_back(b);
			wybierz_stos(z,kol_8,stos1,stos2,stos3,stos4,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,zapas);
			break;
		case 5:
			if(kol_5.size()==0)break;
			b=kol_5.back();
			kol_8.push_back(b);
			wybierz_stos(z,kol_8,stos1,stos2,stos3,stos4,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,zapas);
			break;
		case 6:
			if(kol_6.size()==0)break;
			b=kol_6.back();
			kol_8.push_back(b);
			wybierz_stos(z,kol_8,stos1,stos2,stos3,stos4,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,zapas);
			break;
		case 7:
			if(kol_7.size()==0)break;
			b=kol_7.back();
			kol_8.push_back(b);
			wybierz_stos(z,kol_8,stos1,stos2,stos3,stos4,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,zapas);
			break;
	}
}

void ekran(queue <karta>& zapas,vector<karta>& kol_1,vector<karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4){

	cout<<"-------------------------------------------"<<endl;
	kolejka(zapas);	
	cout<<"          ";
	stosy4(stos1,stos2,stos3,stos4);
	cout<<endl;
	for(int i=0;;i++)
	{
	cout<<"-------------------------------------------"<<endl;
	wyswietl_vec(kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7);
	cout<<"-------------------------------------------"<<endl;
	pokaz_menu();
	int wybor=0;
	cin>>wybor;
	system ("cls");
	int z;
	karta y;
	
	switch (wybor){
		case 0: 
			cout<<"Poddales sie"<<endl;
			cout<<"KONIEC GRY"<<endl;
			exit(0);
			break;
		case 1: 
			pomieszaj(zapas);
			cout<<"          ";
			stosy4(stos1,stos2,stos3,stos4);
			cout<<endl;
			break;
		case 2:
			cout<<"-------------------------------------------"<<endl;
			y=wez_karte(zapas,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7);
			cout<<"          ";
			stosy4(stos1,stos2,stos3,stos4);
			system("cls");
			cout<<"-------------------------------------------"<<endl;
			umiesc_karte(y,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,stos1,stos2,stos3,stos4,zapas);
			break;
		case 3:
			cout<<"-------------------------------------------"<<endl;
			kolejka(zapas);	
			cout<<"          ";
			stosy4(stos1,stos2,stos3,stos4);
			cout<<endl;
			cout<<"-------------------------------------------"<<endl;
			wyswietl_vec(kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7);
			cout<<"-------------------------------------------"<<endl;
			cout<<"z ktorej kolumny chcesz wziac karty"<<endl;
			cin>>z;
			sprawdz_karty(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,stos1,stos2,stos3,stos4,zapas);			
			break;
		case 4:
			cout<<"-------------------------------------------"<<endl;
			kolejka(zapas);	
			cout<<"          ";
			stosy4(stos1,stos2,stos3,stos4);
			cout<<endl;
			cout<<"-------------------------------------------"<<endl;
			wyswietl_vec(kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7);
			cout<<"-------------------------------------------"<<endl;
			cout<<"z ktorej kolumny chcesz wziac karty"<<endl;
			cin>>z;
			system("cls");
			wstaw_do_stos(z,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,stos1,stos2,stos3,stos4,zapas);		
			break;	
		default:		
			break;	
	cout<<endl;	
	}
	}
}

void wyswietl_vec1(vector<karta> kol, int i){
	if(kol.size()>i)
		kol[i].wyswietl();
		else cout<<"    ";
		cout<<" |";
}

void wyswietl_vec(vector<karta> kol_1,vector <karta> kol_2,vector<karta> kol_3,vector<karta> kol_4,vector<karta> kol_5,vector<karta> kol_6,vector<karta> kol_7){
	int max;
	max=kol_1.size();
	if(kol_2.size()>max) max=kol_2.size();
	if(kol_3.size()>max) max=kol_3.size();
	if(kol_4.size()>max) max=kol_4.size();
	if(kol_5.size()>max) max=kol_5.size();
	if(kol_6.size()>max) max=kol_6.size();
	if(kol_7.size()>max) max=kol_7.size();
	
	for(int i=0;i<max;i++){
		cout<<"|";
		wyswietl_vec1(kol_1,i);
		wyswietl_vec1(kol_2,i);
		wyswietl_vec1(kol_3,i);
		wyswietl_vec1(kol_4,i);
		wyswietl_vec1(kol_5,i);
		wyswietl_vec1(kol_6,i);
		wyswietl_vec1(kol_7,i);
		cout<<endl;
	}
}

void kolejka(queue <karta> zapas){
	queue <karta> dodatkowa;
	karta x,y,z;
	int n=0;
	
	while((!zapas.empty())&&(n<3)){
		x=zapas.front();
		cout<<setw(3);
		dodatkowa.push(x);
		zapas.pop();
		n++;
	}
		if(!dodatkowa.empty()){
		x=dodatkowa.front();
		dodatkowa.pop();}
		if(!dodatkowa.empty()){
		y=dodatkowa.front();
		dodatkowa.pop();}
		if(!dodatkowa.empty()){
		z=dodatkowa.front();
		dodatkowa.pop();}
		z.wyswietl();
		y.wyswietl();
		x.wyswietl();
		
}

void usun_z_kolejki(queue <karta>& zapas){
	zapas.pop();	
}
	
void pomieszaj(queue <karta>& zapas)
{
	karta x;
	if(zapas.size()>3){
		for(int i=0;i<3;i++){
		x=zapas.front();
		zapas.push(x);
		zapas.pop();
		}
		cout<<"-------------------------------------------"<<endl;
		kolejka(zapas);
	}	
	else{
		cout<<"-------------------------------------------"<<endl;
		kolejka(zapas);
	} 
}	

karta wez_karte(queue <karta>& zapas,vector<karta> kol_1,vector <karta> kol_2,vector<karta> kol_3,vector<karta> kol_4,vector<karta> kol_5,vector<karta> kol_6,vector<karta> kol_7){
	karta x;
	if(!zapas.empty()){
		x=zapas.front();
		kolejka(zapas);
	}	
	return x;
}

void umiesc_karte(karta &x,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2,stack <karta>& stos3,stack <karta>& stos4,queue <karta>& zapas){
	int wybor=0;
	kolejka(zapas);
	cout<<"          ";
	stosy4(stos1,stos2,stos3,stos4);
	cout<<endl;
	cout<<"-------------------------------------------"<<endl;
	wyswietl_vec(kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7);
	cout<<"-------------------------------------------"<<endl;
	cout<<"1-dodaj na stos"<<endl;
	cout<<"2-dodaj do kolumny"<<endl;
	cin>>wybor;
	system("cls");
	switch(wybor){
		case 1:
			x.stosy(x,stos1,stos2,stos3,stos4,zapas);
			cout<<"-------------------------------------------"<<endl;
			kolejka(zapas);
			cout<<"          ";
			stosy4(stos1,stos2,stos3,stos4);
			cout<<endl;
			break;
		case 2:
			dodaj_kolumnie(x,zapas,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,stos1,stos2,stos3,stos4);
			break;
		default:
			break;		
	}
}

bool karta::sprawdz1(karta p, karta q){		
	if(((p.nr_kol+q.nr_kol)%2==1)&&(p.nr_fig==(q.nr_fig)+1))
	return true;
	else return false;
} 

bool karta::sprawdz2(karta p, karta q){
	if((p.nr_kol==q.nr_kol)&&(p.nr_fig==(q.nr_fig)-1))
	return true;
	else return false;
}

void karta::stosy(karta p,stack <karta>& stos1,stack <karta>& stos2 ,stack <karta>& stos3 ,stack <karta>& stos4,queue <karta>& zapas){	
	bool czy_wstawil=false;
	
		if(sprawdz2(stos1.top(),p)){
			stos1.push(p);
			czy_wstawil=true;
		}
		else if(sprawdz2(stos2.top(),p)){
			stos2.push(p);
			czy_wstawil=true;
		}
		else if(sprawdz2(stos3.top(),p)){
			stos3.push(p);
			czy_wstawil=true;
		}
		else if(sprawdz2(stos4.top(),p)){
			stos4.push(p);
			czy_wstawil=true;
		}
		
		if(czy_wstawil) usun_z_kolejki(zapas);
}


void pokaz_menu(){
	cout<<"0 - wyjdz"<<endl;
	cout<<"1 - pomieszaj zapas"<<endl;	
	cout<<"2 - wez karte z zapasu"<<endl;
	cout<<"3 - wez karty z kolumny"<<endl;
	cout<<"4 - wstaw z kolumny do stosu"<<endl;
}
 
void zakryj(vector <karta>& kol){
	int rozmiar;
	rozmiar=kol.size()-1;
	for(int i=0;i<rozmiar;i++){
		kol[i].zakrywanie(kol,0);
	}	
}

void karta::zakrywanie(vector <karta>& kol,int q){
	if(q==0)
	odkryta=false;
	if(q==1)
	odkryta=true;
} 

void karta::zrob_stos(stack<karta>& stos,int m){
	karta zerowa;
	zerowa.nr_kol=m;
	stos.push(zerowa);
}

void dodaj_kolumnie(karta &x,queue <karta>& zapas,vector<karta>& kol_1,vector <karta>& kol_2,vector<karta>& kol_3,vector<karta>& kol_4,vector<karta>& kol_5,vector<karta>& kol_6,vector<karta>& kol_7,stack <karta>& stos1,stack <karta>& stos2 ,stack <karta>& stos3 ,stack <karta>& stos4){
	cout<<"-------------------------------------------"<<endl;
	kolejka(zapas);
	cout<<"          ";
	stosy4(stos1,stos2,stos3,stos4);
	cout<<endl;
	cout<<"-------------------------------------------"<<endl;
	wyswietl_vec(kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7);
	cout<<"-------------------------------------------"<<endl;
	cout<<"ktorej kolumnie"<<endl;
	int a,n;
	cin>>n;
	switch(n){
		case 1:
			dodaj_kolumnie1(x,zapas,kol_1);
			break;
		case 2:
			dodaj_kolumnie1(x,zapas,kol_2);
			break;
		case 3:
			dodaj_kolumnie1(x,zapas,kol_3);
			break;
		case 4:
			dodaj_kolumnie1(x,zapas,kol_4);
			break;
		case 5:				
			dodaj_kolumnie1(x,zapas,kol_5);
			break;
		case 6:		
			dodaj_kolumnie1(x,zapas,kol_6);
			break;
		case 7:			
			dodaj_kolumnie1(x,zapas,kol_7);
		break;		
	}
	
	system("cls");
	cout<<"-------------------------------------------"<<endl;
	kolejka(zapas);
	cout<<"          ";
	stosy4(stos1,stos2,stos3,stos4);
	cout<<endl;
}

void dodaj_kolumnie1(karta &x,queue <karta>& zapas,vector<karta>& kol){
	int a;
	karta b;
	a=kol.size();
	if(a==0&&kol[0].krol(x)){
		kol.push_back(x);
		usun_z_kolejki(zapas);
	}
	else if(a>0){
		b=kol.back();	
		if(x.sprawdz1(b,x)){
			kol.push_back(x);
			usun_z_kolejki(zapas);
		}	
	}
}

void utworz(int& ile,vector<karta>& kol,int& rozdanie,karta losowe[])
{
	for(int i=0;i<ile;i++){
		kol.push_back(losowe[rozdanie]);
		rozdanie++;
	}
	zakryj(kol);
	ile++;	
}

int main()
{
	srand(time(NULL));
	const int ile_kart=52;
	karta talia[ile_kart];
	talia[ile_kart].zrob_talie(talia);
	
	karta losowe[ile_kart];
	int los[ile_kart];
	losowanie(los);
	for(int i=0;i<ile_kart;i++){
		losowe[i]=talia[los[i]];
	}

	int rozdanie=0;
	int ile=1;
	
	vector<karta> kol_1;
		utworz(ile,kol_1,rozdanie,losowe);
	vector<karta> kol_2;
		utworz(ile,kol_2,rozdanie,losowe);
	vector<karta> kol_3;
		utworz(ile,kol_3,rozdanie,losowe);
	vector<karta> kol_4;
		utworz(ile,kol_4,rozdanie,losowe);
	vector<karta> kol_5;
		utworz(ile,kol_5,rozdanie,losowe);
	vector<karta> kol_6;
		utworz(ile,kol_6,rozdanie,losowe);
	vector<karta> kol_7;
		utworz(ile,kol_7,rozdanie,losowe);
		
	queue <karta> zapas;
	do{
		zapas.push(losowe[rozdanie]);
		rozdanie++;
	}while(rozdanie<52);

	stack <karta> stos1;
	stack <karta> stos2;
	stack <karta> stos3;
	stack <karta> stos4;
	
	karta x;
	x.zrob_stos(stos1,1);
	x.zrob_stos(stos2,2);
	x.zrob_stos(stos3,3);
	x.zrob_stos(stos4,4);
	
	ekran(zapas,kol_1,kol_2,kol_3,kol_4,kol_5,kol_6,kol_7,stos1,stos2,stos3,stos4); 
	
	return 0;
}
