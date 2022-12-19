#include <iostream> // Di gunakan untuk menjalankan perintah input dan output. seperti cin, cout.
#include <string.h> // Di gunakan untuk membaca String
using namespace std; //Menggunakan skope std sebagai nama skope untuk penggunaan instruksi, misalnya std::cin std::cout
struct buku //membuat struktur buku
{
	int kodeB,stock;
	char judul[20];
	int b;
}buku[100]; //deklarasikan
struct pinjam //membuat struktur pinjam
{
	int kodepinjam,d,kB,tglpin,tglbalik,dipinjem;
	char namap[40];
	char alamat[40];
	char status;
}pinjembuku[100]; //deklarasikan

void exit(){
    cout<<"-- Anda Telah Logout -- \n";
    cout<<"-- Terima Kasih atas kunjungannya --\n";
}
void menuPerpustakaan(){
    cout<<"---- Aplikasi Perpustakaan ----"<<endl;
    cout<<"-------- Menu ----------\n";
    cout<<" 1. Input Buku        \n";
    cout<<" 2. Daftar Buku       \n";
    cout<<" 3. Peminjaman      \n";
    cout<<" 4. Pengembalian    \n";
    cout<<" 5. Laporan   \n";
    cout<<" 6. Exit                \n";
    cout<<"----------------------\n";

}
//body
int main(){
	system("cls"); //di gunakan untuk membersihkan layar output, karena setelah kita menjalankan isi program (program 1,2,3)

	int jmlbuk,c,f,g,jmlpin,lp,kodepin,stok;
	int b=-1;
	int d=-1;
	char yn,yn2;

	//membuat username dan password
	login:
	string user = "";
	string pass = "";
	string* idpass;
	idpass=&user;
	idpass=&pass;
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\t\t -------  Selamat Datang di Perpustakaan Unsika --------\n\n";
	cout << "\t\t\t  Username : ";
	cin>> user;
	cout << "\t\t\t  Password : ";
	cin >> pass;

    cout<<endl;
	if(user == "algoritma" && pass == "alpro123"){
		cout << "\n\n Anda berhasil login. \n" << endl;
		system("pause");
		system("cls");
		goto mulaimenu;
	}else if(user == "algoritma" && pass != "alpro123"){
		cout<<" Password Anda Salah \n";
   	    system("pause");
   	    system("cls");
	 	goto login;
	}else if(user != "algoritma" && pass == "alpro123"){
        cout<<" Username Anda Salah \n";
   	    system("pause");
   	    system("cls");
	 	goto login;
	}else{
        cout<<" Username dan Password Anda Salah \n";
   	    system("pause");
   	    system("cls");
	 	goto login;
	}
	//end membuat username dan password

	mulaimenu: //mulai menu
	int pil;
	menuPerpustakaan();
    cout<<"Masukan Pilihan anda[ 1 s.d. 6 ] = ";
    cin>>pil;

	if(pil ==1){ //input buku
		inbuk:
		system("cls");
		cout<<"\n"<<endl;
		cout<<"\t\t\tInput Buku : \n"; //input buku berdasarkan jumlah  buku yang mau di input
		cout<<"\t\t\t____________________\n"<<endl;
		cout<<endl;
        b++;
			cout<<" Masukan data buku Ke \t: "<<b+1<<endl;
			cout<<" Kode Buku \t\t:";
			cin >> buku[b].kodeB;
			cout<<" judul Buku\t\t:";
			cin >> buku[b].judul;
			cout<<" Jumlah Buku\t\t:";
			cin >> buku[b].stock;
			cout<<endl;
			cout<<"Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";
			cin>>yn;
			if(yn=='y'||yn=='Y'){
				goto inbuk;
			}else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				goto mulaimenu;
			}
		{
			cout << "\n\n Data Berhasil Disimpan \n" << endl;
			system("pause");
			system("cls");
			goto mulaimenu;
		}

	}else if( pil == 2 ){ // melihat daftar buku yang sudah di masukkan
		system("cls");
		cout<<"\n"<<endl;
		cout<<"\t\t\tDaftar Buku"<<endl;
		for(c=0;c<=b;c++){
			stok = buku[c].stock-pinjembuku[c].dipinjem;
			cout << "No."<<c+1<<endl;
			cout << "Kode Buku: "<< buku[c].kodeB<<endl;
			cout << "Judul Buku: "<< buku[c].judul<<endl;
			cout << "Jumlah Buku: "<< stok <<endl;
			cout << "Buku Keluar: "<< pinjembuku[c].dipinjem<<endl;
			cout<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
		goto mulaimenu;

	}else if(pil == 3){ // Input transaksi peminjaman Buku
		transaksipinjem:
			d++;
			system("cls");
			cout<<"\n"<<endl;
			cout<<"\t\t\t Transaksi Peminjaman : \n";
			cout<<"\t\t\t____________________\n"<<endl;
			cout<<endl;
				cout<<" Masukan data Pinjaman Ke \t: "<<d+1<<endl;
				cout<<" Kode Pinjaman \t\t\t:";
				cin >> pinjembuku[d].kodepinjam;
				cout<<" Kode Buku \t\t\t:";
				cin >> pinjembuku[d].kB;
				cout<<" Nama Penyewa Buku \t\t:";
				cin >> pinjembuku[d].namap;
				cout<<" Alamat Penyewa \t\t:";
				cin >> pinjembuku[d].alamat;
				cout<<" Tanggal Pinjam (DDMMYYYY)\t:";
				cin >> pinjembuku[d].tglpin;
				cout<<" Tanggal Balik (DDMMYYYY)\t:";
				cin >> pinjembuku[d].tglbalik;
				lp = (pinjembuku[d].tglbalik-pinjembuku[d].tglpin)/1000000;
				if(lp<=0){
                        cout << "Lama Pinjaman(jika jumlah hari pada bulan peminjaman 30 hari)\t\t\t: " << lp+29 << endl;
                        cout << "Lama Pinjaman(jika jumlah hari pada bulan peminjaman 31 hari)\t\t\t: " << lp+30 << endl;
                        cout << "Lama Pinjaman(jika bulan peminjaman pada bulan februari)\t\t\t: " << lp+27 << endl;
                        cout << "Lama Pinjaman(jika bulan peminjaman pada bulan februari pada tahun kabisat)\t\t\t: " << lp+28 << endl;
                        if(lp+29||lp+27||lp+28||lp+30>14){
                            cout << "WARNING!!! anda akan terkena denda Rp 100.000 jika melanjutkan(y/n): ";
                            cin >>yn2;
                            if((yn2=='y')||(yn2=='Y')){
                                cout << "Anda terkena denda Rp 100.000" << endl;
                            }else{
                                system("pause");
                                system("cls");
                                goto transaksipinjem;
                            }
                        }
                    }else{
                        cout<<" Lama Pinjaman \t\t\t:"<<lp<<" Hari"<<endl;
                        if(lp>14){
                            cout << "WARNING!!! anda akan terkena denda Rp 100.000 jika melanjutkan(y/n): ";
                            cin >>yn2;
                            if((yn2=='y')||(yn2=='Y')){
                                cout << "Anda terkena denda Rp 100.000" << endl;
                            }else{
                                system("pause");
                                system("cls");
                                goto transaksipinjem;
                            }
                        }
                    }
				cout<<" banyak buku yang di pinjam  \t:";
				cin >> pinjembuku[d].dipinjem;
				cout<<endl;
				cout<<" Status dipinjam (y) ? \t\t:";
				cin>>pinjembuku[d].status;
				cout<<endl;
			cout<<"Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";cin>>yn;

			if(yn=='y'||yn=='Y'){
				goto transaksipinjem;
			}else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				goto mulaimenu;
			}

	}else if(pil == 4){ //untuk pengembalian buku
		system("cls");
		pengembalian:
			cout<<"\n"<<endl;
			cout<<"\t\t\tMasukan kode Peminjaman :";
			cin>>kodepin;
			cout<<"\t\t\t____________________\n"<<endl;
			cout<<endl;
			for(f=0;f<=d;f++){
				if(pinjembuku[f].kodepinjam==kodepin){
					cout<<" Nama Penyewa Buku \t\t:"<<pinjembuku[f].namap;
					cout<<endl;
					cout<<" Alamat Penyewa \t\t:"<<pinjembuku[f].alamat;
					cout<<endl;
					if(buku[f].kodeB==pinjembuku[f].kB){
						cout<<" Judul Buku \t\t\t:"<<buku[f].judul<<endl;
					}
					cout<<" Tanggal Pinjam (DDMMYYYY)\t:"<<pinjembuku[f].tglpin;
					cout<<endl;
					cout<<" Tanggal Balik (DDMMYYYY)\t:"<<pinjembuku[f].tglbalik;
					cout<<endl;
					lp = (pinjembuku[f].tglbalik-pinjembuku[f].tglpin)/1000000;
					if(lp<=0){
                        cout << "Lama Pinjaman(jika jumlah hari pada bulan peminjaman 30 hari)\t\t\t: " << lp+29 << endl;
                        cout << "Lama Pinjaman(jika jumlah hari pada bulan peminjaman 31 hari)\t\t\t: " << lp+30 << endl;
                        cout << "Lama Pinjaman(jika bulan peminjaman pada bulan februari)\t\t\t: " << lp+27 << endl;
                        cout << "Lama Pinjaman(jika bulan peminjaman pada bulan februari pada tahun kabisat)\t\t\t: " << lp+28 << endl;
                    if(lp+29||lp+27||lp+28||lp+30>14){
                            cout << "Anda akan terkena denda Rp 100.000";
                        }
                    }else{
                        cout<<" Lama Pinjaman \t\t\t:"<<lp<<" Hari"<<endl;
                        if(lp>14){
                            cout << "Anda akan terkena denda Rp 100.000";
                        }
                    }
					cout<<endl;
					cout<<" banyak buku yang di pinjam  \t:"<<pinjembuku[f].dipinjem;
					cout<<endl;
					cout<<" Status : "<<pinjembuku[f].status;
					if((pinjembuku[f].status == 'y') || (pinjembuku[f].status == 'Y')){
						cout<<" (di Pinjam) "<<endl;
					}else{
						cout<<" (di kembalikan) "<<endl;
					}
					cout<<endl;
					cout<<" Sudah di kembalikan ? (y/n) : ";
					cin>>yn;
					if((yn == 'Y') || (yn == 'y')){
						cout<<" ganti status ( input n ) :";
						cin>>pinjembuku[f].status;
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						goto mulaimenu;
					}else{
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						goto mulaimenu;
					}
				}else{
					cout << "\n\n Data Tidak Di temukan \n" << endl;
					cout<<" Apakah ingin mengulang kembali ? (y/n) : ";cin>>yn;
					if(yn == 'Y' || yn == 'y'){
						system("cls");
						goto pengembalian;
					}else{
						system("cls");
						goto mulaimenu;
					}
				}
			}
	}else if(pil == 5){ //melihat laporan buku
		system("cls");
			cout<<"\n"<<endl;
			cout<<"\t\t\t laporan Perpustakaan\n";
			cout<<"\t\t\t____________________\n"<<endl;
			for(g=0;g<=b;g++){
				if(pinjembuku[g].kB==buku[g].kodeB){
					cout << "No. "<<g+1<< endl;
					cout << "Kode Peminjam: "<<pinjembuku[g].kodepinjam<< endl;
					cout << "Judul Buku: " <<buku[g].judul<< endl;
					cout << "Nama Peminjam: "<<pinjembuku[g].namap<< endl;
					cout << "Alamat Peminjam: "<<pinjembuku[g].alamat<< endl;
					cout << "Tanggal Pinjam: "<<pinjembuku[g].tglpin<<endl;
					cout << "Tanggal Balik: " <<pinjembuku[g].tglbalik<<endl;
					cout << "Status Peminjaman: "<<pinjembuku[g].status<<endl;
					if((pinjembuku[g].status == 'y') || (pinjembuku[g].status == 'Y')){
						cout<<" (di Pinjam) "<<endl;
					}else{
						cout<<" (di kembalikan) "<<endl;
					}
					cout<< "Jumlah buku yang dipinjam: " <<pinjembuku[g].dipinjem<<endl;
					cout<<endl;
				}
			}
		system("pause");
		system("cls");
		goto mulaimenu;

	//footer
	}else if(pil == 6){ //keluar
		system("pause");
		system("cls");
		exit();
		system("pause");
		system("cls");
		goto login;

	}else{ //jika inputan semua salah
		system("cls");
		goto mulaimenu;
	}


}
