/*Saya Abdurrahman Al Ghifari mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h> // mengambil/menjalankan fungsi dari library input/output
#include <string.h> // mengambil/menjalankan fungsi dari library string
#include <time.h> // mengambil/menjalankan fungsi dari library time/waktu
#pragma once

// ===================================================================
// mendeklarasikan mesin untuk menampilkan tampilan animasi delay waktu
// ===================================================================
// mendeklrasikan mesin untuk melakukan delay
void delay(int number_of_seconds);
// ===================================================================

// =======================================================================
// mendeklarasikan tiap typedef struct yang dibutuhkan untuk mengolah data
// =======================================================================

// mendeklarasikan typedef untuk tabel peralatan
typedef struct{ 
    // isi dengan atribut dari tabel
    char id_peralatan[10]; // var untuk atribut id tabel peralatan
    char nama_peralatan[50]; // var untuk atribut nama peralatan
    char merek_peralatan[50]; // var untuk atribut merek peralatan
}t_peralatan; // beri nama typedef nya

// mendeklarasikan typedef untuk tabel peminjaman
typedef struct{ 
    // isi dengan atribut dari tabel
    char id_peminjaman[10]; // var untuk atribut id tabel peminjaman
    char fk_peralatan[10]; // var untuk fk id tabel peralatan
    char nama_peminjam[50]; // var untuk atribut nama peminjam
}t_peminjaman; // beri nama typedef nya
// =======================================================================

// ====================================================
// mendeklarasikan tiap variabel global yang dibutuhkan
// ====================================================

// mendeklarasikan variabel global yang dipakai (tujuan agar mempermudah modifikasi data dalam mesin tanpa perlu return nilai)
extern int indeks; // var global untuk menyatakan indeks pada pita
extern int panjangkata; // var global untuk menampung panjang/lenght dari sebuah kata yg sedang digunakan 
extern char ckata[50]; // var untuk menampung kata yg sedang diolah pada mesin
extern int idxperalatan; // var global untuk menampung nilai banyak dari data pada tabel peralatan
extern int idxpeminjaman; // var global untuk menampung nilai banyak dari data pada tabel peminjaman
extern t_peralatan listPeralatan[50]; // var global struct untuk menampung data t_peralatan
extern t_peminjaman listPeminjaman[50]; // var global struct untuk menampung data t_peminjaman
// ====================================================

// ======================================================
// mendeklarasikan setiap tombol yang ada pada mesin kata
// ======================================================

void STARTKATA(char pita[]); // deklarasi prosedur untuk memulai mesin 

void RESETKATA(); // deklarasi prosedur untuk mereset kata yg sedang ditampung

void INCKATA(char pita[]); // deklarasi prosedur untuk lanjut ke next kata

char* GETCKATA(); // deklarasi fungsi untuk mengembalikan kata yg sedang berjalan ke main

int GETPANJANGKATA(); // deklarasi fungsi untuk mengembalikan nilai panjang dari kata yg digunakan 

int EOPKATA(char pita[]); // deklarasi fungsi untuk mengembalikan nilai batas dari pita
// ======================================================

// ===========================================================================
// mendeklarasikan setiap prosedur dari proses store data pada sequential file
// ===========================================================================

// mendeklarasikan prosedur untuk melakukan read data sesuai dengan parameter file tabel peralatan
void readFilePeralatan(t_peralatan source[], char fileName[]);

// mendeklarasikan prosedur untuk melakukan read data sesuai dengan parameter file tabel peminjaman
void readFilePeminjaman(t_peminjaman source[], char fileName[]);

// mendeklarasikan prosedur untuk melakukan write data sesuai dengan parameter file tabel peralatan
void writeToFilePeralatan(t_peralatan source[], char fileName[]);

// mendeklarasikan prosedur untuk melakukan write data sesuai dengan parameter file tabel peminjaman
void writeToFilePeminjaman(t_peminjaman source[], char fileName[]);

// mendefinisikan prosedur untuk delete data t_peralatan
void deletePeralatan(char idKeyDelete[50], t_peralatan source[]);

// mendefinisikan prosedur untuk delete data t_peminjaman
void deletePeminjaman(char idKeyDelete[50], t_peminjaman source[]);
// ===========================================================================

// ================================================
// mendeklarasikan prosedur dari proses modify data
// ================================================

// mendeklarasikan mesin untuk memodifikasi data arsip
void modify_data(char pita[501], char tempPita[6][50]);
// ================================================