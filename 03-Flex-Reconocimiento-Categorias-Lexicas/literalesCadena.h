
#define MAX_TAM_IDENTIFIER 50



typedef struct Data{
    char identificador[MAX_TAM_IDENTIFIER];
    int repeticion;
} Data;

typedef struct LiteralCadenaNode{
    Data data;
    struct LiteralCadenaNode* next;
} LiteralCadenaNode;



void add(LiteralCadenaNode** head, char identificador[]);
void push(LiteralCadenaNode** head, char identificador[]);
Data newDataIdentifier(char identificador[]);
LiteralCadenaNode* search(LiteralCadenaNode* head, char identificador[]);
void sortIdentidier(LiteralCadenaNode** head);
void printList(LiteralCadenaNode* node);
void deleteList(LiteralCadenaNode** head);

void reporteLiteralCadenas(LiteralCadenaNode** head,char identificador[]);
