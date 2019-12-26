grammar Mikro;

variable  : VAR NAME EQUALS NUMBER ;

// KEYWORDS

VAR : 'var';

// SYMBOLS

EQUALS : '=';

NAME : [a-zA-Z][a-zA-Z0-9]* ;

fragment DIGIT : [0-9] ;
NUMBER         : DIGIT+ ([.,] DIGIT+)? ;
WHITESPACE : [ \t\u000C\r\n]+ -> skip;