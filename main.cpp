#include<bits/stdc++.h>
using namespace std;
struct Trie{
    char ch;
    int WordCount;    // WordCount will count the word ending with this character
    Trie *child[26];   // this will store the next character of the word
    Trie(char c){    // creating a parameterized constructor
        ch = c;
        WordCount = 0;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

void insert(Trie*node , int ind ,string s){
    if(ind == s.length()){
    	node->WordCount++; // when we reach last character of the string then we will increase the WordCount to make sure the presence of string s
        return;
    }
    if(node->child[s[ind]-'a']!=NULL){     // if the child of current index is present we will call the insert function again and increase the index
        insert(node->child[s[ind]-'a'],ind+1,s);
    }
    else{
        node->child[s[ind]-'a'] = new Trie(s[ind]);  // creating new child node with current character
        insert(node->child[s[ind]-'a'],ind+1,s);
    }
}

bool search(Trie*node,int ind,string s){
	 if(ind == s.length()){
	 	if(node->WordCount>0){    // so if the WordCount of last character is greater than 0 then the word is present
	 		return true;
	 	}
	 	return false;
	 }
	 bool check = true;
	 if(node->child[s[ind]-'a'] == NULL){
	 	check = false;
	 }
	 else{
	 	check = search(node->child[s[ind]-'a'],ind+1,s);
	 }
	 return check;
}
void deletee(Trie*node,int ind,string s){
	 if(ind == s.length()){
	 	node->WordCount--; // decrementing the word count
	 	return ;
	 }
     deletee(node->child[s[ind]-'a'],ind+1,s);
}
int main(){
    Trie * root = new Trie('#');
    string s;
    while(true){
        cout<<"Press 1 for insertion \n";
        cout<<"Press 2 for search \n";
        cout<<"Press 3 to delete \n";
        cout<<"Press 0 to  exit \n";
        int choice;
        cin>>choice;
        switch(choice){
        case 0:
            return 0;
        case 1:
            cout<<"Enter the string that you want to insert : ";
            cin>>s;
            insert(root,0,s);
            cout<<"String inserted Successfully \n";
            break;
        case 2:
            cout<<"Enter the string that you want to search : ";
            cin>>s;
            if(search(root,0,s)){
                cout<<"String is Present\n";
            }
            else{
                cout<<"String is absent \n";
            }
            break;
        case 3:
            cout<<"Enter the string that you want to delete : ";
            cin>>s;
            if(!search(root,0,s)){
                cout<<"String is already not Present\n";
            }
            else{
                deletee(root,0,s);
            }
            break;
        }
    }
}
