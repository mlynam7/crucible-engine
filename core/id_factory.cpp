/* 
 * File:   id_factory.cpp
 * Author: Matt Lynam <lynam.matt@gmail.com>
 *
 * Created on December 5, 2014
 * 
 * The MIT License (MIT)
 *
 * Copyright (c) December 5, 2014 Matt Lynam <lynam.matt@gmail.com>
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

#include "id_factory.h"

namespace cec = crucible::engine::core;

cec::IdFactory::IdFactory() : id_counter_(0) {
  
}

cec::IdFactory::IdFactory(IdFactory&& other) 
: id_counter_(other.id_counter_)
, id_queue_(other.id_queue_) {
  
}

cec::IdFactory& cec::IdFactory::operator =(IdFactory&& other) {
  id_counter_ = other.id_counter_;
  id_queue_ = other.id_queue_;
  return *this;
}

cec::UInt cec::IdFactory::CreateId() {
  UInt id;
  mtx_.lock();
  if (id_queue_.size() > 0) {
    id = id_queue_.front();
    id_queue_.pop();
  }
  else {
    id = id_counter_++;
  }
  mtx_.unlock();
  return id;
}

void cec::IdFactory::ReclaimId(const UInt& id) {
  mtx_.lock();
  id_queue_.push(id);
  mtx_.unlock();
}