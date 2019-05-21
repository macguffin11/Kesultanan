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
	nbInsert(&MyList,nbSearch(MyList.root,"RM Ibnu Jarot"), "RM Ibnu Jarot", 'L', 35);		//HB IV
	nbInsert(&MyList,nbSearch(MyList.root,"RM Ibnu Jarot"), "RM Gathot Menol", 'L', 35);				//First Son HB V
	nbInsert(&MyList,nbSearch(MyList.root,"RM Ibnu Jarot"), "RM Mustojo", 'L', 35);			//HB V		//First Son HB IV
	nbInsert(&MyList,nbSearch(MyList.root,"RM Gathot Menol"), "RM Gusti Timur", 'L', 5);	//HB VI		//Next Brother HB V
	nbInsert(&MyList,nbSearch(MyList.root,"RM Mustojo"), "RM Murtejo", 'L', 35);			//HB VII	//!First Son HB VI
	nbInsert(&MyList,nbSearch(MyList.root,"RM Murtejo"), "RM Sujadi", 'L', 35);				//HB VIII	//!First Son HB VII
	nbInsert(&MyList,nbSearch(MyList.root,"RM Murtejo"), "RM Prawoto", 'L', 35);						//!First Son HB VII
	nbInsert(&MyList,nbSearch(MyList.root,"RM Murtejo"), "RA Murharidah", 'P', 35);						//!First Son HB VII
	nbInsert(&MyList,nbSearch(MyList.root,"RM Murtejo"), "RA Condroprojo", 'L', 35);					//!First Son HB VII
	
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
//	printf("\nLevel Order : ");
//	nbLevelOrder(MyList.root,1,2);
	printf("\nDEPTH: %d\n", nbDepth(MyList.root));
}
