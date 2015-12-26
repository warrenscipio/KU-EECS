%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list_type;
%}

%option       noyywrap nounput yylineno
%x            COMMENT PARA PRE OL UL LI LI2

%%

"<h1>"[^<]*"</h1>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
     
    yytext[yyleng-5] = 0;
    printf( "\\section{%s}", yytext+4 );
}

"<h2>"[^<]*"</h2>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
     
    yytext[yyleng-5] = 0;
    printf( "\\subsection{%s}", yytext+4 );
}

"<h3>"[^<]*"</h3>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
    yytext[yyleng-5] = 0;
    printf( "\\subsubsection{%s}", yytext+4 );
}
[ \t\n\r]+ {
    /**************************************************************************
     * Matched some whitespace that is not inside of an HTML tag. We
     * just ignore the whitespace.
     *************************************************************************/
}

. {
    /**************************************************************************
     * Matched something that we did not expect to see. Issue an error and
     * exit the program with a failure message.
     *************************************************************************/
    fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
    exit( 1 );
}

"<!--" {
    /**************************************************************************
     * Matched an HTML comment so print it out as a LateX comment. The
     * beginning and ending tags are stripped off before the LateX comment
     * is emitted.
     *************************************************************************/
    printf( "%% " );
    BEGIN COMMENT;
}



<COMMENT>[\n](\r)? {
    /**************************************************************************
     * Matched a newline and possible carriage return while parsing an HTML
     * comment. Print out a new line making sure to mark the next line as a
     * comment as well.
     *************************************************************************/
    printf( "\n%% " );
}

<COMMENT>[ \t] {
    /**************************************************************************
     * Matched some white space while parsing an HTML comment. Print out
     * the white space as is.
     *************************************************************************/
    printf( "%s", yytext );
}

<COMMENT>. {
    /**************************************************************************
     * Matched any other text while parsing an HTML comment. Print out
     * the text as is.
     *************************************************************************/
    printf( "%s", yytext );
}

<COMMENT>"-->" {
    /**************************************************************************
     * Matched an HTML end comment while parsing an HTML comment. Print out
     * a new line and resume normal parsing.
     *************************************************************************/
    printf( "\n" );
    BEGIN 0;
}




"<pre>" {

	printf( "\\begin{verbatim}");
	BEGIN PRE;
}


<PRE>[\n](\r)? {

    printf("%s" "\n% ");
}

<PRE>[ \t] {
  
    printf("%s", yytext );
}

<PRE>. {

    printf( "%s", yytext );
}

<PRE>"</pre>" {

	printf( "\\end{verbatim}" );
	BEGIN 0;

}




"<p>" {

	printf( "\n" );
	//printf( "%s", yytext );
	BEGIN PARA;

}




<PARA>. {

    printf( "%s", yytext );
}

<PARA>"</p>" {

	printf( "\n" );
	BEGIN 0;//get out of para

}



<PARA>"<small>"[^<]*"</small>" {

	yytext[yyleng-8] = 0;
	printf( "{\\scriptsize %s}", yytext+7 );

}

<PARA>"<big>"[^<]*"</big>" {

	yytext[yyleng-6] = 0;
	printf( "{\\Large %s}", yytext+5 );

}

<PARA>"<b>"[^<]*"</b>" {

	yytext[yyleng-4] = 0;
	printf( "\\textbf{%s}", yytext+3 );

}

<PARA>"<i>"[^<]*"</i>" {

	yytext[yyleng-4] = 0;
	printf( "\\textit{%s}", yytext+3 );

}

<PARA>"<strong>"[^<]*"</strong>" {

	yytext[yyleng-9] = 0;
	printf( "\\textmd{%s}", yytext+8 );

}

<PARA>"<em>"[^<]*"</em>" {

	yytext[yyleng-5] = 0;
	printf( "\\emph{%s}", yytext+4 );

}

<PARA>"<sup>"[^<]*"</sup>" {

	yytext[yyleng-6] = 0;
	printf( "\\textsuperscript{%s}", yytext+5 );

}

<PARA>"<sub>"[^<]*"</sub>" {

	yytext[yyleng-6] = 0;
	printf( "\\textsubscript{%s}", yytext+5 );

}




"<ul>" {

	printf( "\\begin{itemize}" );
	BEGIN UL;

}

<UL>"<li>" {

	yytext[yyleng-5] = 0;
	printf("\\item ", yytext+4);
	BEGIN LI;
}



<LI>"<small>"[^<]*"</small>" {

	yytext[yyleng-8] = 0;
	printf( "{\\scriptsize %s}", yytext+7 );

}

<LI>"<big>"[^<]*"</big>" {

	yytext[yyleng-6] = 0;
	printf( "{\\Large %s}", yytext+5 );

}

<LI>"<b>"[^<]*"</b>" {

	yytext[yyleng-4] = 0;
	printf( "\\textbf{%s}", yytext+3 );

}

<LI>"<i>"[^<]*"</i>" {

	yytext[yyleng-4] = 0;
	printf( "\\textit{%s}", yytext+3 );

}

<LI>"<strong>"[^<]*"</strong>" {

	yytext[yyleng-9] = 0;
	printf( "\\textmd{%s}", yytext+8 );

}

<LI>"<em>"[^<]*"</em>" {

	yytext[yyleng-5] = 0;
	printf( "\\emph{%s}", yytext+4 );

}

<LI>"<sup>"[^<]*"</sup>" {

	yytext[yyleng-6] = 0;
	printf( "\\textsuperscript{%s}", yytext+5 );

}

<LI>"<sub>"[^<]*"</sub>" {

	yytext[yyleng-6] = 0;
	printf( "\\textsubscript{%s}", yytext+5 );

}
<LI>"</li>" {

	printf( "\n" );
	BEGIN 0;
	BEGIN UL;
}



<UL>"</li>" {

	printf( "\n" );
	BEGIN 0;
	BEGIN UL;

}


<UL>"</ul>" {

	printf( "\\end{itemize}" );
	BEGIN 0;
	
}


"<ol>" {

	printf( "\\begin{enumerate}" );
	BEGIN OL;

}

<OL>"<li>" {

	yytext[yyleng-5] = 0;
	printf("\\item{%s}", yytext+4);
	BEGIN LI2;
	
}


<LI2>"<small>"[^<]*"</small>" {

	yytext[yyleng-8] = 0;
	printf( "{\\scriptsize %s}", yytext+7 );

}

<LI2>"<big>"[^<]*"</big>" {

	yytext[yyleng-6] = 0;
	printf( "{\\Large %s}", yytext+5 );

}

<LI2>"<b>"[^<]*"</b>" {

	yytext[yyleng-4] = 0;
	printf( "\\textbf{%s}", yytext+3 );

}

<LI2>"<i>"[^<]*"</i>" {

	yytext[yyleng-4] = 0;
	printf( "\\textit{%s}", yytext+3 );

}

<LI2>"<strong>"[^<]*"</strong>" {

	yytext[yyleng-9] = 0;
	printf( "\\textmd{%s}", yytext+8 );

}

<LI2>"<em>"[^<]*"</em>" {

	yytext[yyleng-5] = 0;
	printf( "\\emph{%s}", yytext+4 );

}

<LI2>"<sup>"[^<]*"</sup>" {

	yytext[yyleng-6] = 0;
	printf( "\\textsuperscript{%s}", yytext+5 );

}

<LI2>"<sub>"[^<]*"</sub>" {

	yytext[yyleng-6] = 0;
	printf( "\\textsubscript{%s}", yytext+5 );

}
<LI2>"</li>" {

	printf( "\n" );
	BEGIN 0;
	BEGIN OL;
}


<OL>"</li>" {

	printf( "\n" );
	BEGIN 0;
	BEGIN OL;

}


<OL>"</ol>" {

	printf( "\\end{enumerate}");
	BEGIN 0;
	
}




"<small>"[^<]*"</small>" {

	yytext[yyleng-8] = 0;
	printf( "\\{scriptsize %s}", yytext+7 );

}

"<big>"[^<]*"</big>" {

	yytext[yyleng-6] = 0;
	printf( "\\{Large %s}", yytext+5 );

}

"<b>"[^<]*"</b>" {

	yytext[yyleng-4] = 0;
	printf( "\\textbf{%s}", yytext+3 );

}

"<i>"[^<]*"</i>" {

	yytext[yyleng-4] = 0;
	printf( "\\textit{%s}", yytext+3 );

}

"<strong>"[^<]*"</strong>" {

	yytext[yyleng-9] = 0;
	printf( "\\textmd{%s}", yytext+8 );

}

"<em>"[^<]*"</em>" {

	yytext[yyleng-5] = 0;
	printf( "\\emph{%s}", yytext+4 );

}

"<sup>"[^<]*"</sup>" {

	yytext[yyleng-6] = 0;
	printf( "\\textsuperscript{%s}", yytext+5 );

}

"<sub>"[^<]*"</sub>" {

	yytext[yyleng-6] = 0;
	printf( "\\textsubscript{%s}", yytext+5 );

}



%%

/**************************************************************************
 * The main function for the HTML to LateX converter. Here we do three
 * things:
 *  1. Print out the LateX document header.
 *  2. Invoke the lexer to print out the LateX document
 *  3. Print out the LateX footer.
 *************************************************************************/
int main( int argc, const char *argv[] ) {
    printf( "\\documentclass[12pt]{article}\n" );
    printf( "\\usepackage{fixltx2e}\n" );
    printf( "\n" );
    printf( "\\setlength{\\parindent}{0.0in}\n" );
    printf( "\\setlength{\\parskip}{0.125in}\n" );
    printf( "\n\n" );
    printf( "\\begin{document}\n" );
    yylex();
    printf( "\\end{document}\n" );
    return 0;
}
