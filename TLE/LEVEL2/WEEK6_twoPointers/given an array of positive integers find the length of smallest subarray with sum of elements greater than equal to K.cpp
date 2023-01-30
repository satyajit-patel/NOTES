int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    int k;
    cin>>k;
    int i=0,j=0;
    int ans=inf64,sum=0;
    while(j<n)
    {
        //including the jth element in our good segment 
        sum+=a[j];
        
        while(i<=j && sum>=k) //i to j -> good 
        //it will break when sum<k
        {
            //update answer 
            ans=min(ans,j-i+1);
            
            //move left pointer 1 ahead 
            //do remove ith element and reduce the sum till the segment is again good 
            sum-=a[i];
            i++;
        }
        //move j pointer as usual 
        j++;
    }
    
    cout<<ans<<endl;