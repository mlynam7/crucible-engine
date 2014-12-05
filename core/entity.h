/* 
 * File:   entity.h
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
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include <mutex>
#include <queue>
#include <memory>

#include "component.h"
#include "crucible.h"

namespace crucible {
namespace engine {
namespace core {

class Entity {
public:
  /* typedefs */
  typedef std::unique_ptr<Entity> UPEntity;
  typedef std::shared_ptr<Entity> SPEntity;
  typedef std::queue<UInt> IdRecycleQueue;
  
  /* ctor */
  Entity();
  explicit Entity(const Component::ComponentMap&);
  Entity(Entity&&);
  Entity(const Entity&) = delete;
  
  virtual ~Entity();
  
  /* operators */
  Entity& operator=(Entity&&);
  Entity& operator=(const Entity&) = delete;
  
  /* functions */
  void AddComponent(const UInt& bucket, const UInt& bit);
  void RemoveComponent(const UInt& bucket, const UInt& bit);
  const UInt& id() const { return id_; }
private:
  Component::ComponentMap component_map_;
  UInt id_;
  
  static IdRecycleQueue id_queue_;
  static UInt id_counter_;
  static std::mutex mtx_;
  
  /* functions */
  static UInt CreateId();
  static void ReclaimId(const UInt&);
};

} // namespace core
} // namespace engine
} // namespace crucible

#endif	/* ENTITY_H */

