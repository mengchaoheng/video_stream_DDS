// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file HelloWorld.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "HelloWorld.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

HelloWorld::HelloWorld()
{
    // m_index com.eprosima.idl.parser.typecode.PrimitiveTypeCode@10bbd20a
    m_index = 0;
    // m_message com.eprosima.idl.parser.typecode.StringTypeCode@48503868
    m_message ="";
    // m_size com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6895a785
    m_size = 0;
    // m_picture com.eprosima.idl.parser.typecode.SequenceTypeCode@184f6be2


}

HelloWorld::~HelloWorld()
{




}

HelloWorld::HelloWorld(
        const HelloWorld& x)
{
    m_index = x.m_index;
    m_message = x.m_message;
    m_size = x.m_size;
    m_picture = x.m_picture;
}

HelloWorld::HelloWorld(
        HelloWorld&& x) noexcept 
{
    m_index = x.m_index;
    m_message = std::move(x.m_message);
    m_size = x.m_size;
    m_picture = std::move(x.m_picture);
}

HelloWorld& HelloWorld::operator =(
        const HelloWorld& x)
{

    m_index = x.m_index;
    m_message = x.m_message;
    m_size = x.m_size;
    m_picture = x.m_picture;

    return *this;
}

HelloWorld& HelloWorld::operator =(
        HelloWorld&& x) noexcept
{

    m_index = x.m_index;
    m_message = std::move(x.m_message);
    m_size = x.m_size;
    m_picture = std::move(x.m_picture);

    return *this;
}

bool HelloWorld::operator ==(
        const HelloWorld& x) const
{

    return (m_index == x.m_index && m_message == x.m_message && m_size == x.m_size && m_picture == x.m_picture);
}

bool HelloWorld::operator !=(
        const HelloWorld& x) const
{
    return !(*this == x);
}

size_t HelloWorld::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    current_alignment += (100 * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);




    return current_alignment - initial_alignment;
}

size_t HelloWorld::getCdrSerializedSize(
        const HelloWorld& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.message().size() + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.picture().size() > 0)
    {
        current_alignment += (data.picture().size() * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }




    return current_alignment - initial_alignment;
}

void HelloWorld::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_index;
    scdr << m_message.c_str();
    scdr << m_size;
    scdr << m_picture;

}

void HelloWorld::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_index;
    dcdr >> m_message;
    dcdr >> m_size;
    dcdr >> m_picture;
}

/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void HelloWorld::index(
        uint32_t _index)
{
    m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t HelloWorld::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& HelloWorld::index()
{
    return m_index;
}

/*!
 * @brief This function copies the value in member message
 * @param _message New value to be copied in member message
 */
void HelloWorld::message(
        const std::string& _message)
{
    m_message = _message;
}

/*!
 * @brief This function moves the value in member message
 * @param _message New value to be moved in member message
 */
void HelloWorld::message(
        std::string&& _message)
{
    m_message = std::move(_message);
}

/*!
 * @brief This function returns a constant reference to member message
 * @return Constant reference to member message
 */
const std::string& HelloWorld::message() const
{
    return m_message;
}

/*!
 * @brief This function returns a reference to member message
 * @return Reference to member message
 */
std::string& HelloWorld::message()
{
    return m_message;
}
/*!
 * @brief This function sets a value in member size
 * @param _size New value for member size
 */
void HelloWorld::size(
        uint32_t _size)
{
    m_size = _size;
}

/*!
 * @brief This function returns the value of member size
 * @return Value of member size
 */
uint32_t HelloWorld::size() const
{
    return m_size;
}

/*!
 * @brief This function returns a reference to member size
 * @return Reference to member size
 */
uint32_t& HelloWorld::size()
{
    return m_size;
}

/*!
 * @brief This function copies the value in member picture
 * @param _picture New value to be copied in member picture
 */
void HelloWorld::picture(
        const std::vector<uint8_t>& _picture)
{
    m_picture = _picture;
}

/*!
 * @brief This function moves the value in member picture
 * @param _picture New value to be moved in member picture
 */
void HelloWorld::picture(
        std::vector<uint8_t>&& _picture)
{
    m_picture = std::move(_picture);
}

/*!
 * @brief This function returns a constant reference to member picture
 * @return Constant reference to member picture
 */
const std::vector<uint8_t>& HelloWorld::picture() const
{
    return m_picture;
}

/*!
 * @brief This function returns a reference to member picture
 * @return Reference to member picture
 */
std::vector<uint8_t>& HelloWorld::picture()
{
    return m_picture;
}

size_t HelloWorld::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;







    return current_align;
}

bool HelloWorld::isKeyDefined()
{
    return false;
}

void HelloWorld::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
        
}
