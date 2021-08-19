
#define MAX_TAM_IDENTIFIER 50

typedef struct DataConstDec{
    char constante[MAX_TAM_IDENTIFIER];
} DataConstDec;

typedef struct ConstDecNode{
    DataConstDec data;
    struct ConstDecNode* next;
} ConstDecNode;

void pushConstDec(ConstDecNode** head, char *dec);
DataConstDec newDataConstDec(char *dec);
void printConstantesDecimales(ConstDecNode* node);
void deleteListaConstanteDecimales(ConstDecNode** head);
