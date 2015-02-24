/*
Creational Pattern: SINGLETON
Author: Rajesh V.S
Language: C++
Email: rajeshvs@msn.com
*/

#include <iostream>

using namespace std;

class Singleton
{
private:
    static bool instanceFlag;
    static Singleton *single;
    Singleton()
    {
        //private constructor
    }
public:
    static Singleton* getInstance();
    void method();
    ~Singleton()
    {
        instanceFlag = false;
    }
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance()
{
    if(! instanceFlag)
    {
        single = new Singleton();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void Singleton::method()
{
    cout << "Method of the singleton class" << endl;
}

int main()
{
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();

    return 0;
}

/**
* Singleton pattern example with Double checked Locking
*/
public class DoubleCheckedLockingSingleton{
     private volatile DoubleCheckedLockingSingleton INSTANCE;
  
     private DoubleCheckedLockingSingleton(){}
  
     public DoubleCheckedLockingSingleton getInstance(){
         if(INSTANCE == null){
            synchronized(DoubleCheckedLockingSingleton.class){
                //double checking Singleton instance
                if(INSTANCE == null){
                    INSTANCE = new DoubleCheckedLockingSingleton();
                }
            }
         }
         return INSTANCE;
     }
}

/**
* Singleton pattern example with static factory method
*/

public class Singleton{
    //initailzed during class loading
    private static final Singleton INSTANCE = new Singleton();
  
    //to prevent creating another instance of Singleton
    private Singleton(){}

    public static Singleton getSingleton(){
        return INSTANCE;
    }
}

/** Preferred style for singletons. */
public enum SantaClaus {
  INSTANCE;
  
  /**Add some behavior to the object. */
  public void distributePresents(){
    //elided    
  }
  
  /** Demonstrate use of SantaClaus. */
  public static void main(String... aArgs){
    SantaClaus fatGuy = SantaClaus.INSTANCE;
    fatGuy.distributePresents();
    
    //doesn't compile :
    //SantaClaus fatGuy = new SantaClaus();
  }
} 

# Singleton/ClassVariableSingleton.py
class SingleTone(object):
    __instance = None
    def __new__(cls, val):
        if SingleTone.__instance is None:
            SingleTone.__instance = object.__new__(cls)
        SingleTone.__instance.val = val
        return SingleTone.__instance
