#include "main.h"

// Print functions
void print(util::Iterator<util::Comparable<int>> & obj)
{
    // print iterator
    if (&obj == obj.next()) return;
    if (obj.left() != nullptr) print(*obj.left());
    std::cout << "\t<< ComparableIterator[" << &obj << "] >>\n";
    std::cout << "\t- iterator.value() = " << (int)obj << "\n";
    std::cout << "\t- iterator.level() = " << obj.level() << "\n";
    std::cout << "\t- iterator.right() = " << obj.right() << "\n";
    std::cout << "\t- iterator.left()  = " << obj.left() << "\n\n";
    if (obj.right() != nullptr) print(*obj.right());
}
void print(util::AATree<util::Comparable<int>> & obj)
{
    // print aa tree
    std::cout << "<< AATree | " << &obj << " >>\n\n";
    print(*obj.root());
}

// TreeState :: definition
TreeState::TreeState(StateManager * manager)
{
    // initialize variables
    this->m_value = 0;
    this->m_manager = manager;
    this->m_keyEnter = false;
    for (int i = 0; i < 10; i++) this->m_key[i] = false;
}
void TreeState::OnBegin()
{
    // display state
    system("cls");
    std::cout << "<< TreeState >>\n";
    std::cout << "Press 'Esc' to go back to menu\n";
    std::cout << "Type a number and press enter to add to tree\n\n";
    std::cout << "\tnumber = ";
}
void TreeState::OnUpdate()
{
    // check if escape pressed
    if (GetAsyncKeyState(VK_ESCAPE) < 0)
    {
        // go back to menu
        std::cout << ";\n\n";
        print(this->m_tree);
        system("pause");
        this->m_manager->SetState(States::MenuState);
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
                this->m_tree.insert(util::Comparable<int>(this->m_value));
                // ask for new number
                this->m_value = 0;
                this->m_keyEnter = false;
                std::cout << "\tnumber = ";
            }
        }
    }
}