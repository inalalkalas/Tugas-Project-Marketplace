#include <stdio.h>
#include <string.h>
#include "produkGudang.h"
#include <stdlib.h>

struct Product {
    char name[50];
    char restockDate[20];
    char expiryDate[20];
};

void addProduct() {
    FILE *file;
    struct Product product;

    file = fopen("products.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter restock date (dd-mm-yyyy): ");
    scanf("%s", product.restockDate);
    printf("Enter expiry date (dd-mm-yyyy): ");
    scanf("%s", product.expiryDate);

    fprintf(file, "%s %s %s\n", product.name, product.restockDate, product.expiryDate);

    fclose(file);

    printf("Product added successfully!\n");
}

void searchProduct() {
    FILE *file;
    char searchName[50];
    struct Product product;
    int found = 0;

    file = fopen("products.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter product name to search: ");
    scanf("%s", searchName);

    while (fscanf(file, "%s %s %s", product.name, product.restockDate, product.expiryDate) != EOF) {
        if (strcmp(product.name, searchName) == 0) {
            found = 1;
            printf("Product found!\n");
            printf("Name: %s\nRestock Date: %s\nExpiry Date: %s\n", product.name, product.restockDate, product.expiryDate);
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }

    fclose(file);
}

void editProduct() {
    FILE *file, *tempFile;
    char editName[50];
    struct Product product;
    int found = 0;

    file = fopen("products.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        exit(1);
    }

    printf("Enter product name to edit: ");
    scanf("%s", editName);

    while (fscanf(file, "%s %s %s", product.name, product.restockDate, product.expiryDate) != EOF) {
        if (strcmp(product.name, editName) == 0) {
            found = 1;
            printf("Enter new restock date (dd-mm-yyyy): ");
            scanf("%s", product.restockDate);
            printf("Enter new expiry date (dd-mm-yyyy): ");
            scanf("%s", product.expiryDate);
        }

        fprintf(tempFile, "%s %s %s\n", product.name, product.restockDate, product.expiryDate);
    }

    if (!found) {
        printf("Product not found!\n");
    } else {
        printf("Product edited successfully!\n");
    }

    fclose(file);
    fclose(tempFile);

    remove("products.txt");
    rename("temp.txt", "products.txt");
}

void deleteProduct() {
    FILE *file, *tempFile;
    char deleteName[50];
    struct Product product;
    int found = 0;

    file = fopen("products.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        exit(1);
    }

    printf("Enter product name to delete: ");
    scanf("%s", deleteName);

    while (fscanf(file, "%s %s %s", product.name, product.restockDate, product.expiryDate) != EOF) {
        if (strcmp(product.name, deleteName) == 0) {
            found = 1;
            printf("Product deleted successfully!\n");
            continue; // Skip writing the deleted product to the temporary file
        }

        fprintf(tempFile, "%s %s %s\n", product.name, product.restockDate, product.expiryDate);
    }

    if (!found) {
        printf("Product not found!\n");
    }

    fclose(file);
    fclose(tempFile);

    remove("products.txt");
    rename("temp.txt", "products.txt");
}

