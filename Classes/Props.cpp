#include"Props.h"

Props* Props::create(const std::string& PropImage) {
    Props* prop = new (std::nothrow) Props();
    if (prop && prop->initWithFile(PropImage)) {
        prop->autorelease();
      //  prop->Is_End = false;
        return prop;
    }
    CC_SAFE_DELETE(prop);
    return nullptr;
}
bool Props::TestEnding() {
    if (this->Last_time >= 0)
    {
        Last_time--;
        return false;
    }
    else{
        //Is_End = true;
        return true;
    }
}