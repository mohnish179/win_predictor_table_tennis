#include <iostream>

#include<cmath>
using namespace std;

float factorial(int r, int n)
{
    double x=1,y=1,z=1;

    for(int i=1;i<=n;i++)
    {
        x*=i;
    }
    for(int i=1;i<=r;i++)
    {
        y*=i;
    }
    for(int i=1;i<=n-r;i++)
    {
        z*=i;
    }
    return x/(y*z);
}
float serving_prob(int n,int tracker)
{
    float x;

    if(tracker == 1||tracker==0)
    {
        x=pow(0.6,(n/2)+1);
        x*=pow(0.4,n/2);


    }
    else
    {
        x=pow(0.6,(n/2));
        x*=pow(0.4,(n/2)+1);
    }

    return x;

}

int main() {

    string A,B;
    int a_match=0,b_match=0;
    int a_pt=0,b_pt=0;
    float flag;
    int cur;
    cout<<"Input the player names "<<endl;
    cin>>A;
    cin>>B;

    int tracker=0;

    for(int j=0;j<5;j++) {

        cout<<"Welcome to the game no. "<<j+1<<endl;

        a_pt=0;b_pt=0;

        while (a_pt < 11 && b_pt < 11) {


            if (a_pt == 10 && b_pt == 10)
                break;

            float ans = 0;
            cout << "who won the point? 1 or 2 ";
            tracker++;
            cin >> cur;
            if (cur == 1)
                a_pt += 1;
            else
                b_pt += 1;

            if (a_pt > 10 || b_pt >10)
                break;



            for (int i = 0; i < 11 - b_pt; i++) {

                ans += factorial(i, 10 + i - a_pt) * pow(0.5, 11 - a_pt) * pow(0.5, i);
            }

            if (a_pt > b_pt)
                cout << A << " has higher probability of winning with percentage of " << ans * 100 << endl;
            else if (a_pt == b_pt)
                cout << "Both have equal probability of 50 % to win" << endl;
            else
                cout << B << " has higher probability of winning with percentage of " << (1 - ans) * 100 << endl;

            flag=ans;

        }

        if (a_pt == 10 && b_pt == 10) {
            cout << "DEUCE" << endl;
            while (a_pt != 12 && b_pt != 12) {


                cout << "who won the point? 1 or 2 " << endl;
                cin >> cur;
                if (cur == 1) {

                    if (b_pt == 11) {
                        b_pt--;
                        cout << "DEUCE" << endl;
                    }
                    else {
                        a_pt += 1;
                        cout<<"Advantage Taken "<<endl;
                    }
                } else {

                    if (a_pt == 11) {
                        a_pt--;
                        cout << "DEUCE" << endl;
                    }
                    else {
                        b_pt += 1;
                        cout<<"Advantage Taken "<<endl;
                    }
                }

                float ans = 0;

                for (int i = 0; i < 12 - b_pt; i++) {
                    ans += factorial(i, 11 + i - a_pt) * pow(0.5, 12 - a_pt) * pow(0.5, i);



                }
if(ans<1) {
    if (a_pt > b_pt)
        cout << A << " has higher probability of winning with percentage of " << ans * 100 << endl;
    else if (a_pt == b_pt)
        cout << "Both have equal probability of 50 % to win" << endl;
    else
        cout << B << " has higher probability of winning with percentage of " << (1 - ans) * 100 << endl;

                flag=ans;}

            }//while
        }//if
        if (a_pt > b_pt) {
            cout << " GAME OVER and the winner is " << A << " with " << flag * 100 << endl;
            a_match++;
        }
        else {
            cout << " GAME OVER and the winner is " << B << " with " << flag * 100 << endl;
            b_match++;
        }

        float ans = 0;

        for (int i = 0; i < 6 - b_match; i++) {
            ans += factorial(i, 5 + i - a_match) * pow(0.5, 6 - a_match) * pow(0.5, i);

        }

        if (a_match > b_match)
            cout << A << " has higher probability of winning the whole match with percentage of " << ans * 100 << endl;
        else if (a_match == b_match)
            cout << "Both have equal probability of 50 % to win the whole match " << endl;
        else
            cout << B << " has higher probability of winning the whole match with percentage of " << (1 - ans) * 100 << endl;


    }




    return 0;
}
