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
 * @file HelloWorld.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_HELLOWORLD_H_
#define _FAST_DDS_GENERATED_HELLOWORLD_H_


#include <fastrtps/utils/fixed_size_string.hpp>

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(HelloWorld_SOURCE)
#define HelloWorld_DllAPI __declspec( dllexport )
#else
#define HelloWorld_DllAPI __declspec( dllimport )
#endif // HelloWorld_SOURCE
#else
#define HelloWorld_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define HelloWorld_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure HelloWorld defined by the user in the IDL file.
 * @ingroup HELLOWORLD
 */
class HelloWorld
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport HelloWorld();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~HelloWorld();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object HelloWorld that will be copied.
     */
    eProsima_user_DllExport HelloWorld(
            const HelloWorld& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object HelloWorld that will be copied.
     */
    eProsima_user_DllExport HelloWorld(
            HelloWorld&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object HelloWorld that will be copied.
     */
    eProsima_user_DllExport HelloWorld& operator =(
            const HelloWorld& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object HelloWorld that will be copied.
     */
    eProsima_user_DllExport HelloWorld& operator =(
            HelloWorld&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x HelloWorld object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const HelloWorld& x) const;

    /*!
     * @brief Comparison operator.
     * @param x HelloWorld object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const HelloWorld& x) const;

    /*!
     * @brief This function sets a value in member index
     * @param _index New value for member index
     */
    eProsima_user_DllExport void index(
            uint32_t _index);

    /*!
     * @brief This function returns the value of member index
     * @return Value of member index
     */
    eProsima_user_DllExport uint32_t index() const;

    /*!
     * @brief This function returns a reference to member index
     * @return Reference to member index
     */
    eProsima_user_DllExport uint32_t& index();

    /*!
     * @brief This function copies the value in member message
     * @param _message New value to be copied in member message
     */
    eProsima_user_DllExport void message(
            const std::string& _message);

    /*!
     * @brief This function moves the value in member message
     * @param _message New value to be moved in member message
     */
    eProsima_user_DllExport void message(
            std::string&& _message);

    /*!
     * @brief This function returns a constant reference to member message
     * @return Constant reference to member message
     */
    eProsima_user_DllExport const std::string& message() const;

    /*!
     * @brief This function returns a reference to member message
     * @return Reference to member message
     */
    eProsima_user_DllExport std::string& message();
    /*!
     * @brief This function copies the value in member file_path
     * @param _file_path New value to be copied in member file_path
     */
    eProsima_user_DllExport void file_path(
            const std::array<char, 10>& _file_path);

    /*!
     * @brief This function moves the value in member file_path
     * @param _file_path New value to be moved in member file_path
     */
    eProsima_user_DllExport void file_path(
            std::array<char, 10>&& _file_path);

    /*!
     * @brief This function returns a constant reference to member file_path
     * @return Constant reference to member file_path
     */
    eProsima_user_DllExport const std::array<char, 10>& file_path() const;

    /*!
     * @brief This function returns a reference to member file_path
     * @return Reference to member file_path
     */
    eProsima_user_DllExport std::array<char, 10>& file_path();
    /*!
     * @brief This function copies the value in member image_data
     * @param _image_data New value to be copied in member image_data
     */
    eProsima_user_DllExport void image_data(
            const std::vector<char>& _image_data);

    /*!
     * @brief This function moves the value in member image_data
     * @param _image_data New value to be moved in member image_data
     */
    eProsima_user_DllExport void image_data(
            std::vector<char>&& _image_data);

    /*!
     * @brief This function returns a constant reference to member image_data
     * @return Constant reference to member image_data
     */
    eProsima_user_DllExport const std::vector<char>& image_data() const;

    /*!
     * @brief This function returns a reference to member image_data
     * @return Reference to member image_data
     */
    eProsima_user_DllExport std::vector<char>& image_data();

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const HelloWorld& data,
            size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;

private:

    uint32_t m_index;
    std::string m_message;
    std::array<char, 10> m_file_path;
    std::vector<char> m_image_data;
};

#endif // _FAST_DDS_GENERATED_HELLOWORLD_H_