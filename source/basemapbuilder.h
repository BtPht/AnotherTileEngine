/*
 * PlanarBaseMapBuilder.h
 *
 *  Created on: 6 oct. 2013
 *      Author: bertrand
 */

#ifndef PLANARBASEMAPBUILDER_H_
#define PLANARBASEMAPBUILDER_H_

#include "basemap.h"

//#include <boost/property_tree/xml_parser.hpp>

class BaseMapBuilder {
public:
        BaseMapBuilder();
        virtual ~BaseMapBuilder();

        BaseMap createBaseMap_Planar(const std::string &filename);

private :
        BaseMap *createBaseMap_PlanarSafe();
        BaseMap *createBaseMap_PlanarUnsafe();
        void loadTileset();
        void loadRects();
        void createMap();

        std::ifstream file;
        BaseMap *result;
        std::vector<std::vector<sf::IntRect>> rectsSprites;
};

#endif /* PLANARBASEMAPBUILDER_H_ */
