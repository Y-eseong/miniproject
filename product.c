#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

int addProduct(Product *p){
	int orderName;
	printf("어떤 품목? ");
	scanf("%d", &orderName);
	p->name=orderName;
	printf("몇 개? ");
	scanf("%d", &p->q);
	if(orderName==1) p->price=p->q*4000;
	else if(orderName==2) p->price=p->q*15800;
	else if(orderName==3) p->price=p->q*19800;
	printf("이름? ");
	scanf("%s", p->who);
	printf("배송지?(ex.서울특별시/종로구/...) ");
	scanf("%s", p->address);
	printf("배송방법은?(1 새벽배송 2 택배배송) ");
	scanf("%d", &p->how);
	printf("------");
	return 1;
}
void showProduct(){
	printf("\n***MENU***\n");
	printf("1. [거창] 딸기 크리스피롤 1봉(대한민국 최고 농업기술에 선정된 명인): 4,000원\n");
	printf("2. [담양] 신령 호두 100g (대한민국 과일산업대전 대표과일에 선정된 명인): 15,800원\n");
	printf("3. [산청] 반건시 곶감 10개입(대한민국 과일산업대전 대표과일에 선정된 명인): 19,800원\n");
}
int readProduct(Product p){
	if(p.name==1) printf("[거창] 딸기 크리스피롤 1봉(대한민국 최고 농업기술에 선정된 명인) %d개: %d원\n  주문자: %s, 배송지: %s", p.q, p.price, p.who, p.address);
	else if(p.name==2) printf("[담양] 신령 호두 100g (대한민국 과일산업대전 대표과일에 선정된 명인) %d개: %d원\n  주문자: %s, 배송지: %s", p.q, p.price, p.who, p.address);
	else if(p.name==3) printf("[산청] 반건시 곶감 10개입(대한민국 과일산업대전 대표과일에 선정된 명인) %d개: %d원\n  주문자: %s, 배송지: %s", p.q, p.price, p.who, p.address);
	if(p.how==1) printf(", 배송 방법: 새벽배송\n");
	else if(p.how==2) printf(", 배송 방법: 택배배송\n");
	return 1;
}
void listProduct(Product *p, int count){
	printf("===================\n");
	for(int i=0; i<count; i++){
		if(p[i].price==-1) continue;
		printf("%2d", i+1);
		readProduct(p[i]);
	}
}
int updateProduct(Product *p){
	int orderName;
	printf("어떤 품목? ");
	scanf("%d", &orderName);
	p->name=orderName;
	printf("몇 개? ");
	scanf("%d", &p->q);
	if(orderName==1) p->price=p->q*4000;
	else if(orderName==2) p->price=p->q*15800;
	else if(orderName==3) p->price=p->q*19800;
	printf("이름? ");
	scanf("%s", p->who);
	printf("배송지?(ex.서울특별시/종로구/...) ");
	scanf("%s", p->address);
	printf("배송방법은?(1 새벽배송 2 택배배송) ");
	scanf("%d", &p->how);
	printf("------");
	return 1;
}
int deleteProduct(Product *p){
	p->price=-1;
	return 1;
}
int selectMenu(){
	int menu;
	printf("1. 주문 조회\n");
	printf("2. 주문하기\n");
	printf("3. 주문 수정\n");
	printf("4. 주문 삭제\n");
	printf("5. 이름 검색\n");
	printf("6. 주소 검색\n");
	printf("7. 배송 방법 검색\n");
	printf("8. 파일 저장\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	return menu;
}
int selectNo(Product *p, int count){
	int n;
	listProduct(p, count);
	printf("번호는 (취소: 0)? ");
	scanf("%d", &n);
	return n;
}
