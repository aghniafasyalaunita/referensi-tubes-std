#include "MLL.h"
#include <iostream>
using namespace std;

bool isEmptyToko(listToko L){
    return L.first == nullptr;
};
bool isEmptyProduk(listProduk L){
    return L.first == nullptr;
};

void createListToko(listToko &L){
    L.first = nullptr;
    L.last = nullptr;
};

void createListProduk(listProduk &LP){
    LP.first = nullptr;
    LP.last = nullptr;
};

adrToko alokasiToko(infotypeToko X){
    adrToko p = new elmToko;
    p->info = X;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
adrProduk alokasiProduk(infotypeProduk X){
    adrProduk P = new elmProduk;
    P->info = X;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstToko(listToko &L, adrToko P){
    if (isEmptyToko(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}
void insertLastToko(listToko &L, adrToko P){
    if (isEmptyToko(L)){
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}
void insertLastProduk(listProduk &LP, adrProduk P){
    if (isEmptyProduk(LP)){
        LP.first = P;
        LP.last = P;
    } else {
       P->prev = LP.last;
       LP.last->next = P;
       LP.last = P;
    }
};


void deleteFirstToko(listToko &L, adrToko &P){
    if (isEmptyToko(L)){
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
        L.first->prev = nullptr;
    }
}

void deleteLastToko(listToko &L, adrToko &P){
    if (isEmptyToko(L)){
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.last;
        L.last = P->prev;
        P->prev = nullptr;
        L.last->next = nullptr;
    }
}
void deleteAfterToko(listToko &L, adrToko Prec, adrToko &P){
    P = Prec->next;
    Prec->next = P->next;
    (P->next)->prev = Prec;
    P->next = nullptr;
    P->prev = nullptr;
}


void deleteFirstProduk(listProduk &LP, adrProduk &P){
    if (isEmptyProduk(LP)){
        P = nullptr;
    } else if (LP.first == LP.last) {
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    } else {
        P = LP.first;
        LP.first = P->next;
        P->next = nullptr;
        LP.first->prev = nullptr;
    }
};

void deleteLastProduk(listProduk &LP, adrProduk &P){
    if (isEmptyProduk(LP)){
        P = nullptr;
    } else if (L.first == L.last) {
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    } else {
        P = LP.last;
        LP.last = P->prev;
        P->prev = nullptr;
        LP.last->next = nullptr;
    }
};

void deleteAfterProduk(listProduk &LP, adrProduk Prec, adrProduk &P){
     if (isEmptyProduk(LP)){
        P = nullptr;
    }else if (LP.first == LP.last) {
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        (P->next)->prev = Prec;
        P->next = nullptr;
        P->prev = nullptr;
    }

};

void lepasToko(listToko &L, adrToko P){
    adrToko Q;
    if (P == L.first){
        deleteFirstToko(L, Q);
    } else if (P == L.last){
        deleteLastToko(L, Q);
    } else {
        deleteAfterToko(L, P->prev, Q);
    }
}
void lepasProduk(listProduk &LP, adrProduk P){
    adrProduk Q;
    if (P == LP.first) {
        deleteFirstProduk(LP, Q);
    } else if (P == LP.last) {
        deleteLastProduk(LP, Q);
    } else {
        deleteAfterProduk(LP, P->prev, Q);
    }
};


adrToko findToko(listToko L, string idToko){
    adrToko P, found;
    P = L.first;
    while (P!=nullptr){
        if (P->info.idToko == idToko){
            found = P;
        }
        P = P->next;
    }
    return found;
}
adrProduk findProduk(listProduk LP, string kode){
    adrProduk P, found;
    P = LP.first;
    while (P!=nullptr){
        if (P->info.kode == kode){
            found = P;
        }

        P = P->next;
    }
    return found;
};
adrProduk findProdukMarketplace(listToko L, string kode, adrToko &T){
    adrProduk P;
    T = L.first;
    while (T != nullptr) {
        P = findProduk(T->lProduk, kode);
        if (P != nullptr) {
            return P;
        }
        T = T->next;
    }
    T = nullptr;
    return nullptr;
};

void printToko(adrToko T){
    cout<< "[" << T->info.idToko << "] " << T->info.nama<< " | kota: " << T->info.kota<< " | rating: " << T->info.rating << endl;
}
void printProduk(adrProduk P){
    cout << "   - " << P->info.kode << " | " << P->info.nama<< " | " << P->info.kategori<< " | Rp" << P->info.harga<< " | stok: " << P->info.stok << endl;
}
void printListProduk(listProduk LP){
     adrProduk P = LP.first;
    if (P == nullptr) {
        cout << "   (belum ada produk)" << endl;
    }
    while (P != nullptr) {
        printProduk(P);
        P = P->next;
    }
}
void printAll(listToko L){
    adrToko T = L.first;
    if (T == nullptr) {
        cout << "Marketplace masih kosong." << endl;
    }
    while (T != nullptr) {
        printToko(T);
        printListProduk(T->lProduk);
        T = T->next;
    }
}


int totalNilaiStok(listProduk LP){
    int total = 0;
    adrProduk P = LP.first;
    while (P != nullptr){
        total += (int)P->info.harga * P->info.stok;
        P = P->next;
    }
    return total;
}

// cari toko dengan total nilai stok tertinggi
adrToko findTokoStokTertinggi(listToko L, int &maxNilai){
    adrToko T = L.first;
    adrToko best = nullptr;
    maxNilai = 0;
    while (T != nullptr){
        int nilai = totalNilaiStok(T->lProduk);
        if (best == nullptr || nilai > maxNilai){
            best = T;
            maxNilai = nilai;
        }
        T = T->next;
    }
    return best;
}

void printTokoStokTertinggi(listToko L){
    int maxNilai;
    adrToko T = findTokoStokTertinggi(L, maxNilai);
    if (T == nullptr){
        cout << "Marketplace masih kosong." << endl;
    } else {
        cout << "Toko dengan nilai stok tertinggi:" << endl;
        printToko(T);
        cout << "Total nilai stok: Rp" << maxNilai << endl;
    }
}

int nbToko(listToko L){
    int n = 0;
    adrToko T = L.first;
    while (T != nullptr){ n++; T = T->next; }
    return n;
}

int nbProduk(listProduk LP){
    int n = 0;
    adrProduk P = LP.first;
    while (P != nullptr){ n++; P = P->next; }
    return n;
}
