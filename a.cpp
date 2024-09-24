#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct Trie{
    Trie* child[10];
    char self;
    Trie(){
        for(int i=0;i<10;i++){
            char c=i+'0';
            child[c]=NULL;
        }
    }
};
void addnode(string s,Trie*head){
    if(head==NULL){
        head=new Trie();
    }
    Trie*temp=head;
    int i=0;
    while(i<s.length()){
        if(temp->child[s[i]]){
            temp=temp->child[s[i]];
            i++;
        }
        else{
            temp->child[s[i]]=new Trie();
            temp=temp->child[s[i]];
            i++;
        }
    }
    return ;
}
int search(string s,Trie*head){
    Trie*temp=head;
    int cnt=0;
    int i=0;
    while(i<s.length() && temp->child[s[i]]){
        temp=temp->child[s[i]];
        i++,cnt++;
    }
    return cnt;
}
int main(){
    Trie*root=new Trie();
    string s;
    cin>>s;
    while(s!="q"){
        addnode(s,root);
        cin>>s;
    }
    cout<<"now 2nd array"<<endl;
    int ans=0;
    cin>>s;
    while(s!="q"){
        ans=max(ans,search(s,root));
        cin>>s;
    }
    cout<<ans;

}