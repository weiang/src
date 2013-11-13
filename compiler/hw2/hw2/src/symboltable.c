#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include"header.h"

#define TABLE_SIZE	256
#define MAX_ID_NUMBER	1000

symtab * hash_table[TABLE_SIZE];
extern int linenumber;

int HASH(char * str){
	int idx=0;
	while(*str){
		idx = idx << 1;
		idx+=*str;
		str++;
	}	
	return (idx & (TABLE_SIZE-1));
}

/*returns the symbol table entry if found else NULL*/

symtab * lookup(char *name){
	int hash_key;
	symtab* symptr;
	if(!name)
		return NULL;
	hash_key=HASH(name);
	symptr=hash_table[hash_key];

	while(symptr){
		if(!(strcmp(name,symptr->lexeme)))
			return symptr;
		symptr=symptr->back;
	}
	return NULL;
}


void insertID(char *name){
	int hash_key;
	symtab* ptr;
	symtab* symptr=(symtab*)malloc(sizeof(symtab));	
	
	hash_key=HASH(name);
	ptr=hash_table[hash_key];
	
	if(ptr==NULL){
		/*first entry for this hash_key*/
		hash_table[hash_key]=symptr;
//		symptr->front=NULL;
		symptr->back=NULL;
	}
	else{
		symptr -> back = ptr;
//		ptr->back=symptr;
//		symptr->back=symptr;
		hash_table[hash_key]=symptr;	
	}
	
	strcpy(symptr->lexeme,name);
	symptr->line=linenumber;
	symptr->counter=1;
}

void printSym(symtab* ptr) 
{
	    printf(" Name = %s \n", ptr->lexeme);
	    printf(" References = %d \n", ptr->counter);
}

int compare(const symtab *a, const symtab *b)
{
	return strcmp(a -> lexeme, b -> lexeme);
}

void printSymTab()
{
    symtab syms[MAX_ID_NUMBER];
    int i;
	int id_index = 0;
	symtab *symptr;
	for (i = 0; i < TABLE_SIZE; i++)
    {
		symptr = hash_table[i];
		while (symptr != NULL) {
			strcpy(syms[id_index].lexeme, symptr -> lexeme);
			syms[id_index].counter = symptr -> counter;
	//		printf("%s\n", syms[id_index].lexeme);
			id_index ++;
			symptr = symptr->back;
		}
    }
	qsort(syms, id_index, sizeof(*syms), (int(*)(const void *, const void *))compare);
	printf("Frequency of identifiers:\n");
	for (i = 0; i < id_index; i ++)
		printf("%-10s %d\n", syms[i].lexeme, syms[i].counter);

}
