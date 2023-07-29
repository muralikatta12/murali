#include<stdio.h>
#include<unistd.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define TRIES 3
void password();
void heading();
void mainMenu();
int addBook();
void viewBooks();
int searchBook();
int editBook();
void deleteBook(); 
void help();
void exitprog();
struct BOOK_INFO
{
    int ID;
    char Name[20];
    char Author[20];
    int Quantity;
    int RackNo;
};
struct BOOK_INFO add;
FILE *fp;
FILE *file2;
int main()
{
password();
}
void heading()
{
     time_t t;   // not a primitive datatype
    time(&t);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);

    printf("\n\n\n\t\t\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t\t\t############                                                   ############\n");
    printf("\t\t\t\t\t\t############        ");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);
    printf("<<<LIBRARY MANAGMENT SOFTWARE >>>");
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
    printf("          ############");
    printf("\n\t\t\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t\t\t########################################################################### D/M/D/T/Y >%s",ctime(&t));
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);

    printf("\n                                                \t\t\t\t\t\t\t\t\t                                             \n");
   

    }
void password()
{
    heading();
    int count=1;
    char pass[]="murali";
    char ch[20];
    {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE);
 
    printf("\nPlease Enter Password :\n");

    }
            gets(ch);
    while(strcmp(ch,pass)!=0)
    {
        count++;
        if(count>TRIES)
        {
            exit(1);
        }
        
        {
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);
        printf("\n INVALID\nTRY AGAIN\n");
            getchar();
          fgets(ch,sizeof(ch),stdin);
        }
        
  }
       {
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);

    printf("\n\nLog in Successfully.........\n\n"
            "Press any key to Continue.......\n");
       }
            getchar();
            mainMenu();
}
void mainMenu()
{
    int choice =0;
    system("clear");
    while(1)
    {
        printf("________________________**********************Main Menu***********************_______________________\n\n");
        printf( "1.Add bokk\n"
                "2.view book list\n"
                "3.search book\n"
                "4.edit book\n"
                "5.delete book\n"
                "6.Help\n"
                "7.Exit\n\n");
        printf("************************************************####************************************************\n");
                printf("enter your choice:");
                scanf("%d",&choice);
                getchar();
                if (choice==1)
                {
                    addBook();
                }
                else if(choice==2)
                {
                    viewBooks();

                }
                else if(choice==3)
                {
                    searchBook();
                }
                else if(choice==4)
                {
                    editBook();
                }
                else if(choice==5)
                {
                    deleteBook();
                }
                else if(choice==6)
                {
                    help();

                }
                else if(choice==7)
                {
                    break;
                    
                }
                else{
                    printf("worng choice \n Try again \n");
                }
    }
               exitprog();
}
                int addBook()
                {
                    int d,count=0;
                    system("clear");
                    printf("**************************Book info***********************\n\n");
                    fp=fopen("books.txt","ab+");
                    printf("Enter ID:- ");
                    fflush(stdin);
                    scanf("%d",&d);
                    rewind(fp);
                    while(fread(&add, sizeof(add),1,fp)==1)
                    {
                        if(d== add.ID)
                        {
                            printf("this book is already in library");
                            return 0;
                        }
                    }
                    add.ID=d;
                    printf("Enter Name:- " );
                    fflush(stdin);
                    scanf("%s",add.Name);

                    printf("Enter Author :- ");
                    fflush(stdin);
                    scanf("%s",&add.Author);

                    printf("Enter quantity:- ");
                    fflush(stdin);
                    scanf("%d",&add.Quantity);

                    printf("Enter Rack-no:- ");
                    fflush(stdin);
                    scanf("%d",&add.RackNo);

                    fseek(fp,0,SEEK_END);
                    fwrite(&add,sizeof(add),1,fp);
                    fclose(fp);
                    printf("Book Added Successfully\n\n");
                    return 0;
                }          
        void viewBooks()
        {
            int count=0;
            system("clear");
            printf("*******************************View Books****************************************\n");
            printf("ID\nName\nAuthor\nQuantity\nRack No\n\n\n");

            fp=fopen("books.txt","rb");
            while(fread(&add,sizeof(add),1,fp)==1)
            {
                printf("%d",add.ID);
                printf("\n%s",add.Name);
                printf("\n%s",add.Author);
                printf("\n%d",add.Quantity);
                printf("\n%d\n",add.RackNo);

                count=count+add.Quantity;
            }
            fclose(fp);
            printf("\n\nTotal books in the library :%d\n",count);
            printf("\npress any key........\n");
            getchar();

        }
        int searchBook()
        {
            int count;
            system("clear");
            printf("************************search books*****************************\n\n");
            fp=fopen("books.txt","rb");
            printf("Enter ID:- \n");
            scanf("%d",&count);
            getchar();
            while(fread(&add,sizeof(add),1,fp)==1)
            {
                if(count==add.ID)
                {
            printf("\nBook is found.....\n");
            printf("Id:- %d\n", add.ID);
            printf("Name:- %s\n", add.Name);
            printf("Author:- %s\n", add.Author);
            printf("Quantity:- %d\n", add.Quantity);
            printf("Rack no:- %d\n\n", add.RackNo);
             printf("\nPress any key... \n ");
            getchar();

            return 0;
                }
            }
            printf("ID not found\n");
            printf("\n press any key.......\n");
            getchar();
            return 0;
        }
        int editBook()
        {
            int d;
            int count=0;
            system("clear");
            printf("**********************************Edit book******************************\n");
            fp=fopen("books.txt","rb+");
            printf("Enter ID:\n");
            scanf("%d",&d);
            getchar();
            while(fread(&add,sizeof(add),1,fp)==1)
            {
                if(d==add.ID)
                {
                    printf("ID is Available\n\n");
                    printf("ID:- %d\n",add.ID);
                    printf("Enter new name:- ");
                    scanf("%s",add.Name);
                    printf("Enter New author:- ");
                    scanf("%s",add.Author);
                    printf("Enter new quantituy");
                    getchar();
                    printf("Enter new Rack no:- ");
                    scanf("%d",&add.RackNo);
                    getchar();
                    fseek(fp,ftell(fp)-sizeof(add),0);
                    fwrite(&add,sizeof(add),1,fp);
                    fclose(fp);

                    printf("\n\npress any key .........\n");
                    getchar();
                    return 0;

                }
            }
            printf("id not match\n");
            printf("\n\npress any key.........\n");
            getchar();
            return 0;
        }
       
        void deleteBook()
{
    int d, count = 0;
    system("clear");
    printf("*********************Delete Book **************************************\n");
    printf("Enter ID for delete:");
    scanf("%d", &d);
    getchar();

    fp = fopen("books.txt", "rb");
    file2 = fopen("text.txt", "wb+");
    while (fread(&add, sizeof(add), 1, fp) == 1)
    {
        if (d != add.ID)
        {
            fwrite(&add, sizeof(add), 1, file2);
        }
        else
        {
            count = 1;
        }
    }
    fclose(fp);
    fclose(file2);

    if (count == 0)
    {
        printf("Book not found \n");
    }
    else
    {
        remove("books.txt");
        rename("text.txt", "books.txt");
    }

    printf("press any key/.........\n");
    fflush(stdin);
    getchar();
}

        void help()
        {
            system("clear");
    printf("\n\n");
    printf("this is a simple library projects\n");
    printf("the password is <murali>\n");
    printf("you can add books, edit books and delete books \n\n");
    printf("thank you very much for visiting \n\n");
    printf("press any key/.........\n");
            fflush(stdin);
            getchar();
        }
        void exitprog()
        {
            system("clear");
            printf("Thank you!!\n\n");
            printf("wait.........\n");
            sleep(5);
            exit(0);
        }

                    