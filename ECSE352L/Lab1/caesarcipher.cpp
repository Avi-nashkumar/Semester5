#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

string encryption(string text,int key){
    int len_text= text.length();
    string output="";
    for (int i = 0; i < len_text; i++)
    {
        if(isupper(text[i])){
            output+=char(int(text[i]+key-65)%26 +65);

        }
        else
        {
            output+= char(int(text[i]+key-97)%26 +97);
        }
        
        
    }
    return output;
    
}
string decryption(string text,int key){
    int len_text= text.length();
    string input="";
    for (int i = 0; i < len_text; i++)
    {
        if(isupper(encryption(text,key)[i])){
            input+=char(int(encryption(text,key)[i]-key-65)%26 +65);

        }
        else
        {
            input+= char(int(encryption(text,key)[i]-key-97)%26 +97);
        }
        
        
    }
    return input;
    
}

int main(){
    cout<<"Enter the message:"<<endl;
    string text;
    getline(cin, text);
    int size;
    cin>>size;
    cout<<"1 for encryption and 2 for decryption"<<endl;
    int i;
    
    for( i=1;i<=2;i++){
        cin>>i;
        cout<<"\n";
        
        
        if(i==1){
             cout<<encryption(text,size);
        }
        if(i==2) cout<<decryption(text,size);



    }


    




    return 0;
}