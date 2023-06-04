#include "WiFirouter.h"
#include "list.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

int main() {
	list* head = NULL;
	int n = 0, close = 0,
		delnum = 0,printnum = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		printf("\nВ списке %d элементов.\n", NumberOfElements(head));
		printf("\tВыберите действие:\n");
		printf("1 - добавить элемент\n");
		printf("2 - удалить элемент\n");
		printf("3 - вывести элемент\n");
		printf("4 - напечатать список\n");
		printf("0 - выйти\n");
		printf("Вводите: ");
		scanf("%d", &n);

		if (n == 1) {
			wifi* w = createwifi();
			head = InsertToStart(w, head);
			free(w);
		}
		if (n == 2) {
			puts("Введите номер элемента для удаленя");
			scanf("%d", &delnum);
			head = Delete_Number(delnum, head);
		}
		if (n == 3) {
			scanf("%d", &printnum);
			Print_Number(printnum, head);
		}
		if (n == 4) {
			printList(head);
		}
		if (n == 0) {
			close = 1;
		}

	}while(!close);
	
	for (int i = NumberOfElements(head); i > 0; i--) {
		head = Delete_Number(1, head);
	}
		printf("Число элементов в списке:%d", NumberOfElements(head));

};



int mainA() {
	list* head = NULL;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	wifi* w1 = initializewifi(6000, 4, 2, "ASUS RT-AX55");
	
	wifi* w2 = initializewifi(5000, 4, 2, "TP - Link Archer AX1800");
	
	wifi* w3 = initializewifi(4300, 3, 2, "ASUS RT - AX53U");
	
	wifi* w4 = initializewifi(4000, 3, 2, "Huawei AX3 Pro");

	Print(w1);
	Print(w2);
	Print(w3);
	Print(w4);
	if (Equals(w1, w2) == 1)printf("\nВайфай роутер 1 и вайфай роутер 2: одинаковые\n");
	else printf("\nВайфай роутер 1 и вайфай роутер 2: разные\n");
	if (Compareprices(w1, w2) == 1) printf("\n1 вайфай роутер дешевле 2\n");
	if (Compareprices(w1, w2) == -1) printf("\n1 вайфай роутер дороже 2\n");
	free(w1);
	free(w2);
	free(w3);
	free(w4);

	return EXIT_SUCCESS;
}
