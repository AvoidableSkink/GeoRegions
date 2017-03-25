#include <fstream>
#include <iostream>

#include "World.h"
#include "WorldUserInterface.h"

int main()
{
    std::cout << "Welcome to the GeoRegions system" << std::endl << std::endl;

    // Create a world object
    World* world;

    // Load if from the data file, if possible
    std::ifstream inputStream("Nations.txt");
    if (inputStream.is_open())
    {
        // Try to load the first region in the field, which should be a world, and all of it's sub-regions
        Region* region = Region::create(inputStream);
        if (region!= nullptr && region->getType()==Region::WorldType)
        {
            world = (World*) region;
            std::cout << "Loaded a world and "  << world->getSubRegionCount() << " nations from Nations.txt" << std::endl;
        }
        else
        {
            world = new World();
            std::cout << "Problem loading Nation.txt -- created a new world" << std::endl;
        }
        inputStream.close();
    }
    else
    {
        world = new World();
        std::cout << "Created a new world" << std::endl;
    }

    // Run the main user interface
    WorldUserInterface mainUI(world);
    mainUI.run();

    // Save the world!
    std::ofstream outputStream("Nations.txt");
    if (outputStream.is_open())
    {
        world->save(outputStream);
    }
    outputStream.close();
}