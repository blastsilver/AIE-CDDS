#pragma once

enum class States
{
    MenuState, ListState, TreeState, HashState
};

class State
{
public:
    // public defaults
    inline virtual ~State() {};
    // public functions
    inline virtual void OnEnd() {};
    inline virtual void OnBegin() {};
    inline virtual void OnUpdate() {};
    inline virtual States type() = 0;
};

class MenuState : public State
{
protected:
    // variables
    bool m_key[3];
    StateManager * m_manager;
public:
    // public defaults
    MenuState(StateManager * manager);
    // public functions
    virtual void OnBegin();
    virtual void OnUpdate();
    inline virtual States type() { return States::MenuState; };
};

class TreeState : public State
{
protected:
    // variables
    int m_value;
    bool m_key[10];
    bool m_keyEnter;
    StateManager * m_manager;
    util::AATree<util::Comparable<int>> m_tree;
public:
    // public defaults
    TreeState(StateManager * manager);
    // public functions
    virtual void OnBegin();
    virtual void OnUpdate();
    inline virtual States type() { return States::TreeState; };
};

class HashState : public State
{
protected:
    // variables
    int m_count;
    char m_string[100];
    StateManager * m_manager;
    util::HashMap<int> m_hash;
public:
    // public defaults
    HashState(StateManager * manager);
    // public functions
    virtual void OnBegin();
    virtual void OnUpdate();
    inline virtual States type() { return States::HashState; };
};

class ListState : public State
{
protected:
    // variables
    int m_value;
    bool m_key[10];
    bool m_keyEnter;
    StateManager * m_manager;
    util::LinkedList<int> m_list;
public:
    // public defaults
    ListState(StateManager * manager);
    // public functions
    virtual void OnBegin();
    virtual void OnUpdate();
    inline virtual States type() { return States::ListState; };
};