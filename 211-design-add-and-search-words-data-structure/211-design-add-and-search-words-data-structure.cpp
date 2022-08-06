class WordDictionary {
public:
    class Node{
      public:
        Node* links[26];
        bool flag=false;
    };
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        
        for(char c: word){
            if(!temp->links[c-'a'])
            {
                temp->links[c-'a'] = new Node();
            }
            temp = temp->links[c-'a'];
        }
        temp->flag=true;
        
    }
    
    bool search(string word) {
         Node* temp = root;
        
        return search(word,temp,0);
        
    }
    bool search(string &word, Node* node,int ind){
        
        for(int i=ind;i<word.size();i++)
        {
            if(word[i]=='.'){
                for(int j=0;j<26;j++)
                {
                    
                    Node* tmp = node;
                    if(node->links[j]){
                       // cout<<i<<" "<<j<<"\n";
                         if(search(word,tmp->links[j],i+1))
                           return true;
                    }
                   
                }
                return false;
                
            }
            else{
                if(!node->links[word[i]-'a'])
                    return false;
                node = node->links[word[i]-'a'];
            }
        }
        return node->flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */