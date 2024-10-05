cin>>maxNum;
    for (int i = 1; i<n; i++)
        cin >> num;
        maxNum=larger(num,maxNum);
    cout <<"The largest number is "<< maxNum;
 return 0;
}