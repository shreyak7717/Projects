#include<iostream>
#include<string>
using namespace std;
class RPC
{
    private:
    string input1, input2;
    int x,score1=0,score2=0;
    string i1,i2;
    public:
    RPC(int rounds)
    {
        cout<<"Enter the no. of rounds";
        x=rounds;
        cin>>x;
        cout<< "The no. of rounds the player wants to play is "<<x<<"\n";
    }
    void game()
    {
        for(int i =0; i<x;i++)
        {
            cout<<"Enter input of player 1\n";
            cin>>i1;
            cout<<"Enter input of player 2\n";
            cin>>i2;    
            input1=i1;
            input2=i2;
        if (input1=="Rock"&&input2=="Rock")
        {
            cout<<"Tie\n";
        }
        else if (input1=="Rock"&&input2=="Paper")
        {
            cout<<"Player 2 wins\n";score2++;
        }
         else if (input1=="Rock"&&input2=="Scissor")
        {
            cout<<"Player 1 wins\n";score1++;
        }
         else if (input1=="Scissor"&&input2=="Paper")
        {
            cout<<"Player 1 wins\n";score1++;
        }
        else if (input1=="Scissor"&&input2=="Scissor")
        {
            cout<<"Tie\n";
        }
         else if (input1=="Scissor"&&input2=="Rock")
        {
            cout<<"Player 2 wins\n";score2++;
        }
         else if (input1=="Paper"&&input2=="Paper")
        {
            cout<<"Tie\n";
        }
        else if (input1=="Paper"&&input2=="Scissor")
        {
            cout<<"Player 1 wins\n";score1++;
        }
        else if (input1=="Paper"&&input2=="Rock")
        {
            cout<<"Player 2 wins\n";score2++;
        }
        else{
            cout<<"WRONG ENTRY";
        }
    }cout<<"Score of player 1 and player 2 is "<<score1<<" and "<<score2<<" respectively"<<"\n";}
    
};
int main()
{
    RPC obj(0);
    obj.game();

}