#pragma once

namespace util
{
    enum class States
    {
        NONE, State1, State2, State3
    };

    class State
    {
    public:
        // public functions
        inline virtual void OnEnd() {};
        inline virtual void OnBegin() {};
        inline virtual void OnUpdate() {};
        inline virtual States type() = 0;
    };

    class State1 : public State
    {
    public:
        // public functions
        inline virtual void OnEnd() { std::cout << "\t- State 1 :: ended!\n"; };
        inline virtual void OnBegin() { std::cout << "\t- State 1 :: started!\n"; };
        inline virtual void OnUpdate() { std::cout << "\t- State 1 :: updated!\n";  };
        inline virtual States type() { return States::State1; };
    };

    class State2 : public State
    {
    public:
        // public functions
        inline virtual void OnEnd() { std::cout << "\t- State 2 :: ended!\n"; };
        inline virtual void OnBegin() { std::cout << "\t- State 2 :: started!\n"; };
        inline virtual void OnUpdate() { std::cout << "\t- State 2 :: updated!\n"; };
        inline virtual States type() { return States::State2; };
    };

    class State3 : public State
    {
    public:
        // public functions
        inline virtual void OnEnd() { std::cout << "\t- State 3 :: ended!\n"; };
        inline virtual void OnBegin() { std::cout << "\t- State 3 :: started!\n"; };
        inline virtual void OnUpdate() { std::cout << "\t- State 3 :: updated!\n"; };
        inline virtual States type() { return States::State3; };
    };
}