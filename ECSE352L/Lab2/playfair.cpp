#include<iostream>
#include<vector>
using namespace std;
 

 //Matrix of 5*5 containing all characters except J
const char encoder[5][5]={{'A','B','C','D','E'},
                          {'F','G','H','I','K'},
                          {'L','M','N','O','P'},
                          {'Q','R','S','T','U'},
                          {'V','W','X','Y','Z'}};
 
 //Function to get the position of any character in the matrix
void get_pos(char p, int& r, int& c)
{
    if (p < 'J')
    {
        r = (p - 65) / 5;
        c = (p - 65) % 5;
    }
    else if (p > 'J')
    {
        r = (p - 66) / 5;
        c = (p - 66) % 5;
    }
    return;
}
 //First condition: If the characters belong to the same row
void same_row(int r, vector<char>& code, int c1, int c2)
{
    code.push_back(encoder[r][(c1 + 1) % 5]);
    code.push_back(encoder[r][(c2 + 1) % 5]);
    return;
}
 //Second condition: If the characters belong to the same column
void same_column(int c, vector<char>& code, int r1, int r2)
{
    code.push_back(encoder[(r1 + 1) % 5][c]);
    code.push_back(encoder[(r2 + 1) % 5][c]);
    return;
}
 //Third condition: If the characters belong to the diffrent row and column
void diff_col_row(int r1, int c1, vector<char>& code, int r2, int c2)
{
    code.push_back(encoder[r1][c2]);
    code.push_back(encoder[r2][c1]);
    return;
}
// Encryption function 
void encode(vector<char> msgx, int len)
{
    vector<char> code;
    int i = 0, j = 0;
    int r1, c1, r2, c2;
    while (i < len)
    {
        get_pos(msgx[i], r1, c1);
          i++;
        get_pos(msgx[i], r2, c2);
        if (r1 == r2)
        {
            same_row(r1, code, c1, c2);
        }
        else if (c1 == c2)
        {
            same_column(c1, code, r1, r2);
        }
        else
        {
            diff_col_row(r1, c1, code, r2, c2);
        }
        i++;
    }
    cout<<"\nCODE: ";
    for (j = 0;j < code.size();j++)
    {
        cout<<code[j];
    }
    return;
}
// converting lowercase input to upper case
void get_input(vector<char>& a)
{
    char c;
    while (1)
    {
        c = getchar();
        if (c >= 97 && c <= 122)
        c=c-32;
        if (c == '\n')
            break;
        else if (c==' ')
            continue;
        else if (c == 'J')
        a.push_back('I');
        a.push_back(c);
    }
    return;
}
 // converting to digraph by adding 'Z' if necessary
void convert_string(vector<char>& msg, vector<char>& msgx)
{
    int i, j;
    i = j = 0;
    while (i < msg.size())
    {
        msgx.push_back(msg[i]);
        i++;
        if (i == msg.size())
        {
            msgx.push_back('Z');
            break;
        }
        if (msg[i] == msgx[j])
        {
            msgx.push_back('Z');
            j++;
        }
        else if(msg[i] != msgx[j])
        {
            j++;
            msgx.push_back(msg[i]);
            i=i+1;
        }
        j++;
    }
}
 
int main()
{
    vector<char> msg;
    vector<char> msgx;
    int i, j;
    cout<<"Enter Message to Encrypt:";
    get_input(msg);
    convert_string(msg, msgx);
    int len = msgx.size();
    
    cout<<"\n";
    for (i = 0;i < len;i++)
    cout<<msgx[i];
    //this is the string after making pairs of 2
    encode(msgx, len);
 
    return 0;
}