grammar Lab6;

// Define literals, keywords or operators, here as tokens.
tokens {
    PLUS = '+';
    MINUS = '-';
    MULT = '*';
    DIV = '/';
    EXPONENT = '^';
    OPENPAR = '(';
    CLOSEPAR = ')';
    LOG = 'log';
    SINE = 'sin';
    COSINE = 'cos';
    TANGENT = 'tan';
}

// Written in the target language. The header section can be
// used to import any Java classes that may be required.
@header {
	import java.lang.Math;
	import java.io.*;
}

// A main function to the parser. This function will setup the
// parsers input stream and execute the rule named "top".
@members {
    public static void main(String[] args) throws Exception {
        Lab6Lexer lex = new Lab6Lexer(new ANTLRInputStream(System.in));
       	CommonTokenStream tokens = new CommonTokenStream(lex);
        Lab6Parser parser = new Lab6Parser(tokens);

        try {
            parser.top();
        } catch (RecognitionException e)  {
            e.printStackTrace();
        }
    }
}

// Some example lexer fragments. These fragments don't produce any
// tokens themselves but can be used inside of other lexer rules.
fragment BIN: '0' .. '1';
fragment OCT: '0' .. '7';
fragment DEC: '0' .. '9';
fragment HEX: ('0' .. '9' | 'A' .. 'F' | 'a' .. 'f');
// The white space lexer rule. Match any number of white space characters
// and hide the results from the parser.
WS : (' ' | '\t' | '\r' | '\n')+ { $channel=HIDDEN; };
// The decimal value lexer rule. Match one or more decimal digits.
INT : DEC+ ;
DECIMAL : DEC+'.'DEC+ ;
// The binary value lexer rule. Match one or more decimal digits.
BINARY : '0b'BIN+ ;
// The octal value lexer rule. Match one or more octal digits.
//OCTAL : OCT+ ;
// The hexadecimal value lexer rule. Match one or more hexadecimal digits.
HEXADECIMAL: '0x'HEX+ ;
// The top rule. You should replace this with your own rule definition to
// parse expressions according to the assignment.
top : expr* EOF
	| OPENPAR expr CLOSEPAR EOF
    | EOF
    ;
expr 
	:digit  { System.out.println( $digit.value ); } 
	| addExpr { System.out.println( $addExpr.value ); } 
	| subExpr { System.out.println( $subExpr.value ); }
	| mulExpr { System.out.println( $mulExpr.value ); }
	| divExpr { System.out.println( $divExpr.value ); }
	| expExpr { System.out.println( $expExpr.value ); }
	| sinExpr { System.out.println( $sinExpr.value ); }
	| cosExpr { System.out.println( $cosExpr.value ); }
	| tanExpr { System.out.println( $tanExpr.value ); }
	| logExpr { System.out.println( $logExpr.value ); }
	;
	
	

	
addExpr returns [float value] 
	: l = digit { $value = $l.expr; }
		( PLUS r = digit { $value += $r.expr; } )
	;
						   
subExpr returns [float value] 
	: l = digit { $value = $l.value; }
		( MINUS r = digit { $value -= $r.value; } )
	;
mulExpr returns [float value] 
	: l = digit { $value = $l.value; }
		( MULT r = digit { $value *= $r.value; } )
	;
	
divExpr returns [float value] 
	: l = digit { $value = $l.value; }
		( DIV r = digit { $value /= $r.value; } )
	;
	
expExpr returns [float value] 
	: l = digit { $value = $l.value; }
		( EXPONENT r = digit { $value = (float)(Math.pow((float)$value, (float)$r.value)); } )
	;
	
sinExpr returns [float value] 
	: SINE r = digit { $value = (float)(Math.sin((float)$r.value)); }
	;
	
cosExpr returns [float value] 
	: COSINE r = digit { $value = (float)(Math.cos((float)$r.value)); }
	;
tanExpr returns [float value] 
	: TANGENT r = digit { $value = (float)(Math.tan((float)$r.value)); }
	;
	
logExpr returns [float value] 
	: LOG r = digit { $value = (float)(Math.log((float)$r.value)); }
	;
	
digit returns [float value] 
	: INT { $value = Integer.parseInt( $INT.getText(), 10); }
	| DECIMAL { $value = Float.parseFloat( $DECIMAL.getText()); }
	| BINARY { $value = Integer.parseInt( $BINARY.getText().substring(2), 2); }
	| HEXADECIMAL { $value = Integer.parseInt( $HEXADECIMAL.getText().substring(2), 16); }
	;

