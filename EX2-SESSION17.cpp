#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char *str, int size) {
    printf("Nhap vao chuoi: ");
    fgets(str, size, stdin);
    // Xóa ký t? newline n?u có
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void inChuoi(char *str) {
    printf("Chuoi vua nhap la: %s\n", str);
}

void demChuCai(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            count++;
        }
    }
    printf("So luong chu cai trong chuoi la: %d\n", count);
}

void demChuSo(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    printf("So luong chu so trong chuoi la: %d\n", count);
}

void demKyTuDacBiet(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && !isspace(str[i])) {
            count++;
        }
    }
    printf("So luong ky tu dac biet trong chuoi la: %d\n", count);
}

int main() {
    char str[100];
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapChuoi(str, sizeof(str));
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                demChuCai(str);
                break;
            case 4:
                demChuSo(str);
                break;
            case 5:
                demKyTuDacBiet(str);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}

