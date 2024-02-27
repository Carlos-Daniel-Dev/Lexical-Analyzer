%{

%}

%%
[0-9]+              { yylval.integer = atoi(yytext); return INT; }
"+"                 { return ADD; }
"-"                 { return SUB; }
"*"                 { return MUL; }
"/"                 { return DIV; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
[ \t\n]             ; /* ignore spaces */
.                   { yyerror("Caracter not recognized"); }
%%

int yywrap() {
    return 1;
}
