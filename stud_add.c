void stud_add(SLL **ptr)   // Adding at last
{
        SLL *new,*last;
        new=malloc(sizeof(SLL));
        printf("Enter name and percentage : ");
        new->rollno = c++;
o:
        scanf("%s %f",new->name,&new->percentage);
        if(new->percentage<0 || new->percentage>100)
        {
                printf("\nPercentage should be in between 0 to 100...\n\nEnter name and percentage again : ");
                goto o;
        }
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
