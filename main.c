#include <stdio.h>
#include "product.h"
#include "manager.h"

int main(){
#ifdef DEBUG
	printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif
	Product p[20];
	int count=0, menu, index=0;

	count = loadData(p);
	index=count;
	
	while(1){
		menu = selectMenu();
		if(menu==0) break;
		else if(menu==1){
			if(count==0) printf("데이터가 없습니다.\n");
			else listProduct(p, index);
		}
		else if(menu==2){
			if(index==20) continue;
			showProduct();
			count += addProduct(&p[index++]);
			printf("=> 추가됨\n");
		}
		else if(menu==3){
			if(count==0) continue;
			int n = selectNo(p, index);
			if(n==0){
				printf("=> 취소됨\n");
				continue;
			}
			showProduct();
			updateProduct(&p[n-1]);
			printf("수정됨\n");
		}
		else if(menu==4){
			if(count==0) continue;
			int m = selectNo(p, index);
			if(m==0){
				printf("=> 취소됨\n");
				continue;
			}
			int check;
			printf("정말로 삭제하시겠습니까?(삭제: 1) ");
			scanf("%d", &check);
			if(check==1){
				deleteProduct(&p[m-1]);
				printf("=> 삭제됨\n");
				count--;
			}
		}
		else if(menu==5){
			searchWho(p, index);
		}

		else if(menu==6){
			searchAddress(p, index);
		}
		else if(menu==7){
			searchHow(p, index);
		}
		else if(menu==8){
			saveData(p, index);
		}
	}
	printf("종료됨!\n");
}
