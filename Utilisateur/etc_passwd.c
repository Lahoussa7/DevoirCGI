#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	printf("Content-type: text/html\n\n");
	printf("<html>");
	printf("<head><title>user</title></head>");
	printf("<body width=100%%><div align=\"center\" style=\"background-color:pink;text-align:center;justify-content:center;margin:0 17.5%%;width:65%%;height:15%%;\"><h1 style=\"color:beige;\"> Les Informations sur les utilisateurs</h1></div><center><table border width=\"70%%\" height=\"60%%\" style=\"text-align:center;margin-top:-8%%\">");
	printf("<tr style=\"background-color:turquoise;\"><th>USER</th>");
	printf("<th>DIRECTORY</th>");
	printf("<th>SHELL</th></tr>");
    FILE *file;
    file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
	char line[1000];
    char user[900];
    char home_directory[100];
    char shell[200];
    int uid, gid;
	while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^\n]", user, &uid, &gid, home_directory, shell) ==5) {
            if (uid >= 1000 && gid >= 1000 && gid<2000 && uid<2000) {
               printf("<tr><td>%s</td><td>%s</td><td>%s</td></tr><br>",user,home_directory,shell);
            }
        }
    }
     fclose(file);
    printf("</table></center></body></html>");
   
    return 0;
}

