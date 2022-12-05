#include<iostream>
using namespace std;
static int p=0;
static int rcount=2;
static int ccount=2;
static int dcount=2;
static char arr[3][3]={0};
class game{
    public:
    void print()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j<2)
                {
                    cout<<arr[i][j]<<"  | ";
                }
                else
                {
                    cout<<arr[i][j];
                }
            }
            if(i<2)
            {
                cout<<endl<<"___ ___ ___";
            }
            cout<<endl;
        }
    }
    void enter1(int pos)
    {
        pos=pos-1;
        if(pos>=0 && pos<3)
        {
            if(arr[0][pos]==NULL)
            {
                arr[0][pos]='O';
            }
            else
            {
                cout<<"Already selected position. Try Again."<<endl;
                cout<<"Enter new position:"<<endl;
                cin>>pos;
                this->enter1(pos);
            }
        }
        else if(pos>=3 && pos<6)
        {
            if(arr[1][pos-3]==NULL)
            {
                arr[1][pos-3]='O';
            }
            else
            {
                cout<<"Already selected position. Try Again."<<endl;
                cout<<"Enter new position:"<<endl;
                cin>>pos;
                this->enter1(pos);
            }
        }
        else if(pos>=6 && pos<9)
        {
            if(arr[2][pos-6]==NULL)
            {
                arr[2][pos=-6]='O';
            }
            else
            {
                cout<<"Already selected position. Try Again."<<endl;
                cout<<"Enter new position:"<<endl;
                cin>>pos;
                this->enter1(pos);
            }
        }
    }
    void enter0(int pos)
    {
        pos=pos-1;
        if(pos>=0 && pos<3)
        {
            if(arr[0][pos]==NULL)
            {
                arr[0][pos]='X';
            }
            else
            {
                cout<<"Already selected position. Try Again."<<endl;
                cout<<"Enter new position:"<<endl;
                cin>>pos;
                this->enter0(pos);
            }
        }
        else if(pos>=3 && pos<6)
        {
            if(arr[1][pos-3]==NULL)
            {
                arr[1][pos-3]='X';
            }
            else
            {
                cout<<"Already selected position. Try Again."<<endl;
                cout<<"Enter new position:"<<endl;
                cin>>pos;
                this->enter0(pos);
            }
        }
        else if(pos>=6 && pos<9)
        {
            if(arr[2][pos-6]==NULL)
            {
                arr[2][pos-6]='X';
            }
            else
            {
                cout<<"Already selected position. Try Again."<<endl;
                cout<<"Enter new position:"<<endl;
                cin>>pos;
                this->enter0(pos);
            }
        }
    }
    void player0()
    {
        int pos;
        cout<<"Enter position:";
        cin>>pos;
        cout<<endl;
        this->enter0(pos);
    }
    void player1()
    {
        int pos;
        cout<<"Enter position:";
        cin>>pos;
        cout<<endl;
        this->enter1(pos);
    }
    int frcount()
    {
        if((arr[0][0]=='O' && arr[0][1]=='O' && arr[0][2]=='O') || (arr[1][0]=='O' && arr[1][1]=='O' && arr[1][2]=='O') || (arr[2][0]=='O' && arr[2][1]=='O' && arr[2][2]=='O'))
        {
            rcount=0;
            return rcount;
        }
        else if((arr[0][0]=='X' && arr[0][1]=='X' && arr[0][2]=='X') || (arr[1][0]=='X' && arr[1][1]=='X' && arr[1][2]=='X') || (arr[2][0]=='X' && arr[2][1]=='X' && arr[2][2]=='X'))
        {
            rcount=1;
            return rcount;
        }
        else
        {
            rcount=2;
            return rcount;
        }
    }
    int fccount()
    {
        if((arr[0][0]=='O' && arr[1][0]=='O' && arr[2][0]=='O') || (arr[0][1]=='O' && arr[1][1]=='O' && arr[2][1]=='O') || (arr[0][2]=='O' && arr[1][2]=='O' && arr[2][2]=='O'))
        {
            ccount=0;
            return ccount;
        }
        else if((arr[0][0]=='X' && arr[1][0]=='X' && arr[2][0]=='X') || (arr[0][1]=='X' && arr[1][1]=='X' && arr[2][1]=='X') || (arr[0][2]=='X' && arr[1][2]=='X' && arr[2][2]=='x'))
        {
            ccount=1;
            return ccount;
        }
        else
        {
            ccount=2;
            return ccount;
        }
    }
    int fdcount()
    {
        if((arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O') ||(arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O'))
        {
            dcount=0;
            return dcount;
        }
        else if((arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X') ||(arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X'))
        {
            dcount=1;
            return dcount;
        }
        else
        {
            dcount=2;
            return dcount;
        }
    }
    int gamecheck()
    {
        if(frcount()==0 || fccount()==0 || fdcount()==0)
        {
            return 0;
        }
        else if(frcount()==1 || fccount()==1 || fdcount()==1)
        {
            return 1;
        }
        else return 2;
    }
    void noresult()
    {
        int ct=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(arr[i][j]==NULL)
                {
                    ct++;
                }
            }
        }
        if(ct==0)
        {
            cout<<"No result"<<endl;
        }
    }
};



int main()
{
    char check;
    cout<<"Play Game: Yes(Y) or No(N)"<<endl;
    cin>>check;
    cout<<endl;
    game g;
    if(check=='Y' || check=='y')
    {
        cout<<"Player 1: O and Player 2: X"<<endl;
        g.print();
        while((rcount!=1 && rcount!=0 && ccount!=1 && ccount!=0 && dcount!=0 && dcount!=1))
        {
            if(p==0)
            {
                g.player0();
                if(g.gamecheck()==1)
                {
                    cout<<"Player 1 wins."<<endl;
                    g.print();
                    break;
                }
                else if(g.gamecheck()==0)
                {
                    cout<<"Player 0 wins."<<endl;
                    g.print();
                    break;
                }
                p=1;
                g.print();
                cout<<endl;
                g.noresult();
                continue;
            }
            else if(p==1)
            {
                g.player1();
                if(g.gamecheck()==1)
                {
                    cout<<"Player 1 wins."<<endl<<endl;
                    g.print();
                    break;
                }
                else if(g.gamecheck()==0)
                {
                    cout<<"Player 0 wins."<<endl<<endl;
                    g.print();
                    break;
                }
                p=0;
                g.print();
                cout<<endl;
                g.noresult();
                continue;
            }
        }
    }
    else if(check=='N' || check=='n')
    {
        cout<<"Okay...Thank You"<<endl;
    }
}
