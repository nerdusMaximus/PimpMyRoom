//
//  main.cpp
//  FinalProject
//
//  Created by Ronald Brenner on 08.08.17.
//  Copyright © 2017 rapidRonald. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <iostream>
#include "Visualizer.hpp"
#include "Optimizer.hpp"

// ====================
// Main Function starts here
// ====================

int main(int argc, const char * argv[]) {
    
//  ==================
//	Create Test SceneObject
//	==================
    
	SceneObject firstChairObject = SceneObject();
	firstChairObject.setType(0);
    firstChairObject.length = 1.0;
    firstChairObject.height = 1.0;
    firstChairObject.width = 1.0;
    firstChairObject.init();
	
	SceneObject cupboardObject = SceneObject();
	cupboardObject.setType(2);
    //cupboardObject.setPosition(glm::vec3(4.5f, 0.0f, 4.5f));
    cupboardObject.length = 1.0;
    cupboardObject.height = 2.0;
	cupboardObject.width = 1.0;
    cupboardObject.init();
    
	SceneObject bookObject = SceneObject();
	bookObject.setType(20);
	bookObject.setPosition(glm::vec3(0.0f, 0.725f, 0.0f));
	
	SceneObject tableObject = SceneObject();
	tableObject.setType(1);
    tableObject.setPosition(glm::vec3(1.0f, 0.0f, 1.5f));
	tableObject.children.push_back(bookObject);
    tableObject.length = 2.0;
    tableObject.height = 1.2;
    tableObject.width = 3.0;
    tableObject.init();
    
	SceneObject wallObject = SceneObject();
	wallObject.setType(11);
	
	SceneObject floorObject = SceneObject();
	floorObject.setType(10);
	floorObject.setPosition(glm::vec3(0.0));
	floorObject.children.push_back(tableObject);
	floorObject.children.push_back(firstChairObject);
    floorObject.children.push_back(firstChairObject);
    floorObject.children.push_back(firstChairObject);
    floorObject.children.push_back(cupboardObject);
    floorObject.children.push_back(cupboardObject);
    floorObject.children.push_back(cupboardObject);
    floorObject.children.push_back(cupboardObject);

    
	SceneObject rootObject = SceneObject();
	rootObject.setType(99);
	rootObject.setPosition(glm::vec3( 0.0f,  0.0f,  0.0f));
	rootObject.children.push_back(wallObject);
	rootObject.children.push_back(floorObject);
    
    
    for(int i = 0; i < rootObject.children.size(); i++)
    {
        if(rootObject.children[i].type == 10)
        {
            Optimizer optimizer(rootObject.children[i], 1.0f, 0.0001f);
            rootObject.children[i]  = optimizer.optimize();
        }
    }
 
    tableObject.setPosition(glm::vec3(0.0f, 0.0f, 4.5f));
    rootObject.children.push_back(tableObject);
    
//	==================
//	Visualization part
//	==================

	Visualizer visualizer = Visualizer();
	visualizer.doVisualisation(&rootObject);
	return 0;
	
}
