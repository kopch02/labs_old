#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct datetime
{
    int number;
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;
};
struct DLList
{
    
    struct Node
    {
        datetime data;     //information
        Node* next;   //next node position
        Node* prev;   //previous node position
    };

    Node* F=NULL;     //first node
    Node* L=NULL;     //last node
    Node* C=NULL;     //current node
    int Count;        //node count

    void Out();
    void Info();
    void Clear();

    bool MoveNext();
    bool MovePrev();
    bool MoveFirst();
    bool MoveLast();

    bool Init(datetime);
    bool AddNext(datetime);
    bool AddPrev(datetime);
    bool AddFirst(datetime);
    bool AddLast(datetime);

    bool Del(datetime&);
    bool DelNext(datetime&);
    bool DelPrev(datetime&);
    bool DelFirst(datetime&);
    bool DelLast(datetime&);
};

bool DLList::MoveNext()
{
    if(!F)       return false;
    if(!C)       {C=F; return true;}
    if(C==L) return false;
    C=C->next;
    return true;
}

bool DLList::MovePrev()
{
    if(!F)       return false;
    if(!C)       {C=F; return true;}
    if(!C->prev) return false;
    C=C->prev;
    return true;
}
bool DLList::MoveFirst()
{
    if(!F) return false;
    C=F;
    return true;
}

bool DLList::MoveLast()
{
    if(!L) return false;
    C=L;
    return true;
}

bool DLList::Init(datetime data)
{
   if(!F)
   {
        F=new Node;
        L=F;
        C=F;
        F->prev=NULL;
        F->next=NULL;
        F->data = data;
        Count=1;
        return true;
   }
   else
        return false;
}

bool DLList::AddNext(datetime data)
{
	if(!F) return Init(data);

	Node* temp=C->next;
	C->next=new Node;
	C->next->next=temp;
	C->next->prev=C;

	if(!temp)
        L=C->next;
	else
        temp->prev=C->next;

    C=C->next;
    C->data=data;
    Count++;
    return true;

}

bool DLList::AddPrev(datetime data)
{
	if(!F) return Init(data);

	Node* temp=C->prev;
	C->prev=new Node;
	C->prev->next=C;
	C->prev->prev=temp;

	if(!temp)
        F=C->prev;
	else
        temp->next=C->prev;

    C=C->prev;
    C->data=data;
    Count++;
    return true;
}

bool DLList::AddFirst(datetime data)
{
    if (MoveFirst())return AddPrev(data);
    else return false;
}

bool DLList::AddLast(datetime data)
{
    if (MoveLast())return AddNext(data);
    else return false;
}

void DLList::Out()
{
    if(!F)  {
                cout<<"List is empty"<<endl;
                return;
            }

    Node* temp=C;
    cout<<"List: "<<endl;
    
    
        cout<<endl;
        cout<<"--------------"<<endl;
        cout<<endl;
        cout<<"number - "<<temp->data.number<<endl;
       cout<<"second - "<<temp->data.second<<endl;
       cout<<"minute - "<<temp->data.minute<<endl;
       cout<<"hour - "<<temp->data.hour<<endl;
       cout<<"day - "<<temp->data.day<<endl;
       cout<<"month - "<<temp->data.month<<endl;
       cout<<"year - "<<temp->data.year<<endl;
    
 
    cout<<endl;
}

void DLList::Info()
{

cout<<endl;
cout<<endl;
    if(Count)
        cout<<"List node count: "<<Count<<endl;
    else
        cout<<"List is empty"<<endl;
   bool flag = true;
    if(!C)
    {
        flag=MoveFirst();
    }
    Node* temp=C;
    cout<<endl;
        temp=temp->next;
    for (int i=0;i<2;i++)
    {
        cout<<"Current node data = "<<endl;
        cout<<endl;
        cout<<"number - "<<temp->data.number<<endl;
        cout<<"second - "<<temp->data.second<<endl;
        cout<<"minute - "<<temp->data.minute<<endl;
        cout<<"hour - "<<temp->data.hour<<endl;
        cout<<"day - "<<temp->data.day<<endl;
        cout<<"month - "<<temp->data.month<<endl;
        cout<<"year - "<<temp->data.year<<endl;
        temp=temp->prev;
    }
cout<<endl;
cout<<endl;

}

bool DLList::DelFirst(datetime& data)
{
    if(!F)      return false;
    if(C!=F)    MoveFirst();

    Node* temp = C->next;
    data = C->data;

    if(temp) temp->prev=NULL;
    delete C;

    C=temp;
    F=temp;
    Count--;
    if(!temp) {L=NULL; return false;}
    return true;
}

bool DLList::DelLast(datetime& data)
{
    if(!F)      return false;
    if(C!=L)    MoveLast();

    Node* temp = C->prev;
    data = C->data;

    if(temp) temp->next=NULL;
    delete C;

    C=temp;
    L=temp;
    Count--;

    if(!temp) {F=NULL; return false;}
    return true;
}

bool DLList::Del(datetime& data)
{
    if(!F) return false;
	if(!C) return false;

	if(C==F) return DelFirst(data);
    if(C==L) return DelLast(data);

    Node* temp = C->next;
	data=C->data;

	C->prev->next=C->next;
	C->next->prev=C->prev;

	delete C;
	C=temp;
	Count--;
	return true;
}

bool DLList::DelNext(datetime& data)
{
    if(!F) return false;
	if(!C) return false;
	if (MoveNext()) return Del(data);
    return false;
}
bool DLList::DelPrev(datetime& data)
{
    if(!F) return false;
	if(!C) return false;
	if (MovePrev()) return Del(data);
    return false;
}

void DLList::Clear()
{
   if(!MoveFirst())
   {
       cout<<"List is empty"<<endl;
       return;
   }
   datetime k;
   while(Del(k));
}

int main()
{
    DLList MyList;

    datetime a;
    datetime buff;

    ifstream file;
    ofstream ff;
    
    file.open("file.txt");
    for(int i=0;i<4;i++)
    {
    file>>a.number>>a.second>>a.minute>>a.hour>>a.day>>a.month>>a.year;
    MyList.AddNext(a);
    }
    file.close();
    MyList.MovePrev();
    cout<<endl<<"current"<<endl<<endl;
    MyList.Out();
    MyList.MoveNext();
    cout<<"next"<<endl<<endl;
    MyList.Out();
    MyList.MovePrev();
    MyList.MovePrev();
    cout<<"prev"<<endl<<endl;
    MyList.Out();
    


    return 0;
}