#include <iostream>
#include <string>
using namespace std;

const int maxKamar=5;
const int maxAntrian=4;
struct Kamar{
    int no ; 
    string nama_pelanggan;
    bool terisi;
};

struct Pesan{
	int awal, akhir;
    string data[maxAntrian];
    int nomor[maxAntrian];
    int umur[maxAntrian];
    int totalAntri=0;
    Kamar dataKamar[maxKamar];
}pesan;

struct Baru{
    int atas;
    string data[maxAntrian];
}pelangganBaru;

bool penuh;
bool kosong;

bool DataPenuh(){
   if (pesan.akhir==maxAntrian-1){
      penuh= true;
   }else {
penuh= false;
   }
   return (penuh);
}

bool DataKosong(){
   if (pesan.akhir==-1){
      kosong= true;
   }else {
   kosong= false;
   }
   return (kosong);
}

bool CekKamar()
{
    for(int i=0;i<maxKamar;i++)
    {
        if(pesan.dataKamar[i].terisi==false)
        {
            return true;
        }
    }
    return false;
}
void PesanKamar(string nama)
{
    for(int i=0;i<maxKamar;i++)
    {
        if(pesan.dataKamar[i].terisi==false)
        {
            pesan.dataKamar[i].terisi=true;
            pesan.dataKamar[i].nama_pelanggan=nama;
            return;
        }
    }
}
void BuatKamar()
{
    for(int i=0;i<maxKamar;i++)
    {
        pesan.dataKamar[i].no=i+1;
    }
}

void CekKamarPelanggan()
{
    int target=0,no=0;
    string nama;
    cout<<"\nNo Kamar siapa yang ingin dicari? ";cin>>nama;
    for(int i=0;i<maxKamar;i++)
    {
        if(pesan.dataKamar[i].nama_pelanggan==nama)
        {
            no=pesan.dataKamar[i].no;
            i=maxKamar;
        }
        target++;
    }
    if(target<maxKamar)
    {
        cout<<"\nno kamar"<<nama<<" adalah "<<no;
    }else{
        cout<<"\ntidak ada kamar yang ditempati oleh nama itu";
    }
}
void UmurPelanggan()
{
    int maxArray=pesan.akhir+1;
    int umurArray[maxArray];
    int temp;
    for(int i=0;i<maxArray;i++)
    {
        umurArray[i]=pesan.umur[i];
    }
    int n=maxArray;
    for(int i=1;i<n;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            if(umurArray[j]<umurArray[j-1])
            {
                temp=umurArray[j];
                umurArray[j]=umurArray[j-1];
                umurArray[j-1]=temp;
            }
        }
    }
    for(int i=0;i<maxArray;i++)
    {
        cout<<umurArray[i]<<" ";
    }
}
void AntriPelanggan()
{
    string nama;
    if (!DataPenuh()){
        if(CekKamar())
        {
            pesan.akhir++;
            pesan.totalAntri++;
            pesan.nomor[pesan.akhir]=pesan.totalAntri;
            cout<<"Masukkan Nama : ";
            cin>>nama;
            pesan.data[pesan.akhir]=nama;
            cout<<"masukkan umur anda :";
            cin>>pesan.umur[pesan.akhir];
            PesanKamar(pesan.data[pesan.akhir]);
            if(pelangganBaru.atas!=maxAntrian-1)
            {
                pelangganBaru.atas++;
                pelangganBaru.data[pelangganBaru.atas]=nama;
            }else
            {
                cout<<"\nStack penuh! data Pelanggan terbaru tidak dapat dimasukkan!";
            }
        }else{
            cout<<"kamar penuh!";
        }
        }else {
            cout << "Antrean penuh!";
    };
}

void KamarSiap()
{
    if (!DataKosong()){
        cout<<"Panggilan Nomor : ";cout<<pesan.nomor[pesan.awal+1];
        cout<<"\nAtas nama : ";cout<<pesan.data[pesan.awal+1]<<endl;
        for (int i=1;i<=pesan.akhir+1;i++){
            pesan.data[i-1]=pesan.data[i];
            pesan.nomor[i-1]=pesan.nomor[i];
            pesan.umur[i-1]=pesan.umur[i];
        }
            pesan.akhir--;
    }else {
        cout << "Antrian kosong";
    }
}

void PelangganTerbaru()
{
    if(pelangganBaru.atas>-1)
    {
        cout<<"\nPelanggan TErbaru :"<<pelangganBaru.data[pelangganBaru.atas];
        pelangganBaru.atas--;
    }else{
        cout<<"\nStack kosong!";
    }
}

int main() {
    // Antrian 
    BuatKamar();
    pelangganBaru.atas=-1;
    int *jmlAntrian=&pesan.akhir;
    pesan.awal=-1;
    pesan.akhir=-1;
    int pil;
    do {
        cout << "\nPilihan!"<<endl;
        cout << "1. Antrikan Pelanggan"<<endl;
        cout << "2. Kamar siap"<<endl;
        cout << "3. Lihat Jumlah Antrian"<<endl;
        cout << "4. Cek Kamar Pelanggan"<<endl;
        cout << "5. Sorting umur pelanggan"<<endl;
        cout << "6. Info Pelanggan terbaru"<<endl;
        cout << "7. Tutup Antrian"<<endl; 
        cout << "Silahkah Pilih : "; cin>>pil;
        switch (pil){
            case 1 :
                AntriPelanggan();
                break;
            case 2 :
                KamarSiap();
                break;  
            case 3 :
                //cout<<"Jml Antrian tersisa: ";cout<<pesan.akhir+1;
                cout<<"Jml Antrian tersisa: ";cout<<*jmlAntrian+1;
                break;
            case 4:
                CekKamarPelanggan();
            break;
            case 5:
                UmurPelanggan();
            break;
            case 6:
                PelangganTerbaru();
            break;
        }
    }
         
    while (pil !=7);
    
    return 0;
}
