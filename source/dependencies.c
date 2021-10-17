#include "dependencies.h"

void mysh_init(){
    printf("\n######################## ✽ Sofia's Shell ✽ ########################\n\n");

}

void set_env(){
    environment.cwd = getcwd(NULL, 0);
    environment.user = getenv("USER");
}

void refresh_prompt(){
    char *prompt;
    char *aux;

    prompt = malloc(strlen(environment.user));

    if(environment.cwd != NULL && environment.user != NULL){
        strcpy(prompt, environment.user);
        if((aux = realloc(prompt, strlen(environment.cwd)+strlen("@")+strlen(":~ ")+1)) != NULL){
            prompt = aux;
            strcat(prompt, "@");
            strcat(prompt, environment.cwd);
            strcat(prompt,":~ ");

            write(STDOUT_FILENO, prompt, strlen(prompt));
            return;
        }
    }
    write(STDOUT_FILENO, "error", strlen("error"));
    //free(aux);
    free(prompt);
}

void parser(char *stream){
    char *aux;

    while(stream != NULL){
        aux = strtok(stream, " \t\n");
        if(strcmp(aux, "cd") == 0){
            aux = strtok(NULL, " \t\n");
            //llama a funcion para cambiar de directorio
        }
        else if(strcmp(aux, "clr") == 0){
            clrscr();
            refresh_prompt();
        }
    }

}