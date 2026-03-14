#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definisi Struktur untuk data kota
typedef struct {
    char kode[4];
    char nama[20];
    int ongkos_per_kg;
    int is_luar_pulau; // 0: Dalam, 1: Luar
} Kota;

int main() {
    // Inisialisasi Data Master Kota sesuai tabel
    Kota daftar_kota[] = {
        {"MDN", "Medan", 8000, 0},
        {"BLG", "Balige", 5000, 0},
        {"JKT", "Jakarta", 12000, 1},
        {"SBY", "Surabaya", 13000, 1}
    };
    int jumlah_kota = sizeof(daftar_kota) / sizeof(daftar_kota[0]);

    char input_kode[10];
    float berat_a;

    printf("=== SYSTEM LAYANAN DEL-EXPRESS ===\n");
    printf("Ketik 'END' pada kode kota untuk keluar\n\n");

    while (1) {
        printf("Masukkan Kode Kota: ");
        if (scanf("%s", input_kode) == 0) break;

        // Cek apakah user ingin mengakhiri program
        if (strcmp(input_kode, "END") == 0) {
            printf("Program Selesai. Terima kasih!\n");
            break;
        }

        printf("Masukkan Berat Paket A (kg): ");
        if (scanf("%f", &berat_a) == 0) break;

        // Cari data kota berdasarkan kode
        int ditemukan = -1;
        for (int i = 0; i < jumlah_kota; i++) {
            if (strcmp(input_kode, daftar_kota[i].kode) == 0) {
                ditemukan = i;
                break;
            }
        }

        if (ditemukan != -1) {
            // Logika Perhitungan Berat
            float berat_b = 1.5f * berat_a; // Paket B adalah 3/2 dari Paket A
            float total_berat = berat_a + berat_b;
            
            // Hitung Biaya Awal
            float total_ongkos = total_berat * daftar_kota[ditemukan].ongkos_per_kg;
            float diskon = 0;
            char info_promo[100] = "Tidak ada promo";

            // Logika Promo
            if (total_berat > 10) {
                diskon = 0.10f * total_ongkos;
                total_ongkos -= diskon;
                strcpy(info_promo, "Diskon 10% (Berat > 10kg)");
            }

            if (daftar_kota[ditemukan].is_luar_pulau == 1) {
                if (total_berat > 10) 
                    strcat(info_promo, " & Gratis Asuransi");
                else 
                    strcpy(info_promo, "Gratis Asuransi (Luar Pulau)");
            }

            // Output Struk Pembayaran
            printf("\n==================================\n");
            printf("        STRUK PEMBAYARAN          \n");
            printf("==================================\n");
            printf("Kota Tujuan         : %s\n", daftar_kota[ditemukan].nama);
            printf("Berat Paket Butet   : %.2f kg\n", berat_a);
            printf("Berat Paket Ucok    : %.2f kg\n", berat_b);
            printf("Total Berat         : %.2f kg\n", total_berat);
            printf("----------------------------------\n");
            printf("Promo yang Didapat  : %s\n", info_promo);
            printf("Total Ongkos Kirim  : Rp %.0f\n", total_ongkos);
            printf("==================================\n\n");

        } else {
            printf("Error: Kode kota '%s' tidak ditemukan dalam sistem.\n\n", input_kode);
        }
    }

    return 0;
}