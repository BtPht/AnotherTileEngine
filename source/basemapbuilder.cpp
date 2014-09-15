#include "basemapbuilder.h"

BaseMapBuilder::BaseMapBuilder() :
        result(new BaseMap)
{
}

BaseMapBuilder::~BaseMapBuilder()
{
        if(file.is_open()) file.close();
}

BaseMap BaseMapBuilder::createBaseMap_Planar(const std::string& filename)
{
        file.open(filename.c_str());

        BaseMap *result = createBaseMap_PlanarUnsafe();

        file.close();

        return *result;
}

BaseMap *BaseMapBuilder::createBaseMap_PlanarUnsafe()
{
        if(file.is_open())
                return createBaseMap_PlanarSafe();
        else return new BaseMap;
}

BaseMap *BaseMapBuilder::createBaseMap_PlanarSafe()
{
        loadTileset();
        loadRects() ;
        createMap() ;

        return result;
}

void BaseMapBuilder::loadTileset()
{
        TexturesManager *manager = TexturesManager::getInstance();

        std::string str;
        bool has_transparency;

        //chargement des fichiers de tilsets

        file >> str >> has_transparency;

        if(!has_transparency){
                result->tileset.push_back(manager->getTexture(str));
        }
        else{
                throw "lecture d'un tilset avec transparence. Erreur : non implémenté";
        }
}

void BaseMapBuilder::loadRects(){

        unsigned int nbSprites, nbRects;
        unsigned int idSpriteRead, x, y, w, h;

        file >> nbSprites >> nbRects;

        rectsSprites.resize(nbSprites,std::vector<sf::IntRect>(0));

        for (unsigned int i = 0 ; i < nbRects ; ++i) {
                file >> idSpriteRead >> x >> y >> w >> h;
                rectsSprites[idSpriteRead].push_back(sf::IntRect(x, y, w, h));
        }
}

void BaseMapBuilder::createMap()
{
        unsigned int nbSpritesInMap, nbLayers;
        unsigned int id_map, x, y, layer, practibility;
        std::string str;

        file >> nbSpritesInMap >> nbLayers;

        result->sprites.resize(nbLayers, std::vector<RichObject>(0));


        for (unsigned int i = 0 ; i < nbSpritesInMap ; ++i) {
                file >> id_map >> x >> y >> layer >> str >> practibility;

                result->sprites[layer].push_back(
                                        RichObject(AnimatedSprite(result->tileset[0]), str)
                                );

                for(auto &i : rectsSprites[id_map]){
                        result->sprites[layer].back().addAnimation(i);
                }

                result->sprites[layer].back().setPosition(x,y);
                result->sprites[layer].back().setPractibility(practibility);
        }
}
