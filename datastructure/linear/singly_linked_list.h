struct node
{
    node *next;
    int element;
};

class singly_linked_list
{
    public:
        node *head, *tail;

        void prepend(value);       
        void append(value);   
        void appendafter(index);   
        int pop();                
        int popFirst();            
        int head();                
        int tail();                
        void remove(index);      
    
    // 1. new node 생성, 주소값 저장하기.
    // 2. new node head 값으로 바꾸기.
    void prepend(int value){
        newNode = {&head, value};
        *head = &newNode;
        return;
    }   

    // 1. new node 생성, 주소값 저장하기.
    // 2. tail의 다음값 newnode값으로 바꾸기.
    // 3. new node tail 값으로 바꾸기.
    void append(int value){
        newNode = {&head, value};
        tail.next = &newNode;
        *tail = &newNode;
    }

    // 1.위치 찾기.
    void appendafter(int index){

    } 

    int pop(){
        return
    }

    int popFirst(){
        return
    }

    int head(){
        return
    }

    int tail(){
        return
    }
    
    void remove(int index){

    }
};