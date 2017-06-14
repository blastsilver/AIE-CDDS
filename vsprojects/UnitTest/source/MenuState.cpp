#include "main.h"

// MenuState :: definition
MenuState::MenuState(StateManager * manager)
{
    // initialize variables
    this->m_key[0] = false;
    this->m_key[1] = false;
    this->m_key[2] = false;
    this->m_manager = manager;
}
void MenuState::OnBegin()
{
    // display state
    system("cls");
    std::cout << "Press one of the keys to continue!\n\n";
    std::cout << "\t - Press '1' for AA Tree;\n";
    std::cout << "\t - Press '2' for Hash Map;\n";
    std::cout << "\t - Press '3' for Linked List;\n";
}
void MenuState::OnUpdate()
{
    if (GetKeyState('1') < 0) this->m_key[0] = true; else
    {
        // continue to tree state
        if (this->m_key[0]) return this->m_manager->set(States::TreeState);
    }
    if (GetKeyState('2') < 0) this->m_key[1] = true; else
    {
        // continue to hash state
        if (this->m_key[1]) return this->m_manager->set(States::HashState);
    }
    if (GetKeyState('3') < 0) this->m_key[2] = true; else
    {
        // continue to list state
        if (this->m_key[2]) return this->m_manager->set(States::ListState);
    }
}