#include "tree.h"

int main()
{
    Tree* t = new Tree;
    int var;

    t->left = NULL;
    t->right = NULL;
    
    cout<<"Введите корень (целое число)"<<endl;
    cin>>t->data;
    
    do{
        cout<<"Выберите действие:\n0 - выход 1 - добавить лист\n2 - вывести дерево 3 - найти элемент\n4 - запись без повторений"<<endl;
        cin>>var;
    
        switch(var)
        {
            case 0:
                goto L1;
            case 1:
                cout<<"Введите элемент (целое число)"<<endl;
                cin>>var;
                AddSheet(t, var);
                break;
            case 2:
                PrintTree(t);
                break;
            case 3:
                cout<<"Введите искомое целое число"<<endl;
                cin>>var;
                search(t, var);
                break;
            case 4:
                cout<<"введите элемент (целое число)"<<endl;
                cin>>var;
                wr_block(t, var);
                break;
        }
    }while(1);
L1:

    return 0;
}
