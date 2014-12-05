/* 
 * File:   entity.cpp
 * Author: Matt Lynam <lynam.matt@gmail.com>
 *
 * Created on December 2, 2014
 * 
 * The MIT License (MIT)
 *
 * Copyright (c) December 2, 2014 Matt Lynam <lynam.matt@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * UTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "entity.h"

namespace cec = crucible::engine::core;

cec::Entity::Entity() 
: component_map_({}) 
, id_(CreateId()) {   
}

cec::Entity::Entity(const Component::ComponentMap& components)
  : component_map_(components)
  , id_(CreateId()) {
}

cec::Entity::Entity(Entity&& other) 
: component_map_(other.component_map_)
, id_(other.id_) {
  // invalidate other
  other.id_ = 0;
  other.component_map_ = {};
}

cec::Entity::~Entity() {
  // reclaim the id
  ReclaimId(id_);
}

cec::Entity& cec::Entity::operator=(Entity&& other) {
  component_map_ = other.component_map_;
  id_ = other.id_;
  // invalidate other
  other.id_ = 0;
  other.component_map_ = {};
  return *this;
}

void cec::Entity::AddComponent(const UInt& bucket, const UInt& bit) {
  // TODO: confirm we won't attempt an out of range access of bit_field
  component_map_.bit_field[bucket] |= bit;
}

void cec::Entity::RemoveComponent(const UInt& bucket, const UInt& bit) {
  // TODO: confirm we won't attempt an out of range access of bit_field
  component_map_.bit_field[bucket] &= ~bit;
}

cec::UInt cec::Entity::CreateId() {
  UInt id;
  if (id_queue_.size() > 0) {
    mtx_.lock();
    id = id_queue_.front();
    // remove reused id
    id_queue_.pop();
    mtx_.unlock();
  }
  else {
    id = id_counter_++;
  }
  return id;
}

void cec::Entity::ReclaimId(const UInt& id) {
  // TODO: lock
  mtx_.lock();
  id_queue_.push(id);
  mtx_.unlock();
}

cec::Entity::IdRecycleQueue cec::Entity::id_queue_ = { };
cec::UInt cec::Entity::id_counter_ = 1;
std::mutex cec::Entity::mtx_;