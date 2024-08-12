//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                           -*-*-*-*-*-*-*-*-*-*-MENU-*-*-*-*-*-*-*-*-*-*-               
//
//1.Singly Linear LinkedList
//2.Doubly Circular LinkedList
//3.Stack
//4.Queue
//5.Singly Circular LinkedList
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NAME : Singly Linear Linked List
//
//Description : Generic Implementation of Singly Linear LinkedList
//
//Date : 3/7/2024
//
//Author : Vishal Gadade
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T>* First;
        int iCount;
    
    public:
        SinglyLL();//Constructor

        void Display();                  ///////////////////////////
        int Count();                     //
                                         //Definations of Functions
        void InsertFirst(T No);          // of Singly LinkedList
        void InsertLast(T No);           //
        void InsertAtPos(T No,int iPos); //
        void DeleteFirst();              //
        void DeleteLast();               //
        void DeleteAtPos(int iPos);      ///////////////////////////
};

        template <class T>
        SinglyLL<T>::SinglyLL()
        {
            First = NULL;
            iCount = 0;
        }

        
        template <class T>
        void SinglyLL<T>::Display()        //Display Function for Singly LinkedList 
        {
             struct nodeSL<T>* temp= First;

            while(temp != NULL)
            {
                cout<<"|"<<temp->data<<"|->";
                temp = temp->next;
            }

                cout<<"NULL"<<endl;
        }


        
        template <class T>
        int SinglyLL<T>::Count()           //Count Function for Singly LinkedList 
        {
            return iCount;
        }


        
        template <class T>
        void SinglyLL<T>::InsertFirst(T No) //Insert First Function for Singly LinkedList 
        {
            struct nodeSL<T>*  newn = NULL;
            newn = new nodeSL<T>;
            newn->data = No;
            newn->next = NULL;

            if(First == NULL)
            {
                First = newn;
            }
            else
            {
                newn ->next = First;
                First = newn;
            }
            iCount++;
        }



        template <class T>
        void SinglyLL<T>::InsertLast(T No)   //Insert Last Function for Singly LinkedList 
        {
            struct nodeSL<T>*  newn = NULL;
            newn = new nodeSL<T>;
            newn->data = No;
            newn->next = NULL;

            if(First == NULL)
            {
                First = newn;
            }
            else
            {
                struct nodeSL<T>* temp = First;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;

            }

            iCount++;
        }





        template <class T>
        void SinglyLL<T>::InsertAtPos(T No,int iPos)  //Insert At position Function for 
             {                                        //Singly LinkedList  
            if(iPos < 1 || iPos > iCount+1)
            {
                  cout<<"Invalid position..!!!"<<endl;

                  return;
            }

            if(iPos == 1)
            {
                InsertFirst(No);
            }
            else if(iPos == iCount+1)
            {
                 InsertLast(No);
            }
            else
            {
                struct nodeSL<T>*  temp = First;
                struct nodeSL<T>*  newn = new nodeSL<T>;
                 newn->data = No;
                 newn->next = NULL;

                 for(int iCnt = 1;iCnt < (iPos -1);iCnt++)
                 {
                    temp = temp->next;
                 }

                 newn->next = temp->next;
                 temp->next = newn;

                 iCount++;

            }
        }




        template <class T>
        void SinglyLL<T>::DeleteFirst()    //Delete First Function for Singly LinkedList 
        {
            if(First == NULL)
            {
                cout<<"Linked  List is empty..!!"<<endl;
                return;
            }
            
            if(First ->next == NULL)
            {
                delete First;
                First = NULL;
            }
            else
            {
                 struct nodeSL<T>*  temp = First;

                First = First->next;
                delete temp;
            }

            iCount--;
        }



        template <class T>
        void SinglyLL<T>::DeleteLast()   //Delete Last Function for Singly LinkedList 
        {
            if(First == NULL)
            {
                cout<<"LL is Empty ..."<<endl;
                return;
            }

            if(First ->next == NULL)
            {
                delete First;
                First = NULL;
            }
            else
            {
                 struct nodeSL<T>*  temp = First;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                delete temp->next;

                temp->next = NULL;

            }

            iCount--;

        }


        template <class T>
        void SinglyLL<T>::DeleteAtPos(int iPos)  //Delete At position Function for Singly LinkedList 
        {
            if(iPos <1 || iPos > iCount)
            {
                cout<<"Invalid Position..!"<<endl;
                return;
            }

            if(iPos == 1)
            {
                DeleteFirst();
            }
            else if(iPos == iCount)
            {
                DeleteLast();
            }
            else
            {
                 struct nodeSL<T>*  temp1 = First;
                struct nodeSL<T>*  temp2 = NULL;

                for(int iCnt = 0;iCnt < (iPos-1); iCnt++)
                {
                    temp1 = temp1->next;
                }

                temp2 = temp1->next;

                temp1->next = temp2->next;

                iCount--;
            }
        }




//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NAME : Doubly Circular Linked List
//
//Description : Generic Implementation of Doubly Circular LinkedList
//
//Date : 3/7/2024
//
//Author : Vishal Gadade
//////////////////////////////////////////////////////////////////////////////////////////////////////////////



template<class T>
struct nodeDCL
{
    int data;
    struct nodeDCL<T>*next;
    struct nodeDCL<T>*prev;
};



template<class T>
class DoublyCL
{
    private:
        struct nodeDCL<T>* First;
        struct nodeDCL<T>* Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template<class T>
DoublyCL <T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}



template<class T>
void DoublyCL<T>::Display()  //Display Function for Doubly Circular LinkedList 
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}



template<class T>
int DoublyCL<T>::Count()  //Count Function for Doubly Circular LinkedList 
{
    return iCount;
}


template<class T>
void DoublyCL<T>::InsertFirst(T No) ////Insert First Function for Doubly Circular LinkedList 
{
    struct nodeDCL<T>*  newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}



template<class T>
void DoublyCL<T>::InsertLast(T No)//InsertLast Function for Doubly Circular LinkedList 
{
   struct nodeDCL<T>* newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template<class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)//Insert At pos Function for Doubly Circular LinkedList 
{
    struct nodeDCL<T>*  temp = NULL;
    struct nodeDCL<T>*  newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDCL<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}



template<class T>
void DoublyCL<T>::DeleteFirst() ////Delete first Function for Doubly Circular LinkedList 
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single nodeDL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one nodeDL
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}



template<class T>
void DoublyCL<T>::DeleteLast()////Delete Last Function for Doubly Circular LinkedList 
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single nodeDL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one nodeDL
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}



template<class T>
void DoublyCL<T>::DeleteAtPos(int iPos) //Delete At pos Function for Doubly Circular LinkedList 
{
    struct nodeDCL<T>*  temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NAME : Stack
//
//Description : Generic Implementation of Stack Datastructure
//
//Date : 3/7/2024
//
//Author : Vishal Gadade
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};


template<class T>
class Stack
{
  private:
    struct nodeS<T>* First;
    int iCount;

  public:
    Stack(); 
    void Display();
    int Count();
    void Push(T no);//InsertFirst
    T Pop();//DeleteFirst

};

template<class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Stack<T>::Display()
{
    cout<<"Element of stack are: "<<endl;
    struct nodeS<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
} 

template<class T>
int Stack<T>::Count()
{
    return iCount;
}

template<class T>
void Stack<T>::Push(T No)
{
    struct nodeS<T>* newn = NULL;

    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
T Stack<T>::Pop()
{
    int iValue = 0;
    struct nodeS<T>* temp = First;
    if(First==NULL)
    {
     cout<<"Unable to pop the emement..Stack is empty...!!!"<<endl;
     return -1;
    }
    else
    {

        iValue = First->data;
        First = First->next;
        delete temp;
         
         iCount--;
        
    }

    return iValue;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NAME : Queue
//
//Description : Generic Implementation of Queue Datastructure
//
//Date : 3/7/2024
//
//Author : Vishal Gadade
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
struct nodeQ
{
    T data;
    struct node *next;
};

template<class T>
class Queue
{
  private:
    struct nodeQ<T>* First;
    int iCount;

  public:
    Queue(); 
    void Display();
    int Count();
    void EnQueue(T no);//InsertLast
    T DeQueue();//DeleteFirst

};

template<class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void Queue<T>::Display()
{
    cout<<"Element of queue: "<<endl;
    struct nodeQ<T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int Queue<T>::Count()
{
    return iCount;
}

template<class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQ<T>* newn = NULL;
    struct nodeQ<T>* temp = NULL;

    newn = new nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp ->next;
        }

        temp->next = newn;
       
    }
    iCount++;
}

template<class T>
T Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQ<T>* temp = First;
    if(First==NULL)
    {
     return -1;
    }
    else
    {
        

        iValue = First->data;
        First = First->next;
        delete temp;
         
         iCount--;
        
    }

    return iValue;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NAME : Singly Circular Linked List
//
//Description : Generic Implementation of Singly Circular LinkedList
//
//Date : 3/7/2024
//
//Author : Vishal Gadade
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeSCL
{
    T data;
    struct nodeSCL *next;
};


template<class T>
class SinglyCL
{
    private:
        struct nodeSCL<T>* First;
        struct nodeSCL<T>* Last;
        int iCount;
    
    public:
        SinglyCL();
        void Display();
        int Count();
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};
        
        template<class T>
        SinglyCL<T>::SinglyCL()
        {
            First = NULL;
            iCount = 0;
        }
        
        template<class T>
        void SinglyCL<T>::Display()
        {
            do
            {
                cout<<"|"<<First->data<<"|->";
                First = First->next;
            }
            while(First!=(Last->next));

                
        }
        
        template<class T>
        int SinglyCL<T>::Count()
        {
            return iCount;
        }
        
        template<class T>
        void SinglyCL<T>::InsertFirst(T No)
        {
            struct nodeSCL<T>* newn = NULL;
            newn = new nodeSCL<T>;
            newn->data = No;
            newn->next = NULL;

            if(First == NULL)
            {
                First = newn;
                Last  = newn;
            }
            else
            {
                newn ->next = First;
                First = newn;
            }

            Last->next = First;
            iCount++;
        }
        
        template<class T>
        void SinglyCL<T>::InsertLast(T No)
        {
            struct nodeSCL<T>* newn = NULL;
            newn = new nodeSCL<T>;
            newn->data = No;
            newn->next = NULL;

            if(First == NULL)
            {
                First = newn;
                Last  = newn;
            }
            else
            {
              Last->next = newn;
              Last = newn;

            }

            Last->next = First;

            iCount++;
        }
         
         template<class T>
        void SinglyCL<T>::InsertAtPos(T No,int iPos)
        {
            if(iPos < 1 || iPos > iCount+1)
            {
                  cout<<"Invalid position..!!!"<<endl;

                  return;
            }

            if(iPos == 1)
            {
                InsertFirst(No);
            }
            else if(iPos == iCount+1)
            {
                 InsertLast(No);
            }
            else
            {
                 struct nodeSCL<T>* temp = First;
                 struct nodeSCL<T>* newn = new nodeSCL<T>;
                 newn->data = No;
                 newn->next = NULL;

                 for(int iCnt = 1;iCnt < (iPos -1);iCnt++)
                 {
                    temp = temp->next;
                 }

                 newn->next = temp->next;
                 temp->next = newn;

                 iCount++;

            }
        }

        template<class T>
        void SinglyCL<T>::DeleteFirst()
        {
            if(First == NULL)
            {
                cout<<"Linked  List is empty..!!"<<endl;
                return;
            }
            
            if(First ->next == NULL)
            {
                delete First;
                First = NULL;
                Last = NULL;
            }
            else
            {
                struct nodeSCL<T>* temp = First;

                First = First->next;
                delete temp;
                Last->next = First;
            }
            
            iCount--;
        }
        
        template<class T>
        void SinglyCL<T>::DeleteLast()
        {
            if(First == NULL)
            {
                return;
            }

            if(First ->next == NULL)
            {
                delete First;
                First = NULL;
            }
            else
            {
                struct nodeSCL<T>* temp = First;

                while(temp->next != Last)
                {
                    temp = temp->next;
                }

                Last = temp;

                delete temp->next;
                
                Last ->next = First;
                
                

            }

            iCount--;

        }
        
        template<class T>
        void SinglyCL<T>::DeleteAtPos(int iPos)
        {
            if(iPos <1 || iPos > iCount)
            {
                cout<<"Invalid Position..!"<<endl;
                return;
            }

            if(iPos == 1)
            {
                DeleteFirst();
            }
            else if(iPos == iCount)
            {
                DeleteLast();
            }
            else
            {
                struct nodeSCL<T>* temp1 = First;
                struct nodeSCL<T>* temp2 = NULL;

                for(int iCnt = 1;iCnt < (iPos-1); iCnt++)
                {
                    temp1 = temp1->next;
                }

                temp2 = temp1->next;

                temp1->next = temp2->next;

                iCount--;
            }
        }




//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NAME : Doubly Linked List
//
//Description : Generic Implementation of "Doubly LinkedList".
//
//Date : 3/7/2024
//
//Author : Vishal Gadade
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeDLL
{
    T data;
    struct nodeDLL *next;
    struct nodeDLL *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct nodeDLL<T>* First;
        int iCount;
    
    public:
        DoublyLL();
        void Display();
        int Count();
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};
        
        template<class T>
        DoublyLL<T>::DoublyLL()
        {
            First = NULL;
            iCount = 0;
        }
        
        template<class T>
        void DoublyLL<T>::Display()
        {
            struct nodeDLL<T>* temp = First;
            
            while(temp !=NULL)
            {
                cout<<"|"<<temp->data<<"|->";
                temp = temp->next;
            }
            

                
        }
        
        template<class T>
        int DoublyLL<T>::Count()
        {
            return iCount;
        }

        template<class T>
        void DoublyLL<T>::InsertFirst(T No)
        {
            struct nodeDLL<T>* newn = NULL;
            newn = new nodeDLL<T>;
            newn->data = No;
            newn->next = NULL;
            newn->prev = NULL;

            if(First == NULL)
            {
                First = newn;
                
            }
            else
            {
                newn->next = First;
                First->prev = newn;
                First = newn;
            }

            iCount++;
        }

        template<class T>
        void DoublyLL<T>::InsertLast(T No)
        {
            struct nodeDLL<T>* newn = NULL;
            newn = new nodeDLL<T>;
            newn->data = No;
            newn->next = NULL;
            newn->prev = NULL;

            if(First == NULL)
            {
                First = newn;
    
            }
            else
            {
              struct nodeDLL<T>* temp = First;

              while(temp->next != NULL)
              {
                temp = temp->next;
              }
              temp->next = newn;
              newn->prev = temp;

            }

            iCount++;
        }

        template<class T>
        void DoublyLL<T>::InsertAtPos(T No,int iPos)
        {
            if(iPos < 1 || iPos > iCount+1)
            {
                  return;
            }

            if(iPos == 1)
            {
                InsertFirst(No);
            }
            else if(iPos == iCount+1)
            {
                 InsertLast(No);
            }
            else
            {
                 struct nodeDLL<T>* temp = First;
                 struct nodeDLL<T>* newn = new nodeDLL<T>;
                 newn->data = No;
                 newn->next = NULL;
                 newn->prev = NULL;

                 for(int iCnt = 1;iCnt < (iPos -1);iCnt++)
                 {
                    temp = temp->next;
                 }

                 newn->next = temp->next;
                 temp->next = newn;
                 newn->next->prev = newn;
                 newn->prev = temp;

                 iCount++;

            }
        }

        
        template<class T>
        void DoublyLL<T>::DeleteFirst()
        {
            if(First == NULL)
            {
                return;
            }
            
            if(First ->next == NULL &&(First->prev == NULL))
            {
                delete First;
                First = NULL;
            }
            else
            {
                First = First->next;
                delete First->prev;
                First->prev = NULL;
            }
            
            iCount--;
        }

        template<class T>
        void DoublyLL<T>::DeleteLast()
        {
            if(First == NULL)
            {
                return;
            }

            if(First ->next == NULL)
            {
                delete First;
                First = NULL;
            }
            else
            {
                struct nodeDLL<T>* temp = First;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                
                delete temp->next;

                temp->next = NULL;
                

            }

            iCount--;

        }

        template<class T>
        void DoublyLL<T>::DeleteAtPos(int iPos)
        {
            if(iPos <1 || iPos > iCount)
            {
                cout<<"Invalid Position..!"<<endl;
                return;
            }

            if(iPos == 1)
            {
                DeleteFirst();
            }
            else if(iPos == iCount)
            {
                DeleteLast();
            }
            else
            {
                struct nodeDLL<T>* temp = First;
               

                for(int iCnt = 1;iCnt < (iPos-1); iCnt++)
                {
                    temp = temp->next;
                }

                temp->next = temp->next->next;
                delete temp->next->prev;
                temp->next->prev = temp;


                iCount--;
            }
        }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////




int main()
{
    
    return 0;
}

