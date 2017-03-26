//
// Created by Stephen Clyde on 3/4/17.
//

#include "Region.h"
#include "Utils.h"
#include "World.h"
#include "Nation.h"
#include "State.h"
#include "County.h"
#include "City.h"

#include <iomanip>

const std::string regionDelimiter = "^^^";
const int TAB_SIZE = 4;
unsigned int Region::m_nextId = 0;

Region* Region::create(std::istream &in)
{
    Region* region = nullptr;
    std::string line;
    std::getline(in, line);
    if (line!="")
    {
        region = create(line);
        if (region!= nullptr)
            region->loadChildren(in);
    }
    return region;
}
Region* Region::create(const std::string& data)
{
    Region* region = nullptr;
    std::string regionData;
    unsigned long commaPos = (int) data.find(",");
    if (commaPos != std::string::npos)
    {
        std::string regionTypeStr = data.substr(0,commaPos);
        regionData = data.substr(commaPos+1);

        bool isValid;
        RegionType regionType = (RegionType) convertStringToInt(regionTypeStr, &isValid);

        if (isValid)
        {
            region = create(regionType, regionData);
        }

    }

    return region;
}

Region* Region::create(RegionType regionType, const std::string& data)
{
    Region* region = nullptr;
    std::string fields[3];
    if (split(data, ',', fields, 3)) {

        // Create the region based on type
        switch (regionType) {
            case WorldType:
                region = new World();
                break;
            case NationType:
                region = new Nation(fields);
                break;
            case StateType:
                region = new State(fields);
                break;
            case CountyType:
                region = new County(fields);
                break;
            case CityType:
                region = new City(fields);
                break;
            default:
                break;
        }

        // If the region isn't valid, git ride of it
        if (region != nullptr && !region->getIsValid()) {
            delete region;
            region = nullptr;
        }
    }

    return region;
}

std::string Region::regionLabel(RegionType regionType)
{
    std::string label = "Unknown";
    switch (regionType)
    {
        case Region::WorldType:
            label = "World";
            break;
        case Region::NationType:
            label = "Nation";
            break;
        case Region::StateType:
            label = "State";
            break;
        case Region::CountyType:
            label = "County";
            break;
        case Region::CityType:
            label = "City";
            break;
        default:
            break;
    }
    return label;
}

Region::Region() { }

Region::Region(RegionType type, const std::string data[]) :
        m_id(getNextId()), m_regionType(type), m_isValid(true)
{
    m_name = data[0];
    m_population = convertStringToUnsignedInt(data[1], &m_isValid);
    if (m_isValid)
        m_area = convertStringToDouble(data[2], &m_isValid);
}

Region::~Region()
{
    for (int i = 0; i < mySubRegions.size(); ++i) {
        delete mySubRegions[i];
    }
}

std::string Region::getRegionLabel() const
{
    return regionLabel(getType());
}

unsigned int Region::computeTotalPopulation()
{
    unsigned int totalPopulation = 0;
    if (getSubRegionCount() == 0)
    {
        totalPopulation = m_population;
    }
    else
    {
        totalPopulation = m_population + computeTotalPopulationHelper();
    }
    return totalPopulation;
}

unsigned int Region::computeTotalPopulationHelper() {
    if (getSubRegionCount() == 0)
    {
        return getPopulation();
    }
    else
    {
        unsigned int totalPopulation = 0;
        for (int i = 0; i < mySubRegions.size(); ++i) {
            totalPopulation += mySubRegions[i]->computeTotalPopulationHelper();
        }
        return totalPopulation;
    }
}

void Region::list(std::ostream& out)
{
    out << std::endl;
    out << getName() << ":" << std::endl;

    for (int i = 0; i < mySubRegions.size(); ++i) {
        out << mySubRegions[i]->getId() << " " << mySubRegions[i]->getName() << std::endl;
    }
}

void Region::display(std::ostream& out, unsigned int displayLevel, bool showChild)
{
    if (displayLevel>0)
    {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    unsigned totalPopulation = computeTotalPopulation();
    double area = getArea();
    double density = (double) totalPopulation / area;

    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    if (showChild)
    {
        for (int i = 0; i < mySubRegions.size(); ++i) {
            mySubRegions[i]->display(out, displayLevel, false);
        }
    }
}

void Region::save(std::ostream& out)
{
    out << getType()
        << "," << getName()
        << "," << getPopulation()
        << "," << getArea()
        << std::endl;

    // TODO: implement loop in save method to save each sub-region
    // foreach subregion,
    //      save that region
    for (int i = 0; i < mySubRegions.size(); ++i) {
        mySubRegions[i]->save(out);
    }
    out << regionDelimiter << std::endl;
}

void Region::validate()
{
    m_isValid = (m_area!=UnknownRegionType && m_name!="" && m_area>=0);
}

void Region::loadChildren(std::istream& in)
{
    std::string line;
    bool done = false;
    while (!in.eof() && !done)
    {
        std::getline(in, line);
        line = trim(line);
        if (line==regionDelimiter)
        {
            done = true;
        }
        else
        {
            Region* child = create(line);
            if (child!= nullptr)
            {
                mySubRegions.push_back(child);
                child->loadChildren(in);
            }
        }
    }
}

unsigned int Region::getNextId()
{
    if (m_nextId==UINT32_MAX)
        m_nextId=1;

    return m_nextId++;
}

//my lovely added functions
void Region::add(Region* rPtr) {
    mySubRegions.push_back(rPtr);
}

int Region::getSubRegionCount() {
    return mySubRegions.size();
}

Region* Region::getSubAtID(int id) {
    for (int i = 0; i < mySubRegions.size(); ++i) {
        if (mySubRegions[i]->getId() == id)
        {
            return mySubRegions[i];
        }
    }
    return nullptr;
}