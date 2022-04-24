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
	X(ERR_PARSE,"\n")\

#define X(A,B) A,
typedef enum {ERRORS} err_t;

#undef X
#define X(A,B) B,
char* errors[]={ERRORS};

void err_throw(err_t e,...)
{
	va_list args;
	va_start(args,e);
	vprintf(errors[e],args);
	va_end(args);
	exit(1);
}

#define err_lex(col,msg) err_throw(ERR_LEX,lex.line,col,msg);
/*****************************************************************************/
/* TokenType */
/*****************************************************************************/
#define ASCII\
	X(TK_NUL,"TK_NUL",L_NOP) X(TK_SOH,"TK_SOH",L_NOP) X(TK_STX,"TK_STX",L_NOP)\
	X(TK_ETX,"TK_ETX",L_NOP) X(TK_EOT,"TK_EOT",L_NOP) X(TK_ENQ,"TK_ENQ",L_NOP)\
	X(TK_ACK,"TK_ACK",L_NOP) X(TK_BEL,"TK_BEL",L_NOP) X(TK_BS,"TK_BS",L_NOP)\
	X(TK_HT,"TK_HT",L_NOP) X(TK_LF,"TK_LF",L_NOP) X(TK_VT,"TK_VT",L_NOP)\
	X(TK_FF,"TK_FF",L_NOP) X(TK_CR,"TK_CR",L_NOP) X(TK_SO,"TK_SO",L_NOP)\
	X(TK_SI,"TK_SI",L_NOP) X(TK_DLE,"TK_DLE",L_NOP) X(TK_DC1,"TK_DC1",L_NOP)\
	X(TK_DC2,"TK_DC2",L_NOP) X(TK_DC3,"TK_DC3",L_NOP) X(TK_DC4,"TK_DC4",L_NOP)\
	X(TK_NAK,"TK_NAK",L_NOP) X(TK_SYN,"TK_SYN",L_NOP) X(TK_ETB,"TK_ETB",L_NOP)\
	X(TK_CAN,"TK_CAN",L_NOP) X(TK_EM,"TK_EM",L_NOP) X(TK_SUBST,"TK_SUBST",L_NOP)\
	X(TK_ESC,"TK_ESC",L_NOP) X(TK_FS,"TK_FS",L_NOP) X(TK_GS,"TK_GS",L_NOP)\
	X(TK_RS,"TK_RS",L_NOP) X(TK_US,"TK_US",L_NOP) X(TK_SPACE,"TK_SPACE",L_NOP)\
	X(TK_EXCL,"TK_EXCL",L_ASCII) X(TK_DQUOTE,"TK_DQUOTE",L_STR) X(TK_POUND,"TK_POUND",L_ASCII)\
	X(TK_DOLLAR,"TK_DOLLAR",L_ASCII) X(TK_PERCENT,"TK_PERCENT",L_ASCII) X(TK_AMP,"TK_AMP",L_ASCII)\
	X(TK_SQUOTE,"TK_SQUOTE",L_NOP) X(TK_LPAREN,"TK_LPAREN",L_ASCII) X(TK_RPAREN,"TK_RPAREN",L_ASCII)\
	X(TK_ASTER,"TK_ASTER",L_ASCII) X(TK_PLUS,"TK_PLUS",L_ASCII) X(TK_COMMA,"TK_COMMA",L_ASCII)\
	X(TK_MINUS,"TK_MINUS",L_ASCII) X(TK_PERIOD,"TK_PERIOD",L_ASCII) X(TK_FSLASH,"TK_FSLASH",L_ASCII)\
	X(TK_0,"TK_0",L_DIGIT) X(TK_1,"TK_1",L_DIGIT) X(TK_2,"TK_2",L_DIGIT)\
	X(TK_3,"TK_3",L_DIGIT) X(TK_4,"TK_4",L_DIGIT) X(TK_5,"TK_5",L_DIGIT)\
	X(TK_6,"TK_6",L_DIGIT) X(TK_7,"TK_7",L_DIGIT) X(TK_8,"TK_8",L_DIGIT)\
	X(TK_9,"TK_9",L_DIGIT) X(TK_COLON,"TK_COLON",L_ASCII) X(TK_SEMI,"TK_SEMI",L_ASCII)\
	X(TK_LT,"TK_LT",L_ASCII) X(TK_ASSI,"TK_ASSI",L_ASCII) X(TK_GT,"TK_GT",L_ASCII)\
	X(TK_QUESTION,"TK_QUESTION",L_NOP) X(TK_AT,"TK_AT",L_ASCII) X(TK_A,"TK_A",L_LETTER)\
	X(TK_B,"TK_B",L_LETTER) X(TK_C,"TK_C",L_LETTER) X(TK_D,"TK_D",L_LETTER)\
	X(TK_E,"TK_E",L_LETTER) X(TK_F,"TK_F",L_LETTER) X(TK_G,"TK_G",L_LETTER)\
	X(TK_H,"TK_H",L_LETTER) X(TK_I,"TK_I",L_LETTER) X(TK_J,"TK_J",L_LETTER)\
	X(TK_K,"TK_K",L_LETTER) X(TK_L,"TK_L",L_LETTER) X(TK_M,"TK_M",L_LETTER)\
	X(TK_N,"TK_N",L_LETTER) X(TK_O,"TK_O",L_LETTER) X(TK_P,"TK_P",L_LETTER)\
	X(TK_Q,"TK_Q",L_LETTER) X(TK_R,"TK_R",L_LETTER) X(TK_S,"TK_S",L_LETTER)\
	X(TK_T,"TK_T",L_LETTER) X(TK_U,"TK_U",L_LETTER) X(TK_V,"TK_V",L_LETTER)\
	X(TK_W,"TK_W",L_LETTER) X(TK_X,"TK_X",L_LETTER) X(TK_Y,"TK_Y",L_LETTER)\
	X(TK_Z,"TK_Z",L_LETTER) X(TK_LSQUARE,"TK_LSQUARE",L_ASCII) X(TK_BSLASH,"TK_BSLASH",L_NOP)\
	X(TK_RSQUARE,"TK_RSQUARE",L_ASCII) X(TK_CARAT,"TK_CARAT",L_NOP) X(TK_USCORE,"TK_USCORE",L_LETTER)\
	X(TK_GRAVE,"TK_GRAVE",L_ASCII) X(TK_a,"TK_a",L_LETTER) X(TK_b,"TK_b",L_LETTER)\
	X(TK_c,"TK_c",L_LETTER) X(TK_d,"TK_d",L_LETTER) X(TK_e,"TK_e",L_LETTER)\
	X(TK_f,"TK_f",L_LETTER) X(TK_g,"TK_g",L_LETTER) X(TK_h,"TK_h",L_LETTER)\
	X(TK_i,"TK_i",L_LETTER) X(TK_j,"TK_j",L_LETTER) X(TK_k,"TK_k",L_LETTER)\
	X(TK_l,"TK_l",L_LETTER) X(TK_m,"TK_m",L_LETTER) X(TK_n,"TK_n",L_LETTER)\
	X(TK_o,"TK_o",L_LETTER) X(TK_p,"TK_p",L_LETTER) X(TK_q,"TK_q",L_LETTER)\
	X(TK_r,"TK_r",L_LETTER) X(TK_s,"TK_s",L_LETTER) X(TK_t,"TK_t",L_LETTER)\
	X(TK_u,"TK_u",L_LETTER) X(TK_v,"TK_v",L_LETTER) X(TK_w,"TK_w",L_LETTER)\
	X(TK_x,"TK_x",L_LETTER) X(TK_y,"TK_y",L_LETTER) X(TK_z,"TK_z",L_LETTER)\
	X(TK_LCURLY,"TK_LCURLY",L_NOP) X(TK_PIPE,"TK_PIPE",L_ASCII) X(TK_RCURLY,"TK_RCURLY",L_NOP)\
	X(TK_TILDE,"TK_TILDE",L_NOP) X(TK_DEL,"TK_DEL",L_NOP)\

#define TOKEN_TYPES\
	X(TK_ID,"TK_ID",L_NOP) X(TK_NUM,"TK_NUM",L_NOP) X(TK_STR,"TK_STR",L_NOP)\
	X(TK_EOF,"TK_EOF",L_NOP)\

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

int lex_get()
{
	lex.current=fgetc(lex.stream);
	lex.column++;
	return feof(lex.stream);
}

char lex_peek()
{
	char c=fgetc(lex.stream);
	ungetc(c,lex.stream);
	return c;
}

void lex_cat()
{
	tokens
	.data[tokens.length]
	.value[tokens.data[tokens.length].length++]=lex.current;
}

inline void lex_undo()
{
	ungetc(lex.current,lex.stream);
}

int lex_cat_get()
{
	lex_cat();
	return lex_get();
}

token_p lex_push(token_type_t type)
{
	tokens.data[tokens.length].type=type;
	return &tokens.data[tokens.length++];
}

token_p lex_push_ascii()
{
	lex_cat();
	return lex_push(lex.current);
}

#define ISLBL(L) labels[lex.current]==&&L
#define NOTLBL(L) labels[lex.current]!=&&L
#define ISC(C) lex.current==C
#define NOTC(C) lex.current!=C

token_p lex_process()
{
	#undef X
	#define X(A,B,C) &&C,
	static void* labels[]={ASCII TOKEN_TYPES};
	L_LEX:
		if(lex_get()) return lex_push(TK_EOF);
		if(ISC('\n'))
		{
			if(lex.repl) return lex_push(TK_EOF);
			lex.line++;
		}
		goto *labels[lex.current];
	L_NOP:goto L_LEX;
	L_LETTER:
		lex_cat_get();
		if(ISLBL(L_LETTER)||ISLBL(L_DIGIT)) goto L_LETTER;
		lex_undo();
		return lex_push(TK_ID);
	L_DIGIT:
		while(ISLBL(L_DIGIT)) lex_cat_get();
		if(lex.current=='.')
		{
			lex_cat_get();
			if(NOTLBL(L_DIGIT)) err_lex(lex.column,"Failed To Parse Number.");
			while(ISLBL(L_DIGIT)) lex_cat_get();
		}
		lex_undo();
		return lex_push(TK_NUM);
	L_STR:
		lex_get();
		while(NOTC('\"'))
		{
			if(lex_cat_get()) err_lex(lex.column,"Unterminated String.");
		}
		lex_get();
		lex_undo();
		return lex_push(TK_STR);
	L_ASCII:return lex_push_ascii();
}
/*****************************************************************************/
/* Rx */
/*****************************************************************************/
void interpret()
{
	token_p token=0;
	do
	{
		token=lex_process();
		printf("token_t(%s,%s)\n",token_types[token->type],token->value);
	}while(token->type!=TK_EOF);
}

void main(int nargs,char** args)
{
	static void* labels[]={&&L_LOAD,&&L_REPL};
	lex.repl=nargs<2;
	goto *labels[lex.repl];
	L_LOAD:
		lex.stream=fopen(args[1],"rb");
		if(!lex.stream) err_throw(ERR_NOFILE,args[1]);
		interpret();
		goto L_EXIT;
	L_REPL:
		lex.stream=stdin;
		for(;;)
		{
			printf("> ");
			interpret();
		}
	L_EXIT:
	fclose(lex.stream);
}