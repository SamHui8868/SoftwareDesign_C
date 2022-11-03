
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

const int _SIZE = 53;
const int h_size=13;


class deck
    {
    public:
        deck();
    void shuffle();
    void dealcard();
    void showdeck();
    void transfer( int phands[],int p);
    int drawcard();

    private:
    int d=1;
    int current_deck[_SIZE];
    int playerhands[5][h_size];
    };
class player
{
public:
    int hands[50];
    int handssuit[50];
    player();
    void showhands();
    void drawhands(int card);
    void sorting();
    void showlands();
    void build();
    void changehands();
    int sum();
    int draw_per_turn;

private:
    int c;
    int cost;
    int buildings[10];
    int job;
    int build_per_turn;
    int no_of_buildings;
    int build_type[10];

};

void Endturn();
void Start(string p);

int main()
{
 int j;
 cout<<"Welcome to POKER STAR!!!!"<<endl
     <<"To start the game type 0";
 cin>>j;
 if(j==0)
 {

 }

 player A;
 player B;
 player C;
 player D;
 deck DECK2;
 deck DECK1;

 DECK1.shuffle();
 DECK1.dealcard();
 DECK1.transfer(A.hands,1);
 DECK1.transfer(B.hands,2);
 DECK1.transfer(C.hands,3);
 DECK1.transfer(D.hands,4);
 DECK2.shuffle();


 int i;
 for(i=0;i<1;i++)
 {

 Start("A");
 cout<<endl;
 cout<<"CITYA   ";A.showlands();
 cout<<"CITYB   ";B.showlands();
 cout<<"CITYC   ";C.showlands();
 cout<<"CITYD   ";D.showlands();
 cout<<endl;

 A.drawhands(DECK2.drawcard());
 A.sorting();
 A.showhands();
 A.build();
 Endturn();


 Start("B");
 cout<<endl;
 cout<<"CITYA   ";A.showlands();
 cout<<"CITYB   ";B.showlands();
 cout<<"CITYC   ";C.showlands();
 cout<<"CITYD   ";D.showlands();
 cout<<endl;

 B.drawhands(DECK2.drawcard());
 B.sorting();
 B.showhands();
 B.build();
 Endturn();

 Start("C");
 cout<<endl;
 cout<<"CITYA   ";A.showlands();
 cout<<"CITYB   ";B.showlands();
 cout<<"CITYC   ";C.showlands();
 cout<<"CITYD   ";D.showlands();
 cout<<endl;

 C.drawhands(DECK2.drawcard());
 C.sorting();
 C.showhands();
 C.build();
 Endturn();

 Start("D");
 cout<<endl;
 cout<<"CITYA   ";A.showlands();
 cout<<"CITYB   ";B.showlands();
 cout<<"CITYC   ";C.showlands();
 cout<<"CITYD   ";D.showlands();
 cout<<endl;

 D.drawhands(DECK2.drawcard());
 D.sorting();
 D.showhands();
 D.build();
 Endturn();
 }

 cout<<"A: ";A.sum();
 cout<<"B: ";B.sum();
 cout<<"C: ";C.sum();
 cout<<"D: ";D.sum();
 return 0;
}
deck::deck()
{
    int i;
    for(i=0 ; i<_SIZE ; i++ )
    {
        current_deck[i]=i;
    }
}
void deck::shuffle()
{
    int i;
    int r=0;
    int temp;
    srand((unsigned)time(NULL));
    for(i=1 ; i<_SIZE ; i++ )
    {
     r=rand()%52+1;
     temp=current_deck[r];
     current_deck[r]=current_deck[i];
     current_deck[i]=temp;
    };


}
void deck::dealcard()
{
int r;
for(r=1; r<5;r++)
{
    int h=r;
    int i=0;
    for(i=0; i<13;i++){
    if(h>>52)
    { break;}
    playerhands[r][i]=current_deck[h];
    h=h+4;
            }
}
}
void deck::showdeck()
{
    int i;
    for(i=0 ; i<_SIZE ; i++ )
    {
        cout<< current_deck[i]<<" ";
            }
            cout<<endl;
}
void deck::transfer(int phands[],int p)//transfer hands from class deck to class player
{
   int i;
   for(i=0;i<13;i++)
   {
     phands[i]=playerhands[p][i];
   }

}
int deck::drawcard()
{
    int j;
    j=current_deck[d];
    d++;

    return j;
}
player::player()
{
    c=12;
    cost=10;
    draw_per_turn=1;
    no_of_buildings=0;
    int i;
    for(i=0;i<10;i++)
    {
        buildings[i]=0;
    }
}
void player::sorting()
{
  int i;
  int j;
  int temp;
  for(i=0;i<c+1;i++)
  {
      for(j=i+1;j<c+1;j++)
      {
          if(hands[i]>hands[j])
          {
              temp=hands[i];
              hands[i]=hands[j];
              hands[j]=temp;

          }
      }
  }

}
void player::drawhands(int card)
{
   c++;
   hands[c]=card;

}
void player::showlands()
{
    int i;
    for(i=0; i<10;i++)
    {
        if (build_type[i]==1)
        {
           cout<< "normal" << buildings[i]<<"   ";
        }
        if (build_type[i]==2)
        {
           cout<< "office" << buildings[i]<<"   ";
        }
        if (build_type[i]==3)
        {
           cout<< "residence" << buildings[i]<<"   ";
        }
        if (build_type[i]==4)
        {
           cout<< "factory" << buildings[i]<<"   ";
        }
        if (build_type[i]==5)
        {
           cout<< "bank" << buildings[i]<<"   ";
        }
    }
    cout<<endl;
}
void player::changehands()
{
    int i;
    for (i=0;i<13;i++)if (answer==1)
        {
            cout << "you build an office in position " << no_of_buildings ;
            buildings[no_of_buildings]=10;
            build_type[no_of_buildings]=1;
            no_of_buildings++;
        }
    {
        if(hands[i]>0&&hands[i]<14)
    {
        handssuit[i]=1;
    }

    if(hands[i]>=14&&hands[i]<27)
    {
        hands[i]=hands[i]-13;
        handssuit[i]=2;
    }

     if(hands[i]>=27 && hands[i]<40)
    {
        hands[i]=hands[i]-26;
        handssuit[i]=3;
    }

     if(hands[i]>=40 && hands[i]<53)
     {
        hands[i]=hands[i]-39;
        handssuit[i]=4;
     }
    }
}
void player::showhands()
{
  int i;
  cout<<"(Suit Face)This is your hands:   ";
  for(i=0;i<c+1;i++)
  {
    if(handssuit[i]==0)
    {
        cout<<i<<".used   ";
    }
    if(handssuit[i]==1)
    {
        cout<<i<<"."<<"Club"<<hands[i]<<"   ";
    }

    if(handssuit[i]==2)
    {
        cout<<i<<"."<<"Diamond"<<hands[i]<<"   ";
    }

     if(handssuit[i]==3)
    {
        cout<<i<<"."<<"Heart"<<hands[i]<<"   ";
    }

     if(handssuit[i]==4)
     {
        cout<<i<<"."<<"Spade"<<hands[i]<<"   ";
     }

    }
    cout<<endl<<endl;
  }

  void player::build()
  {
      int ans;
      int type;
      int h,i,j,k,l,p;
     cout<<"Do you want to build?(0 for yes,1 for No)"<<endl;
     cin>>ans;
     if(ans==0)
     {
         cout<<"What type of buildings do you want to build? 1 for special, 0 for normal"<<endl;
         cin>>type;
         while(type==1)
         {
             cout<<"Which two cards do you want to use? Type the position."<<endl;
             cin>>i;
             cin>>j;
        if(hands[i]+hands[j]!=10 || handssuit[i]!=handssuit[j])
    {
        cout << "you type the wrong number." << endl << "please type the correct number." ;
        continue;
    }

    else
    {
        hands[i]=0;
        hands[j]=0;
        handssuit[i]=0;
        handssuit[j]=0;
        cout << "which special house do you want to build? 1 for office 2 for residence 3 for factory 4 for bank. " ;
        cin answer ;
        if (answer==1)
        {
            cout << "you build an office in position " << no_of_buildings ;
            buildings[no_of_buildings]=10;
            build_type[no_of_buildings]=2;
            no_of_buildings++;
        }
        if (answer==2)
        {
            cout << "you build a residence in position " << no_of_buildings ;
            buildings[no_of_buildings]=10;
            build_type[no_of_buildings]=3;
            no_of_buildings++;
        }
        if (answer==3)
        {
            cout << "you build an factory in position " << no_of_buildings ;
            buildings[no_of_buildings]=10;
            build_type[no_of_buildings]=4;
            no_of_buildings++;
        }
        if (answer==4)
        {
            cout << "you build an bank in position " << no_of_buildings ;
            buildings[no_of_buildings]=10;
            build_type[no_of_buildings]=5;
            no_of_buildings++;
        }
    }
        }
        while (type==0)
        {
            cout << "How many cards do you want to use?";
            cin answ;
            cout << "please type the card position you want to use"
            for (k=0;k<answ;k++)
            {
                for (h=0;h<11;h++)
                {
                    cardsum[h]=0;
                }
                cin << p[k];
                if (hands[p[k]]==0)
                {
                    cout << "This card is used.Please type the correct number."
                    continue;
                }
                cardsum[k+1]=cardsum[k]+hands[p[k]];
            }
            for (l=0;l<answ;l++)
            {
                hands[p[l]]=0;
                handssuit[p[l]]=0;
            }
            switch (cardsum[k+1])
            {
                case 1:
                buildings[no_of_buildings]=1;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 1";
                no_of_buildings++;
                break;
                case 2:
                buildings[no_of_buildings]=2;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 2" ;
                no_of_buildings++;
                break;
                case 3:
                buildings[no_of_buildings]=3;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 3";
                no_of_buildings++;
                break;
                case 4:
                buildings[no_of_buildings]=4;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 4";
                no_of_buildings++;
                break;
                case 5:
                buildings[no_of_buildings]=5;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 5";
                no_of_buildings++;
                break;
                case 6:
                buildings[no_of_buildings]=6;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 6";
                no_of_buildings++;
                break;
                case 7:
                buildings[no_of_buildings]=7;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 7";
                no_of_buildings++;
                break;
                case 8:
                buildings[no_of_buildings]=8;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 8";
                no_of_buildings++;
                break;
                case 9:
                buildings[no_of_buildings]=9;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 9";
                no_of_buildings++;
                break;
                default:
                buildings[no_of_buildings]=10;
                build_type[no_of_buildings]=1;
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 10";
                no_of_buildings++;
                break;
            }
        }
  int player::sum()
  {
    int i;
    int point=0;
    for(i=0;i<10;i++)
    {
     point=point+buildings[i];
    }
    cout<<point<<endl;
    return point;
  }
  void Endturn()
  {
    int i;
    cout<<"PLS TYPE 0 TO END YOUR TURN"<<endl;
    cin>>i;
    if(i==0)
    {
        system("cls");
    }
  }
  void Start(string p)
  {
      int i;
      cout<<"PLAYER "<<p<<",to start your turn type 0"<<endl;
      cin>>i;
      if(i==0)
      {

      }
  }
