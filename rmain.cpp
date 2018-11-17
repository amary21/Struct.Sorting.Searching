#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

typedef struct {
	string nim,nama;
	int nilai;
}siswa;
typedef siswa mahasiswa[10];//struct
mahasiswa mhs,dummy;
int n=0;
void tambah_data(mahasiswa &x)//menginputkan data
{
	char ya;
	ulang:
		n++;
		cout<<"Masukkan data mahasiswa ke "<<n<<endl;
		cout<<"Masukkan Nim : ";cin>>x[n].nim;
		cout<<"Masukkan Nama : ";cin>>x[n].nama;
		cout<<"Masukkan Nilai : ";cin>>x[n].nilai;
		cout<<"Input berhasil input lagi (y)/(t) : ";cin>>ya;
		if((ya=='Y')||(ya=='y')){
			goto ulang;
		}
		else {
			cout<<"Tekan enter untuk kembali ke menu utama"<<endl;
		}
}
void cetak_data(mahasiswa &x)//menampilkan hasil ouput dari input tambah_data
{
	system ("cls");
	cout<<"Daftar Mahasiswa Saat Ini"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<" NO 	Nim 	Nama 	Nilai"<<endl;
	cout<<"----------------------------------"<<endl;
	for( int i = 1; i<=n; i++){
		cout<<i<<" 	"<<x[i].nim<<" 	"<<x[i].nama<<" 	"<<x[i].nilai<<endl;
		cout<<"----------------------------------"<<endl;
	}
		
}
void filter_data(mahasiswa &x){ //multipile math
	int filter ; bool ketemu= false;
	cout<<"Memfilter nilai Mahasiswa dengan nilai lebih dari sama dengan yang di inputkan"<<endl;
	cout<<"Masukkan nilai : ";cin>>filter;
        cout<<"----------------------------------"<<endl;
	cout<<" NO 	Nim 	Nama 	Nilai"<<endl;
	cout<<"----------------------------------"<<endl;
	for (int i=1;i<=n;i++){
		if(x[i].nilai>=filter){
			ketemu = true;
			cout<<i<<" 	"<<x[i].nim<<" 	"<<x[i].nama<<" 	"<<x[i].nilai<<endl;
		}
	}
	if (not ketemu){
		cout<<"tidak ada mahasiswa dengan nilai "<<filter<<endl;
	}
}

void cari_data(mahasiswa &x){ //sigle math
	int cari ; bool ketemu= false;
	cout<<"Mencari nilai mahasiswa"<<endl;
	cout<<"Masukkan nilai yang di cari : ";cin>>cari;
	for (int i=1;i<=n;i++){
		if(x[i].nilai==cari){
			ketemu = true;
			cout<<"yang mempunyai nilai "<<cari<<" = "<<endl;
			cout<<"Nim : "<<x[i].nim<<" nama "<<x[i].nama<<endl;
		}
	}
	if (not ketemu){
		cout<<"tidak ada mahasiswa dengan nilai "<<cari<<endl;
	}
}

void urut_data (mahasiswa &x)//metode exchange
{
	cout<<"Mengurutkan mahasiswa berdasrkan nilai : "<<endl;
	for(int i=1; i<=n; i++){
		dummy[i]=x[i];
	}//mengurutkan dari terbesar ke terkecil 
	siswa swap;
	for(int i = 1; i<=n;i++)
        {
		for(int j = i+1; j<=n; j++){
                    if(dummy[i].nilai<dummy[j].nilai){
			swap = dummy[i];
                        dummy[i]=dummy[j];
                        dummy[j]=swap;
                    }
            }
        }
	cout<<"Hasil Setelah di urutkan "<<endl;
	cetak_data(dummy);
}
void urut_buble(mahasiswa &x)//metode buble
{
        cout<<"Mengurutkan mahasiswa berdasrkan nilai : "<<endl;
        for(int i=1; i<=n; i++){
		dummy[i]=x[i];
	}//mengurutkan dari terbesar ke terkecil
        siswa swap;
        for(int i=0; i<n; i++)
            for(int j=0;j<n-i; j++)
            if(dummy[j].nilai < dummy[j+1].nilai){
			swap = dummy[j];
                        dummy[j]=dummy[j+1];
                        dummy[j+1]=swap;
		}
        
        cout<<"Hasil Setelah di urutkan "<<endl;
        cetak_data(dummy);
}



int main(){
	int pilih = 0;
	lagi:
		system("cls");
		cout<<"pilih menu : "<<endl;
		cout<<"1. Input Data "<<endl;
		cout<<"2. Cetak Data"<<endl;
		cout<<"3. Cari Data"<<endl;
		cout<<"4. Urut data (Exchange sort)"<<endl;
                cout<<"5. Filtering Data"<<endl;
                cout<<"6. Urut Nilai (Buble sort)"<<endl;
		cout<<"0. selesai "<<endl;
		cout<<"Pilih menu : ";cin>>pilih;
		switch(pilih){
			case 1 : if (n==20)//input data
                        {
				cout<<"Data penuh";
			}
			else {
				tambah_data(mhs);	
			}
			break;
			case 2: if (n==0)//cetak data
                        {
				cout<<"Data kosong";
			}
			else {
				cetak_data(mhs);	
			}
			break;
			case 3: if (n==0)//cari data
                        {
				cout<<"Data kosong";
			}
			else {
				cari_data(mhs);	
			}
			break;
			case 4: if (n==0)//urut data(exchange mode)
                        {
				cout<<"Data kosong";
			}
			else {
				urut_data(mhs);	
			}
                        break;
                        case 5: if (n==0)//filter data
                        {
				cout<<"Data kosong";
			}
			else {
				filter_data(mhs);	
			}
                        break;
                        case 6: if (n==0)//urut data(buble mode)
                        {
				cout<<"Data kosong";
			}
			else {
				urut_buble(mhs);	
			}
			break;
			case 0 : cout<<"TerimaKasih"<<endl;//pilihan keluar
			break;
			default : cout<<"salah pilih menu"<<endl;//pilihan tidak sesuai
			break;
			
		}
		system("pause");
		if(pilih!=0)goto lagi;
		
		
		
return 0;		
}