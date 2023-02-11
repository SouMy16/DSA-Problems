class Solution {
public:
    int countCollisions(string &str) {
    	int n=str.size(), i=0;
 
    	while(i<n&&str[i]=='L'){
         	i++;
    	}
 
    	if(i==n) {return 0;}
 
    	int j=n-1;
 
    	while(str[j]=='R' && j > i)
        {
        	j--;
    	}
 
    	if(i==j) {return 0;}
 
    	n=j-i+1;
    	int rlPairs=0, sNum=0;
    	for(int k=i; k<=j; k++) {
        	if(str[k]=='S'){
          	sNum++;
        	}
     	}
  
    	return n-sNum;
	}

};