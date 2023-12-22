#include <stdio.h>
#include <string.h>
#include "dataPembeli.h"

DataPembeli dataPembeli [MAX_PEMBELI];
int dataDaf[MAX_PEMBELI];
int data_Log[MAX_PEMBELI];
int data_Fog[MAX_PEMBELI];

// Daftar sebagai pembeli 
void daftarPembeli(DataPembeli *dataPembeli, int *dataDaf, int *numRegistrations) 
{

    printf("Daftar\n");
    
    printf("Masukkan Nama: ");
    fgets(dataPembeli[*dataDaf].nama, sizeof(dataPembeli[*dataDaf].nama), stdin);
    
    printf("Masukkan No Handphone: ");
    fgets(dataPembeli[*dataDaf].nomor, sizeof(dataPembeli[*dataDaf].nomor), stdin);

    printf("Masukkan Alamat: ");
    fgets(dataPembeli[*dataDaf].alamat, sizeof(dataPembeli[*dataDaf].alamat), stdin);

    printf("Masukkan Email: ");
    fgets(dataPembeli[*dataDaf].email, sizeof(dataPembeli[*dataDaf].email), stdin);

    printf("Masukkan Password: ");
    fgets(dataPembeli[*dataDaf].password, sizeof(dataPembeli[*dataDaf].password), stdin);

    FILE *file = fopen("buyyer_data.txt", "a");
    if (file != NULL)
    {
        // Save data to the file
        fprintf(file, "%s|%s|%s|%s|%s\n", dataPembeli[*dataDaf].nama, dataPembeli[*dataDaf].nomor, dataPembeli[*dataDaf].alamat, dataPembeli[*dataDaf].email, dataPembeli[*dataDaf].password);
        fclose(file);
    }

    // Increment the registration counter
    (*dataDaf)++;
}

// Login sebagai pembeli
int loginPembeli(DataPembeli *dataPembeli, int data_Log, int numRegistrations) {
    char inputEmail[70];
    char inputPassword[48];

    printf("Masukkan Email: ");
    fgets(inputEmail, sizeof(inputEmail), stdin);

    for (int i = 0; i < numRegistrations; i++) {
        if (strcmp(inputEmail, dataPembeli[i].email) == 0) {
            printf("Masukkan Password: ");
            fgets(inputPassword, sizeof(inputPassword), stdin);

            if (strcmp(inputPassword, dataPembeli[i].password) == 0) {
                printf("Login berhasil!\n");
                return 1; // Login berhasil
            } else {
                printf("Password salah!\n");
                return 0; // Password salah
            }
        }
    }

    printf("Email tidak ditemukan!\n");
    return -1; // Email tidak ditemukan
}

// Function untuk pemulihan password
void lupaPassword(DataPembeli *dataPembeli, int data_Fog, int numRegistrations) {
    char inputEmail[70];

    printf("Masukkan Email: ");
    fgets(inputEmail, sizeof(inputEmail), stdin);

    for (int i = 0; i < numRegistrations; i++) {
        if (strcmp(inputEmail, dataPembeli[i].email) == 0) {
            // Simulasi pengiriman email pemulihan
            printf("Email pemulihan password telah dikirim ke %s\n", inputEmail);
            return;
        }
    }

    printf("Email tidak ditemukan!\n");
}
