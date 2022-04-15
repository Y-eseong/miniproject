typedef struct{
	int name;
	int q;
	char who[100];
	char address[100];
	int price;
	int how;
} Product;

int addProduct(Product *p);
int readProduct(Product p);
void showProduct();
void listProduct(Product *p, int count);
int updateProduct(Product *p);
int deleteProduct(Product *p);
int selectMenu();
int selectNo(Product *p, int count);
