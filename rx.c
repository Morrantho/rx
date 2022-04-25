#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#define ERR(E,...) printf(E,__VA_ARGS__); exit(1);
#define ASCII X(TK_NUL,"TK_NUL",L_INTERPRET) X(TK_SOH,"TK_SOH",L_INTERPRET) X(TK_STX,"TK_STX",L_INTERPRET) X(TK_ETX,"TK_ETX",L_INTERPRET) X(TK_EOT,"TK_EOT",L_INTERPRET) X(TK_ENQ,"TK_ENQ",L_INTERPRET) X(TK_ACK,"TK_ACK",L_INTERPRET) X(TK_BEL,"TK_BEL",L_INTERPRET) X(TK_BS,"TK_BS",L_INTERPRET) X(TK_HT,"TK_HT",L_INTERPRET) X(TK_LF,"TK_LF",L_LF) X(TK_VT,"TK_VT",L_INTERPRET) X(TK_FF,"TK_FF",L_INTERPRET) X(TK_CR,"TK_CR",L_INTERPRET) X(TK_SO,"TK_SO",L_INTERPRET) X(TK_SI,"TK_SI",L_INTERPRET) X(TK_DLE,"TK_DLE",L_INTERPRET) X(TK_DC1,"TK_DC1",L_INTERPRET) X(TK_DC2,"TK_DC2",L_INTERPRET) X(TK_DC3,"TK_DC3",L_INTERPRET) X(TK_DC4,"TK_DC4",L_INTERPRET) X(TK_NAK,"TK_NAK",L_INTERPRET) X(TK_SYN,"TK_SYN",L_INTERPRET) X(TK_ETB,"TK_ETB",L_INTERPRET) X(TK_CAN,"TK_CAN",L_INTERPRET) X(TK_EM,"TK_EM",L_INTERPRET) X(TK_SUBST,"TK_SUBST",L_INTERPRET) X(TK_ESC,"TK_ESC",L_INTERPRET) X(TK_FS,"TK_FS",L_INTERPRET) X(TK_GS,"TK_GS",L_INTERPRET) X(TK_RS,"TK_RS",L_INTERPRET) X(TK_US,"TK_US",L_INTERPRET) X(TK_SPACE,"TK_SPACE",L_INTERPRET) X(TK_EXCL,"TK_EXCL",L_ASCII) X(TK_DQUOTE,"TK_DQUOTE",L_STR) X(TK_POUND,"TK_POUND",L_ASCII) X(TK_DOLLAR,"TK_DOLLAR",L_ASCII) X(TK_PERCENT,"TK_PERCENT",L_ASCII) X(TK_AMP,"TK_AMP",L_ASCII) X(TK_SQUOTE,"TK_SQUOTE",L_INTERPRET) X(TK_LPAREN,"TK_LPAREN",L_ASCII) X(TK_RPAREN,"TK_RPAREN",L_ASCII) X(TK_ASTER,"TK_ASTER",L_ASCII) X(TK_PLUS,"TK_PLUS",L_ASCII) X(TK_COMMA,"TK_COMMA",L_ASCII) X(TK_MINUS,"TK_MINUS",L_ASCII) X(TK_PERIOD,"TK_PERIOD",L_ASCII) X(TK_FSLASH,"TK_FSLASH",L_ASCII) X(TK_0,"TK_0",L_DIGIT) X(TK_1,"TK_1",L_DIGIT) X(TK_2,"TK_2",L_DIGIT) X(TK_3,"TK_3",L_DIGIT) X(TK_4,"TK_4",L_DIGIT) X(TK_5,"TK_5",L_DIGIT) X(TK_6,"TK_6",L_DIGIT) X(TK_7,"TK_7",L_DIGIT) X(TK_8,"TK_8",L_DIGIT) X(TK_9,"TK_9",L_DIGIT) X(TK_COLON,"TK_COLON",L_ASCII) X(TK_SEMI,"TK_SEMI",L_ASCII) X(TK_LT,"TK_LT",L_ASCII) X(TK_ASSI,"TK_ASSI",L_ASCII) X(TK_GT,"TK_GT",L_ASCII) X(TK_QUESTION,"TK_QUESTION",L_INTERPRET) X(TK_AT,"TK_AT",L_ASCII) X(TK_A,"TK_A",L_LETTER) X(TK_B,"TK_B",L_LETTER) X(TK_C,"TK_C",L_LETTER) X(TK_D,"TK_D",L_LETTER) X(TK_E,"TK_E",L_LETTER) X(TK_F,"TK_F",L_LETTER) X(TK_G,"TK_G",L_LETTER) X(TK_H,"TK_H",L_LETTER) X(TK_I,"TK_I",L_LETTER) X(TK_J,"TK_J",L_LETTER) X(TK_K,"TK_K",L_LETTER) X(TK_L,"TK_L",L_LETTER) X(TK_M,"TK_M",L_LETTER) X(TK_N,"TK_N",L_LETTER) X(TK_O,"TK_O",L_LETTER) X(TK_P,"TK_P",L_LETTER) X(TK_Q,"TK_Q",L_LETTER) X(TK_R,"TK_R",L_LETTER) X(TK_S,"TK_S",L_LETTER) X(TK_T,"TK_T",L_LETTER) X(TK_U,"TK_U",L_LETTER) X(TK_V,"TK_V",L_LETTER) X(TK_W,"TK_W",L_LETTER) X(TK_X,"TK_X",L_LETTER) X(TK_Y,"TK_Y",L_LETTER) X(TK_Z,"TK_Z",L_LETTER) X(TK_LSQUARE,"TK_LSQUARE",L_ASCII) X(TK_BSLASH,"TK_BSLASH",L_INTERPRET) X(TK_RSQUARE,"TK_RSQUARE",L_ASCII) X(TK_CARAT,"TK_CARAT",L_INTERPRET) X(TK_USCORE,"TK_USCORE",L_LETTER) X(TK_GRAVE,"TK_GRAVE",L_ASCII) X(TK_a,"TK_a",L_LETTER) X(TK_b,"TK_b",L_LETTER) X(TK_c,"TK_c",L_LETTER) X(TK_d,"TK_d",L_LETTER) X(TK_e,"TK_e",L_LETTER) X(TK_f,"TK_f",L_LETTER) X(TK_g,"TK_g",L_LETTER) X(TK_h,"TK_h",L_LETTER) X(TK_i,"TK_i",L_LETTER) X(TK_j,"TK_j",L_LETTER) X(TK_k,"TK_k",L_LETTER) X(TK_l,"TK_l",L_LETTER) X(TK_m,"TK_m",L_LETTER) X(TK_n,"TK_n",L_LETTER) X(TK_o,"TK_o",L_LETTER) X(TK_p,"TK_p",L_LETTER) X(TK_q,"TK_q",L_LETTER) X(TK_r,"TK_r",L_LETTER) X(TK_s,"TK_s",L_LETTER) X(TK_t,"TK_t",L_LETTER) X(TK_u,"TK_u",L_LETTER) X(TK_v,"TK_v",L_LETTER) X(TK_w,"TK_w",L_LETTER) X(TK_x,"TK_x",L_LETTER) X(TK_y,"TK_y",L_LETTER) X(TK_z,"TK_z",L_LETTER) X(TK_LCURLY,"TK_LCURLY",L_INTERPRET) X(TK_PIPE,"TK_PIPE",L_ASCII) X(TK_RCURLY,"TK_RCURLY",L_INTERPRET) X(TK_TILDE,"TK_TILDE",L_INTERPRET) X(TK_DEL,"TK_DEL",L_INTERPRET)
#define TOKEN_TYPES X(TK_ID,"TK_ID",L_INTERPRET) X(TK_NUM,"TK_NUM",L_INTERPRET) X(TK_STR,"TK_STR",L_INTERPRET)
#undef X
#define X(A,B,C) A,
typedef enum{ASCII TOKEN_TYPES}token_type_t;
#undef X
#define X(A,B,C) B,
char* token_types[]={ASCII TOKEN_TYPES};
typedef struct{token_type_t type;int length;char value[128];}token_t,*token_p;
struct{int length;token_t data[1024];}tokens={0};
struct{int line;int column;char current;char repl;FILE* stream;}lex={0,.line=1};
#define LEX_GET()({lex.current=fgetc(lex.stream); lex.column++; feof(lex.stream)==0;})
#define LEX_PEEK()({char c=fgetc(lex.stream); ungetc(c); c;})
#define LEX_CAT()({tokens.data[tokens.length].value[tokens.data[tokens.length].length++]=lex.current;})
#define LEX_UNDO()({ungetc(lex.current,lex.stream);})
#define LEX_CAT_GET()({LEX_CAT(); LEX_GET();})
#define LEX_PUSH(TYPE)({tokens.data[tokens.length++].type=TYPE;})
#define LEX_PUSH_ASCII()({LEX_CAT(); LEX_PUSH(lex.current);})
#define LEX_TK()({tokens.data[tokens.length-1];})
#define LEX_LADDR()({lex_ops[lex.current];})
void main(int nargs,char** args)
{
	static void* load_or_repl[]={&&L_LOAD,&&L_REPL};
	static void* interpret_or_nofile[]={&&L_INTERPRET,&&L_NOFILE};
	static void* quit_or_lex[]={&&L_QUIT,&&L_LEX};
	static void* interpret_or_repl[]={&&L_INTERPRET,&&L_REPL};
	static void* letter_or_letter_a[]={&&L_LETTER_A,&&L_LETTER};
	static void* letter_b_or_letter[]={&&L_LETTER_B,&&L_LETTER};
	static void* digit_a_or_digit[]={&&L_DIGIT_A,&&L_DIGIT};
	static void* digit_e_or_b[]={&&L_DIGIT_E,&&L_DIGIT_B};
	static void* digit_d_or_c[]={&&L_DIGIT_D,&&L_DIGIT_C};
	static void* digit_e_or_c[]={&&L_DIGIT_E,&&L_DIGIT_C};
	#undef X
	#define X(A,B,C) &&C,
	static void* lex_ops[]={ASCII TOKEN_TYPES};
	lex.repl=nargs<2;
	goto *load_or_repl[lex.repl];
L_LOAD:
	lex.stream=fopen(args[1],"rb");
	goto *interpret_or_nofile[lex.stream==0];
L_NOFILE:
	ERR("File Not Found: %s\n",args[1])
L_REPL:
	lex.stream=stdin;
	printf("> ");
L_INTERPRET:
	goto *quit_or_lex[LEX_GET()];
L_LEX:
	goto *lex_ops[lex.current];
L_LF:
	lex.line++;
	lex.column=0;
	goto *interpret_or_repl[lex.repl];
L_LETTER:
	LEX_CAT_GET();
	goto *letter_or_letter_a[lex_ops[lex.current]==&&L_LETTER];
L_LETTER_A:
	goto *letter_b_or_letter[lex_ops[lex.current]==&&L_DIGIT];
L_LETTER_B:
	LEX_UNDO();
	LEX_PUSH(TK_ID);
	goto L_PARSE;
L_DIGIT:
	LEX_CAT_GET();
	goto *digit_a_or_digit[lex_ops[lex.current]==&&L_DIGIT];
L_DIGIT_A:
	goto *digit_e_or_b[lex.current=='.'];
L_DIGIT_B:
	LEX_CAT_GET();
	goto *digit_d_or_c[lex_ops[lex.current]==&&L_DIGIT];
L_DIGIT_C:
	LEX_CAT_GET();
	goto *digit_e_or_c[lex_ops[lex.current]==&&L_DIGIT];
L_DIGIT_D:
	ERR("Lex Error: Failed To Parse Number %s\n","");
L_DIGIT_E:
	LEX_UNDO();
	LEX_PUSH(TK_NUM);
	goto L_PARSE;
L_STR:
	goto L_INTERPRET;
L_ASCII:
	LEX_PUSH_ASCII();
	goto L_PARSE;
L_PARSE:
	printf("token(%s,%s)\n",token_types[LEX_TK().type],LEX_TK().value);
	goto L_INTERPRET;
L_QUIT:
	fclose(lex.stream);
}