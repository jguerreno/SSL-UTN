
#define MAX_TAM_IDENTIFIER 50

typedef struct DataConstHex{
    char constante[MAX_TAM_IDENTIFIER];
} DataConstHex;

typedef struct ConstHexNode{
    DataConstHex data;
    struct ConstHexNode* next;
} ConstHexNode;

void pushConstHex(ConstHexNode** head, char *hex);
DataConstHex newDataConstHex(char *hex);
void printConstantesHexadecimales(ConstHexNode* node);
void deleteListaConstanteHexadecimales(ConstHexNode** head);
