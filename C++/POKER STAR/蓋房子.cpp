cout << "�аݱz�n�\�Фl��?";
cin >> buildanswer;
if (buildanswer=Y)
{
    cout << "�аݱz�Q�\�S����٬O���q��??�S��нп�J1�A���q�нп�J2�C";
    cin >> ha ;
    while (ha==1)
    {
        cout << "�бz��J��i�P����m�C";
        for (a=0 , a<2 , a++)
        {
            cin cpo ;
            cpr[a+1]=cpr[a]+cardprice[a];
            cf[a]=cff[a];
        }
        if (cpr[a+1]!=10 || cf[1]!=cf[2])
        {
            cout << "�z�X���P���ŦX����";
        }
        if (cpr[a+1]==10 && cf[1]==cf[2])
        {
            cout << "�бz��J�z�Q�n�\���S���";
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
            cout << "�z��J���O���~���Ʀr�C"
            }
        }
    }
    if (ha==2)
    {
     cout << "�бz��J�A�Q�X���P���ƶq:";
    cin >> cardnum;
    cout << "�бz��J�Q�X���P����m:";
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
