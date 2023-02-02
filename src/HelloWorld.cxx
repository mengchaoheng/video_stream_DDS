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
    // m_index com.eprosima.idl.parser.typecode.PrimitiveTypeCode@184f6be2
    m_index = 0;
    // m_message com.eprosima.idl.parser.typecode.StringTypeCode@56aac163
    m_message ="";
    // m_file_path com.eprosima.idl.parser.typecode.ArrayTypeCode@1f7030a6
    memset(&m_file_path, 0, (10) * 1);
    // m_image_data com.eprosima.idl.parser.typecode.SequenceTypeCode@5a1c0542


}

HelloWorld::~HelloWorld()
{




}

HelloWorld::HelloWorld(
        const HelloWorld& x)
{
    m_index = x.m_index;
    m_message = x.m_message;
    m_file_path = x.m_file_path;
    m_image_data = x.m_image_data;
}

HelloWorld::HelloWorld(
        HelloWorld&& x) noexcept 
{
    m_index = x.m_index;
    m_message = std::move(x.m_message);
    m_file_path = std::move(x.m_file_path);
    m_image_data = std::move(x.m_image_data);
}

HelloWorld& HelloWorld::operator =(
        const HelloWorld& x)
{

    m_index = x.m_index;
    m_message = x.m_message;
    m_file_path = x.m_file_path;
    m_image_data = x.m_image_data;

    return *this;
}

HelloWorld& HelloWorld::operator =(
        HelloWorld&& x) noexcept
{

    m_index = x.m_index;
    m_message = std::move(x.m_message);
    m_file_path = std::move(x.m_file_path);
    m_image_data = std::move(x.m_image_data);

    return *this;
}

bool HelloWorld::operator ==(
        const HelloWorld& x) const
{

    return (m_index == x.m_index && m_message == x.m_message && m_file_path == x.m_file_path && m_image_data == x.m_image_data);
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

    current_alignment += ((10) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


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

    if ((10) > 0)
    {
        current_alignment += ((10) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.image_data().size() > 0)
    {
        current_alignment += (data.image_data().size() * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }




    return current_alignment - initial_alignment;
}

void HelloWorld::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_index;
    scdr << m_message.c_str();
    scdr << m_file_path;

    scdr << m_image_data;

}

void HelloWorld::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_index;
    dcdr >> m_message;
    dcdr >> m_file_path;

    dcdr >> m_image_data;
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
 * @brief This function copies the value in member file_path
 * @param _file_path New value to be copied in member file_path
 */
void HelloWorld::file_path(
        const std::array<char, 10>& _file_path)
{
    m_file_path = _file_path;
}

/*!
 * @brief This function moves the value in member file_path
 * @param _file_path New value to be moved in member file_path
 */
void HelloWorld::file_path(
        std::array<char, 10>&& _file_path)
{
    m_file_path = std::move(_file_path);
}

/*!
 * @brief This function returns a constant reference to member file_path
 * @return Constant reference to member file_path
 */
const std::array<char, 10>& HelloWorld::file_path() const
{
    return m_file_path;
}

/*!
 * @brief This function returns a reference to member file_path
 * @return Reference to member file_path
 */
std::array<char, 10>& HelloWorld::file_path()
{
    return m_file_path;
}
/*!
 * @brief This function copies the value in member image_data
 * @param _image_data New value to be copied in member image_data
 */
void HelloWorld::image_data(
        const std::vector<char>& _image_data)
{
    m_image_data = _image_data;
}

/*!
 * @brief This function moves the value in member image_data
 * @param _image_data New value to be moved in member image_data
 */
void HelloWorld::image_data(
        std::vector<char>&& _image_data)
{
    m_image_data = std::move(_image_data);
}

/*!
 * @brief This function returns a constant reference to member image_data
 * @return Constant reference to member image_data
 */
const std::vector<char>& HelloWorld::image_data() const
{
    return m_image_data;
}

/*!
 * @brief This function returns a reference to member image_data
 * @return Reference to member image_data
 */
std::vector<char>& HelloWorld::image_data()
{
    return m_image_data;
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
