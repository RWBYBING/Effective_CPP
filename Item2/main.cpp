#include <iostream>
#include <memory>

// Item 2: Prefer consts, enums, and inlines to #defines
// Sometimes we would define some constant value using #define, like this
#define ASPECT_RATIO 1.653

// Actually, simple constants, prefer const objects or enums to #defines
// The compiler won't show errors about ASPECT_RATIO if there is an error
// Here are some better ways to handle constants
// 1. consts
const double AspectRatio = 1.653;
const char * const authorName = "Scott Meyers";

class GamePlayer
{
private:
    static const int NumTurns = 5;      // constant declaration, which is determined at compile-time
    int scores[NumTurns];               // use of constant

    // another way for constants: enum hack
    enum { NumTurns_Enum_Hack = 5 };
    int scores_enum_hack[NumTurns_Enum_Hack];

public:
    const int getNumTurns()
    {
        return NumTurns;
    }

    const int& getNumTurnsReference()
    {
        return NumTurns;
    }

    const int getNumTurnsEnumHack()
    {
        return NumTurns_Enum_Hack;
    }

    // this is not going to work as well
    // const int& getNumTurnsEnumHackReference()
    // {
    //     return NumTurns_Enum_Hack;
    // }
};

// Also, function-like macros, prefer inline functions to #defines
// #define function will lead to some unexpected results, see the example in main function

// #define version:
#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))



// better way
template <typename T>
inline void callWithMax(const T& a, const T& b)
{
    ((a) > (b) ? (a) : (b));
}

int main()
{
    std::unique_ptr<GamePlayer> gamePlayer = std::make_unique<GamePlayer>();
    // this will work
    std::cout << gamePlayer->getNumTurns() << std::endl;
    // this will not work
    // Because we only declared this constant and did not allocate actual memory
    // std::cout << gamePlayer->getNumTurnsReference();

    // the another way of doing this is to use Enum Hack
    std::cout << gamePlayer->getNumTurnsEnumHack() << std::endl;

    int a = 5, b = 0;
    // #define functions' weird phenomenon
    CALL_WITH_MAX(++a, b);          // a is incremented twice
    CALL_WITH_MAX(++a, b+10);       // a is incremented once

    int c = 5, d = 0;
    // inline function works well
    callWithMax(++c, d);
    callWithMax(++c, d+10);

    std::cout << a << std::endl;
    std::cout << c << std::endl;

    return 0;
}