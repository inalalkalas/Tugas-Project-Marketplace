#include <stdio.h>
#include <string.h>
#include "dataPenjual.h"
#include <stdlib.h>

DataPenjual dataPenjual [MAX_PEMBELI];

void encryptPasswordPenjual(char *password) {
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] = password[i] + 1;
    }
}

void clearBufferPJ() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// Function to register as a seller
void daftarPenjual()
{

    clearBufferPJ();
    DataPenjual dataPenjual;
    FILE *file = fopen(DATABASE_FILE, "a");   

    printf("Daftar\n");
    
    // Replace scanf for name with fgets
    printf("Masukkan Nama: ");
    fgets(dataPenjual.nama_penjual, sizeof(dataPenjual.nama_penjual), stdin);
    dataPenjual.nama_penjual[strcspn(dataPenjual.nama_penjual, "\n")] = '\0'; // Remove newline

    // Replace scanf for number with fgets
    printf("Masukkan No Handphone: ");
    fgets(dataPenjual.nomor_penjual, sizeof(dataPenjual.nomor_penjual), stdin);
    dataPenjual.nomor_penjual[strcspn(dataPenjual.nomor_penjual, "\n")] = '\0'; // Remove newline

    // Replace scanf for address with fgets
    printf("Masukkan Alamat: ");
    fgets(dataPenjual.alamat_penjual, sizeof(dataPenjual.alamat_penjual), stdin);
    dataPenjual.alamat_penjual[strcspn(dataPenjual.alamat_penjual, "\n")] = '\0'; // Remove newline

    // Replace scanf for email with fgets
    printf("Masukkan Email: ");
    fgets(dataPenjual.email_penjual, sizeof(dataPenjual.email_penjual), stdin);
    dataPenjual.email_penjual[strcspn(dataPenjual.email_penjual, "\n")] = '\0'; // Remove newline

    // Replace scanf for password with fgets
    printf("Masukkan Password: ");
    fgets(dataPenjual.password_penjual, sizeof(dataPenjual.password_penjual), stdin);
    dataPenjual.password_penjual[strcspn(dataPenjual.password_penjual, "\n")] = '\0'; // Remove newline

    encryptPasswordPenjual(dataPenjual.password_penjual);

    fprintf(file, "%s|%s|%s|%s|%s\n", dataPenjual.nama_penjual, dataPenjual.nomor_penjual, dataPenjual.alamat_penjual, dataPenjual.email_penjual, dataPenjual.password_penjual);
   

    // Increment the registration counter
    fclose(file);
 
}

// Function to login as a seller
int loginPenjual(char *email_penjual, char *password_penjual)
{
    DataPenjual user;
    FILE *file = fopen(DATABASE_FILE, "r");

    while (fscanf(file, "%s %s %c", user.email_penjual, user.password_penjual) != EOF) {
        if (strcmp(email_penjual, user.email_penjual) == 0) {
            encryptPasswordPenjual(password_penjual);
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
