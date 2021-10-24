//
// Created by Bartosz Śnieg on 10.08.2021.
//

#include "AbstractGameObject.hpp"

void engine::object::AbstractGameObject::KeyboardKeyPressEvent(std::vector<event::Key> *keyList) {
    this->onKeyPressEvent(keyList);
    if(this->children!= nullptr)
        for (auto &i: *this->children) {
            i->KeyboardKeyPressEvent(keyList);
        }
}

void engine::object::AbstractGameObject::KeyboardKeyReleaseEvent(std::vector<event::Key> *keyList) {
    this->onKeyReleaseEvent(keyList);
    if(this->children!= nullptr)
        for (auto &i: *this->children) {
            i->KeyboardKeyReleaseEvent(keyList);
        }
}

void engine::object::AbstractGameObject::MouseKeyReleaseEvent(engine::event::MouseEvent e) {
    this->onMouseReleaseEvent(e);
    if(this->children!= nullptr)
        for (auto &i: *this->children) {
            i->MouseKeyReleaseEvent(e);
        }
}

void engine::object::AbstractGameObject::MouseKeyPressEvent(engine::event::MouseEvent e) {
    this->onMousePressEvent(e);
    if(this->children!= nullptr)
        for (auto &i: *this->children) {
            i->MouseKeyPressEvent(e);
        }
}

void engine::object::AbstractGameObject::destroyed() {
    this->onDestroyed();
    if(this->children!= nullptr)
        for (auto &i: *this->children) {
            i->destroyed();
        }

    delete this->children;
    this->children = nullptr;
}

void engine::object::AbstractGameObject::updateEvent() {
    this->onUpdate();
    if(this->children!= nullptr)
        for (auto& i: *this->children) {
            i->updateEvent();
        }
}

void engine::object::AbstractGameObject::initEvet() {
    this->onInit();
    if(this->children!= nullptr)
        for (auto &i: *this->children) {
            i->initEvet();
        }
}

void engine::object::AbstractGameObject::addChildren(engine::object::AbstractGameObject *obj) {
        if(this->children == nullptr)
            this->children = new std::vector<engine::object::AbstractGameObject*>();
        this->children->push_back(obj);

}

void engine::object::AbstractGameObject::deleteChildren(int id) {

    if(id>=0&& id<this->children->size())
    {
        this->children->erase(this->children->begin()+id);
    }else
    {
        throw engine::exception::OutOfRangeException("Index is out of range!!!!");
    }

}

engine::object::AbstractGameObject::~AbstractGameObject() {
    delete this->children;

}

int engine::object::AbstractGameObject::getId(AbstractGameObject *obj) {
    int a = -1;
    for (int i = 0; i < this->children->size(); ++i) {
        if(this->children->at(i) == obj)
        {
            a = i;
            break;
        }
    }
    return a;
}




