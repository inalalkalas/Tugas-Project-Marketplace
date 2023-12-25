#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataPembeli.h"
#include "data.h"

DataPembeli dataPembeli [MAX_PEMBELI];


/*void encryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] = password[i] + 1;
    }
}*/

// Daftar sebagai pembeli 
void daftarPembeli() 
{
    void clearNewline(void);

    DataPembeli dataPembeli;
    FILE *file = fopen(DATABASE_FILE, "a");   

    printf("Daftar\n");
    
    printf("Masukkan Nama: ");
    scanf("%s", dataPembeli.nama_pembeli);

    printf("Masukkan No Handphone: ");
    scanf("%s", dataPembeli.nomor_pembeli);

    printf("Masukkan Alamat: ");
    scanf("%s", dataPembeli.alamat_pembeli);

    printf("Masukkan Email: ");
    scanf("%s", dataPembeli.email);

    printf("Masukkan Password: ");
    scanf("%s", dataPembeli.password_pembeli);
    //encryptPassword(dataPembeli.password_pembeli);

    fprintf(file, "%s|%s|%s|%s|%s\n", dataPembeli.nama_pembeli, dataPembeli.nomor_pembeli, dataPembeli.alamat_pembeli, dataPembeli.email, dataPembeli.password_pembeli);
   

    // Increment the registration counter
    fclose(file);
}

// Add this function definition

// Login sebagai pembeli

int loginUser(char *email, char *password_pembeli) {
    clearNewline();
    DataPembeli user;
    FILE *file = fopen(DATABASE_FILE, "r");

    while (fscanf(file, "%s %s %c", user.email, user.password_pembeli) != EOF) {
        if (strcmp(email, user.email) == 0) {
            encryptPassword(password_pembeli);
            if (strcmp(password_pembeli, user.password_pembeli) == 0) {
                fclose(file);
                return 1; // Pengguna ditemukan
            } else {
                printf("email tidak ditemukan");
            }
        }
    }
    fclose(file);
    return 0; // Pengguna tidak ditemukan
}

// Function untuk pemulihan password
void forgotPassword() {
    clearNewline();
    DataPembeli user;
    char email[MAX_EMAIL];
    FILE *file = fopen(DATABASE_FILE, "r");

    printf("Masukkan email Anda: ");
    scanf("%s", email);

    while (fscanf(file, "%s %s %c", user.email, user.password_pembeli) != EOF) {
        if (strcmp(email, user.email) == 0) {
            printf("Password Anda: %s\n", user.password_pembeli);
            fclose(file);
            return;
        }
    }

    printf("email tidak ditemukan.\n");
    fclose(file);
}

void display_name(char *nama_pembeli) {
    printf("Nama: %s\n", nama_pembeli);
}

void display_alamat(char *alamat_pembeli){
    printf("Alamat: %s \n", alamat_pembeli);
}

void display_nomor(char *nomor_pembeli){
    printf("Nomor Handphone: %s \n", nomor_pembeli);
}