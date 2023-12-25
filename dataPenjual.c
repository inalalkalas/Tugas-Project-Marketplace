#include <stdio.h>
#include <string.h>
#include "dataPenjual.h"
#include <stdlib.h>
#include "data.h"

DataPenjual dataPenjual [MAX_PEMBELI];

void encryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] = password[i] + 1;
    }
}
// Function to register as a seller
void daftarPenjual()
{

    void clearNewline(void);

    DataPenjual dataPenjual;
    FILE *file = fopen(DATABASE_FILE, "a");   

    printf("Daftar\n");
    
    printf("Masukkan Nama: ");
    scanf("%s", dataPenjual.nama_penjual);

    printf("Masukkan No Handphone: ");
    scanf("%s", dataPenjual.nomor_penjual);

    printf("Masukkan Alamat: ");
    scanf("%s", dataPenjual.alamat_penjual);

    printf("Masukkan Email: ");
    scanf("%s", dataPenjual.email_penjual);

    printf("Masukkan Password: ");
    scanf("%s", dataPenjual.password_penjual);
    encryptPassword(dataPenjual.password_penjual);

    fprintf(file, "%s|%s|%s|%s|%s\n", dataPenjual.nama_penjual, dataPenjual.nomor_penjual, dataPenjual.alamat_penjual, dataPenjual.email_penjual, dataPenjual.password_penjual);
   

    // Increment the registration counter
    fclose(file);
 
}

// Function to login as a seller
int loginPenjual(char *email_penjual, char *password_penjual)
{
    //clearNewline();
    DataPenjual user;
    FILE *file = fopen(DATABASE_FILE, "r");

    while (fscanf(file, "%s %s %c", user.email_penjual, user.password_penjual) != EOF) {
        if (strcmp(email_penjual, user.email_penjual) == 0) {
            encryptPassword(password_penjual);
            if (strcmp(password_penjual, user.password_penjual) == 0) {
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

// Function to recover password
void fogPassword()
{
    clearNewline();
    DataPenjual user;
    char email[MAX_EMAIL];
    FILE *file = fopen(DATABASE_FILE, "r");

    printf("Masukkan email Anda: ");
    scanf("%s", email);

    while (fscanf(file, "%s %s %c", user.email_penjual, user.password_penjual) != EOF) {
        if (strcmp(email, user.email_penjual) == 0) {
            printf("Password Anda: %s\n", user.password_penjual);
            fclose(file);
            return;
        }
    }

    printf("email tidak ditemukan.\n");
    fclose(file);
}
