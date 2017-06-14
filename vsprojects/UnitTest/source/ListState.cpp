#include "main.h"

// Print functions
void print(util::Iterator<int> & obj)
{
    // print iterator
    if (&obj == obj.next()) return;
    std::cout << "\t<< Iterator[" << &obj << "] >>\n";
    std::cout << "\t- iterator.value() = " << (int)obj << "\n";
    std::cout << "\t- iterator.right() = " << obj.right() << "\n";
    std::cout << "\t- iterator.left()  = " << obj.left() << "\n\n";
    if (obj.next() != nullptr) print(*obj.next());
}
void print(util::LinkedList<int> & obj)
{
    // print linked list
    std::cout << "<< LinkedList | " << &obj << " >>\n\n";
    if (obj.head() != nullptr) print(*obj.head());
}

// TreeState :: definition
ListState::ListState(StateManager * manager)
{
    // initialize variables
    this->m_value = 0;
    this->m_manager = manager;
    this->m_keyEnter = false;
    for (int i = 0; i < 10; i++) this->m_key[i] = false;
}
void ListState::OnBegin()
{
    // display state
    system("cls");
    std::cout << "<< ListState >>\n";
    std::cout << "Press 'Esc' to go back to menu\n";
    std::cout << "Type a number and press enter to add to list\n\n";
    std::cout << "\tnumber = ";
}
void ListState::OnUpdate()
{
    // check if escape pressed
    if (GetAsyncKeyState(VK_ESCAPE) < 0)
    {
        // go back to menu
        std::cout << ";\n\n";
        print(this->m_list);
        system("pause");
        this->m_manager->set(States::MenuState);
    }
    else
    {
        // go through number keys
        for (int i = 0; i < 10; i++)
        {
            // check number pressed
            if (GetAsyncKeyState('0' + i) < 0) this->m_key[i] = true; else
            {
                // check if key down
                if (this->m_key[i])
                {
                    this->m_key[i] = false;
                    std::cout << char('0' + i);
                    this->m_value = this->m_value * 10 + i;
                }
            }
        }
        // check if enter pressed
        if (GetAsyncKeyState(VK_RETURN) < 0) this->m_keyEnter = true; else
        {
            // check if key down
            if (this->m_keyEnter)
            {
                // print tree
                if (m_value == 0) std::cout << 0;
                std::cout << ";\n";
                this->m_list.insert(util::Comparable<int>(this->m_value));
                // ask for new number
                this->m_value = 0;
                this->m_keyEnter = false;
                std::cout << "\tnumber = ";
            }
        }
    }
}