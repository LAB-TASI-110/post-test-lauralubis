#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data produk
typedef struct {
    int id;
    char nama[50];
    double harga;
} Menu;

int main() {
    // Menambahkan menu baru sesuai permintaan
    // Total sekarang ada 8 menu
    Menu daftarMenu[] = {
        {1, "Nasi Goreng Spesial Del", 15000.0},
        {2, "Ayam Penyet Kantin", 10000.0},
        {3, "Teh Manis Dingin", 5000.0},
        {4, "Bakwan", 10000.0},
        {5, "Pisang Coklat", 10000.0},
        {6, "Nugget", 15000.0},
        {7, "Kopi", 7000.0},
        {8, "Roti Isi Ayam", 15000.0}
    };

    // Menghitung jumlah elemen dalam array secara otomatis
    int jumlahMenu = sizeof(daftarMenu) / sizeof(daftarMenu[0]);
    
    int pilihan, jumlah;
    char buffer[100];
    double totalBelanja = 0;

    printf("==========================================\n");
    printf("   SISTEM KASIR KAFETARIA IT DEL v2.0    \n");
    printf("==========================================\n");

    while (1) {
        printf("\nMENU TERSEDIA:\n");
        for (int i = 0; i < jumlahMenu; i++) {
            printf("%d. %-20s | Rp%8.2f\n", daftarMenu[i].id, daftarMenu[i].nama, daftarMenu[i].harga);
        }
        printf("0. Selesai & Bayar\n");
        printf("------------------------------------------\n");

        printf("Input ID Menu: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Validasi: Pastikan input adalah angka
            if (sscanf(buffer, "%d", &pilihan) != 1) {
                printf(">> [Sistem] Error: Masukkan angka ID yang tertera!\n");
                continue;
            }
        }

        if (pilihan == 0) break;

        // Validasi ID Menu
        if (pilihan < 1 || pilihan > jumlahMenu) {
            printf(">> [Sistem] Error: Menu ID %d tidak ditemukan.\n", pilihan);
            continue;
        }

        printf("Jumlah Unit [%s]: ", daftarMenu[pilihan - 1].nama);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &jumlah) != 1 || jumlah <= 0) {
                printf(">> [Sistem] Error: Jumlah minimal pesanan adalah 1.\n");
                continue;
            }
        }

        // Kalkulasi Backend
        double subtotal = daftarMenu[pilihan - 1].harga * jumlah;
        totalBelanja += subtotal;

        printf(">> [Sistem] Ditambahkan: %d x %s = Rp%.2f\n", 
                jumlah, daftarMenu[pilihan - 1].nama, subtotal);
        printf("------------------------------------------\n");
    }

    // Ringkasan Akhir
    printf("\n\n==========================================");
    printf("\n          STRUK PEMBAYARAN KAFETARIA      ");
    printf("\n==========================================");
    printf("\nTOTAL AKHIR : Rp%.2f", totalBelanja);
    printf("\nStatus      : LUNAS");
    printf("\n==========================================");
    printf("\nSemangat belajarnya, mahasiswa Del!\n\n");

    return 0;
}