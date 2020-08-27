#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int a;
int b;


// Encryption function
string encryption(string message){
    string output="";

    for(int i=0;i<message.length();i++){
    if(message[i]!=' '){

    output+= (char)((((a*message[i]-'A')+b)%26) +'A');
    }
    else
    output+=message[i];
    }

    return output;


}

//Multiplicative Inverse
int multiplicativeinverse(int a){
    int inv;
    for(int i=0;i<26;i++){
        if((a*i)%26==1){
            inv=i;
            break;

        }
    }
    return inv;
}

//GCD
int gcd(int x,int y){
    
    
    if(y==0)return x;
    else{
       
        return gcd(y,x%y);
        
    }
   
}

//Decryption Function
string decryption(string output,int inv){
    string input="";
    

    if(gcd(26,a)==1){
        
    for(int i=0;i<output.length();i++){
        input+= char(((inv*(output[i]-b-'A'))%26 +'A'));

    }}
    return input;

}


int main(){
    cout<<"Enter the message:"<<endl;
    string message;
    getline(cin, message);
    cout<<"Enter a:"<<endl;
    cin>>a;
    cout<<"Enter b:"<<endl;
    cin>> b;
   
    cout<<"Multiplicative Inverse="<<multiplicativeinverse(a)<<endl;
    cout<< "encrypted message is:"<<endl;
    string k= encryption(message);
    
    cout<<k<<endl;
    cout<<"Decrypted message is:"<<endl;
        
    cout<<decryption(k,multiplicativeinverse(a));

  return 0;
}