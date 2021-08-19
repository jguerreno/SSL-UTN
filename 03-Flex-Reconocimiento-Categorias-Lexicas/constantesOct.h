
#define MAX_TAM_IDENTIFIER 50

typedef struct DataConstOct{
    char constante[MAX_TAM_IDENTIFIER];
} DataConstOct;

typedef struct ConstOctNode{
    DataConstOct data;
    struct ConstOctNode* next;
} ConstOctNode;

void pushConstOct(ConstOctNode** head, char *oct);
DataConstOct newDataConstOct(char *oct);
void printConstantesOctales(ConstOctNode* node);
void deleteListaConstanteOctales(ConstOctNode** head);
