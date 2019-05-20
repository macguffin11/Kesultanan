#include "nbtree_d.h"

nbTree MyList;
nbAddr 	PDel, 
		Prec;
int i,
	pilih;
			
void Print_R_D();

int main(){
	printf("Struktur data dan Algoritma : ADT Non-Binary Tree Struktur Dinamis\n");
	
	//ALLOC
	nbCreate(&MyList);
	
	//Create Root
	nbInsert(&MyList,nbSearch(MyList.root,0),13);
	nbInsert(&MyList,nbSearch(MyList.root,13),1);
	nbInsert(&MyList,nbSearch(MyList.root,13),8);
	nbInsert(&MyList,nbSearch(MyList.root,13),97);
	nbInsert(&MyList,nbSearch(MyList.root,1),26);
	nbInsert(&MyList,nbSearch(MyList.root,1),4);
	nbInsert(&MyList,nbSearch(MyList.root,4),5);
	nbInsert(&MyList,nbSearch(MyList.root,4),6);
	nbInsert(&MyList,nbSearch(MyList.root,4),7);
	nbInsert(&MyList,nbSearch(MyList.root,97),24);
	nbInsert(&MyList,nbSearch(MyList.root,97),25);
	nbInsert(&MyList,nbSearch(MyList.root,97),10);
	
	//Print Root & Depth
	Print_R_D();
	
	//Delete Node
	delete_node(&MyList);
	
	//Print Root & Depth
	Print_R_D();
	
	//Selection
	printf("\nMENU");
	printf("\n(1) Lakukan Delete lagi \n(2) Kembalikan Tree ke Kondisi Awal \n(3) Exit");
	scanf("%d", &pilih);
	switch(pilih){
		case 1 :{
			delete_node(&MyList);
			break;
		}
		case 2 :{
			system("cls");
			return main();
			break;
		}
		case 3 :{
			exit(0);
			break;
		}
	}
	
	
	return 0;
}

void Print_R_D(){
	printf("===Root=== (Jumlah '-' menyatakan level)\n");	
	nbPrint(MyList.root, " ");
	printf("\nPost Order : ");
	nbPost(MyList.root);
	printf("\nPre Order : ");
	nbPre(MyList.root);
	printf("\nIn Order : ");
	nbIn(MyList.root);
	printf("\nDEPTH: %d\n", nbDepth(MyList.root));
}
