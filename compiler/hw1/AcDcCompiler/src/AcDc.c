#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"


int main( int argc, char *argv[] )
{
	int i;
    FILE *source, *target;
    Program program;
    SymbolTable symtab;
	Statement  stmt;

    if( argc == 3){
        source = fopen(argv[1], "r");
        target = fopen(argv[2], "w");
        if( !source ){
            printf("can't open the source file\n");
            exit(2);
        }
        else if( !target ){
            printf("can't open the target file\n");
            exit(2);
        }
        else{
            program = parser(source);
            fclose(source);
            symtab = build(program);
/*			
 			printf("Bulid symtab:\n");
			for (i = 0; i != 26; i ++) {
				if (symtab.entry[i].type != Notype) 
					printf("%s\n", symtab.entry[i].name);
			}
							
			printf("symtab : = %p\n", &symtab);
*/
			check(&program, &symtab);
            gencode(program, target, &symtab);
		}
	}
    else{
        printf("Usage: %s source_file target_file\n", argv[0]);
    }


    return 0;
}

/* Traver through AST to recover source program */
void print_code(Program *program)
{
		Statements *stmts;
		Statement stmt;
		stmts = program -> statements;
        while(stmts != NULL){
			stmt = stmts->first;
			if(stmt.type == Print){
				printf("p %s ", stmt.stmt.variable);
			}
			if(stmt.type == Assignment){
				printf("%s = ", stmt.stmt.assign.id);
				print_expr(stmt.stmt.assign.expr);
			}
			stmts = stmts->rest;
		 }
}

/********************************************* 
  Scanning 
 *********************************************/
Token getNumericToken( FILE *source, char c )
{
    Token token;
    int i = 0;

    while( isdigit(c) ) {
        token.tok[i++] = c;
        c = fgetc(source);
    }

    if( c != '.' ){
        ungetc(c, source);
        token.tok[i] = '\0';
        token.type = IntValue;
        return token;
    }

    token.tok[i++] = '.';

    c = fgetc(source);
    if( !isdigit(c) ){
        ungetc(c, source);
        printf("Expect a digit : %c\n", c);
        exit(1);
    }

    while( isdigit(c) ){
        token.tok[i++] = c;
        c = fgetc(source);
    }

    ungetc(c, source);
    token.tok[i] = '\0';
    token.type = FloatValue;
    return token;
}

Token scanner( FILE *source )
{
	int i;
    char c;
    Token token;

    while( !feof(source) ){
        c = fgetc(source);

        while( isspace(c) ) c = fgetc(source);

        if( isdigit(c) )
            return getNumericToken(source, c);

        token.tok[0] = c;	/* Modify here to get variable length identifier */
		token.tok[1] = '\0';
		switch(c){
            case '=':
                token.type = AssignmentOp;
                return token;
            case '+':
                token.type = PlusOp;
                return token;
            case '-':
                token.type = MinusOp;
                return token;
            case '*':
                token.type = MulOp;
                return token;
            case '/':
                token.type = DivOp;
                return token;
            case EOF:
                token.type = EOFsymbol;
                token.tok[0] = '\0';
                return token;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				for (i = 1; ; i ++) {
					c = fgetc(source);
					if (c != ' ' && c != '\n')
						token.tok[i] = c;
					else 
						break;
				}
				token.tok[i] = '\0';
				if(strcmp("f", token.tok) == 0)	// float delcartion
					token.type = FloatDeclaration;
				else if(strcmp("i", token.tok) == 0)	// integer del
					token.type = IntegerDeclaration;
				else if(strcmp("p", token.tok) == 0)	// print statement
					token.type = PrintOp;
				else 
					token.type = Alphabet;
		//		printf("Read token : %s \n", token.tok);
				return token;

            default:
                printf("Invalid character : %c\n", c);
                exit(1);
        }
	}
    token.tok[0] = '\0';
    token.type = EOFsymbol;
    return token;
}


/********************************************************
  Parsing
 *********************************************************/
Declaration parseDeclaration( FILE *source, Token token )
{
    Token token2;
    switch(token.type){
        case FloatDeclaration:
        case IntegerDeclaration:
            token2 = scanner(source);
            if (strcmp(token2.tok, "f") == 0 ||
                    strcmp(token2.tok, "i") == 0 ||
                    strcmp(token2.tok, "p") == 0) {
                printf("Syntax Error: %s cannot be used as id\n", token2.tok);
                exit(1);
            }
            return makeDeclarationNode( token, token2 );
        default:
            printf("Syntax Error: Expect Declaration %s\n", token.tok);
            exit(1);
    }
}

Declarations *parseDeclarations( FILE *source )
{
	int i = 0;
    Token token = scanner(source);
    Declaration decl;
    Declarations *decls;
    switch(token.type){
        case FloatDeclaration:
        case IntegerDeclaration:
            decl = parseDeclaration(source, token);
            decls = parseDeclarations(source);
            return makeDeclarationTree( decl, decls );
        case PrintOp:
			ungetc(' ', source);
			ungetc(token.tok[0], source);
			return NULL;
        case Alphabet:	// Here need some changes
			ungetc(' ', source);
			for (i = strlen(token.tok) - 1; i >= 0; i --)
				ungetc(token.tok[i], source);
            return NULL;
        case EOFsymbol:
            return NULL;
        default:
            printf("Syntax Error: Expect declarations %s\n", token.tok);
            exit(1);
    }
}

Expression *parseValue( FILE *source )
{
    Token token = scanner(source);
    Expression *value = (Expression *)malloc( sizeof(Expression) );
    value->leftOperand = value->rightOperand = NULL;

    switch(token.type){
        case Alphabet:
            (value->v).type = Identifier;
	//		(value->v).val.id = token.tok[0];	// Here needs some changes
			strcpy((value -> v).val.id, token.tok);
			(value -> v).val.id[strlen(token.tok)] = '\0';
            break;
        case IntValue:
            (value->v).type = IntConst;
            (value->v).val.ivalue = atoi(token.tok);
            break;
        case FloatValue:
            (value->v).type = FloatConst;
            (value->v).val.fvalue = atof(token.tok);
            break;
        default:
            printf("Syntax Error: Expect Identifier or a Number %s\n", token.tok);
            exit(1);
    }

    return value;
}

Expression *parseExpression( FILE *source, Expression *lvalue )
{
	int i;
    Token token = scanner(source);
    Expression *expr;
	Expression *tmp;

    switch(token.type){
        case PlusOp:
            expr = (Expression *)malloc( sizeof(Expression) );
            (expr->v).type = PlusNode;
            (expr->v).val.op = Plus;
            expr->leftOperand = lvalue;
			tmp = parseValue(source);
            expr->rightOperand = parseTerm(source, tmp);
            return parseExpression(source, expr);
        case MinusOp:
            expr = (Expression *)malloc( sizeof(Expression) );
            (expr->v).type = MinusNode;
            (expr->v).val.op = Minus;
            expr->leftOperand = lvalue;
			tmp = parseValue(source);
            expr->rightOperand = parseTerm(source, tmp);
            return parseExpression(source, expr);	// Multiple and Divise operations should be added here
			
		case Alphabet:	// Changes needed here
        case PrintOp:
			ungetc(' ' , source);
			for (i = strlen(token.tok) - 1; i >= 0; i --)
				ungetc(token.tok[i], source);
            return lvalue;
        case EOFsymbol:
            return lvalue;
        default:
            printf("Syntax Error: Expect a numeric value or an identifier %s\n", token.tok);
            exit(1);
    }
}

/*
Expression *parseExpression( FILE *source, Expression *lvalue )
{
	int i;
    Token token = scanner(source);
    Expression *expr;

    switch(token.type){
        case PlusOp:
            expr = (Expression *)malloc( sizeof(Expression) );
            (expr->v).type = PlusNode;
            (expr->v).val.op = Plus;
            expr->leftOperand = lvalue;
            expr->rightOperand = parseValue(source);
            return parseExpressionTail(source, expr);
        case MinusOp:
            expr = (Expression *)malloc( sizeof(Expression) );
            (expr->v).type = MinusNode;
            (expr->v).val.op = Minus;
            expr->leftOperand = lvalue;
            expr->rightOperand = parseValue(source);
            return parseExpressionTail(source, expr);
		case MulOp:
			expr = (Expression *)malloc(sizeof(Expression));
			(expr -> v).type = MulNode;
			(expr -> v).val.op = Mul;
			expr -> leftOperand = lvalue;
			expr -> rightOperand = parseValue(source);
			return parseExpressionTail(source, expr);
		case DivOp:
			expr = (Expression *)malloc(sizeof(Expression));
			(expr -> v).type = DivNode;
			(expr -> v).val.op = Div;
			expr -> leftOperand = parseValue(source);
			return parseExpressionTail(source, expr);
		case PlusOp:
		case MinusOp:
			return parseExpression
		case Alphabet:		// Changes needed here
        case PrintOp:
			ungetc(' ', source);
			for (i = strlen(token.tok) - 1; i >= 0; i --)
				ungetc(token.tok[i], source);
            return NULL;

        case EOFsymbol:
            return NULL;
        default:
            printf("Syntax Error: Expect a numeric value or an identifier %s\n", token.tok);
            exit(1);
    }
}
*/

/*
Expression *parseTermTail(FILE * source, Expression *lvalue)
{
	int i;
	Token token;
	Expression *expr;

	token = scanner(source);
	switch(token.type) {
		case MulOp:
			expr = (Expression *)malloc(sizeof(Expression));
			(expr -> v).type = MulNode;
			(expr -> v).val.op = Mul;
			expr -> leftOperand = lvalue;
			expr -> rightOperand = parseValue(source);
			return parseTermTail(source, expr);

		case DivOp:
			expr = (Expression *)malloc(sizeof(Expression));
			(expr -> v).type = DivNode;
			(expr -> v).val.op = Div;
			expr -> leftOperand = lvalue;
			expr -> rightOperand = parseValue(source);
			return parseTermTail(source, expr);
		
		case PlusOp:
		case MinusOp:
			return parseExpression(source, lvalue);
		
		case Alphabet:
		case PrintOp:
			ungetc(' ', source);
			for (i = strlen(token.tok) - 1; i >= 0; i --)
				ungetc(token.tok[i], source);
			return lvalue;

		case EOFsymbol:
			return lvalue;
			
		default:
            printf("Syntax Error: Expect a numeric value or an identifier %s\n", token.tok);
			exit(1);
	}
}
*/
Expression *parseTerm(FILE *source, Expression *lvalue)
{
	int i;
	Token token;
	Expression *expr;

	token = scanner(source);
	switch(token.type) {
		case MulOp:
			expr = (Expression *)malloc(sizeof(Expression));
			(expr -> v).type = MulNode;
			(expr -> v).val.op = Mul;
			expr -> leftOperand = lvalue;
			expr -> rightOperand = parseValue(source);
			return parseTerm(source, expr);

		case DivOp:
			expr = (Expression *)malloc(sizeof(Expression));
			(expr -> v).type = DivNode;
			(expr -> v).val.op = Div;
			expr -> leftOperand = lvalue;
			expr -> rightOperand = parseValue(source);
			return parseTerm(source, expr);
		
		case PlusOp:
		case MinusOp:
		case Alphabet:
		case PrintOp:
			ungetc(' ', source);
			for (i = strlen(token.tok) - 1; i >= 0; i --)
				ungetc(token.tok[i], source);
			return lvalue;

		case EOFsymbol:
			return lvalue;
			
		default:
            printf("Syntax Error: Expect a numeric value or an identifier %s\n", token.tok);
			exit(1);
	}
}

Statement parseStatement( FILE *source, Token token )
{
    Token next_token;
    Expression *value, *expr, *term;

    switch(token.type){
        case Alphabet:
            next_token = scanner(source);
            if(next_token.type == AssignmentOp){
                value = parseValue(source);
				term = parseTerm(source, value);
				expr = parseExpression(source, term);
//                return makeAssignmentNode(token.tok[0], value, expr);	// token.tok[0] here need to be changed
				return makeAssignmentNode(token.tok, term, expr);	
			}
            else{
                printf("Syntax Error: Expect an assignment op %s\n", next_token.tok);
                exit(1);
            }
        case PrintOp:
            next_token = scanner(source);
            if(next_token.type == Alphabet)
//                return makePrintNode(next_token.tok[0]);		// next_token.tok[0] here need to be changed
				return makePrintNode(next_token.tok);
			else{
                printf("Syntax Error: Expect an identifier %s\n", next_token.tok);
                exit(1);
            }
            break;
        default:
            printf("Syntax Error: Expect a statement %s\n", token.tok);
            exit(1);
    }
}

Statements *parseStatements( FILE * source )
{

    Token token = scanner(source);
    Statement stmt;
    Statements *stmts;

    switch(token.type){
        case Alphabet:
        case PrintOp:
            stmt = parseStatement(source, token);
            stmts = parseStatements(source);
            return makeStatementTree(stmt , stmts);
        case EOFsymbol:
            return NULL;
        default:
            printf("Syntax Error: Expect statements %s\n", token.tok);
            exit(1);
    }
}


/*********************************************************************
  Build AST
 **********************************************************************/
Declaration makeDeclarationNode( Token declare_type, Token identifier )
{
    Declaration tree_node;

    switch(declare_type.type){
        case FloatDeclaration:
            tree_node.type = Float;
            break;
        case IntegerDeclaration:
            tree_node.type = Int;
            break;
        default:
            break;
    }
//    tree_node.name = identifier.tok[0];	// Changes !!!
	strcpy(tree_node.name, identifier.tok);

    return tree_node;
}

Declarations *makeDeclarationTree( Declaration decl, Declarations *decls )
{
    Declarations *new_tree = (Declarations *)malloc( sizeof(Declarations) );
    new_tree->first = decl;
    new_tree->rest = decls;

    return new_tree;
}


// Statement makeAssignmentNode( char id, Expression *v, Expression *expr_tail )	// Changes!!!
Statement makeAssignmentNode(char *id, Expression *v, Expression *expr_tail)
{
    Statement stmt;
    AssignmentStatement assign;

    stmt.type = Assignment;

//	assign.id = id;	// Changes!!!
	strcpy(assign.id, id);

	if(expr_tail == NULL)
        assign.expr = v;
    else
        assign.expr = expr_tail;
    stmt.stmt.assign = assign;

    return stmt;
}

// Statement makePrintNode( char id )
Statement makePrintNode(char *id)
{
    Statement stmt;
    stmt.type = Print;
//    stmt.stmt.variable = id;	// Changes!!!
	strcpy(stmt.stmt.variable, id);
    return stmt;
}

Statements *makeStatementTree( Statement stmt, Statements *stmts )
{
    Statements *new_tree = (Statements *)malloc( sizeof(Statements) );
    new_tree->first = stmt;
    new_tree->rest = stmts;

    return new_tree;
}

/* parser */
Program parser( FILE *source )
{
    Program program;

    program.declarations = parseDeclarations(source);
    program.statements = parseStatements(source);

    return program;
}


/********************************************************
  Build symbol table
 *********************************************************/
void InitializeTable( SymbolTable *table )
{
    int i;

    for(i = 0 ; i < 26; i++)
   //     table->table[i] = Notype;
		table -> entry[i].type = Notype;
}

/*
void add_table( SymbolTable *table, char c, DataType t )
{
    int index = (int)(c - 'a');

    if(table->table[index] != Notype)
        printf("Error : id %c has been declared\n", c);//error
    table->table[index] = t;
}
*/
void add_table(SymbolTable *table, char *c, DataType t)
{
//	printf("In add_table\n");
	int i = 0; 
	for (; i != 26; i ++) {
		if (table -> entry[i].type != Notype) 
			if (strcmp(table -> entry[i].name, c) == 0) {
				printf("Error : id %s has been declared\n", c);
				exit(1);
			}
			else 
				continue;
		table -> entry[i].type = t;
		strcpy(table -> entry[i].name, c);
//		printf("string: %s has been added!\n", c);
		break;
	}
}

SymbolTable build( Program program )
{
    SymbolTable table;
    Declarations *decls = program.declarations;
    Declaration current;

    InitializeTable(&table);

    while(decls != NULL){
        current = decls->first;
        add_table(&table, current.name, current.type);
        decls = decls->rest;
    }
    return table;
}


/********************************************************************
  Type checking
 *********************************************************************/

void convertType( Expression * old, DataType type )
{
    if(old->type == Float && type == Int){
        printf("error : can't convert float to integer\n");
        return;
    }
    if(old->type == Int && type == Float){
        Expression *tmp = (Expression *)malloc( sizeof(Expression) );
        if(old->v.type == Identifier)
 //           printf("convert to float %c \n",old->v.val.id);
			printf("convert to float %s \n", old -> v.val.id);
		else
            printf("convert to float %d \n", old->v.val.ivalue);
        tmp->v = old->v;
        tmp->leftOperand = old->leftOperand;
        tmp->rightOperand = old->rightOperand;
        tmp->type = old->type;	// Using old node as the integer to float conversion node

        Value v;
        v.type = IntToFloatConvertNode;
        v.val.op = IntToFloatConvert;
        old->v = v;
        old->type = Int;
        old->leftOperand = tmp;
        old->rightOperand = NULL;
    }
}

DataType generalize( Expression *left, Expression *right )
{
    if(left->type == Float || right->type == Float){
        printf("generalize : float\n");
        return Float;
    }
    printf("generalize : int\n");
    return Int;
}

/*
DataType lookup_table( SymbolTable *table, char c )
{
    int id = c-'a';
    if( table->table[id] != Int && table->table[id] != Float)
        printf("Error : identifier %c is not declared\n", c);//error
    return table->table[id];
}
*/
DataType lookup_table(SymbolTable *table, char *c)
{
//	printf("table = %p\n", table);
	int i = 0;
	for (; i != 26; i ++) {
		if (table -> entry[i].type != Notype) {
			if (strcmp(table -> entry[i].name, c) == 0)
				return table -> entry[i].type;
		}
	}
	printf("Error : identifier %s is not declared\n", c);
	exit(1);
}


void checkexpression( Expression * expr, SymbolTable * table )
{
//	printf("In checkexpression: symtab = %p\n", table);
//    char c;
	char *c;
	if(expr->leftOperand == NULL && expr->rightOperand == NULL){
        switch(expr->v.type){
            case Identifier:
             //   c = expr->v.val.id;
				printf("identifier : %s\n", expr -> v.val.id);
                expr->type = lookup_table(table, expr -> v.val.id);
                break;
            case IntConst:
                printf("constant : int\n");
                expr->type = Int;
                break;
            case FloatConst:
                printf("constant : float\n");
                expr->type = Float;
                break;
                //case PlusNode: case MinusNode: case MulNode: case DivNode:
//			case MiunsNode:
//				printf("operator: minus\n");
//				expr -> type = 
            default:
                break;
        }
    }
    else{
        Expression *left = expr->leftOperand;
        Expression *right = expr->rightOperand;

        checkexpression(left, table);
        checkexpression(right, table);

        DataType type = generalize(left, right);
        convertType(left, type);//left->type = type;//converto
        convertType(right, type);//right->type = type;//converto
        expr->type = type;
		constant_folding(expr);
    }
}

void constant_folding(Expression *expr)
{
	Expression *left, *right;
	if (expr == NULL)
		return;
	left = expr -> leftOperand;
	right = expr -> rightOperand;

	constant_folding(expr -> leftOperand);
	constant_folding(expr -> rightOperand);
	if (expr -> leftOperand && expr -> rightOperand) {
		if ((left -> v.type == right -> v.type)
				&& (left -> v.type == IntConst || left -> v.type == FloatConst)) {
			switch (expr -> v.type) {
				case PlusNode:
					if (expr -> leftOperand -> v.type == IntConst) {
						expr -> v.val.ivalue = left -> v.val.ivalue + right -> v.val.ivalue;
						expr -> v.type = IntConst;
					}
					else { 
						expr -> v.val.fvalue = left -> v.val.fvalue + right -> v.val.fvalue;
						expr -> v.type = FloatConst;
					}
					break;
				
				case MinusNode:
					if (left -> v.type == IntConst) {
						expr -> v.val.ivalue = left -> v.val.ivalue - right -> v.val.ivalue;
						expr -> v.type = IntConst;
					}
					else {
						expr -> v.val.fvalue = left -> v.val.fvalue - right -> v.val.fvalue;
						expr -> v.type = FloatConst;
					}
					break;

				case MulNode:
					if (left -> v.type == IntConst) {
						expr -> v.val.ivalue = left -> v.val.ivalue * right -> v.val.ivalue;
						expr -> v.type = IntConst;
					}
					else {
						expr -> v.val.fvalue = left -> v.val.fvalue * right -> v.val.fvalue;
						expr -> v.type = FloatConst;
					}
				break;

				case DivNode:
					if (left -> v.type == IntConst) {
						expr -> v.val.ivalue = left -> v.val.ivalue / right -> v.val.ivalue;
						expr -> v.type = IntConst;
					}
					else {
						expr -> v.val.fvalue = left -> v.val.fvalue / right -> v.val.fvalue;
						expr -> v.type = FloatConst;
					}
					break;
			}	
			if (expr -> leftOperand -> leftOperand != NULL 
						&& expr -> leftOperand -> rightOperand == NULL)	{
					free(expr -> leftOperand -> leftOperand);
					expr -> leftOperand -> leftOperand = NULL;
			}
			free(expr -> leftOperand);
			free(expr -> rightOperand);
			expr -> leftOperand = expr -> rightOperand = NULL;
		}
	}
}	

void checkstmt( Statement *stmt, SymbolTable * table )
{
//	printf("In checkstmt: symtab = %p\n", table);
    if(stmt->type == Assignment){
        AssignmentStatement assign = stmt->stmt.assign;
//        printf("assignment : %c \n",assign.id);
		printf("assignment : %s \n", assign.id);
		checkexpression(assign.expr, table);
        stmt->stmt.assign.type = lookup_table(table, assign.id);
        if (assign.expr->type == Float && stmt->stmt.assign.type == Int) {	// Type conversion checks here!
            printf("error : can't convert float to integer\n");
        }
    }
    else if (stmt->type == Print){
//        printf("print : %c \n",stmt->stmt.variable);
		printf("print : %s \n", stmt -> stmt.variable);
		lookup_table(table, stmt->stmt.variable);
    }
    else printf("error : statement error\n");//error
}

void check( Program *program, SymbolTable * table )
{
//	printf("In check: symtab = %p\n", table);
    Statements *stmts = program->statements;
    while(stmts != NULL){
        checkstmt(&stmts->first,table);	// Check every statement
        stmts = stmts->rest;
    }
}


/***********************************************************************
  Code generation
 ************************************************************************/
void fprint_op( FILE *target, ValueType op )
{
    switch(op){
        case MinusNode:
            fprintf(target,"-\n");
            break;
        case PlusNode:
            fprintf(target,"+\n");
            break;
		case MulNode:
			fprintf(target, "*\n");
			break;
		case DivNode:
			fprintf(target, "/\n");
			break;
        default:
            fprintf(target,"Error in fprintf_op ValueType = %d\n",op);
            break;
    }
}

/* 
 * Return index of table entry which contains id 
 * Return -1 if no entry contains identifier
 */
int identifier_index_in_table(char *id, SymbolTable *table)
{
	int i;
	for (i = 0; i < 26; i ++) {
		if (table -> entry[i].type != Notype
				&& strcmp(table -> entry[i].name, id) == 0)
			return i;
	}
	return -1;
}

// void fprint_expr( FILE *target, Expression *expr)
void fprint_expr(FILE *target, Expression *expr, SymbolTable *table)
{
	int i;
    if(expr->leftOperand == NULL){
        switch( (expr->v).type ){
            case Identifier:
    //            fprintf(target,"l%c\n",(expr->v).val.id);
                i = identifier_index_in_table((expr -> v).val.id, table);
				if (i == -1) {
					printf("Error : identifier %s is not defined!\n", (expr -> v).val.id);
					exit(0);
				}
				fprintf(target, "l%c\n", i + 'a');
				break;
            case IntConst:
                fprintf(target,"%d\n",(expr->v).val.ivalue);
                break;
            case FloatConst:
                fprintf(target,"%f\n", (expr->v).val.fvalue);
                break;
            default:
                fprintf(target,"Error In fprint_left_expr. (expr->v).type=%d\n",(expr->v).type);
                break;
        }
    }
    else{
        fprint_expr(target, expr->leftOperand, table);
        if(expr->rightOperand == NULL){
            fprintf(target,"5k\n");		// Int convert to Float node
        }
        else{
            //	fprint_right_expr(expr->rightOperand);
            fprint_expr(target, expr->rightOperand, table);
            fprint_op(target, (expr->v).type);
        }
    }
}

// void gencode(Program prog, FILE * target)
void gencode(Program prog, FILE *target, SymbolTable *table)
{
	int i;
    Statements *stmts = prog.statements;
    Statement stmt;

    while(stmts != NULL){
        stmt = stmts->first;
        switch(stmt.type){
            case Print:
//                fprintf(target,"l%c\n",stmt.stmt.variable);
				i = identifier_index_in_table(stmt.stmt.variable, table);
				if (i == -1) { 
					printf("Error: identifier %s is not defined!\n", stmt.stmt.variable);
					exit(0);
				}
				fprintf(target, "l%c\n", 'a' + i);
				fprintf(target,"p\n");
                break;
            case Assignment:
                fprint_expr(target, stmt.stmt.assign.expr, table);
                /*
                   if(stmt.stmt.assign.type == Int){
                   fprintf(target,"0 k\n");
                   }
                   else if(stmt.stmt.assign.type == Float){
                   fprintf(target,"5 k\n");
                   }*/
         //       fprintf(target,"s%c\n",stmt.stmt.assign.id);
				i = identifier_index_in_table(stmt.stmt.variable, table);
				if (i == 26) 
					printf("Error: identifier %s is not defined!\n", stmt.stmt.assign.id);
				fprintf(target, "s%c\n", 'a' + i);
				fprintf(target,"0 k\n");
				break;
        }
        stmts=stmts->rest;
    }

}


/***************************************
  For our debug,
  you can omit them.
 ****************************************/
void print_expr(Expression *expr)
{
    if(expr == NULL)
        return;
    else{
        print_expr(expr->leftOperand);
        switch((expr->v).type){
            case Identifier:
//                printf("%c ", (expr->v).val.id);
				printf("%s ", (expr -> v).val.id);
				break;
            case IntConst:
                printf("%d ", (expr->v).val.ivalue);
                break;
            case FloatConst:
                printf("%f ", (expr->v).val.fvalue);
                break;
            case PlusNode:
                printf("+ ");
                break;
            case MinusNode:
                printf("- ");
                break;
            case MulNode:
                printf("* ");
                break;
            case DivNode:
                printf("/ ");
                break;
            case IntToFloatConvertNode:
                printf("(float) ");
                break;
            default:
                printf("error ");
                break;
        }
        print_expr(expr->rightOperand);
    }
}

void test_parser( FILE *source )
{
    Declarations *decls;
    Statements *stmts;
    Declaration decl;
    Statement stmt;
    Program program = parser(source);

    decls = program.declarations;

    while(decls != NULL){
        decl = decls->first;
        if(decl.type == Int)
            printf("i ");
        if(decl.type == Float)
            printf("f ");
//        printf("%c ",decl.name);
		printf("%s ", decl.name);
		decls = decls->rest;
    }

    stmts = program.statements;

    while(stmts != NULL){
        stmt = stmts->first;
        if(stmt.type == Print){
//           printf("p %c ", stmt.stmt.variable);
			printf("p %s ", stmt.stmt.variable);
		}

        if(stmt.type == Assignment){
//            printf("%c = ", stmt.stmt.assign.id);
			printf("%s = ", stmt.stmt.assign.id);
			print_expr(stmt.stmt.assign.expr);
        }
        stmts = stmts->rest;
    }

}
