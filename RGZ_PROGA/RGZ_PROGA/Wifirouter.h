#ifndef WiFirouter_H_

#define WiFirouter_H_
#define MODEL_LENGTH 50
typedef struct WiFirouter {
	double price;
	int lanports;
	int cores;
	char model[MODEL_LENGTH];
} wifi;
wifi* initializewifi(double price, int lanports, int cores, char* model);
void Print(wifi* w);
int Equals(wifi* w1, wifi* w2);
int Compareprices(wifi* w1, wifi* w2);
#endif //WiFirouter_H_