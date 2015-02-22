#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack { 
  private: 
    vector<T> elems;     // elements 

  public: 
    void push(T const&);  // push element 
    void pop();               // pop element 
    T top() const;            // return top element 
    bool empty() const{       // return true if empty.
        return elems.empty(); 
    } 
}; 

template <class T>
void Stack<T>::push (T const& elem) 
{ 
    // append copy of passed element 
    elems.push_back(elem);    
} 

template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
	// remove last element 
    elems.pop_back();         
} 

template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
	// return copy of last element 
    return elems.back();      
} 

int main() 
{ 
    try { 
        Stack<int>         intStack;  // stack of ints 
        Stack<string> stringStack;    // stack of strings 

        // manipulate int stack 
        intStack.push(7); 
        cout << intStack.top() <<endl; 

        // manipulate string stack 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
} 

template <class T>
class mypair {
    T values[2];
    public:
        mypair(T first, T second) {
            value[0]= first; 
            value[1]= second;
        };
};

template <class T>
class mypair {
    T a, b;
    public:
        mypair(T first, T second) {
            a=first;
            b=second;
        }
        T getmax();
};

tempplate <class T>
T mypair<T>::getmax() {
    T retval;
    retval = a>b?a:b;
    return retval;
}

int main() {
    mypair <int> myobject(100, 75);
    cout << myobject.getmax();
    return 0;
}

mypair<int> myobject(225, 36);

template <class T>
class mycontainer {
    T element;
    public:
        mycontainer (T arg) {element=arg;}
        T increase() { return ++element; }        
};

template <>
class mycontainer <char> {
    char element;
    public:
        mycontainer (char arg) {element=arg;}
        char uppercase() {
            if ((element>='a') && (element<='z'))
                element += 'A'-'a';
            return element;
        }
};  

int main() {
    mycontainer<int> myint(7);
    mycontainer<char> mychar('j');
    
    cout<<myint.increase()<<endl;
    cout<<mychar.uppercase()<<endl;
    return 0;
}

template <class T> class mycontainer { ... };
template <> class mycontainer <char> { ... };

template<typename T>
void f(T s)
{
    std::cout << s << '\n';
}
 
int main()
{
    f<double>(1); // instantiates and calls f<double>(double)
    f<>('a'); // instantiates and calls f<char>(char)
    f(7); // instantiates and calls f<int>(int)
    void (*ptr)(std::string) = f; // instantiates f<string>(string)
}

template<typename To, typename From> To convert(From f);
 
void g(double d) 
{
    int i = convert<int>(d); // calls convert<int,double>(double)
    char c = convert<char>(d); // calls convert<char,double>(double)
    int(*ptr)(float) = convert; // instantiates convert<int, float>(float)
}

template<class ... Types> void f(Types ... values);
void g() {
  f<int*, float*>(0, 0, 0); // Types = {int*, float*, int}
}

template< class T > void f(T);              // #1: template overload
template< class T > void f(T*);             // #2: template overload
void                     f(double);         // #3: nontemplate overload
template<>          void f(int);            // #4: specialization of #1
 
f('a');        // calls #1
f(new int(1)); // calls #2
f(1.0);        // calls #3
f(1);          // calls #

template< class T > void f(T);    // #1: overload for all types
template<>          void f(int*); // #2: specialization of #1 for pointers to int
template< class T > void f(T*);   // #3: overload for all pointer types
 
f(new int(1)); // calls #3, even though specialization of #1 would be a perfect match