#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "asteroid.h"
#include "spaceship.h"

void press_any_key()
{
    std::cout << "\n Press any key... ";
    _getch();
}

int main()
{
    std::atexit(press_any_key);

    asteroid aster(12345);
    spaceship ship("Alfa-Romeo");
    object obj;
    object obj_aster = asteroid(67890);
    object obj_ship = spaceship("Omega-Juliette");
    asteroid aster_obj = obj_aster;
    spaceship ship_obj = obj_ship;

    auto check_variables = [&]()
    {
        std::cout << std::boolalpha << "\n Test for null:"
            << "\n\t aster.is_null(): " << aster.is_null()
            << "\n\t ship.is_null(): " << ship.is_null()
            << "\n\t obj.is_null(): " << obj.is_null()
            << "\n\t obj_aster.is_null(): " << obj_aster.is_null()
            << "\n\t obj_ship.is_null(): " << obj_ship.is_null()
            << "\n\t aster_obj.is_null(): " << aster_obj.is_null()
            << "\n\t ship_obj.is_null(): " << ship_obj.is_null()
            << std::endl;

        std::cout << "\n Test for data class:"
            << "\n\t aster.data_class(): " << aster.data_class()
            << "\n\t ship.data_class(): " << ship.data_class()
            << "\n\t obj.data_class(): " << obj.data_class()
            << "\n\t obj_aster.data_class(): " << obj_aster.data_class()
            << "\n\t obj_ship.data_class(): " << obj_ship.data_class()
            << "\n\t aster_obj.data_class(): " << aster_obj.data_class()
            << "\n\t ship_obj.data_class(): " << ship_obj.data_class()
            << std::endl;

        std::cout << "\n Test identification:"
            << "\n\t aster.get_identifier(): " << aster.get_identifier()
            << "\n\t ship.get_name(): " << ship.get_name()
            << "\n\t aster_obj.get_identifier(): " << aster_obj.get_identifier()
            << "\n\t ship_obj.get_name(): " << ship_obj.get_name()
            << std::endl;
    };

    std::cout << "\n ======== Check after constructors ========" << std::endl;
    check_variables();

    aster = asteroid(335577);
    ship = spaceship("Ramambahara");
    obj = object();
    obj_aster = asteroid(446688);
    obj_ship = spaceship("Mamburu");
    aster_obj = obj_aster;
    ship_obj = obj_ship;

    std::cout << "\n ======== Check after assignments ========" << std::endl;
    check_variables();

    return 0;
}
