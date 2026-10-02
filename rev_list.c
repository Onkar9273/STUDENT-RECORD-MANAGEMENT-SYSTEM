
// ******************************** Reversing the list *********************************

void rev_list(SLL **ptr)
{
        if(*ptr==0)
        {
                printf("No Records Found...\n");
                return ;
        }
        int co=0,i;
        co=countNode(*ptr);
        if(co>1)
        {
                SLL **a,*t=*ptr;
                a=malloc(sizeof(SLL *)*co);
                for(i=0;i<co;i++)
                {
                        a[i]=t;
                        t=t->next;
                }
                for(i=co-1;i>0;i--)
                        a[i]->next=a[i-1];
                a[0]->next=0;
                *ptr=a[co-1];
        }
        printf("List has Been Reversed Successfully...\n");
}
