#include <stdio.h>
#include <string.h>
#include "dataPenjual.h"
#include <stdlib.h>


struct dataPenjual
{
    char nama[100];
    char alamat[400];
    char nomor[30];
    char email[70];
    char password[48];
};

// Function to clear newline
void clearNewline()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Function to register as a seller
void daftarPenjual(struct dataPenjual *dataPenjual, int *data)
{
    clearNewline(); // Clear newline buffer

    printf("Daftar\n");

    printf("Masukan Nama Toko: ");
    fgets(dataPenjual[*data].nama, sizeof(dataPenjual[*data].nama), stdin);

    printf("Masukan No Handphone: ");
    fgets(dataPenjual[*data].nomor, sizeof(dataPenjual[*data].nomor), stdin);

    printf("Masukan Alamat: ");
    fgets(dataPenjual[*data].alamat, sizeof(dataPenjual[*data].alamat), stdin);

    printf("Masukan Email: ");
    fgets(dataPenjual[*data].email, sizeof(dataPenjual[*data].email), stdin);

    printf("Masukan Password: ");
    fgets(dataPenjual[*data].password, sizeof(dataPenjual[*data].password), stdin);

    // Open file in append mode
    FILE *file = fopen("seller_data.txt", "a");
    if (file != NULL)
    {
        // Save data to the file
        fprintf(file, "%s|%s|%s|%s|%s\n", dataPenjual[*data].nama, dataPenjual[*data].nomor, dataPenjual[*data].alamat, dataPenjual[*data].email, dataPenjual[*data].password);
        fclose(file);
    }

    (*data)++; // Increment the data index
}

// Function to login as a seller
int loginPenjual(struct dataPenjual *dataPenjual, int data)
{
    char inputEmail[70];
    char inputPassword[48];

    clearNewline();

    printf("Masukan Email: ");
    fgets(inputEmail, sizeof(inputEmail), stdin);

    for (int i = 0; i < data; i++)
    {
        if (strcmp(inputEmail, dataPenjual[i].email) == 0)
        {
            printf("Masukan Password: ");
            fgets(inputPassword, sizeof(inputPassword), stdin);

            if (strcmp(inputPassword, dataPenjual[i].password) == 0)
            {
                printf("Login berhasil!\n");
                return 1; // Login successful
            }
            else
            {
                printf("Password salah!\n");
                return 0; // Password incorrect
            }
        }
    }

    printf("Email tidak ditemukan!\n");
    return -1; // Email not found
}

// Function to recover password
void lupaPassword(struct dataPenjual *dataPenjual, int data)
{
    char inputEmail[70];

    clearNewline();

    printf("Masukan Email: ");
    fgets(inputEmail, sizeof(inputEmail), stdin);

    for (int i = 0; i < data; i++)
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

// Function to load data from file
void loadDataFromFile(struct dataPenjual *dataPenjual, int *data)
{
    FILE *file = fopen("seller_data.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", dataPenjual[*data].nama, dataPenjual[*data].nomor, dataPenjual[*data].alamat, dataPenjual[*data].email, dataPenjual[*data].password) == 5)
        {
            (*data)++;
        }
        fclose(file);
    }
}

