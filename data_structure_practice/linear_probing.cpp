#include <iostream>
#include <ctime>
#include <random>
#define MAX_CNT 30000000
using namespace std;

struct Node{
    int key, val;
};

Node nodes[MAX_CNT + 3];
int cnt_node;

Node* buck[MAX_CNT + 3];

Node* dummy = new Node();

Node* get_node(int key, int val){
    Node* ret = &nodes[cnt_node++];
    ret->key = key;
    ret->val = val;
    return ret;
}

int get_hash(int x){
    int tmp = x * 1217 + 71;
    tmp = tmp * 18217 + 13;
    tmp = tmp * 17 + 7;
    tmp = tmp * 11 + 3;
    return (tmp % MAX_CNT + MAX_CNT) % MAX_CNT;
}

void insert(int key, int val){
    int h = get_hash(key);
    int cur = h;
    while(buck[cur] != NULL && buck[cur]->key != key && buck[cur]->key != -1){
        cur = (cur + 1) % MAX_CNT;
        if(cur == h) break;
    }
    if(buck[cur] != NULL && buck[cur]->key != key && buck[cur]->key != -1) return;
    buck[cur] = get_node(key, val);
}

void remove(int key){
    int h = get_hash(key);
    int cur = h;
    while(buck[cur] != NULL){
        if(buck[cur]->key == key){
            int k = buck[cur]->key;
            int v = buck[cur]->val;
            buck[cur] = dummy;
            return;
        }
        cur = (cur + 1) % MAX_CNT;
    }
}

Node* find(int key){
    int h = get_hash(key);
    int cur = h;
    while(buck[cur] != NULL && buck[cur]->key != key){
        cur = (cur + 1) % MAX_CNT;
        if(cur == h) break;
    }
    return buck[cur] == NULL || buck[cur]->key != key ? NULL : buck[cur];
}

int main(){
    dummy->key = -1;
    for(int i = 0; i < MAX_CNT; i++) buck[i] = NULL;
    srand(time(NULL));

    clock_t start = clock();
    for(int i = 0; i < 20000000; i++){
        insert(rand(), rand());
        find(rand());
        remove(rand());
    }

    clock_t end = clock();

    cout << double(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
