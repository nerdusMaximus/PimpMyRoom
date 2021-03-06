//
//  SceneObject.hpp
//  FinalProject
//
//  Created by Ronald Brenner on 22.08.17.
//  Copyright © 2017 rapidRonald. All rights reserved.
//

#ifndef SceneObject_hpp
#define SceneObject_hpp

#include <stdio.h>
#include <vector>
#include "ResourceManager.hpp"


class SceneObject
{
public:
	std::vector<SceneObject> children = {};
	
	glm::vec3 position = glm::vec3(0.0);
	GLfloat angle = 0.0;
	unsigned int type = 0;
	std::string path = "";
	
	SceneObject();
		
	void setType(unsigned int typeParam);
	void setPosition(glm::vec3 positionParam);
	void setAngle(GLfloat angleParam);
	void setPath(std::string pathParam);
	void draw(ResourceManager &resourceManager);
};

#endif /* SceneObject_hpp */
