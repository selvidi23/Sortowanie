#include <iostream>


using namespace std;
int wb(int x)
{
    if(x<0)
        return -x;
    else return x;
}
int part(int tab[],int p, int l)
{
    int x = tab[p];
    int i = p, j = l, a;
    while(true)
    {
        while(tab[j] > x)
            j--;
        while(tab[i] < x)
            i++;
        if (i < j)
        {
            a = tab[i];
            tab[i] = tab[j];
            tab[j] = a;
            i++;
            j--;
        }
        else return j;
    }
}
void qs(int tab[], int p, int l)
{

    int q;

    if(p < l)
    {
        q = part(tab,p,l);
        qs(tab,p,q);
        qs(tab,q+1,l);
    }
}
int main()
{
    int iloscwejsc,spr;
    spr = 1000000;


    cin >> iloscwejsc;

    for(;iloscwejsc >= 1000000;)
    {
        cin >> iloscwejsc;
    }
    int tab[iloscwejsc];



    for(int i=0;i<iloscwejsc;i++)
    {
        cin >> tab[i];
    }
    qs(tab,0,iloscwejsc-1);
    for (int i = 0; i < iloscwejsc-1; i++)
    {
        if ((tab[i+1] - tab[i]) < spr)
        {
            spr = tab[i+1] - tab[i];
        }
    }

    cout << wb(spr) << endl;
    for (int i = 0; i < iloscwejsc-1;i++)
    {
        if ((tab[i+1] - tab[i]) == spr)
        {
            cout << tab[i] << " " << tab[i+1] << endl;
        }
    }

    return 0;
}