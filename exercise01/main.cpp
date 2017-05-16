#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "gpio_class.h"

using namespace std;

int main (void)
{

    string inputstate;
    GPIOClass* gpio18 = new GPIOClass("18"); //create new GPIO object to be attached to  GPIO18
    GPIOClass* gpio17 = new GPIOClass("17"); //create new GPIO object to be attached to  GPIO17

    gpio18->export_gpio(); //export GPIO18

    cout << " GPIO pins exported" << endl;

    gpio18->setdir_gpio("out"); // GPIO18 set to output

    cout << " Set GPIO pin directions" << endl;

    while(1)
    {
        gpio18->setval_gpio("1"); // turn LED ON
        usleep(1000000);  // wait for 1 second
        gpio18->setval_gpio("0"); // turn LED ON
        usleep(1000000);  // wait for 1 second

    }
    cout << "Exiting....." << endl;
    return 0;
}
