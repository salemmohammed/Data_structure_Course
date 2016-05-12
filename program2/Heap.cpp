#include "Heap.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

std::size_t get_parent(std::size_t pos)
{
    return (pos - 1) / 2;
}

std::size_t get_left(std::size_t pos)
{
    return 2*pos + 1;
}

std::size_t get_right(std::size_t pos)
{
    return 2*pos + 2;
}

bool is_valid_pos(std::vector<Player>& heap, std::size_t pos)
{
    return pos < heap.size();
}

Heap::Heap(string filename) 
{
    std::ifstream infile;
    infile.open(filename.c_str());  
    // reading from file
    /*

    Get C string equivalent
    Returns a pointer to an array that contains a null-terminated sequence of characters 
    (i.e., a C-string) representing the current value of the string object.
    */

    while (infile)
    {
        int budget;
        std::string name;
        std::string dummy;


        std::getline(infile, name);  //   std::getline (std::cin,name);

        if (name.size() == 0)
            //encountered an empty line, not allowed in middle of input, break and done.
            break;

        infile >> budget;   // cin >> input
        ///get the extraneous newline character
        std::getline(infile, dummy);


        Player player(name, budget);

        addPlayer(player);
    }

    infile.close();
}

Heap::Heap(const Heap& copy)
{
    internal_heap = copy.internal_heap;
}

void Heap::addPlayer(Player newPlayer)
{
    std::size_t current_pos = internal_heap.size();

    internal_heap.push_back(newPlayer);


    while (true)
    {
        ///if the current_pos is at the root
        if (current_pos == 0)
        {
            break;
        }

        auto& current = internal_heap[current_pos];

        ///the & means "reference", which means that parent will NOT make a copy, but rather
        /// be an "ALIAS" for the Player in the heap
        
        std::size_t parent_pos = get_parent(current_pos);

        auto& parent = internal_heap[parent_pos];

        if (current.getBudget() <= parent.getBudget())
            ///then the rules are satisfied, and we are done.
            break;

        ///       3
        ///      / \
        ///    100  2
        ///       100
        ///      / \
        ///     3   2

        ///simply swap in this case

        std::swap(internal_heap[current_pos], internal_heap[parent_pos]);
        current_pos = parent_pos;
    

    }
}

bool Heap::empty(){
    return internal_heap.size() == 0;
}
unsigned int Heap::size(){
    return internal_heap.size();
}
std::vector<Player> Heap::getArray(){
    return internal_heap;
}
Player Heap::getPlayer(){
    assert(!empty());

    ///return the root
    Player player = internal_heap[0];

    if (internal_heap.size() == 1)
    {
        internal_heap.pop_back();
        return player;
    }

    std::size_t current_pos = 0;
    std::size_t last_pos = internal_heap.size() - 1;

    std::swap(internal_heap[current_pos], internal_heap[last_pos]);

    internal_heap.pop_back();

    while (true)
    {
        auto& current = internal_heap[current_pos];

        if (!is_valid_pos(internal_heap,get_left(current_pos)))
            ///there is no children, and no rule is broken
            break;

        auto& left = internal_heap[get_left(current_pos)];

        if (!is_valid_pos(internal_heap,get_right(current_pos)))
        {
            ///only the left is in the heap

            if (left.getBudget() <= current.getBudget())
                ///then no rule is broken, and we are done
                break;

            std::swap(internal_heap[current_pos], internal_heap[get_left(current_pos)]);
            current_pos = get_left(current_pos);
            continue;
        }



        ///if we get to here, the is a valid left, and a valid right
        auto& right = internal_heap[get_right(current_pos)];

        if (left.getBudget() <= current.getBudget() && right.getBudget() <= current.getBudget())
            ///then no rule is broken, and we are done
            break;

        // std::cout << "current: " << internal_heap[current_pos].getBudget();
        // std::cout << ", left: " << internal_heap[get_left(current_pos)].getBudget();
        // std::cout << ", right: " << internal_heap[get_right(current_pos)].getBudget() << std::endl;
        if (left.getBudget() > right.getBudget())
        {
            ///swap the left
            std::swap(internal_heap[current_pos], internal_heap[get_left(current_pos)]);

            assert(internal_heap[current_pos].getBudget() >= internal_heap[get_left(current_pos)].getBudget());
            assert(internal_heap[current_pos].getBudget() >= internal_heap[get_right(current_pos)].getBudget());
            current_pos = get_left(current_pos);
        } else {
            std::swap(internal_heap[current_pos], internal_heap[get_right(current_pos)]);
            assert(internal_heap[current_pos].getBudget() >= internal_heap[get_left(current_pos)].getBudget());
            assert(internal_heap[current_pos].getBudget() >= internal_heap[get_right(current_pos)].getBudget());
            current_pos = get_right(current_pos);
        }
    }


    return player;
}