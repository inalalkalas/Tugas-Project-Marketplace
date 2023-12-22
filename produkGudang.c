#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "produkGudang.h"

// Struktur untuk menyimpan informasi produk

// Fungsi untuk menukar dua elemen
void swap(PROduct *a, PROduct *b) {
    PROduct temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk membagi array dan mengembalikan indeks pivot
int partition(PROduct arr[], int low, int high, int (*compare)(float, float)) {
    float pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compare(arr[j].price, pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Fungsi untuk melakukan quicksort pada array
void quickSort(PROduct arr[], int low, int high, int (*compare)(float, float)) {
    if (low < high) {
        int pi = partition(arr, low, high, compare);
        quickSort(arr, low, pi - 1, compare);
        quickSort(arr, pi + 1, high, compare);
    }
}

// Fungsi untuk membandingkan dua harga (untuk ascending dan descending)
int compareAscending(float a, float b) {
    return a < b;
}

int compareDescending(float a, float b) {
    return a > b;
}

void getCurrentDate(char *date) {
    time_t t;
    struct tm *current_time;

    // Mendapatkan waktu saat ini
    time(&t);
    current_time = localtime(&t);

    // Format tanggal sebagai DD-MM-YYYY
    strftime(date, 15, "%d-%m-%Y", current_time);
}

void addProduct(FILE *file) {
    PROduct product;

    printf("Masukkan nama produk: ");
    scanf("%s", product.name);
    printf("Masukkan harga produk: ");
    scanf("%lf", &product.price);

    // Mendapatkan tanggal saat ini
    getCurrentDate(product.restock_date);

    // Menetapkan tanggal kedaluwarsa misalnya 30 hari dari tanggal restock
    time_t t = time(NULL);
    struct tm *expiry_time = localtime(&t);
    expiry_time->tm_mday += 250; // Tambah 30 hari
    mktime(expiry_time);

    // Format tanggal kedaluwarsa sebagai DD-MM-YYYY
    strftime(product.expiry_date, 15, "%d-%m-%Y", expiry_time);

    // Menulis data produk ke dalam file
    fprintf(file, "%s %.2f %s %s\n", product.name, product.price, product.restock_date, product.expiry_date);
    printf("Produk berhasil ditambahkan.\n");
}

void editProduct(FILE *file, const char *productName) {
    PROduct product, temp;
    int found = 0;

    // Membaca data produk dari file
    rewind(file);
    while (fscanf(file, "%s %f %s %s", product.name, &product.price, product.restock_date, product.expiry_date) != EOF) {
        if (strcmp(product.name, productName) == 0) {
            printf("Masukkan informasi produk yang baru:\n");
            printf("Harga baru: ");
            scanf("%f", &temp.price);

            // Mendapatkan tanggal restock saat ini
            getCurrentDate(temp.restock_date);

            // Menetapkan tanggal kedaluwarsa misalnya 30 hari dari tanggal restock
            time_t t = time(NULL);
            struct tm *expiry_time = localtime(&t);
            expiry_time->tm_mday += 30; // Tambah 30 hari
            mktime(expiry_time);

            // Format tanggal kedaluwarsa sebagai DD-MM-YYYY
            strftime(temp.expiry_date, 15, "%d-%m-%Y", expiry_time);

            // Menulis data produk yang telah diubah ke dalam file
            fprintf(file, "%s %.2f %s %s\n", product.name, temp.price, temp.restock_date, temp.expiry_date);
            printf("Informasi produk berhasil diubah.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Produk tidak ditemukan.\n");
    }
}

// Fungsi untuk mencari produk berdasarkan nama
void searchProduct(FILE *file, const char *productName) {
    PROduct product;
    int found = 0;

    // Membaca data produk dari file
    rewind(file);
    while (fscanf(file, "%s %f %s %s", product.name, &product.price, product.restock_date, product.expiry_date) != EOF) {
        if (strcmp(product.name, productName) == 0) {
            printf("Produk ditemukan:\n");
            printf("Nama: %s\n", product.name);
            printf("Harga: %.2f\n", product.price);
            printf("Tanggal Restock: %s\n", product.restock_date);
            printf("Tanggal Expired: %s\n", product.expiry_date);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Produk tidak ditemukan.\n");
    }
}

// Fungsi untuk menghapus produk berdasarkan nama
void deleteProduct(FILE *file, const char *productName) {
    PROduct product;
    FILE *tempFile;

    // Membuka file temporary untuk menulis sementara
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        return;
    }

    int found = 0;

    // Membaca data produk dari file
    rewind(file);
    while (fscanf(file, "%s %f %s %s", product.name, &product.price, product.restock_date, product.expiry_date) != EOF) {
        // Jika produk ditemukan, skip penulisan ke temporary file (menghapus produk)
        if (strcmp(product.name, productName) == 0) {
            found = 1;
            continue;
        }

        // Menulis data produk yang tidak dihapus ke dalam temporary file
        fprintf(tempFile, "%s %.2f %s %s\n", product.name, product.price, product.restock_date, product.expiry_date);
    }

    // Menutup file temporary
    fclose(tempFile);

    // Menghapus file awal
    remove("products.txt");

    // Mengganti nama temporary file menjadi nama file asli
    if (rename("temp.txt", "products.txt") != 0) {
        printf("Error renaming temporary file.\n");
        return;
    }

    if (found) {
        printf("Produk berhasil dihapus.\n");
    } else {
        printf("Produk tidak ditemukan.\n");
    }
}




