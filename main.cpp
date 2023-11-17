#include "spiski.h"

template <typename T>
void menu (T str);

int main()
{
    int choice, value, prioriti;
    cout<<"Выберите структуру: \n1-стек\n2-очередь\n3-приоритетная очередь"<<endl;
    cin>>choice;

    if(choice == 1)
    {
        Stack st;
        while(1)
        {
            system("clear");
            cout<<"Выберите действие \n0-выход \n1-напечатать\n2-добавить\n3-извлеч"<<endl;
            cin>>choice;

            if(choice == 1) st.print();
            else if(choice == 2)
            {
                cout<<"Введите число"<<endl;
                cin>>value;
                st.add(value);
            }
            else if(choice == 3) st.pop();
            else if(choice == 0) break;
            else cout<<"Неверное число!"<<endl;
        }
    }
    else if(choice == 2)
    {
        Queue qe;    
        while(1)
        {
            system("clear");
            cout<<"Выберите действие \n0-выход \n1-напечатать\n2-добавить\n3-извлеч"<<endl;
            cin>>choice;

            if(choice == 1) qe.print();
            else if(choice == 2)
            {
                cout<<"Введите число"<<endl;
                cin>>value;
                qe.add(value);
            }
            else if(choice == 3) qe.pop();
            else if(choice == 0) break;
            else cout<<"Неверное число!"<<endl;
        }
    }
    else if(choice == 3)
    {
        PQueue qe;   
        while(1)
        {
            system("clear");
            cout<<"Выберите действие \n0-выход \n1-напечатать\n2-добавить\n3-извлеч"<<endl;
            cin>>choice;

            if(choice == 1) qe.print();
            else if(choice == 2)
            {
                cout<<"Введите число"<<endl;
                cin>>value;
                cout<<"Введите приоритет"<<endl;
                cin>>prioriti;
                qe.add(value, prioriti);
            }
            else if(choice == 3) qe.pop();
            else if(choice == 0) break;
            else cout<<"Неверное число!"<<endl;
        }
    }
    else cout<<"Неверное число!"<<endl;
    return 0;
}

template <typename T>
void menu(T str)
{
    ;
}
