/*Saya Abdurrahman Al Ghifari mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h" // mengambil/menjalankan deklarasi yang ada pada file header

int main() { // deklarasi fungsi utama(main) program
    char pita[501]; // string untuk menampung inputan user
    char tempPita[6][50]; // string temporary atau wadah sementara dalam memecah querry

    idxperalatan = 0; // inisialisasi index banyak data peralatan
    idxpeminjaman = 0; // inisialisasi index banyak data peminjaman
    readFilePeralatan(listPeralatan, "t_peralatan.txt"); // membaca file t_peralatan
    readFilePeminjaman(listPeminjaman, "t_peminjaman.txt"); // membaca file t_peminjaman

    // ini program untuk menampilkan animasi sederhana
    // Array dari string yang akan ditampilkan
    const char *lines[] = {
        "  ____  _           __  __      ",
        " / ___|(_)_ __ __ _/ _|/ _| ___ ",
        "| |  _ | | '__/ _` | |_| |_ / _ ",
        "| |_| || | | | (_| |  _|  _|  __/",
        " \\____|_|_|  \\__,_|_| |_|  \\___|",
        "    /\\___/\\   /\\___/\\           ",
        "   (  o o  ) (  o o  )          ",
        "    \\  >  /   \\  >  /           ",
        "<==================================>",
        "<===== GIRAFFE DBMS vers. 1.0 =====>"
    };

    // Menghitung jumlah baris
    int num_lines = sizeof(lines) / sizeof(lines[0]);

    // Menampilkan setiap baris dengan jeda satu detik
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
        delay(1);  // Menunggu selama satu detik
    }

    printf("\n"); // spasi sebelum insert query dbms

    // melakukan perulangan do while sampai input berupa kata EXIT/Exit/exit
    do{
        printf("Giraffe's dbms>"); // cetak ini sebagai penghias
        scanf(" %500[^\n]s", &pita); // minta masukan user untuk mengisi pita

        // memanggil fungsi untuk melakukan modify data pada arsip 
        modify_data(pita, tempPita); 

    } while (strcmp(tempPita[0], "EXIT") != 0); // keluar perulangan ketika input kata EXIT
    
    return 0;
}