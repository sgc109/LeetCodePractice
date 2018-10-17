#include<bits/stdc++.h> 
#define MAX_CNT 30000000
using namespace std; 
  
//Hashnode class 
class HashNode 
{ 
    public: 
    int value; 
    int key; 
      
    HashNode(){}
    //Constructor of hashnode  
    HashNode(int key, int value) 
    { 
        this->value = value; 
        this->key = key; 
    } 
}; 

HashNode nodes[MAX_CNT];
int cnt_node;
HashNode* get_node(int key, int val){
    HashNode* ret = &nodes[cnt_node++];
    ret->key = key;
    ret->value = val;
    return ret;
}
  
//template for generic type 
//Our own Hashmap class 
class HashMap 
{ 
    //hash element array 
    HashNode **arr; 
    int capacity; 
    //current size 
    int size; 
    //dummy node 
    HashNode *dummy; 
  
    public: 
    HashMap() 
    { 
        //Initial capacity of hash array 
        capacity = 30000000; 
        size=0; 
        arr = new HashNode*[capacity]; 
          
        //Initialise all elements of array as NULL 
        for(int i=0 ; i < capacity ; i++) 
            arr[i] = NULL; 
          
        //dummy node with value and key -1 
        dummy = get_node(1, -1);
    } 
    // This implements hash function to find index 
    // for a key 
    int hashCode(int key) 
    { 
        return key % capacity; 
    } 
      
    //Function to add key value pair 
    void insertNode(int key, int value) 
    { 
        HashNode *temp = get_node(key, value);
          
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
          
        //find next free space  
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
               && arr[hashIndex]->key != -1) 
        { 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //if new node to be inserted increase the current size 
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
            size++; 
        arr[hashIndex] = temp; 
    } 
      
    //Function to delete a key value pair 
    int deleteNode(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
          
        //finding the node with given key 
        while(arr[hashIndex] != NULL) 
        { 
            //if node found 
            if(arr[hashIndex]->key == key) 
            { 
                HashNode *temp = arr[hashIndex]; 
                  
                //Insert dummy node here for further use 
                arr[hashIndex] = dummy; 
                  
                // Reduce size 
                size--; 
                return temp->value; 
            } 
            hashIndex++; 
            hashIndex %= capacity; 
  
        } 
          
        //If not found return null 
        return NULL; 
    } 
      
    //Function to search the value for a given key 
    int get(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
  
        //finding the node with given key    
        while(arr[hashIndex] != NULL) 
        { 
            //if node found return its value 
            if(arr[hashIndex]->key == key) 
                return arr[hashIndex]->value; 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //If not found return null 
        return NULL; 
    } 
      
    //Return current size  
    int sizeofMap() 
    { 
        return size; 
    } 
      
    //Return true if size is 0 
    bool isEmpty() 
    { 
        return size == 0; 
    } 
      
    //Function to display the stored key value pairs 
    void display() 
    { 
        for(int i=0 ; i<capacity ; i++) 
        { 
            if(arr[i] != NULL && arr[i]->key != -1) 
                cout << "key = " << arr[i]->key  
                     <<"  value = "<< arr[i]->value << endl; 
        } 
    } 
}; 
  
//Driver method to test map class 
int main() 
{ 
    srand(time(NULL));
    HashMap *h = new HashMap;

    clock_t start = clock();
    
    for(int i = 0; i < 20000000; i++) {
        h->insertNode(rand(), rand());
//        h->deleteNode(rand());
        h->get(rand());
    }

    clock_t end = clock();

    cout << "time consuming : " << double(end - start) / CLOCKS_PER_SEC << 's' << endl;
  
    return 0; 
} 
