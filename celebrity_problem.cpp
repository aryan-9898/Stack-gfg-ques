 private:
    bool knows(vector<vector<int> >& M,int a,int b){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
            
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        
        for(int i=0;i<n;i++){
            s.push(i);
        }
        // step 2- get 2 elements and compare them
        while(s.size()>1){
            int a=s.top();
            s.pop();
            
            int b=s.top();
            s.pop();
            
            if(knows(M,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int candidate=s.top();
        //step.3: single element in stock is potential celebrity.hence verify
        bool rowcheck=false;
        int zerocount=0;
        
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0){
                zerocount++;
            }
        }
        
        //all zero
        if(zerocount==n){
            rowcheck=true;
        }
        
        bool colcheck=false;
        int onecount=0;
        
        for(int i=0;i<n;i++){
            if(M[i][candidate]==1){
                onecount++;
            }
        }
        
        //all zero
        if(onecount==n-1){
            colcheck=true;
        }
        
        if(rowcheck==true && colcheck==true){
            return candidate;
            
        }
        else{
            return -1;
        }
        
    }
