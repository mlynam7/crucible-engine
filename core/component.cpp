/* 
 * File:   component.cpp
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

#include "component.h"

namespace cec = crucible::engine::core;

cec::Component::Component() 
: id_(id_factory_.CreateId()) {
    
}
cec::Component::Component(Component&& other) 
  : id_(id_factory_.CreateId()) {
  // invalidate the other
  other.id_ = 0;
}
cec::Component::Component(const Component& other) 
  : id_(id_factory_.CreateId())
  , register_id_(other.register_id_) {
  
}

cec::Component& cec::Component::operator =(Component&& other) {
  
}

cec::Component& cec::Component::operator =(const Component&& other) {
  
}

cec::Component::~Component() {
    
}

cec::Component::RegisterId cec::Component::RegisterComponent(const UInt& family, 
                                                             const UInt& bit) {
  // validate input
  if (family > kMaxComponentBuckets)
    // return invalid id.
    return {};
  if (component_register_.bit_field[family] & bit == bit)
    // component is already registered to this family & bit, return invalid id.
    return {};
  // set bit
  component_register_.bit_field[family] |= bit;  
  return {family, bit};
}

void cec::Component::UnRegisterComponent(const UInt& family, const UInt& bit) {
  if (family > kMaxComponentBuckets)
    return;
  component_register_.bit_field[family] &= ~bit;
}

cec::Component::ComponentMap cec::Component::component_register_ = { };