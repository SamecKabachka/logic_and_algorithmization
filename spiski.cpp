#include "spiski.h"

void Queue::add(int num) 
{

    spisok* tmp;

   if (!start)
   {
       tmp = new spisok;
       tmp->num = num;
       
       tmp->next = NULL;
       tmp->back = NULL;
       this->start = tmp;
   }
   else
   {
       spisok *sps = start;
       while(sps->next != NULL) 
        {
            sps = sps->next;
        }

        tmp = new spisok;
        tmp->num = num;
        tmp->next = NULL;
        tmp->back = sps;
        sps->next = tmp;
        end = tmp;
   }
}

void Queue::print()
{
    spisok* sps = this->start;

    while(1)
    {
        cout<<sps->num<<" ";
        if (!sps->next) break;
        sps = sps->next;
    }
    cout<<endl;
    cin.ignore();
    cin.get();
}

void Queue::pop()
{
    spisok* tmp;
    
    if (!start)
    {
        cout<<"Список пуст!"<<endl;
        return;
    }

    tmp = start;
    if(start->next == NULL) start = NULL;
    else
    {
        start = start->next;
        start->back = NULL;
    }
    cout<<tmp->num<<endl;
    free(tmp);
    

    cin.ignore();
    cin.get();
}

void Stack::pop()
{
    spisok* tmp;

    if(!start)
    {
        cout<<"Список пуст!"<<endl;
    }

    tmp = end;
    if(end->back == NULL) start = NULL;
    else
    {
        end = end->back;
        end->next = NULL;
    }
    cout<<tmp->num<<endl;
    free(tmp);
    
    cin.ignore();
    cin.get();
};

void PQueue::add(int num, int preoriti)
{
    spisok* tmp,* sps;

    if(!start) 
    {
        tmp = new spisok;

        tmp->num = num;
        tmp->preoriti = preoriti;
        tmp->next = NULL;
        tmp->back = NULL;
        this->start = tmp;
        this->end = tmp;
    }
    else
    {
        sps = start;
        tmp = new spisok;
        tmp->num = num;
        tmp->preoriti = preoriti;
        

       while(1)
       {
            if(preoriti < sps->preoriti)
            {
                spisok* pred = sps->back;
                tmp->next = sps;
                if(!pred)
                {
                    this->start = tmp;
                    tmp->back = NULL;
                }
                else
                {
                    tmp->back = pred;
                    pred->next = tmp;
                    sps->back = tmp;
                }
                break;
            }
            
            else if(sps->next == NULL) 
            {
                tmp->next = NULL;
                tmp->back = sps;
                sps->next = tmp;
                end = tmp;
                break;
            }
            sps = sps->next;
       }
    }
};
