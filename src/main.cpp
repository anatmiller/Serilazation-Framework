#include "pch.h"
#include <string>
#include <iostream>       // std::cout
#include <cstddef>        // std::size_t
#include <utility>


#include "Circle.h"
#include "vector"
#include "OutArchive.h"
#include "InArchive.h"

using namespace std;

int main()
{
    std::vector<std::shared_ptr<Base>> objects;
    objects.push_back(std::make_shared<point>(1.0f,2.0f));
    objects.push_back(std::make_shared<point>(50.0f,12.0f));
    objects.push_back(std::make_shared<Circle>(5.0f,10.0f,10));

    OutArchive write_archive("out.dat");
    write_archive.write(objects);

    std::vector<std::shared_ptr<Base>> loaded_objects;
    InArchive read_archive("out.dat");
    read_archive.read(loaded_objects);
}
