#include "main.h"
#include <time.h>

// Print functions
void print(util::Iterator<util::HashComparable<int>> & obj)
{
    // print iterator
    if (&obj == obj.next()) return;
    if (obj.left() != nullptr) print(*obj.left());
    std::cout << "\t<< HashComparableIterator[" << &obj << "] >>\n";
    std::cout << "\t- iterator.value() = " << (int)obj << "\n";
    std::cout << "\t- iterator.right() = " << obj.right() << "\n";
    std::cout << "\t- iterator.left()  = " << obj.left() << "\n";
    std::cout << "\t- iterator.hash()  = " << obj.value().hash() << "\n\n";
    if (obj.right() != nullptr) print(*obj.right());
}
void print(util::HashMap<int> & obj)
{
    // print hash map
    std::cout << "<< HashMap | " << &obj << " >>\n\n";
    print(*obj.root());
}

// HashState :: definition
HashState::HashState(StateManager * manager)
{
    // initialize variables
    this->m_count = 1000;
    this->m_manager = manager;
}
void HashState::OnBegin()
{
    srand((unsigned int)time(NULL));
    // display state
    system("cls");
    std::cout << "<< HashState >>\n";
    std::cout << this->m_count << " tests to complete! \n";
    std::cout << "Press 'Esc' to go back to menu\n\n";
    system("pause");
}
void HashState::OnUpdate()
{
    // check if escape pressed
    if (GetKeyState(VK_ESCAPE) < 0 || this->m_count == 0)
    {
        // go back to menu
        print(this->m_hash);
        this->m_hash.erase();
        std::cout << "\n ~~ No Collisions! ~~ \n";
        system("pause");
        return this->m_manager->SetState(States::MenuState);
    }
    else
    {
        try
        {
            int cIndex = 0;
            // increment data
            for (int i = 0; i < 100; i++) this->m_string[i] = rand() % 0xff;
            // insert value to hash map
            this->m_hash.insert(this->m_string, this->m_count--);
        }
        catch (const char * message)
        {
            // error found
            std::cout << "\n\n ~~ COLLISION ERROR :: " << message << "\n ~~";
            system("pause");
            return this->m_manager->SetState(States::MenuState);
        }
        catch (...)
        {
            // error found
            std::cout << "UNKNOWN COLLISION ERROR\n";
            system("pause");
            return this->m_manager->SetState(States::MenuState);
        }
    }
}