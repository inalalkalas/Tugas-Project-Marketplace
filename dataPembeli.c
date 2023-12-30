#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataPembeli.h"

DataPembeli dataPembeli [MAX_PEMBELI];


void encryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] = password[i] + 1;
    }
}

void clearBufferPM() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Daftar sebagai pembeli 
void daftarPembeli() 
{
    clearBufferPM();
    DataPembeli dataPembeli;
    FILE *file = fopen(DATABASE_FILE_BUYYER, "a");   

    printf("Daftar\n");
    
    // Replace scanf for name with fgets
    printf("Masukkan Nama: ");
    fgets(dataPembeli.nama_pembeli, sizeof(dataPembeli.nama_pembeli), stdin);
    dataPembeli.nama_pembeli[strcspn(dataPembeli.nama_pembeli, "\n")] = '\0'; // Remove newline

    // Replace scanf for number with fgets
    printf("Masukkan No Handphone: ");
    fscanf(dataPembeli.nomor_pembeli, sizeof(dataPembeli.nomor_pembeli), stdin);
    dataPembeli.nomor_pembeli[strcspn(dataPembeli.nomor_pembeli, "\n")] = '\0'; // Remove newline

    // Replace scanf for address with fgets
    printf("Masukkan Alamat: ");
    fgets(dataPembeli.alamat_pembeli, sizeof(dataPembeli.alamat_pembeli), stdin);
    dataPembeli.alamat_pembeli[strcspn(dataPembeli.alamat_pembeli, "\n")] = '\0'; // Remove newline

    // Replace scanf for email with fgets
    printf("Masukkan Email: ");
    fgets(dataPembeli.email, sizeof(dataPembeli.email), stdin);
    dataPembeli.email[strcspn(dataPembeli.email, "\n")] = '\0'; // Remove newline

    // Replace scanf for password with fgets
    printf("Masukkan Password: ");
    fgets(dataPembeli.password_pembeli, sizeof(dataPembeli.password_pembeli), stdin);
    dataPembeli.password_pembeli[strcspn(dataPembeli.password_pembeli, "\n")] = '\0'; // Remove newline
    encryptPassword(dataPembeli.password_pembeli);

    fprintf(file, "%s|%s|%s|%s|%s\n", dataPembeli.nama_pembeli, dataPembeli.nomor_pembeli, dataPembeli.alamat_pembeli, dataPembeli.email, dataPembeli.password_pembeli);
   

    // Increment the registration counter
    fclose(file);
}

// Login sebagai pembeli

int loginUser(char *email, char *password_pembeli) {
    DataPembeli user;
    FILE *file = fopen(DATABASE_FILE_BUYYER, "r");

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
    DataPembeli user;
    char email[MAX_EMAIL];
    FILE *file = fopen(DATABASE_FILE_BUYYER, "r");

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
