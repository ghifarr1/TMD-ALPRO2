/*Saya Abdurrahman Al Ghifari mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h" // mengambil/menjalankan deklarasi yang ada pada file header

// ===================================================================
// mendefinisikan mesin untuk menampilkan tampilan animasi delay waktu
// ===================================================================

int indeks; // var global untuk menyatakan indeks pada pita
int panjangkata; // var global untuk menampung panjang/lenght dari sebuah kata yg sedang digunakan 
char ckata[50]; // var untuk menampung kata yg sedang diolah pada mesin
int idxperalatan; // var global untuk menampung nilai banyak dari data pada tabel peralatan
int idxpeminjaman; // var global untuk menampung nilai banyak dari data pada tabel peminjaman
t_peralatan listPeralatan[50]; // var global struct untuk menampung data t_peralatan
t_peminjaman listPeminjaman[50]; // var global struct untuk menampung data t_peminjaman


// mendefinisikan mesin untuk melakukan delay
void delay(int number_of_seconds){
    // Mengonversi waktu ke milidetik
    int milli_seconds = 1000 * number_of_seconds;

    // Menyimpan waktu mulai
    clock_t start_time = clock();

    // Menunggu sampai waktu berlalu
    while (clock() < start_time + milli_seconds);
}
// ===================================================================

// ======================================================
// mendefinisikan setiap tombol yang ada pada mesin kata
// ======================================================

// mendefinisikan prosedur untuk memulai mesin
void STARTKATA(char pita[]){
    indeks = 0; // inisialisasi indeks
    panjangkata = 0; // inisialisasi panjang kata
    while (pita[indeks] == ' '){ // cek jika spasi
        indeks++; // skip terus indeksnya
    }
    
    while ((pita[indeks] != ' ') && (pita[indeks] != ';')){ // cek kalo udh sampe batas akhir
        ckata[panjangkata] = pita[indeks]; // pindahin katanya
        indeks++; // tambah indeks
        panjangkata++; // tambah pj kata
    }
    ckata[panjangkata] = '\0'; // kasih nul termi diakhir
}

// mendefinisikan prosedur untuk mereset kata yg sedang ditampung
void RESETKATA(){
    panjangkata = 0; // reset panjangnya
    ckata[panjangkata] = '\0'; // cut langsung dengan nul termi
}

// mendefinisikan prosedur untuk lanjut ke next kata
void INCKATA(char pita[]){
    panjangkata = 0; // reset panjangnya
    while (pita[indeks] == ' '){ // cek jika spasi
        indeks++; // skip terus indeksnya
    }
    while ((pita[indeks] != ' ') && (pita[indeks] != ';')){ // cek kalo udh sampe batas akhir
        ckata[panjangkata] = pita[indeks]; // pindahin katanya
        indeks++; // tambah indeks
        panjangkata++; // tambah pj kata
    }
    ckata[panjangkata] = '\0'; // kasih nul termi diakhir
}

// mendefinisikan fungsi untuk mengembalikan kata yg sedang berjalan ke main
char* GETCKATA(){
    return ckata; // mengembalikan kata
}

// mendefinisikan fungsi untuk mengembalikan nilai panjang dari kata yg digunakan 
int GETPANJANGKATA(){
    return panjangkata; // mengembalikan nilai
}

// mendefinisikan fungsi untuk mengembalikan nilai batas dari pita
int EOPKATA(char pita[]){
    if (pita[indeks] == ';'){ // cek jika akhir dari pita
        return 1; // mengembalikan nilai
    }else{ // jika bukan
        return 0; // mengembalikan nilai
    }
}
// ======================================================

// ==========================================================================
// mendefinisikan setiap prosedur dari proses store data pada sequential file
// ==========================================================================

// mendefinisikan prosedur untuk melakukan read data sesuai dengan parameter file tabel peralatan
void readFilePeralatan(t_peralatan source[], char fileName[]){
    FILE *fTemp; // deklarasi pointer alokasi data sementara
    fTemp = fopen(fileName, "r"); //  membuka jalinan file r untuk operator read file
   
   // ini untuk membaca end of file dan melakukan scanning di awal
    int returnVal = fscanf(fTemp, "%s %s %s", source[idxperalatan].id_peralatan, source[idxperalatan].nama_peralatan, source[idxperalatan].merek_peralatan); // untuk scan 3 data pada baris pertama dari isi file

    // cek apakah data yang discan di atas dummy atau tidak              
    if (strcmp(source[idxperalatan].id_peralatan, "####") == 0 || returnVal == EOF) printf("Empty set of file\n");
    else { // jika buka dummy/eof
        while (strcmp(source[idxperalatan].id_peralatan, "####") != 0) { // selama bukan data dummy/eof
            idxperalatan = idxperalatan + 1; // maju ke indeks penampung berikutnya
            // untuk scan 6 data pada baris berikutnya dari isi file
            fscanf(fTemp, "%s %s %s", source[idxperalatan].id_peralatan, source[idxperalatan].nama_peralatan, source[idxperalatan].merek_peralatan); 
        }
    }
    fclose(fTemp); // tutup file
}

// mendefinisikan prosedur untuk melakukan read data sesuai dengan parameter file tabel peminjaman
void readFilePeminjaman(t_peminjaman source[], char fileName[]){
    FILE *fTemp; // deklarasi pointer alokasi data sementara
    fTemp = fopen(fileName, "r"); //  membuka jalinan file r untuk operator read file
   
   // ini untuk membaca end of file dan melakukan scanning di awal
    int returnVal = fscanf(fTemp, "%s %s %s", source[idxpeminjaman].id_peminjaman, source[idxpeminjaman].fk_peralatan, source[idxpeminjaman].nama_peminjam); // untuk scan 3 data pada baris pertama dari isi file

    // cek apakah data yang discan di atas dummy atau tidak              
    if (strcmp(source[idxpeminjaman].id_peminjaman, "####") == 0 || returnVal == EOF) printf("Empty set of file\n");
    else { // jika buka dummy/eof
        while (strcmp(source[idxpeminjaman].id_peminjaman, "####") != 0) { // selama bukan data dummy/eof
            idxpeminjaman = idxpeminjaman + 1; // maju ke indeks penampung berikutnya
            // untuk scan 6 data pada baris berikutnya dari isi file
            fscanf(fTemp, "%s %s %s", source[idxpeminjaman].id_peminjaman, source[idxpeminjaman].fk_peralatan, source[idxpeminjaman].nama_peminjam); 
        }
    }
    fclose(fTemp); // tutup file
}

// mendefinisikan prosedur untuk melakukan write data sesuai dengan parameter file tabel peralatan
void writeToFilePeralatan(t_peralatan source[], char fileName[]){
    FILE *fTemp; // deklarasi pointer alokasi data sementara
    fTemp = fopen(fileName, "w"); // buka file dengan operator write to file

    // melakukan perulangan untuk menuliskan data di file 
    for (int i = 0; i < idxperalatan; i++){
        // write data data ke dalam file
        fprintf(fTemp, "%s %s %s\n", source[i].id_peralatan, source[i].nama_peralatan, source[i].merek_peralatan);
    }
    // write data dummy setelah bikin data data dalam file
    fprintf(fTemp, "%s %s %s\n", "####", "####", "####");

    fclose(fTemp); // tutup file
}

// mendefinisikan prosedur untuk melakukan write data sesuai dengan parameter file tabel peminjaman
void writeToFilePeminjaman(t_peminjaman source[], char fileName[]){
    FILE *fTemp; // deklarasi pointer alokasi data sementara
    fTemp = fopen(fileName, "w"); // buka file dengan operator write to file

    // melakukan perulangan untuk menuliskan data di file 
    for (int i = 0; i < idxpeminjaman; i++){
        // write data data ke dalam file
        fprintf(fTemp, "%s %s %s\n", source[i].id_peminjaman, source[i].fk_peralatan, source[i].nama_peminjam);
    }
    // write data dummy setelah bikin data data dalam file
    fprintf(fTemp, "%s %s %s\n", "####", "####", "####");

    fclose(fTemp); // tutup file
}

// mendefinisikan prosedur untuk delete data t_peralatan
void deletePeralatan(char idKeyDelete[50], t_peralatan source[]){
    int status = 0; // status sebagai penanda
    if (strcmp(idKeyDelete, source[0].id_peralatan) == 0){
        // rekaman baru di paling depan
        // geser semua isi array belakang
        int i;
        for (i = 0; i < idxperalatan; i++){
            source[i] = source[i + 1];
        }
        status = 1;
        idxperalatan--;
    }else if (strcmp(idKeyDelete, source[idxperalatan - 1].id_peralatan) == 0){
        // rekaman baru di belakang
        status = 1;
        idxperalatan--;
    }else{
        // rekaman baru memiliki posisi di tengah
        int i = 0;
        int stop = 0;
        // cari posisi
        while ((i < idxperalatan) && (stop == 0)){
            if (strcmp(source[i].id_peralatan, idKeyDelete) == 0){
                stop = 1;
            }else{
                i++;
            }
        }

        if (stop == 1){
            int j;
            for (j = i; j < idxperalatan; j++){
                source[j] = source[j + 1];
            }
            status = 1;
            idxperalatan--;
        }
    }

    // flush data
    writeToFilePeralatan(source, "t_peralatan.txt"); // tulis ke file data yg dimodifikasi
}

// mendefinisikan prosedur untuk delete data t_peminjaman
void deletePeminjaman(char idKeyDelete[50], t_peminjaman source[]){
    int status = 0; // status sebagai penanda
    if (strcmp(idKeyDelete, source[0].id_peminjaman) == 0){
        // rekaman baru di paling depan
        // geser semua isi array belakang
        int i;
        for (i = 0; i < idxpeminjaman; i++){
            source[i] = source[i + 1];
        }
        status = 1;
        idxpeminjaman--;
    }else if (strcmp(idKeyDelete, source[idxpeminjaman - 1].id_peminjaman) == 0){
        // rekaman baru di belakang
        status = 1;
        idxpeminjaman--;
    }else{
        // rekaman baru memiliki posisi di tengah
        int i = 0;
        int stop = 0;
        // cari posisi
        while ((i < idxpeminjaman) && (stop == 0)){
            if (strcmp(source[i].id_peminjaman, idKeyDelete) == 0){
                stop = 1;
            }else{
                i++;
            }
        }

        if (stop == 1){
            int j;
            for (j = i; j < idxpeminjaman; j++){
                source[j] = source[j + 1];
            }
            status = 1;
            idxpeminjaman--;
        }
    }

    // flush data
    writeToFilePeminjaman(source, "t_peminjaman.txt"); // tulis ke file data yg dimodifikasi
}
// ==========================================================================

// ===============================================
// mendefinisikan prosedur dari proses modify data
// ===============================================

// mendefinisikan mesin untuk memodifikasi data arsip
void modify_data(char pita[501], char tempPita[6][50]){
    STARTKATA(pita); // menjalankan mesin kata
    strcpy(tempPita[0], GETCKATA()); // mengcopy kata pertama untuk dilakukan cek

    if (pita[strlen(pita) - 1] == ';'){ // cek pertama untuk error handling tidak ada eop/semicolon

        if (strcmp(tempPita[0], "INPUT") == 0){
            // cek jika kata pertama adalah input, maka masuk if input

            // melakukan inisialisasi pada query yg sudah dipecah pecah
            strcpy(tempPita[2], ""); 
            strcpy(tempPita[3], "");
            strcpy(tempPita[4], "");
            strcpy(tempPita[5], "");

            // salin inputan ke masing2 wadah query
            INCKATA(pita);
            strcpy(tempPita[1], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[2], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[3], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[4], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[5], GETCKATA()); // ini untuk mengecek apakah ada query lebih
            
            if (strcmp(tempPita[1], "Tperalatan") == 0){ // cek dlu apakah tabelnya tperalatan
                if (strcmp(tempPita[5], "") != 0){ // cek lagi apakah query nya kelebihan
                    // jika iya tampilkan pesan error bahwa query berlebih
                    printf("\033[1;31m[007] SQLSTATE ERROR: Syntax error, excess number of query\033[0m\n\n");
                }else if(strcmp(tempPita[2], "") == 0 || strcmp(tempPita[3], "") == 0  || strcmp(tempPita[4], "") == 0 ){ // cek lagi apakah query nya kurang
                    // jika iya tampilkan pesan error bahwa query kurang
                    printf("\033[1;31m[006] SQLSTATE ERROR: Syntax error, deficient number of query\033[0m\n\n");
                }else{ // lainnya berarti query aman

                    // lakukan pengecekan pk terlebih dahulu, menghindari pk yg diinput sama
                    int markPK = 0; // var mark untuk pk
                    for (int i = 0; i < idxperalatan; i++){ // perulangan sebanyak jumlah data
                        if (strcmp(tempPita[2], listPeralatan[i].id_peralatan) == 0){ // cek lagi apakah id yang dimasukan udh ada
                            markPK = 1; // jika ada mark menyala
                        }
                    }
                    
                    if (markPK == 1){ // jika mark pk menyala maka id yg dimasukan sudah ada
                        // tampilkan pesan error bahwa id yang di input sudah ada
                        printf("\033[1;33m[003] SQLSTATE ERROR: ID already exist\033[0m\n\n");
                    }else{ // lainnya jika id nya aman 
                        // maka lakukan menginputan data
                        strcpy(listPeralatan[idxperalatan].id_peralatan, tempPita[2]);
                        strcpy(listPeralatan[idxperalatan].nama_peralatan, tempPita[3]);
                        strcpy(listPeralatan[idxperalatan].merek_peralatan, tempPita[4]);
                        idxperalatan++; // idx atau jumlah dari data bertambah
                        writeToFilePeralatan(listPeralatan, "t_peralatan.txt"); // tulis ke file data yg di input
                        printf("\033[1;32mQuery successfully execute, 1 row affected\033[0m\n\n"); // tampilkan pesan data aman
                    }
                    
                }
            }else if (strcmp(tempPita[1], "Tpeminjaman") == 0){ // cek dlu apakah tabelnya tpeminjaman
                if (strcmp(tempPita[5], "") != 0){ // cek lagi apakah query nya kelebihan
                    // jika iya tampilkan pesan error bahwa query berlebih
                    printf("\033[1;31m[007] SQLSTATE ERROR: Syntax error, excess number of query\033[0m\n\n");
                }else if(strcmp(tempPita[2], "") == 0 || strcmp(tempPita[3], "") == 0  || strcmp(tempPita[4], "") == 0 ){ // cek lagi apakah query nya kurang
                    // jika iya tampilkan pesan error bahwa query kurang
                    printf("\033[1;31m[006] SQLSTATE ERROR: Syntax error, deficient number of query\033[0m\n\n");
                }else{ // lainnya berarti query aman

                    // lakukan pengecekan pk terlebih dahulu, menghindari pk yg diinput sama
                    int markPK = 0; // var mark untuk pk
                    for (int i = 0; i < idxpeminjaman; i++){ // perulangan sebanyak jumlah data
                        if (strcmp(tempPita[2], listPeminjaman[i].id_peminjaman) == 0){ // cek lagi apakah id yang dimasukan udh ada
                            markPK = 1; // jika ada mark menyala
                        }
                    }
                    
                    // lakukan pengecekan fk terlebih dahulu, apakah id yg menjadi fk sudah ada
                    int markFK = 0; // var mark untuk fk
                    for (int i = 0; i < idxperalatan; i++){ // perulangan sebanyak jumlah data t_peralatan
                        if (strcmp(tempPita[3], listPeralatan[i].id_peralatan) == 0){ // cek lagi apakah fk yang dimasukan udh ada di t_peralatan
                            markFK = 1; // jika ada mark menyala
                        }
                    }

                    if (markPK == 1){ // jika mark pk menyala maka id yg dimasukan sudah ada
                        // tampilkan pesan error bahwa id yang di input sudah ada
                        printf("\033[1;33m[003] SQLSTATE ERROR: ID already exist\033[0m\n\n");
                    }else if (markFK == 0){ // jika mark fk tidak menyala maka fk yg dimasukan belum ada
                        // tampilkan pesan error bahwa fk yang di input belum ada
                        printf("\033[1;33m[010] SQLSTATE ERROR: FOREIGN ID not found\033[0m\n\n"); 
                    }else{ // lainnya jika id nya aman 
                        // maka lakukan menginputan data
                        strcpy(listPeminjaman[idxpeminjaman].id_peminjaman, tempPita[2]);
                        strcpy(listPeminjaman[idxpeminjaman].fk_peralatan, tempPita[3]);
                        strcpy(listPeminjaman[idxpeminjaman].nama_peminjam, tempPita[4]);
                        idxpeminjaman++; // idx atau jumlah dari data bertambah
                        writeToFilePeminjaman(listPeminjaman, "t_peminjaman.txt"); // tulis ke file data yg di input
                        printf("\033[1;32mQuery successfully execute, 1 row affected\033[0m\n\n"); // tampilkan pesan data aman
                    }

                }
            }else{ // lainnya berarti tabelnya salah
                // maka tampilkan pesan error tabelnya tidak ada
                printf("\033[1;33m[008] SQLSTATE ERROR: Table not found\033[0m\n\n");
            }

        }else if (strcmp(tempPita[0], "SHOW") == 0){
            // cek jika kata pertama adalah show, maka masuk if show

            // salin inputan ke masing2 wadah query
            INCKATA(pita);
            strcpy(tempPita[1], GETCKATA());
            
            // lakukan cek terhadap query ke dua
            if (strcmp(tempPita[1], "Tperalatan") == 0){ // jika query kedua tperalatan

                // lakukan show untuk data yg ada di tabel tperalatan
                if (idxperalatan == 0){ // cek jika jumlah file 0
                    printf("\033[1;32mEmpty set of file\033[0m\n\n"); // cetak ini
                }else{ // jika ada file nya
                    
                    // mendeklarasikan var untuk menampung nilmax dari len setiap jenis data dan inisialisasi sesuai len dari nama atribut
                    int maxlenIDPeralatan = strlen("ID_Peralatan"), maxlenNamaPeralatan = strlen("Nama_Peralatan"), maxlenMerek = strlen("Merek");
                    for (int i = 0; i < idxperalatan; i++){ // perulangan sebanyak counter si skincare
                        // mengcek panjang lenght string dari setiap attribute data
                        if (maxlenIDPeralatan < strlen(listPeralatan[i].id_peralatan)){
                            maxlenIDPeralatan = strlen(listPeralatan[i].id_peralatan);
                        }   
                    
                        if (maxlenNamaPeralatan < strlen(listPeralatan[i].nama_peralatan)){
                            maxlenNamaPeralatan = strlen(listPeralatan[i].nama_peralatan);
                        }   
                    
                        if (maxlenMerek < strlen(listPeralatan[i].merek_peralatan)){
                            maxlenMerek = strlen(listPeralatan[i].merek_peralatan);
                        }
                    }
                    
                    // ini var untuk mentotalkan semua len total tabel(untuk bikin border tabel)
                    int allmaxlenPeralatan = maxlenIDPeralatan + maxlenNamaPeralatan + maxlenMerek;
                    
                    printf("+");
                    for (int i = 0; i < allmaxlenPeralatan + 8; i++){
                        printf("-");
                    }
                    printf("+\n");

                    printf("| ID_Peralatan");
                    for (int j = 0; j < maxlenIDPeralatan - strlen("ID_Peralatan"); j++){
                        printf(" ");
                    }
                    printf(" | Nama_Peralatan");
                    for (int j = 0; j < maxlenNamaPeralatan - strlen("Nama_Peralatan"); j++){
                        printf(" ");
                    }
                    printf(" | Merek");
                    for (int j = 0; j < maxlenMerek - strlen("Merek"); j++){
                        printf(" ");
                    }
                    printf(" |\n");

                    printf("+");
                    for (int i = 0; i < allmaxlenPeralatan + 8; i++){
                        printf("-");
                    }
                    printf("+\n");
                    for (int i = 0; i < idxperalatan; i++){
                        // menampilkan data pada terminal
                        int j;
                        printf("| %s", listPeralatan[i].id_peralatan);
                        for (j = 0; j < maxlenIDPeralatan + 1 - strlen(listPeralatan[i].id_peralatan); j++){
                            printf(" ");
                        }
                        printf("| %s", listPeralatan[i].nama_peralatan);
                        for (j = 0; j < maxlenNamaPeralatan + 1 - strlen(listPeralatan[i].nama_peralatan); j++){
                            printf(" ");
                        }
                        printf("| %s", listPeralatan[i].merek_peralatan);
                        for (j = 0; j < maxlenMerek - strlen(listPeralatan[i].merek_peralatan); j++){
                            printf(" ");
                        }
                        printf(" |\n");
                        
                    }
                    printf("+");
                    for (int i = 0; i < allmaxlenPeralatan + 8; i++){
                            printf("-");
                    }
                    printf("+\n");

                    printf("\033[1;34m[INFO] Showing Table Tperalatan\033[0m\n\n");
                }

            }else if (strcmp(tempPita[1], "Tpeminjaman") == 0){  // jika query kedua tpeminjaman
                // lakukan show untuk data yg ada di tabel tpeminjaman

                if (idxpeminjaman == 0){ // cek jika jumlah file 0
                    printf("\033[1;32mEmpty set of file\033[0m\n\n"); // cetak ini
                }else{ // jika ada file nya

                    // mendeklarasikan var untuk menampung nilmax dari len setiap jenis data dan inisialisasi sesuai len dari nama atribut
                    int maxlenIDPeminjaman = strlen("ID_Peminjaman"), maxlenFKPeralatan = strlen("ID_Peralatan"), maxlenNamaPeminjam = strlen("Nama_Peminjam");
                    for (int i = 0; i < idxperalatan; i++){ // perulangan sebanyak counter si skincare
                        // mengcek panjang lenght string dari setiap attribute data
                        if (maxlenIDPeminjaman < strlen(listPeminjaman[i].id_peminjaman)){
                            maxlenIDPeminjaman = strlen(listPeminjaman[i].id_peminjaman);
                        }   

                        if (maxlenFKPeralatan < strlen(listPeminjaman[i].fk_peralatan)){
                            maxlenFKPeralatan = strlen(listPeminjaman[i].fk_peralatan);
                        }   
                    
                        if (maxlenNamaPeminjam < strlen(listPeminjaman[i].nama_peminjam)){
                            maxlenNamaPeminjam = strlen(listPeminjaman[i].nama_peminjam);
                        }
                    }
                    
                    // ini var untuk mentotalkan semua len total tabel(untuk bikin border tabel)
                    int allmaxlenPeminjaman = maxlenIDPeminjaman + maxlenFKPeralatan + maxlenNamaPeminjam;
                    
                    printf("+");
                    for (int i = 0; i < allmaxlenPeminjaman + 8; i++){
                        printf("-");
                    }
                    printf("+\n");

                    printf("| ID_Peminjaman");
                    for (int j = 0; j < maxlenIDPeminjaman - strlen("ID_Peminjaman"); j++){
                        printf(" ");
                    }
                    printf(" | ID_Peralatan");
                    for (int j = 0; j < maxlenFKPeralatan - strlen("ID_Peralatan"); j++){
                        printf(" ");
                    }
                    printf(" | Nama_Peminjam");
                    for (int j = 0; j < maxlenNamaPeminjam - strlen("Nama_Peminjam"); j++){
                        printf(" ");
                    }
                    printf(" |\n");

                    printf("+");
                    for (int i = 0; i < allmaxlenPeminjaman + 8; i++){
                        printf("-");
                    }
                    printf("+\n");
                    for (int i = 0; i < idxpeminjaman; i++){
                        // menampilkan data pada terminal
                        int j;
                        printf("| %s", listPeminjaman[i].id_peminjaman);
                        for (j = 0; j < maxlenIDPeminjaman + 1 - strlen(listPeminjaman[i].id_peminjaman); j++){
                            printf(" ");
                        }
                        printf("| %s", listPeminjaman[i].fk_peralatan);
                        for (j = 0; j < maxlenFKPeralatan + 1 - strlen(listPeminjaman[i].fk_peralatan); j++){
                            printf(" ");
                        }
                        printf("| %s", listPeminjaman[i].nama_peminjam);
                        for (j = 0; j < maxlenNamaPeminjam - strlen(listPeminjaman[i].nama_peminjam); j++){
                            printf(" ");
                        }
                        printf(" |\n");
                        
                    }
                    printf("+");
                    for (int i = 0; i < allmaxlenPeminjaman + 8; i++){
                            printf("-");
                    }
                    printf("+\n");
                
                    printf("\033[1;34m[INFO] Showing Table Tpeminjaman\033[0m\n\n");
                }

            }else{ // lainnya jika tabel salah
                // tampilkan pesan error tabel tidak ditemukan
                printf("\033[1;33m[008] SQLSTATE ERROR: Table not found\033[0m\n\n");
            }
            
        }else if (strcmp(tempPita[0], "UPDATE") == 0){
            // cek jika kata pertama adalah update, maka masuk if update

            // melakukan inisialisasi pada query yg sudah dipecah pecah
            strcpy(tempPita[2], ""); 
            strcpy(tempPita[3], "");
            strcpy(tempPita[4], "");
            strcpy(tempPita[5], "");

            INCKATA(pita);
            strcpy(tempPita[1], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[2], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[3], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[4], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[5], GETCKATA()); // ini untuk mengecek apakah ada query lebih

            if (strcmp(tempPita[1], "Tperalatan") == 0){ // cek dlu apakah tabelnya tperalatan
                if (strcmp(tempPita[5], "") != 0){ // cek lagi apakah query nya kelebihan
                    // jika iya tampilkan pesan error bahwa query berlebih
                    printf("\033[1;31m[007] SQLSTATE ERROR: Syntax error, excess number of query\033[0m\n\n");
                }else if(strcmp(tempPita[2], "") == 0 || strcmp(tempPita[3], "") == 0  || strcmp(tempPita[4], "") == 0 ){ // cek lagi apakah query nya kurang
                    // jika iya tampilkan pesan error bahwa query kurang
                    printf("\033[1;31m[006] SQLSTATE ERROR: Syntax error, deficient number of query\033[0m\n\n");
                }else{ // lainnya berarti query aman

                    // lakukan pengecekan pk terlebih dahulu, menghindari pk yg diupdate tidak ada
                    int markPK = 0; // var mark untuk pk
                    int i = 0; // var idx counter
                    int idxUpdate = 0; // var marking untuk mengetahui data ke berapa yg diupdate
                    while (i < idxperalatan && markPK == 0){ // perulangan sebanyak jumlah data dan ketika id nya udh sesuai
                        if (strcmp(tempPita[2], listPeralatan[i].id_peralatan) == 0){ // cek apakah id nya sesuai/matching
                            markPK = 1; // jika iya mark menyala
                            idxUpdate = i; // pindahkan index pada data yg ingin diubah ke var mark index
                        }else{ // jika tidak
                            markPK = 0; // mark tetap nol untuk lanjut terus sampe cari yg sama
                        }
                        i++; // ingkremen idx counter
                    }

                    if (markPK == 0){ // jika mark pk tidak menyala maka id yg dimasukan tidak ditemukan/tidak matching
                        // tampilkan pesan error bahwa id yang dimasukan tidak ditemukan
                        printf("\033[1;33m[004] SQLSTATE ERROR: ID not found\033[0m\n\n");
                    }else{ // lainnya jika id nya aman 
                        
                        if (strcmp(tempPita[3], "ID_Peralatan") == 0){ // cek apakah kolom yg mau diubah kolom id
                            // jika iya tampilkan pesan error bahwa id tidak dapat diubah
                            printf("\033[1;33m[005] SQLSTATE ERROR: ID can't be changed\033[0m\n\n");
                        }else if (strcmp(tempPita[3], "Nama_Peralatan") == 0){ // cek apakah kolom yg mau diubah kolom nama peralatan
                            // maka lakukan update pada data
                            strcpy(listPeralatan[idxUpdate].nama_peralatan, tempPita[4]);
                            writeToFilePeralatan(listPeralatan, "t_peralatan.txt"); // tulis ke file data yg di input
                            printf("\033[1;32mQuery successfully execute, 1 row affected\033[0m\n\n"); // tampilkan pesan data aman
                        }else if (strcmp(tempPita[3], "Merek") == 0){ // cek apakah kolom yg mau diubah kolom merek
                            // maka lakukan update pada data
                            strcpy(listPeralatan[idxUpdate].merek_peralatan, tempPita[4]);
                            writeToFilePeralatan(listPeralatan, "t_peralatan.txt"); // tulis ke file data yg di input
                            printf("\033[1;32mQuery successfully execute, 1 row affected\033[0m\n\n"); // tampilkan pesan data aman
                        }else{ // lainnya berarti salah input nama kolom
                            // tampilkan pesan error salah input nama kolom
                            printf("\033[1;33m[009] SQLSTATE ERROR: Coloumn not found\033[0m\n\n");
                        }
                        
                    }
                    
                }
            }else if (strcmp(tempPita[1], "Tpeminjaman") == 0){ // cek dlu apakah tabelnya tpeminjaman
                if (strcmp(tempPita[5], "") != 0){ // cek lagi apakah query nya kelebihan
                    // jika iya tampilkan pesan error bahwa query berlebih
                    printf("\033[1;31m[007] SQLSTATE ERROR: Syntax error, excess number of query\033[0m\n\n");
                }else if(strcmp(tempPita[2], "") == 0 || strcmp(tempPita[3], "") == 0  || strcmp(tempPita[4], "") == 0 ){ // cek lagi apakah query nya kurang
                    // jika iya tampilkan pesan error bahwa query kurang
                    printf("\033[1;31m[006] SQLSTATE ERROR: Syntax error, deficient number of query\033[0m\n\n");
                }else{ // lainnya berarti query aman

                    // lakukan pengecekan pk terlebih dahulu, menghindari pk yg diupdate tidak ada
                    int markPK = 0; // var mark untuk pk
                    int i = 0; // var idx counter
                    int idxUpdate = 0; // var marking untuk mengetahui data ke berapa yg diupdate
                    while (i < idxpeminjaman && markPK == 0){ // perulangan sebanyak jumlah data dan ketika id nya udh sesuai
                        if (strcmp(tempPita[2], listPeminjaman[i].id_peminjaman) == 0){ // cek apakah id nya sesuai/matching
                            markPK = 1; // jika iya mark menyala
                            idxUpdate = i; // pindahkan index pada data yg ingin diubah ke var mark index
                        }else{ // jika tidak
                            markPK = 0; // mark tetap nol untuk lanjut terus sampe cari yg sama
                        }
                        i++; // ingkremen idx counter
                    }

                    // lakukan pengecekan fk terlebih dahulu, apakah fk yang mau diupdate ada di tabel
                    int markFK = 0; // var mark untuk fk
                    for (int i = 0; i < idxperalatan; i++){ // perulangan sebanyak jumlah data t_peralatan
                        if (strcmp(tempPita[4], listPeralatan[i].id_peralatan) == 0){ // cek lagi apakah fk yang dimasukan udh ada di t_peralatan
                            markFK = 1; // jika ada mark menyala
                        }
                    }                        
                    
                    if (markPK == 0){ // jika mark pk tidak menyala maka id yg dimasukan tidak ditemukan/tidak matching
                        // tampilkan pesan error bahwa id yang dimasukan tidak ditemukan
                        printf("\033[1;33m[004] SQLSTATE ERROR: ID not found\033[0m\n\n");
                    }else{ // lainnya jika id nya aman 
                        
                        if (strcmp(tempPita[3], "ID_Peminjaman") == 0){ // cek apakah kolom yg mau diubah kolom id
                            // jika iya tampilkan pesan error bahwa id tidak dapat diubah
                            printf("\033[1;33m[005] SQLSTATE ERROR: ID can't be changed\033[0m\n\n");
                        }else if (strcmp(tempPita[3], "ID_Peralatan") == 0){ // cek apakah kolom yg mau diubah kolom nama peralatan

                            if (markFK == 0){ // cek apakah fk yg mau di update sudah ada di tabel
                                // jika tidak ada maka tampilkan pesan error fk tidak ditemukan
                                printf("\033[1;33m[010] SQLSTATE ERROR: FOREIGN ID not found\033[0m\n\n");
                            }else{
                                // maka lakukan update pada data
                                strcpy(listPeminjaman[idxUpdate].fk_peralatan, tempPita[4]); // cek apakah kolom yg mau diubah kolom fk id_peralatan
                                writeToFilePeminjaman(listPeminjaman, "t_peminjaman.txt"); // tulis ke file data yg di input
                                printf("\033[1;32mQuery successfully execute, 1 row affected\033[0m\n\n"); // tampilkan pesan data aman
                            }
                            
                        }else if (strcmp(tempPita[3], "Nama_Peminjam") == 0){
                            // maka lakukan update pada data
                            strcpy(listPeminjaman[idxUpdate].nama_peminjam, tempPita[4]); // cek apakah kolom yg mau diubah kolom nama peminjam
                            writeToFilePeminjaman(listPeminjaman, "t_peminjaman.txt"); // tulis ke file data yg di input
                            printf("\033[1;32mQuery successfully execute, 1 row affected\033[0m\n\n"); // tampilkan pesan data aman
                        }else{ // lainnya berarti salah input nama kolom
                            // tampilkan pesan error salah input nama kolom
                            printf("\033[1;33m[009] SQLSTATE ERROR: Coloumn not found\033[0m\n\n");
                        }
                        
                    }

                }
            }else{ // lainnya berarti tabelnya salah
                // maka tampilkan pesan error tabelnya tidak ada
                printf("\033[1;33m[008] SQLSTATE ERROR: Table not found\033[0m\n\n");
            }

        }else if (strcmp(tempPita[0], "DELETE") == 0){
            // cek jika kata pertama adalah delete, maka masuk if delete

            // melakukan inisialisasi pada query yg sudah dipecah pecah
            strcpy(tempPita[2], ""); 
            strcpy(tempPita[3], "");

            // salin inputan ke masing2 wadah query
            INCKATA(pita);
            strcpy(tempPita[1], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[2], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[3], GETCKATA()); // ini untuk mengecek apakah ada query lebih

            if (strcmp(tempPita[1], "Tperalatan") == 0){ // cek dlu apakah tabelnya tperalatan
                if (strcmp(tempPita[3], "") != 0){ // cek lagi apakah query nya kelebihan
                    // jika iya tampilkan pesan error bahwa query berlebih
                    printf("\033[1;31m[007] SQLSTATE ERROR: Syntax error, excess number of query\033[0m\n\n");
                }else if(strcmp(tempPita[2], "") == 0){ // cek lagi apakah query nya kurang
                    // jika iya tampilkan pesan error bahwa query kurang
                    printf("\033[1;31m[006] SQLSTATE ERROR: Syntax error, deficient number of query\033[0m\n\n");
                }else{ // lainnya berarti query aman

                    // lakukan pengecekan pk terlebih dahulu, menghindari pk yg dihapus tidak ada
                    int markPK = 0; // var mark untuk pk
                    int i = 0; // var idx counter
                    while (i < idxperalatan && markPK == 0){ // perulangan sebanyak jumlah data dan ketika id nya udh sesuai
                        if (strcmp(tempPita[2], listPeralatan[i].id_peralatan) == 0){ // cek apakah id nya sesuai/matching
                            markPK = 1; // jika iya mark menyala
                        }else{ // jika tidak
                            markPK = 0; // mark tetap nol untuk lanjut terus sampe cari yg sama
                        }
                        i++; // ingkremen idx counter
                    }
                    
                    // lakukan pengecekan fk terlebih dahulu, apakah id menjadi fk pada tabel lain
                    int markFK = 0; // var mark untuk fk
                    i = 0; // var idx counter
                    while (i < idxpeminjaman && markFK == 0){ // perulangan sebanyak jumlah data dan ketika id nya ada di tabel lain
                        if (strcmp(tempPita[2], listPeminjaman[i].fk_peralatan) == 0){ // cek apakah id nya ada di tabel lain
                            markFK = 1; // jika iya mark menyala
                        }else{ // jika tidak
                            markFK = 0; // mark tetap nol untuk lanjut terus sampe cari yg sama
                        }
                        i++; // ingkremen idx counter
                    }

                    if (markPK == 0){ // jika mark pk tidak menyala maka id yg dimasukan tidak ditemukan/tidak matching
                        // tampilkan pesan error bahwa id yang dimasukan tidak ditemukan
                        printf("\033[1;33m[004] SQLSTATE ERROR: ID not found\033[0m\n\n");
                    }else if (markFK == 1){ // jika mark fk menyala maka id yg dimasukan jadi fk di tabel lain
                        // tampilkan pesan error bahwa id yang dimasukan tidak bisa dihapus karna jadi fk
                        printf("\033[1;33m[011] SQLSTATE ERROR: ID is on use in other table\033[0m\n\n");
                    }else{ // lainnya jika id nya aman 
                        // maka lakukan penghapusan data
                        deletePeralatan(tempPita[2], listPeralatan);
                        printf("\033[1;32mQuery successfully execute, 1 row affected\033[0m\n\n"); // tampilkan pesan data aman
                    }
                    
                }
            }else if (strcmp(tempPita[1], "Tpeminjaman") == 0){ // cek dlu apakah tabelnya tpeminjaman
                if (strcmp(tempPita[3], "") != 0){ // cek lagi apakah query nya kelebihan
                    // jika iya tampilkan pesan error bahwa query berlebih
                    printf("\033[1;31m[007] SQLSTATE ERROR: Syntax error, excess number of query\033[0m\n\n");
                }else if(strcmp(tempPita[2], "") == 0){ // cek lagi apakah query nya kurang
                    // jika iya tampilkan pesan error bahwa query kurang
                    printf("\033[1;31m[006] SQLSTATE ERROR: Syntax error, deficient number of query\033[0m\n\n");
                }else{ // lainnya berarti query aman

                    // lakukan pengecekan pk terlebih dahulu, menghindari pk yg dihapus tidak ada
                    int markPK = 0; // var mark untuk pk
                    int i = 0; // var idx counter
                    while (i < idxpeminjaman && markPK == 0){ // perulangan sebanyak jumlah data dan ketika id nya udh sesuai
                        if (strcmp(tempPita[2], listPeminjaman[i].id_peminjaman) == 0){ // cek apakah id nya sesuai/matching
                            markPK = 1; // jika iya mark menyala
                        }else{ // jika tidak
                            markPK = 0; // mark tetap nol untuk lanjut terus sampe cari yg sama
                        }
                        i++; // ingkremen idx counter
                    }

                    if (markPK == 0){ // jika mark pk tidak menyala maka id yg dimasukan tidak ditemukan/tidak matching
                        // tampilkan pesan error bahwa id yang dimasukan tidak ditemukan
                        printf("\033[1;33m[004] SQLSTATE ERROR: ID not found\033[0m\n\n");
                    }else{ // lainnya jika id nya aman 
                        // maka lakukan penghapusan data
                        deletePeminjaman(tempPita[2], listPeminjaman);
                        printf("\033[1;32mQuery successfully execute, 1 row affected\033[0m\n\n"); // tampilkan pesan data aman
                    }
                    
                }
            }else{ // lainnya berarti tabelnya salah
                // maka tampilkan pesan error tabelnya tidak ada
                printf("\033[1;33m[008] SQLSTATE ERROR: Table not found\033[0m\n\n");
            }

        }else if (strcmp(tempPita[0], "JOIN") == 0){
            // cek jika kata pertama adalah join, maka masuk if join
            
            // melakukan inisialisasi pada query yg sudah dipecah pecah
            strcpy(tempPita[1], ""); 
            strcpy(tempPita[2], ""); 
            strcpy(tempPita[3], "");

            // salin inputan ke masing2 wadah query
            INCKATA(pita);
            strcpy(tempPita[1], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[2], GETCKATA());
            INCKATA(pita);
            strcpy(tempPita[3], GETCKATA()); // ini untuk mengecek apakah ada query lebih

            // lakukan cek query ke 2 3 4
                if (strcmp(tempPita[3], "") != 0){ // cek lagi apakah query nya kelebihan
                    // jika iya tampilkan pesan error bahwa query berlebih
                    printf("\033[1;31m[007] SQLSTATE ERROR: Syntax error, excess number of query\033[0m\n\n");
                }else if(strcmp(tempPita[1], "") == 0 || strcmp(tempPita[2], "") == 0){ // cek lagi apakah query nya kurang
                    // jika iya tampilkan pesan error bahwa query kurang
                    printf("\033[1;31m[006] SQLSTATE ERROR: Syntax error, deficient number of query\033[0m\n\n");
                }else{ // lainnya ketika query aman

                    // jika yang dijoin adalah tabel tperalatan dan tpeminjaman
                    if ((strcmp(tempPita[1], "Tperalatan") == 0 && strcmp(tempPita[2], "Tpeminjaman") == 0) ||
                        (strcmp(tempPita[1], "Tpeminjaman") == 0 && strcmp(tempPita[2], "Tperalatan") == 0)){
                        
                        // tampilkan hasil dari joinnya
                        if (idxpeminjaman == 0){ // cek jika jumlah file 0
                            printf("\033[1;32mEmpty set of file\033[0m\n\n"); // cetak ini
                        }else{ // jika ada file nya

                            // mendeklarasikan var untuk menampung nilmax dari len setiap jenis data dan inisialisasi sesuai len dari nama atribut
                            int maxlenIDPeminjaman = strlen("ID_Peminjaman"), maxlenFKPeralatan = strlen("ID_Peralatan"), maxlenNamaPeminjam = strlen("Nama_Peminjam"), maxlenNamaPeralatan = strlen("Nama_Peralatan"), maxlenMerek = strlen("Merek");
                            for (int i = 0; i < idxperalatan; i++){ // perulangan sebanyak counter si skincare
                                // mengcek panjang lenght string dari setiap attribute data
                                if (maxlenIDPeminjaman < strlen(listPeminjaman[i].id_peminjaman)){
                                    maxlenIDPeminjaman = strlen(listPeminjaman[i].id_peminjaman);
                                }   

                                if (maxlenFKPeralatan < strlen(listPeminjaman[i].fk_peralatan)){
                                    maxlenFKPeralatan = strlen(listPeminjaman[i].fk_peralatan);
                                }   
                            
                                if (maxlenNamaPeminjam < strlen(listPeminjaman[i].nama_peminjam)){
                                    maxlenNamaPeminjam = strlen(listPeminjaman[i].nama_peminjam);
                                }

                                if (maxlenNamaPeralatan < strlen(listPeralatan[i].nama_peralatan)){
                                    maxlenNamaPeralatan = strlen(listPeralatan[i].nama_peralatan);
                                }   
                        
                                if (maxlenMerek < strlen(listPeralatan[i].merek_peralatan)){
                                    maxlenMerek = strlen(listPeralatan[i].merek_peralatan);
                                }
                            }
                            
                            // ini var untuk mentotalkan semua len total tabel(untuk bikin border tabel)
                            int allmaxlenPeminjaman = maxlenIDPeminjaman + maxlenFKPeralatan + maxlenNamaPeminjam + maxlenNamaPeralatan + maxlenMerek;
                            
                            printf("+");
                            for (int i = 0; i < allmaxlenPeminjaman + 14; i++){
                                printf("-");
                            }
                            printf("+\n");

                            printf("| ID_Peminjaman");
                            for (int j = 0; j < maxlenIDPeminjaman - strlen("ID_Peminjaman"); j++){
                                printf(" ");
                            }
                            printf(" | ID_Peralatan");
                            for (int j = 0; j < maxlenFKPeralatan - strlen("ID_Peralatan"); j++){
                                printf(" ");
                            }
                            printf(" | Nama_Peminjam");
                            for (int j = 0; j < maxlenNamaPeminjam - strlen("Nama_Peminjam"); j++){
                                printf(" ");
                            }
                            printf(" | Nama_Peralatan");
                            for (int j = 0; j < maxlenNamaPeralatan - strlen("Nama_Peralatan"); j++){
                                printf(" ");
                            }
                            printf(" | Merek");
                            for (int j = 0; j < maxlenMerek - strlen("Merek"); j++){
                                printf(" ");
                            }
                            printf(" |\n");

                            printf("+");
                            for (int i = 0; i < allmaxlenPeminjaman + 14; i++){
                                printf("-");
                            }
                            printf("+\n");

                            
                            for (int i = 0; i < idxpeminjaman; i++){
                                // menampilkan data pada terminal
                                int ketemu = 0; // var untuk mark ketemu fk
                                int k = 0; // var idx counter
                                // int markIDX = 0; // var untuk memark index dari fk yg matching
                                while (k < idxperalatan && ketemu == 0){
                                    if (strcmp(listPeminjaman[i].fk_peralatan, listPeralatan[k].id_peralatan) == 0){
                                        ketemu = 1;
                                        // markIDX = k;
                                    }else{
                                        ketemu = 0;
                                        k++;
                                    }
                                }

                                int j;
                                printf("| %s", listPeminjaman[i].id_peminjaman);
                                for (j = 0; j < maxlenIDPeminjaman + 1 - strlen(listPeminjaman[i].id_peminjaman); j++){
                                    printf(" ");
                                }
                                printf("| %s", listPeminjaman[i].fk_peralatan);
                                for (j = 0; j < maxlenFKPeralatan + 1 - strlen(listPeminjaman[i].fk_peralatan); j++){
                                    printf(" ");
                                }
                                printf("| %s", listPeminjaman[i].nama_peminjam);
                                for (j = 0; j < maxlenNamaPeminjam + 1 - strlen(listPeminjaman[i].nama_peminjam); j++){
                                    printf(" ");
                                }
                                printf("| %s", listPeralatan[k].nama_peralatan);
                                for (j = 0; j < maxlenNamaPeralatan + 1 - strlen(listPeralatan[k].nama_peralatan); j++){
                                    printf(" ");
                                }
                                printf("| %s", listPeralatan[k].merek_peralatan);
                                for (j = 0; j < maxlenMerek - strlen(listPeralatan[k].merek_peralatan); j++){
                                    printf(" ");
                                }
                                printf(" |\n");
                            }

                            printf("+");
                            for (int i = 0; i < allmaxlenPeminjaman + 14; i++){
                                    printf("-");
                            }
                            printf("+\n");
                        
                            printf("\033[1;34m[INFO] Showing Join Table\033[0m\n\n");

                        }

                    }else{ // lainnya jika tabel yg dijoin tidak ada
                        // tampilkan pesan error tabel tidak ditemukan
                        printf("\033[1;33m[008] SQLSTATE ERROR: Table not found\033[0m\n\n");
                    }
                    
                }
        }else if (strcmp(tempPita[0], "SHOWS") == 0){
            // cek jika kata pertama adalah shows, maka masuk if shows
            
            // salin inputan ke masing2 wadah query
            INCKATA(pita);
            strcpy(tempPita[1], GETCKATA());

            // lakukan cek untuk query ke dua
            if (strcmp(tempPita[1], "TABLES") == 0){
                // buat tampilan hardcode untuk menampilkan daftar tabel
                printf("+-------------------+\n");
                printf("| ALL TABLES        |\n");
                printf("|-------------------|\n");
                printf("| Tperalatan        |\n");
                printf("| Tpeminjaman       |\n");
                printf("+-------------------+\n");
                printf("\033[1;34m[INFO] Showing all tables\033[0m\n\n"); // tampilkan pesan info
            }else{ // lainnya jika query salah
                // tampilkan pesan error query salah
                printf("\033[1;31m[002] SQLSTATE ERROR: Syntax error, check your syntax update for new query\033[0m\n\n");
            }
            
        }else if (strcmp(tempPita[0], "EXIT") == 0){
            // cek jika kata pertama adalah exit, maka masuk if exit
            // tampilkan gambar ini
            printf("Thank you Coder, Rest Well!\n\n");
                printf("    /\\___/\\   Selamat\n");
                printf("   (  o o  )  Beristirahat!\n");
                printf("   /  \\./  \\ /\n");
                printf("  /  |   |  |\n");
                printf(" |  \\|___|/ /\n");
                printf(" |  |    | /\n");
                printf(" |__|    |/\n");
                printf("    ||  ||\n");
        }else{ // lainnya jika query nya salah
            // tampilkan pesan error jika query salah
            printf("\033[1;31m[002] SQLSTATE ERROR: Syntax error, check your syntax update for new query\033[0m\n\n");
        }

    }else{ // lainnya jika tidak ada semicolon
        // tampilkan pesan error
        printf("\033[1;31m[001] SQLSTATE ERROR: Syntax error, expect ';' in the end statement\033[0m\n\n");
    }
}
// ===============================================