#ifndef LIST_H_

#define _LIST_H_

#include "WiFirouter.h"

typedef struct WiFiListElement {
	wifi* value;
	struct WiFiListElement* next;
} list;
list* InsertToStart(wifi* newValue, list* head);
void printList(list* head);
int NumberOfElements(list* head);
list* Delete_Number(int Num, list* head);
void* Print_Number(int Num, list* head);
wifi* createwifi();
#endif //LIST_H_
