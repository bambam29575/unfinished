#include <iostream>
using namespace std;


class node {
    public:
    int data;
    node *link;
};
node *ptr, *tail, *head, *temp;
char ch, ch2;
int pos, i, count = 0;

void display();
void insert();
void del();
void oper();

int main(){
    cout <<"1 st node"<< endl;
    ptr = new node;
    cin >> ptr->data;
    tail = ptr;
    head = ptr;
   
    
    oper();
    return 0;
}

void display(){
    temp = head;
    i = 1;
    while(i <=  count+1){
        cout << temp->data << " ";
        temp = temp->link;
        i++;
    }
    cout << endl;
}

void insert(){
    cout << "New node?" <<endl;
    cin >> ch;
    
    while(ch == 'y'){
       ptr = new node;
       cout << "Enter data" << endl;
       cin >> ptr->data;
       count ++;
       cout << "Where" << endl;
    
       cin >> ch2;
       if (ch2 == 'h'){
           ptr->link = head;
           head = ptr;
       }else if(ch2 == 'm'){
           temp = head;
           cout << "position" << endl;
           cin >> pos;
           while(i < pos-1 ){
               temp = temp->link;
               i++;
           }
           ptr->link = temp->link;
           temp->link = ptr;
           
       }
       else{
           tail->link = ptr;
           tail = ptr;
       }
       cout << "Want to create next node?" << endl;
       cin >> ch;
    }
 oper();
}

void oper(){
    cout << "action" << endl;
    cin >> ch;
    if(ch == 'd'){
        del();
    }else if(ch == 'i'){
        insert();
    }else if(ch == 's'){
        display();
    }else{
        cout << "invalid" << endl;
    }
}

void del(){
    count--;
    cout << "Node position" << endl;
    cin >> ch;
    if (ch == 'h'){
       temp = head;
       head = temp->link;
       temp->link = nullptr;
    }else if(ch == 'm'){
        cout << "position" << endl;
        cin >> pos;
        i = 1;
        temp = head;
        while(i < pos){
            if(i == pos-1){
                temp->link = temp->link->link;
            }
            temp = temp->link;
            i++;
        }
        temp->link = nullptr;
    }else{
        i =1;
        temp = head;
        while(i < count-1){
            tail = temp;
            tail->link = nullptr;
        }
    }
    oper();
}
