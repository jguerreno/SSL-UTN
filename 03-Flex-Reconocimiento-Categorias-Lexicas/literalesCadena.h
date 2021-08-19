
#define MAX_TAM_IDENTIFIER 50



typedef struct DataLiteralCadena{
    char cadenaLiteral[MAX_TAM_IDENTIFIER];
    int repeticion;
} DataLiteralCadena;

typedef struct LiteralCadenaNode{
    DataLiteralCadena data;
    struct LiteralCadenaNode* next;
} LiteralCadenaNode;



void addLiteralCadena(LiteralCadenaNode** head, char cadenaLiteral[]);
void pushLiteralCadena(LiteralCadenaNode** head, char cadenaLiteral[]);
DataLiteralCadena newDataLiteralCadena(char cadenaLiteral[]);
LiteralCadenaNode* searchLiteralCadena(LiteralCadenaNode* head, char cadenaLiteral[]);
void sortLiteralCadena(LiteralCadenaNode** head);
void printListLiteralCadena(LiteralCadenaNode* node);
void deleteListLiteralCadena(LiteralCadenaNode** head);

