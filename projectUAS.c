#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dataPembeli.h"
#include "dataPenjual.h"
//#include "produkGudang.h"

// menampilkan data pada penjual
void tampilItem();
void estimasiRestock();
void restock();
void settingPenjual();

void tampilItem() {
    // Implementasi logika menampilkan data produk
    printf("Implementasi logika menampilkan data produk\n");
}

void estimasiRestock() {
    // Implementasi logika menampilkan estimasi restock
    printf("Implementasi logika menampilkan estimasi restock\n");
}

void restock() {
    // Implementasi logika restock
    printf("Implementasi logika restock\n");
}

void settingPenjual() {
    // Implementasi logika setting penjual
    printf("Implementasi logika setting penjual\n");
}

void tampilSbgPenjual () 
{
    int choice6;

    do{

        printf("1. Tambahkan Item\n");
        printf("2. lihat data produk\n");
        printf("3. lihat tanggal restock\n");
        printf("4. lihat estimasi restock\n");
        printf("5. setting\n");
        printf("6. back\n");
        printf("7. exit\n");
        printf("Pilihan Anda: ");
        scanf("%i", &choice6);

        switch (choice6){

        case 1:
            addProduct();
            printf("add product");
            break;
        case 2:
            tampilItem();
            printf("melihat");
            break;
        case 3:
            estimasiRestock();
            printf("estimasi");
            break;
        case 4:
            restock();
            printf("restock");
            break;
        case 5:
            settingPenjual(); 
            printf("setting");
            break;
        case 6:
            return 0;
            break;
        case 7:
            exit (1);
            break;
        }

        if (choice6 == 7){
            return 1;
        }

    } while (choice6 != 7);

}

// menampilkan barang yang sudah ditambahkan
/*void tampilItem()
{
    char choice4 [20];

    do{

        printf("1. Edit Produk\n"); // mengedit data produk yang beradadi file handling
        printf("2. Remove Produk\n"); // delete produk 
        printf("E. exit\n"); // keluar dari program
        printf("Pilihan Anda: ");
        fgets(choice4, sizeof(choice4), stdin);

        switch (choice4 [0]){

        case '1':
                editProduct(, &productName); // edit data produk yang sudah diinputkan 
                break;
        case '2':
                deleteProduct(); // menghapus data produk 
                break;
        case 'E':
                printf("Exiting...\n");           
                break;
        default:
               printf("Pilihan tidak valid. Silakan coba lagi.\n"); 
        }

    } while (choice4 != 'e' || choice4 != 'E');


}


// menampilkan settingan untuk penjual melengkapi biodata
void settingPenjual()
{
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

        switch (choice8){
            case 1:
                   printf("Masukan Nama: ");
                   break;
            case 2: 
                   printf("Masukan Alamat: ");
                   break;
            case 3:        
                   printf("Masukan No.Handphone: ");
                   break;
            case 'B':
            case 'b':
                     printf("Back to seller menu\n");
                     break;
            case 'E':
            case 'e':
                     printf("Exiting...\n");
                     break;
            default:
                    printf("Pilihan tidak valid. Silakan coba lagi.\n"); 
        }             

    } while (choice8 != 'e' || choice8 != 'E');
}*/


// menampilkan data pada pembeli
void tampilSbgPembeli() 
{
    int choice7;

    do{

        printf("1. searching\n");
        printf("2. keranjang\n");
        printf("3. setting\n");
        printf("4. exit\n");
        printf("Pilihan Anda: ");
        scanf("%i", &choice7);

        switch (choice7){

            case 1:
                    
                    break;
            case 2:
                    tampilanKeranjang();
                    break;
            case 3:
                    settingPembeli();
                    break;
            case 4:
                    exit (1);
                    break;
        }

    } while (choice7 != 4);
}


// menampilkan baarang yang sudah di cari
/*void tampilSearchBarang()
{
    char choice5 [15];

    do{

        printf("S. search\n");
        printf("Menu\n");
        printf("1. Urutkan dari Harga Tertinggi\n");
        printf("2. Urutkan dari Harga Terendah\n");
        printf("B. back\n");
        printf("E. exit\n");
        fgets(choice5, sizeof(choice5), stdin);

        swich (choice5) {
            case 'S':
            case 's':
                printf("Search\n");
                break;
            case '1':
                printf("Urutkan dari Harga Tertinggi\n");
                break;
            case '2':
                printf("Urutkan dari Harga Terendah\n");
                break;
            case 'B':
            case 'b':
                printf("Back to previous menu\n");
                break;
            case 'E':
            case 'e':
                printf("Exiting...\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (choice5 != 'e' || choice5 != 'E');
}*/

// menampilkan isi pada keranjang 
void tambahitem();
void tampilanKeranjang();
void removeItem();
void removeProduk();

void tambahitem() {
    // Implement logic to add an item to the shopping cart or product list
    printf("Implement tambahitem() logic here\n");
}
void removeItem() {
    // Implement logic to remove an item from the shopping cart or product list
    printf("Implement removeItem() logic here\n");
}

void removeProduk() {
    // Implement logic to delete a product from the system
    printf("Implement removeProduk() logic here\n");
}

void tampilanKeranjang()
{
    int choice2;

    do{

        printf("1. Tambah Item\n"); // tambah item pada barang yang berada di keranjang
        printf("2. Remove Item\n"); // mengurangi item yang dibeli 
        printf("3. Remove\n"); //delete produk
        printf("4. back\n"); //kembali ke halaman menu utama
        printf("5. exit\n"); //keluar dari program
        printf("Pilihan Anda: ");
        scanf("%d", &choice2);

        switch (choice2)
        {
        case 1:
            tambahItem();
            printf("Implement tambahitem() logic here\n");
            break;
        case 2:
            RemoveItem();
            printf("Implement removeItem() logic here\n");
            break;
        case 3:
            Remove();
            printf("Implement deleteProduk() logic here\n");
            break;
        case 4:
            return -1;
            break;
        case 5: 
            exit(1);
            break;
        }

    } while (choice2 != 5);
}

// menampilkan profil dan juga data tentang penjual
/*void tampilanProfilePenjual(struct Penjual *data)
{
    char choice3 [20]; 
    
    do{

        printf("%c", dataPenjual[*data_DafPJ].nama); // nama toko
        printf("1. Daftar produk\n"); // semua produk penjual
        printf("2. Tentang penjual\n"); // informasi tentang nama toko 
        printf("B. back\n"); // kembali ke searching
        printf("E. exit\n"); // keluar dari program
        printf("Pilihan Anda: ");
        fgets(choice3, sizeof(choice3) ,stdin);

    } while (choice3 != 'e' || choice3 != 'E');
}*/

// menampilkan settingan untuk penjual melengkapi biodata
void tampilnama();
void alamatNama();
void nomorHP();

void tampilnama() {
    // Implementasi logika menampilkan nama pembeli
    printf("Implementasi logika menampilkan nama pembeli\n");
}

void alamatNama() {
    // Implementasi logika menampilkan alamat pembeli
    printf("Implementasi logika menampilkan alamat pembeli\n");
}

void nomorHP() {
    // Implementasi logika menampilkan nomor handphone pembeli
    printf("Implementasi logika menampilkan nomor handphone pembeli\n");
}

void settingPembeli()
{
    int choice1;

    do{

        printf("Menu\n");
        printf("1. Nama\n"); // nama dari pembeli 
        printf("2. Alamat\n"); // alamat pembeli 
        printf("3. No.Handphone\n"); // no handphone pembeli yang sudah login
        printf("4. back\n"); // kembali ke menu penjual 
        printf("5. exit\n");
        printf("Pilihan Anda: ");
        scanf("%i", &choice1);

        switch (choice1)
        {
            case 1: 
                tampilnama();
                break;
            case 2:
                alamatNama();
                break;
            case 3:
                nomorHP();
                break;
            case 4:
                return -1;
                break;
            case 5:
                exit (1);
                break;        
        }

    } while (choice1 != 5);

}


int main () {
    int choice = 0;
    int dataDaf = 0;
    int data_DafPJ = 0;
    int numRegistrations = 0;
    int Choice;
    int choicePembeli;


    do {
        printf("Login Sebagai:\n");
        printf("1. Penjual\n");
        printf("2. Pembeli\n");
        printf("3. Exit\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        printf("\n------------------------------------------------------------------------------\n");

        switch (choice) {

            case 1:
                do {

                    printf("1. Daftar\n");
                    printf("2. Login\n");
                    printf("3. Lupa password\n");
                    printf("4. Exit\n");
                    printf("Pilihan anda: ");
                    scanf("%d", &Choice);

                    switch (Choice) {
                        case 1:
                            printf("\n----------------------------------------------------------------------------------\n");
                            daftarPenjual(dataPenjual, &data_DafPJ, &numRegistrations);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPenjual();
                            numRegistrations++;
                            break;
                        case 2:
                            printf("\n----------------------------------------------------------------------------------\n");
                            int result = loginPenjual(dataPenjual, &data_LogPJ, numRegistrations);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPenjual();
                            numRegistrations++;
                            break;
                        case 3:
                            printf("\n----------------------------------------------------------------------------------\n");
                            lupaPassword(&dataPenjual, &data_FogPJ, numRegistrations);
                            printf("\n----------------------------------------------------------------------------------\n");
                            loginPenjual(&dataPenjual, &data_LogPJ, numRegistrations);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPenjual();
                            numRegistrations++;
                            break;
                        case 4:
                            exit (1);
                            break;
                    }
                } while (Choice != 4 || Choice != 4);

                break;

            case 2:
                do {

                    printf("1. Daftar\n");
                    printf("2. Login\n");
                    printf("3. Lupa password\n");
                    printf("4. Lanjut\n");
                    printf("5. Exit\n");
                    printf("Pilihan Anda: ");
                    scanf("%i", &choicePembeli);

                    switch (choicePembeli) {
                        case 1:
                            printf("\n----------------------------------------------------------------------------------\n");
                            daftarPembeli(dataPembeli, &dataDaf ,&numRegistrations);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPembeli();
                            printf("\n----------------------------------------------------------------------------------\n");
                            break;
                        case 2:
                            printf("\n----------------------------------------------------------------------------------\n");
                            loginPembeli(dataPembeli, &data_Log, numRegistrations);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPembeli();
                            printf("\n----------------------------------------------------------------------------------\n");
                            break;
                        case 3:
                            printf("\n----------------------------------------------------------------------------------\n");
                            lupaPassword(dataPembeli, &data_Fog, numRegistrations);
                            printf("\n----------------------------------------------------------------------------------\n");
                            loginPembeli(dataPembeli, &data_Log, numRegistrations);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPembeli();
                            break;
                        case 4:
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPembeli();
                            break;
                        case 5:
                            exit (1);
                            break;
                        default:
                            return; // exit the program if an invalid choice is entered
                    }
                } while (choice != 5);

                break;

            case 3:
                printf("terima kasih :)\n");
                return -1;
                break;

            default:
                printf("terima kasih :)\n");
                return; // exit the program if an invalid choice is entered
            }
          choice++;  
        } while (choice != '3' && choice != '3');

        return 0;
    }

    
