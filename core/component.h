/* 
 * File:   component.h
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

#ifndef COMPONENT_H
#define	COMPONENT_H

#include <utility>
#include <memory>

#include "id_factory.h"
#include "crucible.h"

namespace crucible {
namespace engine {
namespace core {

class Component {
public:
  /* typdefs */
  typedef struct { UInt bit_field[kMaxComponentBuckets]; } ComponentMap;
  typedef std::unique_ptr<Component> UPComponent;
  typedef std::shared_ptr<Component> SPComponent;
  typedef std::pair<UInt, UInt> RegisterId;
  
  /* ctors */
  Component();
  Component(Component&&);
  Component(const Component&);
  
  /* operators */
  Component& operator=(Component&&);
  Component& operator=(const Component&&);
  
  virtual ~Component();
  
  /* functions */
  const RegisterId& register_id() const { return register_id_; }
  const UInt& id() const { return id_; }
protected:
  RegisterId register_id_;

  static RegisterId RegisterComponent(const UInt& family, const UInt& bit);
  static void UnRegisterComponent(const UInt& family, const UInt& bit);
private:  
  UInt id_;
  static ComponentMap component_register_;
  static IdFactory id_factory_;
};

} // namespace core
} // namespace engine
} // namespace crucible

#endif	/* COMPONENT_H */

