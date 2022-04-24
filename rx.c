#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdarg.h>
/*****************************************************************************/
/* Error */
/*****************************************************************************/
#define ERRORS\
	X(ERR_NONE,"")\
	X(ERR_USAGE,"Usage 1:rx <src>\n Usage 2:rx\n")\
	X(ERR_NOFILE,"File Not Found: %s\n")\
	X(ERR_LEX,"Lex Error | Ln %d, Col %d | %s \n")\
	X(ERR_PARSE,"\n")
#define X(A,B) A,
typedef enum {ERRORS} err_t;
#undef X
#define X(A,B) B,
char* errors[]={ERRORS};
#define err_throw(E,...) printf(errors[E],__VA_ARGS__); exit(1);
#define err_lex(col,msg) err_throw(ERR_LEX,lex.line,col,msg)
#define err_parse(col,msg) err_throw(ERR_PARSE,"")
/*****************************************************************************/
/* TokenType */
/*****************************************************************************/
#define ASCII\
	X(TK_NUL,"TK_NUL",LEX_NOP) X(TK_SOH,"TK_SOH",LEX_NOP) X(TK_STX,"TK_STX",LEX_NOP)\
	X(TK_ETX,"TK_ETX",LEX_NOP) X(TK_EOT,"TK_EOT",LEX_NOP) X(TK_ENQ,"TK_ENQ",LEX_NOP)\
	X(TK_ACK,"TK_ACK",LEX_NOP) X(TK_BEL,"TK_BEL",LEX_NOP) X(TK_BS,"TK_BS",LEX_NOP)\
	X(TK_HT,"TK_HT",LEX_NOP) X(TK_LF,"TK_LF",LEX_NOP) X(TK_VT,"TK_VT",LEX_NOP)\
	X(TK_FF,"TK_FF",LEX_NOP) X(TK_CR,"TK_CR",LEX_NOP) X(TK_SO,"TK_SO",LEX_NOP)\
	X(TK_SI,"TK_SI",LEX_NOP) X(TK_DLE,"TK_DLE",LEX_NOP) X(TK_DC1,"TK_DC1",LEX_NOP)\
	X(TK_DC2,"TK_DC2",LEX_NOP) X(TK_DC3,"TK_DC3",LEX_NOP) X(TK_DC4,"TK_DC4",LEX_NOP)\
	X(TK_NAK,"TK_NAK",LEX_NOP) X(TK_SYN,"TK_SYN",LEX_NOP) X(TK_ETB,"TK_ETB",LEX_NOP)\
	X(TK_CAN,"TK_CAN",LEX_NOP) X(TK_EM,"TK_EM",LEX_NOP) X(TK_SUBST,"TK_SUBST",LEX_NOP)\
	X(TK_ESC,"TK_ESC",LEX_NOP) X(TK_FS,"TK_FS",LEX_NOP) X(TK_GS,"TK_GS",LEX_NOP)\
	X(TK_RS,"TK_RS",LEX_NOP) X(TK_US,"TK_US",LEX_NOP) X(TK_SPACE,"TK_SPACE",LEX_NOP)\
	X(TK_EXCL,"TK_EXCL",LEX_ASCII) X(TK_DQUOTE,"TK_DQUOTE",LEX_STR) X(TK_POUND,"TK_POUND",LEX_ASCII)\
	X(TK_DOLLAR,"TK_DOLLAR",LEX_ASCII) X(TK_PERCENT,"TK_PERCENT",LEX_ASCII) X(TK_AMP,"TK_AMP",LEX_ASCII)\
	X(TK_SQUOTE,"TK_SQUOTE",LEX_NOP) X(TK_LPAREN,"TK_LPAREN",LEX_ASCII) X(TK_RPAREN,"TK_RPAREN",LEX_ASCII)\
	X(TK_ASTER,"TK_ASTER",LEX_ASCII) X(TK_PLUS,"TK_PLUS",LEX_ASCII) X(TK_COMMA,"TK_COMMA",LEX_ASCII)\
	X(TK_MINUS,"TK_MINUS",LEX_ASCII) X(TK_PERIOD,"TK_PERIOD",LEX_ASCII) X(TK_FSLASH,"TK_FSLASH",LEX_ASCII)\
	X(TK_0,"TK_0",LEX_DIGIT) X(TK_1,"TK_1",LEX_DIGIT) X(TK_2,"TK_2",LEX_DIGIT)\
	X(TK_3,"TK_3",LEX_DIGIT) X(TK_4,"TK_4",LEX_DIGIT) X(TK_5,"TK_5",LEX_DIGIT)\
	X(TK_6,"TK_6",LEX_DIGIT) X(TK_7,"TK_7",LEX_DIGIT) X(TK_8,"TK_8",LEX_DIGIT)\
	X(TK_9,"TK_9",LEX_DIGIT) X(TK_COLON,"TK_COLON",LEX_ASCII) X(TK_SEMI,"TK_SEMI",LEX_ASCII)\
	X(TK_LT,"TK_LT",LEX_ASCII) X(TK_ASSI,"TK_ASSI",LEX_ASCII) X(TK_GT,"TK_GT",LEX_ASCII)\
	X(TK_QUESTION,"TK_QUESTION",LEX_NOP) X(TK_AT,"TK_AT",LEX_ASCII) X(TK_A,"TK_A",LEX_LETTER)\
	X(TK_B,"TK_B",LEX_LETTER) X(TK_C,"TK_C",LEX_LETTER) X(TK_D,"TK_D",LEX_LETTER)\
	X(TK_E,"TK_E",LEX_LETTER) X(TK_F,"TK_F",LEX_LETTER) X(TK_G,"TK_G",LEX_LETTER)\
	X(TK_H,"TK_H",LEX_LETTER) X(TK_I,"TK_I",LEX_LETTER) X(TK_J,"TK_J",LEX_LETTER)\
	X(TK_K,"TK_K",LEX_LETTER) X(TK_L,"TK_L",LEX_LETTER) X(TK_M,"TK_M",LEX_LETTER)\
	X(TK_N,"TK_N",LEX_LETTER) X(TK_O,"TK_O",LEX_LETTER) X(TK_P,"TK_P",LEX_LETTER)\
	X(TK_Q,"TK_Q",LEX_LETTER) X(TK_R,"TK_R",LEX_LETTER) X(TK_S,"TK_S",LEX_LETTER)\
	X(TK_T,"TK_T",LEX_LETTER) X(TK_U,"TK_U",LEX_LETTER) X(TK_V,"TK_V",LEX_LETTER)\
	X(TK_W,"TK_W",LEX_LETTER) X(TK_X,"TK_X",LEX_LETTER) X(TK_Y,"TK_Y",LEX_LETTER)\
	X(TK_Z,"TK_Z",LEX_LETTER) X(TK_LSQUARE,"TK_LSQUARE",LEX_ASCII) X(TK_BSLASH,"TK_BSLASH",LEX_NOP)\
	X(TK_RSQUARE,"TK_RSQUARE",LEX_ASCII) X(TK_CARAT,"TK_CARAT",LEX_NOP) X(TK_USCORE,"TK_USCORE",LEX_LETTER)\
	X(TK_GRAVE,"TK_GRAVE",LEX_ASCII) X(TK_a,"TK_a",LEX_LETTER) X(TK_b,"TK_b",LEX_LETTER)\
	X(TK_c,"TK_c",LEX_LETTER) X(TK_d,"TK_d",LEX_LETTER) X(TK_e,"TK_e",LEX_LETTER)\
	X(TK_f,"TK_f",LEX_LETTER) X(TK_g,"TK_g",LEX_LETTER) X(TK_h,"TK_h",LEX_LETTER)\
	X(TK_i,"TK_i",LEX_LETTER) X(TK_j,"TK_j",LEX_LETTER) X(TK_k,"TK_k",LEX_LETTER)\
	X(TK_l,"TK_l",LEX_LETTER) X(TK_m,"TK_m",LEX_LETTER) X(TK_n,"TK_n",LEX_LETTER)\
	X(TK_o,"TK_o",LEX_LETTER) X(TK_p,"TK_p",LEX_LETTER) X(TK_q,"TK_q",LEX_LETTER)\
	X(TK_r,"TK_r",LEX_LETTER) X(TK_s,"TK_s",LEX_LETTER) X(TK_t,"TK_t",LEX_LETTER)\
	X(TK_u,"TK_u",LEX_LETTER) X(TK_v,"TK_v",LEX_LETTER) X(TK_w,"TK_w",LEX_LETTER)\
	X(TK_x,"TK_x",LEX_LETTER) X(TK_y,"TK_y",LEX_LETTER) X(TK_z,"TK_z",LEX_LETTER)\
	X(TK_LCURLY,"TK_LCURLY",LEX_NOP) X(TK_PIPE,"TK_PIPE",LEX_ASCII) X(TK_RCURLY,"TK_RCURLY",LEX_NOP)\
	X(TK_TILDE,"TK_TILDE",LEX_NOP) X(TK_DEL,"TK_DEL",LEX_NOP)
#define TOKEN_TYPES\
	X(TK_ID,"TK_ID",LEX_NOP) X(TK_NUM,"TK_NUM",LEX_NOP) X(TK_STR,"TK_STR",LEX_NOP)\
	X(TK_EOF,"TK_EOF",LEX_NOP)
#undef X
#define X(A,B,C) A,
typedef enum{ASCII TOKEN_TYPES}token_type_t;
#undef X
#define X(A,B,C) B,
char* token_types[]={ASCII TOKEN_TYPES};
/*****************************************************************************/
/* Token */
/*****************************************************************************/
typedef struct
{
	token_type_t type;
	int length;
	char value[128];
}token_t,*token_p;
struct
{
	int length;
	token_t data[1024];
}tokens={0};
/*****************************************************************************/
/* Lexer */
/*****************************************************************************/
struct
{
	int line;
	int column;
	char current;
	char repl;
	FILE* stream;
}lex={0,.line=1};
#define LEX_GET()({lex.current=fgetc(lex.stream); lex.column++; feof(lex.stream);})
#define LEX_PEEK()({char c=fgetc(lex.stream); ungetc(c); c;})
#define LEX_CAT()({tokens.data[tokens.length].value[tokens.data[tokens.length].length++]=lex.current;})
#define LEX_UNDO()({ungetc(lex.current,lex.stream);})
#define LEX_CAT_GET()({LEX_CAT(); LEX_GET();})
#define LEX_PUSH(TYPE)({tokens.data[tokens.length].type=TYPE; &tokens.data[tokens.length++];})
#define LEX_PUSH_ASCII()({LEX_CAT(); LEX_PUSH(lex.current);})
#define ISLBL(L) l1[lex.current]==&&L
#define NOTLBL(L) l1[lex.current]!=&&L
#define ISC(C) lex.current==C
#define NOTC(C) lex.current!=C
#define _LEX_LEX_\
	LEX_LEX:\
		if(LEX_GET()) return LEX_PUSH(TK_EOF);\
		if(ISC('\n'))\
		{\
			if(lex.repl) return LEX_PUSH(TK_EOF);\
			lex.line++;\
		}\
		goto *l1[lex.current];
#define _LEX_NOP_\
	LEX_NOP:\
		goto LEX_LEX;
#define _LEX_ID_\
	LEX_LETTER:\
		LEX_CAT_GET();\
		if(ISLBL(LEX_LETTER)||ISLBL(LEX_DIGIT)) goto LEX_LETTER;\
		LEX_UNDO();\
		return LEX_PUSH(TK_ID);
#define _LEX_NUMBER_\
	LEX_DIGIT:\
		while(ISLBL(LEX_DIGIT)) LEX_CAT_GET();\
		if(lex.current=='.')\
		{\
			LEX_CAT_GET();\
			if(NOTLBL(LEX_DIGIT)) exit(1);\
			while(ISLBL(LEX_DIGIT)) LEX_CAT_GET();\
		}\
		LEX_UNDO();\
		return LEX_PUSH(TK_NUM);
#define _LEX_STR_\
	LEX_STR:\
		LEX_GET();\
		while(NOTC('\"'))\
		{\
			if(LEX_CAT_GET()) exit(1);\
		}\
		LEX_GET();\
		LEX_UNDO();\
		return LEX_PUSH(TK_STR);
#define _LEX_ASCII_\
	LEX_ASCII:\
		return LEX_PUSH_ASCII();

token_p lex_lex()
{
	#undef X
	#define X(A,B,C) &&C,
	static void* l1[]={ASCII TOKEN_TYPES};
	_LEX_LEX_\
	_LEX_NOP_\
	_LEX_ID_\
	_LEX_NUMBER_\
	_LEX_STR_\
	_LEX_ASCII_\
}
/*****************************************************************************/
/* I don't have an answer either. */
/*****************************************************************************/
#define _RX_LOAD_\
	RX_LOAD:\
		lex.stream=fopen(args[1],"rb");\
		goto *l2[lex.stream==0];
#define _RX_NOFILE_\
	RX_NOFILE:\
		err_throw(ERR_NOFILE,args[1]);
#define _RX_REPL_\
	RX_REPL:\
		lex.stream=stdin;\
		printf("> ");
#define _RX_INTERPRET_\
	RX_INTERPRET:\
		token_p token=0;\
		do\
		{\
			token=lex_lex();\
			printf("token_t(%s,%s)\n",token_types[token->type],token->value);\
		}while(token->type!=TK_EOF);\
		goto *l3[lex.repl];
#define _RX_EXIT_\
	RX_EXIT:\
		fclose(lex.stream);
void main(int nargs,char** args)
{
	static void* l1[]={&&RX_LOAD,&&RX_REPL};
	static void* l2[]={&&RX_INTERPRET,&&RX_NOFILE};
	static void* l3[]={&&RX_EXIT,&&RX_REPL};
	lex.repl=nargs<2;
	goto *l1[lex.repl];
	_RX_LOAD_
	_RX_NOFILE_
	_RX_REPL_
	_RX_INTERPRET_
	_RX_EXIT_
}