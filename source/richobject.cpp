#include "richobject.h"

RichObject::RichObject()
{
}

RichObject::RichObject(const AnimatedSprite &p_anim, const std::string &p_name)
        :AnimatedSprite(p_anim),
          practibility(1.0),
          name(p_name)
{
}

RichObject::~RichObject() {
        // TODO Auto-generated destructor stub
}


float RichObject::getPractibility() const {
        return practibility;
}

void RichObject::setPractibility(const float &p_practibility) {
        this->practibility = p_practibility;
}

const std::string& RichObject::getName() const {
        return name;
}

void RichObject::setName(const std::string &name) {
        this->name = name;
}
