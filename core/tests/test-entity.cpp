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
  
  if (entity.id() == 0)
    std::cout << "%TEST_FAILED% time=0 testname=CreateEntity (test-entity) message=Invalid Id"  << std::endl;
}

void test2() {
  std::cout << "test-entity test 2" << std::endl;
  std::cout << "%TEST_FAILED% time=0 testname=test2 (test-entity) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
  std::cout << "%SUITE_STARTING% test-entity" << std::endl;
  std::cout << "%SUITE_STARTED%" << std::endl;

  std::cout << "%TEST_STARTED% test1 (test-entity)" << std::endl;
  CreateEntity();
  std::cout << "%TEST_FINISHED% time=0 test1 (test-entity)" << std::endl;

  std::cout << "%SUITE_FINISHED% time=0" << std::endl;

  return (EXIT_SUCCESS);
}

