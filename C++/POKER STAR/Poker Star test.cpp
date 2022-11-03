

#include <iostream>
#include <cstdlib>
#include <time.h>


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
    int d;
    int current_deck[_SIZE];
    int playerhands[5][h_size];
    };
class player
{
public:
    int hands[50];
    int rdraw_per_turn;
    int buildings[10];
    int point=0;
    int c;
    player();
    void showhands();
    void drawhands(int card);
    void showlands();
    void showstatus(string a);
    void build();
    int Last();
    int sum();
    void changehands();
    void business(int i);
    void invester(int i);
    void developer(int i);
    void poor(int i);
    void Endturn();
    void poorskill(int i);
    void developerskill(int i);
    void investerskill(int i);

private:

    int cost;
    int no_fac;
    int build_per_turn;
    int draw_per_turn;
    int fcost;
    int fbuild_per_turn;
    int fdraw_per_turn;
    int rcost;
    int rbuild_per_turn;

    int no_of_buildings;
    string build_type[10];
    string hands_suit[50];
};


void Start(string p);

int main()
{
int j;
 cout<<"Welcome to POKER STAR!!!!"<<endl
     <<"To start the game enter any numbers";
 cin>>j;
 if(j==0)
 {
 }

 srand(time(NULL));
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
 A.changehands();
 B.changehands();
 C.changehands();
 D.changehands();


 int a,b,c,d;
 int turn=1;
 do
 {
    int k;
    int p[4]={0,1,2,3};
    int charac;
    int i;
    int r=0;
    int t;
    for(i=1 ; i<4 ; i++ )
    {
     r=rand()%4;
     t=p[r];
     p[r]=p[i];
     p[i]=t;
    }
 for(i=0;i<4;i++)
 {
switch(p[i])
{
case 0:

 Start("A");
 cout<<"TURN: "<<turn<<endl<<endl;
 A.business(i);
 A.poor(i);
 A.developer(i);
 A.invester(i);
 A.showstatus("A");
 cout<<"CITYA   ";A.showlands();
 cout<<"CITYB   ";B.showlands();
 cout<<"CITYC   ";C.showlands();
 cout<<"CITYD   ";D.showlands();
 cout<<endl;
 for(k=0;k<A.rdraw_per_turn;k++)
 {
   if(A.c+B.c+C.c+D.c==100)
   {
       break;
   }
   A.drawhands(DECK2.drawcard());
 }


 A.showhands();
 A.build();
 A.poorskill(i);
 A.developerskill(i);
 A.investerskill(i);
 A.Endturn();
 break;

case 1:
 Start("B");
 cout<<"TURN: "<<turn<<endl<<endl;
 B.business(i);
 B.poor(i);
 B.developer(i);
 B.invester(i);
 B.showstatus("B");
 cout<<"CITYA   ";A.showlands();
 cout<<"CITYB   ";B.showlands();
 cout<<"CITYC   ";C.showlands();
 cout<<"CITYD   ";D.showlands();
 cout<<endl;

  for(k=0;k<B.rdraw_per_turn;k++)
 {
   if(A.c+B.c+C.c+D.c==100)
   {
       break;
   }
   B.drawhands(DECK2.drawcard());
 }


 B.showhands();
 B.build();
 B.poorskill(i);
 B.developerskill(i);
 B.investerskill(i);
 B.Endturn();
 break;

 case 2:

 Start("C");
 cout<<"TURN: "<<turn<<endl<<endl;
 C.business(i);
 C.poor(i);
 C.developer(i);
 C.invester(i);
 C.showstatus("C");
 cout<<"CITYA   ";A.showlands();
 cout<<"CITYB   ";B.showlands();
 cout<<"CITYC   ";C.showlands();
 cout<<"CITYD   ";D.showlands();
 cout<<endl;

  for(k=0;k<C.rdraw_per_turn;k++)
 {
   if(A.c+B.c+C.c+D.c==100)
   {
       break;
   }
   C.drawhands(DECK2.drawcard());
 }


 C.showhands();
 C.build();
 C.poorskill(i);
 C.developerskill(i);
 C.investerskill(i);
 C.Endturn();

 break;

 case 3:

 Start("D");
 cout<<"TURN: "<<turn<<endl<<endl;
 D.business(i);
 D.poor(i);
 D.developer(i);
 D.invester(i);
 D.showstatus("D");
 cout<<"CITYA   ";A.showlands();
 cout<<"CITYB   ";B.showlands();
 cout<<"CITYC   ";C.showlands();
 cout<<"CITYD   ";D.showlands();
 cout<<endl;
 for(k=0;k<D.rdraw_per_turn;k++)
 {
   if(A.c+B.c+C.c+D.c==100)
   {
       break;
   }
   D.drawhands(DECK2.drawcard());
 }


 D.showhands();
 D.build();
 D.poorskill(i);
 D.developerskill(i);
 D.investerskill(i);
 D.Endturn();

 break;
}
 }
 turn++;
 a=A.Last();
 b=B.Last();
 c=C.Last();
 d=D.Last();

 }while(a==0 && b==0 && c==0 && d==0);

 cout<<"A: ";A.sum();
 cout<<"B: ";B.sum();
 cout<<"C: ";C.sum();
 cout<<"D: ";D.sum();
 cout<<"The player with the highest point is winner! winner! chicken! dinnner!"<<endl;
 return 0;
}
deck::deck()
{
    d=1;
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
    if(h>52)
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
    no_fac=0;
    draw_per_turn=1;
    build_per_turn=1;
    draw_per_turn=1;
    fcost=0;
    fbuild_per_turn=0;
    fdraw_per_turn=0;
    no_of_buildings=0;
    int i;
    for(i=0;i<10;i++)
    {
        buildings[i]=0;
    }
    for(i=0;i<10;i++)
    {
        build_type[i]="NO";
    }
}
void player::drawhands(int card)
{
   c++;
if(card>0&&card<14)
    {
        hands_suit[c]="Clubs";
        hands[c]=card;
    }

    if(card>=14&&card<27)
    {
        hands[c]=card-13;
        hands_suit[c]="Daimonds";
    }

    if(card>=27 && card<40)
    {
        hands[c]=card-26;
        hands_suit[c]="Hearts";
    }

    if(card>=40 && card<53)
    {
        hands[c]=card-39;
        hands_suit[c]="Spades";
    }
}
void player::showlands()
{
    int i;
    for(i=0; i<10;i++)
    {
        cout<<build_type[i]<<"  "<<buildings[i]<<"      ";
    }
        cout<<endl<<endl;
}
void player::changehands()
{
    int i;
    for (i=0;i<13;i++)
    {
     if(hands[i]>0&&hands[i]<14)
    {
        hands_suit[i]="Clubs";
    }

    if(hands[i]>=14&&hands[i]<27)
    {
        hands[i]=hands[i]-13;
        hands_suit[i]="Daimonds";
    }

    if(hands[i]>=27 && hands[i]<40)
    {
        hands[i]=hands[i]-26;
        hands_suit[i]="Hearts";
    }

    if(hands[i]>=40 && hands[i]<53)
    {
        hands[i]=hands[i]-39;
        hands_suit[i]="Spades";
    }
    }
}
void player::showhands()
{
  int i;
  cout<<"(Postion.SuitFace)This is your hands:   ";
  for(i=0;i<c+1;i++)
  {
    if(hands[i]==0)
    {
        cout<<i<<".used   ";
    }else
    {
    cout<<i<<"."<<hands_suit[i]<<hands[i]<<"   ";
    }
    }



    cout<<endl<<endl;
  }
void player::showstatus(string a)
{
    rcost=cost+fcost;
    rbuild_per_turn=build_per_turn+fbuild_per_turn;
    rdraw_per_turn=draw_per_turn+fdraw_per_turn;
    cout<<"Player "<<a<<" your cost of building special buildings is "<<rcost<<endl
                    <<" you can build "<<rbuild_per_turn<<" buildings this turn."<<endl
                    <<" you can draw "<<rdraw_per_turn<<" cards this turn."<<endl<<endl;
}
void player::build()
  {
      int l;
      for(l=0;l<rbuild_per_turn;l++)
      {
      int cardsum[11];
      cardsum[0]=0;
      int p[10];
      int ans;
      int type;
      int i;
      int j;
      int k;
      int l;
      int h;
      int t=0;
      int s=0;
      int tol;
      int num;
      int fun;
      int answ;
     cout<<"Do you want to build?(0 for NO,1 for Yes)"<<endl;
     cin>>ans;
     if(ans==1)
     {
         cout<<"What type of buildings do you want to build? 0 for normal, 1 for special"<<endl;
         cin>>type;
         if(type==0)
         {
            cout << "How many cards do you want to use?"<<endl;
            cin >>answ;
            cout << "please type the card position you want to use"<<endl;
            for (k=0;k<answ;k++)
            {
                do
                {
                cin >> p[k];
                if (hands[p[k]]==0)
                {
                    cout << "This card is used.Please type the correct number."<<endl;
                }
                }while(hands[p[k]]==0);
                cardsum[k+1]=cardsum[k]+hands[p[k]];
            }
            for (l=0;l<answ;l++)
            {
                hands[p[l]]=0;
                hands_suit[p[l]]=="empty";
            }
            switch (cardsum[k])
            {
                case 0:
                cout << "you are idiot"<<endl;
                break;
                case 1:
                buildings[no_of_buildings]=1;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 1"<<endl;
                no_of_buildings++;
                break;
                case 2:
                buildings[no_of_buildings]=2;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 2" <<endl;
                no_of_buildings++;
                break;
                case 3:
                buildings[no_of_buildings]=3;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 3"<<endl;
                no_of_buildings++;
                break;
                case 4:
                buildings[no_of_buildings]=4;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 4"<<endl;
                no_of_buildings++;
                break;
                case 5:
                buildings[no_of_buildings]=5;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 5"<<endl;
                no_of_buildings++;
                break;
                case 6:
                buildings[no_of_buildings]=6;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 6"<<endl;
                no_of_buildings++;
                break;
                case 7:
                buildings[no_of_buildings]=7;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 7"<<endl;
                no_of_buildings++;
                break;
                case 8:
                buildings[no_of_buildings]=8;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 8"<<endl;
                no_of_buildings++;
                break;
                case 9:
                buildings[no_of_buildings]=9;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 9"<<endl;
                no_of_buildings++;
                break;
                default:
                buildings[no_of_buildings]=10;
                build_type[no_of_buildings]="Normal";
                cout << "you build a normal house in position" << no_of_buildings <<"its point is 10"<<endl;
                no_of_buildings++;
                break;
            }
         }


     if(type==1)
     {
         cout<<"How many cards do you want to use ? (1 or 2)" <<endl;
         cin>>num;
         if(num==1)
         {
              do
             {
             cout<<"Which cards do you want to use? Type the position."<<endl;
             cin>>i;
             if(hands[i]==0)
             {
              cout<<"Position "<<i<<" has no card!! PLS type again."<<endl;
              t++;
             }
             if(hands[i]<rcost)
             {
               cout<<"The value of the card is not enough to build special building!!"<<endl;
               t++;
             }
             if (hands[i]!=0 && hands[i]>=rcost)
             {
                 t=3;
             }
             }while(t<3);
             hands[i]=0;
             hands_suit[i]="empty";
         }
         if(num==2)
         {
             do
             {
             cout<<"Which cards do you want to use? Type two positions."<<endl;
             cin>>i>>j;

             if(hands[i]==0)
             {
              cout<<"Position "<<i<<" has no card!! PLS type again."<<endl;
              s++;
             }
             if(hands[j]==0)
             {
              cout<<"Position "<<j<<" has no card!! PLS type again."<<endl;
              s++;
             }

             if(hands_suit[i]!=hands_suit[j])
             {
               cout<<"Two cards should have same suits!!"<<endl;
               s++;
             }

             tol=hands[i]+hands[j];
             if(tol<rcost)
             {
               cout<<"The value of the cards are not enough to build special building!!"<<endl;
               s++;
             }
            if (hands[i]!=0 && tol>=rcost && hands[j]!=0 && hands_suit[i]==hands_suit[j])
            {
                s=6;
            }
             }while(s<6);
         hands[i]=0;
         hands[j]=0;
         hands_suit[i]="empty";
         hands_suit[j]="empty";
         }

         cout << "which special house do you want to build? (1 for office 2 for mansion 3 for factory 4 for bank) "<<endl ;
         cin>>fun;
         switch(fun)
         {
         case 0:
             cout << "Wrong ans nothing is built"<<endl;
             break;
         case 1:
             build_per_turn++;
             buildings[no_of_buildings]=10;
             build_type[no_of_buildings]="Office";
             cout<<"You have built a "<<10<<"  points "<<"Office."<<endl;
             break;
         case 2 :
                          do
             {
             cout<<"You can choose one more card to increase the value of mansion. Type the position."<<endl;
             cin>>k;
             if(hands[k]==0)
             {
              cout<<"Position "<<k<<" has no card!! PLS type again."<<endl;
             }
             }while(hands[k]==0);
             buildings[no_of_buildings]=10+hands[k];
             build_type[no_of_buildings]="Mansion";
             cout<<"You have built a "<<buildings[no_of_buildings]<<"  points "<<"Mansion."<<endl;
             hands[k]=0;
             hands_suit[k]="empty";
             break;
         case 3 :
             no_fac++;
             buildings[no_of_buildings]=10;
             build_type[no_of_buildings]="Factory";
             cout<<"You have built a "<<10<<"  points "<<"Factory."<<endl;
             break;
         case 4:
             cost--;
             buildings[no_of_buildings]=10;
             build_type[no_of_buildings]="Bank";
             cout<<"You have built a "<<10<<"  points "<<"Bank."<<endl;

            break;
         }
     }
     no_of_buildings++;
  }
  }
  }
  void player::poor(int i)
  {
        if(i==0)
    {
        fdraw_per_turn++;
        cout<<"This turn you are Poor."<<endl<<endl;
    }
}
void player::poorskill(int i)
{   int answer,p,pos;
    if (i==0)
    {
     cout <<"Do you want to use skill?0 for no 1 for yes"<<endl;
    cin >>answer;
    if (answer==1)
    {
        cout <<"Please type the  position of Spades 13"<<endl;
        cin >>p;
        if (hands_suit[p]!="Spades"||hands[p]!=13)
        {
            cout << "You lied.You are idiot."<<endl;
        }
        else
        {
         cout<<"You can choose a building to double the value."<<endl;
         cin>>pos;
         buildings[pos]=buildings[pos]+buildings[pos];
         cout <<"This building's point is "<<buildings[pos]<<endl;
        }
        hands_suit[p]="empty";
        hands[p]=0;
}
    }

}

  void player::business(int i)
  {

            if(i==1)
      {
        fcost--;
        fcost--;
        cout<<"This turn you are Businessman."<<endl<<endl;
      }
  }
  void player::developer(int i)
  {
            if(i==2)
      {
        fbuild_per_turn++;
        cout<<"This turn you are Developer."<<endl<<endl;
      }

  }
  void player::developerskill(int i)
  {
      int answer,j,k,p,fun,tol;
      if(i==2)
      {
          cout << "Do you want to use skill? 0 for no 1 for yes"<<endl;
          cin >> answer;
          if (answer==1)
          {
              do
             {
             cout<<"Which two cards do you want to use? Type two positions."<<endl;
             cin>>i>>j;

             if(hands[i]==0)
             {
              cout<<"Position "<<i<<" has no card!! PLS type again."<<endl;
             }
             if(hands[j]==0)
             {
              cout<<"Position "<<j<<" has no card!! PLS type again."<<endl;
             }
             tol=hands[i]+hands[j];
             if(tol<10)
             {
               cout<<"The value of the cards are not enough to build special building!!"<<endl;
             }

             }while(hands[i]==0 || tol<10 || hands[j]==0);
             hands[i]=0;
             hands[j]=0;
             hands_suit[i]="empty";
             hands_suit[j]="empty";
             cout << "which special house do you want to build? (1 for office 2 for mansion 3 for factory 4 for bank) "<<endl ;
         cin>>fun;
             cout <<"Where do you want to change type the position"<<endl;
             cin >> p;
         switch(fun)
         {
         default:
             cout << "you are idiot"<<endl;
             break;
         case 1:
             build_per_turn++;
             buildings[p]=10;
             build_type[p]="Office";
             cout<<"You have built a "<<10<<"  points "<<"Office."<<endl;
             break;
         case 2 :
                          do
             {
             cout<<"You can choose one more card to increase the value of mansion. Type the position."<<endl;
             cin>>k;
             if(hands[k]==0)
             {
              cout<<"Position "<<k<<" has no card!! PLS type again."<<endl;
             }
             }while(hands[k]==0);
             buildings[p]=10+hands[k];
             build_type[p]="Mansion";
             cout<<"You have built a "<<buildings[p]<<"  points "<<"Mansion."<<endl;
             hands[k]=0;
             hands_suit[k]="empty";
             break;
         case 3 :
             no_fac++;
             buildings[p]=10;
             build_type[p]="Factory";
             cout<<"You have built a "<<10<<"  points "<<"Factory."<<endl;
             break;
         case 4:
             cost--;
             buildings[p]=10;
             build_type[p]="Bank";
             cout<<"You have built a "<<10<<"  points "<<"Bank."<<endl;
             break;
         }
        }
      }
  }
  void player::invester(int i)
  {
      if(i==3)
      {
        cout<<"This turn you are invester."<<endl<<endl;
      }
  }
  void player::investerskill(int i)
  {
      int answer,j,p,t=0;
      if (i==3)
      {
          cout << "Do you want to use skill?0 for no 1 for yes"<<endl;
          cin >> answer;
          if (answer==1)
          {
              do{
                    cout <<"Which cards do you want to use? Type the position."<<endl;
                    cin >> j;
                    if (hands[j]==0)
                    {
                        cout << "You are idiot.Type the correct one."<<endl;
                    }
                }while (hands[j]==0);

              do
              {
                  cout <<"Please type the mansion's position"<<endl;
                  cin >> p;
                  if (build_type[p]!="Mansion")
                  {
                       cout << "You are idiot.Type the correct one."<<endl;
                       t++;
                  }
              }while(t<3&&build_type[p]!="Mansion");
              if (build_type[p]=="Mansion")
              {
                  buildings[p]=buildings[p]+hands[j];
                  hands[j]=0;
                  hands_suit[j]="empty";
              }
          }
      }
  }
  int player::Last()
  {
      int flag=0;
      if(no_of_buildings>=10)
      {
          flag=1;
      }
      return flag;
  }
  int player::sum()
  {
    int i;
    for(i=0;i<10;i++)
    {
     point=point+buildings[i];
    }
    point=point+(no_fac*no_of_buildings);
    cout<<point<<endl;
    return point;
  }
  void player::Endturn()
  {
    int i;
    fcost=0;
    fbuild_per_turn=0;
    fdraw_per_turn=0;
    cout<<"PLS TYPE 0 TO END YOUR TURN"<<endl;
    cin>>i;
    if(i==0)
    {
     system("cls");
    }
    system("cls");
  }
  void Start(string p)
  {
      int i;
      cout<<"PLAYER "<<p<<",to start your turn enter any numbers"<<endl;
      cin>>i;
      if(i==0)
      {

      }
  }
