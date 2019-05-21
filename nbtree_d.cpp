#include <limits.h>
#include <malloc.h>
#include "nbtree_d.h"

void nbCreate(nbTree *x){
	(*x).root=NULL;
}

nbAddr nbCNode(char X[], char jk, int u){
	nbAddr newNode;
	newNode=(nbAddr) malloc(sizeof(ElmtTree));
	if (newNode != NULL){
		strcpy(newNode->info.nama,X);
		newNode->info.jk=jk;
		newNode->info.usia=u;
		newNode->parent=NULL;
		newNode->fs=NULL;
		newNode->nb=NULL;
	}
	return newNode;
}

void nbInsert(nbTree *tRoot, nbAddr parent, char X[], char jk, int u){
	
	nbAddr newNode, temp;
	
	newNode=nbCNode(X, jk, u);
	if (newNode !=NULL){ //Jika penciptaan node baru berhasil
		if (parent==NULL) //JIka belum terdapat root
			tRoot->root=newNode;
		else{
			temp=parent;
			if (temp->fs != NULL){
				temp=temp->fs;
				while(temp->nb!=NULL)
					temp=temp->nb;
				temp->nb=newNode;
			}else
				temp->fs=newNode;
			newNode->parent=parent;
		}
	}
}

nbAddr nbSearch(nbAddr root, char src[]){
	nbAddr nSrc;
	if (root!=NULL){
		if (strcmp(root->info.nama, src) == 0)
			return root;
		else{
			nSrc=nbSearch(root->fs,src);
			if (nSrc==NULL)
				return nbSearch(root->nb,src);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}

void nbUpgrade(nbAddr *root){
	nbAddr temp;
	temp=(*root)->nb;
	if ((*root)->fs==NULL)
		(*root)->fs=temp;
	while(temp!=NULL){
		temp->parent=*root;
		temp=temp->nb;
	}
}

void nbDelete(nbAddr *pDel, nbTree *pTree){
	nbAddr pCur;
	pCur=*pDel;

	if (pCur==pTree->root && pCur->fs==NULL){
		pTree->root=NULL;
		return;
	}

	while(pCur->fs!=NULL){
		pCur=pCur->fs;
	}

//	while (pCur!=*pDel){
//		nbUpgrade(&pCur);
//		if (pCur->parent!=NULL){
//			pCur->nb=pCur->parent->nb;
//		}
//		else{
//			pCur->nb=NULL;
//			pCur=pCur->parent;
//		}
//	}

	if (pCur->parent!=NULL){
		pCur->parent->fs=pCur->fs;
	}
	if (pCur->fs!=NULL){
		pCur->fs->parent=pCur->parent;
	}
	if (pCur->parent==NULL){
		pTree->root=pCur;
	}
}

void delete_node(nbTree *pTree){
	
	nbAddr pdel, temp, temp2, tempNb;
	pdel=pTree->root;
	char value[20];
	int i=0;
	printf("\nNode yg di delete : ");
	scanf("%[^\n]", value);
	
	if(pTree->root != NULL){
		pdel=nbSearch(pTree->root,value);
		if(pdel->fs != NULL){
			temp = pdel;
			while(temp->fs != NULL){
				strcpy(temp->info.nama, temp->fs->info.nama);
				tempNb=temp->fs->nb;
				temp2 = temp;
				temp=temp->fs;
			}
			temp2->fs=tempNb;
			temp->nb=NULL;
			temp->parent=NULL;
			pdel = temp;
		}
		else if(pdel->fs==NULL){
			temp=pdel->parent;
			
			if(temp->fs==pdel){
				temp->fs=pdel->nb;
			}
			else{
				temp=temp->fs;
				while(temp->nb != NULL ){
					if(temp->nb==pdel){
						temp->nb = temp->nb->nb;
						
					}
					else{
						temp=temp->nb;
					}
				}
			}
		}
		//null_node(&pdel);
		free(pdel);
	}
	else{
		printf("Tree Kosong!!!");
	}
}

int nbDepth(nbAddr root)
{
	int y=0,z=0;

	if(root==NULL) {
		return -1;
	}else {
		y=nbDepth(root->fs);
		z=nbDepth(root->nb);
		
		if (root->parent == NULL || root->parent->fs == root) {
			if (y > z)
				return (y+1);
			else
				return (z+1);		
		}else {
			if (y > z)
				return (y);
			else
				return (z);	
		}
	}
}

/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root){
	if (root!=NULL){
		nbPost(root->fs);
		printf("%s ", root->info.nama);
		nbPost(root->nb);
	}
/*
// Post Order Non Rekursif -> selesai
nbAddr pCur;
	boolean arah;
	arah=0;

	pCur=pTree.root;
	do{
		if(pCur->fs!=NULL && arah==0)
			pCur=pCur->fs;
		else{
			printf("%d ", pCur->info);
			arah=0;
			if (pCur->nb!= NULL)
				pCur=pCur->nb;
			else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);
*/
}

void nbPre(nbAddr root){
	if (root!=NULL){
		printf("%s ", root->info.nama);
		nbPre(root->fs);
		nbPre(root->nb);
	}
/*
// Pre order Non Rekursif -> Selesai
nbAddr pCur;
	boolean arah;
	arah=0;

	pCur=pTree.root;
	printf("%d ", pCur->info);
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
			printf("%d ", pCur->info);
		}else{
			arah=0;
			if (pCur->nb!= NULL){
				pCur=pCur->nb;
				printf("%d ", pCur->info);
			}else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);*/

}

void nbIn(nbAddr root){
	if (root!=NULL){
		nbIn(root->fs);
		if (root->fs==NULL) printf("%s ", root->info.nama);
		if (root->parent !=NULL)
			if (root->parent->fs==root)
				printf("%s ", root->parent->info.nama);
		nbIn(root->nb);
	}

/*
// Inorder non rekursif -> belum selesai
	nbAddr pCur;
	int arah;
	arah=0;

	pCur=pTree.root;
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
		}else{
			if (pCur->nb!= NULL){
				printf("%d ", pCur->info);
				pCur=pCur->nb;
			}else{
					printf("%d ", pCur->info);
					arah=1;
				pCur=pCur->parent;
			}
			if (arah==0 && pCur->parent!=NULL)
				printf("%d ", pCur->parent->info);
			if (arah==0) arah=1;
		}
	}while(pCur!=NULL);
*/
}



void nbLevelOrder(nbAddr root,int curLevel, int desLevel)
{
	if(root!=NULL)
	{
		if(curLevel==desLevel)
			printf("%s  ",root->info.nama);
		nbLevelOrder(root->fs,curLevel+1,desLevel);
		nbLevelOrder(root->nb,curLevel,desLevel);
	}
}

void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (node!=NULL){
		printf("%s %s\n",tab,node->info.nama);
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}

void nbCreateFile(){
	
}

void nbOpenFile(){
	
}
