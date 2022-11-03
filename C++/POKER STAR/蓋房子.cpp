cout << "請問您要蓋房子嗎?";
cin >> buildanswer;
if (buildanswer=Y)
{
    cout << "請問您想蓋特殊房還是普通房??特殊房請輸入1，普通房請輸入2。";
    cin >> ha ;
    while (ha==1)
    {
        cout << "請您輸入兩張牌的位置。";
        for (a=0 , a<2 , a++)
        {
            cin cpo ;
            cpr[a+1]=cpr[a]+cardprice[a];
            cf[a]=cff[a];
        }
        if (cpr[a+1]!=10 || cf[1]!=cf[2])
        {
            cout << "您出的牌不符合條件";
        }
        if (cpr[a+1]==10 && cf[1]==cf[2])
        {
            cout << "請您輸入您想要蓋的特殊房";
            cin >> specialhouse ;
            switch (specialhouse)
            {
            case 2 :
            hpo[n]=2;
            hpr[n]=10;
            n++;
            break;
            case 3 :
            hpo[n]=3;
            hpr[n]=10;
            n++;
            break;
            case 4 :
            hpo[n]=4;
            hpr[n]=10;
            n++;
            break;
            case 5 :
            hpo[n]=5;
            hpr[n]=10;
            n++;
            break;
            default:
            cout << "您輸入的是錯誤的數字。"
            }
        }
    }
    if (ha==2)
    {
     cout << "請您輸入你想出的牌的數量:";
    cin >> cardnum;
    cout << "請您輸入想出的牌的位置:";
    for (a=0 , a<cardnum , a++)
    {
        cin >> cardposition ;
        cp[a+1]=cp[a]+cardprice[a];
        cardprice[a]=0;
    }
    switch (cp[a+1])
       {
       case 1:
        hpo[n]=1;
        hpr[n]=1;
        n++;
        break;
        case 2:
        hpo[n]=1;
        hpr[n]=2;
        n++;
        break;
        case 3:
        hpo[n]=1;
        hpr[n]=3;
        n++;
        break;
        case 4:
        hpo[n]=1;
        hpr[n]=4;
        n++;
        break;
        case 5:
        hpo[n]=1;
        hpr[n]=5;
        n++;
        break;
        case 6:
        hpo[n]=1;
        hpr[n]=6;
        n++;
        break;
        case 7:
        hpo[n]=1;
        hpr[n]=7;
        n++;
        break;
        case 8:
        hpo[n]=1;
        hpr[n]=8;
        n++;
        break;
        case 9:
        hpo[n]=1;
        hpr[n]=9;
        n++;
        break;
        default:
        hpo[n]=1;
        hpr[n]=10;
        n++;
        break;
       }
    }
}
