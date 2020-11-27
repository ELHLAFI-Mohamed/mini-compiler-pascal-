#include "analyse.h"
#include "lex.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>

void analyse(){

	if((Car_Cour>='a'&& Car_Cour<='z' )|| (Car_Cour>='A'&& Car_Cour<='Z')){
	word=(char*)malloc(40);
		strncat(word,&Car_Cour,1);
	read_car();
while((Car_Cour>='a'&& Car_Cour<='z' )|| (Car_Cour>='A'&& Car_Cour<='Z') || (Car_Cour>='0' && Car_Cour<='9') ){
	strncat(word,&Car_Cour,1);
	read_car();

}

if(strcmp(word,"program")==0){
	printf("%s -> PROGRAM_TOKEN\n",word);
}
 

else if(strcmp(word,"const")==0){
	printf("%s -> CONST_TOKEN\n",word);
}
else if(strcmp(word,"var")==0){
	printf("%s -> VAR_TOKEN\n",word);
}
else if(strcmp(word,"Begin")==0){
	printf("%s -> BEGIN_TOKEN\n",word);
}
else if(strcmp(word,"end")==0){
	printf("%s -> END_TOKEN\n",word);
}
else if(strcmp(word,"if")==0){
	printf("%s -> IF_TOKEN\n",word);
}
else if(strcmp(word,"then")==0){
	printf("%s -> THEN_TOKEN\n",word);
}
else if(strcmp(word,"while")==0){
	printf("%s -> WHILE_TOKEN\n",word);
}
else if(strcmp(word,"DO")==0){
	printf("%s -> DO_TOKEN\n",word);
}
else if(strcmp(word,"read")==0){
	printf("%s -> RED_TOKEN\n",word);
}
else if(strcmp(word,"write")==0){
	printf("%s -> WRITE_TOKEN\n",word);
}
else printf("%s -> ID_TOKEN\n",word);

strcpy(word,"");
free(word);

}

 if(Car_Cour==123){
 

read_car();
if(Car_Cour==42){
	
	int r=0 ;

while(r==0 && Car_Cour!=EOF){
	
	read_car();
	
	
	
	if(Car_Cour==42){
		
		read_car();
		if (Car_Cour==125)
		{
			r= 1;

		}

	}

}
if(r==1) {printf(" {* *} ->COMMENT_TOKEN\n"); read_car();}

else printf("ERROR_TOKEN\n");
}
else printf("%c ->GUIMO_TOKEN\n",Car_Cour );
}
 
 if (Car_Cour==125)
 {
 	printf("%c ->GUIMF_TOKEN\n",Car_Cour);
 }


   if((Car_Cour>='0' && Car_Cour<='9')){
  	strcpy(number,"");
 	strncat(number,&Car_Cour,1);
	read_car();
	while((Car_Cour>='0' && Car_Cour<='9')){
		strncat(number,&Car_Cour,1);
		read_car();
	}
	if((Car_Cour>='a' && Car_Cour<='z') && (Car_Cour>='A' ||Car_Cour<='Z') ){
		strncat(number,&Car_Cour,1);
		printf("%s -> ERREUR_TOKEN\n",number);
		strcpy(word,"");
	}
	else printf("%s -> NUM_TOKEN\n",number);
	strcpy(number,"");

}
 if(Car_Cour==61){
	printf("%c -> EGALE_TOKEN\n",Car_Cour);
}
if(Car_Cour==59){
	printf("%c -> PV_TOKEN\n",Car_Cour);
}if(Car_Cour==46){
	printf("%c -> PT_TOKEN\n",Car_Cour);

}
 if(Car_Cour==43){
	printf("%c -> PLUS_TOKEN\n",Car_Cour);
}
if(Car_Cour==45){
	printf("%c -> MOINS_TOKEN\n",Car_Cour);
}
 if(Car_Cour==42){
	printf("%c -> MULT_TOKEN\n",Car_Cour);
}
 if(Car_Cour==47){
	printf("%c -> DIV_TOKEN\n",Car_Cour);
}
 if(Car_Cour==44){
	printf("%c -> VIR_TOKEN\n",Car_Cour);

}

 if(Car_Cour==58){
	char c=Car_Cour;
	read_car();
	if(Car_Cour==61){
	printf(":= -> AFF_TOKEN\n");
}
else
printf("%c -> ERREUR_TOKEN\n",c);
}


 if(Car_Cour==60){
	char c=Car_Cour;
	read_car();
	if(Car_Cour==61){
	printf("<= -> INFEG_TOKEN\n");
}
else if(Car_Cour==62){
	printf("<> -> DIFF_TOKEN\n");
}

else{printf("%c -> INF_TOKEN\n",c);  analyse() ; }

}


 if(Car_Cour==62){
	char c=Car_Cour;
	read_car();
	if(Car_Cour==61){
	printf(">= -> SUPEG_TOKEN\n");
}

else{ printf("%c -> SUP_TOKEN\n",c);  analyse() ;    }

}

if(Car_Cour==40){
	printf("%c -> PO_TOKEN\n",Car_Cour);

}
if(Car_Cour==41){
	printf("%c -> PF_TOKEN\n",Car_Cour);

}

 if(Car_Cour==32){
	printf("%c -> SPACE_TOKEN\n",Car_Cour);

}

if(Car_Cour==10){
	printf("%c ->NEWLINE_TOKEN\n",Car_Cour);

}



}




void read_car(){

Car_Cour=fgetc(file);

}
void opn_file(char *filename){

	file=fopen(filename,"a+");
	read_car();
	while(Car_Cour!=EOF){
		analyse();
		read_car();
	}
	printf("EOF_TOKEN\n");



}
