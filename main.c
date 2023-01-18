#include<stdio.h>
#include "create_dir.c"


char * ask_folder_name() {
    static char foldername[25];
    printf("Enter your project name: ");
    scanf("%s", foldername);
    
    return foldername;
}




int main()
{   
    char * folder_name;
    folder_name = ask_folder_name();
    printf("%s\n", folder_name);
    create_dir(folder_name);
    return 0;
}
