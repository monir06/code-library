#include<bits/stdc++.h>
using namespace std;

struct node{
    bool endmark=0;
    node* child[52] = {NULL}; // সর্বোচ্চ ৫২ ক্যারাক্টার
};

node *root = new node;
int getId(char ch){
    int id = ch-'A';
    if(ch>='a') id-=6;
    return id;
}
void insert(string s){
    node *crnt = root;//আমাদের রুট নোড এর এড্রেস কে একটা  ভ্যারিয়েবল এর রেখেছি
    for(int i=0;i<s.length();i++){
        int id = getId(s[i]);//কততম ইনডেক্স এ অ্যাড্রেস রাখতে হবে তা হিসাব করেছি
        if(crnt->child[id] == NULL)//যদি ঐ ইনডেক্স এ আগে থেকেই কোন অ্যাড্রেস না থাকে, 
            crnt->child[id]=new node; //তবে একটি নোড অ্যাড্রেস দিয়ে দেই
        crnt=crnt->child[id];//ঐ অ্যাড্রেস টি কে বর্তমান অ্যাড্রেস বানাই
    }
    crnt->endmark=1;//বর্তমান অ্যাড্রেস এ একটি শব্দ শেষ হয়েছে
}

 
bool search(string &s){
    node *currentNode = root;//আমাদের রুট নোড এর এড্রেস কে একটা  ভ্যারিয়েবল এর রেখেছি
    for(int i=0;i<s.length();i++){//স্ত্রিং এর ক্যারাক্টার গুলোর উপর লুপ
        int id = getId(s[i]);//কততম ইনডেক্স এ অ্যাড্রেস রাখতে হবে তা হিসাব করেছি
        if(currentNode->child[id]==NULL) //যদি ঐ ইনডেক্স এ আগে থেকেই কোন অ্যাড্রেস না থাকে, 
            return false;//তার মানে শব্দ টি নেই। তাই আর নিচে গিয়ে কাজ নেই।
        currentNode = currentNode->child[id];//নতুবা ঐ অ্যাড্রেস টি কে বর্তমান অ্যাড্রেস বানাই
    }
    return currentNode->endmark;//বর্তমান অ্যাড্রেস এ একটি শব্দ শেষ হলে true return করবে, নয়তো false
}

/*main function*/
int main(){
 string s="Love";
    insert("Bangali");  
    insert("Bangla");
    insert("Love");
    insert("Lover");
    insert("Locker");
    
    if(search(s)){
        cout<<s<<" found\n";
    }else{
        cout<<s<<" not found\n";
    }
    return 0;
}
