
#define MAX_TAM_IDENTIFIER 50

typedef struct DataConstReal{
    char constante[MAX_TAM_IDENTIFIER];
} DataConstReal;

typedef struct ConstRealNode{
    DataConstReal data;
    struct ConstRealNode* next;
} ConstRealNode;

void pushConstReal(ConstRealNode** head, char *real);
DataConstReal newDataConstReal(char *real);
void printConstantesReales(ConstRealNode* node);
void deleteListaConstanteReales(ConstRealNode** head);
