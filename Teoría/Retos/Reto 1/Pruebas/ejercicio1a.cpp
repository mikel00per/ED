 
#include<iostream>

using namespace std;

int main(){
    
    int n=100,j, i=2, x=0, sb=0;		
    do{
            j=1;	
            sb=0;
            while (j <= n){		
                    j=j*2;		
                    x++;	
                    sb++;
            }   
            i++;
            cout << "Vuelta (n): " << i << endl;
            cout << "Subvueltas: " << sb << endl << endl;
    }while (i<=n);

    cout << endl << "Subueltas total: " << x << endl;
    
return 0;
}
