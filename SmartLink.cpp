#include "Shared.h"
#include <iostream>

int main()
{

    if (true) {
        shared_ptr_toy q1;
        shared_ptr_toy q = shared_ptr_toy("Bone");
        if (true) {
            shared_ptr_toy n1 = shared_ptr_toy();
            q1 = n1;
            shared_ptr_toy n = q;
            shared_ptr_toy m = q;
        }
    }
    
}

