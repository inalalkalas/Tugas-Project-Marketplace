#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataPembeli/dataPembeli.h"
#include "../include/dataPenjual/dataPenjual.h"
#include "../include/produkGudang/produkGudang.h"

// menampilkan data pada penjual
void tampilSbgPenjual ()     
{
    FILE *file = fopen(DATABASE_FILE_PRODUK, "a+");

    if (file == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }
    int choice6;
    char editName[50];
    char deleteName[50];


    do{

        printf("1. Tambahkan Produk\n");
        printf("2. List Produk\n");
        printf("3. Edit Produk\n");
        printf("4. Delete Produk\n");
        printf("5. back\n");
        printf("6. exit\n");
        printf("Pilihan Anda: ");
        scanf("%i", &choice6);

        switch (choice6){

        case 1:
            printf("\n----------------------------------------------------------------------------------\n");
            addProduct(file);
            break;
        case 2:
            printf("\n----------------------------------------------------------------------------------\n");
            viewProducts(file);
            printf("\n----------------------------------------------------------------------------------\n");
            break;
        case 3:
                printf("\n----------------------------------------------------------------------------------\n");
                printf("Enter Product name to edit: ");
                scanf("%s", editName);
                editProduct(file, editName); // edit data produk yang sudah diinputkan 
                break;
        case 4:
                printf("\n----------------------------------------------------------------------------------\n");
                printf("Enter product name to delete: ");
                scanf("%s", deleteName);
                deleteProduct(file, deleteName);
        case 5:
            printf("\n----------------------------------------------------------------------------------\n"); 
            return -1;
            break;
        case 6:
            exit (1);
            break;

        }

    } while (choice6 != 6);

    fclose(file);
}


/*
    baris ini adalah baris untuk menu pembeli dll
*/

// menampilkan data pada pembeli
void tampilSbgPembeli() 
{

    int choice7;

    do{

        printf("1. searching\n");
        printf("2. keranjang\n");
        printf("3. exit\n");
        printf("Pilihan Anda: ");
        scanf("%i", &choice7);

        switch (choice7){

            case 1:
                    printf("\n----------------------------------------------------------------------------------\n");
                    searchBarang();
                    break;
            case 2:
                    printf("\n----------------------------------------------------------------------------------\n");
                    listKeranjang();
                    break;
            case 3:
                    exit (1);
                    break;
        }

    } while (choice7 != 3);

}

// menampilkan baarang yang sudah di cari
void searchBarang()
{
    PROduct product[MAX_PRODUCTS];

    FILE *file = fopen(DATABASE_FILE_PRODUK, "r");

    if (file == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }    

    int choice5;
    char searchName[100];


    do{
   
        printf("Menu\n");
        printf("1. Search and Sort by Harga Tertinggi\n");
        printf("2. Search and Sort by Harga Terendah\n");
        printf("3. Keranjang\n");
        printf("4. Back\n");
        printf("5. Exit\n");
        scanf("%i", &choice5);

        switch (choice5) {
            case 1:
                // Search for a product by name and display in descending order
                printf("Masukkan nama produk yang ingin dicari: ");
                scanf("%s", searchName);
                searchProduct(file, searchName);
                quickSort(product, 0, MAX_PRODUCTS - 1, compareDescending);
                viewProducts(file);
                break;
            case 2:
                // Search for a product by name and display in ascending order
                printf("Masukkan nama produk yang ingin dicari: ");
                scanf("%s", searchName);
                searchProduct(file, searchName);
                quickSort(product, 0, MAX_PRODUCTS - 1, compareAscending);
                viewProducts(file);
                break;
            case 3:
                printf("\n----------------------------------------------------------------------------------\n");
                listKeranjang();
                break;
            case 4:
                return -1;
                break;
            case 5:
                exit(1);
                break;
        }

    } while (choice5 != 4);

    fclose(file);
}

// menampilkan isi pada keranjang 
void listKeranjang()
{
    FILE *file = fopen(DATABASE_FILE_PRODUK, "a+");

    if (file == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    PROduct allProducts[MAX_PRODUCTS];    
    int choice2;
    int jumlahAllProducts = 0;
    char deleteFromCartName[50];


    do{

        printf("1. Tambah Item\n"); // tambah item pada barang yang berada di keranjang
        printf("2. Remove Item\n"); // mengurangi item yang dibeli 
        printf("3. Remove\n"); //delete produk
        printf("4. Tampilan barang Keranjang\n"); //tampilan item
        printf("5. back\n"); //kembali ke halaman menu utama
        printf("6. exit\n"); //keluar dari program
        printf("Pilihan Anda: ");
        scanf("%d", &choice2);

        switch (choice2)
        {
        case 1:
            printf("\n----------------------------------------------------------------------------------\n");
            tambahItem(allProducts, &jumlahAllProducts, allProducts, jumlahAllProducts);
            tampilanKeranjang(allProducts, jumlahAllProducts);
            break;
        case 2:
            printf("\n----------------------------------------------------------------------------------\n");
            removeItem(allProducts, &jumlahAllProducts);            
            break;
        case 3:
            printf("\n----------------------------------------------------------------------------------\n");
            printf("Enter product name to delete from cart: ");
            scanf("%s", deleteFromCartName);
            deleteProduk(file, allProducts, &jumlahAllProducts, deleteFromCartName);            
            break;
        case 4:
            tampilanKeranjang(allProducts, jumlahAllProducts);    
            break;
        case 5:
            printf("\n----------------------------------------------------------------------------------\n");
            return -1;
            break;
        case 6: 
            exit(1);
            break;
        }

    } while (choice2 != 6);

    fclose(file);
}


/*
    main program 
*/

int main () {
    int choice = 0;
    int Choice;
    int choicePembeli;
    char email[MAX_EMAIL];
    char password_pembeli[MAX_PASSWORD];
    int *result = 0;
    int *result1 = 0;
    char nama_pembeli[MAX_NAMA];
    char alamat_pembeli[MAX_ALAMAT];
    char email_penjual[MAX_EMAIL];
    char password_penjual[MAX_PASSWORD];


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
                            daftarPenjual();
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPenjual();
                            break;
                        case 2:
                            printf("\n----------------------------------------------------------------------------------\n");
                            result1 = loginPenjual(email_penjual, password_penjual);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPenjual();
                            break;
                        case 3:
                            printf("\n----------------------------------------------------------------------------------\n");
                            fogPassword();
                            printf("\n----------------------------------------------------------------------------------\n");
                            result1 = loginPenjual(email_penjual, password_penjual);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPenjual();
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
                            daftarPembeli();
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPembeli();
                            printf("\n----------------------------------------------------------------------------------\n");
                            break;
                        case 2:
                            printf("\n----------------------------------------------------------------------------------\n");
                            result = loginUser(email, password_pembeli);
                            printf("\n----------------------------------------------------------------------------------\n");
                            tampilSbgPembeli();
                            printf("\n----------------------------------------------------------------------------------\n");
                            break;
                        case 3:
                            printf("\n----------------------------------------------------------------------------------\n");
                            forgotPassword();
                            printf("\n----------------------------------------------------------------------------------\n");
                            result1 = loginUser(email, password_pembeli);
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

    
