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
	printf("==============================\n");
	printf("SILSILAH KESULTANAN YOGYAKARTA\n");
	printf("==============================\n\n");
	
	if (MyList.root == NULL){
		//ALLOC
		nbCreate(&MyList);
		//OPEN FILE
		nbOpenFile(MyList);
	}
	
	//MENU
	printf("PROGRAM MENU\n");
	printf("1. Input Element Tree\n");
	printf("2. Delete Element Tree\n");
	printf("3. Tampilkan Silsilah Keluarga\n");
	printf("4. Tampilkan Silsilah Kesultanan\n");
	printf("5. Traversal Non Binary Tree\n");
	printf("6. Exit\n\n");
	printf("Pilihan	:"); scanf("%d", &menu);
	switch(menu){
		case 1 : {
			Input :
			printf("\nInput Element Tree\n");
			printf("Nama	:"); fflush(stdin); scanf("%[^\n]s", &New.nama);
			printf("JK	:"); 	 fflush(stdin); scanf("%c", &New.jk);
			printf("Tahun Lahir	:"); scanf("%d", &New.thn_lhr);
			printf("Tahun Meninggal :"); scanf("%d", &New.thn_mngl);
			printf("Tahun Menikah :"); scanf("%d", &New.menikah);
			printf("Parent	:"); fflush(stdin); scanf("%[^\n]s", &Parent);
			nbInsert(&MyList, nbSearch(MyList.root, Parent), New);	
			nbPrint(MyList.root, " ");
			
			printf("\nInput Element Tree Lagi ? (1 = Ya, 2 = Kembali ke Menu)\n");
			scanf("%d", &pilih);
			if (pilih==1){
				goto Input;
			} else {
				printf("\nSave ke File ? (1 = Ya, 2 = Kembali ke Menu)\n");
				scanf("%d", &pilih);
				if (pilih == 1)
					nbCreateFile(MyList.root);
				system("cls");
				free(MyList.root);
				MyList.root=NULL;
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
			printf("===Silsilah Keluarga=== \n");
			printf("\nDEPTH: %d\n\n", nbDepth(MyList.root));
			nbPrint(MyList.root, " ");
			system("pause");
			system("cls");
			break;
		}
		case 4 : {
			system("cls");
			printf("===Silsilah Kesultanan=== \n");
			printf("\nDEPTH: %d\n\n", nbDepth(MyList.root));	
			nbPrint(MyList.root, " ");
			system("pause");
			system("cls");
			break;
		}
		case 5 : {
			printf("\nPost Order : ");
			nbPost(MyList.root);
			printf("\n\nPre Order : ");
			nbPre(MyList.root);
			printf("\n\nIn Order : ");
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
	
	return main();
}
