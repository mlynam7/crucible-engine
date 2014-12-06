/* 
 * File:   test-entity.cpp
 * Author: Matt Lynam <lynam.matt@gmail.com>
 *
 * Created on Dec 4, 2014, 4:57:04 PM
 */

#include <stdlib.h>
#include <iostream>

#include <entity.h>

using namespace crucible::engine::core;

/*
 * Simple C++ Test Suite
 */

void CreateEntity() {
  std::cout << "test-entity CreateEntity" << std::endl;
  Entity entity = { };
  
  if (entity.id() != 1) {
    std::cout << "%TEST_FAILED% time=0 testname=CreateEntity (test-entity) ";
    std::cout << "message=Invalid Id"  << std::endl; 
  }
}

void RecycleEntityId() {
  std::cout << "test-entity RecycleEntityId" << std::endl;
  
  Entity entity[3];
  
  std::cout << "Entity id: " << entity[0].id() << std::endl;
  std::cout << "Entity id: " << entity[1].id() << std::endl;
  std::cout << "Entity id: " << entity[2].id() << std::endl;
  
  {
    Entity entity_single = { };
    std::cout << "entity_single id: " << entity_single.id() << std::endl;
  }
  
  Entity entity_single_recycled = { };
  std::cout << "entity_single_recycled id: " << entity_single_recycled.id();
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  std::cout << "%SUITE_STARTING% test-entity" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% CreateEntity (test-entity)" << std::endl;
  CreateEntity();
  std::cout << "%TEST_FINISHED% time=0 CreateEntity (test-entity)" << std::endl;

  std::cout << "%TEST_STARTED% RecycleEntityId (test-entity)" << std::endl;
  RecycleEntityId();
  std::cout << "%TEST_FINISHED% time=0 RecycleEntityId (test-entity)";
  std::cout << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}

