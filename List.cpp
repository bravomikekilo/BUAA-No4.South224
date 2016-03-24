#include <iostream>
#include <stdlib.h>
using namespace std;
struct data{
    short num;
};
struct listNode{
    struct data data;
    struct listNode * next;
};
void delete_list(struct listNode * p)
{
	if(p==NULL)
	    return;
        while(p->next!=NULL)
	{
	    struct listNode *temp = p->next;
	    free(p);
	    p = temp;
	}
	free(p);
	return;
}
double avg(struct listNode *p)
{
    double re =-1;
    double sum = 0;
    int count = 0;
    while(p!=NULL)
    {
	sum += p->data.num;
	count ++;
	p = p->next;
    }
    if(count)
	re =sum/count;
    return re;
}
int main()
{
   struct listNode *Head=NULL;
   struct listNode *p=NULL;
   while(1)
   {
       short temp;
       cout << "输入成绩|>"; 
       cin >> temp;
       if (temp < 0 )
	   break;
       struct listNode * node = (struct listNode * )malloc(sizeof( struct listNode));
       node->data.num =temp;
       node->next=NULL;
       if (Head==NULL)
       { Head = node; p=node;}

       else{
       p->next = node;
       p = node;}
   }
   cout<<"平均值是|>"<<avg(Head)<<endl;
   delete_list(Head);
   return 0;
}
