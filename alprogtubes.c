/*
ini adalah tugasku
JUDUL : PROGRAM PEMESANAN MAKANAN

DEKLARASI :

ALGORITMA :


*/


//Kumpulan Library
#include <stdio.h>
#include <time.h>


//Prosedur
void cls() {
    system("cls");
}

void greeting() {
    printf("=================================\n");
    printf("        SELAMAT DATANG DI        \n");
    printf("      GWAENCHANA RESTAURANT      \n");
    printf("=================================\n\n");
}

void Endgreeting(){
	printf("Pesanan Anda Telah Masuk\n");
    printf("Mohon Ditunggu Sampai Nama Anda Dipanggil\n");
    printf("Terima Kasih!\n");
    printf("--------------------------------------------------\n");
}

void thanks() {
    printf("Terima kasih telah (...). Sampai jumpa!");
}


//Variabel Global
int option_P, option_M, option_MP;
int no_meja, jumlah, harga, harga_MA, harga_MI, harga_D, total, countPesanan, uang_bayar, uang_kembalian;
float ppn;
char nama[55];
char choice;

//Fungsi Hitung
int HargaMenu() {
    int harga_MA[] = {30000, 25000, 25000, 30000, 35000, 25000, 25000, 30000, 75000, 35000, 25000, 45000, 150000, 45000, 40000};
    int harga_MI[] = {75000, 65000, 22000, 20000, 18000, 29000, 250000, 25000, 20000, 10000};
    int harga_D[] = {10000, 25000, 8000, 30000, 15000};

    harga = 0;

    if (option_M >= 1 && option_M <= 15) {
        harga = harga_MA[option_M - 1];
    }
    else if (option_M >= 16 && option_M <= 25) {
        harga = harga_MI[option_M - 16];
    }
    else if (option_M >= 26 && option_M <= 30) {
        harga = harga_D[option_M - 26];
    }

    return harga;
}

void cetakStruk(int no_meja, char nama[55], int option_M, int jumlah, int harga, int total) {
    cls();
    greeting();

    printf("==============================================\n");
    printf("                  S T R U K                   \n");
    printf("==============================================\n\n");

    printf("Nomor Meja    : %d\n", no_meja);
    printf("Nama Pemesan  : %s\n", nama);

    printf("\nPesanan       : ");
    // Tampilkan nama pesanan berdasarkan opsi makanan yang dipilih
    if (option_M >= 1 && option_M <= 15) {
        printf("Makanan: ");
        const char* makanan[] = {"Kimbab", "Tteokbokki", "Ramen", "Odeng", "Bibimbap", "Jajangmyeon", "Japchae", 
                                 "Rabokki", "Bulgogi", "Korean Fried Chicken", "Spicy Cold Noodle", 
                                 "Ginseng Chicken Soup", "Samgyeopsal", "Korean Stew (Jjigae)", "Kimchi Jjigae (Stew)"};
        printf("%s", makanan[option_M - 1]);
    } else if (option_M >= 16 && option_M <= 25) {
        printf("Minuman: ");
        const char* minuman[] = {"Soju", "Makgeolgi", "Omija Tea", "Peach Tea", "Black Tea", 
                                "Strawberry Latte", "Goguma Latte", "Greentea Latte", "Americano", "Mineral water"};
        printf("%s", minuman[option_M - 16]);
    } else if (option_M >= 26 && option_M <= 30) {
        printf("Dessert: ");
        const char* dessert[] = {"Bungeoppang", "Patbingsoo", "Hottteok", "Hwachae", "Jeonggwa"};
        printf("%s", dessert[option_M - 26]);
    }

    printf("\nJumlah        : %d\n", jumlah);
    printf("Harga Satuan : Rp%d\n", harga);
    printf("Total Harga   : Rp%d\n", total);

    Endgreeting();
}


int HitungPembayaran(int jumlah, int HargaMenu) {
    int total = 0;
    total += HargaMenu * jumlah;
    return total;
}

/*int HitungPembayaran(int *harga, int *jumlah, int countPesanan) {
    int total = 0;

    harga = HargaMenu();

    for (int i = 0; i < countPesanan; i++) {
        total += harga[i] * jumlah[i];
    }

    return total;
}*/


//Fungsi Main
int main() {

    do {
        cls();

    greeting();

    printf("+======================+\n");
    printf("|   METODE PEMESANAN   |\n");
    printf("+----------------------+\n");
    printf("| 1 | Dine In          |\n");
    printf("| 2 | Take Away        |\n");
    printf("+======================+\n");
    printf("Masukkan metode pemesanan : ");
    scanf("%d", &option_P);
    printf("\n");

    printf("Silahkan masukkan nama pemesan : ");
    scanf("%s", &nama);

        if (option_P == 1) {
            printf("Masukkan nomor meja : ");
            scanf("%d", &no_meja);
            printf("\n");
        }
        else if (option_P == 2) {
            //Nanti di sini printf nomor antrian otomatis, setiap harinya akan keriset jd no 1 lagi
        }
        else {
            printf("Mohon maaf, input yang Anda masukkan tidak valid.\n");
        }

    printf("+=======================================================================================================================================+\n");
    printf("|                                                              M   E   N   U                                                            |\n");
    printf("+=======================================================================================================================================+\n");
    printf("| NO |        MAKANAN         |      HARGA      | | NO |      MINUMAN      |      HARGA      | | NO |     DESSERT     |      HARGA      |\n");
    printf("+----+------------------------+-----------------+ +----+-------------------+-----------------+ +----+-----------------+-----------------+\n");
    printf("| 1  | Kimbab                 | Rp        30.000| | 16 | Soju              | Rp        75.000| | 26 | Bungeoppang     | Rp        10.000|\n");
    printf("| 2  | Tteokbokki             | Rp        25.000| | 17 | Makgeolgi         | Rp        65.000| | 27 | Patbingsoo      | Rp        25.000|\n");
    printf("| 3  | Ramen                  | Rp        25.000| | 18 | Omija Tea         | Rp        22.000| | 28 | Hotteok         | Rp         8.000|\n");
    printf("| 4  | Odeng                  | Rp        30.000| | 19 | Peach Tea         | Rp        20.000| | 29 | Hwachae         | Rp        30.000|\n");
    printf("| 5  | Bibimbap               | Rp        35.000| | 20 | Black Tea         | Rp        18.000| | 30 | Jeonggwa        | Rp        15.000|\n");
    printf("| 6  | Jajangmyeon            | Rp        25.000| | 21 | Strawberry Latte  | Rp        29.000| |    |                 |                 |\n");
    printf("| 7  | Japchae                | Rp        25.000| | 22 | Goguma Latte      | Rp        25.000| |    |                 |                 |\n");
    printf("| 8  | Rabokki                | Rp        30.000| | 23 | Green Tea Latte   | Rp        25.000| |    |                 |                 |\n");
    printf("| 9  | Bulgogi                | Rp        75.000| | 24 | Americano         | Rp        20.000| |    |                 |                 |\n");
    printf("| 10 | Korean Fried Chicken   | Rp        35.000| | 25 | Mineral Watter    | Rp        10.000| |    |                 |                 |\n");
    printf("| 11 | Spicy Cold Noodle      | Rp        25.000| |    |                   |                 | |    |                 |                 |\n");
    printf("| 12 | Ginseng Chicken Soup   | Rp        45.000| |    |                   |                 | |    |                 |                 |\n");
    printf("| 13 | Samgyeopsal            | Rp       150.000| |    |                   |                 | |    |                 |                 |\n");
    printf("| 14 | Korean Stew (Jjigae)   | Rp        45.000| |    |                   |                 | |    |                 |                 |\n");
    printf("| 15 | Kimchi Jjigae (stew)   | Rp        40.000| |    |                   |                 | |    |                 |                 |\n");
    printf("+---------------------------------------------------------------------------------------------------------------------------------------+\n");
    printf("| 0  | Selesai                                                                                                                          |\n");
    printf("+=======================================================================================================================================+\n");
    
       do {
            printf("Silahkan masukkan pilihan Anda : ");
            scanf("%d", &option_M);

            if (option_M >= 1 && option_M <= 30) {
                printf("Masukkan jumlah : ");
                scanf("%d", &jumlah);
                printf("\n");
                // Perbaiki pemanggilan fungsi HitungPembayaran
                total += HitungPembayaran(jumlah, HargaMenu());
            } else if (option_M == 0) {
                printf("--------------------------------------------------\n");
                printf("Total Pesanan Anda : Rp.%d\n", total);
                printf("--------------------------------------------------\n");
                break;
            } else {
                printf("Mohon maaf, input yang Anda masukkan tidak valid.\n");
            }
        } while (1);

    cetakStruk(no_meja, nama[55], option_M, jumlah, harga, total);

    printf("+=======================+\n");
    printf("|   METODE PEMBAYARAN   |\n");
    printf("+-----------------------+\n");
    printf("| 1. Cash               |\n");
    printf("| 2. Debit              |\n");
    printf("| 3. QRIS               |\n");
    printf("+=======================+\n");
    printf("Masukkan metode pembayaran : ");
    scanf("%d", &option_MP);
    printf("\n");
    
        if (option_MP == 1) {
            printf("Masukkan uang tunai yang dibayarkan : ");
            scanf("%d", &uang_bayar);
            uang_kembalian = uang_bayar - total;
            printf("Uang kembalian : Rp%d\n", uang_kembalian);
        }
        else if (option_MP == 2 || option_MP == 3) {
            break;
        }
        else {
            printf("Mohon maaf, input yang Anda masukkan tidak valid.\n");
        }

    printf("Apakah ada pesanan lain? (Y/N): "); 
    scanf(" %c", &choice);

    } while (choice == 'y' || choice =='Y');

    cls();
    printf("Pesanan Atas Nama: %s\n", nama);
	Endgreeting();

    return 0;
}


//Billing to txt
ini adalah tugas tool yang diberikan
