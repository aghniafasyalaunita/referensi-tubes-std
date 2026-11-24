#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct infotypeToko {
    string idToko;
    string nama;
    string kota;
    float rating;
};

struct infotypeProduk {
    string kode;
    string nama;
    string kategori;
    int harga;
    int stok;
};

typedef struct elmToko *adrToko;
typedef struct elmProduk *adrProduk;

struct elmProduk {
    infotypeProduk info;
    adrProduk next;
    adrProduk prev;
};

struct listProduk {
    adrProduk first;
    adrProduk last;
};

struct elmToko {
    infotypeToko info;
    listProduk lProduk;
    adrToko next;
    adrToko prev;
};

struct listToko {
    adrToko first;
    adrToko last;
};

bool isEmptyToko(listToko L);
bool isEmptyProduk(listProduk L);

void createListToko(listToko &L);
void createListProduk(listProduk &LP);

adrToko alokasiToko(infotypeToko X);
adrProduk alokasiProduk(infotypeProduk X);

void insertFirstToko(listToko &L, adrToko P);
void insertLastToko(listToko &L, adrToko P);
void insertLastProduk(listProduk &LP, adrProduk P);

void deleteFirstToko(listToko &L, adrToko &P);
void deleteLastToko(listToko &L, adrToko &P);
void deleteAfterToko(listToko &L, adrToko Prec, adrToko &P);

void lepasToko(listToko &L, adrToko P);
void lepasProduk(listProduk &LP, adrProduk P);

adrToko findToko(listToko L, string idToko);
adrProduk findProduk(listProduk LP, string kode);
adrProduk findProdukMarketplace(listToko L, string kode, adrToko &T);

void printToko(adrToko T);
void printProduk(adrProduk P);
void printListProduk(listProduk LP);
void printAll(listToko L);
int nbToko(listToko L);
int nbProduk(listProduk LP);


#endif // MLL_H_INCLUDED
