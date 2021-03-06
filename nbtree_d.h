/*
File	: nbtree_d.h
Author	: SN
Last Updt : 25-5-2011
*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nbTreeNode *nbAddr;

typedef struct nbTypeInfo{
	char nama[20];
	char jk;
	int thn_lhr;
	int thn_mngl;
	int menikah;
}nbType;

typedef struct tnbFile{
	nbType	son;
	char 	parent[20];
}nbFile;

typedef struct nbTreeNode{
	nbType info; 	
	nbAddr parent; 	//Parent
	nbAddr fs; 		//First child
	nbAddr nb; 		//Next brother
}ElmtTree;

struct nbTree{
	nbAddr root;
};

/* ---------------- Konstruktor Tree ---------------- */
void nbCreate(nbTree *x);
//Membuat tree kosong (X.root=NULL)

/* ---------------- Alokasi node baru Tree ---------------- */
nbAddr nbCNode(nbType Bio);
//Alokasi untuk membuat node baru

/* ---------------- Operasi-operasi Tree ---------------- */
void nbInsert(nbTree *tRoot, nbAddr parent, nbType Bio);
// Menambah element pada node parent

nbAddr nbSearch(nbAddr root, char src[]);
// Mencari node dengan info ttn dan mengembalikan addressnya

void nbUpgrade(nbAddr *root);
// Mengupgrade parent dari beberapa node. (digunakan pada proses penghapusan)

void nbDelete(nbAddr *pDel, nbTree *pTree);
// Menghapus node tertentu dan digantikan oleh fs dari node tsb

int nbDepth(nbAddr root);
// Mengukur kedalaman suatu node dari root

void delete_node(nbTree *pTree);

/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root); 
// Postorder traversing

void nbPre(nbAddr root); 
// Preorder traversing

void nbIn(nbAddr root); 
// Inorder traversing

void nbLevelOrder(nbAddr root,int curLevel, int desLevel); 
// Levelorder traversing

/* ---------------- PRINT TREE ---------------- */
void nbPrint(nbAddr node, char tab[]);

/* ---------------- FILE Tree ---------------- */
void nbCreateFile(nbAddr root); // Fungsi
void nbOpenFile(nbTree& List); // Fungsi

void structcpy(nbFile& x, nbAddr pcur);

/* ------------------Other----------------------*/
int Hitung_Usia(int curYear, nbType Y);
void cek_sultan(int curYear, nbAddr root); 
bool isHidup(int curYear, nbAddr pCur);

#endif
