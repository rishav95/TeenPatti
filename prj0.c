#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int kiker,temp,playa,n,pl[17][3][2];
void card_print(int card)
{
    switch (card)
    {
        case 14:
            printf("Ace");
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 6:
            printf("6");
            break;
        case 7:
            printf("7");
            break;
        case 8:
            printf("8");
            break;
        case 9:
            printf("9");
            break;
        case 10:
            printf("10");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        default:
            printf("Not Valid");
            break;
    }
};
void suit_print(int suit)
{
    switch(suit)
    {
        case 1:
            printf(" of Spades\t%c","0x03");
            break;
        case 2:
            printf(" of Clubs\t%c",5);
            break;
        case 3:
            printf(" of Hearts\t%c",3);
            break;
        case 4:
            printf(" of Diamonds\t%c",4);
            break;
        default:
            printf("Not valid");
            break;
    }
};
int check_dedge(int dedge[17])
{
    int high,i;
    high=dedge[0];
    playa=0;
    for(i=1;i<n;i++)
    {
        if(dedge[i]>high)
        {
            high=dedge[i];
            playa=i;
        }
    }
    if(high<=14)
    {
        for(i=0;i<n;i++)
        {
            if(i==playa)
                continue;
            if(high==dedge[i])
            {
                if(pl[i][1][0]>pl[playa][1][0])
                {
                    high=pl[i][1][0];
                    playa=i;
                }
                else
                    high=pl[playa][1][0];
            }
        }
    }
    return high;
};
int is_run(int plhand[3][2])
{
    int i,j,k;
    i=plhand[0][0];
    j=plhand[1][0];
    k=plhand[2][0];
        if(i==12&&j==13&&k==14)
            return 3;
        else if(j==(i+1)&&k==(j+1))
            return 0;
        else if(i==2&&j==3&&k==14)
            return 2;
        else return 1;
};
int is_color(int plhand[3][2])
{
    if(plhand[0][1]==plhand[1][1]&&plhand[0][1]==plhand[2][1])
        return 0;
    else
        return 1;
};
 void hand_sort(int plhand[3][2])
{
        int j,k;
        for(j=0;j<=2;j++)
        {
            for(k=j+1;k<=2;k++)
                if(plhand[j][0]>plhand[k][0])
            {
                temp=plhand[j][0];
                plhand[j][0]=plhand[k][0];
                plhand[k][0]=temp;
                temp=plhand[j][1];
                plhand[j][1]=plhand[k][1];
                plhand[k][1]=temp;
            }
        }
};
void shuffle(int deck[52][2])
{
    int i,c,temp;
     for(i=0;i<52;i++)
    {

        c=rand()%52;
        temp = deck[i][0];
        deck[i][0]=deck[c][0];
        deck[c][0]=temp;
        temp = deck[i][1];
        deck[i][1]=deck[c][1];
        deck[c][1]=temp;
    }
};
int is_trial(int plhand[3][2])
{
    if(plhand[0][0]==plhand[1][0]&&plhand[0][0]==plhand[2][0])
        return 0;
    else if(plhand[0][0]==plhand[1][0]&&plhand[0][0]!=plhand[2][0])
        return 1;
    else if(plhand[0][0]==plhand[2][0]&&plhand[0][0]!=plhand[1][0])
        return 1;
    else if(plhand[1][0]==plhand[2][0]&&plhand[1][0]!=plhand[0][0])
        return 1;
    else
        return 2;
};
void draw(int deck[52][2])
{
    int i;
    for(i=0;i<51;i++)
    {
    deck[i][0]=deck[i+1][0];
    deck[i][1]=deck[i+1][1];
    }
};
int check_pair(int plhand[3][2])
{
    int dedge;
    if(plhand[0][0]==plhand[1][0])
        {
            dedge=plhand[0][0];
            kiker=plhand[2][0];
        }
    else if(plhand[0][0]==plhand[2][0])
        {
            dedge=plhand[0][0];
            kiker=plhand[1][0];
        }
    else if(plhand[1][0]==plhand[2][0])
        {
            dedge=plhand[1][0];
            kiker=plhand[0][0];
        }
    else
        dedge=0;
    return dedge;
};
void main()
{
    int z,t,s,c,i,j,k,dedge[17],deck[52][2],cardval,suit,kik[17],highest;
    srand(time(NULL));
    printf("Enter Number of players : (Keep in mind that this game can take a maximum of 17 players...!!!)");
    scanf("%d",&n);
    for(i=0;i<52;i++)
    {
    switch(i%13)
    {
    case 0:
        cardval=14;
        break;
    case 1:
        cardval=2;
        break;
    case 2:
        cardval=3;
        break;
    case 3:
        cardval=4;
        break;
    case 4:
        cardval=5;
        break;
    case 5:
        cardval=6;
        break;
    case 6:
        cardval=7;
        break;
    case 7:
        cardval=8;
        break;
    case 8:
        cardval=9;
        break;
    case 9:
        cardval=10;
        break;
    case 10:
        cardval=11;
        break;
    case 11:
        cardval=12;
        break;
    case 12:
        cardval=13;
        break;
    default:
        cardval=0;
        break;
    }
    deck[i][0]=cardval;
    }
    for(i=0;i<52;i++)
    {
    if(i<13)
        suit=1;
    if(i>=13&&i<26)
        suit=2;
    if(i>=26&&i<39)
        suit=3;
    if(i>=39&&i<52)
        suit =4;
    deck[i][1]=suit;
    }
    shuffle(deck);
     for(t=0;t<3;t++)
    {
        for(i=0;i<n;i++)
        {
            pl[i][t][0]=deck[0][0];
            pl[i][t][1]=deck[0][1];
            draw(deck);
        }
    }
        for(s=0;s<n;s++)
        {
        printf("\n\n\nCards of player %d are :\n",s+1);
        hand_sort(pl[s]);
        for(i=0;i<3;i++)
        {
            card_print(pl[s][i][0]);
            suit_print(pl[s][i][1]);
            printf("\n");
        }
        if(is_trial(pl[s])==0)
            dedge[s]=70+pl[s][0][0];
        if(is_trial(pl[s])==1)
            dedge[s]=13+check_pair(pl[s]);
        kik[s]=kiker;
        if(is_trial(pl[s])==2)
        {
            if(is_run(pl[s])==0&&is_color(pl[s])==1)
                dedge[s]=24+pl[s][2][0];
            if(is_run(pl[s])==3&&is_color(pl[s])==1)
                dedge[s]=26+pl[s][2][0];
            if(is_run(pl[s])==2&&is_color(pl[s])==1)
                dedge[s]=25+pl[s][2][0];
            if(is_run(pl[s])==1&&is_color(pl[s])==0)
                dedge[s]=39+pl[s][2][0];
            if(is_run(pl[s])==0&&is_color(pl[s])==0)
                dedge[s]=50+pl[s][2][0];
            if(is_run(pl[s])==3&&is_color(pl[s])==0)
                dedge[s]=52+pl[s][2][0];
            if(is_run(pl[s])==2&&is_color(pl[s])==0)
                dedge[s]=51+pl[s][2][0];
            if(is_run(pl[s])==1&&is_color(pl[s])==1)
                dedge[s]=pl[s][2][0];
        }
        }
    highest=check_dedge(dedge);
    printf("\n");
    if(highest>=1&&highest<=14)
    {
        printf("player %d wins with ",playa+1);
        card_print(highest);
        printf(" high Card");
    }
    if(highest>=15&&highest<=27)
        {
            c=dedge[playa]%15;
            printf("player %d wins with a pair of ",playa+1);
            card_print(c+2);
            printf("s and ");
            card_print(kik[playa]);
            printf(" kiker");
        }
    if(highest>=28&&highest<=40)
    {
        c=dedge[playa]%26;
        printf("player %d wins with a run from ",playa+1);
        card_print(c);
        printf(" to ");
        if(pl[playa][0][0]==2&&pl[playa][1][0]==3&&pl[playa][2][0]==14)
            card_print(3);
        else if(pl[playa][0][0]==12&&pl[playa][1][0]==13&&pl[playa][2][0]==14)
            card_print(13);
        else
            card_print(c+2);
    }
    if(highest>=41&&highest<=53)
    {
        c=dedge[playa]%39;
        z=pl[playa][0][1];
        printf("player %d wins with a flush",playa+1);
        suit_print(z);
        printf(" and ");
        card_print(c);
        printf(" high card");
    }
    if(highest>=54&&highest<=66)
    {
        c=dedge[playa]%52;
        printf("Player %d wins with a double run from ",playa+1);
        card_print(c);
        printf("to ");
        if(pl[playa][0][0]==2&&pl[playa][1][0]==3&&pl[playa][2][0]==14)
        {
            card_print(3);
        }
        else if(pl[playa][0][0]==12&&pl[playa][1][0]==13&&pl[playa][2][0]==14)
            card_print(13);
        else
        card_print(c+2);
    }
    if(highest>=70)
    {
        c=dedge[playa]%70;
        printf("player %d wins with a trial of ",playa+1);
        card_print(c);
    }
    getch();
}
