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

void inChuoiDaoNguoc(char *str) {
    int len = strlen(str);
    printf("Chuoi dao nguoc la: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

void demSoTu(char *str) {
    int count = 0;
    int inWord = 0;
    while (*str) {
        if (isspace(*str)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
        str++;
    }
    printf("So luong tu trong chuoi la: %d\n", count);
}

void soSanhChuoi(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 > len2) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void inHoaChuCai(char *str) {
    while (*str) {
        putchar(toupper(*str));
        str++;
    }
    printf("\n");
}

void themChuoi(char *str1, char *str2, int size) {
    if (strlen(str1) + strlen(str2) < size) {
        strcat(str1, str2);
    } else {
        printf("Khong the them chuoi vi vuot qua kich thuoc cho phep.\n");
    }
}

int main() {
    char str[100] = "";
    char str2[100] = "";
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                nhapChuoi(str, sizeof(str));
                break;
            case 2:
                inChuoiDaoNguoc(str);
                break;
            case 3:
                demSoTu(str);
                break;
            case 4:
                nhapChuoi(str2, sizeof(str2));
                soSanhChuoi(str, str2);
                break;
            case 5:
                inHoaChuCai(str);
                break;
            case 6:
                nhapChuoi(str2, sizeof(str2));
                themChuoi(str, str2, sizeof(str));
                printf("Chuoi sau khi them: %s\n", str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

