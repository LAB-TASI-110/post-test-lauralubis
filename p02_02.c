#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan data per barang
typedef struct {
    char nama[30];
    char kategori[20];
    int stok;
} Barang;

int main() {
    int N;
    int kodeKategori;
    int totalStok = 0;

    printf("=== Program Inventaris Gudang ===\n");

    // 1. Input Jumlah Total Data (N)
    printf("Masukkan jumlah total data (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Error: N harus berupa angka positif.\n");
        return 1;
    }

    Barang gudang[N]; // Array dinamis berdasarkan input N

    // 2. Input Deret Stok (s1, s2, ..., sN)
    printf("Masukkan deret stok sebanyak %d data:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Stok s%d: ", i + 1);
        scanf("%d", &gudang[i].stok);

        // Logika penentuan nama dan kategori berdasarkan pola gambar
        // s1=Minyak, s2=Rok, s3=Gula, s4=Dasi
        if (i == 0) {
            strcpy(gudang[i].nama, "Minyak");
            strcpy(gudang[i].kategori, "Bahan Dapur");
        } else if (i == 1) {
            strcpy(gudang[i].nama, "Rok Pramuka");
            strcpy(gudang[i].kategori, "Pakaian");
        } else if (i == 2) {
            strcpy(gudang[i].nama, "Gula");
            strcpy(gudang[i].kategori, "Bahan Dapur");
        } else if (i == 3) {
            strcpy(gudang[i].nama, "Dasi SD");
            strcpy(gudang[i].kategori, "Pakaian");
        } else {
            strcpy(gudang[i].nama, "Barang Lain");
            strcpy(gudang[i].kategori, "Umum");
        }
    }

    // 3. Input Kode Kategori Barang
    printf("\nPilih kategori yang ingin dihitung:\n");
    printf("1. Pakaian\n2. Bahan Dapur\n");
    printf("Masukkan Kode Kategori (1/2): ");
    scanf("%d", &kodeKategori);

    char target[20];
    if (kodeKategori == 1) strcpy(target, "Pakaian");
    else if (kodeKategori == 2) strcpy(target, "Bahan Dapur");
    else {
        printf("Error: Kode kategori tidak tersedia.\n");
        return 1;
    }

    // Menampilkan hasil dan menghitung total
    printf("\n--- Hasil Filter: %s ---\n", target);
    for (int i = 0; i < N; i++) {
        if (strcmp(gudang[i].kategori, target) == 0) {
            printf("- %s: %d pcs\n", gudang[i].nama, gudang[i].stok);
            totalStok += gudang[i].stok;
        }
    }

    printf("-------------------------------\n");
    printf("TOTAL STOK AKHIR: %d pcs\n", totalStok);

    return 0;
}