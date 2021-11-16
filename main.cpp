/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {}  //1
    int value;
    std::string name;
};

struct C                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float thing1 { 0 }, thing2 { 0 };
    float updaterTimes(const float& updatedValue)      //12
    {
        std::cout << "U's thing1 value: " << this->thing1 << std::endl;
        this->thing1 = updatedValue;
        std::cout << "U's thing1 updated value: " << this->thing1 << std::endl;
        while( std::abs(this->thing2 - this->thing1) > 0.001f )
        {
            this->thing2 += 0.01f;
        }
        std::cout << "U's thing2 updated value: " << this->thing2 << std::endl;
        return this->thing2 * this->thing1;
    }
};

struct Z
{
    static float updaterMultiply(U& that, const float& updatedValue )        //10
    {
        std::cout << "U's thing1 value: " << that.thing1 << std::endl;
        that.thing1 = updatedValue;
        std::cout << "U's thing1 updated value: " << that.thing1 << std::endl;
        while( std::abs(that.thing2 - that.thing1) > 0.001f )
        {
            that.thing2 += 0.01f;
        }
        std::cout << "U's thing2 updated value: " << that.thing2 << std::endl;
        return that.thing2 * that.thing1;
    }  
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1( 5, "a");                                             //6
    T t2( 7, "b");                                             //6
    
    C f;                                            //7
    const auto& smaller = f.compare(t1, t2);  
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Z::updaterMultiply( u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.updaterTimes( updatedValue ) << std::endl;
}
