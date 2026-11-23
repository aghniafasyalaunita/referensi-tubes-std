#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include "mll.h"

struct Infotype{
    int harga;
    string kode;
    adrProduk produk;
    adrToko toko;
};

typedef struct Node *Address;

struct Node{
    Infotype info;
    Address left;
    Address right;
};

typedef Address BinTree;

void createTree(BinTree &root);
bool isEmptyTree(BinTree root);
bool lebihKecil(Infotype a, Infotype b);
bool lebihBesar(Infotype a, Infotype b);
bool sama(Infotype a, Infotype b);
Address createNode(Infotype x);
void deallocate(Address &N);

void insertBST(Infotype x, BinTree &N);
Address findNode(Infotype x, BinTree N);
Address findHarga(int harga, BinTree N);
Address findMin(BinTree root);
Address findMax(BinTree root);
BinTree deleteBST(BinTree root, Infotype x);

void printInfo(Infotype x);
void preOrder(BinTree root);
void inOrder(BinTree root);
void postOrder(BinTree root);
void cariRentangHarga(BinTree root, int hMin, int hMax, int &jumlah);
int hitungNode(BinTree root);
int tinggiTree(BinTree root);

#endif