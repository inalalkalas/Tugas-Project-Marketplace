#include <stdio.h>
#include <string.h>
#include "dataPenjual.h"
#include <stdlib.h>

DataPenjual dataPenjual [MAX_PEMBELI];
int data_LogPJ[MAX_PEMBELI];
int data_LogPJ[MAX_PEMBELI];
int data_FogPJ[MAX_PEMBELI];


// Function to clear newline
void clearNewline(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Function to register as a seller
void daftarPenjual(DataPenjual *dataPenjual, int *data_DafPJ, int *numRegistrations)
{

    clearNewline();

    printf("Daftar\n");

    printf("Masukan Nama Toko: ");
    fgets(dataPenjual[*data_DafPJ].nama, sizeof(dataPenjual[*data_DafPJ].nama), stdin);

    printf("Masukan No Handphone: ");
    fgets(dataPenjual[*data_DafPJ].nomor, sizeof(dataPenjual[*data_DafPJ].nomor), stdin);

    printf("Masukan Alamat: ");
    fgets(dataPenjual[*data_DafPJ].alamat, sizeof(dataPenjual[*data_DafPJ].alamat), stdin);

    printf("Masukan Email: ");
    fgets(dataPenjual[*data_DafPJ].email, sizeof(dataPenjual[*data_DafPJ].email), stdin);

    printf("Masukan Password: ");
    fgets(dataPenjual[*data_DafPJ].password, sizeof(dataPenjual[*data_DafPJ].password), stdin);

    // Open file in append mode
    FILE *file = fopen("seller_data.txt", "a");
    if (file != NULL)
    {
        // Save data to the file
        fprintf(file, "%s|%s|%s|%s|%s\n", dataPenjual[*data_DafPJ].nama, dataPenjual[*data_DafPJ].nomor, dataPenjual[*data_DafPJ].alamat, dataPenjual[*data_DafPJ].email, dataPenjual[*data_DafPJ].password);
        fclose(file);
    }

    (*data_DafPJ)++; // Increment the data index
}

// Function to login as a seller
int loginPenjual(DataPenjual *dataPenjual, int data_LogPJ, int numRegistrations)
{
    char inputEmail[70];
    char inputPassword[48];

    clearNewline();

    printf("Masukkan Email: ");
    fgets(inputEmail, sizeof(inputEmail), stdin);

    for (int i = 0; i < numRegistrations; i++) {
        if (strcmp(inputEmail, dataPenjual[i].email) == 0) {
            printf("Masukkan Password: ");
            fgets(inputPassword, sizeof(inputPassword), stdin);

            if (strcmp(inputPassword, dataPenjual[i].password) == 0) {
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

// Function to recover password
void fogPassword(DataPenjual *dataPenjual, int data_FogPJ, int numRegistrations)
{
    char inputEmail[70];

    printf("Masukan Email: ");
    fgets(inputEmail, sizeof(inputEmail), stdin);

    for (int i = 0; i < data_FogPJ; i++)
    {
        if (strcmp(inputEmail, dataPenjual[i].email) == 0)
        {
            // Simulate sending a recovery email
            printf("Email pemulihan password telah dikirim ke %s\n", inputEmail);
            return;
        }
    }

    printf("Email tidak ditemukan!\n");
}
