#include "nbtree_d.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

nbTree MyList;
nbAddr 	PDel, 
		Prec;
nbType New;
int i,
	pilih,
	menu;
char Parent[20],
	cari[20],
	status[14];

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
	printf("2. Update Info Tree\n");
	printf("3. Tampilkan Silsilah Keluarga\n");
	printf("4. Pewaris Tahta Kesultanan\n");
	printf("5. Traversal Non Binary Tree\n");
	printf("6. Exit\n\n");
	printf("Pilihan	:"); scanf("%d", &menu);
	switch(menu){
		case 1 : {
			Input :
			printf("\nInput Element Tree\n");
			printf("Nama			: "); fflush(stdin); scanf("%[^\n]s", &New.nama);
			printf("JK			: "); 	 fflush(stdin); scanf("%c", &New.jk);
			printf("Tahun Lahir		: "); scanf("%d", &New.thn_lhr);
			printf("Tahun Meninggal 	: "); scanf("%d", &New.thn_mngl);
			printf("Pernah Menikah (1=Y/0=T): "); scanf("%d", &New.menikah);
			printf("Parent	: "); fflush(stdin); scanf("%[^\n]s", &Parent);
			nbInsert(&MyList, nbSearch(MyList.root, Parent), New);	
			nbPrint(MyList.root, " ");
			
			printf("\nInput Element Tree Lagi ? (1 = Ya, 2 = Kembali ke Menu)\n");
			scanf("%d", &pilih);
			if (pilih==1){
				goto Input;
			} else {
				printf("\nSave ke File ? (1 = Ya, 2 = Tidak)\n");
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
			//UPDATE INFO TREE
			system("cls");
			break;
		}
		case 3 : {	
			system("cls");
			printf("===Silsilah Keluarga Besar Kesultanan=== \n");
			printf("\nDEPTH: %d\n\n", nbDepth(MyList.root));
			nbPrint(MyList.root, " "); 
			printf("\n1. Tampilkan Biodata \n2. Cek Sultan \nPilih :"); scanf("%d", &pilih);
			switch(pilih){
				case 1 : {
						printf("\nTampilkan Biodata \n(Masukkan Nama)	: "); fflush(stdin); scanf("%[^\n]", &cari);
						printf("Jenis Kelamin	: %c\n", nbSearch(MyList.root, cari)->info.jk);
						printf("Tahun Lahir	: %d\n", nbSearch(MyList.root, cari)->info.thn_lhr);
						
						if(nbSearch(MyList.root, cari)->info.thn_mngl == 0){
							printf("Tahun Wafat	: [Belum Wafat]\n");
						}else {
							printf("Tahun Wafat	: %d\n", nbSearch(MyList.root, cari)->info.thn_mngl);
						}
					
						if(nbSearch(MyList.root, cari)->info.menikah==1){
							strcpy(status, "Sudah Menikah");
						} else {
							strcpy(status, "Belum Menikah");
						}
						printf("Status		: %s\n", status);
					break;
				}
				case 2 : {
						printf("\nCek Sultan (Pada Tahun)	= "); scanf("%d", &pilih);
						cek_sultan(pilih, MyList.root);
					break;
				}
			}
			printf("\n");
			system("pause");
			system("cls");
			break;
		}
		case 4 : {
			system("cls");
			printf("===Pewaris Tahta Kesultanan=== \n");	
			nbPrint(MyList.root, " ");
			printf("(RM Ibnu Jarot = Sultan ke-4)\n\n");
			printf("Tampilkan Silsilah :\n1. Sultan ke-5 \n2. Sultan ke-6 \n3. Sultan ke-7 \n4. Sultan ke-8 \n5. Sultan ke-9 \n6. Sultan ke-10 \n7. Sultan ke-11\n\n");
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
			printf("\n\n");
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
