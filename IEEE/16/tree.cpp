#include<bits/stdc++.h>
using namespace std;

class Node{
    int id;
    char letter;
    string data;
    Node *left;
    Node *right;
    
public:
    Node(int val): id(val),letter('\0'),data("\0"),left(nullptr),right(nullptr){}
    ~Node(){}

    string getData(){
        return this->data;
    }
    char getLetter(){
        return this->letter;
    }
    Node* getLeft(){
        return this->left;
    }
    Node* getRight(){
        return this->right;
    }

    void setLeft(Node* l){
        this->left=l;
    }
    void setRight(Node* r){
        this->right=r;
    }
    void setData(string a){
        this->data=a;
    }
    void setLetter(char a){
        this->letter=a;
    }


};


int main(){

    int n,m;
    cin>>n>>m;
    string s;
    int a,x,y;

    vector<Node*> arr(n+1);
    for(int i=1;i<=n;i++){
        *arr[i] = Node(i);
    }


    char c,l;

    for(int i=0;i<n;i++){
        cin>>c;
        

        

        if(c=='I'){
            Node* curr = arr[a];
            cin>>a>>l>>x>>y;
            
            (*curr).setLetter(l);
            (*curr).setLeft(arr[x]);
            (*curr).setRight(arr[y]);
        }else{
            Node* curr = arr[a];
            cin>>a>>s;
            (*curr).setData(s);
        }
    }

    for(int k=0;k<m;k++){
        
        getline(cin, s);
        cout<<s<<endl;
        set<char> check;
        for(auto c:s){
            check.insert(c);
        }

        vector<string> ans;

        Node* curr = arr[1];
        while(curr!=nullptr){
            cout<<(*curr).getLetter()<<endl;
            if((*curr).getLetter()!='\0'){    

                //char l = (char)curr.getData();
                if(check.find((*curr).getLetter())!=check.end()){
                    check.erase((*curr).getLetter());
                    curr = (*curr).getLeft();
                }else{
                    curr = (*curr).getRight();
                }
            }else{
                ans.push_back((*curr).getData());
                curr = (*curr).getLeft();
            }

        }

        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}