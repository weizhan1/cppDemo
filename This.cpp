#include <iostream>
using namespace std;

class Dummy {
public:
    bool isitme (Dummy& param);    
};
bool Dummy::isitme (Dummy& param)
{
    if (&param == this) return true;
    else return false;
}
int main() {
    Dummy a;
    Dummy* b = &a;
    if (b->isitme(a)) 
        cout<<"yes, &a is b"<<endl;
    return 0; 
}

/*
 CVector& CVector::Operator=(const& 
 */

