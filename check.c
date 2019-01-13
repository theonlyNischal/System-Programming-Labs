#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
    char item_name[33];
    char item_database[33];
    char enter_again;
    float item_price;
    int item_found = 0;
    int c;
    do{
        printf("Enter the Item Name: \n");
        scanf("%s", &item_name);
        printf("Enter Price of %s: \n", item_name);
        scanf("%f", &item_price);

    FILE *fp;
    fp = fopen("check.txt", "a+");
    if (fp){
            do{
               fscanf(fp, "%[^\n]", &item_database);
               if(strcmp(item_name, item_database) == 0){
                    printf("%s already in database.\n", item_name);
                    item_found = 1;
                    break;
               }

            }while(c = fgetc(fp) != EOF);

            if (item_found == 0){
                    printf("%s doesn't exist.\n", item_name);
                    printf("Adding %s in database.\n", item_name);
                    fprintf(fp, "%s\n", item_name);
            }

    } //end of if(file)
fclose(fp);
fflush(stdin);
    printf("Enter another item?\n");
    scanf("%c", &enter_again);
    } while(enter_again == 'Y' || enter_again == 'y');

    printf("Exiting the system.\n");
    getch();
    return 0;

}
