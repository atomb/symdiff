/* *******************************************************************
    File name : tokens.h
    Purpose   : This is the header file for the tokenizer.c It 
                contains the type definitions to be exported from
                the tokenizer.c.
 * ******************************************************************* */

# include "stream.h"

# define TRUE  1
# define FALSE 0
# define EOTSTREAM      0
# define NUMERIC        18
# define IDENTIFIER     17
# define LAMBDA         6
# define AND            9
# define OR             11
# define IF             13
# define XOR            16
# define LPAREN         19
# define RPAREN         20
# define LSQUARE        21
# define RSQUARE        22
# define QUOTE          23
# define BQUOTE         24
# define COMMA          25
# define EQUALGREATER   32
# define STRING_CONSTANT 27
# define CHARACTER_CONSTANT 29
# define ERROR             -1

typedef struct token_stream_type {
                             character_stream ch_stream;
                          } *token_stream;

typedef struct token_type {
                                int token_id;
                                char token_string[80];
                          } *token;

token_stream open_token_stream();

token get_token();

BOOLEAN compare_token();

BOOLEAN is_eof_token();

int default1[]={
                 54, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 51, -2, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1 ,-1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
                 -1, 52, -3, -1 ,-1, -1, -1, -1, -1, -1
               };
int base[]   ={
                  -32, -96,-105, -93, -94, -87, -1,  -97, -86, -1,
                  -99, -1,  -72, -1,  -80, -82, -1,   53,  43, -1,
                  -1,  -1,  -1,  -1,  -1,  -1,  133, -1,  233, -1,
                  -1,  0,   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
                  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
                  -1,  46,  40,  -1, 251,  -1,  -1,  -1,  -1,  -1
              };
int next[] = {
                  0,  2, 26, 28,  3,  4,  5, 23, 19, 20,
                  6, -1, 25,  8,  9, 11, 18, 18, 18, 18,
                 18, 18, 18, 18, 18, 18, -1, 30, -1, 31,
                 13, 15, 16, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 21,
                 -1, 22, 32, -1, 24,  7, 17, 17, 17, 17,
                 17, 17, 17, 12, 17, 17,  1, 17, 17, 10,
                 17, 17, 17, 17, 17, 17, 17, 17, 14, 17,
                 17, 18, 18, 18, 18, 18, 18, 18, 18, 18,
                 18, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, -1, -1, 26, 26, 27, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                  0,  0, -1, -1, -1, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29
            };
int check[] = {   0,  1,  0,  0,  2,  3,  4,  0,  0,  0,
                  5, -1,  0,  7,  8, 10,  0,  0,  0,  0,
                  0,  0,  0,  0,  0,  0, -1,  0, -1,  0,
                 12, 14, 15,  0,  0,  0,  0,  0,  0,  0,
                  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                 -1,  0, 31, -1,  0,  0,  0,  0,  0,  0,
                  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                  0, 18, 18, 18, 18, 18, 18, 18, 18, 18,
                 18, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 51, 51, 51, 51, 51, 51, 51, 51, 51,
                 51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
                 51, 51, 51, 51, 51, 51, 51, 52, 52, 52,
                 52, 52, 52, 52, 52, 52, 52, 52, 52, 52,
                 52, 52, 52, 52, 52, 52, 52, 52, 52, 52,
                 52, 52, 52, -1, -1, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,  
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,  
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,  
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,  
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,  
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,  
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,  
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,  
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 54, 54, -1, -1, -1, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28
              };
  
