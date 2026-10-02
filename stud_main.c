#include "student.h"
static int c=1;
int main()
{
        SLL *headptr=0;
        char op;
        FILE *fp=fopen("student.dat","r");
        if(fp!=0)
        {
                SLL **ptr=&headptr;
                SLL *new,*last;
                while(1)
                {
                        new=malloc(sizeof(SLL));
                        if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage)==-1)
                                break;
                        c++;
                        new->next=0;
                        if(*ptr==0)
                                *ptr=new;
                        else
                        {
                                last=*ptr;
                                while(last->next)
                                        last=last->next;
                                last->next=new;
                        }
                }
                printf("\033[31;3m\nStudent records copied from file...\n\033[0m");
        }
        while(1)
        {
                printf("\n******** STUDENT RECORD MENU ********\n\na/A : Add new record\nd/D : Delete a record\ns/S : Show the list\nm/M : Modify a record\nv/V : Save records\ne/E : Exit\nt/T : Sort the list\nl/L : Delete all the records\nr/R : Reverse the list\n\nEnter your choice : ");
                scanf(" %c",&op);
                printf("\n");
                switch(op)
{

                        case 'a':
                        case 'A':
                                stud_add(&headptr);
                                break;
                        case 's':
                        case 'S':
                                stud_show(headptr);
                                break;
                        case 'm':
                        case 'M':
                                stud_mod(headptr);
                                break;
                        case 'd':
                        case 'D':
                                stud_del(&headptr);
                                break;
                        case 'l':
                        case 'L':
                                del_all(&headptr);
                                break;
                        case 'v':
                        case 'V':
                                stud_save(headptr);
                                break;
                        case 't':
                        case 'T':
                                stud_sort(headptr);
                                break;
                        case 'r':
                        case 'R':
                                rev_list(&headptr);
                                break;
                        case 'e':
                        case 'E':
                                {
                                        char op;
                                        printf("S/s : Save and exit\nE/e : Exit without saving\n\nEnter your choice : ");
                                        scanf(" %c",&op);
                                        switch(op)
                                        {
                                                case 's':
                                                case 'S':
                                                        stud_save(headptr);
                                                        break;
                                                case 'e':

                                                case 'E' :     return 0;
                                        }
                                }
                                return 0;
                }
        }
}
