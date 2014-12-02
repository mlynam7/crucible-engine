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

#include <memory>

#ifndef CRUCIBLE_H
#include "crucible.h"
#else
#include "crucible.h"
#endif

namespace crucible {
namespace engine {
namespace core {

class Component {
public:
  /* typdefs */
  typedef struct { UInt bit_field[64]; } ComponentMap;
  typedef std::unique_ptr<Component> UPComponent;
  typedef std::shared_ptr<Component> SPComponent;
  
  /* ctors */
  Component();
  
  virtual ~Component();
};

} // namespace core
} // namespace engine
} // namespace crucible

#endif	/* COMPONENT_H */
