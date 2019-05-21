#include "nbtree_d.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

nbTree MyList;
nbAddr 	PDel, 
		Prec;
nbType New;
int i,
	pilih,
	menu;
char Parent[20];

int main(){
	
	//Header
	printf("Struktur data dan Algoritma : Implementasi ADT Non-Binary Tree Struktur Dinamis\n");
	printf("Dibuat Oleh :	");
	printf("Febriyoga Bagus Satria	(181511013)\n");
	printf("\t\tLuthfi Alri		(181511021)\n\n");
	printf("SILSILAH KESULTANAN YOGYAKARTA\n\n");
	
	//ALLOC
	nbCreate(&MyList);
	
	//MENU
	printf("PROGRAM MENU\n");
	printf("1. Input Element Tree\n");
	printf("2. Delete Element Tree\n");
	printf("3. Tampilkan Silsilah Keluarga\n");
	printf("4. Tampilkan Silsilah Kesultanan\n");
	printf("5. Traversal Non Binary Tree\n");
	printf("5. Exit\n");
	printf("Pilihan	:"); scanf("%d", &menu);
	switch(menu){
		case 1 : {
			//
			/*nbInsert(&MyList,nbSearch(MyList.root,"RM Ibnu Jarot"), "RM Ibnu Jarot", 'L', 35);		//HB IV
			nbInsert(&MyList,nbSearch(MyList.root,"RM Ibnu Jarot"), "RM Gathot Menol", 'L', 35);				//First Son HB V
			nbInsert(&MyList,nbSearch(MyList.root,"RM Ibnu Jarot"), "RM Mustojo", 'L', 35);			//HB V		//First Son HB IV
			nbInsert(&MyList,nbSearch(MyList.root,"RM Gathot Menol"), "RM Gusti Timur", 'L', 5);	//HB VI		//Next Brother HB V
			nbInsert(&MyList,nbSearch(MyList.root,"RM Mustojo"), "RM Murtejo", 'L', 35);			//HB VII	//!First Son HB VI
			nbInsert(&MyList,nbSearch(MyList.root,"RM Murtejo"), "RM Sujadi", 'L', 35);				//HB VIII	//!First Son HB VII
			nbInsert(&MyList,nbSearch(MyList.root,"RM Murtejo"), "RM Prawoto", 'L', 35);						//!First Son HB VII
			nbInsert(&MyList,nbSearch(MyList.root,"RM Murtejo"), "RA Murharidah", 'P', 35);						//!First Son HB VII
			nbInsert(&MyList,nbSearch(MyList.root,"RM Murtejo"), "RA Condroprojo", 'L', 35);					//!First Son HB VII*/
			
			//Input Manual
			Input :
			printf("\nInput Element Tree\n");
			printf("Nama	:"); fflush(stdin); scanf("%[^\n]s", &New.nama);
			printf("JK	:"); 	 fflush(stdin); scanf("%[^\n]s", &New.jk);
			printf("Usia	:"); scanf("%d", &New.usia);
			printf("Parent	:"); fflush(stdin); scanf("%[^\n]s", &Parent);
			nbInsert(&MyList, nbSearch(MyList.root, Parent), New);
			
			printf("\nInput Element Tree Lagi ? (1 = Ya, 2 = Kembali ke Menu)\n");
			scanf("%d", &pilih);
			if (pilih==1){
				goto Input;
			} else {
				system("cls");
				return main();
			}
				
			break;
		}
		case 2 : {
			//Delete Node
			delete_node(&MyList);
			break;
		}
		case 3 : {	
			system("cls");
			printf("===Silsilah Keluarga=== (Jumlah '-' menyatakan level)\n");	
			printf("\nDEPTH: %d\n", nbDepth(MyList.root));
			nbPrint(MyList.root, " ");
			system("pause");
			system("cls");
			break;
		}
		case 4 : {
			system("cls");
			printf("===Silsilah Kesultanan=== (Jumlah '-' menyatakan level)\n");
			printf("\nDEPTH: %d\n", nbDepth(MyList.root));	
			nbPrint(MyList.root, " ");
			system("pause");
			system("cls");
			break;
		}
		case 5 : {
			printf("\nPost Order : ");
			nbPost(MyList.root);
			printf("\nPre Order : ");
			nbPre(MyList.root);
			printf("\nIn Order : ");
			nbIn(MyList.root);
			system("pause");
			system("cls");
			break;
		}
		case 6 : {
			exit(0);
			break;
		}
	}
	
	
	//Selection
	printf("\nMENU");
	printf("\n(1) Lakukan Delete lagi \n(2) Kembalikan Tree ke Kondisi Awal \n(3) Menu");
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
			return main();
			break;
		}
	}
	
	
	return 0;
}
