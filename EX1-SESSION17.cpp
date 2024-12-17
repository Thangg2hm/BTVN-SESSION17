#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void hienThiMang(int *arr, int size) {
    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int tinhTong(int *arr, int size) {
    int tong = 0;
    for (int i = 0; i < size; i++) {
        tong += arr[i];
    }
    return tong;
}

int phanTuLonNhat(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int choice;
    int *arr = NULL;
    int size = 0;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &size);
                arr = (int*)malloc(size * sizeof(int));
                if (arr == NULL) {
                    printf("Khong du bo nho de cap phat\n");
                    return 1;
                }
                nhapMang(arr, size);
                break;
            case 2:
                hienThiMang(arr, size);
                break;
            case 3:
                printf("Do dai cua mang la: %d\n", size);
                break;
            case 4:
                printf("Tong cac phan tu trong mang la: %d\n", tinhTong(arr, size));
                break;
            case 5:
                printf("Phan tu lon nhat trong mang la: %d\n", phanTuLonNhat(arr, size));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    if (arr != NULL) {
        free(arr);
    }

    return 0;
}

