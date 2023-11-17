#include "tree.h"

void wr_block(Tree* t, int num)
{
    int i = search(t, num);
    cout<<i<<endl;
    if (i == 0) AddSheet(t, num);
    else cout<<"Элемент существует!"<<endl;
}

void AddSheet(Tree* tr, int num, Tree* tmp)
{
    if(!tr)
    {
        return;
    }

    if(!tmp)
    {
        tmp = new Tree;
        tmp->data = num;
        tmp->left = NULL;
        tmp->right = NULL;
    }

    if(num < tr->data)
    {
        if(!tr->left)
        {
            tr->left = tmp; 
            tr = NULL;  
            return;
        }
        else AddSheet(tr->left, num, tmp = tmp);
    }
    else
    {
        if(!tr->right)
        {
            tr->right = tmp;
            tr = NULL;
            return;
        }
        else AddSheet(tr->right, num, tmp = tmp);
    }
}


void PrintTree(Tree const * node, std::string const & rpref, std::string const & cpref, std::string const & lpref) {
    if (!node) return;
    if (node->right)
        PrintTree(node->right, rpref + "  ", rpref + ch_ddia_hor, rpref + ch_ver_spa);
    std::cout << cpref << std::to_string(node->data) << std::endl;
    if (node->left)
        PrintTree(node->left, lpref + ch_ver_spa, lpref + ch_udia_hor, lpref + "  ");
}

int search (Tree* tr, int num)
{
    bool key = 0;
    if(!tr) return num;

    if(num == tr->data)
    {
        tr = NULL;
        key = 1;
        
    }
    else if(num < tr->data and tr->left != NULL) num = search(tr->left, num);
    else if (num > tr->data and tr->right != NULL) num = search(tr->right, num);
    else {num = 0; key = 1;}

    if (num and key) {cout<<"Элемент найден!"<<endl; key = 0;}
    else if (num == 0 and key) {cout<<"Элемент не найден!"<<endl; key = 0;}
    return num;
}
