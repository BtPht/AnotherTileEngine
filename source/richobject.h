#ifndef RICHOBJECT_H_
#define RICHOBJECT_H_

#include "animatedsprite.h"

class RichObject: public AnimatedSprite {
public:
        RichObject();
        RichObject(const AnimatedSprite &p_anim, const std::string &p_name= "default name");
        virtual ~RichObject();

        float getPractibility() const;
        void setPractibility(const float &p_practibility);

        const std::string& getName() const;
        void setName(const std::string& name);

private:
        float practibility = 1.0;
        std::string name = "";
};

#endif /* RICHOBJECT_H_ */
