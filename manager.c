#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

void searchWho(Product *p, int count){
	char who[100];
	int c=0;
	printf("이름? ");
	scanf("%s", who);
	for(int i=0; i<count; i++){
		if(p[i].price==-1) continue;
		if(strncmp(p[i].who, who, sizeof(who))==0){
		       	readProduct(p[i]);
			c++;
			break;
		}
	}
	if(c==0) printf("해당 이름이 없습니다.\n");
}
void searchAddress(Product *p, int count){
	char address[100];
	int c=0;
	printf("주소는? ");
	scanf("%s", address);
	for(int i=0; i<count; i++){
		if(p[i].price==-1) continue;
		if(strstr(p[i].address, address)){
			readProduct(p[i]);
		 	c++;				
		}
	}
	if(c==0) printf("해당 주소가 없습니다.\n");
	
}
void searchHow(Product *p, int count){
	int how;
	int c=0;
	printf("배송 방법은(1 새벽배송 2 택배배송)? ");
	scanf("%d", &how);
	for(int i=0; i<count; i++){
		if(p[i].price==-1) continue;
		if(how==p[i].how){
		readProduct(p[i]);
		c++;
		}
	}	
	if(c==0) printf("해당 배송 방법이 없습니다.\n");
}
void saveData(Product *p, int count){
	FILE *fp;
	fp=fopen("product.txt", "wt");
	for(int i=0; i<count; i++){
		if(p[i].price==-1) continue;
		fprintf(fp, "%d %d %d %s %s %d\n", p[i].name, p[i].q, p[i].price, p[i].who, p[i].address, p[i].how);
	}	
	fclose(fp);
	printf("=>저장됨\n");
}
int loadData(Product *p){
	int count =0, i;
	FILE *fp;
	fp=fopen("product.txt", "rt");
	for(i=0; i<100; i++){
		fscanf(fp, "%d", &p[i].name);
		if(feof(fp)) break;
		fscanf(fp, "%d", &p[i].q);
		fscanf(fp, "%d", &p[i].price);
		fscanf(fp, "%s", p[i].who);
		fscanf(fp, "%s", p[i].address);
		fscanf(fp, "%d", &p[i].how);
		count++;
	}
	fclose(fp);
	if(count==0) printf("=> 파일없음\n");
	else printf("=>불러옴\n");
	
	return i;
}
