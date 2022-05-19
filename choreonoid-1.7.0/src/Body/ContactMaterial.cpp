/**
   \file
   \author Shin'ichiro Nakaoka
*/

#include "ContactMaterial.h"

using namespace cnoid;


ContactMaterial::ContactMaterial()
{
    init();
    info_ = new Mapping;
}


ContactMaterial::ContactMaterial(const ContactMaterial& org)
{
    staticFriction_ = org.staticFriction_;
    dynamicFriction_ = org.dynamicFriction_;
    restitution_ = org.restitution_;

    info_ = org.info_->cloneMapping();
}


ContactMaterial::ContactMaterial(const Mapping* info)
{
    init();
    info_ = info->cloneMapping();

    double mu;
    if(info_->extract("friction", mu)){
        setFriction(mu);
    }
    info_->extract("staticFriction", staticFriction_);
    info_->extract("dynamicFriction", dynamicFriction_);

    info_->extract("restitution", restitution_);
}


ContactMaterial::~ContactMaterial()
{

}

void ContactMaterial::init()
{
    staticFriction_ = 0.5;
    dynamicFriction_ = 0.5;
    restitution_ = 0.0;
}


template<> double ContactMaterial::info(const std::string& key, const double& defaultValue) const
{
    double value;
    if(info_->read(key, value)){
        return value;
    }
    return defaultValue;
}


template<> bool ContactMaterial::info(const std::string& key, const bool& defaultValue) const
{
    bool value;
    if(info_->read(key, value)){
        return value;
    }
    return defaultValue;
}
