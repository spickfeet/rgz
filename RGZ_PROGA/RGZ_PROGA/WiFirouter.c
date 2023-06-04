#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "WiFirouter.h"
#include "list.h"


wifi* initializewifi(double price, int lanports, int cores, char* model) {
	wifi* newwifi = malloc(sizeof(wifi));
	if (price < 999) price = 999;
	if (price > 200000) price = 200000;
	if (lanports < 1) lanports = 1;
	if (lanports > 4) lanports = 4;
	if (cores < 1) cores = 1;
	if (cores > 4) cores = 4;
	if (model == NULL) strncpy(newwifi->model, "Модель не указана", MODEL_LENGTH);
	
	newwifi->price = price;
	newwifi->lanports = lanports;
	newwifi->cores = cores;
	strncpy(newwifi->model, model, MODEL_LENGTH);
	
	return newwifi;
}
void Print(wifi* w) {
	printf("\n\nМодель: %s\n", w->model);
	printf("Цена: %.2f\n", w->price);
	printf("Количество портов: %d\n", w->lanports);
	printf("Количество ядер: %i", w->cores);

}

int Equals(wifi* w1, wifi* w2) {
	if (w1->price == w2->price &&
		w1->cores == w2->cores &&
		w1->lanports == w2->lanports &&
		strcmp(w1->model, w2->model) == 0) {
		return 1;
	}
	return 0;
}
int Compareprices(wifi* w1, wifi* w2) {
	if (w1->price < w2->price) return 1;
	if (w1->price > w2->price) return -1;
	return 0;
}
list* InsertToStart(wifi* newValue, list* head) {
	list* newItem = malloc(sizeof(list));
	newItem->value = newValue;
	newItem->next = head;
	return newItem;
}

void printList(list* head) {
	 for(list* item = head; item != NULL; item = item->next) {
	 Print(item->value);
	 }
	printf("\n");
}
int NumberOfElements(list* head) {
	int c = 0;
	for (list* item = head; item != NULL; item = item->next) {
		c += 1;
	}
	return c;
}

list* Delete_Number(int Num, list* head)
{
	
	list* p = head, * t;
	int i = 1;
	if (head == NULL) { puts("Список пуст!"); return NULL; }
	if (Num == 1) // Удаление элемента из начала списка
	{
		t = head;
		head = head->next;
		free(t);
		return head;
	}
	while (p->next != NULL)
		if (Num == i + 1) // Удаление элемента из середины списка
		{
			t = p->next;
			p->next = p->next->next;
			free(t);
			return head;
		}
		else
		{
			i++;
			p = p->next;
		}
	puts("Такого номера в списке нет!"); // Такого номера в списке нет
	return head;
}
void* Print_Number(int Num, list* head)
{
	list* p = head, * t;
	int i = 1;
	if (head == NULL) { puts("Список пуст!"); return; }
	if (Num == 1) {
		Print(head->value); 
		return;
	}// вывод первого элемента списка

		
	while (p->next != NULL)
		if (Num == i + 1) // Вывод элемента из середины и конца списка
		{
			t = p->next;
			Print(t->value);
			return;
		}
		else
		{
			i++;
			p = p->next;
		}
	puts("Такого номера в списке нет!");// Такого номера в списке нет
	return;
}
wifi* createwifi() {
	double price = 0;
	int lanports = 0, cores = 0;
	char model[MODEL_LENGTH];
	puts("Введите цену");
	scanf("%f", &price);
	puts("Введите количество LAN портов");
	scanf("%d", &lanports);
	puts("Введите количество ядер");
	scanf("%d", &cores);
	puts("Введите модель");
	scanf("%s", model);
	wifi* w = initializewifi(price, lanports, cores, model);
	return w;
}
