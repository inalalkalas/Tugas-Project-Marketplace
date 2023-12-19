#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "dataPembeli.h"
#include "dataPenjual.h"
#include "produkGudang.h"

// struct pada data
struct All {
    char namaBarangPenjual [50]; 
    char namaBarangPembeli [50];
    int hargaBarangJual, hargaBarangBeli;
};

// fungsi untuk kembali ke menu 
void tandaReturn(char choieceR){
    if (choieceR == 'r' || choieceR == 'R'){
        return 1;
    } else {
        return 0;
    }
}

// perulangan untuk exit 
void tandaExit(char choiceE){
    if (choiceE == 'e' || choiceE == 'E'){
        return 1;
    } else
        return 0;
}

// membersihkan enter
void clearNewline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// mengurutkan harga dari yang terendah
void hargaTertinggi(struct namaBarangPenjual *produk, int start, int finish){
    
    int start, finish, pivot, temp, cek;
    start = x;
    finish = y;
    pivot = y;

    if (start <= finish){
        while (start < finish){
            while (z[start] <= z[pivot]){
                start++;
            }
            while (z[finish] > z[pivot]){
                finish--;
            }
            if (start < finish) {
                temp = z[finish];
                z[finish] = z[start];
                z[start] = temp;
            }
        }

        temp = z[pivot]; 
        z[pivot] = z[finish];
        z[finish] = temp;

        quicksort(x, finish - 1, z);
        quicksort(finish + 1, y, z);
    }
}

// mengurutkan harga dari yang terbesar
void hargaTerendah(struct namaBarangPenjual *produk, int start, int finish){

    int start, finish, pivot, temp;

    start = x;
    finish = y;
    pivot = y;

    if (start <= finish) {
        while (start < finish) {
            while (z[start] >= z[pivot]) {
                start++;
            }
            while (z[finish] < z[pivot]) {
                finish--;
            }
            if (start < finish) {
                temp = z[finish];
                z[finish] = z[start];
                z[start] = temp;
            }
        }

        temp = z[pivot];
        z[pivot] = z[finish];
        z[finish] = temp;

        quicksort(x, finish - 1, z);
        quicksort(finish + 1, y, z);
    }
}


// menampilkan data pada pilihan pertama
void tampilanData (){
    char choice [10];

    do {
                
        printf("Login Sebagai:\n");
        printf("1. Penjual\n");
        printf("2. Pembeli\n");
        printf("E. Exit\n");
        printf("Pilihan Anda: ");
        fgets(choice, sizeof(choice), stdin);

        switch (choice [0]){

            case '1': 

                    do{
                        char Choice [10];

                        printf("1. Daftar\n");
                        printf("2. Login\n");
                        printf("3. lupa password\n");
                        printf("E. exit\n");
                        printf("Pilihan anda ");
                        fgets(Choice, sizeof(Choice), stdin);

                        switch (Choice[0]){

                            case '1':
                                daftarPenjual();
                                tampilSbgPenjual();
                                break;
                            case '2':
                                loginPenjual();
                                tampilSbgPenjual();
                                break;
                            case '3':
                                lupaPassword();
                                loginPenjual();
                                tampilSbgPenjual();
                                break;
                            default:
                                return 1;
                                break;

                    } while (choice != 'e' || choice !='E');

                    break;

            case '2':

                    do{

                    char choice [10];

                    printf("1. Daftar\n");
                    printf("2. Login\n");
                    printf("3. lupa password\n");
                    printf("4. Lanjut\n");
                    printf("E. exit\n");
                    printf("Pilihan Anda ");
                    fgets(choice, sizeof(choice), stdin);

                    switch (choice [0])
                    {
                    case '1':
                        daftarPembeli();
                        tampilSbgPembeli();
                        break;
                    case '2':
                        loginPembeli();
                        tampilSbgPembeli();
                        break;
                    case '3':
                        //
                        loginPembeli();
                        tampilSbgPembeli;
                        break;
                    case '4':
                        tampilSbgPembeli();
                        break;
                    case 'E':
                        tandaExit();
                    default:
                        return 1;
                        break;
                    }



                    } while (choice != 'e' || choice != "E");

            default:
                tandaExit();
            }
 
        } while (choice != 'e' || choice != 'E'); 
    } 
}

// menampilkan data pada penjual
void tampilSbgPenjual () {
    char choice6 [20];

    do{

        printf("1. Tambahkan Item\n");
        printf("2. lihat data produk\n");
        printf("3. lihat tanggal restock\n");
        printf("4. lihat estimasi restock\n");
        printf("5. setting\n");
        printf("E. exit\n");
        printf("Pilihan Anda: ");
        fgets(choice6, sizeof(choice6), stdin);

        switch (choice6 [0]){

        case '1':
            tambahItemPenjual();
            break;
        case '2':
            tampilItem();
            break;
        case '3':

            break;
        case '4':

            break;
        case '5': 
            settingPenjual();
            break;
        default:
            break;

        }

    } while (choice6 != 'e' || choice6 != 'E');

}

// menampilkan barang yang sudah ditambahkan
void tampilItem(){
        char choice4 [20];

    do{

        printf("1. Edit Produk\n"); // mengedit data produk yang beradadi file handling
        printf("2. Remove Produk\n"); // delete produk 
        printf("E. exit\n"); // keluar dari program
        printf("Pilihan Anda: ");
        fgets(choice4, sizeof(choice4), stdin);

        switch (choice4 [0]){

        case '1': // edit data produk yang sudah diinputkan 
                break;
        case '2': // menghapus data produk 
                break;
        case 'E':// keluar program
                break;
        default:

        }

    } while (choice4 != 'e' || choice4 != 'E');


}


// menampilkan settingan untuk penjual melengkapi biodata
void settingPenjual(){
    char choice8 [10];

    do{

        printf("Menu\n");
        printf("1. Nama\n"); // nama dari pembeli 
        printf("2. Alamat\n"); // alamat pembeli 
        printf("3. No.Handphone\n"); // no handphone pembeli yang sudah login
        printf("B. back\n"); // kembali ke menu penjual 
        printf("E. exit\n");
        printf("Pilihan Anda: ");
        fgets(choice8, sizeof(choice8), stdin);


    } while (choice8 != 'e' || choice8 != 'E');
}


// menampilkan data pada pembeli
void tampilSbgPembeli() {
    char choice7 [10];

    do{

        printf("1. searching\n");
        printf("2. keranjang\n");
        printf("3. pesan\n");
        printf("4. notifikasi\n");
        printf("5. setting\n");
        printf("E. exit");
        printf("Pilihan Anda: ");
        fgets(choice7, sizeof(choice7), stdin);

    } while (choice7 != 'e' || choice7 != 'E');
}


// menampilkan baarang yang sudah di cari
void tampilSearchBarang(){
    char choice5 [15];

    do{

        printf("S. search\n");
        printf("Menu\n");
        printf("1. Urutkan dari Harga Tertinggi\n");
        printf("2. Urutkan dari Harga Terendah\n");
        printf("B. back\n");
        printf("E. exit\n");
        fgets(choice5, sizeof(choice5), stdin);


    } while (choice5 != 'e' || choice5 != 'E');
}

// menampilkan isi pada keranjang 
void tampilanKeranjang(){
    char choice2 [10];

    do{

        printf("+. Tambah Item\n"); // tambah item pada barang yang berada di keranjang
        printf("-. Remove Item\n"); // mengurangi item yang dibeli 
        printf("R. Remove\n"); //delete produk
        printf("B. back\n"); //kembali ke halaman menu utama
        printf("E. exit\n"); //keluar dari program
        printf("Pilihan Anda: ");
        fgets(choice2, sizeof(choice2), stdin);

    } while (choice2 != 'e' || choice2 != 'E');
}

// menampilkan profil dan juga data tentang penjual
void tampilanProfilePenjual(){
    char choice3 [20];    

    do{

        printf("%c", &*dataPenjual.nama ); // nama toko
        printf("1. Daftar produk\n"); // semua produk penjual
        printf("2. Tentang penjual\n"); // informasi tentang nama toko 
        printf("B. back\n"); // kembali ke searching
        printf("E. exit\n"); // keluar dari program
        printf("Pilihan Anda: ");
        fgets(choice3, sizeof(choice3) ,stdin);

    } while (choice3 != 'e' || choice3 != 'E');
}

// menampilkan settingan untuk penjual melengkapi biodata
void settingPembeli(){
    char choice1[13];

    do{

        printf("Menu\n");
        printf("1. Nama\n"); // nama dari pembeli 
        printf("2. Alamat\n"); // alamat pembeli 
        printf("3. No.Handphone\n"); // no handphone pembeli yang sudah login
        printf("B. back\n"); // kembali ke menu penjual 
        printf("E. exit\n");
        printf("Pilihan Anda: ");
        fgets(choice1, sizeof(choice1), stdin);

    } while (choice1 != 'e' || choice1 != 'E');

}

int main () {
    do{
        tampilanData();

    } while (1);

    return 0;
}
