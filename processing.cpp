#include<bits/stdc++.h>
using namespace std;
#define COUNT 320000

int a[COUNT][26]={0};
vector<string> words;

bool is_string(string& s)
{
    for(int i=0;i<s.size();i++)
        if(islower(s[i]))
            continue;
        else if(isupper(s[i]))
            {
                s[i]=tolower(s[i]);
                continue;
            }
        else
            return false;
    return true;
}
vector<string > parse_it()
{
    int counter=0;
    string s;
    vector<string> v;

    ifstream in;
    in.open("new_words.txt");

    while(in>>s)
        if(is_string(s))
            v.push_back(s);

    in.close();
    return v;
}
void dump_it()
{
    for(int i=0;i<words.size();i++)
    {
        for(int j=0;j<words[i].size();j++)
        {
            a[i][words[i][j]-'a']++;
        }
       // for(int j=0;j<26;j++)
         //   cout<<a[i][j]<<" ";
        //cout<<endl;
    }
}
void printer(int* temp)
{
    vector<string >answers;
    for(int i=0;i<words.size();i++)
    {
        int flag=0;
        for(int j=0;j<26;j++)
        {
            if(a[i][j]>temp[j])
            {
                flag++;
                break;
            }
        }
        if(flag==0)
            answers.push_back(words[i]);

    }
    sort(answers.begin(),answers.end(),[](string& a,string& b){return a.size()>b.size();});
    for(int i=0;i<answers.size();i++)
        if(answers[i].size()>1)
            cout<<"\t"<<i+1<<". "<<answers[i]<<endl;
}

void answering(string& s)
{
    int temp[26]={0};
    for(int i=0;i<s.size();i++)
        temp[s[i]-'a']++;
    printer(temp);
}
void preprocess()
{
    ifstream in;
    in.open("wordlist.txt");
    vector<string >vs;
    string s;
    map<string,bool>m;
    int counter=0;
    while(in>>s)
    {
        s[0]=tolower(s[0]);
        if(is_string(s)&&s.size()>1&&m[s]==false)
            vs.push_back(s);
        else
            {
                cout<<s<<endl;
                counter++;
            }
        m[s]=true;
    }
    cout<<counter<<endl;
    in.close();
    ofstream out;
    out.open("new_words.txt");
    for(int i=0;i<vs.size();i++)
        out<<vs[i]<<endl;
}

int main()
{
   // preprocess();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    words=parse_it();

    dump_it();
    cout<<"preprocessing has been completed\n"<<endl<<endl;
    while(true)
    {
        cout<<"enter a word to generate all its anagrams :"<<endl;
        string s;
        cin>>s;
        answering(s);
        cout<<endl;
    }
    return 0;
}
