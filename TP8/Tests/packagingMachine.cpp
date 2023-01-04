#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}

// ---------------------------------------------


unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    int count = 0;
    vector<Object> new_objs;
    for (Object& obj : objs) {
        if (obj.getWeight() <= boxCapacity) {
            objects.push(obj);
            count++;
        }
        else {new_objs.push_back(obj);}
    }
    objs = new_objs;
	return count;
}



Box PackagingMachine::searchBox(Object& obj) {
    priority_queue<Box> aux = boxes;
    priority_queue<Box> final;
    Box box;
    bool found = false;
    while (!aux.empty()) {
        Box u = aux.top();
        aux.pop();
        if (u.getFree() >= obj.getWeight() && !found) {
            box = u;
            found = true;
        }
        else {final.push(u);}
    }
    boxes = final;
    return box;
}


unsigned PackagingMachine::packObjects() {
    priority_queue<Object> aux = objects;
    priority_queue<Box> aux_boxes = boxes;

    unsigned int count = 0;

    while (!aux.empty() && !aux_boxes.empty()) {
        Box b;
        Object u = aux.top();
        if (b.getFree() >= u.getWeight()) {
            b.addObject(u);
            aux.pop();
        }
        else {
            b = aux_boxes.top();
            if (b.getFree() < u.getWeight()) break;
            b.addObject(u);
            aux.pop();
            aux_boxes.pop();
            count++;
        }
    }

	return count;
}

// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
	return res;
}



