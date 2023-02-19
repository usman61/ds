//Following code contains complete implementation of array list.

#include<iostream>
using namespace std;

class arrayImplementation // creating a class
{
    public:
    int *arr;  //this pointer will point to our actual array
    int *curr; // temporary pointer , will we use for doing different operations
    int length,size; // length is the number of elements in array and 
                     //size is the capacity of array
    public:

    arrayImplementation(int s) // parameterized constructor
    {
        size=s;
        arr=new int[s];
        length=0;
        curr=NULL;
    }

    ~arrayImplementation() // destructor
    {
        delete[] arr;
    }

    bool IsEmpty()// this function will return true if the array
                  // is empty and false if its not 
    {
        if(length==0)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    bool IsFull()// this function will return true if the array
                  // is full and false if its not 
    {
        if(length==size) //condition for array to be full
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void start() // this function will take our temporary pointer to the start
    {
        if(IsEmpty())
        {
            return;
        }
        else
        {
            curr=arr;
        }
    }

    void tail() // this function will take our temporary pointer to the end
    {
       if(IsEmpty()) 
        {
            return;
        } 
        
        else
        {
            curr=(arr+length)-1;
        }
    }

    void next() // this will move our current poinetr to the next location
    {
        if(IsFull())
        {
            cout<<"Not possible"<<endl;
            return;
        }

        else
        {
            curr++;
        }
    }

    void back() // this will move our current pointer one step back
    {
        if(curr==arr)
        {
            cout<<"Not possible"<<endl;
            return;
        }
        
        else
        {
            curr--;
        }    
    }

    //this function will take two parameters (value and position) and put the value at 
    // that specific position
    void insertElementAt(int value, int pos)
    {
        if(IsEmpty() && pos==1) // if the array is empty and the position is 1 
        {
            curr=arr;
            *curr=value;
        }

        if(IsFull()) // if the array if full mlore values cannot be addded
        {
            cout<<"Array is full.No more values can be added."<<endl;
            return;
        }
        
        if(pos>(length+1))   
        {
            cout<<"Not possible"<<endl;
            return;
        }

        tail(); // take the curr pointer to the end
        for(int i =length;i>=pos;i--)
        {
            *(curr+1)=*curr;
            curr--;
        }

        *(curr+1)=value;
        length++;
    }

    //this function will print the elements of the array
    void printList()
    {
        if(IsEmpty()) // if the array is empty
        {
            cout<<"Array is empty.Nothing to display."<<endl;
            return;
        }

        start();

        cout<<"-----------------------------------------------"<<endl;

        for(int i=0; i<length; i++)
        {
            cout<<*(curr+i)<<" ";
        }
        cout<<endl;
        cout<<"-----------------------------------------------"<<endl;
        
    }

    //this function will insert element at the end of array or if the array is 
    //empty it will be inserted as first value
    void insertElement (int X)
    {
        if(IsFull()) //if the array is full the functio will returm from here
        {
            cout<<"Array is full .No more elements can be added"<<endl;
            return;
        }

        if(IsEmpty()) // if the array is empty the value will be inserted at the first position
        {
            curr=arr; 
            *curr=X;
            length++;
        }
        else
        {
            tail();
            *(curr+1)=X;
            length++;
        }
    }

    //this function will check if the value is present in the array or not ad if it 
    //is present it will return its position
    int searchElement (int X)
    {
        int s=0; // we will store the position in this variable also if the value is nt present in the array s will be return 

        if(IsEmpty())
        {
            cout<<"Array is empty."<<endl;
            return s;
        }

        start();

        for(int i=1; i<=length; i++) // loop for traversing through the whole array
        {
            s++; // we will inc s in each loop iteration
            if(*curr==X)// it will check whetre
            {
                cout<<"Value Found"<<endl;
                return s;
            }
            curr++;
        }

        cout<<X<<"Value does not exist in the array"<<endl;
        return s;
    }

    //this function will delete the value at the position  given in the parameter
    //and return true if the value is deleted and false ifthe value is not deleted
    bool deleteElement (int X)
    {
        int check=searchElement(X); 

        if(check==0) // checking whether the value exist in the array or not
        {
            return false;
        }
        else // if the value exist
        {
            start();
            curr=arr+check-1;

            for(int i=check; i<length; i++)
            {
                *curr=*(curr+1);
                curr++;

            }

            length--;
            return true;
        }
    }

    //return the length of the array
    int Length()
    {
        return length;
    }

    //it reverse the array 
    void reverseList()
    {
        start();
        int s=length;
        int n=(length/2);

        for(int i=0;i<=n;i++)
        {
            int temp=*curr;
            *curr=*(arr+(s-1));
            *(arr+(s-1))=temp;
            curr++;
            s--;
        }
    }

    //this function will empty the array by making its length equal to 0
    void emptyList()
    {
        length=0;
    }

    //this function will copy the one array into the other array
    void copyList(arrayImplementation o1 , arrayImplementation o2)
    {
        start();
        int *temp=o2.arr;
        for(int i=0 ; i<length;i++)
        {
            *temp=*curr;
            curr++;
            temp++;
        }

        cout<<"The list is sucessfully copied."<<endl;
        temp=o2.arr;
        for(int i=0 ; i<length;i++) //printing the copy array
        {
            cout<<*temp<<" ";
            temp++;
        }
    }

    //this function sort the array in asscending order
    void sort()
    {
        for(int i=0; i<length ; i++)
        {
            start();
            int *temp=curr+1;
                for(int i=0 ;i<(length-1) ;i++)
                {
                    if(*temp<*curr) //if the previous element is larger then the next element it will replace it
                    {
                        int v=*curr;
                        *curr=*temp;
                        *temp=v;
                    }
                    curr++;
                    temp++;
                }
        }

        start();

        cout<<"Array is sucessfully sorted."<<endl;
        for(int i=0; i<length ; i++) //printing the array after sorting it
        {
            cout<<*curr<<" "<<endl;
            curr++;
        }
    }


//this function will compare two arrays and return true if they are same.
bool compareList(arrayImplementation L1, arrayImplementation L2) 
{
    int s; int ss;
    cout<<"Full the array you want to compare."<<endl;
    cout<<"Size :";
    cin>>s;
    L2.size=s;

    cout<<"Enter the elements :"<<endl;

    int *temp=L2.arr;

    for(int i=0; i<s; i++)
    {
        cin>>*temp;
        temp++;
    }

    int sss=L1.size + (abs(L1.size-L2.size)); //sss will store the length of the array that is greater in length

    start();

    temp=L2.arr;
 
    for(int i=0; i<sss; i++) // compare the each element of the list
    {
        if(*curr!=*temp)
        {
            return false;
        }

        curr++;
        temp++;
    }

    return true;
} 



};

int main()
{
    int s, s1;
    cout<<"Enter size for array 1."<<endl;
    cin>>s;
    arrayImplementation obj(s); // creating object of the class
  
    arrayImplementation obj1(s); // creating object of the class

    arrayImplementation obj2(0); // creating object of the class

    int input; //this will store the user choice 

do //  using this loop for creating menu driven program
{
    cout<<"Enter the option number.Press 0 to exit."<<endl;
    cout<<"1)InsertElementAt()"<<endl;
    cout<<"2)PrintList"<<endl;
    cout<<"3)IsEmpty"<<endl;
    cout<<"4)IsFull"<<endl;
    cout<<"5)InsertElement()"<<endl;
    cout<<"6)SearchElement()"<<endl;
    cout<<"7)DeleteElement ()"<<endl;
    cout<<"8)ReverseList()"<<endl;
    cout<<"9)Length()"<<endl;
    cout<<"10)EmptyList"<<endl;
    cout<<"11)copyList()"<<endl;
    cout<<"12)sort()"<<endl;
    cout<<"13)compareList()"<<endl;

    cin>>input;

    switch (input)
    {

    case 1:
        int pos; int value;
        cout<<"Enter the position"<<endl;
        cin>>pos;
        cout<<"Enter the value"<<endl;
        cin>>value;
        obj.insertElementAt(value, pos);
        cout<<endl;
    break;

    case 2:
        obj.printList();
        cout<<endl;
    break;

    case 3:
        bool ans;
        ans=obj.IsEmpty();
        if(ans) 
        {
            cout<<"Array is empty"<<endl;
        }
        else
        {
            cout<<"Array is not empty"<<endl;
        }
        cout<<endl;
    break;

    case 4:
        bool ans1;
        ans1=obj.IsFull();
        if(ans1)
        {
            cout<<"Array is Full"<<endl;
        }
        else
        {
            cout<<"Array is not Full"<<endl;
        }
        cout<<endl;
    break;

    case 5:
        int vall;
        cout<<"Enter the Value you want to insert."<<endl;
        cin>>vall;
        obj.insertElement(vall);
        cout<<endl;
    break;

    case 6:
        int val;
        int poss;
        cout<<"Enter the value you want to search."<<endl;
        cin>>val;
        poss=obj.searchElement(val);
        cout<<"position = "<<poss;
        cout<<endl;
    break;

    case 7:
    int valll; bool a;
    cout<<"Enter the value you want to delete"<<endl;
    cin>>valll;
    a=obj.deleteElement(valll);
    if(a)
    {
        cout<<"Value is deleted"<<endl;
    }
    else
    {
        cout<<"Value doesnot exist"<<endl;
    }
    cout<<endl;
    break;

    case 8:
        obj.reverseList();
        cout<<endl;
    break;

    case 9:
        int l;
        l=obj.Length();
        cout<<"Length of the array ="<<l;
        cout<<endl;
    break;

    case 10:
        obj.emptyList();
        cout<<endl;
    break;

    case 11:
    obj.copyList(obj,obj1);
    cout<<endl;
    break;

    case 12:
    obj.sort();
    break;

    case 13:
    bool c;
    c=obj.compareList(obj,obj2);
    if(c)
    {
        cout<<"Lists are same."<<endl;
    }
    else
    {
        cout<<"Lists are not same."<<endl;
    }
    break;
    
    default:
        cout<<"Enter correct option number."<<endl;
    break;

    }
}while (input!=0);

    return 0;
}
