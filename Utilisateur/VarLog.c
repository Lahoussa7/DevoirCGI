#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nombreline(){
	printf("Content-type: text/html\n\n");
	printf("<html>");
	printf("<head><title>varlog</title><head>");
	printf("<body style=\"background-color:violet;\"><div align=\"center\"><B><font color=\"crimson\" size=20>Les 100 derniers authentification dans /var/log/auth.log </font></B></div><center><table border width=80%% height=70%% style=\"text-align:center;\">");
	printf("<tr style=\"background-color:white;\"><th>DATE DE L'OUVERTURE ET DE FERMETURE</th><th>OUVERT/FERMER </th><th>UTILISATEUR</th></tr>");
	char *car =(char*)malloc(sizeof(char)*1000);
	FILE*file;
	file=fopen("/var/log/auth.log","r");
	
	if(file==NULL){
		printf("on n'a pas pu ouvrir le fichier\n");
		
	}
	int nbl=0;
	
	while(!feof(file)){
		fgets(car,1000,file);	
		nbl++;	
	}
	
	fclose(file);
	return nbl-100;
}
/*char*tableauMisyvarlog(FILE*fil){ 
	}*/
int main(){
	FILE*file;
	file=fopen("/var/log/auth.log","r");
	char *ca2 = (char*)malloc(sizeof(char)*1000); 
	char*car=malloc(sizeof(char)*1000);
	
	char*ca5=malloc(sizeof(char)*1000);

	char*ca=malloc(sizeof(char)*1000);

	char*ca3=malloc(sizeof(char)*1000);

	char*ca1=malloc(sizeof(char)*1000);

	char*ca6=malloc(sizeof(char)*1000);

	char*ca7=malloc(sizeof(char)*1000);

	char*ca8=malloc(sizeof(char)*1000);
	
	char*ca9=malloc(sizeof(char)*1000);

	
	if(file==NULL){
		printf("on n'a pas pu ouvrir le fichier\n");
		return 1;
	}
	int i=0;
	int nb=nombreline();
	
	while (feof(file)!=1){
		
	fgets(ca2,1000,file);	

	sscanf(ca2,"%[^ ] %[^ ] %[^ ] %*[^:]: %*[^ ] %[^ ] %[^ ] %*[^ ] %*[^ ] %[^ ] %[^\n]",ca,ca1,car,ca3,ca6,ca7,ca8);
		i++;
		if(i>nb){
			
			if(strstr(ca6,"opened")!=NULL || strstr(ca6,"closed")!=NULL){
		
	              if(strcmp(ca7,"root")==0 || strcmp(ca7,"misa")==0 || strcmp(ca7,"gdm")==0){
		          strcpy(ca9,ca7);
	         }
	        if(strcmp(ca6,"closed")==0 || strcmp(ca6,"opened")==0){
		          strcpy(ca5,ca6);
	        }  
	              printf("<tr style=\"background-color:cadetblue;\"><td>%s   %s   %s</td><td>%s</td><td>%s</td></tr>",ca,ca1,car,ca5,ca9);

             }
	
	         }
	
	}
	fclose(file);
	printf("</center></table></body></html>");
	
	return 0;
	
}
